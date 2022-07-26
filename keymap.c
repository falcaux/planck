/* Copyright 2020 Andrew Liaw	
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is di222tributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST,
	_FN
};

enum planck_keycodes {
    L_RESET = SAFE_RANGE,
};


#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FN MO(_FN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	 /* Base
	  * ,-----------------------------------------------------------------------------------.
	  * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
	  * |------+------+------+------+------+-------------+------+------+------+------+------|
	  * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
	  * |------+------+------+------+------+------|------+------+------+------+------+------|
	  * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |Enter |
	  * |------+------+------+------+------+------+------+------+------+------+------+------|
	  * | Ctrl | Win  | Alt  |  FN  | Lower|    Space    | Raise| AltGr| Left | Down |Right |
	  * `-----------------------------------------------------------------------------------'
	  */
		[_BASE] = LAYOUT_planck_grid(
		KC_ESC,  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,    KC_Y,   KC_U,    KC_I,    KC_O,     KC_P, KC_BSPC,
		KC_TAB,  KC_A,    KC_S,    KC_D,   KC_F,    KC_G,    KC_H,   KC_J,    KC_K,    KC_L,  KC_SCLN, KC_QUOT,
		KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,    KC_N,   KC_M, KC_COMM,  KC_DOT,    KC_UP,  KC_ENT,
		KC_LCTL, KC_LGUI, KC_LALT,   FN,  LOWER,  KC_SPC,  KC_SPC,  RAISE, KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT
	),
	
	/* FN
	 * ,-----------------------------------------------------------------------------------.
	 * | RGB  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |  F7  |  F8  |  F9  |  Del |
	 * |------+------+------+------+------+-------------+------+------+------+------+------|
	 * | CAPS | Prev | Next | Vol+ | Pg Up|      |      |  -_  |  F4  |  F5  |  F6  |  /?  |
	 * |------+------+------+------+------+------|------+------+------+------+------+------|
	 * |      | PLAY | MUTE | Vol- | Pg Dn|      |      |   !  |  F1  |  F2  |  F3  | Pg Up|
	 * |------+------+------+------+------+------+------+------+------+------+------+------|
	 * |      | Reset| Reset|      |      |    INSER    |   0  |  F10 |  F11 |  F12 | Pg Dn|
	 * `-----------------------------------------------------------------------------------'
	 */
	
	[_FN] = LAYOUT_planck_grid(
		RGB_TOG,     KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,  KC_F7,   KC_F8,   KC_F9,  KC_BSPC,
		_______,  KC_MPRV,  KC_MNXT, KC_VOLU, KC_PGUP, _______, _______, KC_MINS,  KC_F4,   KC_F5,   KC_F6,  KC_SLSH,
		_______,  KC_MPLY,  KC_MUTE, KC_VOLD, KC_PGDN, KC_LBRC, KC_RBRC, KC_EXLM,  KC_F1,   KC_F2,   KC_F3,  KC_PGUP, 
		_______,    RESET,  _______, _______, _______,  KC_INS,  KC_INS,    KC_0,  KC_F10,  KC_F11,  KC_F12, KC_PGDN
	),
	
	/* Lowers
	 * ,-----------------------------------------------------------------------------------.
	 * |  ~   |   1  |   2  |   3  |   4  |   5  |   6  |  =+  |   7  |   8  |   9  |  Del |
	 * |------+------+------+------+------+-------------+------+------+------+------+------|
	 * | CAPS | Prev | Next | Vol+ | Pg Up|      |  =+  |   -_ |   4  |   5  |   6  |  /?  | 
	 * |------+------+------+------+------+------|------+------+------+------+------+------|
	 * |      | PLAY | MUTE | Vol- | Pg Dn|   [  |   ]  |   !  |   1  |   2  |   3  | Pg Up|
	 * |------+------+------+------+------+------+------+------+------+------+------+------|
	 * |      |      |      |      |      |    SPACE    |   0  |   0  | Home |  End | Pg Dn|
	 * `-----------------------------------------------------------------------------------'
	 */

	[_LOWER] = LAYOUT_planck_grid(
		KC_TILD,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,  KC_EQL, KC_7,   KC_8,   KC_9,  KC_BSPC,
		KC_CAPS,  KC_MPRV, KC_MNXT, KC_VOLU, KC_PGUP, _______,  KC_EQL, KC_MINS, KC_4,   KC_5,   KC_6,  KC_SLSH,
		_______,  KC_MPLY, KC_MUTE, KC_VOLD, KC_PGDN, KC_LBRC, KC_RBRC, KC_EXLM, KC_1,   KC_2,   KC_3,  KC_PGUP, 
		_______,  _______, _______, _______, _______, _______, _______,    KC_0, KC_0,KC_HOME, KC_END,  KC_PGDN
		),

	/* Raise
	 * ,-----------------------------------------------------------------------------------.
	 * |   `  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
	 * |------+------+------+------+------+-------------+------+------+------+------+------|
	 * | CAPS | Prev | Next | Vol+ | Pg Up|      |      |  -_  |   +  |   _  |  =+  |  \|  |
	 * |------+------+------+------+------+------|------+------+------+------+------+------|
	 * |      | PLAY | MUTE | Vol- | Pg Dn|      |      |      |  [{  |  ]}  | Pg Up|  ?   |
	 * |------+------+------+------+------+------+------+------+------+------+------+------|
	 * |      |      |      |      |      |     INSER   |      |      | Home | Pg Dn| End  |
	 * `-----------------------------------------------------------------------------------'
	 */
	[_RAISE] = LAYOUT_planck_grid(
		KC_GRV,  KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,KC_RPRN,  KC_DEL,  
		KC_CAPS, KC_MPRV, KC_MNXT, KC_VOLU, KC_PGUP, _______, _______, KC_MINS, KC_PLUS, KC_UNDS, KC_EQL, KC_NUBS,
		_______, KC_MPLY, KC_MUTE, KC_VOLD, KC_PGDN, _______, _______, _______, KC_LBRC, KC_RBRC, KC_PGUP,KC_QUES,
		_______,  _______, _______, _______, _______,  KC_INS, KC_INS, _______, KC_RALT, KC_HOME, KC_PGDN, KC_END
	),

	/* AltGr
	 * ,-----------------------------------------------------------------------------------.
	 * |      |   ä  |   è  |   é  |   ê  |      |   ý  |   û  |   î  |   ô  |   œ  | Del  |
	 * |------+------+------+------+------+-------------+------+------+------+------+------|
	 * |      |   à  |   â  |   ë  |   €  |      |      |   ü  |   ï  |   ö  |      |      |
	 * |------+------+------+------+------+------|------+------+------+------+------+------|
	 * |      |      |      |   ç  |      |      |   ñ  |   °  |      |      |      |      |
	 * |------+------+------+------+------+------+------+------+------+------+------+------|
	 * |      |      |      |      |      |             |      |      |      |      |      |
	 * `-----------------------------------------------------------------------------------'
	 */



    /* Adjust (Lower + Raise)
     * ,-----------------------------------------------------------------------------------.
     * | RGB  |EFFET+|  HUE+|BRGTH+| SAT+ |BL ON | MOD+ |  BL+ |BL TOG|BLCYCL|BLBREA| Del  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |Reset |EFFET-|  HUE-|BRGTH-| SAT- |BL OFF| MOD- |  BL- |      |      |      |   |  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |RGB P |RGB B |RGB R |RGB SW|RGB SN|RGB G |RGB K |RGB X |RGB T | Vol+ | PLAY |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |Aud on|Aud of|Mus on|Musoff|      |      |      |      |      | Prev | Vol- | Next |
     * `-----------------------------------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT_planck_grid(
       RGB_TOG, RGB_SPI, RGB_HUI, RGB_VAI, RGB_SAI,  RGB_MOD, RGB_MOD,  BL_INC, BL_TOGG, BL_STEP, BL_BRTG, KC_DEL,
       _______, RGB_SPD, RGB_HUD, RGB_VAD, RGB_SAD, RGB_RMOD,RGB_RMOD,  BL_DEC, _______, KC_WH_U, KC_BTN2, KC_WH_D,
       _______, RGB_M_P, RGB_M_B, RGB_M_R,RGB_M_SW, RGB_M_SN, RGB_M_G, RGB_M_K, RGB_M_X, RGB_M_T, KC_MS_U, KC_BTN1,
       KC_SLEP,  AU_OFF,   MU_ON,  MU_OFF, _______,   KC_INS, KC_INS, KC_WH_U, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R
    )
};


const rgblight_segment_t PROGMEM base_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 9, HSV_BLACK});

const rgblight_segment_t PROGMEM lower_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 9, HSV_RED});

const rgblight_segment_t PROGMEM raise_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 9, HSV_BLUE});

const rgblight_segment_t PROGMEM adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 9, HSV_TURQUOISE});

const rgblight_segment_t PROGMEM capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 9, HSV_MAGENTA});

const rgblight_segment_t PROGMEM fn_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 9, HSV_MAGENTA});


enum rgb_layer_index {
    L_BASE,
    L_RAISE,
    L_LOWER,
    L_ADJUST,
    L_CAPSLOCK,
    L_FN
};

// Later layers take precedence.
const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    [L_BASE] = base_layer,
    [L_LOWER] = lower_layer,
    [L_RAISE] = raise_layer,
    [L_ADJUST] = adjust_layer,
    [L_CAPSLOCK] = capslock_layer,
	[L_FN] = fn_layer
); 


bool led_update_user(led_t led_state) {
    // Turn on RBG for capslock.
    rgblight_set_layer_state(4, led_state.caps_lock);
    return true;
}
 
layer_state_t layer_state_set_user(layer_state_t state) {
    //Set RBG layer according to active keymap layer.
	rgblight_set_layer_state(L_BASE, layer_state_cmp(state, _BASE));
    rgblight_set_layer_state(L_LOWER, layer_state_cmp(state, _LOWER));
	rgblight_set_layer_state(L_RAISE, layer_state_cmp(state, _RAISE));
	rgblight_set_layer_state(L_ADJUST, layer_state_cmp(state, _ADJUST));  
	rgblight_set_layer_state(L_FN, layer_state_cmp(state, _FN));	
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
        case RAISE:
        case LOWER:
            return false;
        default:
            return true;
    }
}

void rgb_matrix_indicators_user(void) {
  #ifdef RGB_MATRIX_ENABLE
  switch (biton32(layer_state)) {
	  
	case _LOWER:
      for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) {
          rgb_matrix_set_color(i, 0xD6, 0x89, 0x10);
        } else {
          rgb_matrix_set_color(i, 0xFF, 0xA5, 0xAF);
        }
      }
      break;
	  
    case _RAISE:
      for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) {
          rgb_matrix_set_color(i, 0x7D, 0x3C, 0x98);
        } else {
          rgb_matrix_set_color(i, 0xFF, 0xA5, 0xAF);
        }
      }
      break;

    case _FN:
      for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) {
          rgb_matrix_set_color(i, 0x00, 0x70, 0xFF);
        } else {
          rgb_matrix_set_color(i, 0xFF, 0xA5, 0xAF);
        }
      }
      break;
	
    case _ADJUST:
      for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) {
          rgb_matrix_set_color(i, 0x7B, 0x24, 0x1C);
        } else {
          rgb_matrix_set_color(i, 0xFF, 0xA5, 0xAF);
        }
      }
      break;
	  
    default:
      break;
  }
  #endif
}
