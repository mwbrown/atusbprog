
#include "cmdline.h"

#include <stddef.h>
#include <stdbool.h>
#include <string.h>

#define STREQ(str, s) (strcmp((str), (s)) == 0)
#define OPTEQ(str, opt_long, opt_short) (STREQ((str), (opt_long)) || STREQ((str), (opt_short)))

typedef enum cmdline_argtype_e {
    ARGTYPE_NONE,
    ARGTYPE_PROGRAM,
    ARGTYPE_DUMP,
    ARGTYPE_DEVICE
} cmdline_argtype_t;

typedef struct dev_name_mapping_s {
    const char  *name;
    aup_device_t device;
} dev_name_mapping_t;

const static dev_name_mapping_t device_names[] = {
    {"at89s52", AUP_DEV_AT89S52},
};

const static size_t device_names_size = sizeof(device_names) / sizeof(dev_name_mapping_t);

static aup_device_t get_device_from_string(const char *name)
{
    for (int i = 0; i < device_names_size; i++)
    {
        if (_strcmpi(name, device_names[i].name) == 0)
        {
            return device_names[i].device;
        }
    }

    return AUP_DEV_NONE;
}

int cmdline_parse(int argc, const char *argv[], cmdline_options_t *options)
{
    cmdline_argtype_t want_argument = ARGTYPE_NONE;

    /* Require a valid options structure and at least one non-program argument
       to be provided (i.e. argv[0] is always the program name itself). */
    if ((options == NULL) || (argc == 0) || (argv == NULL))
    {
        return -1;
    }

    /* Initialize the options structure. */
    memset(options, 0, sizeof(cmdline_options_t));

    for (int i = 1; i < argc; i++)
    {
        const char *arg = argv[i];

        /* Command line arguments consist of:
           - One operation (--program/-p, --erase/-e, --reset/-r, --dump/-d)
           - For --program and --dump, a filename immediately following.
           - A device (--device/-D)
        */

        // TODO replace this with a tokenizer and token struct table, clean up this repetitive code

        if (OPTEQ(arg, "--program", "-p"))
        {
            /* Ensure we don't already have an operation specified. */
            if (options->op != CMDLINE_OP_NONE)
            {
                printf("%s encountered when operation already specified.\n", arg);
                return -1;
            }

            want_argument = ARGTYPE_PROGRAM;
            options->op = CMDLINE_OP_PROGRAM;
        }
        else if (OPTEQ(arg, "--dump", "-d"))
        {
            /* Ensure we don't already have an operation specified. */
            if (options->op != CMDLINE_OP_NONE)
            {
                printf("%s encountered when operation already specified.\n", arg);
                return -1;
            }

            want_argument = ARGTYPE_DUMP;
            options->op = CMDLINE_OP_DUMP;
        }
        else if (OPTEQ(arg, "--erase", "-e"))
        {
            /* Ensure we don't already have an operation specified. */
            if (options->op != CMDLINE_OP_NONE)
            {
                printf("%s encountered when operation already specified.\n", arg);
                return -1;
            }

            options->op = CMDLINE_OP_ERASE;
        }
        else if (OPTEQ(arg, "--reset", "-r"))
        {
            /* Ensure we don't already have an operation specified. */
            if (options->op != CMDLINE_OP_NONE)
            {
                printf("%s encountered when operation already specified.\n", arg);
                return -1;
            }

            options->op = CMDLINE_OP_RESET;
        }
        else if (OPTEQ(arg, "--device", "-D"))
        {
            /* Ensure we don't already have a device specified. */
            if (options->device != AUP_DEV_NONE)
            {
                printf("%s encountered when device already specified.\n", arg);
                return -1;
            }
                
            want_argument = ARGTYPE_DEVICE;
        }
        else
        {
            switch(want_argument)
            {
            case ARGTYPE_PROGRAM:
                options->prog_filename = arg;
                break;

            case ARGTYPE_DUMP:
                options->dump_filename = arg;
                break;

            case ARGTYPE_DEVICE:
                options->device = get_device_from_string(arg);

                /* Did we find a device in the list? */
                if (options->device == AUP_DEV_NONE)
                {
                    printf("\"%s\" is not a valid device name.\n", arg);
                    return -1;
                }
                break;

            case ARGTYPE_NONE:
            default:
                /* Not expecting an unmatched argument. */
                printf("Unexpected \"%s\" in options.\n", arg);
                return -1;
            }

            want_argument = ARGTYPE_NONE;
        }
    }

    if (want_argument != ARGTYPE_NONE)
    {
        /* Reached the end of the argument list and no filename provided. */
        printf("Still expecting argument for last option.\n");
        return -1;
    }

    return 0;
}
