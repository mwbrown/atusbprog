
#ifndef _AUP_PROTO_H_INCLUDED_
#define _AUP_PROTO_H_INCLUDED_

#include <stdint.h>

/* ALL MULTI-BYTE DATA IS LITTLE-ENDIAN UNLESS SPECIFIED OTHERWISE */

/* Structure packing hints */
#if defined(__GNUC__)
#define PACKED __attribute__((packed))
#elif defined(__C51__)
/* Every structure on 8051 is implicitly packed. */
#define PACKED
#else
#error "Unsupported compiler"
#endif

/* USB protocol revision (must match host vs. client) */
#define AUP_PROTO_VERSION_MAJ       0x00
#define AUP_PROTO_VERSION_MIN       0x00
#define AUP_PROTO_VERSION_REV       0x01

#define AUP_MAX_PACKET_SIZE         32

typedef enum aup_msg_type_e {
    AUP_MSG_VERSION_REQ_RSP = 0,            /* Version Request / Response. MUST BE 0 */
    AUP_MSG_LED_REQ,
} PACKED aup_msg_type_t;

/* Individual IN messages */

typedef struct aup_in_msg_version_rsp_s {
    uint8_t maj;                            /**< Major Version */
    uint8_t min;                            /**< Minor Version */
    uint8_t rev;                            /**< Revision Number */
} PACKED aup_in_msg_version_rsp_t;

/* Individual OUT messages */

typedef struct aup_out_msg_led_req_s {
    uint8_t led_mask;                       /* LEDs to update. */
    uint8_t led_val;                        /* Values of updated LEDs. */
} PACKED aup_out_msg_led_req_t;

#define LED_REQ_MASK_RED    0x01            /* Bit to update red LED (P1_B6). */
#define LED_REQ_MASK_GRN    0x02            /* Bit to update green LED (P1_B4). */
#define LED_REQ_MASK_BLU    0x04            /* Bit to update blue LED (P1_B5). */

/* Top-level message structs in/out */

typedef struct aup_out_msg_s {
    uint8_t msg_type;
    union {
        aup_out_msg_led_req_t led_req;
    } msg_data;
} PACKED aup_out_msg_t;

#define AUP_OUT_MSG_HDR_LEN 1

typedef struct aup_in_msg_s {
    uint8_t msg_type;
    union {
        aup_in_msg_version_rsp_t version_rsp;
    } msg_data;
} PACKED aup_in_msg_t;

#define AUP_IN_MSG_HDR_LEN 1

#endif /*_AUP_PROTO_H_INCLUDED_ */
