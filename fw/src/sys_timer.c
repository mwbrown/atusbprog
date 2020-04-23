
#include "sys_timer.h"

#include <SI_EFM8UB1_Register_Enums.h>

static uint16_t systick;

void sys_timer_handle_tmr4_isr(void)
{
    uint8_t SFRPAGE_save = SFRPAGE;
    SFRPAGE = 0x10;

    if (TMR4CN0_TF4H)
    {
        TMR4CN0_TF4H = 0;
        systick++;
    }

    SFRPAGE = SFRPAGE_save;
}

uint16_t sys_timer_get_tick(void)
{
    uint16_t ret;

    /* Have to disable interrupts to do an atomic read. */
    IE_EA = 0;
    ret = systick;
    IE_EA = 1;

    return systick;
}
