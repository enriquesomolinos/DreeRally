
#include "creditsScreen.h"
#include "../defs.h"
#include "../dr.h"
#include "../graphics.h"
#include "../asset/bpaUtil.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL.h>

//----- (004274E0) --------------------------------------------------------
int showCredits()
{
  signed int v0; // ebp@1
  unsigned __int8 v1; // bl@4
  signed int v2; // esi@4
  int blue1; // ST14_4@5
  int green1; // ST10_4@5
  int red1; // eax@5
  signed int v6; // ebp@11
  unsigned __int8 v7; // bl@14
  signed int v8; // esi@14
  int blue; // ST14_4@15
  int green; // ST10_4@15
  int red; // eax@15
  int result; // eax@15
  
  memcpy(dword_461ED8, screenBuffer, 0x4B000u);
  sub_4224E0();
  v0 = 50;
  do
  {
    waitWithRefresh();
    if ( v0 % 2 )
      updateCursor(0);
    v1 = 0;
	v2 = 0;
	//v2 = (signed int)dword_45FC44;
    do
    {
	  blue1 = (convertColorToPaletteColor((palette1[v2+2]), v0 << 17) + 0x8000) >> 16;
	  green1 = (convertColorToPaletteColor(palette1[v2 + 1], v0 << 17) + 0x8000) >> 16;
	  red1 = convertColorToPaletteColor((palette1[v2]), v0 << 17);
      setPaletteAndGetValue(v1, (red1 + 0x8000) >> 16, green1, blue1);
      v2 += 3;
      ++v1;
    }
    while ( v2 < maxPaletteEntries );
    --v0;
  }
  while ( v0 >= 0 );
  openPalFromBpa("credit1.pal");
  extractFromBpa("MENU.BPA", textureTemp, "credit1.bpk");
  copyImageToBuffer((int)textureTemp, (int)screenBuffer);
  refreshAllScreen();
  transitionToCurrentImage();
  while ( !eventDetected() )
    waitWithRefresh();
  transitionToBlack();
  openPalFromBpa("credit2.pal");
  extractFromBpa("MENU.BPA", textureTemp, "credit2.bpk");
  copyImageToBuffer((int)textureTemp, (int)screenBuffer);
  refreshAllScreen();
  transitionToCurrentImage();
  while ( !eventDetected() )
    waitWithRefresh();
  transitionToBlack();
  sub_4224E0();
  memcpy(screenBuffer, dword_461ED8, 0x4B000u);
  refreshAllScreen();
  v6 = 0;
  do
  {
    waitWithRefresh();
    if ( v6 % 2 )
      updateCursor(0);
    v7 = 0;
    //v8 = (signed int)dword_45FC44;
	v8 = 0;
    do
    {
		blue = (convertColorToPaletteColor((palette1[v8+2]), v6 << 17) + 0x8000) >> 16;
      green = (convertColorToPaletteColor(palette1[v8 + 1], v6 << 17) + 0x8000) >> 16;
	  red = convertColorToPaletteColor((palette1[v8]) ,v6 << 17);
      result = setPaletteAndGetValue(v7, (red + 0x8000) >> 16, green, blue);
      v8 += 3;
      ++v7;
    }
    while ( v8 < maxPaletteEntries );
    ++v6;
  }
  while ( v6 < 50 );
  return result;
}
