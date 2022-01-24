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

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x4D52
#define PRODUCT_ID      0x0001
#define DEVICE_VER      0x0001
#define MANUFACTURER    maksrojek
#define PRODUCT         Avocado
#define DESCRIPTION     Split, low profile keyboard with per-key RGB backlit

// #define TAPPING_TOGGLE 1
// #define TAPPING_TERM 200
#define IGNORE_MOD_TAP_INTERRUPT

#define DIODE_DIRECTION COL2ROW

/* key matrix size */
#define MATRIX_ROWS 10
#define MATRIX_COLS 8

#define UNUSED_PINS


// ---------------------
// Pro Micro
#define MATRIX_ROW_PINS \
    { C6, D7, E6, B4, B5 }
#define MATRIX_COL_PINS \
    { F4, F5, F6, F7, B1, B3, B2, B6 }
#define SOFT_SERIAL_PIN D2
#define RGB_DI_PIN D4
// ---------------------


// ---------------------
// STM32F401CCU6
/*
#define MATRIX_ROW_PINS \
    { A1, A2, A3, A4, A5 }
#define MATRIX_COL_PINS \
    { B5, B4, B3, A15, A12, A11, A10, A9 }
#define SOFT_SERIAL_PIN B6
// #define SERIAL_USART_SPEED 921600
#define RGB_DI_PIN A0
#define SPLIT_HAND_PIN C14


#define WS2812_PWM_DRIVER PWMD3
#define WS2812_PWM_CHANNEL 4
#define WS2812_PWM_PAL_MODE 2
#define WS2812_DMA_STREAM STM32_DMA1_STREAM2
#define WS2812_DMA_CHANNEL 5
*/
// ---------------------

// ---------------------
// RGB light options
#define RGBLIGHT_LAYERS

#define RGBLED_SPLIT { 31, 31 }
#define RGBLED_NUM 62
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#define RGBLIGHT_LIMIT_VAL 90
#define RGBLIGHT_SLEEP

#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
// ---------------------


// ---------------------
// RGB matrix options
/*
#define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
// #define RGB_MATRIX_TYPING_HEATMAP
#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_TYPING_HEATMAP

#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 100
#define RGB_MATRIX_STARTUP_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
#define DRIVER_LED_TOTAL 62
#define RGB_MATRIX_SPLIT { 31, 31 }
*/
// ---------------------


/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Bootmagic Lite key configuration */
// #define BOOTMAGIC_LITE_ROW 0
// #define BOOTMAGIC_LITE_COLUMN 0

/* disable these deprecated features by default */
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION


