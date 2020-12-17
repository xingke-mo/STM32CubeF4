/*********************************************************************
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                           www.segger.com                           *
**********************************************************************
*                                                                    *
* C-file generated by                                                *
*                                                                    *
*        emWin Font Converter (ST) version 5.40                      *
*        Compiled Mar 17 2017, 15:34:36                              *
*                                                                    *
*        (c) 1998 - 2017 Segger Microcontroller GmbH & Co. KG        *
*                                                                    *
**********************************************************************
*                                                                    *
* Source file: chinese40.c                                           *
* Font:        Microsoft JhengHei UI                                 *
* Height:      40                                                    *
*                                                                    *
**********************************************************************
*                                                                    *
* Initial font height:  40                                           *
* Read pattern file: C:\Users\bennacef\Desktop\chinese.txt           *
* Range disabled:       0000 - FFFF                                  *
* Read pattern file: C:\Users\bennacef\Desktop\chinese.txt           *
*                                                                    *
**********************************************************************
*/

#include "GUI.h"

#ifndef GUI_CONST_STORAGE
    #define GUI_CONST_STORAGE const
#endif

/* The following line needs to be included in any file selecting the
   font.
*/
extern GUI_CONST_STORAGE GUI_FONT GUI_Fontchinese40;

/* Start of unicode area <CJK Unified Ideographs> */
GUI_CONST_STORAGE unsigned char acGUI_Fontchinese40_6B22[108] =   /* code 6B22 */
{
    ________, ________, XX______, ________,
    ________, ________, XX______, ________,
    _XXXXXXX, XXXX___X, X_______, ________,
    _XXXXXXX, XXXX___X, X_______, ________,
    __X_____, __XX___X, XXXXXXXX, XXX_____,
    __XX____, __XX__XX, XXXXXXXX, XXX_____,
    ___XX___, __XX__XX, ________, _XX_____,
    ____X___, __X___X_, ________, _XX_____,
    ____XX__, _XX__XX_, ________, _X______,
    _____X__, _XX__X__, ___XX___, XX______,
    _____XX_, _XX_XX__, ___XX___, XX______,
    ______XX, _X__X___, ___XX___, XX______,
    ______XX, XX______, ___XX__X, X_______,
    _______X, XX______, ___XX__X, X_______,
    _______X, X_______, ___XX___, ________,
    _______X, XX______, __XXXX__, ________,
    ______XX, XX______, __XXXX__, ________,
    ______XX, _XX_____, __XX_X__, ________,
    _____XX_, _XX_____, _XX__X__, ________,
    _____X__, __XX____, _XX__XX_, ________,
    ____XX__, __XX____, XX____X_, ________,
    ___XX___, __XX___X, XX____XX, ________,
    ___X____, ___XX__X, X______X, ________,
    __X_____, ___X__XX, _______X, X_______,
    _XX_____, ____XXX_, ________, XX______,
    XX______, ___XXX__, ________, _X______,
    ________, __XX____, ________, __X_____
};

GUI_CONST_STORAGE unsigned char acGUI_Fontchinese40_8FCE[108] =   /* code 8FCE */
{
    _X______, ________, XX______, ________,
    __XX____, ______XX, X_______, ________,
    ___XX___, ___XXXX_, __XXXXXX, XX______,
    ____XX__, __XXX___, __XXXXXX, XX______,
    _____XX_, __XX____, __XX____, XX______,
    ______X_, __XX____, __XX____, XX______,
    ________, __XX____, __XX____, XX______,
    XXXXXXXX, __XX____, __XX____, XX______,
    XXXXXXXX, __XX____, __XX____, XX______,
    ______XX, __XX____, __XX____, XX______,
    _____XX_, __XX____, __XX____, XX______,
    ____XX__, __XX____, __XX____, XX______,
    ___XX___, __XX____, __XX____, XX______,
    __XX____, __XX____, __XX____, XX______,
    __XX____, __XX____, __XX____, XX______,
    _XXXXXXX, __XX____, X_XX____, XX______,
    _XXXXXXX, __XX___X, X_XX____, XX______,
    ______XX, __XX_XXX, __XX____, XX______,
    ______XX, __XXXX__, __XX_XXX, XX______,
    _____XX_, __XX____, __XX_XXX, X_______,
    _____XX_, ________, __XX____, ________,
    ____XX__, ________, __XX____, ________,
    ___XXX__, ________, __XX____, ________,
    ___XXXXX, ________, ________, ________,
    __XX__XX, XXX_____, ________, ________,
    XXX_____, XXXXXXXX, XXXXXXXX, XXX_____,
    X_______, ___XXXXX, XXXXXXXX, XXX_____
};

GUI_CONST_STORAGE GUI_CHARINFO_EXT GUI_Fontchinese40_CharInfo[2] =
{
    {  27,  27,   2,   7,  31, acGUI_Fontchinese40_6B22 } /* code 6B22 */
    , {  27,  27,   2,   6,  31, acGUI_Fontchinese40_8FCE } /* code 8FCE */
};

GUI_CONST_STORAGE GUI_FONT_PROP_EXT GUI_Fontchinese40_Prop2 =
{
    0x8FCE /* first character */
    , 0x8FCE /* last character  */
    , &GUI_Fontchinese40_CharInfo[  1] /* address of first character */
    , ( GUI_CONST_STORAGE GUI_FONT_PROP_EXT * )0 /* pointer to next GUI_FONT_PROP_EXT */
};

GUI_CONST_STORAGE GUI_FONT_PROP_EXT GUI_Fontchinese40_Prop1 =
{
    0x6B22 /* first character */
    , 0x6B22 /* last character  */
    , &GUI_Fontchinese40_CharInfo[  0] /* address of first character */
    , &GUI_Fontchinese40_Prop2 /* pointer to next GUI_FONT_PROP_EXT */
};

GUI_CONST_STORAGE GUI_FONT GUI_Fontchinese40 =
{
    GUI_FONTTYPE_PROP_EXT /* type of font    */
    , 40 /* height of font  */
    , 40 /* space of font y */
    , 1 /* magnification x */
    , 1 /* magnification y */
    , {&GUI_Fontchinese40_Prop1}
    , 32 /* Baseline */
    , 17 /* Height of lowercase characters */
    , 24 /* Height of capital characters */
};

