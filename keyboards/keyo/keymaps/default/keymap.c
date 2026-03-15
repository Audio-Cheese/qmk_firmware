// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define _Base 0
#define _Nav 1
#define _Mouse 2
#define _Button 3
#define _Media 4
#define _Number 5
#define _Symbol 6
#define _Func 7
#define _Extra 8

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /* BASE LAYER - COLMAKDH
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ Q │ W │ F │ P │ B │       │ J │ L │ U │ Y │ ' │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ A │ R │ S │ T │ G │       │ M │ N │ E │ I │ O │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ Z │ X │ C │ D │ V │       │ K │ H │ , │ . │ / │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │ESC├───┐           ┌───┤Alt│
      *           └───┤SPC├───┐   ┌───┤BSP├───┘
      *               └───┤TAB│   │ENT├───┘
      *                   └───┘   └───┘
      * 
      * 
      */
    [_Base] = LAYOUT_split_3x5_3(
        KC_Q,            KC_W,            KC_F,            KC_P,           KC_B,    KC_J,    KC_L,            KC_U,            KC_Y,            KC_QUOT,
        LGUI_T(KC_A),    LALT_T(KC_R),    LCTL_T(KC_S),    LSFT_T(KC_T),   KC_G,    KC_M,    RSFT_T(KC_N),    RCTL_T(KC_E),    RALT_T(KC_I),    RGUI_T(KC_O),
        LT(_Button,KC_Z), KC_X,           KC_C,            KC_D,           KC_V,    KC_K,    KC_H,            KC_COMM,         KC_DOT,          LT(_Button,KC_SLSH),
                    LT(_Media,KC_ESC), LT(_Nav, KC_SPC), LT(_Mouse, KC_TAB),      LT(_Symbol,  KC_ENT), LT(_Number,KC_BSPC), LT(_Func, KC_DEL)
    ),
    [_Nav] = LAYOUT_split_3x5_3(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                          KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,                          CW_TOGG, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,
        KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,                           KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,
                                   KC_NO, KC_NO, KC_NO,           KC_ENT,  KC_BSPC,  KC_DEL
    ),    
    [_Mouse] = LAYOUT_split_3x5_3(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                          C(KC_Y), C(KC_V),  C(KC_C), C(KC_X),  C(KC_Z),
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,                          KC_NO,   MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT,
        KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,                           KC_NO,   MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR,
                                   KC_NO, KC_NO, KC_NO,           MS_BTN2,  MS_BTN1,  MS_BTN3
    ),    
    [_Button] = LAYOUT_split_3x5_3(
        C(KC_Y), C(KC_V), C(KC_C), C(KC_X), C(KC_Z),                        C(KC_Y), C(KC_V),  C(KC_C), C(KC_X),  C(KC_Z),
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,                          KC_NO, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,
        C(KC_Y), C(KC_V),  C(KC_C), C(KC_X),  C(KC_Z),                      C(KC_Y), C(KC_V),  C(KC_C), C(KC_X),  C(KC_Z),
                            MS_BTN3,  MS_BTN1,  MS_BTN2,          MS_BTN2,  MS_BTN1,  MS_BTN3
    ),    
    [_Media] = LAYOUT_split_3x5_3(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                          RM_TOGG, RM_NEXT, RM_HUEU,  RM_SATU, RM_VALU,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,                          KC_NO,   KC_MPRV, KC_VOLD, KC_VOLU,    KC_MNXT,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                          KC_NO, KC_NO,     KC_NO,   KC_NO,      KC_NO,
                                   KC_NO, KC_NO, KC_NO,           KC_MSTP, KC_MPLY, KC_MUTE
    ),    
    [_Number] = LAYOUT_split_3x5_3(
        KC_LBRC,    KC_7,   KC_8,   KC_9,   KC_RBRC,                        KC_NO,  KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_SCLN,    KC_4,   KC_5,   KC_6,   KC_EQL,                         KC_NO,  KC_RSFT,    KC_RCTL,    KC_RALT,    KC_RGUI,
        KC_GRV,     KC_1,   KC_2,   KC_3,   KC_BSLS,                        KC_NO,  KC_NO,      KC_NO,      KC_NO,      KC_NO,
                                   KC_DOT, KC_0, KC_MINS,         KC_NO,  KC_NO,  KC_NO
    ),    
    [_Symbol] = LAYOUT_split_3x5_3(
        KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                         KC_NO,  KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                         KC_NO,  KC_RSFT,    KC_RCTL,    KC_RALT,    KC_RGUI,
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,                         KC_NO,  KC_NO,      KC_NO,      KC_NO,      KC_NO,
                                   KC_LPRN, KC_RPRN, KC_UNDS,      KC_NO,  KC_NO,  KC_NO
    ),    
    [_Func] = LAYOUT_split_3x5_3(
        KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR,                           KC_NO,  KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_F11, KC_F4, KC_F5, KC_F6, KC_SCRL,                           KC_NO,  KC_RSFT,    KC_RCTL,    KC_RALT,    KC_RGUI,
        KC_F10, KC_F1, KC_F2, KC_F3, KC_PAUS,                           KC_NO,  KC_NO,      KC_NO,      KC_NO,      KC_NO,
                                   KC_APP, KC_SPC, KC_TAB,           KC_NO,  KC_NO,  KC_NO
    ),    
    [_Extra] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                                   KC_LGUI, KC_BSPC, KC_SPC,           KC_SPC,  KC_ENT,  KC_RALT
    )    
};
