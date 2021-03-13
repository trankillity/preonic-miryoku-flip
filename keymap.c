/* Copyright 2015-2017 Jack Humbert
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

// Declare layers
enum custom_layers {
    _QWERTY = 0,
    _COLEMAK,
    _GAME,
    _NAVI,
    _NMBR,
    _FUNC,
    _SYMB,
    _MDIA,
    _MOUS,
    _SYST
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAK,
    GAME,
    LT_NAVI,
    LT_NMBR,
    LT_FUNC,
    LT_SYMB,
    LT_MDIA,
    LT_MOUS
};

// Define editing layer shortcuts
// Format: EL_Mod_Key
#define EL_C_Z LCTL(KC_Z)
#define EL_C_X LCTL(KC_X)
#define EL_C_C LCTL(KC_C)
#define EL_C_V LCTL(KC_V)
#define EL_C_Y LCTL(KC_Y)
#define OS_SHFT OSM(MOD_LSFT)

#define LT_NAVI LT(_NAVI,KC_SPC)
#define LT_NMBR LT(_NMBR,KC_BSPC)
#define LT_FUNC LT(_FUNC,KC_DEL)
#define LT_SYMB LT(_SYMB,KC_ENT)
#define LT_MDIA LT(_MDIA,KC_ESC)
#define LT_MOUS LT(_MOUS,KC_TAB)

// clang-format off
#define HR_GASC_LAYOUT( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, \
    k40, k41, k42, k43, k44,    k45,   k47, k48, k49, k4a, k4b  \
) { \
    { k00, k01, k02, k03, k04, k05 }, \
    { k10, k11, k12, k13, k14, k15 }, \
    { LGUI_T(k20), LALT_T(k21), LSFT_T(k22), LCTL_T(k23), k24, k25 }, \
    { k30, k31, k32, k33, k34, k35 }, \
    { k06, k07, k08, k09, k0a, k0b }, \
    { k16, k17, k18, k19, k1a, k1b }, \
    { k26, k27, RCTL_T(k28), RSFT_T(k29), LALT_T(k2a), RGUI_T(k2b) }, \
    { k36, k37, k38, k39, k3a, k3b }, \
    { k40, k41, k42, k49, k4a, k4b }, \
    { k45, k47, k48, k43, k44, k45 }  \
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* QWERTY layer:
 * ,-----------------------------------------------------------------------------------.
 * |Rotary|   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |BckSpc|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc~ | A|GUI| S|ALT| D|SHF| F|CTL|   G  |   H  | J|CTL| K|SHF| L|ALT| ;|GUI|   '  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  \   |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Game |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  GUI |  Alt | Shift|Ctrl|=|EntEdt|    Space    |EntNum|Ctrl|-| Shift|  Alt |  GUI |
 * `-----------------------------------------------------------------------------------'
 */
    [_QWERTY] = HR_GASC_LAYOUT(
        XXXXXXX,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       OSL(_SYST),
        KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       XXXXXXX,    XXXXXXX,    KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,   
        KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       OS_SHFT,    OS_SHFT,    KC_H,       KC_J,       KC_K,       KC_L,       KC_QUOT,
        KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       OS_SHFT,    OS_SHFT,    KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,
        XXXXXXX,    XXXXXXX,    LT_FUNC,    LT_NMBR,    LT_SYMB,           OS_SHFT,         LT_MOUS,    LT_NAVI,    LT_MDIA,    XXXXXXX,    XXXXXXX
        ),
/* Colemak-DH layer:
 * ,-----------------------------------------------------------------------------------.
 * |Rotary|   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  |BckSpc|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc~ | A|GUI| R|ALT| S|SHF| T|CTL|   G  |   M  | N|CTL| E|SHF| I|ALT| O|GUI|   '  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  \   |   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  | Game |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  GUI |  Alt | Shift|Ctrl|=|EntEdt|    Space    |EntNum|Ctrl|-| Shift|  Alt |  GUI |
 * `-----------------------------------------------------------------------------------'
 */
    [_COLEMAK] = HR_GASC_LAYOUT(
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        KC_Q,       KC_W,       KC_F,       KC_P,       KC_B,       _______,    _______,    KC_J,       KC_L,       KC_U,       KC_Y,       KC_QUOT,
        KC_A,       KC_R,       KC_S,       KC_T,       KC_G,       _______,    _______,    KC_M,       KC_N,       KC_E,       KC_I,       KC_O,
        KC_Z,       KC_X,       KC_C,       KC_D,       KC_V,       _______,    _______,    KC_K,       KC_H,       KC_COMM,    KC_DOT,     KC_SLSH,
        _______,    _______,    _______,    _______,    _______,          _______,          _______,    _______,    _______,    _______,    _______
        ),
