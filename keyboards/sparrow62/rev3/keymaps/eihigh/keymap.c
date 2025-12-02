#include QMK_KEYBOARD_H

/*
キーレイアウト略記

ベース
q y p o u j k d l c w z
? i n e a , m h t s r Bs
% / ! \ . ; b f g v x `

親指 (thumb cluster)
⌥  ⇧  NAV EXT   SYM  ^  ⌘

SYM
m1 | [ ] $ + # " < > ' @
^  & { } - : * _ ( ) = Bs
m2 9 8 7 6 5 0 1 2 3 4 ~

NAV
 1⌥   1⌘  1^  1⇧          Home ↑  End
 Kana Tab Cr  Eisu        ←    ↓  →   Esc Bs
 ⌘z   ⌘x  ⌘c  ⌘v  ⌘⇧v    ⇧Tab Tab

EXT
F1 F2  F3  F4
F5 F6  F7  F8
F9 F10 F11 F12

shingataレイヤー
！？には、ちぐてこがひげ
ーのとかんっくういしなBs
x すまきるつばたで。ぶヴ

中指コンボ
ゅﾁｪごふｼｪﾃｨｳｨせよみﾌｧｳﾞｧ
ょほじれもゆへあれおえBs
ゃづぞぼむｳｫぱねぺぷﾌｨｳﾞｨ

薬指コンボ
ﾘｭぢめけｼﾞｪﾃﾞｨｳｪわどやﾌｪｳﾞｪ
ﾘｮをさおり ず びら　　そBs
ﾘｬぜざぎろ ぬ べだぴぽﾌｫｳﾞｫ

上段中指コンボ
ﾐｭﾋｭｼｭｼｮｷｭﾁｭ
ﾐｮﾋｮ　　ｷｮﾁｮ
ﾐｬﾋｬ　　ｷｬﾁｬ

上段薬指コンボ
ﾋﾟｭﾋﾞｭｼﾞｭｼﾞｮｷﾞｭﾆｭ
ﾋﾟｮﾋﾞｮ      ｷﾞｮﾆｮ
ﾋﾟｬﾋﾞｬ      ｷﾞｬﾆｬ
*/

enum layer_number {
    LAYER_BASE = 0,
    LAYER_SHINGETA = 1,
    LAYER_SYM = 2,
    LAYER_NAV = 3,
    LAYER_EXT = 4,
    LAYER_SHIFT = 5,
};

enum custom_keycodes {
    MACRO1 = SAFE_RANGE,
    MACRO2,

    // 日本語レイヤー切り替えを伴うキー
    KANA,
    EISU,
    ESCEISU,

    // まったく同じ機能を持つキーコードがあるけどそれらがコンボ判定に引っかからないように独立して定義
    JP_A,
    JP_I,
    JP_U,
    JP_E,
    JP_O,
    JP_X,
    JP_COMM,
    JP_DOT,
    JP_MINS,
    JP_QUES,
    JP_EXLM,

    // ローマ字入力のためのキーシーケンス
    JP_KA,
    JP_KI,
    JP_KU,
    JP_KE,
    JP_KO,
    JP_SA,
    JP_SI,
    JP_SU,
    JP_SE,
    JP_SO,
    JP_TA,
    JP_TI,
    JP_TU,
    JP_TE,
    JP_TO,
    JP_NA,
    JP_NI,
    JP_NU,
    JP_NE,
    JP_NO,
    JP_HA,
    JP_HI,
    JP_HU,
    JP_HE,
    JP_HO,
    JP_MA,
    JP_MI,
    JP_MU,
    JP_ME,
    JP_MO,
    JP_YA,
    JP_YU,
    JP_YO,
    JP_RA,
    JP_RI,
    JP_RU,
    JP_RE,
    JP_RO,
    JP_WA,
    JP_WO,
    JP_NN,
    JP_XTU,
    JP_XYA,
    JP_XYU,
    JP_XYO,

    JP_GA,
    JP_GI,
    JP_GU,
    JP_GE,
    JP_GO,
    JP_ZA,
    JP_ZI,
    JP_ZU,
    JP_ZE,
    JP_ZO,
    JP_DA,
    JP_DI,
    JP_DU,
    JP_DE,
    JP_DO,
    JP_BA,
    JP_BI,
    JP_BU,
    JP_BE,
    JP_BO,
    JP_PA,
    JP_PI,
    JP_PU,
    JP_PE,
    JP_PO,

    JP_KYA,
    JP_KYU,
    JP_KYO,
    JP_SYA,
    JP_SYU,
    JP_SYO,
    JP_TYA,
    JP_TYU,
    JP_TYO,
    JP_NYA,
    JP_NYU,
    JP_NYO,
    JP_HYA,
    JP_HYU,
    JP_HYO,
    JP_MYA,
    JP_MYU,
    JP_MYO,
    JP_RYA,
    JP_RYU,
    JP_RYO,

    JP_GYA,
    JP_GYU,
    JP_GYO,
    JP_ZYA,
    JP_ZYU,
    JP_ZYO,
    JP_BYA,
    JP_BYU,
    JP_BYO,
    JP_PYA,
    JP_PYU,
    JP_PYO,

