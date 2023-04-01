#include QMK_KEYBOARD_H

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  QGMLWB,
};

enum layer_names {
    _QWERTY,
    _QGMLWB,
    _LOWER,
    _RAISE,
    _ADJUST
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
#define CTL_ESC LCTL_T(KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,---------------------------------------s--------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------|------|------|------|------|-------------|------|------|------|------|------|
 * |ctlesc|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------|------|------|------|------|------|------|------|------|------|------|------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------|------|------|------|------|------|------|------|------|------|------|------|
 * |_TEXT | Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 * ctlesc - left control when held, esc when tapped
 */
[_QWERTY] = LAYOUT_ortho_4x12(
  KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  CTL_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  SC_LSPO,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFTENT,
  _______,  KC_LCTL, KC_LALT, KC_LGUI, KC_DEL, LOW_SPC, HI_SPC,  KC_BSPC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT 
),

/* QGMLWB
 * ,-----------------------------------------------------------------------------------,
 * | Tab  |   Q  |   G  |   M  |   L  |   W  |   B  |   Y  |   U  |   V  |   ;  | Bksp |
 * |------|------|------|------|------|-------------|------|------|------|------|------|
 * |ctlesc|   D  |   S  |   T  |   N  |   R  |   I  |   A  |   E  |   O  |   H  |  "   |
 * |------|------|------|------|------|------|------|------|------|------|------|------|
 * | Shift|   Z  |   X  |   C  |   F  |   J  |   K  |   P  |   ,  |   .  |   /  |Enter |
 * |------|------|------|------|------|------|------|------|------|------|------|------|
 * | Lead | Ctrl | Alt  | GUI  | del  |Space |Space | BKSP | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 * ctlesc - left control when held, esc when tapped
 */
[_QGMLWB] = LAYOUT_ortho_4x12(
   KC_TAB,   KC_Q,    KC_G,    KC_M,    KC_L,    KC_W,    KC_B,   KC_Y,    KC_U,    KC_V,    KC_SCLN, KC_BSPC, 
   CTL_ESC,  KC_D,    KC_S,    KC_T,    KC_N,    KC_R,    KC_I,   KC_A,    KC_E,    KC_O,    KC_H,    KC_QUOT, 
   SC_LSPO,  KC_Z,    KC_X,    KC_C,    KC_F,    KC_J,    KC_K,   KC_P,    KC_COMM, KC_DOT,  KC_SLSH, SFTENT, 
   _______,  KC_LCTL, KC_LALT, KC_LGUI, KC_DEL,  LOW_SPC, HI_SPC, KC_BSPC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   `  |      |   [  |   ]  |   -  |   =  |   _  |   +  |   {  |   }  | Del  |
 * |------|------|------|------|------|------|------|------|------|------|------|------|
 * |  Del |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  |   |
 * |------|------|------|------|------|------|------|------|------|------|------|------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | F11  |  F12 |
 * |------|------|------|------|------|------|------|------|------|------|------|------|
 * |      |      |      |      |      |      |       |     | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( 
  KC_TILD, KC_GRV,  _______, KC_LBRC, KC_RBRC, KC_MINS, KC_EQL, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_BSPC, 
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, 
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, 
  _______, _______, DF(_QWERTY), DF(_QGMLWB), _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY 
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  `   |      | cHome|  Up  |  End |      |      |   -  |   =  |   [  |   ]  |  Del |
 * |------|------|------|------|------|-------------|------|------|------|------|------|
 * | lAlt | Lshft| Left | Down | Right| Undo |      | LCTL |      |      |      |   \  |
 * |------|------|------|------|------|------|------|------|------|------|------|------|
 * |      |      |  CUT | COPY | PSTE |QWERTY| Redo |      |      |      |      |      |
 * |------|------|------|------|------|------|------|------|------|------|------|------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 * CTRL when Held, Home when tapped
 */
[_LOWER] = LAYOUT_ortho_4x12( 
  KC_GRV,  _______, CTL_T(KC_HOME), KC_UP,    KC_END,  _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSPC, 
  KC_LALT, KC_LSFT, KC_LEFT, KC_DOWN,  KC_RGHT, LCTL(KC_Z), _______, KC_LCTL, _______, _______, _______, KC_BSLS, 
  _______, _______, LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), LCTL(KC_Y), _______, _______, _______, _______, _______, _______, 
  _______, QWERTY, _______, _______,  _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY 
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | RESET|      |      |      |      |      |      |      |      |      |  Del |
 * |------|------|------|------|------|-------------|------|------|------|------|------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|QGMLWB|      |      |      |
 * |------|------|------|------|------|------|------|------|------|------|------|------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------|------|------|------|------|------|------|------|------|------|------|------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12( 
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY, QGMLWB, _______,  _______, _______, 
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ 
),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
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
