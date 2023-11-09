/* Copyright 2023 Christoffer Arvidsson
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

#include "features/achordion.h"
#include "features/casemodes.h"

enum planck_layers {
    _COLEMAK,
    _MEDIA,
    _NAV,
    _PROG,
    _SYM,
    _NUM,
    _FUN,
};

enum custom_keycodes { CAPSWORD = SAFE_RANGE, SNAKECASE, SCREAMSNAKECASE, CU_RPTR, CU_LPTR };

#define LT_MEDIA LT(_MEDIA, KC_ESC)
#define LT_NAV LT(_NAV, KC_SPC)
#define LT_PROG LT(_PROG, KC_TAB)
#define LT_SYM LT(_SYM, KC_ENT)
#define LT_NUM LT(_NUM, KC_BSPC)
#define LT_FUN LT(_FUN, KC_DEL)
#define MT_Z MT(MOD_RALT, KC_Z)
#define MT_A MT(MOD_LCTL, KC_A)
#define MT_R MT(MOD_LALT, KC_R)
#define MT_S MT(MOD_LGUI, KC_S)
#define MT_T MT(MOD_LSFT, KC_T)
#define MT_N MT(MOD_LSFT, KC_N)
#define MT_E MT(MOD_LGUI, KC_E)
#define MT_I MT(MOD_LALT, KC_I)
#define MT_O MT(MOD_LCTL, KC_O)
#define MT_SLSH MT(MOD_RALT, KC_SLSH)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_COLEMAK] = LAYOUT_planck_grid(
    KC_Q,     KC_W,    KC_F,     KC_P,    KC_B,     KC_NO, KC_NO, KC_J,    KC_L,      KC_U,             KC_Y,     KC_QUOT,
    MT_A,     MT_R,    MT_S,     MT_T,    KC_G,     KC_NO, KC_NO, KC_M,    MT_N,      MT_E,             MT_I,     MT_O,
    MT_Z,     KC_X,    KC_C,     KC_D,    KC_V,     KC_NO, KC_NO, KC_K,    KC_H,      KC_COMM,          KC_DOT,   MT_SLSH,
    KC_NO,    KC_NO,   LT_MEDIA, LT_NAV,  LT_PROG,  KC_NO, KC_NO, LT_SYM,  LT_NUM,    LT_FUN,           KC_NO,    KC_NO
    ),
[_MEDIA] = LAYOUT_planck_grid(
    QK_BOOT,  KC_NO,   KC_NO,    KC_NO,   KC_NO,    KC_NO, KC_NO, RGB_TOG, LED_LEVEL, RGB_MODE_FORWARD, RGB_HUI,  RGB_HUD,
    KC_LCTL,  KC_LALT, KC_LGUI,  KC_LSFT, KC_NO,    KC_NO, KC_NO, KC_MPRV, KC_MSTP,   KC_MPLY,          KC_MNXT,  KC_MUTE,
    KC_RALT,  KC_NO,   KC_NO,    KC_NO,   KC_NO,    KC_NO, KC_NO, KC_NO,   KC_VOLD,   KC_VOLU,          KC_NO,    KC_NO,
    KC_NO,    KC_NO,   KC_NO,    KC_NO,   KC_NO,    KC_NO, KC_NO, KC_NO,   KC_NO,     KC_NO,            KC_NO,    KC_NO
    ),
[_NAV] = LAYOUT_planck_grid(
    QK_BOOT,  KC_NO,   KC_NO,    KC_NO,   KC_NO,    KC_NO, KC_NO, KC_NO,   KC_NO,     KC_NO,            KC_NO,    KC_NO,
    KC_LCTL,  KC_LALT, KC_LGUI,  KC_LSFT, KC_NO,    KC_NO, KC_NO, KC_LEFT, KC_DOWN,   KC_UP,            KC_RIGHT, KC_NO,
    KC_RALT,  KC_NO,   KC_NO,    KC_NO,   KC_NO,    KC_NO, KC_NO, KC_NO,   KC_PGDN,   KC_PGUP,          KC_NO,    KC_NO,
    KC_NO,    KC_NO,   KC_NO,    KC_NO,   KC_NO,    KC_NO, KC_NO, KC_NO,   KC_NO,     KC_NO,            KC_NO,    KC_NO
    ),
[_PROG] = LAYOUT_planck_grid(
    QK_BOOT,  KC_NO,   KC_NO,    KC_NO,   KC_NO,    KC_NO, KC_NO, KC_NO,   KC_LPRN,   KC_RPRN,          KC_CAPS,  SCREAMSNAKECASE,
    KC_LCTL,  KC_LALT, KC_LGUI,  KC_LSFT, KC_NO,    KC_NO, KC_NO, CU_LPTR, KC_LBRC,   KC_RBRC,          CU_RPTR,  CAPSWORD,
    KC_RALT,  KC_NO,   KC_NO,    KC_NO,   KC_NO,    KC_NO, KC_NO, KC_NO,   KC_LCBR,   KC_RCBR,          KC_NO,    SNAKECASE,
    KC_NO,    KC_NO,   KC_NO,    KC_NO,   KC_NO,    KC_NO, KC_NO, KC_NO,   KC_NO,     KC_NO,            KC_NO,    KC_NO
    ),

[_SYM] = LAYOUT_planck_grid(
    KC_NO,    KC_AMPR, KC_ASTR,  KC_LPRN, KC_NO,    KC_NO, KC_NO, KC_NO,   KC_NO,     KC_NO,            KC_NO,    QK_BOOT,
    KC_COLN,  KC_DLR,  KC_PERC,  KC_CIRC, KC_PLUS,  KC_NO, KC_NO, KC_NO,   KC_LSFT,   KC_LGUI,          KC_LALT,  KC_LCTL,
    KC_TILD,  KC_EXLM, KC_AT,    KC_HASH, KC_PIPE,  KC_NO, KC_NO, KC_NO,   KC_NO,     KC_NO,            KC_NO,    KC_RALT,
    KC_NO,    KC_NO,   KC_NO,    KC_RPRN, KC_UNDS,  KC_NO, KC_NO, KC_NO,   KC_NO,     KC_NO,            KC_NO,    KC_NO
    ),
[_NUM] = LAYOUT_planck_grid(
    KC_NO,    KC_7,    KC_8,     KC_9,    KC_NO,    KC_NO, KC_NO, KC_NO,   KC_NO,     KC_NO,            KC_NO,    QK_BOOT,
    KC_SCLN,  KC_4,    KC_5,     KC_6,    KC_EQL,   KC_NO, KC_NO, KC_NO,   KC_LSFT,   KC_LGUI,          KC_LALT,  KC_LCTL,
    KC_GRAVE, KC_1,    KC_2,     KC_3,    KC_BSLS,  KC_NO, KC_NO, KC_NO,   KC_NO,     KC_NO,            KC_NO,    KC_RALT,
    KC_NO,    KC_NO,   KC_NO,    KC_0,    KC_MINS,  KC_NO, KC_NO, KC_NO,   KC_NO,     KC_NO,            KC_NO,    KC_NO
    ),
[_FUN] = LAYOUT_planck_grid(
    KC_F12,   KC_F7,   KC_F8,    KC_F9,   KC_PSCR,  KC_NO, KC_NO, KC_NO,   KC_NO,     KC_NO,            KC_NO,    QK_BOOT,
    KC_F11,   KC_F4,   KC_F5,    KC_F6,   KC_SCRL,  KC_NO, KC_NO, KC_NO,   KC_LSFT,   KC_LGUI,          KC_LALT,  KC_LCTL,
    KC_F10,   KC_F1,   KC_F2,    KC_F3,   KC_PAUSE, KC_NO, KC_NO, KC_NO,   KC_NO,     KC_NO,            KC_NO,    KC_RALT,
    KC_NO,    KC_NO,   KC_NO,    KC_NO,   KC_NO,    KC_NO, KC_NO, KC_NO,   KC_NO,     KC_NO,            KC_NO,    KC_NO
    )
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_achordion(keycode, record)) {
        return false;
    }
    if (!process_case_modes(keycode, record)) {
        return false;
    }

    switch (keycode) {
        case CAPSWORD:
            if (record->event.pressed) {
                enable_caps_word();
            }
            return false;
        case SCREAMSNAKECASE:
            if (record->event.pressed) {
                enable_caps_word();
                enable_xcase_with(KC_UNDS);
            }
            return false;
        case SNAKECASE:
            if (record->event.pressed) {
                enable_xcase_with(KC_UNDS);
            }
            return false;
        case CU_RPTR:
            if (record->event.pressed) {
                SEND_STRING("->");
            }
            break;
        case CU_LPTR:
            if (record->event.pressed) {
                SEND_STRING("<-");
            }
            break;
        default:
            return true;
    }

    return true;
}

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record, uint16_t other_keycode, keyrecord_t* other_record) {
    // Also allow same-hand holds when the other key is in the rows below the
    // alphas.
    if (other_record->event.key.row % (MATRIX_ROWS / 2) >= 3) {
        return true;
    }

    // Otherwise, follow the opposite hands rule.
    return achordion_opposite_hands(tap_hold_record, other_record);
}

void matrix_scan_user(void) {
    achordion_task();
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    switch (tap_hold_keycode) {
        case LT_MEDIA:
        case LT_NAV:
        case LT_PROG:
        case LT_SYM:
        case LT_NUM:
        case LT_FUN:
            return 0;
    }

    return 800;
}

bool achordion_eager_mod(uint8_t mod) {
    switch (mod) {
        case MOD_LGUI:
        case MOD_RGUI:
            return true;

        default:
            return false;
    }
}

// Template
// KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
// KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
// KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
// KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO

// Left
// QK_BOOT,    KC_NO,    KC_NO,    KC_NO,    KC_NO, KC_NO
// MOD_LCTL, MOD_LALT, MOD_LGUI, MOD_LSFT, KC_NO, KC_NO
// KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO, KC_NO
// KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO, KC_NO

// Right
// KC_NO, KC_NO, KC_NO,    KC_NO,    KC_NO,    QK_BOOT
// KC_NO, KC_NO, MOD_LSFT, MOD_LGUI, MOD_LALT, MOD_LCTL
// KC_NO, KC_NO, KC_NO,    KC_NO,    KC_NO,    KC_NO
// KC_NO, KC_NO, KC_NO,    KC_NO,    KC_NO,    KC_NO