    JP_WI,
    JP_WE,
    JP_WHO,
    JP_VA,
    JP_VI,
    JP_VU,
    JP_VE,
    JP_VO,
    JP_FA,
    JP_FI,
    JP_FE,
    JP_FO,
    KC_CHE,
    JP_SHE,
    JP_JE,
    JP_THI,
    JP_DHI,
};

// コンボ定義
#define MNS JP_I  // Migi Nakayubi Shift
#define HNS JP_KA // Hidari Nakayubi Shift
#define MKS JP_SI // Migi Kusuriyubi Shift
#define HKS JP_TO // Hidari Kusuriyubi Shift
#define MNJS JP_KO // Migi Nakayubi Jodan Shift
#define MKJS JP_GA // Migi Kusuriyubi Jodan Shift

// 右中指コンボ
const uint16_t PROGMEM combo_xyu[] = {MNS, JP_EXLM, COMBO_END };
const uint16_t PROGMEM combo_che[] = {MNS, JP_QUES, COMBO_END };
const uint16_t PROGMEM combo_go[]  = {MNS, JP_NI, COMBO_END };
const uint16_t PROGMEM combo_hu[]  = {MNS, JP_HA, COMBO_END };
const uint16_t PROGMEM combo_she[] = {MNS, JP_COMM, COMBO_END };
const uint16_t PROGMEM combo_thi[] = {MNS, JP_TI, COMBO_END };
const uint16_t PROGMEM combo_xyo[] = {MNS, JP_MINS, COMBO_END };
const uint16_t PROGMEM combo_ho[]  = {MNS, JP_NO, COMBO_END };
const uint16_t PROGMEM combo_zi[]  = {MNS, JP_TO, COMBO_END };
const uint16_t PROGMEM combo_re[]  = {MNS, JP_KA, COMBO_END };
const uint16_t PROGMEM combo_mo[]  = {MNS, JP_NN, COMBO_END };
const uint16_t PROGMEM combo_yu[]  = {MNS, JP_XTU, COMBO_END };
const uint16_t PROGMEM combo_xya[] = {MNS, JP_X, COMBO_END };
const uint16_t PROGMEM combo_du[]  = {MNS, JP_SU, COMBO_END };
const uint16_t PROGMEM combo_zo[]  = {MNS, JP_MA, COMBO_END };
const uint16_t PROGMEM combo_bo[]  = {MNS, JP_KI, COMBO_END };
const uint16_t PROGMEM combo_mu[]  = {MNS, JP_RU, COMBO_END };
const uint16_t PROGMEM combo_who[] = {MNS, JP_TU, COMBO_END };
// 左中指コンボ
const uint16_t PROGMEM combo_wi[]  = {HNS, JP_GU, COMBO_END };
const uint16_t PROGMEM combo_se[]  = {HNS, JP_TE, COMBO_END };
const uint16_t PROGMEM combo_yo[]  = {HNS, JP_KO, COMBO_END };
const uint16_t PROGMEM combo_mi[]  = {HNS, JP_GA, COMBO_END };
const uint16_t PROGMEM combo_fa[]  = {HNS, JP_HI, COMBO_END };
const uint16_t PROGMEM combo_va[]  = {HNS, JP_GE, COMBO_END };
const uint16_t PROGMEM combo_he[]  = {HNS, JP_KU, COMBO_END };
const uint16_t PROGMEM combo_a[]   = {HNS, JP_U, COMBO_END };
//const uint16_t PROGMEM combo_re2[] = {HNS, JP_I, COMBO_END };
const uint16_t PROGMEM combo_o[]   = {HNS, JP_SI, COMBO_END };
const uint16_t PROGMEM combo_e[]   = {HNS, JP_NA, COMBO_END };
const uint16_t PROGMEM combo_pa[]  = {HNS, JP_BA, COMBO_END };
const uint16_t PROGMEM combo_ne[]  = {HNS, JP_TA, COMBO_END };
const uint16_t PROGMEM combo_pe[]  = {HNS, JP_DE, COMBO_END };
const uint16_t PROGMEM combo_pu[]  = {HNS, JP_DOT, COMBO_END };
const uint16_t PROGMEM combo_fi[]  = {HNS, JP_BU, COMBO_END };
const uint16_t PROGMEM combo_vi[]  = {HNS, JP_VU, COMBO_END };

