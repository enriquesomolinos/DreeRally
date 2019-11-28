#include <stdio.h>

extern void *anim_currentFrameData; // idb

unsigned int sub_4181E0();
void decryptAnimFrame();
void   openAnimation(const char *animFile, int a2, char * music, int a4, char * effect, char onKeyPressExit, char screenResolution);

FILE* checkAndOpenAnimation();
