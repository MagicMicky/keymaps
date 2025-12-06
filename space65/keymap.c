/* Copyright 2020 Rys Sommefeldt
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#define _BL 0
#define _FL 1

// Custom keycodes
enum custom_keycodes {
    OS_COLOR = QK_USER_0
};

//LOCK SCREEN key for osx
#define KC_LOCK LCTL(LSFT(KC_PWR))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BL] = LAYOUT(
        QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC, KC_GRV,
        KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_MPRV,
        MO(_FL),          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,           KC_MNXT,
        KC_LSFT, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_MPLY,
        KC_LCTL, KC_LALT, KC_LGUI,                   KC_SPC,  KC_SPC,  KC_SPC,           KC_RALT, MO(_FL),                   KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_FL] = LAYOUT(
        QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_DEL,  KC_LOCK,
        _______,          UG_TOGG, UG_NEXT, UG_HUEU, UG_HUED, UG_SATU, UG_SATD, UG_VALU, UG_VALD, OS_COLOR, _______, _______, _______, _______, KC_VOLD,
        MO(_FL),          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_VOLU,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_PGUP, KC_MUTE,
        _______, _______, _______,                   _______, _______, _______,          _______, _______,                   KC_HOME, KC_PGDN, KC_END
    ),
};

// Store detected OS globally
static os_variant_t current_os = OS_UNSURE;
static uint8_t saved_hue = 0;
static uint8_t saved_sat = 0;
static uint8_t saved_val = 0;
static uint8_t saved_mode = 0;
static bool os_detected = false;

// Helper function to set color based on OS
void set_os_color(os_variant_t os) {
    switch (os) {
        case OS_MACOS:
        case OS_IOS:
        case OS_LINUX:
            // Set to pink for macOS/iOS/Linux
            rgblight_sethsv_noeeprom(HSV_PURPLE);
            break;
        case OS_WINDOWS:
            // Set to blue for Windows
            rgblight_sethsv_noeeprom(HSV_CYAN);
            break;
        case OS_UNSURE:
        default:
            // Set to white for default
            rgblight_sethsv_noeeprom(HSV_WHITE);
            break;
    }
}

// Callback to restore previous RGB settings after showing OS color
uint32_t restore_rgb_callback(uint32_t trigger_time, void* cb_arg) {
    // Restore previous RGB settings (or turn off if they were off)
    if (saved_mode == 0 || saved_val == 0) {
        rgblight_disable_noeeprom();
    } else {
        rgblight_sethsv_noeeprom(saved_hue, saved_sat, saved_val);
        rgblight_mode_noeeprom(saved_mode);
    }
    return 0; // Don't repeat
}

// Keyboard initialization - save RGB settings then turn off until OS is detected
void keyboard_post_init_user(void) {
    // Read and save RGB settings from EEPROM before turning off
    saved_hue = rgblight_get_hue();
    saved_sat = rgblight_get_sat();
    saved_val = rgblight_get_val();
    saved_mode = rgblight_get_mode();

    // Turn off RGB until OS detection
    rgblight_disable_noeeprom();
}

// OS Detection callback to set RGB lighting based on OS
bool process_detected_host_os_user(os_variant_t detected_os) {
    current_os = detected_os;
    os_detected = true;

    // Enable RGB and show OS color with breathing effect
    rgblight_enable_noeeprom();
    set_os_color(detected_os);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3); // Breathing mode

    // Schedule restoration of previous color after 3 seconds (3000ms)
    defer_exec(3000, restore_rgb_callback, NULL);

    return true;
}

// Handle custom keycodes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case OS_COLOR:
            if (record->event.pressed) {
                set_os_color(current_os);
            }
            return false;
    }
    return true;
}
