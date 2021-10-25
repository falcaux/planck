/* Copyright 2020 Andrew Liaw
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

//#ifdef AUDIO_ENABLE
//float planck_sound[][2] = SONG(PLANCK_SOUND);
//#endif

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
  * | Ctrl | GUI  | Alt  | FN   | Lower|    Space    | Raise| AltGr| Left | Down |Right |
  * `-----------------------------------------------------------------------------------'
  */
    [_BASE] = LAYOUT_planck_grid(
	KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P, KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT,  KC_UP,  KC_ENT,
    KC_LCTL, KC_LGUI, KC_LALT,   FN,   LOWER,  KC_SPC,  KC_SPC,   RAISE, KC_RALT, KC_LEFT,KC_DOWN, KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | DEL  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | CAPS |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   -  |   =  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |  {   |   }  | Pg Up|  ?   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |     inser   |      |      | Home | Pg Dn| End  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC,KC_AMPR, KC_ASTR,  KC_LPRN, KC_RPRN, KC_DEL,
    KC_CAPS,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, KC_UNDS, KC_PLUS,  KC_MINS, KC_EQL, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, _______, KC_LBRC, KC_RBRC, KC_PGUP, KC_QUES,
    _______, _______, _______, _______,_______,  KC_INS,  KC_INS, _______, _______,  KC_HOME, KC_PGDN, KC_END
    ),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | DEL  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | CAPS |      | Vol+ |      |      |      |      |   _  |   +  |   -  |   =  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | Prev | Vol- | Next |      |      |      |      |   [  |  ]   | Pg Up|  ?   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |     inser   |      |      | Home | Pg Dn| End  |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,   KC_0,  KC_DEL,
    KC_CAPS, _______, KC_VOLU, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_MINS, KC_EQL, KC_SLSH,
    _______, KC_MPRV, KC_VOLD, KC_MNXT, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_PGUP,KC_QUES,
    _______, _______, _______, _______, _______,  KC_INS,  KC_INS, _______, _______, KC_HOME, KC_PGDN, KC_END
),

    /* Adjust (Lower + Raise)
     * ,-----------------------------------------------------------------------------------.
     * | RGB  |EFFET+|  HUE+|BRGTH+| SAT+ |BL ON | MOD+ |  BL+ |BL TOG|BLCYCL|BLBREA| DEL  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |Reset |EFFET-|  HUE-|BRGTH-| SAT- |BL OFF| MOD- |  BL- |      |      |      |   |  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |Aud of|RGB P |RGB B |RGB R |RGB SW|RGB SN|RGB G |RGB K |RGB X |RGB T | Vol+ | PLAY |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |Aud on|Mus on|Musoff|      |      |      |      |      |      | Prev | Vol- | Next |
     * `-----------------------------------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT_planck_grid(
       RGB_TOG, RGB_SPI, RGB_HUI, RGB_VAI, RGB_SAI,    BL_ON, RGB_MOD,  BL_INC, BL_TOGG, BL_STEP, BL_BRTG, KC_DEL,
         RESET, RGB_SPD, RGB_HUD, RGB_VAD, RGB_SAD,   BL_OFF,RGB_RMOD,  BL_DEC, _______, _______, _______,KC_PIPE,
       _______, RGB_M_P, RGB_M_B, RGB_M_R,RGB_M_SW, RGB_M_SN, RGB_M_G, RGB_M_K, RGB_M_X, RGB_M_T, KC_VOLU,KC_MPLY,
         AU_ON,  AU_OFF,   MU_ON,  MU_OFF, _______,  _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT
    ),

	/* FN
	 * ,-----------------------------------------------------------------------------------.
	 * |      |Inser | Home | Pg Up|      |      |      |   *  |   7  |   8  |   9  |  Del |
	 * |------+------+------+------+------+-------------+------+------+------+------+------|
	 * | CAPS | Del  |  End | Pg Dn|      |      |      |   -  |   4  |   5  |   6  |  /   |
	 * |------+------+------+------+------+------|------+------+------+------+------+------|
	 * |      | PLAY | MUTE |      |      |      |      |   !  |   1  |   2  |   3  | Vol+ |
	 * |------+------+------+------+------+------+------+------+------+------+------+------|
	 * |      |      |      |      |      |    PLAY     |   0  |   0  | Prev | Next | Vol- |
	 * `-----------------------------------------------------------------------------------'
	 */

	[_FN] = LAYOUT_planck_grid(
		_______,   KC_INS, KC_HOME, KC_PGUP, RGB_TOG, _______, _______, KC_ASTR, KC_7,   KC_8,   KC_9,  KC_BSPC,
		KC_CAPS,   KC_DEL,  KC_END, KC_PGDN, _______, _______, _______, KC_MINS, KC_4,   KC_5,   KC_6,  KC_SLSH,
		_______,  KC_MPLY, KC_MUTE, _______, _______, _______, _______, KC_EXLM, KC_1,   KC_2,   KC_3,  KC_VOLU, 
		KC_NLCK,    RESET,   RESET, _______, _______, KC_MPLY, KC_MPLY,    KC_0, KC_0,KC_MPRV, KC_MNXT, KC_VOLD
	)

};


