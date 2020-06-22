#pragma once

/* Use I2C or Serial, not both */
#define USE_I2C

/* Select hand configuration */
#define MASTER_LEFT
#define SPLIT_USB_DETECT
#define FLIP_HALF

// Auto Shift settings
// #define AUTO_SHIFT_TIMEOUT 165
/* 
 * By default, Auto Shift is disabled for any key
 * press that is accompanied by one or more modifiers.
 */
// #define AUTO_SHIFT_MODIFIERS

#define TAPPING_TERM 200
/**
 * resets the timeout after each key is tapped
 */
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 300
