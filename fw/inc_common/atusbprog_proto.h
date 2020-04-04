
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
#elif defined(_MSC_VER)
#define PACKED
#pragma pack(push,1)
#else
#error "Unsupported compiler"
#endif

/* USB protocol revision (must match host vs. client) */
#define AUP_PROTO_VERSION_MAJ       0x00
#define AUP_PROTO_VERSION_MIN       0x00
#define AUP_PROTO_VERSION_REV       0x01

#define AUP_MAX_PACKET_SIZE         32

typedef enum aup_msg_type_e {

    /* Out message types (w/ optional corresponding response) */
    /* Note: this is just an optimization for FW RX handler tables. */

    AUP_MSG_VERSION_REQ_RSP = 0,            /* Version Request / Response. MUST BE 0 */
    AUP_MSG_LED_REQ,                        /* Debug LED request. */
    AUP_MSG_INIT_PGM_MODE_REQ_RSP,          /* Initialize Programming Mode Request/Response. */
    AUP_MSG_DATA_WRITE,                     /* Raw data payload for FW blob or raw SPI mode. */

    /* In messages w/out corresponding Out message */

    AUP_MSG_CMD_ACK,                        /* Generic command acknowledge. */
    AUP_MSG_DATA_ACK_RSP,                   /* Raw Data Acknowledge / Response. */

} aup_msg_type_t;

/* Individual IN messages */

typedef struct aup_in_msg_version_rsp_s {
    uint8_t maj;                            /**< Major Version */
    uint8_t min;                            /**< Minor Version */
    uint8_t rev;                            /**< Revision Number */
} PACKED aup_in_msg_version_rsp_t;

typedef struct aup_in_msg_cmd_ack_s {
    uint8_t cmd;                            /**< The command being acknowledged (@ref aup_msg_type_t). */
    uint8_t status;                         /**< The status of the command, see @ref cmd_ack_status_t. */
} PACKED aup_in_msg_cmd_ack_t;

typedef enum cmd_ack_status_e {
    AUP_CMD_STATUS_SUCCESS = 0,             /**< Success. */
    AUP_CMD_STATUS_ERROR,                   /**< Generic error. */
    AUP_CMD_STATUS_NOT_SUPPORTED,           /**< Command not supported. */
    AUP_CMD_STATUS_BAD_SIGNATURE,           /**< Invalid chip signature. */
} cmd_ack_status_t;

typedef struct aup_in_msg_pgm_mode_rsp_s {
    uint8_t status;                         /**< The status of enabling programming, see @ref cmd_ack_status_t. */
} PACKED aup_in_msg_pgm_mode_rsp_t;

typedef struct aup_in_msg_data_ack_rsp_s {
    uint8_t data_recv;                      /**< The number of bytes processed. Should match the number of bytes sent. */
    uint8_t data_want;                      /**< The number of bytes allowed to be sent in the next request. */
    uint16_t data_remain;                   /**< The number of total bytes remaining in the bulk transfer. */
} PACKED aup_in_msg_data_ack_rsp_t;

/* Individual OUT messages */

typedef struct aup_out_msg_led_req_s {
    uint8_t led_mask;                       /**< LEDs to update. */
    uint8_t led_val;                        /**< Values of updated LEDs. */
} PACKED aup_out_msg_led_req_t;

typedef struct aup_out_msg_data_write_s {
    /* TBD not needed as long as USB packetizes correctly? */
    // uint8_t len;
    uint8_t payload[1];						/**< Variable length array (C51 does not support var or 0-len arrays) */
} PACKED aup_out_msg_data_write_t;

#define LED_REQ_MASK_RED    0x01            /**< Bit to update red LED (P1_B6). */
#define LED_REQ_MASK_GRN    0x02            /**< Bit to update green LED (P1_B4). */
#define LED_REQ_MASK_BLU    0x04            /**< Bit to update blue LED (P1_B5). */

#define LED_REQ_MASK_ALL    (LED_REQ_MASK_RED | LED_REQ_MASK_GRN | LED_REQ_MASK_BLU)

typedef struct aup_out_msg_init_pgm_mode_req_s {
    uint8_t chip_id;
    /* remaining structure TBD */
} PACKED aup_out_msg_init_pgm_mode_req_t;

typedef enum pgm_mode_chip_id_e {
    PGM_MODE_CHIP_ID_RAW_SPI = 0,            /**< Raw SPI access for unsupported/custom protocols. */
    PGM_MODE_CHIP_ID_AT89S52,                /**< Atmel AT89S52. */
    PGM_MODE_CHIP_ID_AT89S8253,              /**< Atmel AT89S8253. */
} pgm_mode_chip_id_t;

/* Top-level message structs in/out */

typedef struct aup_out_msg_s {
    uint8_t msg_type;
    union {
        aup_out_msg_led_req_t led_req;
        aup_out_msg_init_pgm_mode_req_t pgm_mode_req;
        aup_out_msg_data_write_t data_write;
    } msg_data;
} PACKED aup_out_msg_t;

#define AUP_OUT_MSG_HDR_LEN 1

typedef struct aup_in_msg_s {
    uint8_t msg_type;
    union {
        aup_in_msg_version_rsp_t version_rsp;
        aup_in_msg_cmd_ack_t cmd_ack;
        aup_in_msg_pgm_mode_rsp_t pgm_mode_rsp;
        aup_in_msg_data_ack_rsp_t data_ack_rsp;
    } msg_data;
} PACKED aup_in_msg_t;

#define AUP_IN_MSG_HDR_LEN 1

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif /*_AUP_PROTO_H_INCLUDED_ */
