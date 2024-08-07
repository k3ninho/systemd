/* SPDX-License-Identifier: LGPL-2.1-or-later */

#include "varlink-io.systemd.Resolve.h"

SD_VARLINK_DEFINE_STRUCT_TYPE(
                ResourceKey,
                SD_VARLINK_DEFINE_FIELD(class, SD_VARLINK_INT, 0),
                SD_VARLINK_DEFINE_FIELD(type, SD_VARLINK_INT, 0),
                SD_VARLINK_DEFINE_FIELD(name, SD_VARLINK_STRING, 0));

SD_VARLINK_DEFINE_STRUCT_TYPE(
                ResourceRecord,
                SD_VARLINK_DEFINE_FIELD_BY_TYPE(key, ResourceKey, 0),
                SD_VARLINK_DEFINE_FIELD(priority, SD_VARLINK_INT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(weight, SD_VARLINK_INT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(port, SD_VARLINK_INT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(name, SD_VARLINK_STRING, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(cpu, SD_VARLINK_STRING, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(os, SD_VARLINK_STRING, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(items, SD_VARLINK_STRING, SD_VARLINK_NULLABLE|SD_VARLINK_ARRAY),
                SD_VARLINK_DEFINE_FIELD(address, SD_VARLINK_INT, SD_VARLINK_NULLABLE|SD_VARLINK_ARRAY),
                SD_VARLINK_DEFINE_FIELD(mname, SD_VARLINK_STRING, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(rname, SD_VARLINK_STRING, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(serial, SD_VARLINK_INT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(refresh, SD_VARLINK_INT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(expire, SD_VARLINK_INT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(minimum, SD_VARLINK_INT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(exchange, SD_VARLINK_STRING, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(version, SD_VARLINK_INT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(size, SD_VARLINK_INT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(horiz_pre, SD_VARLINK_INT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(vert_pre, SD_VARLINK_INT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(latitude, SD_VARLINK_INT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(longitude, SD_VARLINK_INT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(altitude, SD_VARLINK_INT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(keyTag, SD_VARLINK_INT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(algorithm, SD_VARLINK_INT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(digestType, SD_VARLINK_INT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(digest, SD_VARLINK_STRING, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(fptype, SD_VARLINK_INT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(fingerprint, SD_VARLINK_STRING, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(flags, SD_VARLINK_INT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(protocol, SD_VARLINK_INT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(dnskey, SD_VARLINK_STRING, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(signer, SD_VARLINK_STRING, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(typeCovered, SD_VARLINK_INT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(labels, SD_VARLINK_INT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(originalTtl, SD_VARLINK_INT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(expiration, SD_VARLINK_INT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(inception, SD_VARLINK_INT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(signature, SD_VARLINK_STRING, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(nextDomain, SD_VARLINK_STRING, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(types, SD_VARLINK_INT, SD_VARLINK_NULLABLE|SD_VARLINK_ARRAY),
                SD_VARLINK_DEFINE_FIELD(iterations, SD_VARLINK_INT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(salt, SD_VARLINK_STRING, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(hash, SD_VARLINK_STRING, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(certUsage, SD_VARLINK_INT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(selector, SD_VARLINK_INT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(matchingType, SD_VARLINK_INT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(data, SD_VARLINK_STRING, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(tag, SD_VARLINK_STRING, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(value, SD_VARLINK_STRING, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(target, SD_VARLINK_STRING, SD_VARLINK_NULLABLE),
                /* This field is retired */
                /* SD_VARLINK_DEFINE_FIELD(params, SD_VARLINK_STRING, SD_VARLINK_NULLABLE|SD_VARLINK_ARRAY), */
                SD_VARLINK_DEFINE_FIELD(svcparams, SD_VARLINK_OBJECT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(order, SD_VARLINK_INT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(preference, SD_VARLINK_INT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(naptrFlags, SD_VARLINK_STRING, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(services, SD_VARLINK_STRING, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(regexp, SD_VARLINK_STRING, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(replacement, SD_VARLINK_STRING, SD_VARLINK_NULLABLE));

static SD_VARLINK_DEFINE_STRUCT_TYPE(
                ResolvedAddress,
                SD_VARLINK_DEFINE_FIELD(ifindex, SD_VARLINK_INT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(family, SD_VARLINK_INT, 0),
                SD_VARLINK_DEFINE_FIELD(address, SD_VARLINK_INT, SD_VARLINK_ARRAY));

static SD_VARLINK_DEFINE_METHOD(
                ResolveHostname,
                SD_VARLINK_DEFINE_INPUT(ifindex, SD_VARLINK_INT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_INPUT(name, SD_VARLINK_STRING, 0),
                SD_VARLINK_DEFINE_INPUT(family, SD_VARLINK_INT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_INPUT(flags, SD_VARLINK_INT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_OUTPUT_BY_TYPE(addresses, ResolvedAddress, SD_VARLINK_ARRAY),
                SD_VARLINK_DEFINE_OUTPUT(name, SD_VARLINK_STRING, 0),
                SD_VARLINK_DEFINE_OUTPUT(flags, SD_VARLINK_INT, 0));

static SD_VARLINK_DEFINE_STRUCT_TYPE(
                ResolvedName,
                SD_VARLINK_DEFINE_FIELD(ifindex, SD_VARLINK_INT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(name, SD_VARLINK_STRING, 0));

static SD_VARLINK_DEFINE_METHOD(
                ResolveAddress,
                SD_VARLINK_DEFINE_INPUT(ifindex, SD_VARLINK_INT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_INPUT(family, SD_VARLINK_INT, 0),
                SD_VARLINK_DEFINE_INPUT(address, SD_VARLINK_INT, SD_VARLINK_ARRAY),
                SD_VARLINK_DEFINE_INPUT(flags, SD_VARLINK_INT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_OUTPUT_BY_TYPE(names, ResolvedName, SD_VARLINK_ARRAY),
                SD_VARLINK_DEFINE_OUTPUT(flags, SD_VARLINK_INT, 0));

static SD_VARLINK_DEFINE_STRUCT_TYPE(
                ResolvedService,
                SD_VARLINK_DEFINE_FIELD(priority, SD_VARLINK_INT, 0),
                SD_VARLINK_DEFINE_FIELD(weight, SD_VARLINK_INT, 0),
                SD_VARLINK_DEFINE_FIELD(port, SD_VARLINK_INT, 0),
                SD_VARLINK_DEFINE_FIELD(hostname, SD_VARLINK_STRING, 0),
                SD_VARLINK_DEFINE_FIELD(canonicalName, SD_VARLINK_STRING, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD_BY_TYPE(addresses, ResolvedAddress, SD_VARLINK_ARRAY|SD_VARLINK_NULLABLE));

static SD_VARLINK_DEFINE_STRUCT_TYPE(
                ResolvedCanonical,
                SD_VARLINK_DEFINE_FIELD(name, SD_VARLINK_STRING, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(type, SD_VARLINK_STRING, 0),
                SD_VARLINK_DEFINE_FIELD(domain, SD_VARLINK_STRING, 0));

static SD_VARLINK_DEFINE_METHOD(
                ResolveService,
                SD_VARLINK_DEFINE_INPUT(name, SD_VARLINK_STRING, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_INPUT(type, SD_VARLINK_STRING, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_INPUT(domain, SD_VARLINK_STRING, 0),
                SD_VARLINK_DEFINE_INPUT(ifindex, SD_VARLINK_INT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_INPUT(family, SD_VARLINK_INT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_INPUT(flags, SD_VARLINK_INT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_OUTPUT_BY_TYPE(services, ResolvedService, SD_VARLINK_ARRAY),
                SD_VARLINK_DEFINE_OUTPUT(txt, SD_VARLINK_STRING, SD_VARLINK_ARRAY|SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_OUTPUT_BY_TYPE(canonical, ResolvedCanonical, 0),
                SD_VARLINK_DEFINE_OUTPUT(flags, SD_VARLINK_INT, 0));

static SD_VARLINK_DEFINE_STRUCT_TYPE(
                ResolvedRecord,
                SD_VARLINK_DEFINE_FIELD(ifindex, SD_VARLINK_INT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD_BY_TYPE(rr, ResourceRecord, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(raw, SD_VARLINK_STRING, 0));

static SD_VARLINK_DEFINE_METHOD(
                ResolveRecord,
                SD_VARLINK_DEFINE_INPUT(ifindex, SD_VARLINK_INT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_INPUT(name, SD_VARLINK_STRING, 0),
                SD_VARLINK_DEFINE_INPUT(class, SD_VARLINK_INT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_INPUT(type, SD_VARLINK_INT, 0),
                SD_VARLINK_DEFINE_INPUT(flags, SD_VARLINK_INT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_OUTPUT_BY_TYPE(rrs, ResolvedRecord, SD_VARLINK_ARRAY),
                SD_VARLINK_DEFINE_OUTPUT(flags, SD_VARLINK_INT, 0));

static SD_VARLINK_DEFINE_ERROR(NoNameServers);
static SD_VARLINK_DEFINE_ERROR(NoSuchResourceRecord);
static SD_VARLINK_DEFINE_ERROR(QueryTimedOut);
static SD_VARLINK_DEFINE_ERROR(MaxAttemptsReached);
static SD_VARLINK_DEFINE_ERROR(InvalidReply);
static SD_VARLINK_DEFINE_ERROR(QueryAborted);
static SD_VARLINK_DEFINE_ERROR(
                DNSSECValidationFailed,
                SD_VARLINK_DEFINE_FIELD(result, SD_VARLINK_STRING, 0),
                SD_VARLINK_DEFINE_FIELD(extendedDNSErrorCode, SD_VARLINK_INT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(extendedDNSErrorMessage, SD_VARLINK_STRING, SD_VARLINK_NULLABLE));
static SD_VARLINK_DEFINE_ERROR(NoTrustAnchor);
static SD_VARLINK_DEFINE_ERROR(ResourceRecordTypeUnsupported);
static SD_VARLINK_DEFINE_ERROR(NetworkDown);
static SD_VARLINK_DEFINE_ERROR(NoSource);
static SD_VARLINK_DEFINE_ERROR(StubLoop);
static SD_VARLINK_DEFINE_ERROR(
                DNSError,
                SD_VARLINK_DEFINE_FIELD(rcode, SD_VARLINK_INT, 0),
                SD_VARLINK_DEFINE_FIELD(extendedDNSErrorCode, SD_VARLINK_INT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(extendedDNSErrorMessage, SD_VARLINK_STRING, SD_VARLINK_NULLABLE));
static SD_VARLINK_DEFINE_ERROR(CNAMELoop);
static SD_VARLINK_DEFINE_ERROR(BadAddressSize);
static SD_VARLINK_DEFINE_ERROR(ResourceRecordTypeInvalidForQuery);
static SD_VARLINK_DEFINE_ERROR(ZoneTransfersNotPermitted);
static SD_VARLINK_DEFINE_ERROR(ResourceRecordTypeObsolete);

SD_VARLINK_DEFINE_INTERFACE(
                io_systemd_Resolve,
                "io.systemd.Resolve",
                &vl_method_ResolveHostname,
                &vl_method_ResolveAddress,
                &vl_method_ResolveService,
                &vl_method_ResolveRecord,
                &vl_type_ResolvedAddress,
                &vl_type_ResolvedName,
                &vl_type_ResolvedService,
                &vl_type_ResolvedCanonical,
                &vl_type_ResourceKey,
                &vl_type_ResourceRecord,
                &vl_type_ResolvedRecord,
                &vl_error_NoNameServers,
                &vl_error_NoSuchResourceRecord,
                &vl_error_QueryTimedOut,
                &vl_error_MaxAttemptsReached,
                &vl_error_InvalidReply,
                &vl_error_QueryAborted,
                &vl_error_DNSSECValidationFailed,
                &vl_error_NoTrustAnchor,
                &vl_error_ResourceRecordTypeUnsupported,
                &vl_error_NetworkDown,
                &vl_error_NoSource,
                &vl_error_StubLoop,
                &vl_error_DNSError,
                &vl_error_CNAMELoop,
                &vl_error_BadAddressSize,
                &vl_error_ResourceRecordTypeInvalidForQuery,
                &vl_error_ZoneTransfersNotPermitted,
                &vl_error_ResourceRecordTypeObsolete);
