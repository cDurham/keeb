#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x3060
#define DEVICE_VER      0x0001
#define MANUFACTURER    Nahhh
#define PRODUCT         Lets Split vCustom
#define DESCRIPTION     A split keyboard for the cheap makers

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 8
#define MATRIX_COLS 6

// wiring of each half
// rows run top to botttom, cols run left to right
#define DIODE_DIRECTION COL2ROW

// right hand: A0 A1 A2 A3 A4 A5
#define MATRIX_COL_PINS_RIGHT { F7, F6, F5, F4, F1, F0 }
// row pins: 9 10 6 5
#define MATRIX_ROW_PINS_RIGHT { B5, B6, D7, C6 }

// left hand: A0 A1 A2 A3 A5 A4
#define MATRIX_COL_PINS { F7, F6, F5, F4, F0, F1 }
// row pins: 9 6 10 5
#define MATRIX_ROW_PINS { B5, D7, B6, C6 }

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE
