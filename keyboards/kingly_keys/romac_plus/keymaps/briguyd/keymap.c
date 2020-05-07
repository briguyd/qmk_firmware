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

const rgblight_segment_t PROGMEM base_layer_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 4, RGB_WHITE}       // Light 4 LEDs, starting with LED 0
);

const rgblight_segment_t PROGMEM gaming_layer_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 4, RGB_RED}       // Light 4 LEDs, starting with LED 0
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    base_layer_lights,
    gaming_layer_lights    // Overrides base layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_BASE] = LAYOUT(
		KC_7, KC_8, KC_9, \
		KC_4, KC_5, KC_6, \
		KC_1, KC_2, KC_3, \
		TO(_FN1), KC_0, KC_ENT \
	),

	[_FN1] = LAYOUT(
		KC_F16, KC_LGUI, KC_ESC, \
		LALT(KC_Z), KC_END, KC_TAB, \
		KC_F13, KC_F14, KC_F15, \
		TO(_BASE), KC_F16, KC_F17 \
	),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    // Both layers will light up if both kb layers are active

    // rgblight_set_layer_state(0, layer_state_cmp(state, 0));
    // rgblight_set_layer_state(1, layer_state_cmp(state, 1));
   uint8_t layer = biton32(state);

	  switch (layer) {
		case _BASE:
        rgblight_setrgb(RGB_YELLOW);
		  break;
		
		case _FN1:
		  
        rgblight_setrgb(RGB_AZURE);
		  break;
		
	  }

    return state;
}


#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;  // flips the display 180 degrees if offhand
}

void oled_task_user(void) {
  // Host Keyboard Layer Status
  // oled_clear();
  oled_write_P(PSTR("AliveAhahaFuck\n"), false);
  switch (get_highest_layer(layer_state)) {
    case _BASE:
      oled_write_ln_P(PSTR("\n\n\n"), false);
      break;
    case _FN1:
      oled_write_ln_P(PSTR("\nRise\nUp"), false);
      break;
    default:
      // Or use the write_ln shortcut over adding '\n' to the end of your string
      oled_write_ln_P(PSTR("Undef"), false);
  }

  // Host Keyboard LED Status
  // uint8_t led_usb_state = host_keyboard_leds();
  // oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NLCK ") : PSTR("     "), false);
  // oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPS ") : PSTR("       "), false);
  // oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLK") : PSTR("       "), false);
}
#endif
