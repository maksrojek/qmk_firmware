/*
Copyright 2021 Maksymilian Rojek

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
#include QMK_KEYBOARD_H

// Modtap homerow
#define HMRW_A      CTL_T(KC_A)
#define HMRW_S      ALT_T(KC_S)
#define HMRW_D      GUI_T(KC_D)
#define HMRW_F      SFT_T(KC_F)

#define HMRW_J      SFT_T(KC_J)
#define HMRW_K      GUI_T(KC_K)
#define HMRW_L      ALT_T(KC_L)
#define H_SCLN      CTL_T(KC_SCLN)

#define H_GRAVE     CTL_T(KC_GRAVE)
#define H_EQUAL     ALT_T(KC_EQUAL)
#define H_LBRACKET  GUI_T(KC_LBRACKET)
#define H_RBRACKET  SFT_T(KC_RBRACKET)

// Macros
#define W_LEFT      LCTL(KC_LEFT) // move to window to the left
#define W_RIGHT     LCTL(KC_RIGHT) // move to window to the right
#define COPY        LGUI(KC_C)
#define PASTE       LGUI(KC_V)
#define CUT         LGUI(KC_X)


enum layers { _LAYER0, _LAYER1, _LAYER2, _LAYER3 };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_LAYER0] = LAYOUT(
     KC_ESCAPE,  KC_1,   KC_2,     KC_3,    KC_4,        KC_5,                                                      KC_6,        KC_7,     KC_8,    KC_9,    KC_0,     KC_MINUS,
     KC_DELETE,  KC_Q,   KC_W,     KC_E,    KC_R,        KC_T,                                                      KC_Y,        KC_U,     KC_I,    KC_O,    KC_P,     KC_BSLASH,
     KC_EQUAL,   HMRW_A, HMRW_S,   HMRW_D,  HMRW_F,      KC_G,                                                      KC_H,        HMRW_J,   HMRW_K,  HMRW_L,  H_SCLN,   KC_QUOT,
     KC_LSFT,    KC_Z,   KC_X,     KC_C,    KC_V,        KC_B,        W_LEFT,   TG(_LAYER1), TG(_LAYER2),  W_RIGHT, KC_N,        KC_M,     KC_COMM, KC_DOT,  KC_SLSH,  KC_GRAVE,
                                   XXXXXXX, MO(_LAYER3), MO(_LAYER1), KC_SPACE, KC_ENTER,    KC_TAB,       KC_BSPC, MO(_LAYER2), XXXXXXX,  XXXXXXX
    ),
    [_LAYER1] = LAYOUT(
     _______,  _______,  _______,  _______,   _______,   _______,                                          _______,  _______,  _______, _______, _______,  _______,
     _______,  _______,  CUT,      COPY,      PASTE,     _______,                                          _______,  KC_HOME,  KC_UP,   KC_END,  _______,  _______,
     _______,  KC_LCTL,  KC_LALT,  KC_LGUI,   KC_LSFT,   _______,                                          _______,  KC_LEFT,  KC_DOWN, KC_RIGHT,_______,  _______,
     _______,  _______,  _______,  _______,   _______,   _______,   _______, _______,  _______,  _______,  _______,  _______,  _______, _______, _______,  _______,
                                   _______,   _______,   _______,   _______, _______,  _______,  _______,  _______,  _______,  _______
    ),
    [_LAYER2] = LAYOUT(
     _______,  _______,  _______,  _______,     _______,     _______,                                          _______,  _______,  _______, _______, _______,  _______,
     _______,  KC_EXLM,  KC_AT,    KC_LCBR,     KC_RCBR,     KC_PIPE,                                          _______,  _______,  _______, _______, _______,  _______,
     _______,  KC_EXLM,  KC_DLR,   KC_LBRACKET, KC_RBRACKET, KC_ASTR,                                          _______,  KC_LSFT,  KC_LGUI, KC_LALT, KC_LCTL,  _______,
     _______,  KC_AMPR,  KC_HASH,  KC_LPRN,     KC_RPRN,     KC_TILD,   _______, _______,  _______,  _______,  _______,  _______,  _______, _______, _______,  _______,
                                   _______,     _______,     _______,   _______, _______,  _______,  _______,  _______,  _______,  _______
    ),
    [_LAYER3] = LAYOUT(
     _______,  _______,  _______,  _______,   _______,   _______,                                          _______,  _______,  _______, _______, _______,  _______,
     _______,  _______,  _______,  _______,   _______,   _______,                                          _______,  KC_7,     KC_8,    KC_9,    _______,  _______,
     _______,  _______,  _______,  _______,   _______,   _______,                                          KC_0,     KC_4,     KC_5,    KC_6,    _______,  _______,
     _______,  _______,  _______,  _______,   _______,   _______,   _______, _______,  _______,  _______,  _______,  KC_1,     KC_2,    KC_3,    _______,  _______,
                                   _______,   _______,   _______,   _______, _______,  _______,  _______,  _______,  _______,  _______
    )
    // [_LAYER4] = LAYOUT(
    //  _______,  _______,  _______,  _______,   _______,   _______,                                          _______,  _______,  _______, _______, _______,  _______,
    //  _______,  _______,  _______,  _______,   _______,   _______,                                          _______,  _______,  _______, _______, _______,  _______,
    //  _______,  _______,  _______,  _______,   _______,   _______,                                          _______,  _______,  _______, _______, _______,  _______,
    //  _______,  _______,  _______,  _______,   _______,   _______,   _______, _______,  _______,  _______,  _______,  _______,  _______, _______, _______,  _______,
    //                                _______,   _______,   _______,   _______, _______,  _______,  _______,  _______,  _______,  _______
    // )
};

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
    // Key Matrix to LED Index
    // Left Half
    { 0, 1, 2, 3, 4, 5, NO_LED, NO_LED },
    { 11, 10, 9, 8, 7, 6, NO_LED, NO_LED},
    { 12, 13, 14, 15, 16, 17, NO_LED, NO_LED },
    { 25, 24, 23, 22, 21, 20, 19, 18 },
    { NO_LED, NO_LED, NO_LED, 26, 27, 28, 29, 30 },
    // Right Half
    { 31, 32, 33, 34, 35, 36, NO_LED, NO_LED },
    { 42, 41, 40, 39, 38, 37, NO_LED, NO_LED },
    { 43, 44, 45, 46, 47, 48, NO_LED, NO_LED },
    { 56, 55, 54, 53, 52, 51, 50, 49 },
    { NO_LED, NO_LED, NO_LED, 57, 58, 59, 60, 61 }
}, {
    // LED Index to Physical Position
    // Left Half
    { 0, 8 }, { 16, 8 }, { 32, 0 }, { 48, 0 }, { 64, 0 }, { 80, 0 },
    { 0, 24 }, { 16, 24 }, { 32, 16 }, { 48, 16 }, { 64, 16 }, { 80, 16 },
    { 0, 40 }, { 16, 40 }, { 32, 32 }, { 48, 32 }, { 64, 32 }, { 80, 32 },
    { 112, 48 }, { 96, 48 }, { 80, 48 }, { 64, 48 }, { 48, 48 }, { 32, 48 }, { 16, 56 }, { 0, 56 },
    { 112, 64 },{ 96, 64 },{ 80, 64 }, { 64, 64 }, { 48, 64 },
    // Right Half
    { 240, 8 },{ 224, 8 }, { 208, 0 }, { 192, 0 }, { 176, 0 }, { 160, 0 },
    { 240, 24 },{ 224, 24 },{ 208, 16 },{ 192, 16 },{ 176, 16 },{ 160, 16 },
    { 240, 40 },{ 224, 40 }, { 208, 32 }, { 192, 32 }, { 176, 32 }, { 160, 32 },
    { 128, 48 }, { 144, 48 },{ 160, 48 }, { 176, 48 }, { 192, 48 }, { 208, 48 }, { 224, 56 }, { 240, 56 },
    { 128, 64 }, { 144, 64 }, { 160, 64 }, { 176, 64 }, { 192, 64 }
}, {
    // LED Index to Flag
    // Left Half
    4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4,
    // Right Half
    4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4,

} };
#endif

#ifdef OLED_ENABLE
bool oled_task_kb(void) {
    // Defer to the keymap if they want to override
    if(!oled_task_user()) { return false; }

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _LAYER0:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _LAYER1:
            oled_write_P(PSTR("FN\n"), false);
            break;
        case _LAYER2:
            oled_write_P(PSTR("ADJ\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    return false;
}
#endif


//-----------------------------------
// RGB layers custom
const rgblight_segment_t PROGMEM my_right_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {5, 2, HSV_CYAN},
    {17, 4, HSV_CYAN},
    {36, 2, HSV_CYAN},
    {48, 4, HSV_CYAN}
);

const rgblight_segment_t PROGMEM my_left_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {5, 2, HSV_MAGENTA},
    {17, 4, HSV_MAGENTA},
    {36, 2, HSV_MAGENTA},
    {48, 4, HSV_MAGENTA}
);

const rgblight_segment_t PROGMEM my_numpad_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {5, 2, HSV_GREEN},
    {17, 4, HSV_GREEN},
    {36, 2, HSV_GREEN},
    {48, 4, HSV_GREEN}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_right_layer,
    my_left_layer,
    my_numpad_layer
);

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _LAYER1:
            rgblight_set_layer_state(1, true);
            break;
        case _LAYER2:
            rgblight_set_layer_state(0, true);
            break;
        case _LAYER3:
            rgblight_set_layer_state(2, true);
            break;
        case _LAYER0:
        default:  //  for any other layers, or the default layer
            rgblight_set_layer_state(0, false);
            rgblight_set_layer_state(1, false);
            rgblight_set_layer_state(2, false);
            break;
    }
    return state;
}
//-----------------------------------

// //-------------------------------
// // RGB layers blinking settings
// const rgblight_segment_t PROGMEM my_layer0_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {0, 5, HSV_WHITE}
// );
// const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {0, 5, HSV_CYAN}
// );
// const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {0, 5, HSV_MAGENTA}
// );
// const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {0, 5, HSV_RED}
// );

// const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
//     my_layer0_layer,
//     my_layer1_layer,
//     my_layer2_layer,
//     my_layer3_layer
// );

// layer_state_t layer_state_set_user(layer_state_t state) {
//     switch (get_highest_layer(state)) {
//         case _LAYER1:
//             rgblight_blink_layer(1, 500);
//             break;
//         case _LAYER2:
//             rgblight_blink_layer(2, 500);
//             break;
//         case _LAYER3:
//             rgblight_blink_layer(3, 500);
//             break;
//         case _LAYER0:
//         default:  //  for any other layers, or the default layer
//             rgblight_set_layer_state(1, false);
//             rgblight_set_layer_state(2, false);
//             rgblight_set_layer_state(3, false);
//             rgblight_blink_layer(0, 500);
//             break;
//     }
//     return state;
// }

// //-------------------------------
// RGB layers and RGB effect setup
void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;

    rgblight_enable();
    rgblight_mode(RGBLIGHT_EFFECT_RAINBOW_SWIRL + 5); // default RGB effect mode
}

