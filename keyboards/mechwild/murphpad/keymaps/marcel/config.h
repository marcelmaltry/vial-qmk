/*
Copyright 2021 Kyle McCreery
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* Saving space by including fewer RGB Animations */
#undef RGBLIGHT_ANIMATIONS

#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_STATIC_GRADIENT

/* VIAL Specific definitions. */
#define VIAL_KEYBOARD_UID {0x3B, 0x87, 0xE1, 0xE7, 0x57, 0x30, 0x78, 0x13}
#define VIAL_UNLOCK_COMBO_ROWS { 0, 0 }
#define VIAL_UNLOCK_COMBO_COLS { 1, 4 }
#define VIAL_ENCODER_DEFAULT { \
    /* _BASE */ \
    KC_VOLD, KC_VOLU,\
    KC_BRID, KC_BRIU,\
    /* _MEDIA */ \
    KC_VOLD, KC_VOLU,\
    KC_BRID, KC_BRIU,\
    /* _LED */ \
    RGB_VAD, RGB_VAI,\
    KC_TRNS, KC_TRNS,\
    /* _MACRO */ \
    KC_TRNS, KC_TRNS,\
    KC_TRNS, KC_TRNS\
}

/* Set number of layers. */
#define DYNAMIC_KEYMAP_LAYER_COUNT 4

/* Set custom font. */
#undef OLED_FONT_H
#define OLED_FONT_H "keyboards/mechwild/murphpad/keymaps/marcel/glcdfont.c"
