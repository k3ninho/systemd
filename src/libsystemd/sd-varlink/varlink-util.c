/* SPDX-License-Identifier: LGPL-2.1-or-later */

#include "errno-util.h"
#include "varlink-internal.h"
#include "varlink-util.h"

int varlink_get_peer_pidref(sd_varlink *v, PidRef *ret) {
        int r;

        assert_return(v, -EINVAL);
        assert_return(ret, -EINVAL);

        /* Returns r > 0 if we acquired the pidref via SO_PEERPIDFD (i.e. if we can use it for
         * authentication). Returns == 0 if we didn't, and the pidref should not be used for
         * authentication. */

        int pidfd = sd_varlink_get_peer_pidfd(v);
        if (pidfd < 0) {
                if (!ERRNO_IS_NEG_NOT_SUPPORTED(pidfd))
                        return pidfd;

                pid_t pid;
                r = sd_varlink_get_peer_pid(v, &pid);
                if (r < 0)
                        return r;

                r = pidref_set_pid(ret, pid);
                if (r < 0)
                        return r;

                return 0; /* didn't get pidfd securely */
        }

        r = pidref_set_pidfd(ret, pidfd);
        if (r < 0)
                return r;

        return 1; /* got pidfd securely */
}

int varlink_call_and_log(
                sd_varlink *v,
                const char *method,
                sd_json_variant *parameters,
                sd_json_variant **ret_parameters) {

        sd_json_variant *reply = NULL;
        const char *error_id = NULL;
        int r;

        assert_return(v, -EINVAL);
        assert_return(method, -EINVAL);

        r = sd_varlink_call(v, method, parameters, &reply, &error_id);
        if (r < 0)
                return log_error_errno(r, "Failed to issue %s() varlink call: %m", method);
        if (error_id)
                return log_error_errno(sd_varlink_error_to_errno(error_id, reply),
                                         "Failed to issue %s() varlink call: %s", method, error_id);

        if (ret_parameters)
                *ret_parameters = TAKE_PTR(reply);

        return 0;
}

int varlink_callb_and_log(
                sd_varlink *v,
                const char *method,
                sd_json_variant **ret_parameters,
                ...) {

        _cleanup_(sd_json_variant_unrefp) sd_json_variant *parameters = NULL;
        va_list ap;
        int r;

        assert_return(v, -EINVAL);
        assert_return(method, -EINVAL);

        va_start(ap, ret_parameters);
        r = sd_json_buildv(&parameters, ap);
        va_end(ap);
        if (r < 0)
                return log_error_errno(r, "Failed to build JSON message: %m");

        return varlink_call_and_log(v, method, parameters, ret_parameters);
}

int varlink_many_notifyb(Set *s, ...) {
        int r;

        /* Equivalent to varlink_notifyb(), but does this for each entry of the supplied set of Varlink connections */

        if (set_isempty(s))
                return 0;

        _cleanup_(sd_json_variant_unrefp) sd_json_variant *parameters = NULL;
        va_list ap;
        va_start(ap, s);
        r = sd_json_buildv(&parameters, ap);
        va_end(ap);
        if (r < 0)
                return r;

        r = 1;
        sd_varlink *link;
        SET_FOREACH(link, s)
                RET_GATHER(r, sd_varlink_notify(link, parameters));

        return r;
}

int varlink_many_reply(Set *s, sd_json_variant *parameters) {
        if (set_isempty(s))
                return 0;

        int r = 1;
        sd_varlink *link;
        SET_FOREACH(link, s)
                RET_GATHER(r, sd_varlink_reply(link, parameters));

        return r;
}

int varlink_many_error(Set *s, const char *error_id, sd_json_variant *parameters) {
        if (set_isempty(s))
                return 0;

        int r = 1;
        sd_varlink *link;
        SET_FOREACH(link, s)
                RET_GATHER(r, sd_varlink_error(link, error_id, parameters));

        return r;
}
