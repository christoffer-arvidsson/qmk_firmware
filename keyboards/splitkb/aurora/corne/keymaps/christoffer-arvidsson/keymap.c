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

enum corne_layers {
    _COLEMAK,
    _NAV,
    _PROG,
    _MEDIA,
    _SYM,
    _NUM,
    _FUN,
};

// clang-format off
enum custom_keycodes {
    CU_CAPSWORD = SAFE_RANGE,
    CU_LSNKCASE,
    CU_USNKCASE,
    CU_RPTR,
    CU_LPTR
};
// clang-format on

#define LT_MEDIA LT(_MEDIA, KC_ESC)
#define LT_NAV LT(_NAV, KC_SPC)
#define LT_PROG LT(_PROG, KC_TAB)
#define LT_SYM LT(_SYM, KC_ENT)
#define LT_NUM LT(_NUM, KC_BSPC)
/* #define LT_FUN LT(_FUN, KC_DEL) */
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

// Just for cleaner readable keymaps (XXXXXXX is too blocky)
#define _______ KC_NO

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_COLEMAK] = LAYOUT_split_3x6_3(
    _______, KC_Q,     KC_W,    KC_F,     KC_P,    KC_B,             KC_J,    KC_L,      KC_U,    KC_Y,     KC_QUOT, _______,
    _______, MT_A,     MT_R,    MT_S,     MT_T,    KC_G,             KC_M,    MT_N,      MT_E,    MT_I,     MT_O, _______,
    _______, MT_Z,     KC_X,    KC_C,     KC_D,    KC_V,             KC_K,    KC_H,      KC_COMM, KC_DOT,   MT_SLSH, _______,
                             LT_MEDIA, LT_NAV,  LT_PROG,             LT_SYM,  LT_NUM,    QK_REP
    ),
[_NAV] = LAYOUT_split_3x6_3(
    _______, QK_BOOT,  _______, _______,  _______, _______,          _______, _______,   _______, _______,  _______, _______,
    _______, KC_LCTL,  KC_LALT, KC_LGUI,  KC_LSFT, _______,          KC_LEFT, KC_DOWN,   KC_UP,   KC_RIGHT, _______, _______,
    _______, KC_RALT,  _______, _______,  _______, _______,          _______, KC_PGDN,   KC_PGUP, _______,  _______, _______,
                                _______,  _______, _______,          _______, _______,   _______
    ),
[_PROG] = LAYOUT_split_3x6_3(
    _______, QK_BOOT,  _______, _______,  _______, _______,          _______, KC_LPRN,   KC_RPRN, KC_CAPS,  CU_USNKCASE, _______,
    _______, KC_LCTL,  KC_LALT, KC_LGUI,  KC_LSFT, _______,          CU_LPTR, KC_LBRC,   KC_RBRC, CU_RPTR,  CU_CAPSWORD, _______,
    _______, KC_RALT,  _______, _______,  _______, _______,          _______, KC_LCBR,   KC_RCBR, _______,  CU_LSNKCASE, _______,
                                _______,  _______, _______,          _______, _______,   _______
    ),
[_MEDIA] = LAYOUT_split_3x6_3(
    _______, QK_BOOT,  _______, _______,  _______, _______,          _______, _______,   _______, _______,  _______, _______,
    _______, KC_LCTL,  KC_LALT, KC_LGUI,  KC_LSFT, _______,          KC_MPRV, KC_MSTP,   KC_MPLY, KC_MNXT,  KC_MUTE, _______,
    _______, KC_RALT,  _______, _______,  _______, _______,          _______, KC_VOLD,   KC_VOLU, _______,  _______, _______,
                                _______,  _______, _______,          _______, _______,   _______
    ),
[_SYM] = LAYOUT_split_3x6_3(
    _______, _______,  KC_AMPR, KC_ASTR,  KC_LPRN, _______,          _______, _______,   _______, _______,  QK_BOOT, _______,
    _______, KC_COLN,  KC_DLR,  KC_PERC,  KC_CIRC, KC_PLUS,          _______, KC_LSFT,   KC_LGUI, KC_LALT,  KC_LCTL, _______,
    _______, KC_TILD,  KC_EXLM, KC_AT,    KC_HASH, KC_PIPE,          _______, _______,   _______, _______,  KC_RALT, _______,
                                _______,  KC_RPRN, KC_UNDS,          LT_SYM,  LT_NUM,    _______
    ),
[_NUM] = LAYOUT_split_3x6_3(
    _______, _______,  KC_7,    KC_8,     KC_9,    _______,          _______, _______,   _______, _______,  QK_BOOT, _______,
    _______, KC_SCLN,  KC_4,    KC_5,     KC_6,    KC_EQL,           _______, KC_LSFT,   KC_LGUI, KC_LALT,  KC_LCTL, _______,
    _______, KC_GRAVE, KC_1,    KC_2,     KC_3,    KC_BSLS,          _______, _______,   _______, _______,  KC_RALT, _______,
                                _______,  KC_0,    KC_MINS,          LT_SYM,  LT_NUM,    _______
    ),
[_FUN] = LAYOUT_split_3x6_3(
    _______, KC_F12,   KC_F7,   KC_F8,    KC_F9,   KC_PSCR,          _______, _______,   _______, _______,  QK_BOOT, _______,
    _______, KC_F11,   KC_F4,   KC_F5,    KC_F6,   KC_SCRL,          _______, KC_LSFT,   KC_LGUI, KC_LALT,  KC_LCTL, _______,
    _______, KC_F10,   KC_F1,   KC_F2,    KC_F3,   KC_PAUSE,         _______, _______,   _______, _______,  KC_RALT, _______,
                                _______,  _______, _______,          LT_SYM,  LT_NUM,    _______
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
        // Tri-layer shenanigans
        //   https://www.reddit.com/r/olkb/comments/4x3dei/hack_too_ugly_to_live/
        case LT_NUM:
            if (record->event.pressed) {
                layer_on(_NUM);
            } else {
                layer_off(_NUM);
            }
            update_tri_layer(_NUM, _SYM, _FUN);
            break;

        case LT_SYM:
            if (record->event.pressed) {
                layer_on(_SYM);
            } else {
                layer_off(_SYM);
            }
            update_tri_layer(_NUM, _SYM, _FUN);
            break;
        // END Tri-layer shenanigans

        case CU_CAPSWORD:
            if (record->event.pressed) {
                enable_caps_word();
            }
            return false;
        case CU_USNKCASE:
            if (record->event.pressed) {
                enable_caps_word();
                enable_xcase_with(KC_UNDS);
            }
            return false;
        case CU_LSNKCASE:
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
        /* case LT_FUN: */
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


// clang-format off
// Template
//      _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,
//      _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,
//      _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,
//                                 _______, _______, _______,                    _______, _______, _______,
