
#ifndef __DEBUG_UART_H__
#define __DEBUG_UART_H__

#include <stdint.h>

void debug_uart_init(void);
void debug_uart_write_buf(uint8_t *buf, uint8_t size);
void debug_uart_write_char(char c);

#endif /* __DEBUG_UART_H__ */
