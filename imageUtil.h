#ifndef IMAGE_UTIL_H
#define IMAGE_UTIL_H

int   drawImageWithPosition2(int a1, int a2, int a3, int a4);
int   drawImageWithPosition(int a1, int a2, int a3, int a4);
unsigned int   drawTextWithFont(int a1, int a2, const char *a3, int a4);
int   drawBorder(int a1, int a2, int a3, int a4);
int   removeBorder(int a1, int a2, unsigned int a3, int a4);

int   getBoxBigTextOffset(const char *a1);
int   sub_41FA50(const char *a1);
int   getBoxTextOffset(const char *a1);
int   getBoxTextSize(const char *a1);
int   getNameOffsetPositionRight(const char *a1);
int   getBigTextMidSize(const char *a1);
unsigned int   drawInGamePrices(const char *a1, int a2);
int   writeTextInScreen(const char *a1, int a2);

extern const int DEFAULT_BIGLETTER_SPACING_OFFSET;
extern unsigned char fontSpacing_445848[0x1C8];
#define bigLetterSpacing_445848 (*(char (*)[0x68])(fontSpacing_445848 + 0x00))
#define byte_445892 (*(char (*)[0x1C8 - 0x4A])(fontSpacing_445848 + 0x4A))
#define letterSpacing_4458B0 (*(char (*)[0x1C8 - 0x68])(fontSpacing_445848 + 0x68))
#define unk_445928 (*(char (*)[0x1C8 - 0xE0])(fontSpacing_445848 + 0xE0))

#endif