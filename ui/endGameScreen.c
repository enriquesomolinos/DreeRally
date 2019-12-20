#include "endGameScreen.h"
#include "../defs.h"
#include "../dr.h"
#include "../graphics.h"
#include "../asset/bpaUtil.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL.h>

//----- (00427700) --------------------------------------------------------
int showEndScreen()
{
  SDL_RWops *v0; // eax@1
  SDL_Surface *v1; // ebx@1
  int v2; // edi@1
  signed int v3; // esi@1
  signed int v4; // esi@3
  int v5; // edi@6
  signed int v6; // ebp@6
  unsigned __int8 v7; // bl@7
  signed int v8; // esi@7
  int v9; // ST14_4@8
  int v10; // ST10_4@8
  int v11; // eax@8
  int result; // eax@8

  sub_4224E0();
  transitionToBlack();
  v0 = SDL_RWFromFile("end.bmp", "rb");
  v1 = SDL_LoadBMP_RW(v0, 1);
  v2 = 0;
  v3 = 0;
  //v3 = (signed int)dword_45FC44;
  do
  {
    palette1[v3] = colorToPaletteEntry(
		(unsigned __int8)(v1->format->palette->colors[v2].r    & 0xFC) << 14,6553600);
	palette1[v3+1] = colorToPaletteEntry(
		(unsigned __int8)(v1->format->palette->colors[v2].g    & 0xFC) << 14,6553600);
	palette1[v3+2] = colorToPaletteEntry(
		(unsigned __int8)(v1->format->palette->colors[v2].b    & 0xFC) << 14,6553600);

	v3 += 3;
    v2 += 1;
  }
  while ( v3 < maxPaletteEntries );
  memcpy(screenBuffer, v1->pixels, 0x4B000u);
  SDL_FreeSurface(v1);
  refreshAllScreen();
  transitionToCurrentImage();
  v4 = 0;
  do
  {
    waitWithRefresh();
    ++v4;
  }
  while ( !eventDetected() && v4 < 560 );
  v5 = 6553600;
  v6 = 65500;
  do
  {
    waitWithRefresh();
    setMusicVolume(v6);
    v7 = 0;
	v8 = 0;
	//v8 = (signed int)dword_45FC44;
    do
    {
      v9 = (convertColorToPaletteColor((palette1[v8+2]), v5) + 0x8000) >> 16;
      v10 = (convertColorToPaletteColor(palette1[v8 + 1], v5) + 0x8000) >> 16;
      v11 = convertColorToPaletteColor((palette1[v8] - 4), v5);
      result = setPaletteAndGetValue(v7, (v11 + 0x8000) >> 16, v10, v9);
      v8 += 3;
      ++v7;
    }
    while ( v8 < maxPaletteEntries );
    v6 -= 2620;
    v5 -= 0x40000;
  }
  while ( v6 >= 0 );
  return result;
}

