#ifndef IMAGE_UTIL_H
#define IMAGE_UTIL_H

int   drawImageWithPosition2(int a1, int a2, int a3, int a4);
int   drawImageWithPosition(int a1, int a2, int a3, int a4);
unsigned int   drawTextWithFont(int a1, int a2, const char *a3, int a4);
int   drawBorder(int a1, int a2, int a3, int a4);
int   drawBorder2(int a1, int a2, unsigned int a3, int a4);

int   getBoxBigTextOffset(const char *a1);
int   sub_41FA50(const char *a1);
int   getBoxTextOffset(const char *a1);
int   getBoxTextSize(const char *a1);
int   getNameOffsetPositionRight(const char *a1);
int   getBigTextMidSize(const char *a1);
unsigned int   drawInGamePrices(const char *a1, int a2);
int   writeTextInScreen(const char *a1, int a2);

extern const int DEFAULT_BIGLETTER_SPACING_OFFSET;
extern char byte_445892[];
extern char letterSpacing_4458B0[];
extern char bigLetterSpacing_445848[];
extern  char  unk_445928[] ;

#endif