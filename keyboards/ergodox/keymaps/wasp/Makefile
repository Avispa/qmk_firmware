# Having a file like this allows you to override Makefile definitions for your own particular keymap

SUBPROJECT = infinity

LCD_BACKLIGHT_ENABLE = yes
LCD_ENABLE = yes
#LED_ENABLE = yes
NKRO_ENABLE = yes
#TAP_DANCE_ENABLE = yes
SLEEP_LED_ENABLE = no  # Breathing sleep LED during USB suspend
COMMAND_ENABLE   = no  # Commands for debug and configuration
RGBLIGHT_ENABLE ?= yes
MIDI_ENABLE ?= yes

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif
