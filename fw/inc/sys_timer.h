#ifndef __SYS_TIMER_H__
#define __SYS_TIMER_H__

#include <stdint.h>

uint16_t sys_timer_get_tick(void);

/* To be called only by the TIMER4 ISR */
void sys_timer_handle_tmr4_isr(void);

#endif