const rgblight_segment_t PROGMEM base_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 0, HSV_BLACK});

const rgblight_segment_t PROGMEM lower_layer[] = RGBLIGHT_LAYER_SEGMENTS({1, 1, HSV_RED}, {8, 1, HSV_RED});

const rgblight_segment_t PROGMEM raise_layer[] = RGBLIGHT_LAYER_SEGMENTS({3, 4, HSV_GOLD}, {1, 1, HSV_GOLD}, {8, 1, HSV_GOLD}, {7, 1, HSV_GOLD});

const rgblight_segment_t PROGMEM adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS({3, 4, HSV_GREEN}, {1, 1, HSV_TURQUOISE}, {8, 1, HSV_TURQUOISE}, {7, 1, HSV_TURQUOISE});

const rgblight_segment_t PROGMEM capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS({3, 4, HSV_CORAL}, {1, 1, HSV_CORAL}, {8, 1, HSV_CORAL});

const rgblight_segment_t PROGMEM fn_layer[] = RGBLIGHT_LAYER_SEGMENTS({1, 1, HSV_MAGENTA}, {8, 1, HSV_MAGENTA});



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

//bool audio_disable = false;

void keyboard_pre_init_user(void) {
    // If the audio is off during hardware init,
    // it causes problem when the audio is turn on later.
    // The workaround is to always set the audio on during hardware init,
    // then toggle audio back to the setting.
//#ifdef AUDIO_ENABLE
  //  if (!is_audio_on()) {
//         audio_disable = false;
    //    audio_on();
  //  }
//#endif
}

/* void matrix_init_user(void) {
    // To fix a audio related problem. See comments in keyboard_pre_init_user().
#ifdef AUDIO_ENABLE
 //   if (audio_disable) {
//         audio_off();
   // }
#endif
} 

void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;
    rgblight_set_layer_state(0, true);
}*/

bool leader_found;
LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading      = false;
        leader_found = false;
        SEQ_ONE_KEY(L_RESET) {
            leader_found = true;
            reset_keyboard();
        }
        else
            SEQ_ONE_KEY(KC_DEL) {
            leader_found = true;
            layer_clear();
        }
        else
            SEQ_ONE_KEY(LOWER) {
            leader_found = true;
            layer_on(_LOWER);
        }
        else
            SEQ_ONE_KEY(RAISE) {
            leader_found = true;
            layer_on(_RAISE);
        }
        leader_end();
    }
}

//void leader_end(void) {
    // Plays sound on if leader sequence found.
  //  if (leader_found) {
//#ifdef AUDIO_ENABLE
//         PLAY_SONG(planck_sound);
//#endif
//    }
//}

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
    case _RAISE:
      for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) {
          rgb_matrix_set_color(i, 0x6B, 0x00, 0x80);
        } else {
          rgb_matrix_set_color(i, 0x00, 0xFF, 0x00);
        }
      }
      break;

    case _LOWER:
      for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) {
          rgb_matrix_set_color(i, 0xFF, 0xA5, 0x00);
        } else {
          rgb_matrix_set_color(i, 0x00, 0x67, 0xC7);
        }
      }
      break;

    case _ADJUST:
      for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        rgb_matrix_set_color(i, 0xFF, 0x99, 0x00);
      }
      rgb_matrix_set_color(1, 0xFF, 0x00, 0x00);
      break;
	  
    case _FN:
      for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        rgb_matrix_set_color(i, 0x40, 0xCF, 0x20);
      }
      rgb_matrix_set_color(1, 0xAF, 0xC0, 0xA0);
      break;

    default:
      break;
  }
  #endif
}
