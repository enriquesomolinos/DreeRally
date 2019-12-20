#include "startGameScreen.h"
#include "../defs.h"
#include "../dr.h"
#include "../graphics.h"
#include "../asset/bpaUtil.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL.h>

int textureTemp[0xFFFFFu]; // weak

//----- (00427380) --------------------------------------------------------
int apogeeScreen()
{
  signed int v0; // esi@1
  signed int v1; // esi@3
  SDL_RWops *file; // eax@6
  SDL_Surface *image; // ebx@6
//  SDL_RWops * file; // eax@6
 // SDL_Surface * image; // ebx@6

  int v4; // edi@6
  signed int v5; // esi@6
  signed int v6; // esi@8

  v0 = 0;
 

  openPalFromBpa("apogee.pal");
 
  extractFromBpa("MENU.BPA", textureTemp, "apogee.bpk");
  copyImageToBuffer(textureTemp, screenBuffer);
  refreshAllScreen();
  transitionToCurrentImage();
  
  v1 = 0;
  do
  {
    waitWithRefresh();
    ++v1;
  }
  //espera de tres segundos
  while ( !eventDetected() && v1 < 180 );
  transitionToBlack();
  openPalFromBpa("remedy.pal");

  extractFromBpa("MENU.BPA", textureTemp, "remedy.bpk");
  copyImageToBuffer(textureTemp, screenBuffer);
  refreshAllScreen();
  transitionToCurrentImage();

  v1 = 0;
  do
  {
	  waitWithRefresh();
	  ++v1;
  }
  //espera de tres segundos
  while (!eventDetected() && v1 < 180);
  transitionToBlack();
  do
	  setPaletteAndGetValue(v0++, 0, 0, 0);
  while (v0 < 256);
  openPalFromBpa("GTLOGO4.PAL");
  extractFromBpa("MENU.BPA", textureTemp, "GTLOGO4.BPK");
  copyImageToBuffer((int)textureTemp, (int)screenBuffer);
  refreshAllScreen();
  transitionToCurrentImage();
  v1 = 0;
  do
  {
	  waitWithRefresh();
	  ++v1;
  }
  //espera de tres segundos
  while (!eventDetected() && v1 < 180);
  transitionToBlack();

  

  file = SDL_RWFromFile("rmd.bmp", "rb");
  image = SDL_LoadBMP_RW(file, 1);
  v4 = 0;
  v5 = 0;
  //v5 = (signed int)dword_45FC44;
  do
  {
	palette1[v5] = colorToPaletteEntry(
		(unsigned __int8)(image->format->palette->colors[v4].r    & 0xFC) << 14,6553600);
	palette1[v5+1] = colorToPaletteEntry(
		(unsigned __int8)(image->format->palette->colors[v4].g    & 0xFC) << 14,6553600);
	palette1[v5+2] = colorToPaletteEntry(
		(unsigned __int8)(image->format->palette->colors[v4].b    & 0xFC) << 14,6553600);

    v5 += 3;
	//v5 += 12;
    v4 += 1;
  }
  while ( v5 <maxPaletteEntries );
  memcpy(screenBuffer, *(const void **)(image + 20), 0x4B000u);
  SDL_FreeSurface(image);
  refreshAllScreen();
  transitionToCurrentImage();
  v6 = 0;
  do
  {
    
	  
	  waitWithRefresh();
    ++v6;
  }
  //espera de tres segundos
  while ( !eventDetected() && v6 < 180 );
  return transitionToBlack();
}

//----- (00427880) --------------------------------------------------------
int showStartScreen()
{
  signed int v0; // esi@1

  v0 = 0;
  do
    setPaletteAndGetValue(v0++, 0, 0, 0);
  while ( v0 < 256 );
  openPalFromBpa("startscr.pal");
  extractFromBpa("MENU.BPA", textureTemp, "startscr.bpk");
  copyImageToBuffer((int)textureTemp, (int)screenBuffer);//esta variable huele a palete
  refreshAllScreen();  
  return transitionToCurrentImage();
}
// 481E20: using guessed type int textureTemp[];