// 右薬指コンボ
const uint16_t PROGMEM combo_ryu[] = {MKS, JP_EXLM, COMBO_END };
const uint16_t PROGMEM combo_di[]  = {MKS, JP_QUES, COMBO_END };
const uint16_t PROGMEM combo_me[]  = {MKS, JP_NI, COMBO_END };
const uint16_t PROGMEM combo_ke[]  = {MKS, JP_HA, COMBO_END };
const uint16_t PROGMEM combo_je[]  = {MKS, JP_COMM, COMBO_END };
const uint16_t PROGMEM combo_dhi[] = {MKS, JP_TI, COMBO_END };
const uint16_t PROGMEM combo_ryo[] = {MKS, JP_MINS, COMBO_END };
const uint16_t PROGMEM combo_wo[]  = {MKS, JP_NO, COMBO_END };
const uint16_t PROGMEM combo_sa[]  = {MKS, JP_TO, COMBO_END };
// const uint16_t PROGMEM combo_o2[]  = {MKS, JP_KA, COMBO_END };
const uint16_t PROGMEM combo_ri[]  = {MKS, JP_NN, COMBO_END };
const uint16_t PROGMEM combo_zu[]  = {MKS, JP_XTU, COMBO_END };
const uint16_t PROGMEM combo_rya[] = {MKS, JP_X, COMBO_END };
const uint16_t PROGMEM combo_ze[]  = {MKS, JP_SU, COMBO_END };
const uint16_t PROGMEM combo_za[]  = {MKS, JP_MA, COMBO_END };
const uint16_t PROGMEM combo_gi[]  = {MKS, JP_KI, COMBO_END };
const uint16_t PROGMEM combo_ro[]  = {MKS, JP_RU, COMBO_END };
const uint16_t PROGMEM combo_nu[]  = {MKS, JP_TU, COMBO_END };
// 左薬指コンボ
const uint16_t PROGMEM combo_we[]  = {HKS, JP_GU, COMBO_END };
const uint16_t PROGMEM combo_wa[]  = {HKS, JP_TE, COMBO_END };
const uint16_t PROGMEM combo_do[]  = {HKS, JP_KO, COMBO_END };
const uint16_t PROGMEM combo_ya[]  = {HKS, JP_GA, COMBO_END };
const uint16_t PROGMEM combo_fe[]  = {HKS, JP_HI, COMBO_END };
const uint16_t PROGMEM combo_ve[]  = {HKS, JP_GE, COMBO_END };
const uint16_t PROGMEM combo_bi[]  = {HKS, JP_KU, COMBO_END };
const uint16_t PROGMEM combo_ra[]  = {HKS, JP_U, COMBO_END };
//
//
const uint16_t PROGMEM combo_so[]   = {HKS, JP_NA, COMBO_END };
const uint16_t PROGMEM combo_be[]  = {HKS, JP_BA, COMBO_END };
const uint16_t PROGMEM combo_da[]  = {HKS, JP_TA, COMBO_END };
const uint16_t PROGMEM combo_pi[]  = {HKS, JP_DE, COMBO_END };
const uint16_t PROGMEM combo_po[]  = {HKS, JP_DOT, COMBO_END };
const uint16_t PROGMEM combo_fo[] = {HKS, JP_BU, COMBO_END };
const uint16_t PROGMEM combo_vo[] = {HKS, JP_VU, COMBO_END };

// 右中指上段コンボ
const uint16_t PROGMEM combo_myu[] = {MNJS, JP_EXLM, COMBO_END };
const uint16_t PROGMEM combo_hyu[] = {MNJS, JP_QUES, COMBO_END };
const uint16_t PROGMEM combo_syu[] = {MNJS, JP_NI, COMBO_END };
const uint16_t PROGMEM combo_syo[] = {MNJS, JP_HA, COMBO_END };
const uint16_t PROGMEM combo_kyu[] = {MNJS, JP_COMM, COMBO_END };
const uint16_t PROGMEM combo_tyu[] = {MNJS, JP_TI, COMBO_END };
const uint16_t PROGMEM combo_myo[] = {MNJS, JP_MINS, COMBO_END };
const uint16_t PROGMEM combo_hyo[] = {MNJS, JP_NO, COMBO_END };
const uint16_t PROGMEM combo_kyo[] = {MNJS, JP_NN, COMBO_END };
const uint16_t PROGMEM combo_tyo[] = {MNJS, JP_XTU, COMBO_END };
const uint16_t PROGMEM combo_mya[]  = {MNJS, JP_X, COMBO_END };
const uint16_t PROGMEM combo_hya[] = {MNJS, JP_SU, COMBO_END };
const uint16_t PROGMEM combo_sya[] = {MNJS, JP_KI, COMBO_END };
const uint16_t PROGMEM combo_kya[] = {MNJS, JP_RU, COMBO_END };
const uint16_t PROGMEM combo_tya[] = {MNJS, JP_TU, COMBO_END };
// 右薬指上段コンボ
const uint16_t PROGMEM combo_pyu[] = {MKJS, JP_EXLM, COMBO_END };
const uint16_t PROGMEM combo_byu[] = {MKJS, JP_QUES, COMBO_END };
const uint16_t PROGMEM combo_zyu[] = {MKJS, JP_NI, COMBO_END };
const uint16_t PROGMEM combo_zyo[] = {MKJS, JP_HA, COMBO_END };
const uint16_t PROGMEM combo_gyu[] = {MKJS, JP_COMM, COMBO_END };
const uint16_t PROGMEM combo_nyu[] = {MKJS, JP_TI, COMBO_END };
const uint16_t PROGMEM combo_pyo[] = {MKJS, JP_MINS, COMBO_END };
const uint16_t PROGMEM combo_byo[] = {MKJS, JP_NO, COMBO_END };
const uint16_t PROGMEM combo_gyo[] = {MKJS, JP_NN, COMBO_END };
const uint16_t PROGMEM combo_nyo[] = {MKJS, JP_XTU, COMBO_END };
const uint16_t PROGMEM combo_pya[]  = {MKJS, JP_X, COMBO_END };
const uint16_t PROGMEM combo_bya[] = {MKJS, JP_SU, COMBO_END };
const uint16_t PROGMEM combo_zya[] = {MKJS, JP_KI, COMBO_END };
const uint16_t PROGMEM combo_gya[] = {MKJS, JP_RU, COMBO_END };
const uint16_t PROGMEM combo_nya[] = {MKJS, JP_TU, COMBO_END };

