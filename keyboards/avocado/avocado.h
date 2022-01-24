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
#pragma once

#include "quantum.h"

#define LAYOUT( \
    L00, L01, L02, L03, L04, L05,                     R06, R07, R08, R09, R10, R11, \
    L12, L13, L14, L15, L16, L17,                     R18, R19, R20, R21, R22, R23, \
    L24, L25, L26, L27, L28, L29,                     R30, R31, R32, R33, R34, R35, \
    L36, L37, L38, L39, L40, L41, L42, L43, R44, R45, R46, R47, R48, R49, R50, R51, \
                   L52, L53, L54, L55, L56, R57, R58, R59, R60, R61 \
) \
{ \
    { L00,   L01,   L02,   L03,   L04,   L05,   KC_NO, KC_NO }, \
    { L12,   L13,   L14,   L15,   L16,   L17,   KC_NO, KC_NO }, \
    { L24,   L25,   L26,   L27,   L28,   L29,   KC_NO, KC_NO }, \
    { L36,   L37,   L38,   L39,   L40,   L41,   L42,   L43   }, \
    { KC_NO, KC_NO, KC_NO, L52,   L53,   L54,   L55,   L56   }, \
    { R11,   R10,   R09,   R08,   R07,   R06,   KC_NO, KC_NO }, \
    { R23,   R22,   R21,   R20,   R19,   R18,   KC_NO, KC_NO }, \
    { R35,   R34,   R33,   R32,   R31,   R30,   KC_NO, KC_NO }, \
    { R51,   R50,   R49,   R48,   R47,   R46,   R45,   R44   }, \
    { KC_NO, KC_NO, KC_NO, R61,   R60,   R59,   R58,   R57   }, \
}



