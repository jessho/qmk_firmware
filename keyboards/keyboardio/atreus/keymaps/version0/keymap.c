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
#define R_SYM    LT(_SYM, KC_R)
#define DEL_NUM  LT(_NUM, KC_BSPC)
#define SPC_NAV  LT(_NAV, KC_SPC)
#define ENT_FUN  LT(_FUN, KC_ENT)

// Define ~home row mods
#define X_SHF LSFT_T(KC_X)
#define S_CTL RCTL_T(KC_S) // Send R-Ctrl, because L-Ctrl emits Hyper in Karabiner
#define H_OPT LOPT_T(KC_H)
#define T_CMD LCMD_T(KC_T)
#define M_HYP HYPR_T(KC_M)

#define Y_HYP HYPR_T(KC_Y)
#define C_CMD RCMD_T(KC_C)
#define A_OPT ROPT_T(KC_A)
#define E_CTL RCTL_T(KC_E)
#define COMM_SHF RSFT_T(KC_COMM)

#define OPT_SEMI LOPT_T(KC_SCLN)
#define CMD_EQL  LCMD_T(KC_EQL)
#define HYP_BSLS HYPR_T(KC_BSLS)

// Define navigation keys
#define PGBCK  RCMD(KC_LBRC)
#define PGFWD  RCMD(KC_RBRC)
#define REDO   RCMD(KC_Y)
#define UNDO   LCMD(KC_Z)
#define COPY   LCMD(KC_C)
#define CUT    LCMD(KC_X)
#define PASTE  LCMD(KC_V)

#define FN_GLOBE KC_F24  // F24 emits Apple globe (fn key) in Karabiner

// Pretty no-op key
#define XXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /*
   *  B     F     L     D     K        ||        P     W     O     U     .
   *  N     S^    H⌥    T⌘    M❖       ||       ❖Y    ⌘C    ⌥A    ^E     I
   *  X⇧    V     J     Q     Z        ||        '     G     /     ;    ⇧,
   *             esc    R→sym del→num  ||   ret→fn  ␣→nav   tab               
   */
  [_BASE] = LAYOUT( /* Nightingale https://valorance.net/night/reflection */
    KC_B,    KC_F,    KC_L,    KC_D,    KC_K,                        KC_P,    KC_W,    KC_O,    KC_U,    KC_DOT,
    KC_N,    S_CTL,   H_OPT,   T_CMD,   M_HYP,                       Y_HYP,   C_CMD,   A_OPT,   E_CTL,   KC_I,
    X_SHF,   KC_V,    KC_J,    KC_Q,    KC_Z,    XXXX,         XXXX, KC_QUOT, KC_G,    KC_SLSH, KC_SCLN, COMM_SHF,
    XXXX,    XXXX,    XXXX,    KC_ESC,  R_SYM,   DEL_NUM,   ENT_FUN, SPC_NAV, KC_TAB,  XXXX,    XXXX,    XXXX ),

  /*
   *  ~   _   :   +   |      ||      <   &   *   (   >
   *  `       ;   =   \      ||      {   $   %   ^   }
   *                         ||      [   !   @   #   ]
   *                         ||  (   )   fn  .   0   =
   */
  [_SYM] = LAYOUT( /* Symbols */
    KC_TILD, KC_UNDS, KC_COLN,  KC_PLUS, KC_PIPE,                  KC_LT,   KC_AMPR, KC_ASTR, KC_LPRN, KC_GT,
    KC_GRV,  KC_RCTL, OPT_SEMI, CMD_EQL, HYP_BSLS,                 KC_LCBR, KC_DLR,  KC_PERC, KC_CIRC, KC_RCBR,
    KC_LSFT, XXXX,    XXXX,     KC_MINS, XXXX,     XXXX,     XXXX, KC_LBRC, KC_EXLM, KC_AT,   KC_HASH, KC_RBRC,
    XXXX,    XXXX,    XXXX,     XXXX,    XXXX,     XXXX,     XXXX, KC_LPRN, KC_RPRN, XXXX,    XXXX,    XXXX ),
  
  /*
   *                               ||       /    7    8    9    -
   *      ctl  opt  cmd  hyp       ||       *    4    5    6    +
   *  shf                     boot ||       ,    1    2    3    =
   *                               ||       .    0
   */
  [_NUM] = LAYOUT( /* Numpad */
    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                      KC_SLSH, KC_7,    KC_8,    KC_9,    KC_MINS,
    XXXX,    KC_RCTL, KC_LOPT, KC_LCMD, KC_HYPR,                   KC_ASTR, KC_4,    KC_5,    KC_6,    KC_PLUS,
    KC_LSFT, XXXX,    XXXX,    XXXX,    XXXX,    QK_BOOT,    XXXX, KC_COMM, KC_1,    KC_2,    KC_3,    KC_EQL,
    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,       XXXX, KC_DOT,  KC_0,    XXXX,    XXXX,    XXXX ),

  /*
   *        home   ↑   end   pgup       ||       redo       pgbck pgfwd
   *         ←     ↓    →    pgdn       ||       hype  cmd   opt   ctl
   *  undo  cut  copy  paste            ||                              shift
   *                                    ||                                 
   */  
  [_NAV] = LAYOUT( /* Navigation */
    XXXX,    KC_HOME, KC_UP,   KC_END,  KC_PGUP,                 REDO,    XXXX,    PGBCK,   PGFWD,   XXXX,
    XXXX,    KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                 KC_HYPR, KC_RCMD, KC_ROPT, KC_RCTL, XXXX,
    UNDO,    CUT,     COPY,    PASTE,   XXXX,    XXXX,     XXXX, XXXX,    XXXX,    XXXX,    XXXX,    KC_RSFT,
    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,     XXXX, XXXX,    XXXX,    XXXX,    XXXX,    XXXX ),

  /*
   *       F7    F8    F9   F12         ||                                
   *       F4    F5    F6   F11         ||         globefn  cmd   opt   ctl     
   *       F1    F2    F3   F10         ||                                   shift
   *                              fwdel ||                                
   */  
  [_FUN] = LAYOUT( /* Function */
    XXXX,    KC_F7,   KC_F8,   KC_F9,   KC_F12,                  XXXX,     XXXX,    XXXX,    XXXX,    XXXX,
    XXXX,    KC_F4,   KC_F5,   KC_F6,   KC_F11,                  FN_GLOBE, KC_RCMD, KC_ROPT, KC_RCTL, XXXX,
    XXXX,    KC_F1,   KC_F2,   KC_F3,   KC_F10,  XXXX,     XXXX, XXXX,     XXXX,    XXXX,    XXXX,    KC_RSFT,
    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    KC_DEL,   XXXX, XXXX,     XXXX,    XXXX,    XXXX,    XXXX ),
};
