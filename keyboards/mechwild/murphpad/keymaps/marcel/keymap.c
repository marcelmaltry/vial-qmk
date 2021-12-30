/* Copyright 2021 Kyle McCreery
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

// Defines custom key codes
enum custom_keycodes {
    KC_P00 = SAFE_RANGE,
};


// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _MEDIA,
    _LED,
    _MACRO,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
                 _______,  _______, _______, _______,
                 KC_NLCK,  KC_PSLS, KC_PAST, KC_PEQL,
                 KC_P7,    KC_P8,   KC_P9,   KC_PMNS,
        KC_MUTE, KC_P4,    KC_P5,   KC_P6,   KC_PPLS,
     TO(_MEDIA), KC_P1,    KC_P2,   KC_P3,   KC_PENT,
        KC_BSPC, KC_P0,    KC_P00,  KC_PDOT, KC_NO,

                 _______,  _______, _______

    ),
    [_MEDIA] = LAYOUT(
                 _______, _______, _______, _______,
                 _______, _______, _______, KC_BRIU,
                 _______, _______, _______, KC_BRID,
        KC_MUTE, _______, _______, _______, _______,
       TO(_LED), _______, KC_VOLU, _______, KC_MPLY,
      TO(_BASE), KC_MPRV, KC_VOLD, KC_MNXT, KC_NO,

                 _______, _______, _______

    ),
    [_LED] = LAYOUT(
                 _______,  _______, _______, _______,
                 _______,  _______, _______, _______,
                 RGB_MOD,  RGB_HUI, RGB_SAI, RGB_SPI,
        RGB_TOG, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_SPD,
     TO(_MACRO), _______,  _______, _______, _______,
     TO(_MEDIA), _______,  _______, _______, KC_NO,

                 _______, _______, _______

    ),
    [_MACRO] = LAYOUT(
                 _______, _______, _______, _______,
                 _______, _______, _______, _______,
                 _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
      TO(_BASE), _______, _______, _______, _______,
       TO(_LED), _______, _______, _______, KC_NO,

                 _______, _______, _______

    )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_P00:
            if (record->event.pressed) {
                SEND_STRING("00");
            } else {
                // do nothing
            }
            break;
    }
    return true;
};


#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;       // flips the display 270 degrees
}

void render_qmk_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0x00
    };
    oled_write_P(qmk_logo, false);
}

void render_qmk_font_logo(void) {
    static const char PROGMEM qmk_font_logo[] = {
        0x85, 0x86, 0x87, 0x88, 0x89,
        0xA5, 0xA6, 0xA7, 0xA8, 0xA9,
        0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0x00
    };
    oled_write_P(qmk_font_logo, false);
}

void render_mw_logo(void) {     // Render MechWild "MW" Logo
    static const char PROGMEM mw_logo[] = {
        0x94, 0x95, 0x96, 0x97, 0x20,
        0xB4, 0xB5, 0xB6, 0xB7, 0xB8,
        0xD4, 0xD5, 0xD6, 0xD7, 0xD8,
        0x20, 0x98, 0x99, 0x9A, 0x20, 0x00
    };
    oled_write_P(mw_logo, false);
}

void render_layer(void) {
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_ln_P(PSTR("Base\nLayer"), false);
            break;
        case _MEDIA:
            oled_write_ln_P(PSTR("MediaLayer"), false);
            break;
        case _LED:
            oled_write_ln_P(PSTR("LED\nLayer"), false);
            break;
        case _MACRO:
            oled_write_P(PSTR("MacroLayer"), false);
            break;
        default:
            oled_write_ln_P(PSTR("UndefLayer"), false);
    }
}

bool oled_task_user(void) {
    render_mw_logo();

    oled_write_ln("", false);

    render_qmk_logo();
    render_qmk_font_logo();

    oled_write_ln("", false);

    render_layer();
    return false;
}
#endif // OLED_ENABLE
