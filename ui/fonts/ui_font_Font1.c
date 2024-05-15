/*******************************************************************************
 * Size: 18 px
 * Bpp: 1
 * Opts: --bpp 1 --size 18 --font /Users/ry79/Documents/my_squareline_project/assets/微软雅黑.ttf -o /Users/ry79/Documents/my_squareline_project/assets/ui_font_Font1.c --format lvgl -r 0x20-0x7f --symbols 主界面音乐库自然之蓝牙模式叫醒服务指南 --no-compress --no-prefilter
 ******************************************************************************/

#include "../ui.h"

#ifndef UI_FONT_FONT1
#define UI_FONT_FONT1 1
#endif

#if UI_FONT_FONT1

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0xff, 0xf0, 0xf0,

    /* U+0022 "\"" */
    0xff, 0xff,

    /* U+0023 "#" */
    0xc, 0x81, 0x90, 0x22, 0x4, 0xc7, 0xfe, 0x32,
    0x6, 0x40, 0x88, 0xff, 0xc2, 0x60, 0xc8, 0x11,
    0x2, 0x20,

    /* U+0024 "$" */
    0x10, 0x10, 0x3e, 0x52, 0xd0, 0xd0, 0xd0, 0xf0,
    0x70, 0x3c, 0x1e, 0x17, 0x13, 0x13, 0x96, 0xfc,
    0x10, 0x10,

    /* U+0025 "%" */
    0x3c, 0x10, 0xdc, 0x43, 0x18, 0x86, 0x32, 0xc,
    0x6c, 0x1d, 0x90, 0x1e, 0x40, 0x0, 0x9e, 0x2,
    0x6e, 0xd, 0x8c, 0x13, 0x18, 0x46, 0x31, 0x8e,
    0xc2, 0xf, 0x0,

    /* U+0026 "&" */
    0x1e, 0x1, 0xce, 0x6, 0x18, 0x18, 0x66, 0x73,
    0x18, 0xf8, 0x63, 0xe1, 0x98, 0xc4, 0xc1, 0xb3,
    0x3, 0xcc, 0xe, 0x30, 0x38, 0x61, 0xb0, 0xf8,
    0x70,

    /* U+0027 "'" */
    0xff,

    /* U+0028 "(" */
    0x19, 0x88, 0xc6, 0x63, 0x18, 0xc6, 0x31, 0x86,
    0x31, 0x86, 0x18,

    /* U+0029 ")" */
    0xc3, 0x8, 0x63, 0xc, 0x63, 0x18, 0xc6, 0x33,
    0x18, 0x8c, 0xc0,

    /* U+002A "*" */
    0x30, 0x4d, 0x5e, 0x39, 0x24, 0x80,

    /* U+002B "+" */
    0x18, 0xc, 0x6, 0x3, 0xf, 0xf8, 0xc0, 0x60,
    0x30, 0x18, 0x0,

    /* U+002C "," */
    0x6d, 0x20,

    /* U+002D "-" */
    0xf8,

    /* U+002E "." */
    0xf0,

    /* U+002F "/" */
    0x3, 0x2, 0x6, 0x4, 0xc, 0xc, 0x8, 0x18,
    0x10, 0x30, 0x30, 0x20, 0x60, 0x40, 0xc0, 0xc0,

    /* U+0030 "0" */
    0x1e, 0x31, 0x98, 0xd8, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0xc1, 0xe0, 0xf0, 0x6c, 0x66, 0x31, 0xe0,

    /* U+0031 "1" */
    0x38, 0xf8, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18, 0xff,

    /* U+0032 "2" */
    0x3e, 0x21, 0x80, 0x60, 0x30, 0x18, 0xc, 0xc,
    0xe, 0xe, 0xe, 0xe, 0xe, 0xe, 0x7, 0xfc,

    /* U+0033 "3" */
    0x7c, 0x47, 0x3, 0x3, 0x3, 0x6, 0x38, 0x6,
    0x3, 0x3, 0x3, 0x3, 0xc6, 0xfc,

    /* U+0034 "4" */
    0x7, 0x1, 0xc0, 0xf0, 0x2c, 0x13, 0xc, 0xc2,
    0x31, 0x8c, 0xc3, 0x3f, 0xf0, 0x30, 0xc, 0x3,
    0x0, 0xc0,

    /* U+0035 "5" */
    0x7e, 0x60, 0x60, 0x60, 0x60, 0x60, 0x7c, 0x6,
    0x3, 0x3, 0x3, 0x3, 0x86, 0xfc,

    /* U+0036 "6" */
    0x1f, 0x18, 0x18, 0xc, 0xc, 0x6, 0xf3, 0x8d,
    0x83, 0xc1, 0xe0, 0xf0, 0x68, 0x36, 0x31, 0xf0,

    /* U+0037 "7" */
    0xff, 0x80, 0xc0, 0xc0, 0x60, 0x20, 0x30, 0x18,
    0x18, 0xc, 0x4, 0x6, 0x3, 0x3, 0x1, 0x80,

    /* U+0038 "8" */
    0x3c, 0x33, 0x30, 0xd8, 0x6c, 0x33, 0x30, 0xf0,
    0xfc, 0xe3, 0x60, 0xf0, 0x78, 0x36, 0x31, 0xf0,

    /* U+0039 "9" */
    0x3e, 0x31, 0xb0, 0x58, 0x3c, 0x1e, 0xd, 0x8e,
    0x7b, 0x1, 0x80, 0xc0, 0xc0, 0x60, 0x63, 0xe0,

    /* U+003A ":" */
    0xf0, 0x0, 0xf0,

    /* U+003B ";" */
    0x6c, 0x0, 0x0, 0x69, 0x60,

    /* U+003C "<" */
    0x1, 0x83, 0x87, 0xe, 0xc, 0x1, 0xc0, 0x38,
    0x7, 0x0, 0x80,

    /* U+003D "=" */
    0xff, 0x80, 0x0, 0x0, 0xf, 0xf8,

    /* U+003E ">" */
    0x0, 0x60, 0x1c, 0x3, 0x80, 0x60, 0x1c, 0x38,
    0x70, 0xe0, 0x40, 0x0,

    /* U+003F "?" */
    0x7d, 0x1c, 0x18, 0x30, 0xe1, 0x86, 0x18, 0x30,
    0x60, 0x0, 0x3, 0x6, 0x0,

    /* U+0040 "@" */
    0x7, 0xe0, 0x1c, 0x18, 0x30, 0xc, 0x60, 0x6,
    0x63, 0xe3, 0xcc, 0x23, 0xdc, 0x23, 0xd8, 0x23,
    0xd8, 0x23, 0xd8, 0x62, 0xdc, 0x66, 0x67, 0x9c,
    0x60, 0x0, 0x30, 0x0, 0x1c, 0x10, 0x7, 0xf0,

    /* U+0041 "A" */
    0x6, 0x0, 0x70, 0xf, 0x0, 0xd8, 0xd, 0x81,
    0x98, 0x18, 0xc1, 0x8c, 0x30, 0xc3, 0xfe, 0x60,
    0x66, 0x3, 0x60, 0x3c, 0x3,

    /* U+0042 "B" */
    0xfc, 0x63, 0xb0, 0xd8, 0x6c, 0x36, 0x33, 0xf1,
    0x86, 0xc1, 0xe0, 0xf0, 0x78, 0x3c, 0x37, 0xf0,

    /* U+0043 "C" */
    0xf, 0xce, 0x17, 0x1, 0x80, 0xc0, 0x30, 0xc,
    0x3, 0x0, 0xc0, 0x30, 0x6, 0x1, 0x80, 0x38,
    0x43, 0xf0,

    /* U+0044 "D" */
    0xfe, 0x18, 0x73, 0x3, 0x60, 0x6c, 0x7, 0x80,
    0xf0, 0x1e, 0x3, 0xc0, 0x78, 0xf, 0x3, 0x60,
    0x4c, 0x31, 0xfc, 0x0,

    /* U+0045 "E" */
    0xfe, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xfe,
    0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xff,

    /* U+0046 "F" */
    0xff, 0x83, 0x6, 0xc, 0x18, 0x30, 0x7f, 0xc1,
    0x83, 0x6, 0xc, 0x18, 0x0,

    /* U+0047 "G" */
    0xf, 0xe3, 0xc, 0xc0, 0x30, 0xc, 0x1, 0x80,
    0x30, 0x6, 0x1f, 0xc0, 0x78, 0xd, 0x81, 0xb0,
    0x33, 0x6, 0x1f, 0x80,

    /* U+0048 "H" */
    0xc0, 0x78, 0xf, 0x1, 0xe0, 0x3c, 0x7, 0x80,
    0xf0, 0x1f, 0xff, 0xc0, 0x78, 0xf, 0x1, 0xe0,
    0x3c, 0x7, 0x80, 0xc0,

    /* U+0049 "I" */
    0xf6, 0x66, 0x66, 0x66, 0x66, 0x66, 0x6f,

    /* U+004A "J" */
    0xc, 0x30, 0xc3, 0xc, 0x30, 0xc3, 0xc, 0x30,
    0xc3, 0x1b, 0xc0,

    /* U+004B "K" */
    0xc1, 0xb0, 0xcc, 0x63, 0x38, 0xcc, 0x36, 0xf,
    0x3, 0xc0, 0xd8, 0x33, 0xc, 0x63, 0x1c, 0xc3,
    0xb0, 0x60,

    /* U+004C "L" */
    0xc1, 0x83, 0x6, 0xc, 0x18, 0x30, 0x60, 0xc1,
    0x83, 0x6, 0xc, 0x1f, 0xc0,

    /* U+004D "M" */
    0xe0, 0x1f, 0x80, 0x7f, 0x1, 0xfc, 0xf, 0xd0,
    0x2f, 0x61, 0xbc, 0x86, 0xf3, 0x13, 0xcc, 0xcf,
    0x12, 0x3c, 0x78, 0xf0, 0xe3, 0xc3, 0xf, 0xc,
    0x30,

    /* U+004E "N" */
    0xe0, 0x7c, 0xf, 0xc1, 0xe8, 0x3d, 0x87, 0x98,
    0xf3, 0x1e, 0x33, 0xc2, 0x78, 0x6f, 0x5, 0xe0,
    0xfc, 0xf, 0x81, 0xc0,

    /* U+004F "O" */
    0xf, 0x81, 0xc3, 0x18, 0xc, 0xc0, 0x6c, 0x1,
    0xe0, 0xf, 0x0, 0x78, 0x3, 0xc0, 0x1e, 0x0,
    0xd8, 0xc, 0xc0, 0x63, 0x86, 0x7, 0xc0,

    /* U+0050 "P" */
    0xfe, 0x61, 0xb0, 0x78, 0x3c, 0x1e, 0xf, 0x5,
    0x86, 0xfc, 0x60, 0x30, 0x18, 0xc, 0x6, 0x0,

    /* U+0051 "Q" */
    0xf, 0x80, 0xe1, 0x86, 0x3, 0x18, 0xc, 0xc0,
    0x1b, 0x0, 0x6c, 0x1, 0xb0, 0x6, 0xc0, 0x1b,
    0x0, 0x66, 0x3, 0x18, 0xc, 0x38, 0x60, 0x3e,
    0x0, 0x18, 0x0, 0x30, 0x0, 0x7c,

    /* U+0052 "R" */
    0xfc, 0x31, 0x8c, 0x33, 0xc, 0xc3, 0x30, 0xcc,
    0x63, 0xe0, 0xcc, 0x31, 0x8c, 0x23, 0xc, 0xc1,
    0xb0, 0x60,

    /* U+0053 "S" */
    0x3e, 0x60, 0xc0, 0xc0, 0xe0, 0xf0, 0x7c, 0x3e,
    0xf, 0x7, 0x3, 0x3, 0x86, 0xfc,

    /* U+0054 "T" */
    0xff, 0xc3, 0x0, 0xc0, 0x30, 0xc, 0x3, 0x0,
    0xc0, 0x30, 0xc, 0x3, 0x0, 0xc0, 0x30, 0xc,
    0x3, 0x0,

    /* U+0055 "U" */
    0xc0, 0xf0, 0x3c, 0xf, 0x3, 0xc0, 0xf0, 0x3c,
    0xf, 0x3, 0xc0, 0xf0, 0x3c, 0xd, 0x82, 0x61,
    0x8f, 0x80,

    /* U+0056 "V" */
    0xc0, 0x36, 0x3, 0x60, 0x66, 0x6, 0x30, 0x43,
    0xc, 0x30, 0xc1, 0x88, 0x19, 0x81, 0x98, 0xd,
    0x0, 0xf0, 0x7, 0x0, 0x60,

    /* U+0057 "W" */
    0xc0, 0xc0, 0xd0, 0x30, 0x26, 0xe, 0x19, 0x87,
    0x86, 0x61, 0xe1, 0x88, 0x48, 0x43, 0x33, 0x30,
    0xcc, 0xcc, 0x33, 0x33, 0x6, 0x84, 0x81, 0xe1,
    0xe0, 0x78, 0x78, 0xc, 0xc, 0x3, 0x3, 0x0,

    /* U+0058 "X" */
    0x60, 0x6e, 0x18, 0xc3, 0xc, 0xc1, 0x98, 0x1e,
    0x3, 0x80, 0x70, 0xf, 0x3, 0x30, 0xc6, 0x18,
    0x66, 0xc, 0xc0, 0xc0,

    /* U+0059 "Y" */
    0xc0, 0xf0, 0x36, 0x19, 0x86, 0x33, 0xc, 0xc1,
    0xe0, 0x78, 0xc, 0x3, 0x0, 0xc0, 0x30, 0xc,
    0x3, 0x0,

    /* U+005A "Z" */
    0xff, 0xc0, 0x60, 0x18, 0xc, 0x6, 0x1, 0x80,
    0xc0, 0x30, 0x18, 0xc, 0x3, 0x1, 0x80, 0x40,
    0x3f, 0xf0,

    /* U+005B "[" */
    0xfc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcf,

    /* U+005C "\\" */
    0xc0, 0xc0, 0x40, 0x60, 0x20, 0x30, 0x30, 0x10,
    0x18, 0x8, 0xc, 0xc, 0x4, 0x6, 0x2, 0x3,

    /* U+005D "]" */
    0xf3, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x3f,

    /* U+005E "^" */
    0x8, 0xe, 0x5, 0x6, 0xc2, 0x23, 0x19, 0x5,
    0x83,

    /* U+005F "_" */
    0xff,

    /* U+0060 "`" */
    0xc6, 0x20,

    /* U+0061 "a" */
    0x7e, 0x47, 0x3, 0x3, 0x7f, 0xe3, 0xc3, 0xc3,
    0xc7, 0x7b,

    /* U+0062 "b" */
    0xc0, 0x60, 0x30, 0x18, 0xd, 0xe7, 0x1b, 0x7,
    0x83, 0xc1, 0xe0, 0xf0, 0x78, 0x6e, 0x36, 0xf0,

    /* U+0063 "c" */
    0x1f, 0x71, 0x60, 0xc0, 0xc0, 0xc0, 0xc0, 0xe0,
    0x61, 0x3f,

    /* U+0064 "d" */
    0x1, 0x80, 0xc0, 0x60, 0x33, 0xdb, 0x1f, 0x7,
    0x83, 0xc1, 0xe0, 0xf0, 0x78, 0x36, 0x39, 0xec,

    /* U+0065 "e" */
    0x1e, 0x31, 0x90, 0x78, 0x3f, 0xfe, 0x3, 0x1,
    0xc0, 0x61, 0x1f, 0x80,

    /* U+0066 "f" */
    0x3d, 0x86, 0x18, 0xfd, 0x86, 0x18, 0x61, 0x86,
    0x18, 0x61, 0x80,

    /* U+0067 "g" */
    0x3d, 0xb1, 0xf0, 0x78, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0x63, 0x9e, 0xc0, 0x60, 0x24, 0x33, 0xe0,

    /* U+0068 "h" */
    0xc0, 0xc0, 0xc0, 0xc0, 0xde, 0xe7, 0xc3, 0xc3,
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,

    /* U+0069 "i" */
    0xf0, 0xff, 0xff, 0xf0,

    /* U+006A "j" */
    0x18, 0xc0, 0x1, 0x8c, 0x63, 0x18, 0xc6, 0x31,
    0x8c, 0x63, 0x37, 0x0,

    /* U+006B "k" */
    0xc0, 0x60, 0x30, 0x18, 0xc, 0x36, 0x33, 0x31,
    0xb0, 0xf0, 0x78, 0x36, 0x19, 0x8c, 0x66, 0x18,

    /* U+006C "l" */
    0xff, 0xff, 0xff, 0xf0,

    /* U+006D "m" */
    0xde, 0x7b, 0x9e, 0x7c, 0x30, 0xf0, 0xc3, 0xc3,
    0xf, 0xc, 0x3c, 0x30, 0xf0, 0xc3, 0xc3, 0xf,
    0xc, 0x30,

    /* U+006E "n" */
    0xde, 0xe7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3,

    /* U+006F "o" */
    0x1f, 0x18, 0x66, 0x1f, 0x3, 0xc0, 0xf0, 0x3c,
    0xd, 0x82, 0x61, 0x8f, 0x80,

    /* U+0070 "p" */
    0xde, 0x71, 0xb0, 0x78, 0x3c, 0x1e, 0xf, 0x7,
    0x86, 0xe3, 0x6f, 0x30, 0x18, 0xc, 0x6, 0x0,

    /* U+0071 "q" */
    0x3d, 0xb1, 0xf8, 0x78, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0x63, 0x9e, 0xc0, 0x60, 0x30, 0x18, 0xc,

    /* U+0072 "r" */
    0xdf, 0x31, 0x8c, 0x63, 0x18, 0xc6, 0x0,

    /* U+0073 "s" */
    0x3d, 0x83, 0x7, 0xf, 0x87, 0x83, 0x83, 0x87,
    0xf0,

    /* U+0074 "t" */
    0x10, 0xc3, 0x3f, 0x30, 0xc3, 0xc, 0x30, 0xc3,
    0xc, 0x1c,

    /* U+0075 "u" */
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xe7, 0x7b,

    /* U+0076 "v" */
    0xc1, 0xb0, 0xd8, 0x4c, 0x63, 0x31, 0x90, 0xd8,
    0x2c, 0x1c, 0x6, 0x0,

    /* U+0077 "w" */
    0xc3, 0xd, 0xc, 0x36, 0x38, 0x99, 0xa6, 0x26,
    0x98, 0x93, 0x43, 0x4d, 0xf, 0x1c, 0x18, 0x70,
    0x61, 0x80,

    /* U+0078 "x" */
    0x61, 0xb1, 0x8c, 0x82, 0xc1, 0xc0, 0xe0, 0x58,
    0x6c, 0x63, 0x30, 0xc0,

    /* U+0079 "y" */
    0xc1, 0xe0, 0x90, 0xcc, 0x66, 0x21, 0x30, 0xd0,
    0x28, 0x1c, 0xc, 0x6, 0x2, 0x3, 0x7, 0x0,

    /* U+007A "z" */
    0xff, 0x6, 0xe, 0xc, 0x18, 0x10, 0x30, 0x60,
    0x40, 0xff,

    /* U+007B "{" */
    0x3b, 0x18, 0xc6, 0x31, 0x8c, 0x83, 0x18, 0xc6,
    0x31, 0x87,

    /* U+007C "|" */
    0xff, 0xff, 0xff, 0xff, 0xff,

    /* U+007D "}" */
    0xe1, 0x8c, 0x63, 0x18, 0xc6, 0x9, 0x8c, 0x63,
    0x18, 0xdc,

    /* U+007E "~" */
    0x70, 0xf3, 0x3c, 0x38,

    /* U+007F "" */
    0x0,

    /* U+4E3B "主" */
    0x1, 0x80, 0x0, 0x40, 0x0, 0x20, 0xf, 0xff,
    0xe0, 0x8, 0x0, 0x4, 0x0, 0x2, 0x0, 0x1,
    0x0, 0x0, 0x80, 0x3f, 0xff, 0x80, 0x20, 0x0,
    0x10, 0x0, 0x8, 0x0, 0x4, 0x0, 0x2, 0x1,
    0xff, 0xff,

    /* U+4E4B "之" */
    0x1, 0x80, 0x0, 0xc0, 0x0, 0x20, 0xf, 0xff,
    0xc0, 0x0, 0xe0, 0x0, 0xc0, 0x0, 0xc0, 0x0,
    0xc0, 0x0, 0xc0, 0x1, 0xc0, 0x1, 0x80, 0x3,
    0x80, 0x7, 0x80, 0x6, 0x60, 0x2, 0xf, 0xfe,

    /* U+4E50 "乐" */
    0x0, 0xc, 0x1f, 0xff, 0x8, 0x0, 0x4, 0x10,
    0x2, 0x8, 0x1, 0x4, 0x1, 0x82, 0x0, 0xff,
    0xfe, 0x0, 0x80, 0x4, 0x44, 0x6, 0x22, 0x2,
    0x11, 0x83, 0x8, 0x63, 0x4, 0x1b, 0x2, 0x6,
    0xe, 0x0,

    /* U+52A1 "务" */
    0x4, 0x0, 0x0, 0x80, 0x0, 0x3f, 0xfc, 0xe,
    0x3, 0x83, 0x60, 0xc0, 0xc7, 0x70, 0x0, 0x38,
    0x0, 0x7d, 0xe0, 0x79, 0x83, 0xc0, 0x20, 0x0,
    0xff, 0xfc, 0x0, 0x81, 0x80, 0x30, 0x30, 0xc,
    0x6, 0x3, 0x0, 0xc0, 0xc0, 0x38, 0x70, 0x7e,
    0x0, 0x0, 0x0,

    /* U+5357 "南" */
    0x0, 0xc0, 0x0, 0x60, 0x3f, 0xff, 0xe0, 0x18,
    0x0, 0xc, 0x3, 0xff, 0xfd, 0x80, 0x46, 0xc4,
    0x63, 0x62, 0x21, 0xb7, 0xfe, 0xd8, 0x30, 0x6c,
    0x18, 0x36, 0xc, 0x1b, 0xff, 0xed, 0x83, 0x6,
    0xc1, 0x82, 0x60, 0xdf, 0x0,

    /* U+53EB "叫" */
    0x0, 0x4, 0x0, 0x1f, 0x88, 0x62, 0x21, 0x88,
    0x86, 0x22, 0x18, 0x88, 0x62, 0x21, 0x88, 0x86,
    0x22, 0x18, 0x88, 0x62, 0x3f, 0xf9, 0xe6, 0x20,
    0x10, 0x0, 0x40, 0x1, 0x0, 0x4,

    /* U+5E93 "库" */
    0x0, 0xc0, 0x0, 0x30, 0xf, 0xff, 0xe4, 0x0,
    0x2, 0x8, 0x1, 0xc, 0x0, 0xbf, 0xfc, 0x46,
    0x40, 0x22, 0x20, 0x13, 0x10, 0x9, 0xff, 0xc4,
    0x4, 0x2, 0x2, 0x2, 0xff, 0xfd, 0x0, 0x81,
    0x80, 0x40, 0x80, 0x20, 0x0,

    /* U+5F0F "式" */
    0x0, 0x24, 0x0, 0x11, 0x0, 0x8, 0x1f, 0xff,
    0xf0, 0x3, 0x0, 0x1, 0x80, 0x0, 0xc0, 0xff,
    0x60, 0xc, 0x30, 0x6, 0x8, 0x3, 0x4, 0x1,
    0x82, 0x10, 0xfd, 0x8f, 0xfc, 0x4f, 0x0, 0x36,
    0x0, 0xe,

    /* U+6307 "指" */
    0x11, 0x0, 0x8, 0x80, 0x84, 0x47, 0xc2, 0x3e,
    0xf, 0xd0, 0x8, 0x88, 0xc, 0x43, 0xfc, 0x20,
    0x0, 0x14, 0x0, 0x3e, 0xff, 0xbc, 0x40, 0x42,
    0x20, 0x21, 0x1f, 0xf0, 0x88, 0x8, 0x44, 0x4,
    0x63, 0xfe, 0xe1, 0x1, 0x0,

    /* U+670D "服" */
    0x7d, 0xff, 0x22, 0xc0, 0x91, 0x60, 0x48, 0xb3,
    0xe7, 0xd9, 0xe2, 0x2c, 0x1, 0x17, 0xfc, 0x8b,
    0x42, 0x45, 0xa1, 0x3e, 0xd9, 0x11, 0x64, 0x88,
    0xb3, 0xc4, 0x58, 0xc2, 0x2c, 0xf2, 0x16, 0xcd,
    0x7b, 0x83,

    /* U+6A21 "模" */
    0x30, 0x44, 0x18, 0x22, 0xc, 0xff, 0xe6, 0x8,
    0x8f, 0xc4, 0x41, 0x8f, 0xf8, 0xc4, 0x4, 0xf3,
    0xfe, 0x7d, 0x1, 0x3a, 0x80, 0xac, 0x7f, 0xd6,
    0x2, 0x3, 0x7f, 0xf9, 0x81, 0x40, 0xc1, 0xb0,
    0x67, 0x7, 0x36, 0x1, 0x80,

    /* U+7136 "然" */
    0x8, 0x8, 0x6, 0x2, 0x61, 0xf8, 0x88, 0xc6,
    0x20, 0x29, 0xff, 0xd9, 0xc3, 0xd, 0x31, 0xc0,
    0x78, 0x58, 0xe, 0x32, 0x3, 0x18, 0xc3, 0x8c,
    0x1d, 0x86, 0x3, 0x40, 0x1, 0xc, 0x8c, 0x62,
    0x31, 0x9, 0x84, 0x63, 0x40, 0x0, 0x0,

    /* U+7259 "牙" */
    0xff, 0xff, 0x0, 0x30, 0x30, 0x30, 0x30, 0x30,
    0x20, 0x30, 0x60, 0x30, 0x7f, 0xff, 0x0, 0xb0,
    0x1, 0xb0, 0x3, 0x30, 0x6, 0x30, 0xc, 0x30,
    0x38, 0x30, 0x70, 0x30, 0xc0, 0x30, 0x83, 0xe0,

    /* U+754C "界" */
    0x3f, 0xfe, 0x10, 0x41, 0x8, 0x20, 0x87, 0xff,
    0xc2, 0x8, 0x21, 0x4, 0x10, 0x82, 0x8, 0x7f,
    0xfc, 0x3, 0x60, 0x6, 0xc, 0xd, 0x7, 0xcc,
    0x82, 0x20, 0x41, 0x0, 0x40, 0x80, 0x60, 0x40,
    0x40, 0x20,

    /* U+81EA "自" */
    0x4, 0x0, 0x60, 0x3f, 0xff, 0x0, 0x18, 0x0,
    0xc0, 0x7, 0xff, 0xf0, 0x1, 0x80, 0xc, 0x0,
    0x7f, 0xff, 0x0, 0x18, 0x0, 0xc0, 0x7, 0xff,
    0xf0, 0x1,

    /* U+84DD "蓝" */
    0x4, 0x30, 0x7f, 0xff, 0xc1, 0xc, 0x0, 0x8,
    0x2, 0x66, 0x1, 0x33, 0xf8, 0x9b, 0x40, 0x4d,
    0x30, 0x27, 0x8e, 0x0, 0x0, 0xf, 0xff, 0x84,
    0x44, 0xc2, 0x22, 0x61, 0x11, 0x30, 0x88, 0x99,
    0xff, 0xff,

    /* U+9192 "醒" */
    0xff, 0x7f, 0x85, 0x10, 0x21, 0x47, 0xfb, 0xfd,
    0x2, 0xff, 0x40, 0xb5, 0x5f, 0xef, 0x50, 0x3,
    0x95, 0x30, 0xe7, 0x7f, 0xb0, 0x73, 0xf, 0xf0,
    0xc3, 0x5, 0xfe, 0xc1, 0xc, 0x30, 0x43, 0xf,
    0xf0, 0xc3, 0xff, 0xff,

    /* U+9762 "面" */
    0xff, 0xff, 0x80, 0xc0, 0x0, 0x40, 0x0, 0x20,
    0x7, 0xff, 0xf2, 0x20, 0x89, 0x10, 0x44, 0x8f,
    0xe2, 0x44, 0x11, 0x22, 0x8, 0x91, 0x4, 0x48,
    0xfe, 0x24, 0x41, 0x12, 0x20, 0x89, 0xff, 0xfc,
    0x80, 0x2,

    /* U+97F3 "音" */
    0x1, 0x80, 0x0, 0x60, 0x1f, 0xff, 0xc0, 0x0,
    0x0, 0xc1, 0x80, 0x20, 0x83, 0xff, 0xfe, 0x0,
    0x0, 0x0, 0x0, 0x1f, 0xff, 0x8, 0x1, 0x84,
    0x0, 0xc3, 0xff, 0xe1, 0x0, 0x30, 0x80, 0x18,
    0x7f, 0xfc, 0x20, 0x6, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 85, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 90, .box_w = 2, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 5, .adv_w = 125, .box_w = 4, .box_h = 4, .ofs_x = 2, .ofs_y = 10},
    {.bitmap_index = 7, .adv_w = 184, .box_w = 11, .box_h = 13, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 25, .adv_w = 169, .box_w = 8, .box_h = 18, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 43, .adv_w = 256, .box_w = 15, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 70, .adv_w = 251, .box_w = 14, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 95, .adv_w = 74, .box_w = 2, .box_h = 4, .ofs_x = 2, .ofs_y = 10},
    {.bitmap_index = 96, .adv_w = 96, .box_w = 5, .box_h = 17, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 107, .adv_w = 96, .box_w = 5, .box_h = 17, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 118, .adv_w = 131, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 124, .adv_w = 214, .box_w = 9, .box_h = 9, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 135, .adv_w = 69, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 137, .adv_w = 125, .box_w = 5, .box_h = 1, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 138, .adv_w = 69, .box_w = 2, .box_h = 2, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 139, .adv_w = 123, .box_w = 8, .box_h = 16, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 155, .adv_w = 169, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 171, .adv_w = 169, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 184, .adv_w = 169, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 200, .adv_w = 169, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 214, .adv_w = 169, .box_w = 10, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 232, .adv_w = 169, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 246, .adv_w = 169, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 262, .adv_w = 169, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 278, .adv_w = 169, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 294, .adv_w = 169, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 310, .adv_w = 69, .box_w = 2, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 313, .adv_w = 69, .box_w = 3, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 318, .adv_w = 214, .box_w = 9, .box_h = 9, .ofs_x = 3, .ofs_y = 1},
    {.bitmap_index = 329, .adv_w = 214, .box_w = 9, .box_h = 5, .ofs_x = 2, .ofs_y = 3},
    {.bitmap_index = 335, .adv_w = 214, .box_w = 9, .box_h = 10, .ofs_x = 3, .ofs_y = 1},
    {.bitmap_index = 347, .adv_w = 139, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 360, .adv_w = 297, .box_w = 16, .box_h = 16, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 392, .adv_w = 203, .box_w = 12, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 413, .adv_w = 181, .box_w = 9, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 429, .adv_w = 193, .box_w = 10, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 447, .adv_w = 219, .box_w = 11, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 467, .adv_w = 158, .box_w = 8, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 481, .adv_w = 153, .box_w = 7, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 494, .adv_w = 214, .box_w = 11, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 514, .adv_w = 223, .box_w = 11, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 534, .adv_w = 85, .box_w = 4, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 541, .adv_w = 114, .box_w = 6, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 552, .adv_w = 183, .box_w = 10, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 570, .adv_w = 148, .box_w = 7, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 583, .adv_w = 281, .box_w = 14, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 608, .adv_w = 234, .box_w = 11, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 628, .adv_w = 235, .box_w = 13, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 651, .adv_w = 176, .box_w = 9, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 667, .adv_w = 235, .box_w = 14, .box_h = 17, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 697, .adv_w = 188, .box_w = 10, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 715, .adv_w = 166, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 729, .adv_w = 165, .box_w = 10, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 747, .adv_w = 215, .box_w = 10, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 765, .adv_w = 195, .box_w = 12, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 786, .adv_w = 293, .box_w = 18, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 818, .adv_w = 186, .box_w = 11, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 838, .adv_w = 174, .box_w = 10, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 856, .adv_w = 179, .box_w = 10, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 874, .adv_w = 96, .box_w = 4, .box_h = 16, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 882, .adv_w = 120, .box_w = 8, .box_h = 16, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 898, .adv_w = 96, .box_w = 4, .box_h = 16, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 906, .adv_w = 214, .box_w = 9, .box_h = 8, .ofs_x = 2, .ofs_y = 6},
    {.bitmap_index = 915, .adv_w = 129, .box_w = 8, .box_h = 1, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 916, .adv_w = 85, .box_w = 4, .box_h = 3, .ofs_x = 1, .ofs_y = 12},
    {.bitmap_index = 918, .adv_w = 159, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 928, .adv_w = 184, .box_w = 9, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 944, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 954, .adv_w = 184, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 970, .adv_w = 163, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 982, .adv_w = 100, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 993, .adv_w = 184, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1009, .adv_w = 177, .box_w = 8, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1023, .adv_w = 77, .box_w = 2, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1027, .adv_w = 77, .box_w = 5, .box_h = 18, .ofs_x = -2, .ofs_y = -4},
    {.bitmap_index = 1039, .adv_w = 157, .box_w = 9, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1055, .adv_w = 77, .box_w = 2, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1059, .adv_w = 270, .box_w = 14, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1077, .adv_w = 177, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1087, .adv_w = 183, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1100, .adv_w = 184, .box_w = 9, .box_h = 14, .ofs_x = 2, .ofs_y = -4},
    {.bitmap_index = 1116, .adv_w = 184, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1132, .adv_w = 110, .box_w = 5, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1139, .adv_w = 133, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1148, .adv_w = 107, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1158, .adv_w = 177, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1168, .adv_w = 151, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1180, .adv_w = 227, .box_w = 14, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1198, .adv_w = 146, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1210, .adv_w = 152, .box_w = 9, .box_h = 14, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 1226, .adv_w = 142, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1236, .adv_w = 96, .box_w = 5, .box_h = 16, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1246, .adv_w = 77, .box_w = 2, .box_h = 20, .ofs_x = 2, .ofs_y = -4},
    {.bitmap_index = 1251, .adv_w = 96, .box_w = 5, .box_h = 16, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1261, .adv_w = 214, .box_w = 10, .box_h = 3, .ofs_x = 2, .ofs_y = 4},
    {.bitmap_index = 1265, .adv_w = 85, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1266, .adv_w = 288, .box_w = 17, .box_h = 16, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1300, .adv_w = 288, .box_w = 17, .box_h = 15, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1332, .adv_w = 288, .box_w = 17, .box_h = 16, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1366, .adv_w = 288, .box_w = 19, .box_h = 18, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1409, .adv_w = 288, .box_w = 17, .box_h = 17, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1446, .adv_w = 288, .box_w = 14, .box_h = 17, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 1476, .adv_w = 288, .box_w = 17, .box_h = 17, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1513, .adv_w = 288, .box_w = 17, .box_h = 16, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1547, .adv_w = 288, .box_w = 17, .box_h = 17, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1584, .adv_w = 288, .box_w = 17, .box_h = 16, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1618, .adv_w = 288, .box_w = 17, .box_h = 17, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1655, .adv_w = 288, .box_w = 18, .box_h = 17, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1694, .adv_w = 288, .box_w = 16, .box_h = 16, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1726, .adv_w = 288, .box_w = 17, .box_h = 16, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1760, .adv_w = 288, .box_w = 13, .box_h = 16, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 1786, .adv_w = 288, .box_w = 17, .box_h = 16, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1820, .adv_w = 288, .box_w = 18, .box_h = 16, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1856, .adv_w = 288, .box_w = 17, .box_h = 16, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1890, .adv_w = 288, .box_w = 17, .box_h = 17, .ofs_x = 0, .ofs_y = -2}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_1[] = {
    0x0, 0x10, 0x15, 0x466, 0x51c, 0x5b0, 0x1058, 0x10d4,
    0x14cc, 0x18d2, 0x1be6, 0x22fb, 0x241e, 0x2711, 0x33af, 0x36a2,
    0x4357, 0x4927, 0x49b8
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 96, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 20027, .range_length = 18873, .glyph_id_start = 97,
        .unicode_list = unicode_list_1, .glyph_id_ofs_list = NULL, .list_length = 19, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Pair left and right glyphs for kerning*/
static const uint8_t kern_pair_glyph_ids[] =
{
    3, 83,
    3, 84,
    8, 83,
    8, 84,
    9, 75,
    11, 34,
    11, 43,
    11, 68,
    11, 69,
    11, 70,
    11, 72,
    11, 80,
    11, 82,
    34, 11,
    34, 13,
    34, 28,
    34, 36,
    34, 40,
    34, 43,
    34, 48,
    34, 53,
    34, 54,
    34, 55,
    34, 56,
    34, 58,
    34, 59,
    34, 85,
    34, 87,
    34, 88,
    34, 90,
    35, 53,
    35, 58,
    36, 32,
    36, 36,
    36, 40,
    36, 48,
    36, 50,
    37, 13,
    37, 15,
    37, 34,
    37, 53,
    37, 57,
    37, 59,
    38, 34,
    38, 43,
    38, 53,
    38, 56,
    38, 57,
    39, 13,
    39, 15,
    39, 34,
    39, 43,
    39, 52,
    39, 53,
    39, 66,
    39, 71,
    40, 53,
    40, 55,
    40, 90,
    43, 13,
    43, 15,
    43, 34,
    43, 43,
    43, 66,
    44, 13,
    44, 28,
    44, 36,
    44, 40,
    44, 43,
    44, 48,
    44, 50,
    44, 57,
    44, 59,
    44, 68,
    44, 69,
    44, 70,
    44, 72,
    44, 80,
    44, 82,
    44, 85,
    44, 87,
    44, 88,
    44, 90,
    45, 11,
    45, 32,
    45, 34,
    45, 36,
    45, 40,
    45, 43,
    45, 48,
    45, 50,
    45, 53,
    45, 54,
    45, 55,
    45, 56,
    45, 58,
    45, 59,
    45, 85,
    45, 87,
    45, 88,
    45, 90,
    48, 13,
    48, 15,
    48, 34,
    48, 43,
    48, 53,
    48, 57,
    48, 58,
    48, 59,
    49, 13,
    49, 15,
    49, 34,
    49, 40,
    49, 43,
    49, 56,
    49, 57,
    49, 66,
    49, 68,
    49, 69,
    49, 70,
    49, 72,
    49, 80,
    49, 82,
    50, 13,
    50, 15,
    50, 34,
    50, 53,
    50, 57,
    50, 58,
    50, 59,
    51, 28,
    51, 36,
    51, 40,
    51, 43,
    51, 48,
    51, 50,
    51, 53,
    51, 58,
    51, 68,
    51, 69,
    51, 70,
    51, 72,
    51, 80,
    51, 82,
    52, 85,
    52, 87,
    52, 88,
    52, 90,
    53, 13,
    53, 15,
    53, 27,
    53, 28,
    53, 34,
    53, 36,
    53, 40,
    53, 43,
    53, 48,
    53, 50,
    53, 53,
    53, 55,
    53, 56,
    53, 57,
    53, 58,
    53, 66,
    53, 68,
    53, 69,
    53, 70,
    53, 71,
    53, 72,
    53, 78,
    53, 79,
    53, 80,
    53, 81,
    53, 82,
    53, 83,
    53, 84,
    53, 86,
    53, 87,
    53, 88,
    53, 89,
    53, 90,
    53, 91,
    54, 34,
    55, 13,
    55, 15,
    55, 34,
    55, 36,
    55, 40,
    55, 43,
    55, 48,
    55, 50,
    55, 52,
    55, 53,
    55, 66,
    55, 68,
    55, 69,
    55, 70,
    55, 72,
    55, 78,
    55, 79,
    55, 80,
    55, 81,
    55, 82,
    55, 83,
    55, 84,
    55, 86,
    56, 13,
    56, 15,
    56, 34,
    56, 53,
    56, 66,
    56, 68,
    56, 69,
    56, 70,
    56, 72,
    56, 80,
    56, 82,
    57, 13,
    57, 15,
    57, 28,
    57, 36,
    57, 40,
    57, 43,
    57, 48,
    57, 50,
    57, 53,
    58, 13,
    58, 15,
    58, 34,
    58, 36,
    58, 40,
    58, 43,
    58, 48,
    58, 50,
    58, 52,
    58, 53,
    58, 66,
    58, 68,
    58, 69,
    58, 70,
    58, 71,
    58, 72,
    58, 78,
    58, 79,
    58, 80,
    58, 81,
    58, 82,
    58, 83,
    58, 84,
    58, 86,
    59, 43,
    59, 53,
    59, 90,
    60, 75,
    67, 66,
    67, 71,
    67, 89,
    68, 43,
    68, 53,
    68, 58,
    70, 3,
    70, 8,
    71, 10,
    71, 13,
    71, 14,
    71, 15,
    71, 27,
    71, 28,
    71, 32,
    71, 62,
    71, 67,
    71, 73,
    71, 85,
    71, 87,
    71, 88,
    71, 89,
    71, 90,
    71, 94,
    72, 75,
    75, 75,
    76, 13,
    76, 14,
    76, 15,
    76, 27,
    76, 28,
    76, 68,
    76, 69,
    76, 70,
    76, 72,
    76, 80,
    76, 82,
    76, 85,
    79, 3,
    79, 8,
    80, 3,
    80, 8,
    80, 66,
    80, 71,
    80, 89,
    81, 66,
    81, 71,
    81, 89,
    82, 75,
    83, 13,
    83, 14,
    83, 15,
    83, 27,
    83, 28,
    83, 68,
    83, 69,
    83, 70,
    83, 71,
    83, 72,
    83, 78,
    83, 79,
    83, 80,
    83, 82,
    83, 84,
    83, 85,
    83, 87,
    83, 88,
    83, 89,
    83, 90,
    83, 91,
    85, 14,
    85, 32,
    85, 68,
    85, 69,
    85, 70,
    85, 72,
    85, 80,
    85, 82,
    85, 89,
    86, 3,
    86, 8,
    87, 13,
    87, 15,
    87, 66,
    87, 68,
    87, 69,
    87, 70,
    87, 72,
    87, 80,
    87, 82,
    88, 13,
    88, 15,
    88, 68,
    88, 69,
    88, 70,
    88, 72,
    88, 80,
    88, 82,
    89, 68,
    89, 69,
    89, 70,
    89, 72,
    89, 80,
    89, 82,
    90, 3,
    90, 8,
    90, 13,
    90, 15,
    90, 32,
    90, 68,
    90, 69,
    90, 70,
    90, 71,
    90, 72,
    90, 80,
    90, 82,
    90, 85,
    92, 75
};

/* Kerning between the respective left and right glyphs
 * 4.4 format which needs to scaled with `kern_scale`*/
static const int8_t kern_pair_values[] =
{
    -8, -10, -8, -10, 35, -25, -23, -15,
    -15, -15, -15, -15, -15, -20, 10, 10,
    -4, -4, 14, -4, -22, -4, -18, -11,
    -24, 9, -4, -6, -4, -6, -14, -10,
    0, -8, -8, -4, -8, -20, -20, -5,
    -14, -8, -7, 2, 10, 1, 4, 1,
    -23, -23, -20, -10, -4, 2, -12, 2,
    -7, -4, -4, -15, -15, -6, -10, -4,
    6, 6, -14, -14, 14, -14, -14, 6,
    6, -4, -4, -4, -4, -4, -4, -7,
    -11, -8, -14, -31, -15, 9, -10, -10,
    15, -11, -11, -17, -4, -18, -7, -20,
    9, -4, -15, -10, -12, -14, -14, -4,
    -2, -14, -6, -4, -7, -49, -49, -24,
    -2, -20, 6, -9, -10, -12, -12, -12,
    -12, -12, -11, -14, -20, -4, -14, -6,
    -2, -7, 13, -4, -4, 9, -3, -3,
    -8, -6, -8, -8, -9, -9, -9, -8,
    -10, -7, -4, -7, -20, -27, -4, -4,
    -23, -14, -14, -17, -14, -14, 6, 6,
    6, -1, 4, -33, -32, -32, -32, -15,
    -32, -27, -27, -32, -27, -32, -27, -23,
    -27, -15, -17, -27, -17, -20, -6, -31,
    -35, -18, -6, -6, -11, -2, -6, -4,
    6, -22, -20, -20, -20, -20, -12, -12,
    -20, -12, -20, -12, -10, -12, -18, -20,
    -11, 6, -12, -7, -7, -7, -7, -7,
    -7, 10, 9, 13, -4, -4, 15, -4,
    -4, 5, -27, -30, -24, -7, -7, -10,
    -7, -7, -4, 6, -30, -27, -27, -27,
    -4, -27, -21, -21, -27, -21, -27, -21,
    -20, -21, 13, 6, -8, 35, -4, -2,
    -4, 11, -15, -12, -16, -16, 21, -20,
    -15, -20, 13, 13, 10, 21, 3, 3,
    6, 6, 6, 3, 5, 13, 7, 5,
    13, -21, 13, 13, 13, -6, -4, -6,
    -6, -6, -4, -2, -16, -16, -22, -22,
    -4, -6, -4, -4, -6, -4, 15, -24,
    -20, -26, 13, 13, -4, -4, -4, 6,
    -4, -1, -1, -4, -4, 2, 9, 13,
    13, 9, 13, 6, -17, -8, -4, -4,
    -2, -2, -2, -2, 4, -10, -10, -18,
    -20, -6, -2, -2, -2, -2, -2, -2,
    -14, -15, -1, -2, -2, -1, -1, -2,
    -2, -2, -2, -2, -2, -2, 4, 4,
    -15, -19, -12, -2, -2, -2, 1, -2,
    -2, -2, 1, 31
};

/*Collect the kern pair's data in one place*/
static const lv_font_fmt_txt_kern_pair_t kern_pairs =
{
    .glyph_ids = kern_pair_glyph_ids,
    .values = kern_pair_values,
    .pair_cnt = 372,
    .glyph_ids_size = 0
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_pairs,
    .kern_scale = 16,
    .cmap_num = 2,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t ui_font_Font1 = {
#else
lv_font_t ui_font_Font1 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 20,          /*The maximum line height required by the font*/
    .base_line = 4,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if UI_FONT_FONT1*/

