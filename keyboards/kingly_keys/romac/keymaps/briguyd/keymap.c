/* Copyright 2018 Jack Humbert
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

#define _BASE 0
#define _FN1 1
#define _FN2 2
#define _FN3 3
#define HIGHEST_LAYER 3  // replace X with your highest layer

typedef struct {
  bool is_press_action;
  int state;
} tap;

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  DOUBLE_SINGLE_TAP = 5, //send two single taps
  TRIPLE_TAP = 6,
  TRIPLE_HOLD = 7
};

// enum keys {
//   U_LAYR = SAFE_RANGE,
//   RESET_LAYR
// };
static uint8_t current_layer = 0;

//Tap Dance Declarations
enum {
  TD_CYCLE_RESET_LAYERS = 0
};

int cur_dance (qk_tap_dance_state_t *state);
//for the layers tap dance. Put it here so it can be used in any keymap
void move_up (void *user_data);
void reset_layer (void *user_data);
void layers_finished (qk_tap_dance_state_t *state, void *user_data);
void layers_reset (qk_tap_dance_state_t *state, void *user_data);

int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)  return SINGLE_TAP;
    //key has not been interrupted, but they key is still held. Means you want to send a 'HOLD'.
    else return SINGLE_HOLD;
  }
  else if (state->count == 2) {
    /*
     * DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
     * action when hitting 'pp'. Suggested use case for this return value is when you want to send two
     * keystrokes of the key, and not the 'double tap' action/macro.
    */
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  //Assumes no one is trying to type the same letter three times (at least not quickly).
  //If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
  //an exception here to return a 'TRIPLE_SINGLE_TAP', and define that enum just like 'DOUBLE_SINGLE_TAP'
  if (state->count == 3) {
    if (state->interrupted || !state->pressed)  return TRIPLE_TAP;
    else return TRIPLE_HOLD;
  }
  else return 8; //magic number. At some point this method will expand to work for more presses
}

//instanalize an instance of 'tap' for the 'x' tap dance.
static tap layertap_state = {
  .is_press_action = true,
  .state = 0
};

void move_up(void *user_data) {
    current_layer++;
      if (current_layer > HIGHEST_LAYER) {
        current_layer = 0;
      }
      layer_move(current_layer);
}

void reset_layer(void *user_data) {
      current_layer = 0;
      layer_move(current_layer);
}

void layers_finished (qk_tap_dance_state_t *state, void *user_data) {
  layertap_state.state = cur_dance(state);
  switch (layertap_state.state) {
    case SINGLE_TAP: move_up(user_data); break;
    case SINGLE_HOLD: reset_layer(user_data); break;
    // case DOUBLE_TAP: register_code(KC_ESC); break;
    // case DOUBLE_HOLD: register_code(KC_LALT); break;
    // case DOUBLE_SINGLE_TAP: register_code(U_LAYR); unregister_code(U_LAYR); register_code(U_LAYR);
    //Last case is for fast typing. Assuming your key is `f`:
    //For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
    //In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
  }
}

void layers_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (layertap_state.state) {
    // case SINGLE_TAP: unregister_code(U_LAYR); break;
    // case SINGLE_HOLD: unregister_code(RESET_LAYR); break;
    // case DOUBLE_TAP: unregister_code(KC_ESC); break;
    // case DOUBLE_HOLD: unregister_code(KC_LALT);
    // case DOUBLE_SINGLE_TAP: unregister_code(KC_X);
  }
  layertap_state.state = 0;
}

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_CYCLE_RESET_LAYERS]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, layers_finished, layers_reset)
// Other declarations would go here, separated by commas, if you have them
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_BASE] = LAYOUT(
		KC_7, KC_8, KC_9, \
		KC_4, KC_5, KC_6, \
		KC_1, KC_2, KC_3, \
		TD(TD_CYCLE_RESET_LAYERS), KC_0, KC_ENT \
	),

	[_FN1] = LAYOUT(
		KC_F16, KC_LGUI, KC_ESC, \
		LALT(KC_Z), KC_END, KC_TAB, \
		KC_F13, KC_F14, KC_F15, \
		TD(TD_CYCLE_RESET_LAYERS), KC_F16, KC_F17 \
	),

	[_FN2] = LAYOUT(
		KC_2, KC_2, KC_2, \
		KC_2, KC_2, KC_2, \
		KC_2, KC_2, KC_2, \
		TD(TD_CYCLE_RESET_LAYERS), KC_2, KC_2 \
	),

	[_FN3] = LAYOUT(
		KC_3, KC_3, KC_3, \
		KC_3, KC_3, KC_3, \
		KC_3, KC_3, KC_3, \
		TD(TD_CYCLE_RESET_LAYERS), KC_3, KC_3 \
	),
};
