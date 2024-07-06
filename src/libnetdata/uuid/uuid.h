// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef NETDATA_UUID_H
#define NETDATA_UUID_H

// for compatibility with libuuid
typedef unsigned char nd_uuid_t[16];

// for quickly managing it as 2x 64-bit numbers
typedef struct _uuid {
    union {
        nd_uuid_t uuid;
        struct {
            uint64_t hig64;
            uint64_t low64;
        } parts;
    };
} ND_UUID;

#ifdef __GNUC__
#define ND_UUID_DEFINE(name,u0,u1,u2,u3,u4,u5,u6,u7,u8,u9,u10,u11,u12,u13,u14,u15) \
	static const nd_uuid_t name __attribute__ ((unused)) = {u0,u1,u2,u3,u4,u5,u6,u7,u8,u9,u10,u11,u12,u13,u14,u15}
#else
#define ND_UUID_DEFINE(name,u0,u1,u2,u3,u4,u5,u6,u7,u8,u9,u10,u11,u12,u13,u14,u15) \
	static const nd_uuid_t name = {u0,u1,u2,u3,u4,u5,u6,u7,u8,u9,u10,u11,u12,u13,u14,u15}
#endif

static const ND_UUID UUID_ZERO = (ND_UUID){ { .parts = { .hig64 = 0, .low64 = 0 } }};
ND_UUID_DEFINE(streaming_from_child_msgid, 0xed,0x4c,0xdb, 0x8f, 0x1b, 0xeb, 0x4a, 0xd3, 0xb5, 0x7c, 0xb3, 0xca, 0xe2, 0xd1, 0x62, 0xfa);
ND_UUID_DEFINE(streaming_to_parent_msgid, 0x6e, 0x2e, 0x38, 0x39, 0x06, 0x76, 0x48, 0x96, 0x8b, 0x64, 0x60, 0x45, 0xdb, 0xf2, 0x8d, 0x66);
ND_UUID_DEFINE(health_alert_transition_msgid, 0x9c, 0xe0, 0xcb, 0x58, 0xab, 0x8b, 0x44, 0xdf, 0x82, 0xc4, 0xbf, 0x1a, 0xd9, 0xee, 0x22, 0xde);

// this is also defined in alarm-notify.sh.in
ND_UUID_DEFINE(health_alert_notification_msgid, 0x6d, 0xb0, 0x01, 0x8e, 0x83, 0xe3, 0x43, 0x20, 0xae, 0x2a, 0x65, 0x9d, 0x78, 0x01, 0x9f, 0xb7);

ND_UUID UUID_generate_from_hash(const void *payload, size_t payload_len);

#define UUIDeq(a, b) ((a).parts.hig64 == (b).parts.hig64 && (a).parts.low64 == (b).parts.low64)

static inline ND_UUID uuid2UUID(const nd_uuid_t uu1) {
    // uu1 may not be aligned, so copy it to the output
    ND_UUID copy;
    memcpy(copy.uuid, uu1, sizeof(nd_uuid_t));
    return copy;
}

#ifndef UUID_STR_LEN
// CentOS 7 has older version that doesn't define this
// same goes for MacOS
#define UUID_STR_LEN	37
#endif

#define UUID_COMPACT_STR_LEN 33

void uuid_unparse_lower_compact(const nd_uuid_t uuid, char *out);
int uuid_parse_compact(const char *in, nd_uuid_t uuid);

int uuid_parse_flexi(const char *in, nd_uuid_t uuid);
#define uuid_parse(in, uuid) uuid_parse_flexi(in, uuid)

static inline int hex_char_to_int(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    return -1; // Invalid hexadecimal character
}

static inline void nd_uuid_clear(nd_uuid_t uu) {
    memset(uu, 0, sizeof(nd_uuid_t));
}

// Netdata does not need to sort UUIDs lexicographically and this kind
// of sorting does not need to be portable between little/big endian.
// So, any kind of sorting will work, as long as it compares UUIDs.
// The fastest possible, is good enough.
static inline int nd_uuid_compare(const nd_uuid_t uu1, const nd_uuid_t uu2) {
    // IMPORTANT:
    // uu1 or uu2 may not be aligned to word boundaries on this call,
    // so casting this to a struct may give SIGBUS on some architectures.
    return memcmp(uu1, uu2, sizeof(nd_uuid_t));
}

static inline void nd_uuid_copy(nd_uuid_t dst, const nd_uuid_t src) {
    memcpy(dst, src, sizeof(nd_uuid_t));
}

static inline bool nd_uuid_eq(const nd_uuid_t uu1, const nd_uuid_t uu2) {
    return nd_uuid_compare(uu1, uu2) == 0;
}

static inline int nd_uuid_is_null(const nd_uuid_t uu) {
    return nd_uuid_compare(uu, UUID_ZERO.uuid) == 0;
}

void nd_uuid_unparse_lower(const nd_uuid_t uuid, char *out);
void nd_uuid_unparse_upper(const nd_uuid_t uuid, char *out);

#define uuid_is_null(uu) nd_uuid_is_null(uu)
#define uuid_clear(uu) nd_uuid_clear(uu)
#define uuid_compare(uu1, uu2) nd_uuid_compare(uu1, uu2)
#define uuid_copy(dst, src) nd_uuid_copy(dst, src)
#define uuid_eq(uu1, uu2) nd_uuid_eq(uu1, uu2)

#define uuid_generate(out) os_uuid_generate(out)
#define uuid_generate_random(out) os_uuid_generate_random(out)
#define uuid_generate_time(out) os_uuid_generate_time(out)

#define uuid_unparse(uu, out) nd_uuid_unparse_lower(uu, out)
#define uuid_unparse_lower(uu, out) nd_uuid_unparse_lower(uu, out)
#define uuid_unparse_upper(uu, out) nd_uuid_unparse_upper(uu, out)

#endif //NETDATA_UUID_H
