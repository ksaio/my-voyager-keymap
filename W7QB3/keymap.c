#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  ST_MACRO_0,
};



#define DUAL_FUNC_0 LT(8, KC_F9)
#define DUAL_FUNC_1 LT(3, KC_P)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSPC,        
    KC_TAB,         KC_Q,           KC_W,           KC_D,           KC_F,           KC_K,                                           KC_J,           KC_U,           KC_R,           KC_L,           DK_AE,          DUAL_FUNC_0,    
    KC_TRANSPARENT, MT(MOD_LGUI, KC_A),MT(MOD_LALT, KC_S),MT(MOD_LSFT, KC_E),MT(MOD_LCTL, KC_T),KC_G,                                           KC_Y,           MT(MOD_RCTL, KC_N),MT(MOD_RSFT, KC_I),MT(MOD_RALT, KC_O),MT(MOD_RGUI, KC_H),MT(MOD_RSFT, DK_OSTR),
    KC_TRANSPARENT, KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_P,           KC_M,           DK_COMM,        DUAL_FUNC_1,    DK_QUES,        KC_TRANSPARENT, 
                                                    LT(1, KC_SPACE),MT(MOD_RGUI, KC_BSPC),                                MT(MOD_RGUI, KC_DELETE),LT(2, KC_ENTER)
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_TRANSPARENT, LCTL(LSFT(KC_4)),RGB_MODE_FORWARD,                                KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_MEDIA_PLAY_PAUSE,KC_AUDIO_MUTE,  KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_PGDN,        KC_HOME,        KC_UP,          KC_END,         KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_0,                                     KC_PAGE_UP,     KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_BSPC,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, LCTL(RSFT(KC_TAB)),LCTL(KC_TAB),   KC_TRANSPARENT, QK_BOOT,        
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 LCTL(KC_SPACE), KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    KC_TRANSPARENT, DK_GRV,         DK_LABK,        LSFT(KC_NUBS),  DK_MINS,        RALT(KC_I),                                     DK_CIRC,        LALT(LSFT(KC_8)),LALT(LSFT(KC_9)),RALT(RSFT(KC_3)),KC_TRANSPARENT, KC_F12,         
    KC_TRANSPARENT, DK_EXLM,        DK_QUES,        DK_ASTR,        DK_EQL,         DK_AMPR,                                        DK_HASH,        DK_LPRN,        DK_RPRN,        DK_SCLN,        DK_DQUO,        DK_SLSH,        
    KC_TRANSPARENT, DK_TILD,        DK_PLUS,        DK_LBRC,        DK_RBRC,        DK_PERC,                                        RALT(DK_QUOT),  DK_COLN,        DK_COMM,        DK_DOT,         DK_QUOT,        RALT(RSFT(KC_7)),
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT(
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 
  '*', '*', '*', '*'
);




extern rgb_config_t rgb_matrix_config;

RGB hsv_to_rgb_with_value(HSV hsv) {
  RGB rgb = hsv_to_rgb( hsv );
  float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
  return (RGB){ f * rgb.r, f * rgb.g, f * rgb.b };
}

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [1] = { {0,0,0}, {50,218,204}, {50,255,244}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,245,245}, {0,0,0}, {41,255,255}, {0,255,255}, {0,0,0}, {0,0,0}, {169,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {0,0,0}, {0,0,0}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,237}, {0,0,237}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {209,218,204}, {209,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {169,255,255}, {169,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb_with_value(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (!keyboard_config.disable_layer_led) { 
    switch (biton32(layer_state)) {
      case 1:
        set_layer_color(1);
        break;
      case 2:
        set_layer_color(2);
        break;
     default:
        if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
          rgb_matrix_set_color_all(0, 0, 0);
        }
    }
  } else {
    if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
      rgb_matrix_set_color_all(0, 0, 0);
    }
  }

  return true;
}





bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case QK_MODS ... QK_MODS_MAX:
    // Mouse and consumer keys (volume, media) with modifiers work inconsistently across operating systems,
    // this makes sure that modifiers are always applied to the key that was pressed.
    if (IS_CONSUMER_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode))) {
      if (record->event.pressed) {
        add_mods(QK_MODS_GET_MODS(keycode));
        send_keyboard_report();
        wait_ms(2);
        register_code(QK_MODS_GET_BASIC_KEYCODE(keycode));
        return false;
      } else {
        wait_ms(2);
        del_mods(QK_MODS_GET_MODS(keycode));
      }
    }
    break;
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_SPACE))SS_DELAY(30)  SS_TAP(X_G)SS_DELAY(100)  SS_TAP(X_SPACE));
    }
    break;

    case DUAL_FUNC_0:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(DK_ARNG);
        } else {
          unregister_code16(DK_ARNG);
        }
      } else {
        if (record->event.pressed) {
          register_code16(DK_SLSH);
        } else {
          unregister_code16(DK_SLSH);
        }  
      }  
      return false;
    case DUAL_FUNC_1:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(DK_DOT);
        } else {
          unregister_code16(DK_DOT);
        }
      } else {
        if (record->event.pressed) {
          register_code16(DK_COLN);
        } else {
          unregister_code16(DK_COLN);
        }  
      }  
      return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}