/* Gaming layer:
 * ,-----------------------------------------------------------------------------------.
 * |Rotary|   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |BckSpc|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc~ |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   '  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Base |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  Alt | Shift| Ctrl |EntEdt|    Space    |EntNum| Left | Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
 */
    [_GAME] = LAYOUT_preonic_1x2uC(
        _______,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       _______,
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       XXXXXXX,
        KC_ESC,     KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_ENT,
        KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    XXXXXXX,
        KC_LCTL,    KC_LALT,    XXXXXXX,    KC_BSPC,    KC_ENT,           KC_SPC,           XXXXXXX,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT
        ),
/* Nav layer:
 * ,-----------------------------------------------------------------------------------.
 * |Rotary|      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  | PgUp | BkSpc|  Up  |  Del | PgDn |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc~ | Home | Left | Down | Right|  End |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  C+Z |  C+C |  C+X |  C+V |  C+Y |      | <  > | [  ] | {  } |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |(hold)|             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

/* Number layer:
 * ,-----------------------------------------------------------------------------------.
 * |Rotary|      |      |      |      |      | NumLk|   $  |   %  |   ^  |   -  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |  F1  |  F2  |  F3  |  F4  |      |PrtScn|   7  |   8  |   9  |   +  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc~ |  F5  |  F6  |  F7  |  F8  |      |  Ins |   4  |   5  |   6  |   *  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 |      |   =  |   1  |   2  |   3  |   /  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |             |(hold)|   0  |   .  | Enter|      |
 * `-----------------------------------------------------------------------------------'
 */

// RIGHT HAND

    [_NMBR] = LAYOUT_preonic_1x2uC(
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    XXXXXXX,    KC_LBRC,    KC_7,       KC_8,       KC_9,       KC_RBRC,
        _______,    _______,    _______,    _______,    _______,    _______,    XXXXXXX,    KC_SCLN,    KC_4,       KC_5,       KC_6,       KC_EQL,
        _______,    _______,    _______,    _______,    _______,    _______,    XXXXXXX,    KC_GRV,     KC_1,       KC_2,       KC_3,       KC_BSLS,
        XXXXXXX,    XXXXXXX,    _______,    _______,    _______,          _______,          KC_MINS,    KC_0,       KC_PDOT,    XXXXXXX,    XXXXXXX
        ),

    [_SYMB] = LAYOUT_preonic_1x2uC(
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    XXXXXXX,    S(KC_LBRC), S(KC_7),    S(KC_8),    S(KC_9),    S(KC_RBRC),
        _______,    _______,    _______,    _______,    _______,    _______,    XXXXXXX,    S(KC_SCLN), S(KC_4),    S(KC_5),    S(KC_6),    S(KC_EQL),
        _______,    _______,    _______,    _______,    _______,    _______,    XXXXXXX,    S(KC_GRV),  S(KC_1),    S(KC_2),    S(KC_3),    S(KC_BSLS),
        XXXXXXX,    XXXXXXX,    _______,    _______,    _______,          _______,          S(KC_MINS), S(KC_9),    S(KC_0),    XXXXXXX,    XXXXXXX
        ),
    [_FUNC] = LAYOUT_preonic_1x2uC(
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    XXXXXXX,    KC_PSCR,    KC_F7,      KC_F8,      KC_F9,      KC_F12,
        _______,    _______,    _______,    _______,    _______,    _______,    XXXXXXX,    KC_SLCK,    KC_F4,      KC_F5,      KC_F6,      KC_F11,
        _______,    _______,    _______,    _______,    _______,    _______,    XXXXXXX,    KC_PAUS,    KC_F1,      KC_F2,      KC_F3,      KC_F10,
        XXXXXXX,    XXXXXXX,    _______,    _______,    _______,          _______,          KC_TAB,     KC_SPC,     KC_APP,     XXXXXXX,    XXXXXXX
        ),

