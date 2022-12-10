/* Copyright 2019 e3w2q
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

enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Default Layer
   *  Master Side (USB Cable Connected Side)
   *  ,---------------------------------------------------
   *  |    =    (    )   BS  Esc   F1   F2   F3   F4   F5
   *  | NmLk  KP/  KP*  Tab Hank    1    2    3    4    5
   *  |  KP7  KP8  KP9  KP-  Tab    Q    W    E    R    T
   *  |  KP4  KP5  KP6  KP+ Caps    A    S    D    F    G
   *  |  KP1  KP2  KP3 Entr Shft    Z    W    C    V    B
   *  |  KP0   00    .    , Ctrl  GUI  Alt MHEN Spce Spce
   *  `---------------------------------------------------
   *  Slave Side (USB Cable Not Connected Side)
   *  ,---------------------------------------------------
   *  |   F6   F7   F8   F9  F10  F11  F12 PtSc  Del  Ins
   *  |    6    7    8    9    0    -    =   BS   BS Home
   *  |    Y    U    I    O    P    [    ]    \ Entr  End
   *  |    H    J    K    L    ;    ' Entr Entr Entr  PgUp
   *  |    N    M    ,    .    / Shft Shft Shft   Up  PgDn
   *  | Spce  HEN KANA  Alt  App Ctrl MO(1)Left Down Rght
   *  `---------------------------------------------------
   */

  [0] = LAYOUT( /* Base */
    KC_A,     KC_B,     KC_C,     KC_D,     KC_E,
    KC_F,     KC_G,     KC_H,     KC_I,     KC_J,
    KC_M,     KC_N
  ),

  [1] = LAYOUT(
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX
  ),

  [2] = LAYOUT(
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX
  ),
};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (index) {
      case 0:
        if (clockwise) {
          tap_code(KC_PGDN);
        } else {
          tap_code(KC_PGUP);
        }
        break;
      case 1:
        if (clockwise) {
          tap_code(KC_VOLU);
        } else {
          tap_code(KC_VOLD);
        }
        break;
    }
    return false;
}
