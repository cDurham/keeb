#include QMK_KEYBOARD_H
// #include "quantum.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _QGMLWB 1
#define _LOWER 2
#define _RAISE 3
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  QGMLWB,
  MY_HASH,
};

/**
 * Each enum must have a different number to function correctly
 */
enum {
  SPC_DEL = 0,
  SPC_BKS = 1,
  BSPC_DEL = 2,
  F4_ALT = 3,
  TD_RESET
};

void safe_reset(qk_tap_dance_state_t *state, void *user_data) {
    // TD_RESET the keyboard if you tap the key more than three times
    if (state->count >= 3) {
      reset_keyboard();
      reset_tap_dance(state);
    }
};

/**
 * NOTE: tap dance keys will no longer activate AUTO_SHIFT
 */
qk_tap_dance_action_t tap_dance_actions[] = {
  [F4_ALT] = ACTION_TAP_DANCE_DOUBLE(KC_F4, LALT(KC_F4)),
  [TD_RESET] = ACTION_TAP_DANCE_FN(safe_reset)
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define TEXT MO(_TEXT)
#define ADJUST MO(_ADJUST)

#define SFTENT MT(MOD_RSFT, KC_ENT)
#define SFT_N MT(MOD_LSFT, KC_N)
#define CTRL_T MT(MOD_LCTL, KC_T)
#define ALT_S MT(MOD_LALT, KC_S)
#define LOW_SPC LT(LOWER, KC_SPC)
#define HI_SPC LT(RAISE, KC_SPC)
#define SFT_A MT(MOD_RSFT, KC_A)
#define CTL_E MT(MOD_RCTL, KC_E)
#define ALT_O MT(MOD_RALT, KC_O)
#define LSFT_DEL MT(MOD_LSFT, KC_DEL)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,---------------------------------------s--------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |ctlesc|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |_TEXT | Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 * ctlesc - left control when held, esc when tapped
 */
[_QWERTY] = LAYOUT_ortho_4x12( \
  KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, \
  LCTL_T(KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  LSFT_DEL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM, KC_DOT,  KC_SLSH, SFTENT, \
  KC_LEAD, KC_LCTL, KC_LALT, KC_LGUI, KC_DEL, LOW_SPC, HI_SPC,  MY_HASH, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),

/* QGMLWB
 * ,-----------------------------------------------------------------------------------,
 * | Tab  |   Q  |   G  |   M  |   L  |   W  |   B  |   Y  |   U  |   V  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |ctlesc|   D  |   S  |   T  |   N  |   R  |   I  |   A  |   E  |   O  |   H  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   F  |   J  |   K  |   P  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Lead | Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 * ctlesc - left control when held, esc when tapped
 */
[_QGMLWB] = LAYOUT_ortho_4x12( \
   KC_TAB,  KC_Q,    KC_G,    KC_M,    KC_L,    KC_W,    KC_B,   KC_Y,    KC_U,    KC_V,    KC_SCLN, KC_BSPC, \
   KC_ESC,  KC_D,    ALT_S,   CTRL_T,  SFT_N,   KC_R,    KC_I,   SFT_A,   CTL_E,   ALT_O,   KC_H,    KC_QUOT, \
   KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_F,    KC_J,    KC_K,   KC_P,    KC_COMM, KC_DOT,  KC_SLSH, SFTENT, \
   KC_LEAD, KC_LCTL, KC_LALT, KC_LGUI, KC_DEL, LOW_SPC, HI_SPC,  MY_HASH, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   `  |      |   [   |   ] |   -  |   =  |   _  |   +  |   {  |   }  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  Del |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4 |  F5  |  F6   |  F7  |  F8  |  F9  |  F10 | F11  |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |       |     | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  KC_TILD, KC_GRV,  _______, KC_LBRC, KC_RBRC, KC_MINS, KC_EQL, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_BSPC, \
  _______, KC_1,    KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
  KC_F1,   KC_F2,   KC_F3, TD(F4_ALT),KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  `   |      | cHome|  Up  |  End |      |      |   -  |   =  |   [  |   ]  |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | lAlt | Lshft| Left | Down | Right| Undo |      | LCTL |      |      |      |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |  CUT | COPY | PSTE QWERTY Redo |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 * CTRL when Held, Home when tapped
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  KC_GRV,  _______, CTL_T(KC_HOME), KC_UP,    KC_END,  _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSPC, \
  KC_LALT, KC_LSFT, KC_LEFT, KC_DOWN,  KC_RGHT, LCTL(KC_Z), _______, KC_LCTL, _______, _______, _______, KC_BSLS, \
  _______, _______, LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), LCTL(KC_Y), _______, _______, _______, _______, _______, _______, \
  QWERTY, _______, _______, _______,  _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | TD_RESET|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|QGMLWB|      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12( \
  _______, TD(TD_RESET),_______, _______, _______, _______, _______, _______, _______, _______, _______, TD(BSPC_DEL), \
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY, QGMLWB, _______,  _______, _______, \
  _______, KC_ASRP, KC_ASUP, KC_ASDN, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),
};

LEADER_EXTERNS();
void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_F) {
        // Anything you can do in a macro.
        SEND_STRING("QMK is awesome.");
    }
    SEQ_TWO_KEYS(KC_D, KC_D) {
        SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
    }
    SEQ_TWO_KEYS(KC_Z, KC_Z) {
        SEND_STRING(SS_LCTL("K") SS_LCTL("2"));
          // collapse code for vscode
    }
    SEQ_THREE_KEYS(KC_D, KC_D, KC_S) {
        SEND_STRING("https://start.duckduckgo.com\n");
    }
    SEQ_TWO_KEYS(KC_A, KC_S) {
        register_code(KC_LGUI);
        register_code(KC_S);
        unregister_code(KC_S);
        unregister_code(KC_LGUI);
    }
  }
};

layer_state_t layer_state_set_user(layer_state_t state) {
  set_single_persistent_default_layer(_QGMLWB);
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint16_t my_hash_timer;
  switch (keycode) {
    case MY_HASH:
      if(record->event.pressed) {
        my_hash_timer = timer_read();
        register_code(KC_LCTL); // Change the key to be held here
      } else {
        unregister_code(KC_LCTL); // Change the key that was held here, too!
        if (timer_elapsed(my_hash_timer) < TAPPING_TERM) {
          SEND_STRING("#"); // Change the character(s) to be sent on tap here
        }
      }
      return false; // We handled this keypress
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case QGMLWB:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QGMLWB);
      }
      return false;
  };
  return true;
};
