#include <keymap_extras/keymap_colemak.h>
#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "keymap_german.h"


// Layers
enum { QWERTZ = 0, KAY, SC1BW, SYMB, MDIA };

enum custom_keycodes {
	PLACEHOLDER = SAFE_RANGE, // can always be here
	RGB_FF00BB // always start with RGB_
};

enum {
	NONE = 0,
	// number/symbol keys
	A_1, // 1
	A_2, // 2
	A_3, // ...
	A_4,
	A_5,
	A_6,
	A_7,
	A_8,
	A_9,
	A_0,
	// Special
	A_SPC
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  |Ctrl- |           | Ctrl+|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  | Alt/J|   K  |   L  |; / L2| LGui/' |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * |LShift/(|Z/Ctrl|   X  |   C  |   V  |   B  |   [  |           |  ]   |   N  |   M  |   ,  |   .  |//Ctrl|RShift/)|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | -/L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Leader|------|       |------| Tab/L1 |Enter |
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
/*
[255] = KEYMAP(  // layer 0 : default
	// left hand
	 KC_EQL      ,KC_1        ,KC_2        ,KC_3        ,KC_4       ,KC_5        ,LCTL(KC_MINS)
	,KC_DELT     ,KC_Q        ,KC_W        ,KC_E        ,KC_R       ,KC_T        ,TG(SYMB)
	,KC_BSPC     ,KC_A        ,KC_S        ,KC_D        ,KC_F       ,KC_G
	,KC_LSPO     ,CTL_T(KC_Z) ,KC_X        ,KC_C        ,KC_V       ,KC_B        ,ALL_T(KC_LBRC)
	,LT(SYMB,KC_GRV),KC_QUOT  ,LALT(KC_LSFT)  ,KC_LEFT  ,KC_RGHT
	                                                                             ,ALT_T(KC_APP) ,KC_LGUI
	                                                                                            ,KC_HOME
	                                                                ,KC_SPC      ,KC_LEAD       ,KC_END
	// right hand
	,LCTL(KC_EQL)  ,KC_6         ,KC_7       ,KC_8          ,KC_9          ,KC_0            ,KC_MINS
	,TG(SYMB)      ,KC_Y         ,KC_U       ,KC_I          ,KC_O          ,KC_P            ,KC_BSLS
	,KC_H          ,ALT_T(KC_J)  ,KC_K       ,KC_L          ,LT(MDIA,KC_SCLN),GUI_T(KC_QUOT)
	,MEH_T(KC_RBRC),KC_N         ,KC_M       ,KC_COMM       ,KC_DOT        ,CTL_T(KC_SLSH)  ,KC_RSPC
	,KC_UP         ,KC_DOWN      ,KC_LBRC,KC_RBRC           ,LT(SYMB,KC_MINS)
	,KC_LALT       ,CTL_T(KC_ESC)
	,KC_PGUP
	,KC_PGDN,LT(SYMB ,KC_TAB) ,KC_ENT
),
*/

/* Keymap 0: QWERTZ Layer (~Base Layer~)
 *
 * ,-----------------------------------------------------.           ,-----------------------------------------------------.
 * |           | 9  § | 7  ! | 5  " | 3  $ | 1  & | /SYMB|           | SCLK | 0  % | 2  / | 4  ( | 6  ) | 8 =  |   K.A,Y   |
 * |-----------+------+------+------+------+-------------|           |------+------+------+------+------+------+-----------|
 * |     ^     |   Q  |   w  |   E  |R/Ctrl|   T  |  <   |           |  ´   |   Z  |U/Ctrl|   I  |   O  |  P   |     Ü     |
 * |-----------+------+------+------+------+------|      |           |      |------+------+------+------+------+-----------|
 * |     ß     |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  Ö   |  Ä/LShift |
 * |-----------+------+------+------+------+------| LGUI |           |  #   |------+------+------+------+------+-----------|
 * |PlayPa/Ctrl|  Y   |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  -   |   +/Ctrl  |
 * `-----------+------+------+------+------+-------------'           `-------------+------+------+------+------+-----------'
 *     |  PgDn | PgUp | Home |  End |   ß  |                                       | Left |  Up  | Down | Right|  DEL  |
 *     `-----------------------------------'                                       `-----------------------------------'
 *                                         ,-------------.           ,-------------.
 *                                         | LAlt | RCtrl|           | RGUI | LAlt |
 *                                  ,------|------|------|           |------+------+------.
 *                                  |      |      | LGUI |           | RAlt |      |      |
 *                                  |LShift|Backsp|------|           |------|Tab/L1| Space|
 *                                  |      |      | ESC  |           | Enter|      |      |
 *                                  `--------------------'           `--------------------'
 */
[QWERTZ] = KEYMAP(
	// left hand
	   KC_NO         ,M(A_9)        ,M(A_7)        ,M(A_5)       ,M(A_3)        ,M(A_1)        ,MO(SYMB)
	  ,DE_CIRC       ,KC_Q          ,KC_W          ,KC_E         ,CTL_T(KC_R)   ,KC_T          ,DE_LESS
	  ,KC_MINS       ,KC_A          ,KC_S          ,KC_D         ,KC_F          ,KC_G
	  ,CTL_T(KC_MPLY),KC_Z          ,KC_X          ,KC_C         ,KC_V          ,KC_B          ,KC_LGUI
	  ,KC_PGDN       ,KC_PGUP       ,KC_HOME       ,KC_END       ,KC_MINS
	
	                                                                                           ,KC_LALT     ,KC_RCTL
	                                                                                                        ,KC_LGUI
	                                                                            ,KC_LSFT       ,KC_BSPC     ,KC_ESC
	
	// right hand
	                 ,KC_SLCK     ,M(A_0)      ,M(A_2)         ,M(A_4)     ,M(A_6)      ,M(A_8)      ,DF(KAY)
	                 ,KC_EQL      ,KC_Y        ,CTL_T(KC_U)    ,KC_I       ,KC_O        ,KC_P        ,DE_UE
	                              ,KC_H        ,KC_J           ,KC_K       ,KC_L        ,DE_OE       ,SFT_T(DE_AE)
	                 ,DE_HASH     ,KC_N        ,KC_M           ,KC_COMM    ,KC_DOT      ,DE_MINS     ,CTL_T(DE_PLUS)
	                                           ,KC_LEFT        ,KC_DOWN    ,KC_UP       ,KC_RIGHT    ,KC_DEL
	
	  ,KC_RGUI       ,KC_LALT
	  ,KC_RALT
	  ,KC_ENT        ,LT(SYMB,KC_TAB),M(A_SPC)
),

/* Keymap: K.A,Y Layer
 *
 * ,-----------------------------------------------------.           ,-----------------------------------------------------.
 * | Next/Prev | 9  § | 7  ! | 5  " | 3  $ | 1  & | /SYMB|           | SCLK | 0  % | 2  / | 4  ( | 6  ) | 8 =  |   SC1BW   |
 * |-----------+------+------+------+------+-------------|           |------+------+------+------+------+------+-----------|
 * |     ^     |   K  |   .  |   A  |,/Ctrl|   Y  |  <   |           |  #   |   P  |D/Ctrl|   L  |   M  |  J   |     X     |
 * |-----------+------+------+------+------+------|      |           |      |------+------+------+------+------+-----------|
 * |     -     |   H  |   O  |   E  |   I  |   U  |------|           |------|   G  |   T  |   R  |   N  |  S   |     ß     |
 * |-----------+------+------+------+------+------| LGUI |           |  ´   |------+------+------+------+------+-----------|
 * | Play/Pause|   Z  |   F  |   Ä  |Ü/LAlt|   Ö  |      |           |      |   B  |C/LAlt|   W  |   V  |  Q   |     +     |
 * `-----------+------+------+------+------+-------------'           `-------------+------+------+------+------+-----------'
 *     |  PgDn | PgUp | Home |  End |   -  |                                       | Left |  Up  | Down | Right|  DEL  |
 *     `-----------------------------------'                                       `-----------------------------------'
 *                                         ,-------------.           ,-------------.
 *                                         | Ctrl | LGUI |           | RGUI | Ctrl |
 *                                  ,------|------|------|           |------+------+------.
 *                                  |      |      | LAlt |           | RAlt |      |      |
 *                                  |LShift|Backsp|------|           |------| Tab  | SP/BS|
 *                                  |,Ctrl |      | ESC  |           | Enter|/SYMB |      |
 *                                  `--------------------'           `--------------------'
 */
[KAY] = KEYMAP(
	// left hand
	 KC_NO         ,M(A_9)        ,M(A_7)        ,M(A_5)       ,M(A_3)        ,M(A_1)        ,MO(SYMB)
	,DE_CIRC       ,KC_K          ,KC_DOT        ,KC_A         ,ALT_T(KC_COMM),KC_Z          ,DE_LESS
	,DE_MINS       ,KC_H          ,KC_O          ,KC_E         ,KC_I          ,KC_U
	,CTL_T(KC_MPLY),KC_Y          ,KC_F          ,DE_AE        ,CTL_T(DE_UE)  ,DE_OE         ,KC_LGUI
	,KC_PGDN       ,KC_PGUP       ,KC_HOME       ,KC_END       ,DE_MINS
	                                                                                         ,KC_LCTL       ,KC_LGUI
	                                                                                                        ,KC_LALT
	                                                                          ,KC_LSFT       ,KC_BSPC ,KC_ESC


	// right hand
	               ,KC_SLCK       ,M(A_0)        ,M(A_2)       ,M(A_4)        ,M(A_6)        ,M(A_8)        ,DF(SC1BW)
	               ,DE_HASH       ,KC_P          ,ALT_T(KC_D)  ,KC_L          ,KC_M          ,KC_J          ,KC_X
	                              ,KC_G          ,KC_T         ,KC_R          ,KC_N          ,KC_S          ,KC_MINS
	               ,KC_EQL        ,KC_B          ,CTL_T(KC_C)  ,KC_W          ,KC_V          ,KC_Q          ,CTL_T(DE_PLUS)
	                                             ,KC_LEFT      ,KC_DOWN       ,KC_UP         ,KC_RIGHT      ,KC_DEL
	,KC_RGUI       ,KC_RCTL
	,KC_RALT
	,KC_ENT        ,LT(SYMB,KC_TAB),M(A_SPC)
),

/* Keymap: SC1BW Layer
 *
 * ,-----------------------------------------------------.           ,-----------------------------------------------------.
 * | Esc/Shift |   1  |   2  |   3  |   4  |   5  |   G  |           | Print| 0  % | 2  / | 4  ( | 6  ) | 8 =  |   QWERTZ  |
 * |-----------+------+------+------+------+-------------|           |------+------+------+------+------+------+-----------|
 * |  F2/Ctrl  |   6  |   7  |   8  |   9  |   0  |   T  |           |  ´   |   P  |D/Ctrl|   L  |   M  |  J   |           |
 * |-----------+------+------+------+------+------|      |           |      |------+------+------+------+------+-----------|
 * |    F3     |   A  |   S  |   I  |   P  |   H  |------|           |------|   G  |   T  |   R  |   N  |  S   |           |
 * |-----------+------+------+------+------+------|   V  |           |   M  |------+------+------+------+------+-----------|
 * |    F4     |   Y  |   W  |   O  |   U  |   B  |      |           |      |   B  |   C  |   W  |   V  |  F   |           |
 * `-----------+------+------+------+------+-------------'           `-------------+------+------+------+------+-----------'
 *     |   C   |   Q  |   K  |   D  |   Z  |                                       | Left |  Up  | Down | Right|  DEL  |
 *     `-----------------------------------'                                       `-----------------------------------'
 *                                         ,-------------.           ,-------------.
 *                                         |   R  |   F  |           | RGUI | Ctrl |
 *                                  ,------|------|------|           |------+------+------.
 *                                  |      |      |   N  |           | RAlt |      |      |
 *                                  |LShift| Space|------|           |------| Tab  |      |
 *                                  |      |      |   L  |           | Enter|/SYMB |      |
 *                                  `--------------------'           `--------------------'
 */
[SC1BW] = KEYMAP(
	// left hand
	 SFT_T(KC_ESC) ,KC_1          ,KC_2          ,KC_3         ,KC_4          ,KC_5          ,KC_G
	,CTL_T(KC_F2)  ,KC_6          ,KC_7          ,KC_8         ,KC_9          ,KC_0          ,KC_V
	,KC_F3         ,KC_A          ,KC_S          ,KC_I         ,KC_P          ,KC_H
	,KC_F4         ,KC_Z          ,KC_W          ,KC_O         ,KC_U          ,KC_B          ,KC_T
	,KC_C          ,KC_Q          ,KC_K          ,KC_D         ,KC_Y
	                                                                                         ,KC_R          ,KC_F
	                                                                                                        ,KC_N
	                                                                          ,KC_LSFT       ,KC_SPC        ,KC_L


	// right hand
	               ,KC_PSCR       ,M(A_0)        ,M(A_2)       ,M(A_4)        ,M(A_6)        ,M(A_8)        ,DF(QWERTZ)
	               ,KC_EQL        ,KC_P          ,ALT_T(KC_D)  ,KC_L          ,KC_M          ,KC_J          ,KC_NO
	                              ,KC_G          ,KC_T         ,KC_R          ,KC_N          ,DE_S          ,KC_NO
	               ,KC_M          ,KC_B          ,CTL_T(KC_C)  ,KC_W          ,KC_V          ,DE_F          ,KC_NO
	                                             ,KC_LEFT      ,KC_DOWN       ,KC_UP         ,KC_RIGHT      ,KC_DEL
	,KC_RGUI       ,KC_RCTL
	,KC_RALT
	,KC_ENT        ,LT(SYMB,KC_TAB),M(A_SPC)
),


/* Keymap: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  F11   |  F9  |  F7  |  F5  |  F3  |  F1  | /SYMB|           |   -  |  F10 |  F2  |  F4  |  F6  |  F8  |  F12   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  F13   |   @  |   %  |   {  |}/Ctrl|   |  |   &  |           |   +  |   7  |8/Ctrl|   9  |   *  |      |  F14   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  F15   |   $  |   <  |   (  |   )  |   >  |------|           |------|   4  |   5  |   6  |   /  |      |  F16   |
 * |--------+------+------+------+------+------|   !  |           | Enter|------+------+------+------+------+--------|
 * |  F17   |   ~  |   =  |   [  |]/LAlt|   \  |      |           |      |   1  |   2  |   3  |   €  |      |  F18   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |FF00BB|      |      |NxtTab|PrvTab|                                       |   0  |   ,  |   .  |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |Backsp|
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |  DEL |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = KEYMAP(
	// left hand
	   KC_F11        ,KC_F9         ,KC_F7         ,KC_F5         ,KC_F3         ,KC_F1         ,KC_TRNS
	  //,KC_F13        ,DE_AT         ,DE_PERC       ,DE_LCBR       ,CTL_T(DE_RCBR),DE_PIPE       ,DE_AMPR
	  ,KC_F13        ,DE_AT         ,DE_PERC       ,DE_LCBR       ,DE_RCBR       ,DE_PIPE       ,DE_AMPR
	  ,KC_F15        ,DE_DLR        ,DE_LESS       ,DE_LPRN       ,DE_RPRN       ,DE_MORE
	  //,KC_F17        ,DE_TILD       ,DE_EQL        ,DE_LBRC       ,ALT_T(DE_RBRC),DE_BSLS       ,DE_EXLM
	  ,KC_F17        ,DE_TILD       ,DE_EQL        ,DE_LBRC       ,DE_RBRC       ,DE_BSLS       ,DE_EXLM
	  ,RGB_FF00BB    ,KC_NO         ,KC_NO         ,LCTL(KC_PGUP) ,LCTL(KC_PGDN)
	                                                                                            ,KC_TRNS       ,KC_TRNS
	                                                                                                           ,KC_TRNS
	                                                                             ,KC_TRNS       ,KC_DEL        ,KC_TRNS
	// right hand
	                 ,DE_MINS       ,KC_F10        ,KC_F2         ,KC_F4         ,KC_F6         ,KC_F8         ,KC_F12
	                 ,DE_PLUS       ,KC_7          ,CTL_T(KC_8)   ,KC_9          ,DE_ASTR       ,KC_NO         ,KC_F14
	                                ,KC_4          ,KC_5          ,KC_6          ,DE_SLSH       ,KC_NO         ,KC_F16
	                 ,KC_ENT        ,KC_1          ,KC_2          ,KC_3          ,DE_EURO       ,KC_NO         ,KC_F18
	                                               ,KC_0          ,KC_COMM       ,KC_DOT        ,KC_NO         ,KC_NO
	  ,KC_TRNS       ,KC_BSPC
	  ,KC_TRNS
	  ,KC_TRNS       ,KC_TRNS       ,KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | PgUp | Home | End  | PgDn |      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA
[MDIA] = KEYMAP(
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_PGUP, KC_HOME, KC_END,  KC_PGDN, KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
                                           KC_NO  , KC_NO  ,
                                                    KC_NO  ,
                                  KC_NO  , KC_NO  , KC_NO  ,
    // right hand
       KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
                 KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_MPLY,
       KC_NO  ,  KC_NO  , KC_NO  , KC_MPRV, KC_MNXT, KC_NO  , KC_NO  ,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  ,
       KC_NO  ,
       KC_NO  , KC_NO  , KC_WBAK
),
};

const uint16_t PROGMEM fn_actions[] = {
	[1] = ACTION_LAYER_TAP_TOGGLE(SYMB)               // FN1 - Momentary Layer SYMB (Symbols)
	//[2] = ACTION_MACRO_TAP(0),
	//[3] = ACTION_MACRO_TAP(0)
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		// dynamically generate these.
	case RGB_FF00BB:
#ifdef RGBLIGHT_ENABLE
		if (record->event.pressed) {
			rgblight_enable();
			rgblight_mode(1);
			rgblight_setrgb(0xff,0x00,0xbb);
		}
#endif
		return false;
		break;
	}
	return true;
}

static void wasp_num_row(uint8_t id, keyrecord_t *record) {
	uint8_t idx = id - A_1;
	uint8_t kc;
	static bool shifted[10];

	if (keyboard_report->mods & MOD_BIT(KC_LSFT) || ((get_oneshot_mods() & MOD_BIT(KC_LSFT)) && !has_oneshot_mods_timed_out())) {
		if (record->event.pressed) {
			shifted[idx] = true;
		}	
	}

	if (!shifted[idx]) {
		kc = idx + KC_1;
	}
	else {
		switch (id) {
		case A_1: kc = DE_6; break;
		case A_3: kc = DE_4; break;
		case A_5: kc = DE_2; break;
		case A_7: kc = DE_1; break;
		case A_9: kc = DE_3; break;

		case A_0: kc = DE_5; break;
		case A_2: kc = DE_7; break;
		case A_4: kc = DE_8; break;
		case A_6: kc = DE_9; break;
		case A_8: kc = DE_0; break;
		}
	}

	if (record->event.pressed) {
		register_code (kc);
	}
	else {
		unregister_code (kc);
		shifted[idx] = false;
	}
}

static void wasp_space(uint8_t id, keyrecord_t *record) {
	uint8_t kc;
	static bool shifted_spc;

	if (keyboard_report->mods & MOD_BIT(KC_LSFT) || ((get_oneshot_mods() & MOD_BIT(KC_LSFT)) && !has_oneshot_mods_timed_out())) {
		if (record->event.pressed) {
			shifted_spc = true;
		}	
	}

	if (!shifted_spc) {
		kc = KC_SPC;
	}
	else {
		kc = KC_BSPC;
	}

	if (record->event.pressed) {
		register_code (kc);
	}
	else {
		unregister_code (kc);
		shifted_spc = false;
	}
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	switch(id) {
	case A_1 ... A_0:
		wasp_num_row(id, record);
		break;
	case A_SPC:
		wasp_space(id, record);
		break;
	}
	return MACRO_NONE;
}


LEADER_EXTERNS();

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
	uint8_t layer = biton32(layer_state);

	ergodox_board_led_off();
	ergodox_right_led_1_off();
	ergodox_right_led_2_off();
	ergodox_right_led_3_off();
	switch (layer) {
		// TODO: Make this relevant to the ErgoDox EZ.
	case 0:
		#ifdef SUBPROJECT_infinity
		//lcd_backlight_hal_color(0, 0, 0);
		#endif
	case 1:
		ergodox_right_led_1_on();
		#ifdef SUBPROJECT_infinity
		//lcd_backlight_hal_color(5000, 0, 0);
		#endif
		break;
	case 2:
		ergodox_right_led_2_on();
		#ifdef SUBPROJECT_infinity
		//lcd_backlight_hal_color(0, 5000, 0);
		#endif
		break;
	default:
		// none
		break;
	}

	LEADER_DICTIONARY() {
		leading = false;
		leader_end();

		SEQ_ONE_KEY(KC_W) {
			register_code(KC_LALT);
			register_code(KC_F4);
			unregister_code(KC_F4);
			unregister_code(KC_LALT);
		}
		SEQ_ONE_KEY(KC_O) {
			register_code(KC_LCTL);
			register_code(KC_LSFT);
			register_code(KC_O);
			unregister_code(KC_O);
			unregister_code(KC_LSFT);
			unregister_code(KC_LCTL);
		}
	}
}

