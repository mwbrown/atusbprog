
#include "debug_uart.h"

#include <SI_EFM8UB1_Register_Enums.h>

#include <stdint.h>
#include <string.h>

#define UART_CONTEXT_SEG SI_SEG_IDATA
#define UART_BUFFER_SEG  SI_SEG_XDATA
#define UART_BUFFER_LEN  128

typedef struct {
    uint8_t wr_idx;         /**< Index of next char to store */
    uint8_t rd_idx;         /**< Index of next char to print */
    volatile uint8_t count; /**< Number of bytes in the buffer. */
} debug_uart_context_t;

SI_SEGMENT_VARIABLE(debug_uart_ctx, debug_uart_context_t, UART_CONTEXT_SEG);
SI_SEGMENT_VARIABLE(debug_uart_buf[UART_BUFFER_LEN], uint8_t, UART_BUFFER_SEG);

/* Main UART0 Interrupt Handler */
void debug_uart_handle_uart0_isr(void)
{
    if (SCON0 & SCON0_TI__BMASK)
    {
        SCON0_TI = 0;

        if (--debug_uart_ctx.count)
        {
            /* More data remains. */
            SBUF0 = debug_uart_buf[debug_uart_ctx.rd_idx++];
            if (debug_uart_ctx.rd_idx == UART_BUFFER_LEN)
            {
                debug_uart_ctx.rd_idx = 0;
            }
        }
    }
}

void memclrx(SI_VARIABLE_SEGMENT_POINTER(buf, uint8_t, UART_BUFFER_SEG), uint8_t size)
{
    while(size)
    {
        *buf = 0;
        buf++;
        size--;
    }
}

void debug_uart_init(void)
{
    memclrx(debug_uart_buf, UART_BUFFER_LEN);
}

static void debug_uart_kick_tx(void)
{
	uint8_t c = debug_uart_buf[debug_uart_ctx.rd_idx++];

    /* Update the rd_idx since this character has already
       been read into SBUF0. */
    if(debug_uart_ctx.rd_idx == UART_BUFFER_LEN)
    {
        debug_uart_ctx.rd_idx = 0;
    }

    /* Start the transmission. */
    SBUF0 = c;
}

void debug_uart_write_buf(uint8_t *buf, uint8_t size)
{
    uint8_t to_write;
    uint8_t buf_space;

    while (size)
    {
        to_write = size > UART_BUFFER_LEN ? UART_BUFFER_LEN : size;

        /* Wait for the space to be free. */
        while (debug_uart_ctx.count > (UART_BUFFER_LEN - to_write))
        {
            /* Spin... */
        }

        /* Disable UART0 interrupt. */
        IE_ES0 = 0;

        /* Determine how much we can copy at once. */
        buf_space = UART_BUFFER_LEN - debug_uart_ctx.wr_idx;

        if (to_write > buf_space)
        {
            to_write = buf_space;
        }

        memcpy(&debug_uart_buf[debug_uart_ctx.wr_idx], buf, to_write);
        buf  += to_write;
        size -= to_write;

        debug_uart_ctx.wr_idx += to_write;
        if (debug_uart_ctx.wr_idx == UART_BUFFER_LEN)
        {
            debug_uart_ctx.wr_idx = 0;
        }

        /* Decide if we need to kick off the TX. */
        if (debug_uart_ctx.count == 0)
        {
            debug_uart_kick_tx();
        }
        debug_uart_ctx.count += to_write;

        /* Reenable UART0 interrupt. */
        IE_ES0 = 1;
    }
}

void debug_uart_write_char(char c)
{
    while (debug_uart_ctx.count == UART_BUFFER_LEN)
    {
        /* Spin... */
    }

    /* Disable UART0 interrupt. */
    IE_ES0 = 0;

    debug_uart_buf[debug_uart_ctx.wr_idx++] = c;
    if (debug_uart_ctx.wr_idx == UART_BUFFER_LEN)
    {
        debug_uart_ctx.wr_idx = 0;
    }

    ++debug_uart_ctx.count;

    /* Was this the first byte written? */
    if (debug_uart_ctx.count == 1)
    {
        debug_uart_kick_tx();
    }

    /* Reenable UART0 interrupt. */
    IE_ES0 = 1;
}
