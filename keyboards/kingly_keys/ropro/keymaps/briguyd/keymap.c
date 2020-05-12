/* Copyright 2019 Garret G. (TheRoyalSweatshirt)
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

enum layer_names {
    _BASE,
    _GAMING,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum ropro_keycodes {
  QWERTY = SAFE_RANGE,
  GAMING
};


#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

//Tap Dance Declarations
enum {
  TD_LCBR_LBRC = 0,
  TD_RCBR_RBRC
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_LCBR_LBRC]  = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_LBRC),
  [TD_RCBR_RBRC]  = ACTION_TAP_DANCE_DOUBLE(KC_RCBR, KC_RBRC)
// Other declarations would go here, separated by commas, if you have them
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* BASE
   *        ,-----------------------------------------------------------------------------------.
   *        |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10  | F11 |  F12 |
   *        |------+------+------+------+------+-------------+------+------+------+------+------|
   *        |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   -  |
   *        |+------+------+------+------+-----+------+------+------+------+------+------+------|--------------.
   *        | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp | Rotary Click |
   * ,------+------+------+------+------+------+------+------+------+------+------+------+------|--------------'
   * | 5    | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------|
   * | 6    | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |MOUSE5| Ctrl | RAlt | Alt  | GUI  |Lower |SPACE |SPACE | End  | Left | Down |  Up  |Right |
   * `------------------------------------------------------------------------------------------'
   */
  	[_BASE] = LAYOUT(
               KC_F1,     KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,    KC_F11,   KC_F12,
               KC_GRV,    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,      KC_0,     KC_MINUS,
    KC_CAPS,   KC_TAB,    KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,      KC_P,     KC_BSPC,
    TD(TD_LCBR_LBRC),      KC_ESC,    KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,      KC_SCLN,  KC_QUOT,
    _______,      KC_LSHIFT, KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,    KC_SLSH,  KC_ENT,
    TD(TD_RCBR_RBRC),      KC_LCTRL,  KC_RALT, KC_LALT,  KC_LGUI,   LOWER,    KC_SPC,   KC_SPC,   RAISE,    KC_LEFT,  KC_DOWN,   KC_UP,    KC_RGHT
  ),

  /* GAMING
   *        ,-----------------------------------------------------------------------------------.
   *        |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10  | F11 |  F12 |
   *        |------+------+------+------+------+-------------+------+------+------+------+------|
   *        |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   -  |
   *        |+------+------+------+------+-----+------+------+------+------+------+------+------|--------------.
   *        | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp | Rotary Click |
   * ,------+------+------+------+------+------+------+------+------+------+------+------+------|--------------'
   * | 5    | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------|
   * | 6    | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |MOUSE5| Ctrl | RAlt | Alt  | GUI  |Lower |SPACE |SPACE | End  | Left | Down |  Up  |Right |
   * `------------------------------------------------------------------------------------------'
   */
  	[_GAMING] = LAYOUT(
               KC_F1,     KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,    KC_F11,   KC_F12,
               KC_GRV,    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,      KC_0,     KC_MINUS,
    KC_CAPS,   KC_TAB,    KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,      KC_P,     KC_BSPC,
    KC_5,      KC_ESC,    KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,      KC_SCLN,  KC_QUOT,
    KC_6,      KC_LSHIFT, KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,    KC_SLSH,  KC_ENT,
    KC_BTN5,      KC_LCTRL,  KC_RALT, KC_LALT,  KC_LGUI,   LOWER,    KC_SPC,   KC_SPC,   RAISE,    KC_LEFT,  KC_DOWN,   KC_UP,    KC_RGHT
  ),

  /* LOWER
   *        ,-----------------------------------------------------------------------------------.
   *        |TOGRGB|      |      |      |Sat(-)|Hue(-)|Hue(+)|Sat(+)|      |      |Brght-|Brght+|
   *        |------+------+------+------+------+-------------+------+------+------+------+------|
   *        |  `   |      |      |      |      |      |      |      |      |      |      |   =  |
   *        |+------+------+------+------+-----+------+------+------+------+------+------+------|--------------.
   *        |      |      |  Up  |      |      |      |      |      |      |   (  |   )  |   \  |    NumLock   |
   * ,------+------+------+------+------+------+------+------+------+------+------+------+------|--------------'
   * | Home | Del  | Left | Down |Right |      |      |      |  _   |   +  |   {  |   }  |  |   |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | End  |      |      |      |      |      |      |      |      |      |      |      |PrScn |
   * `------------------------------------------------------------------------------------------'
   */
    [_LOWER] = LAYOUT(
              RGB_TOG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  RGB_SAD,  RGB_HUD,  RGB_HUI,  RGB_SAI,  KC_TRNS,  KC_TRNS,  RGB_VAD,  RGB_VAI,
              KC_GRAVE, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_EQUAL,
    KC_NLCK,  KC_TRNS,  KC_TRNS,  KC_UP,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_LPRN,  KC_RPRN,  KC_BSLS,
    KC_HOME,  KC_DEL,   KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_UNDS,  KC_PLUS,  KC_LCBR,  KC_RCBR,  KC_PIPE,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_END,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_PSCR
  ),

  /* RAISE
   *        ,-----------------------------------------------------------------------------------.
   *        |TOGRGB|      |      |      |Sat(-)|Hue(-)|Hue(+)|Sat(+)|      |      |Brght-|Brght+|
   *        |------+------+------+------+------+-------------+------+------+------+------+------|
   *        |  `   |      |      |      |      |      |      |      |      |      |      |   =  |
   *        |+------+------+------+------+-----+------+------+------+------+------+------+------|--------------.
   *        |      |      |  Up  |      |      |      |      |      |      |      |      |      |    NumLock   |
   * ,------+------+------+------+------+------+------+------+------+------+------+------+------|--------------'
   * | Pg Up| Del  | Left | Down |Right |      |      |      |   -  |   =  |   [  |   ]  |   \  |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |Pg Up |Pg Dn |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Pg Dn|      |      |      |      |      |      |      |      |      |      |      |PrScn |
   * `------------------------------------------------------------------------------------------'
   */
    [_RAISE] = LAYOUT(
              RGB_TOG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  RGB_SAD,  RGB_HUD,  RGB_HUI,  RGB_SAI,  KC_TRNS,  KC_TRNS,  RGB_VAD,  RGB_VAI,
              KC_GRAVE, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_EQUAL,
    KC_NLCK,  KC_TRNS,  KC_TRNS,  KC_UP,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_PGUP,  KC_DEL,   KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,  KC_BSLS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_PGUP, KC_PGDN,   KC_TRNS,
    KC_PGDN,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_PSCR
  ),

  /* ADJUST
   *        ,-----------------------------------------------------------------------------------.
   *        |      |      |      |      |      |      |      |      |      |      |      |      |
   *        |------+------+------+------+------+-------------+------+------+------+------+------|
   *        |      |      |      |      |      |      |      |      |      |      |      |      |
   *        |+-----+------+------+------+-----+-------+------+------+------+------+------+------|-----------.
   *        |      |      |      |      |      |      |      |      |      |      |      |      | Reset     |
   * ,------+------+------+------+------+------+------+------+------+------+------+------+------|-----------'
   * |QWERTY|      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------|
   * |GAMING|      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * `------------------------------------------------------------------------------------------'
   */
  	[_ADJUST] = LAYOUT(
               _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,   _______,  _______,  _______,  _______,
               _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,   _______,  _______,  _______,  _______,
    RESET,     _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,   _______,  _______,  _______,  _______,
    QWERTY,    _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,   _______,  _______,  _______,  _______,
    GAMING,    _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,   _______,  _______,  _______,  _______,
    _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,   _______,  _______,  _______,  _______
  ),
};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code16(C(S(KC_TAB)));
        } else {
            tap_code16(C(KC_TAB));
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_BASE);
        rgblight_setrgb(RGB_YELLOW);
      }
      return false;
      break;
    case GAMING:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_GAMING);
        rgblight_setrgb(RGB_AZURE);
      }
      return false;
      break;
  }
  return true;
}

