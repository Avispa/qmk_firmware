#include "simple_visualizer.h"

// XXX: Colors are in HSV.

// Function is declared in `keyboards/ergodox/infinity/simple_visualizer.h`.
static void get_visualizer_layer_and_color(visualizer_state_t* state) {
	uint8_t saturation = 60;
	if (state->status.leds & (1u << USB_LED_CAPS_LOCK)) {
		saturation = 255;
	}
	if (state->status.layer & 0x8) {
		state->target_lcd_color = LCD_COLOR(100, saturation, 0xFF);
		state->layer_text = "Layer 0x8";
	}
	if (state->status.layer & 0x5) {
		state->target_lcd_color = LCD_COLOR(100, saturation, 0xFF);
		state->layer_text = "Layer 0x5";
	}
	else if (state->status.layer & 0x4) {
		state->target_lcd_color = LCD_COLOR(0, saturation, 0xFF); // red probably
		state->layer_text = "Media & Mouse";
	}
	else if (state->status.layer & 0x3) {
		state->target_lcd_color = LCD_COLOR(100, saturation, 0xFF);
		state->layer_text = "Layer 0x3";
	}
	else if (state->status.layer & 0x2) {
		state->target_lcd_color = LCD_COLOR(168, saturation, 0xFF);
		state->layer_text = "Symbol";
	}
	else {
		state->target_lcd_color = LCD_COLOR(84, saturation, 0xFF); // green with little cyan
		state->layer_text = "QWERTZ";
	}
}
