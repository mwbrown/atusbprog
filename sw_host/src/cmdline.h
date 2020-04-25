
#ifndef _CMDLINE_H_INCLUDED_
#define _CMDLINE_H_INCLUDED_

#include "devices.h"

typedef enum cmdline_operation_e {
    CMDLINE_OP_NONE = 0,    /**< No operation (this is an error). */
    CMDLINE_OP_PROGRAM,     /**< Program the chip with a given binary. */
    CMDLINE_OP_ERASE,       /**< Erase the chip only. */
    CMDLINE_OP_RESET,       /**< Reset the chip only. */
    CMDLINE_OP_DUMP,        /**< Dump the chip contents to a file. */
} cmdline_operation_t;

typedef struct cmdline_options_s {
    cmdline_operation_t op;     /**< Operation to perform with the chip. */
    aup_device_t device;        /**< The part number to program. */
    const char *prog_filename;  /**< Filename to program into the chip. */
    const char *dump_filename;  /**< Filename to dump chip contents to. */
} cmdline_options_t;

int cmdline_parse(int argc, const char *argv[], cmdline_options_t *options);

#endif
