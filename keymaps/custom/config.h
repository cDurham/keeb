#pragma once

/* Use I2C or Serial, not both */
#define USE_I2C

/* Select hand configuration */
#define MASTER_LEFT
#define SPLIT_USB_DETECT
#define FLIP_HALF

#define TAPPING_TERM 175

// Auto Shift settings
#define AUTO_SHIFT_TIMEOUT 165
/* By default, Auto Shift is disabled for any key
 * press that is accompanied by one or more modifiers.
 * DEFAULT STATE IS REMOVED (or commented out)
 */
#define AUTO_SHIFT_MODIFIERS

// #define LEADER_TIMEOUT 300
