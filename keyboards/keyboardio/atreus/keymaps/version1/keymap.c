// Copyright (C) 2019, 2020  Keyboard.io, Inc
//
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include QMK_KEYBOARD_H

// Define layer-tap keys
enum layer_names {
    _BASE,
    _SYM,
    _NUM,
    _NAV,
    _FUN,
};
#define BSPC_SYM    LT(_SYM, KC_BSPC)
#define DEL_NUM  LT(_NUM, KC_DEL)
#define SPC_NAV  LT(_NAV, KC_SPC)
#define ENT_FUN  LT(_FUN, KC_ENT)

// Define ~home row mods
#define N_SHF LSFT_T(KC_N)
#define R_CTL LCTL_T(KC_R)
#define T_OPT LOPT_T(KC_T)
#define S_CMD LCMD_T(KC_S)
#define G_HYP HYPR_T(KC_G)

#define Y_HYP HYPR_T(KC_Y)
#define H_CMD RCMD_T(KC_H)
#define A_OPT ROPT_T(KC_A)
#define E_CTL RCTL_T(KC_E)
#define I_SHF RSFT_T(KC_I)

#define GRV_SHF LSFT_T(KC_GRV)
#define BSLS_HYP HYPR_T(KC_BSLS)

// Define navigation keys
#define PGBCK  RCMD(KC_LBRC)
#define PGFWD  RCMD(KC_RBRC)
#define REDO   LCMD(LSFT(KC_Z))
#define UNDO   LCMD(KC_Z)
#define COPY   LCMD(KC_C)
#define CUT    LCMD(KC_X)
#define PASTE  LCMD(KC_V)

#define FN_GLOBE KC_F24  // F24 emits Apple globe (fn key) in Karabiner

// Pretty no-op key
#define XXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /*
   *  B     L     D     C     V        ||        J     F     O     U     ,
   *  N⇧    R^    T⌥    S⌘    G❖       ||       ❖Y    ⌘H    ⌥A    ^E    ⇧I
   *  X     Q     M     W     Z        ||        K     P     '     ;     .
   *             esc bspc→sym del→num  ||     ent→fn ␣→nav  tab               
   */
  [_BASE] = LAYOUT( /* Gallium row-staggered https://github.com/GalileoBlues/Gallium */
    KC_B,  KC_L,  KC_D,  KC_C,   KC_V,                         KC_J,    KC_F,   KC_O,    KC_U,    KC_COMM,
    N_SHF, R_CTL, T_OPT, S_CMD,  G_HYP,                        Y_HYP,   H_CMD,  A_OPT,   E_CTL,   I_SHF,
    KC_X,  KC_Q,  KC_M,  KC_W,   KC_Z,     XXXX,         XXXX, KC_K,    KC_P,   KC_QUOT, KC_SCLN, KC_DOT,
    XXXX,  XXXX,  XXXX,  KC_ESC, BSPC_SYM, DEL_NUM,   ENT_FUN, SPC_NAV, KC_TAB, XXXX,    XXXX,    XXXX ),

  /*
   *  ~                |     ||          &   *   (    
   *  `⇧   ^   ⌥   ⌘   \❖    ||      {   $   %   ^   }
   *                         ||      [   !   @   #   ]
   *                         ||     xxx xxx  )            
   */
  [_SYM] = LAYOUT( /* Symbols */
    KC_TILD, XXXX,    XXXX,    XXXX,    KC_PIPE,                  XXXX,    KC_AMPR, KC_ASTR, KC_LPRN, XXXX,
    GRV_SHF, KC_LCTL, KC_LOPT, KC_LCMD, BSLS_HYP,                 KC_LCBR, KC_DLR,  KC_PERC, KC_CIRC, KC_RCBR,
    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,     XXXX,     XXXX, KC_LBRC, KC_EXLM, KC_AT,   KC_HASH, KC_RBRC,
    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,     XXXX,     XXXX, XXXX,    KC_RPRN, XXXX,    XXXX,    XXXX ),
  
  /*
   *                               ||       /    7    8    9    -
   *  shf ctl  opt  cmd  hyp       ||       *    4    5    6    +
   *                               ||       ,    1    2    3    =
   *                               ||      xxx   .    0
   */
  [_NUM] = LAYOUT( /* Numpad */
    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                      KC_SLSH, KC_7, KC_8, KC_9, KC_MINS,
    KC_LSFT, KC_LCTL, KC_LOPT, KC_LCMD, KC_HYPR,                   KC_ASTR, KC_4, KC_5, KC_6, KC_PLUS,
    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX, KC_COMM, KC_1, KC_2, KC_3, KC_EQL,
    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,       XXXX, KC_DOT,  KC_0, XXXX, XXXX, XXXX ),

  /*
   *        home   ↑   end   pgup       ||       redo       pgbck pgfwd
   *         ←     ↓    →    pgdn       ||       hype  cmd   opt   ctl  shf
   *  undo  cut  copy  paste            ||                                 
   *                                    ||                                 
   */  
  [_NAV] = LAYOUT( /* Navigation */
    XXXX, KC_HOME, KC_UP,   KC_END,  KC_PGUP,                 REDO,    XXXX,    PGBCK,   PGFWD,   XXXX,
    XXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                 KC_HYPR, KC_RCMD, KC_ROPT, KC_RCTL, KC_RSFT,
    UNDO, CUT,     COPY,    PASTE,   XXXX,    XXXX,     XXXX, XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
    XXXX, XXXX,    XXXX,    XXXX,    XXXX,    XXXX,     XXXX, XXXX,    XXXX,    XXXX,    XXXX,    XXXX ),

  /*
   *       F7    F8    F9   F12         ||       globefn                    
   *       F4    F5    F6   F11         ||         hype  cmd   opt  ctl  shf     
   *       F1    F2    F3   F10         ||                                     
   *                                    ||                                
   */  
  [_FUN] = LAYOUT( /* Function */
    XXXX, KC_F7, KC_F8, KC_F9, KC_F12,                 FN_GLOBE, XXXX,    XXXX,    XXXX,    XXXX,
    XXXX, KC_F4, KC_F5, KC_F6, KC_F11,                 KC_HYPR,  KC_RCMD, KC_ROPT, KC_RCTL, KC_RSFT,
    XXXX, KC_F1, KC_F2, KC_F3, KC_F10, XXXX,     XXXX, XXXX,     XXXX,    XXXX,    XXXX,    XXXX,
    XXXX, XXXX,  XXXX,  XXXX,  XXXX,   XXXX,     XXXX, XXXX,     XXXX,    XXXX,    XXXX,    XXXX ),
};
