#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _FL 1

//LOCK SCREEN key for osx
#define KC_LOCK LCTL(LSFT(KC_POWER))

//automator to Hide Slack
#define KC_HSLK LCTL(LSFT(LGUI(KC_M)))
//automator to Open/Activate iterm
#define KC_OTRM LCTL(LSFT(LGUI(KC_SLSH)))
//automator to Open/Activate Chrome
#define KC_OCRM LCTL(LSFT(LGUI(KC_COMM)))
//automator to Open/Activate Code
#define KC_OCDE LCTL(LSFT(LGUI(KC_DOT)))
//automator to Open/Activate Slack
#define KC_OSLK LCTL(LSFT(LGUI(KC_SCLN)))

#define _______ KC_TRNS

//Enable a key that will open or hide slack based on how quick I type it
//1 tap: KC_OSLK
//2 tap: KC_HSLK
enum {
  TD_SLK = 0
};

qk_tap_dance_action_t tap_dance_actions[]  = {
  [TD_SLK] = ACTION_TAP_DANCE_DOUBLE(KC_OSLK, KC_HSLK)
};

#define KC_SLK TD(TD_SLK)

//Keyboards definition

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer)
   * ,----------------------------------------------------------------.
   * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |~ ` |
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  | << |
   * |----------------------------------------------------------------|
   * |FN     |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return | >> |
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up| >| |
   * |----------------------------------------------------------------|
   * |Ctrl|Alt |CMD |        Space          | Slk|FN|Trm |Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
[_BL] = LAYOUT_ansi(
  KC_ESC,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_BSPC,KC_GRV, \
  KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC,KC_BSLS,KC_MPRV, \
  MO(_FL), KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,         KC_ENT,KC_MNXT,  \
  KC_LSFT,         KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,   KC_RSFT,KC_UP,KC_MPLY, \
  KC_LCTL, KC_LALT,KC_LGUI,                KC_SPC,                        KC_SLK,MO(_FL),KC_OTRM, KC_LEFT,KC_DOWN,KC_RGHT),

  /* Keymap _FL: Function Layer
   * ,----------------------------------------------------------------.
   * |   | F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del    |LCK |
   * |----------------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   |   |   |   |   |     | V- |
   * |----------------------------------------------------------------|
   * |      |   |   |   |   |   |   |   |   |   |   |   |        | V+ |
   * |----------------------------------------------------------------|
   * |        |   |   |Bl-|BL |BL+|BLB|   |   |   |   |      |   | Vm |
   * |----------------------------------------------------------------|
   * |    |    |    |                       | Crm|  |Cde |   |   |    |
   * `----------------------------------------------------------------'
   */
[_FL] = LAYOUT_ansi(
  _______, KC_F1 ,KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_LOCK ,  \
  _______,_______,_______,_______,_______, _______,_______,_______,_______,_______,_______,_______,_______, _______,KC_VOLD, \
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,        _______,KC_VOLU, \
  _______,_______,_______,BL_DEC, BL_TOGG,BL_INC, BL_BRTG,_______,_______,_______,_______,_______,     KC_MS_U,KC_MUTE, \
  _______,_______,_______,                 _______,               KC_OCRM,_______,KC_OCDE,KC_MS_L,KC_MS_D, KC_MS_R),
};