// LEFT HAND
    [_NAVI] = LAYOUT_preonic_1x2uC(
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,     KC_INS,     XXXXXXX,    _______,    _______,    _______,    _______,    _______,    _______,    
        KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    KC_CAPS,    XXXXXXX,    _______,    _______,    _______,    _______,    _______,    _______,
        EL_C_Z,     EL_C_X,     EL_C_C,     EL_C_V,     EL_C_Y,     XXXXXXX,    _______,    _______,    _______,    _______,    _______,    _______,
        XXXXXXX,    XXXXXXX,    KC_DEL,     KC_BSPC,    KC_ENT,           _______,          _______,    _______,    _______,    XXXXXXX,    XXXXXXX
        ),
    [_MDIA] = LAYOUT_preonic_1x2uC(
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,    _______,    _______,    _______,    _______,    _______,    
        KC_MPRV,    KC_VOLD,    KC_VOLU,    KC_MNXT,    XXXXXXX,    XXXXXXX,    _______,    _______,    _______,    _______,    _______,    _______,
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,    _______,    _______,    _______,    _______,    _______,
        XXXXXXX,    XXXXXXX,    KC_MUTE,    KC_MPLY,    KC_MSTP,          _______,          _______,    _______,    _______,    XXXXXXX,    XXXXXXX
        ),
    [_MOUS] = LAYOUT_preonic_1x2uC(
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        KC_WH_L,    KC_WH_D,    KC_WH_U,    KC_WH_R,    KC_ACL2,    XXXXXXX,    _______,    _______,    _______,    _______,    _______,    _______,
        KC_MS_L,    KC_MS_D,    KC_MS_U,    KC_MS_R,    KC_ACL1,    XXXXXXX,    _______,    _______,    _______,    _______,    _______,    _______,
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_ACL0,    XXXXXXX,    _______,    _______,    _______,    _______,    _______,    _______,    
        XXXXXXX,    XXXXXXX,    KC_MS_BTN2, KC_MS_BTN3, KC_MS_BTN1,       _______,          _______,    _______,    _______,    XXXXXXX,    XXXXXXX
        ),
