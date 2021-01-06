/*
Copyright 2020 Maksymilian Rojek

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

enum layers { _LAYER0, _LAYER1, _LAYER2, _LAYER3, _LAYER4 };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_LAYER0] = LAYOUT(
/* ┌─────────┬─────────┬─────────┐ */
    TO(_LAYER1), KC_UP,    TO(_LAYER1),
/* ├─────────┼─────────┼─────────┤ */
       KC_LEFT,  KC_DOWN,  KC_RIGHT
/* └─────────┴─────────┴─────────┘ */
  ),

  [_LAYER1] = LAYOUT(
/* ┌─────────┬─────────┬─────────┐ */
    TO(_LAYER2), KC_PGUP,  TO(_LAYER2),
/* ├─────────┼─────────┼─────────┤ */
    KC_HOME,  KC_PGDN,  KC_END
/* └─────────┴─────────┴─────────┘ */
  ),

  [_LAYER2] = LAYOUT(
/* ┌─────────┬─────────┬─────────┐ */
    TO(_LAYER3), KC_MUTE,  TO(_LAYER3),
/* ├─────────┼─────────┼─────────┤ */
    KC_MPRV,  KC_MPLY,  KC_MNXT
/* └─────────┴─────────┴─────────┘ */
  ),

  [_LAYER3] = LAYOUT(
/* ┌─────────┬─────────┬─────────┐ */
   TO(_LAYER4),  KC_MS_U,  TO(_LAYER4),
/* ├─────────┼─────────┼─────────┤ */
    KC_MS_L,  KC_MS_D,  KC_MS_R
/* └─────────┴─────────┴─────────┘ */
  ),

  [_LAYER4] = LAYOUT(
/* ┌─────────┬─────────┬─────────┐ */
   TO(_LAYER0),  RGB_VAI,  TO(_LAYER0),
/* ├─────────┼─────────┼─────────┤ */
    XXXXXXX,  RGB_VAD,  XXXXXXX
/* └─────────┴─────────┴─────────┘ */
  ),

};

const rgblight_segment_t PROGMEM my_layer0_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 5, HSV_WHITE}
);
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 5, HSV_CYAN}
);
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 5, HSV_MAGENTA}
);
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 5, HSV_RED}
);
const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 5, HSV_ORANGE}
);

//void eeconfig_init_user(void) {
    // use the non noeeprom versions, to write these values to EEPROM too
//    rgblight_enable();
//    tap_code(RGB_TOG);
//    rgblight_disable();

//    rgblight_mode(RGB_MODE_PLAIN + 1);
//
//    backlight_enable();
//}

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_layer0_layer,
    my_layer1_layer,
    my_layer2_layer,
    my_layer3_layer,
    my_layer4_layer
);
//
void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;

    rgblight_enable();
    // Rgb light mode
    rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL + 5);

//    rgblight_disable();

}
//
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _LAYER1:
            rgblight_blink_layer(1, 500);
            break;
        case _LAYER2:
            rgblight_blink_layer(2, 500);
            break;
        case _LAYER3:
            rgblight_blink_layer(3, 500);
            break;
        case _LAYER4:
            rgblight_blink_layer(4, 500);
            break;
        case _LAYER0:
        default:  //  for any other layers, or the default layer
            rgblight_set_layer_state(1, false);
            rgblight_set_layer_state(2, false);
            rgblight_set_layer_state(3, false);
            rgblight_set_layer_state(4, false);
            rgblight_blink_layer(0, 500);
            break;
    }
    return state;
}

// oled screen
#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;  // flips the display 180 degrees
}

void oled_task_user(void) {
    // Host Keyboard Layer Status
//    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _LAYER1:
            oled_write_ln_P(PSTR("TO L2 | PGUP | TO L2"), false);
            oled_write_ln_P(PSTR("HOME  | PGDN | END"), false);
            break;
        case _LAYER2:
            oled_write_ln_P(PSTR("TO L3 | MUTE | TO L3"), false);
            oled_write_ln_P(PSTR("PREV  | PLAY | NEXT"), false);
            break;
        case _LAYER3:
            oled_write_P(PSTR("TO L4 | MOUSE | TO L4"), false);
            oled_write_ln_P(PSTR("       CURSOR"), false);
            break;
        case _LAYER4:
            oled_write_ln_P(PSTR("TO L0 | XXXX | TO L0"), false);
            oled_write_ln_P(PSTR("        XXXX"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
//            oled_write_ln_P(PSTR("Default"), false);
            oled_write_ln_P(PSTR("TO L1 |  UP  | TO L1"), false);
            oled_write_ln_P(PSTR("LEFT  | DOWN | RIGHT"), false);
    }

    // Host Keyboard LED Status
//    led_t led_state = host_keyboard_led_state();
//    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
//    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
//    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    // encoder
    oled_write_P(PSTR("\nEncdr: "), false);
    switch (get_highest_layer(layer_state)) {
        case _LAYER1:
            oled_write_P(PSTR("Page Up/Down  "), false);
            break;
        case _LAYER2:
            oled_write_P(PSTR("Volume Control"), false);
            break;
        case _LAYER3:
            oled_write_P(PSTR("Rgb mode cycle"), false);
            break;
        case _LAYER4:
            oled_write_P(PSTR("RGB brightness"), false);
            break;
        default:
            oled_write_P(PSTR("Volume Control"), false);
    }
}
#endif

// encoder
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch (biton32(layer_state)) {
            case 3:
                // rgb mode cycle
                if (clockwise) {
                    rgblight_step();
                } else {
                    rgblight_step_reverse();
                }
                break;
            case 4:
                // rgb brightness
                if (clockwise) {
          //      tap_code(RGB_VAI);
                    rgblight_increase_val();
                } else {
            //    tap_code(RGB_VAD);
                     rgblight_decrease_val();
                }
                break;
            case 1:
                // page up/down
                if (clockwise) {
                    tap_code(KC_PGDN);
                } else {
                    tap_code(KC_PGUP);
                }
                break;
            default:
                // volume up/down.
                if (clockwise) {
                    tap_code(KC__VOLUP);
                } else {
                    tap_code(KC__VOLDOWN);
                }
                break;
        }
    }
}
