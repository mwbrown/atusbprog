
#ifndef __EFM8_CONFIG_H__
#define __EFM8_CONFIG_H__

//
// Pinout definitions for GPIO (SLSTK2000A)
//

#define PIN_PB0         P0_B2   /**< Pushbutton PB0 */
#define PIN_PB1         P0_B3   /**< Pushbutton PB1 */

#define PIN_AT_RST      P1_B1   /**< Atmel RST pin (active-high) */
#define PIN_AT_OE_N     P1_B2   /**< Atmel OE for atusbprog buffer */
#define PIN_AT_AUX      P1_B3   /**< Atmel AUX pin on atusbprog buffer */

#define PIN_LED_GRN     P1_B4   /**< RGB led, green segment */
#define PIN_LED_BLU     P1_B5   /**< RGB led, blue segment */
#define PIN_LED_RED     P1_B6   /**< RGB led, red segment */

#define PIN_DISP_CS     P0_B1
#define PIN_DISP_EN     P1_B3

#endif // __EFM8_CONFIG_H__