combo_t key_combos[] = {
    COMBO(combo_a, KC_A),
    // i
    // u
    COMBO(combo_e, KC_E),
    COMBO(combo_o, KC_O),
    // ka
    // ki
    // ku
    COMBO(combo_ke, JP_KE),
    // ko
    COMBO(combo_sa, JP_SA),
    // si
    // su
    COMBO(combo_se, JP_SE),
    COMBO(combo_so, JP_SO),
    // ta
    // ti
    // tu
    // te
    // to
    // na
    // ni
    COMBO(combo_nu, JP_NU),
    COMBO(combo_ne, JP_NE),
    // no
    // ha
    // hi
    COMBO(combo_hu, JP_HU),
    COMBO(combo_he, JP_HE),
    COMBO(combo_ho, JP_HO),
    // ma
    COMBO(combo_mi, JP_MI),
    COMBO(combo_mu, JP_MU),
    COMBO(combo_me, JP_ME),
    COMBO(combo_mo, JP_MO),
    COMBO(combo_ya, JP_YA),
    COMBO(combo_yu, JP_YU),
    COMBO(combo_yo, JP_YO),
    COMBO(combo_ra, JP_RA),
    COMBO(combo_ri, JP_RI),
    // ru
    COMBO(combo_re, JP_RE),
    COMBO(combo_ro, JP_RO),
    COMBO(combo_wa, JP_WA),
    COMBO(combo_wo, JP_WO),
    // nn
    // xtu
    COMBO(combo_xya, JP_XYA),
    COMBO(combo_xyu, JP_XYU),
    COMBO(combo_xyo, JP_XYO),

    // ga
    COMBO(combo_gi, JP_GI),
    // gu
    // ge
    COMBO(combo_go, JP_GO),
    COMBO(combo_za, JP_ZA),
    COMBO(combo_zi, JP_ZI),
    COMBO(combo_zu, JP_ZU),
    COMBO(combo_ze, JP_ZE),
    COMBO(combo_zo, JP_ZO),
    COMBO(combo_da, JP_DA),
    COMBO(combo_di, JP_DI),
    COMBO(combo_du, JP_DU),
    // de
    COMBO(combo_do, JP_DO),
    // ba
    COMBO(combo_bi, JP_BI),
    // bu
    COMBO(combo_be, JP_BE),
    COMBO(combo_bo, JP_BO),
    COMBO(combo_pa, JP_PA),
    COMBO(combo_pi, JP_PI),
    COMBO(combo_pu, JP_PU),
    COMBO(combo_pe, JP_PE),
    COMBO(combo_po, JP_PO),

    COMBO(combo_kya, JP_KYA),
    COMBO(combo_kyu, JP_KYU),
    COMBO(combo_kyo, JP_KYO),
    COMBO(combo_sya, JP_SYA),
    COMBO(combo_syu, JP_SYU),
    COMBO(combo_syo, JP_SYO),
    COMBO(combo_tya, JP_TYA),
    COMBO(combo_tyu, JP_TYU),
    COMBO(combo_tyo, JP_TYO),
    COMBO(combo_nya, JP_NYA),
    COMBO(combo_nyu, JP_NYU),
    COMBO(combo_nyo, JP_NYO),
    COMBO(combo_hya, JP_HYA),
    COMBO(combo_hyu, JP_HYU),
    COMBO(combo_hyo, JP_HYO),
    COMBO(combo_mya, JP_MYA),
    COMBO(combo_myu, JP_MYU),
    COMBO(combo_myo, JP_MYO),
    COMBO(combo_rya, JP_RYA),
    COMBO(combo_ryu, JP_RYU),
    COMBO(combo_ryo, JP_RYO),
    COMBO(combo_gya, JP_GYA),
    COMBO(combo_gyu, JP_GYU),
    COMBO(combo_gyo, JP_GYO),
    COMBO(combo_zya, JP_ZYA),
    COMBO(combo_zyu, JP_ZYU),
    COMBO(combo_zyo, JP_ZYO),
    COMBO(combo_bya, JP_BYA),
    COMBO(combo_byu, JP_BYU),
    COMBO(combo_byo, JP_BYO),
    COMBO(combo_pya, JP_PYA),
    COMBO(combo_pyu, JP_PYU),
    COMBO(combo_pyo, JP_PYO),

    COMBO(combo_wi, JP_WI),
    COMBO(combo_we, JP_WE),
    COMBO(combo_who, JP_WHO),
    COMBO(combo_va, JP_VA),
    COMBO(combo_vi, JP_VI),
    // vu
    COMBO(combo_ve, JP_VE),
    COMBO(combo_vo, JP_VO),
    COMBO(combo_fa, JP_FA),
    COMBO(combo_fi, JP_FI),
    COMBO(combo_fe, JP_FE),
    COMBO(combo_fo, JP_FO),
    COMBO(combo_che, KC_CHE),
    COMBO(combo_she, JP_SHE),
    COMBO(combo_je, JP_JE),
    COMBO(combo_thi, JP_THI),
    COMBO(combo_dhi, JP_DHI),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, LAYER_SYM, LAYER_NAV, LAYER_SHIFT);
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // do nothing when key is released
    if (!record->event.pressed) {
        return true;
    }
    switch (keycode) {
        case MACRO1: 
            SEND_STRING("???");
            break;
        case MACRO2:
            SEND_STRING("???");
            break;
        case KANA:
            // send Lang1 and enable Shingeta layer
            tap_code16(KC_LNG1);
            layer_on(LAYER_SHINGETA);
            break;
        case EISU:
            // send Lang2 and disable Shingeta layer
            tap_code16(KC_LNG2);
            layer_off(LAYER_SHINGETA);
            break;
        case ESCEISU:
            // send Esc and Lang2, disable Shingeta layer
            tap_code16(KC_ESC);
            tap_code16(KC_LNG2);
            layer_off(LAYER_SHINGETA);
            break;
        case JP_A: tap_code16(KC_A); break;
        case JP_I: tap_code16(KC_I); break;
        case JP_U: tap_code16(KC_U); break;
        case JP_E: tap_code16(KC_E); break;
        case JP_O: tap_code16(KC_O); break;
        case JP_X: tap_code16(KC_X); break;
        case JP_COMM: tap_code16(KC_COMM); break;
        case JP_DOT: tap_code16(KC_DOT); break;
        case JP_MINS: tap_code16(KC_MINS); break;
        case JP_QUES: tap_code16(KC_QUES); break;
        case JP_EXLM: tap_code16(KC_EXLM); break;
        case JP_KA: tap_code16(KC_K); tap_code16(KC_A); break;
        case JP_KI: tap_code16(KC_K); tap_code16(KC_I); break;
        case JP_KU: tap_code16(KC_K); tap_code16(KC_U); break;
        case JP_KE: tap_code16(KC_K); tap_code16(KC_E); break;
        case JP_KO: tap_code16(KC_K); tap_code16(KC_O); break;
        case JP_SA: tap_code16(KC_S); tap_code16(KC_A); break;
        case JP_SI: tap_code16(KC_S); tap_code16(KC_I); break;
        case JP_SU: tap_code16(KC_S); tap_code16(KC_U); break;
        case JP_SE: tap_code16(KC_S); tap_code16(KC_E); break;
        case JP_SO: tap_code16(KC_S); tap_code16(KC_O); break;
        case JP_TA: tap_code16(KC_T); tap_code16(KC_A); break;
        case JP_TI: tap_code16(KC_T); tap_code16(KC_I); break;
        case JP_TU: tap_code16(KC_T); tap_code16(KC_U); break;
        case JP_TE: tap_code16(KC_T); tap_code16(KC_E); break;
        case JP_TO: tap_code16(KC_T); tap_code16(KC_O); break;
        case JP_NA: tap_code16(KC_N); tap_code16(KC_A); break;
        case JP_NI: tap_code16(KC_N); tap_code16(KC_I); break;
        case JP_NU: tap_code16(KC_N); tap_code16(KC_U); break;
        case JP_NE: tap_code16(KC_N); tap_code16(KC_E); break;
        case JP_NO: tap_code16(KC_N); tap_code16(KC_O); break;
        case JP_HA: tap_code16(KC_H); tap_code16(KC_A); break;
        case JP_HI: tap_code16(KC_H); tap_code16(KC_I); break;
        case JP_HU: tap_code16(KC_H); tap_code16(KC_U); break;
        case JP_HE: tap_code16(KC_H); tap_code16(KC_E); break;
        case JP_HO: tap_code16(KC_H); tap_code16(KC_O); break;
        case JP_MA: tap_code16(KC_M); tap_code16(KC_A); break;
        case JP_MI: tap_code16(KC_M); tap_code16(KC_I); break;
        case JP_MU: tap_code16(KC_M); tap_code16(KC_U); break;
        case JP_ME: tap_code16(KC_M); tap_code16(KC_E); break;
        case JP_MO: tap_code16(KC_M); tap_code16(KC_O); break;
        case JP_YA: tap_code16(KC_Y); tap_code16(KC_A); break;
        case JP_YU: tap_code16(KC_Y); tap_code16(KC_U); break;
        case JP_YO: tap_code16(KC_Y); tap_code16(KC_O); break;
        case JP_RA: tap_code16(KC_R); tap_code16(KC_A); break;
        case JP_RI: tap_code16(KC_R); tap_code16(KC_I); break;
        case JP_RU: tap_code16(KC_R); tap_code16(KC_U); break;
        case JP_RE: tap_code16(KC_R); tap_code16(KC_E); break;
        case JP_RO: tap_code16(KC_R); tap_code16(KC_O); break;
        case JP_WA: tap_code16(KC_W); tap_code16(KC_A); break;
        case JP_WO: tap_code16(KC_W); tap_code16(KC_O); break;
        case JP_NN: tap_code16(KC_N); tap_code16(KC_N); break;  
        case JP_XTU: tap_code16(KC_X); tap_code16(KC_T); tap_code16(KC_U); break;
        case JP_XYA: tap_code16(KC_X); tap_code16(KC_Y); tap_code16(KC_A); break;
        case JP_XYU: tap_code16(KC_X); tap_code16(KC_Y); tap_code16(KC_U); break;
        case JP_XYO: tap_code16(KC_X); tap_code16(KC_Y); tap_code16(KC_O); break;
        case JP_GA: tap_code16(KC_G); tap_code16(KC_A); break;
        case JP_GI: tap_code16(KC_G); tap_code16(KC_I); break;
        case JP_GU: tap_code16(KC_G); tap_code16(KC_U); break;
        case JP_GE: tap_code16(KC_G); tap_code16(KC_E); break;
        case JP_GO: tap_code16(KC_G); tap_code16(KC_O); break;
        case JP_ZA: tap_code16(KC_Z); tap_code16(KC_A); break;
        case JP_ZI: tap_code16(KC_Z); tap_code16(KC_I); break;
        case JP_ZU: tap_code16(KC_Z); tap_code16(KC_U); break;
        case JP_ZE: tap_code16(KC_Z); tap_code16(KC_E); break;
        case JP_ZO: tap_code16(KC_Z); tap_code16(KC_O); break;
        case JP_DA: tap_code16(KC_D); tap_code16(KC_A); break;
        case JP_DI: tap_code16(KC_D); tap_code16(KC_I); break;
        case JP_DU: tap_code16(KC_D); tap_code16(KC_U); break;
        case JP_DE: tap_code16(KC_D); tap_code16(KC_E); break;
        case JP_DO: tap_code16(KC_D); tap_code16(KC_O); break;
        case JP_BA: tap_code16(KC_B); tap_code16(KC_A); break;
        case JP_BI: tap_code16(KC_B); tap_code16(KC_I); break;
        case JP_BU: tap_code16(KC_B); tap_code16(KC_U); break;
        case JP_BE: tap_code16(KC_B); tap_code16(KC_E); break;
        case JP_BO: tap_code16(KC_B); tap_code16(KC_O); break;
        case JP_PA: tap_code16(KC_P); tap_code16(KC_A); break;
        case JP_PI: tap_code16(KC_P); tap_code16(KC_I); break;
        case JP_PU: tap_code16(KC_P); tap_code16(KC_U); break;
        case JP_PE: tap_code16(KC_P); tap_code16(KC_E); break;
        case JP_PO: tap_code16(KC_P); tap_code16(KC_O); break;
        case JP_KYA: tap_code16(KC_K); tap_code16(KC_Y); tap_code16(KC_A); break;
        case JP_KYU: tap_code16(KC_K); tap_code16(KC_Y); tap_code16(KC_U); break;
        case JP_KYO: tap_code16(KC_K); tap_code16(KC_Y); tap_code16(KC_O); break;
        case JP_SYA: tap_code16(KC_S); tap_code16(KC_Y); tap_code16(KC_A); break;
        case JP_SYU: tap_code16(KC_S); tap_code16(KC_Y); tap_code16(KC_U); break;
        case JP_SYO: tap_code16(KC_S); tap_code16(KC_Y); tap_code16(KC_O); break;
        case JP_TYA: tap_code16(KC_T); tap_code16(KC_Y); tap_code16(KC_A); break;
        case JP_TYU: tap_code16(KC_T); tap_code16(KC_Y); tap_code16(KC_U); break;
        case JP_TYO: tap_code16(KC_T); tap_code16(KC_Y); tap_code16(KC_O); break;
        case JP_NYA: tap_code16(KC_N); tap_code16(KC_Y); tap_code16(KC_A); break;
        case JP_NYU: tap_code16(KC_N); tap_code16(KC_Y); tap_code16(KC_U); break;
        case JP_NYO: tap_code16(KC_N); tap_code16(KC_Y); tap_code16(KC_O); break;
        case JP_HYA: tap_code16(KC_H); tap_code16(KC_Y); tap_code16(KC_A); break;
        case JP_HYU: tap_code16(KC_H); tap_code16(KC_Y); tap_code16(KC_U); break;
        case JP_HYO: tap_code16(KC_H); tap_code16(KC_Y); tap_code16(KC_O); break;
        case JP_MYA: tap_code16(KC_M); tap_code16(KC_Y); tap_code16(KC_A); break;
        case JP_MYU: tap_code16(KC_M); tap_code16(KC_Y); tap_code16(KC_U); break;
        case JP_MYO: tap_code16(KC_M); tap_code16(KC_Y); tap_code16(KC_O); break;
        case JP_RYA: tap_code16(KC_R); tap_code16(KC_Y); tap_code16(KC_A); break;
        case JP_RYU: tap_code16(KC_R); tap_code16(KC_Y); tap_code16(KC_U); break;
        case JP_RYO: tap_code16(KC_R); tap_code16(KC_Y); tap_code16(KC_O); break;
        case JP_GYA: tap_code16(KC_G); tap_code16(KC_Y); tap_code16(KC_A); break;
        case JP_GYU: tap_code16(KC_G); tap_code16(KC_Y); tap_code16(KC_U); break;
        case JP_GYO: tap_code16(KC_G); tap_code16(KC_Y); tap_code16(KC_O); break;
        case JP_ZYA: tap_code16(KC_Z); tap_code16(KC_Y); tap_code16(KC_A); break;
        case JP_ZYU: tap_code16(KC_Z); tap_code16(KC_Y); tap_code16(KC_U); break;
        case JP_ZYO: tap_code16(KC_Z); tap_code16(KC_Y); tap_code16(KC_O); break;
        case JP_BYA: tap_code16(KC_B); tap_code16(KC_Y); tap_code16(KC_A); break;
        case JP_BYU: tap_code16(KC_B); tap_code16(KC_Y); tap_code16(KC_U); break;
        case JP_BYO: tap_code16(KC_B); tap_code16(KC_Y); tap_code16(KC_O); break;
        case JP_PYA: tap_code16(KC_P); tap_code16(KC_Y); tap_code16(KC_A); break;
        case JP_PYU: tap_code16(KC_P); tap_code16(KC_Y); tap_code16(KC_U); break;
        case JP_PYO: tap_code16(KC_P); tap_code16(KC_Y); tap_code16(KC_O); break;
        case JP_WI: tap_code16(KC_W); tap_code16(KC_I); break;
        case JP_WE: tap_code16(KC_W); tap_code16(KC_E); break;
        case JP_WHO: tap_code16(KC_W); tap_code16(KC_H); tap_code16(KC_O); break;
        case JP_VA: tap_code16(KC_V); tap_code16(KC_A); break;
        case JP_VI: tap_code16(KC_V); tap_code16(KC_I); break;
        case JP_VU: tap_code16(KC_V); tap_code16(KC_U); break;
        case JP_VE: tap_code16(KC_V); tap_code16(KC_E); break;
        case JP_VO: tap_code16(KC_V); tap_code16(KC_O); break;
        case JP_FA: tap_code16(KC_F); tap_code16(KC_A); break;
        case JP_FI: tap_code16(KC_F); tap_code16(KC_I); break;
        case JP_FE: tap_code16(KC_F); tap_code16(KC_E); break;
        case JP_FO: tap_code16(KC_F); tap_code16(KC_O); break;
        case KC_CHE: tap_code16(KC_C); tap_code16(KC_H); tap_code16(KC_E); break;
        case JP_SHE: tap_code16(KC_S); tap_code16(KC_H); tap_code16(KC_E); break;
        case JP_JE: tap_code16(KC_J); tap_code16(KC_E); break;
        case JP_THI: tap_code16(KC_T); tap_code16(KC_H); tap_code16(KC_I); break; 
        case JP_DHI: tap_code16(KC_D); tap_code16(KC_H); tap_code16(KC_I); break;
    }
    return true;
}