/* System layer:
 * ,-----------------------------------------------------------------------------------.
 * |Rotary|      |      |      |      |      |      |      |      |      |      | Reset|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |      |      |      |  F9  |      |      |RGBTog| HUE+ | SAT+ | VAL+ |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc~ |      |      |      |  F5  |      |      |RGBMDE| HUE- | SAT- | VAL- |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |  F3  |      |      |QWERTY|ColeDH| Game |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
    [_SYST] = LAYOUT_preonic_1x2uC(
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    QWERTY,     COLEMAK,    TG(_GAME),  _______,
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    RGB_TOG,
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    RESET,
        XXXXXXX,    XXXXXXX,    _______,    _______,    _______,          _______,          _______,    _______,    _______,    XXXXXXX,    XXXXXXX
        )
};
// clang-format on

#ifdef RGB_MATRIX_ENABLE
int num_led = 4;
int left_led[4] = {5,6,7,8};
int rght_led[4] = {1,2,3,4};

void preonic_led_set(int kbside, uint8_t r, uint8_t g, uint8_t b) {
  for(int i = 0; i < num_led; ++i) {
    if (kbside == 0) {
        rgb_matrix_set_color(left_led[i], r, g, b);
    } else if (kbside == 1) {
        rgb_matrix_set_color(rght_led[i], r, g, b);
    }
  }
}

// Set startup defaults
void keyboard_post_init_user(void) {
	rgb_matrix_set_color_all(RGB_BASE);
	// rgb_matrix_mode_noeeprom(1);
}

// Turn off RGB when PC is suspended, back on when wake
void suspend_power_down_user(void) {
	rgb_matrix_set_suspend_state(true);
}
void suspend_wakeup_init_user(void) {
    rgb_matrix_set_suspend_state(false);
}

// layer_state_t layer_state_set_user(layer_state_t state) {
//     switch (get_highest_layer(state)) {
//         case _SYST:
//             rgb_matrix_set_color_all(RGB_SYST);
//             break;
//         case _GAME:
//             rgb_matrix_set_color_all(RGB_GAME);
//             break;
//         default:
//             rgb_matrix_set_color_all(RGB_BASE);
//             break;
//     }
//   return state;
// }

// Use RGB as indicators
void rgb_matrix_indicators_user(void) {
    // layer_state_cmp(layer_state | default_layer_state, _GAME)
    if (IS_LAYER_ON(_SYST)) {
        rgb_matrix_set_color_all(RGB_SYST);
    } else if (IS_LAYER_ON(_GAME)) {
        rgb_matrix_set_color_all(RGB_GAME);
    }

    if (IS_LAYER_ON(_NMBR)) {
        preonic_led_set(1,RGB_NMBR);
    } else if (IS_LAYER_ON(_SYMB)) {
        preonic_led_set(1,RGB_SYMB);
    } else if (IS_LAYER_ON(_FUNC)) {
        preonic_led_set(1,RGB_FUNC);
    }
    if (IS_LAYER_ON(_NAVI)) {
        preonic_led_set(0,RGB_NAVI);
    } else if (IS_LAYER_ON(_MDIA)) {
        preonic_led_set(0,RGB_MDIA);
    } else if (IS_LAYER_ON(_MOUS)) {
        preonic_led_set(0,RGB_MOUS);
    }
}
#endif

// Set the per key TAPPING_TERM
#ifdef TAPPING_TERM_PER_KEY
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    if (IS_LAYER_ON(_QWERTY)) {
        switch (keycode) {
            case LGUI_T(KC_A):
            case RGUI_T(KC_SCLN):
                return TAPPING_TERM + 150;
            case LALT_T(KC_S):
            case LALT_T(KC_L):
                return TAPPING_TERM + 100;
            case LSFT_T(KC_D):
            case RSFT_T(KC_K):
                return TAPPING_TERM - 25;
            case LCTL_T(KC_F):
            case RCTL_T(KC_J):
                return TAPPING_TERM + 25;
            default:
                return TAPPING_TERM;
        }
    } else if (IS_LAYER_ON(_COLEMAK)) {
        switch (keycode) {
            case LGUI_T(KC_A):
            case RGUI_T(KC_O):
                return TAPPING_TERM + 150;
            case LALT_T(KC_R):
            case LALT_T(KC_I):
                return TAPPING_TERM + 100;
            case LSFT_T(KC_S):
            case RSFT_T(KC_E):
                return TAPPING_TERM - 25;
            case LCTL_T(KC_T):
            case RCTL_T(KC_N):
                return TAPPING_TERM + 25;
            default:
                return TAPPING_TERM;
        }
    }
    switch (keycode) {
        case LT_NAVI:
        case LT_NMBR:
        case LT_FUNC:
        case LT_SYMB:
        case LT_MDIA:
        case LT_MOUS:
            return TAPPING_TERM - 50;
        default:
            return TAPPING_TERM;
    }
}
#endif

#ifdef CAPSWORD_ENABLE
// Caps word: deactivate caps lock following a word
void process_caps_word(uint16_t keycode, keyrecord_t *record) {
// Get the base key code of a mod or layer tap
    switch (keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            if (!record->tap.count) { return; }
            keycode = keycode & 0xFF;
    }
    // Toggle caps lock with the following key codes
    switch (keycode) {
        case KC_ESC:
        case KC_SPC:
        case KC_ENT:
        case KC_TAB:
        case KC_DOT:
        case KC_COMM:
            if (record->event.pressed) { tap_code(KC_CAPS); }
    }
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CAPSWORD_ENABLE
// Monitor key codes to toggle caps lock
if (host_keyboard_led_state().caps_lock) { process_caps_word(keycode, record); }
#endif
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
            break;
        // case GAME:
        //     if (record->event.pressed) {
        //         TG(_GAME);
        //     }
        //     return false;
        //     break;
    }
    return true;
};

#ifdef ENCODER_ENABLE
// Rotary encoder to be added later
void encoder_update_user(uint8_t index, bool clockwise) {
    if (IS_LAYER_ON(_QWERTY) || IS_LAYER_ON(_COLEMAK)) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (IS_LAYER_ON(_NAVI)) {
        if (clockwise) {
            tap_code(KC_WH_D);
        } else {
            tap_code(KC_WH_U);
        }
    } else {
        if (clockwise) {
            register_code(KC_VOLU);
            unregister_code(KC_VOLU);
        } else {
            register_code(KC_VOLD);
            unregister_code(KC_VOLD);
        }
    }
}
#endif