#define SYM_SPC LT(LAYER_SYM, KC_SPC)
#define NAV_SPC LT(LAYER_NAV, KC_SPC)
#define MO_EXT  MO(LAYER_EXT)
#define LCLICK  KC_MS_BTN1
#define OS_LSFT OSM(MOD_LSFT)
#define OS_LALT OSM(MOD_LALT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_LGUI OSM(MOD_LGUI)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_BASE] = LAYOUT(
    // /-------+-------+-------+-------+-------+-------\                 /-------+-------+-------+-------+-------+-------.
        ESCEISU,_______,KC_LGUI,KC_LCTL,KC_LALT,_______,                  _______,KC_RALT,KC_RCTL,KC_RGUI,_______,KC_BSPC,
    // |-------+-------+-------+-------+-------+-------+-------\ /-------+-------+-------+-------+-------+-------+-------|
        KC_Q   ,KC_Y   ,KC_P   ,KC_O   ,KC_U   ,KC_J   ,_______,  _______,KC_K   ,KC_D   ,KC_L   ,KC_C   ,KC_W   ,KC_Z   ,
    // |-------+-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------+-------|
        KC_QUES,KC_I   ,KC_N   ,KC_E   ,KC_A   ,KC_COMM,KC_SPC ,  _______,KC_M   ,KC_H   ,KC_T   ,KC_S   ,KC_R   ,KC_BSPC,
    // |-------+-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------+-------|
        KC_PERC,KC_SLSH,KC_EXLM,KC_BSLS,KC_DOT ,KC_SCLN,LCLICK ,  _______,KC_B   ,KC_F   ,KC_G   ,KC_V   ,KC_X   ,KC_GRV ,
    // \-------+-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------+-------/
                                KC_LALT,KC_LSFT,NAV_SPC,MO_EXT ,  _______,SYM_SPC,KC_LCTL,KC_LGUI
    //                         \-------+-------+-------+-------/  \------+-------+-------+-------/
    ),

    [LAYER_SHINGETA] = LAYOUT(
    // /-------+-------+-------+-------+-------+-------\                 /-------+-------+-------+-------+-------+-------.
        _______,_______,_______,_______,_______,_______,                  _______,_______,_______,_______,_______,_______,
    // |-------+-------+-------+-------+-------+-------+-------\ /-------+-------+-------+-------+-------+-------+-------|
        JP_EXLM,JP_QUES,JP_NI  ,JP_HA  ,JP_COMM,JP_TI  ,_______,  _______,JP_GU  ,JP_TE  ,JP_KO  ,JP_GA  ,JP_HI  ,JP_GE  ,
    // |-------+-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------+-------|
        JP_MINS,JP_NO  ,JP_TO  ,JP_KA  ,JP_NN  ,JP_XTU ,_______,  _______,JP_KU  ,JP_U   ,JP_I   ,JP_SI  ,JP_NA  ,KC_BSPC,
    // |-------+-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------+-------|
        JP_X   ,JP_SU  ,JP_MA  ,JP_KI  ,JP_RU  ,JP_TU  ,_______,  _______,JP_BA  ,JP_TA  ,JP_DE  ,JP_DOT ,JP_BU  ,JP_VU  ,
    // \-------+-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------+-------/
                                _______,_______,_______,_______,  _______,_______,_______,_______
    //                         \-------+-------+-------+-------/  \------+-------+-------+-------/
    ),

    [LAYER_SYM] = LAYOUT(
    // /-------+-------+-------+-------+-------+-------\                 /-------+-------+-------+-------+-------+-------.
        _______,_______,_______,_______,_______,_______,                  _______,_______,_______,_______,_______,_______,
    // |-------+-------+-------+-------+-------+-------+-------\ /-------+-------+-------+-------+-------+-------+-------|
        MACRO1 ,KC_PIPE,KC_LBRC,KC_RBRC,KC_DLR ,KC_PLUS,_______,  _______,KC_HASH,KC_DQUO,KC_LABK,KC_RABK,KC_QUOT,KC_AT  ,
    // |-------+-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------+-------|
        KC_CIRC,KC_AMPR,KC_LCBR,KC_RCBR,KC_MINS,KC_COLN,_______,  _______,KC_ASTR,KC_UNDS,KC_LPRN,KC_RPRN,KC_EQL ,_______,
    // |-------+-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------+-------|
        MACRO2 ,KC_9   ,KC_8   ,KC_7   ,KC_6   ,KC_5   ,_______,  _______,KC_0   ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_TILD,
    // \-------+-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------+-------/
                                _______,_______,_______,_______,  _______,_______,_______,_______
    //                         \-------+-------+-------+-------/ \-------+-------+-------+-------/
    ),

    [LAYER_NAV] = LAYOUT(
    // /-------+-------+-------+-------+-------+-------\                 /-------+-------+-------+-------+-------+-------.
        _______,_______,_______,_______,_______,_______,                  _______,_______,_______,_______,_______,_______,
    // |-------+-------+-------+-------+-------+-------+-------\ /-------+-------+-------+-------+-------+-------+-------|
        _______,OS_LALT,OS_LGUI,OS_LCTL,OS_LSFT,_______,_______,  _______,_______,KC_HOME,KC_UP  ,KC_END ,_______,_______,
    // |-------+-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------+-------|
        _______,KANA   ,KC_TAB ,KC_ENT ,EISU   ,_______,_______,  _______,_______,KC_LEFT,KC_DOWN,KC_RGHT,ESCEISU,_______,
    // |-------+-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------+-------|
        _______,G(KC_Z),G(KC_X),G(KC_C),G(KC_V),G(S(KC_V)),_______,  _______,_______,S(KC_TAB),KC_TAB,_______,_______,_______,
    // \-------+-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------+-------/
                                _______,_______,_______,_______,  _______,_______,_______,_______
    //                         \-------+-------+-------+-------/ \-------+-------+-------+-------/
    ),

    [LAYER_EXT] = LAYOUT(
    // /-------+-------+-------+-------+-------+-------\                 /-------+-------+-------+-------+-------+-------.
        _______,_______,_______,_______,_______,_______,                  _______,_______,_______,_______,_______,_______,
    // |-------+-------+-------+-------+-------+-------+-------\ /-------+-------+-------+-------+-------+-------+-------|
        _______,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,_______,_______,  _______,_______,_______,_______,_______,_______,_______,
    // |-------+-------+-------+-------+-------+--------+-------| |-------+-------+-------+-------+-------+-------+-------|
        _______,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8  ,_______,_______,  _______,_______,_______,_______,_______,_______,_______,
    // |-------+-------+-------+-------+-------+--------+-------| |-------+-------+-------+-------+-------+-------+-------|
        _______,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,_______,_______,  _______,_______,_______,_______,_______,_______,_______,
    // \-------+-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------+-------/
                                _______,_______,_______,_______,  _______,_______,_______,_______
    //                         \-------+-------+-------+-------/ \-------+-------+-------+-------/
    ),

    [LAYER_SHIFT] = LAYOUT(
    // /-------+-------+-------+-------+-------+-------\                 /-------+-------+-------+-------+-------+-------.
        _______,_______,_______,_______,_______,_______,                  _______,_______,_______,_______,_______,_______,
    // |-------+-------+-------+-------+-------+-------+-------\ /-------+-------+-------+-------+-------+-------+-------|
        S(KC_Q),S(KC_Y),S(KC_P),S(KC_O),S(KC_U),S(KC_J),_______,  _______,S(KC_K),S(KC_D),S(KC_L),S(KC_C),S(KC_W),S(KC_Z),
    // |-------+-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------+-------|
        _______,S(KC_I),S(KC_N),S(KC_E),S(KC_A),_______,_______,  _______,S(KC_M),S(KC_H),S(KC_T),S(KC_S),S(KC_R),_______,
    // |-------+-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------+-------|
        _______,_______,_______,_______,_______,_______,_______,  _______,S(KC_B),S(KC_F),S(KC_G),S(KC_V),S(KC_X),_______,
    // \-------+-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------+-------/
                                _______,_______,_______,_______,  _______,_______,_______,_______
    //                         \-------+-------+-------+-------/  \------+-------+-------+-------/
    ),
};
