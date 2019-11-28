#include "graphics.h"
#include "asset/bpaUtil.h"
#include "dr.h"
#include <stdlib.h>
int textureTemp[0xFFFFFu]; // weak

GraphicsGeneral graphicsGeneral;

Graphics2 graphics2;
Graphics4 graphics4;

void *screenBuffer;

//----- (00419F80) --------------------------------------------------------
void freeMemoryGraphics2()
{
  free(graphics2.chattextBpk);
  //TODO FIX peta no se porque free(fasesel1Bpk);
  free(graphics2.facearr1Bpk);
  free(graphics2.enterx2Bpk);
//  free(shoptxt1Bpk);
  //TODO FIX peta no se porque free(shoptxt2Bpk);
  free(graphics2.fametxtBpk);
  free(graphics2.recotxtBpk);
  free(graphics2.recobarBpk);
  free(graphics2.linlin1Bpk);
  free(graphics2.chatlin1Bpk);
  free(graphics2.cursorBpk);
  free(graphics2.fbig3dBpk);
  free(graphics2.fbig3bBpk);
  free(graphics2.mseletx1Bpk);
  free(graphics2.trarr1Bpk);
  free(graphics2.trsnap2m1Bpk[0]);
  free(graphics2.trsnap2m1Bpk[1]);
  free(graphics2.trsnap2m1Bpk[2]);
  free(graphics2.trsnap2m1Bpk[3]);
  free(graphics2.trsnap2m1Bpk[4]);
  free(graphics2.trsnap2m1Bpk[5]);
  free(graphics2.trsnap2m1Bpk[6]);
  free(graphics2.trsnap2m1Bpk[7]);
  free(graphics2.trsnap2m1Bpk[8]);
  free(graphics2.trsnap2m1Bpk[9]);
  free(graphics2.trsnap2m1Bpk[10]);
  free(graphics2.trsnap2m1Bpk[11]);
  free(graphics2.trsnap2m1Bpk[12]);
  free(graphics2.trsnap2m1Bpk[13]);
  free(graphics2.trsnap2m1Bpk[14]);
  free(graphics2.trsnap2m1Bpk[15]);
  free(graphics2.trsnap2m1Bpk[16]);
  free(graphics2.trsnap2m1Bpk[17]);
  free(graphics2.trsnap2m1Bpk[18]);
  free(graphics2.trsnap2m1Bpk[19]);
  
}

//----- (00419950) --------------------------------------------------------
void loadGraphics2()
{
  int v0; // edi@1
  
  int *v38; // esi@1
   int index = 0;
  v0 = 0;
  cursorBpkFrame = 0;
  graphics2.chattextBpk = malloc(0x7530u);
  graphics2.fasesel1Bpk = malloc(0x1B18u);
  graphics2.facearr1Bpk = malloc(0x1100u);
  graphics2.enterx2Bpk = malloc(0x5000u);
  graphics2.shoptxt1Bpk = malloc(0x2800u);
  graphics2.shoptxt2Bpk = malloc(0x2800u);
  graphics2.fametxtBpk = malloc(0x8700u);
  graphics2.recotxtBpk = malloc(0x2800u);
  graphics2.recobarBpk = malloc(0xAA00u);
  graphics2.linlin1Bpk = malloc(0x111Cu);
  graphics2.chatlin1Bpk = malloc(0x1900u);
  graphics2.cursorBpk = malloc(0x4E20u);
  graphics2.fbig3dBpk = malloc(0x18000u);
  graphics2.fbig3bBpk = malloc(0x18000u);
  graphics2.mseletx1Bpk = malloc(0x2800u);
  graphics2.trarr1Bpk = malloc(0x1500u);
  graphics2.trsnap2m1Bpk[0] = malloc(0x3800u);
  graphics2.trsnap2m1Bpk[1] = malloc(0x3800u);
  graphics2.trsnap2m1Bpk[2] = malloc(0x3800u);
  graphics2.trsnap2m1Bpk[3] = malloc(0x3800u);
  graphics2.trsnap2m1Bpk[4] = malloc(0x3800u);
  graphics2.trsnap2m1Bpk[5] = malloc(0x3800u);
  graphics2.trsnap2m1Bpk[6] = malloc(0x3800u);
  graphics2.trsnap2m1Bpk[7] = malloc(0x3800u);
  graphics2.trsnap2m1Bpk[8] = malloc(0x3800u);
  graphics2.trsnap2m1Bpk[9] = malloc(0x3800u);
  graphics2.trsnap2m1Bpk[10] = malloc(0x3800u);
  graphics2.trsnap2m1Bpk[11] = malloc(0x3800u);
  graphics2.trsnap2m1Bpk[12] = malloc(0x3800u);
  graphics2.trsnap2m1Bpk[13] = malloc(0x3800u);
  graphics2.trsnap2m1Bpk[14] = malloc(0x3800u);
  graphics2.trsnap2m1Bpk[15] = malloc(0x3800u);
  graphics2.trsnap2m1Bpk[16] = malloc(0x3800u);
  graphics2.trsnap2m1Bpk[17] = malloc(0x3800u);
  graphics2.trsnap2m1Bpk[18] = malloc(0x3800u);
  graphics2.trsnap2m1Bpk[19] = malloc(0x3800u);
  
 
  v38 = (int *)&graphics2.trsnap2m1Bpk;
  do
  {
    extractFromBpa("MENU.BPA", textureTemp, "trsnap2m.bpk");
    decryptTexture((int)textureTemp, graphics2.trsnap2m1Bpk[index], v0, 14336);
    ++v38;
	index++;
    v0 += 14336;
  }
  while (index < 20);
  //while ((signed int)v38 < (signed int)&configuration.turboGamepad);
  /*extractFromBpa("MENU.BPA", textureTemp, "trsnap2m.bpk");
  decryptTexture((int)textureTemp, (int)trsnap2m2Bpk, 258048, 14336);
  extractFromBpa("MENU.BPA", textureTemp, "trsnap2m.bpk");
  decryptTexture((int)textureTemp, (int)trsnap2m3Bpk, 272384, 14336);*/
  extractFromBpa("MENU.BPA", textureTemp, "cursor.bpk");
  copyImageToBuffer((int)textureTemp, (int)graphics2.cursorBpk);
  extractFromBpa("MENU.BPA", textureTemp,"f-big3b.bpk");
  copyImageToBuffer((int)textureTemp, (int)graphics2.fbig3bBpk);
  extractFromBpa("MENU.BPA", textureTemp, "f-big3d.bpk");
  copyImageToBuffer((int)textureTemp, (int)graphics2.fbig3dBpk);
  extractFromBpa("MENU.BPA", textureTemp, "chatlin1.bpk");
  copyImageToBuffer((int)textureTemp, (int)graphics2.chatlin1Bpk);
  extractFromBpa("MENU.BPA", textureTemp, "chattext.bpk");
  copyImageToBuffer((int)textureTemp, (int)graphics2.chattextBpk);
  extractFromBpa("MENU.BPA", textureTemp, "entertx2.bpk");
  copyImageToBuffer((int)textureTemp, (int)graphics2.enterx2Bpk);
  extractFromBpa("MENU.BPA", textureTemp, "shoptxt1.bpk");
  copyImageToBuffer((int)textureTemp, (int)graphics2.shoptxt1Bpk);
  extractFromBpa("MENU.BPA", textureTemp, "shoptxt2.bpk");
  copyImageToBuffer((int)textureTemp, (int)graphics2.shoptxt2Bpk);
  extractFromBpa("MENU.BPA", textureTemp, "fametxt.bpk");
  copyImageToBuffer((int)textureTemp, (int)graphics2.fametxtBpk);
  extractFromBpa("MENU.BPA", textureTemp, "recotxt.bpk");
  copyImageToBuffer((int)textureTemp, (int)graphics2.recotxtBpk);
  extractFromBpa("MENU.BPA", textureTemp, "recobar.bpk");
  copyImageToBuffer((int)textureTemp, (int)graphics2.recobarBpk);
  extractFromBpa("MENU.BPA", textureTemp, "lic-lin1.bpk");
  copyImageToBuffer((int)textureTemp, (int)graphics2.linlin1Bpk);
  extractFromBpa("MENU.BPA", textureTemp, "facesel1.bpk");
  copyImageToBuffer((int)textureTemp, (int)graphics2.fasesel1Bpk);
  extractFromBpa("MENU.BPA", textureTemp, "facearr1.bpk");
  copyImageToBuffer((int)textureTemp, (int)graphics2.facearr1Bpk);
  extractFromBpa("MENU.BPA", textureTemp, "mseletx1.bpk");
  copyImageToBuffer((int)textureTemp, (int)graphics2.mseletx1Bpk);
  extractFromBpa("MENU.BPA", textureTemp, "trarr1.bpk");
  copyImageToBuffer((int)textureTemp, (int)graphics2.trarr1Bpk);
}

void loadGraphics4()
{
	graphics4.badtitBpk =(void *) malloc(0x1B80u); // eax@1
	graphics4.badsnapBpk =(void *) malloc(0xE400u); // eax@1
	graphics4.escboxBpk =(void *) malloc(0x2EB8u); // eax@1
	graphics4.signlineBpk =(void *) malloc(0x110u); // eax@1
	graphics4.prep4Bpk =(void *) malloc(0x8700u); // eax@1
	
	graphics4.prepw1Bpk =(void *) malloc(0xF0D2u); // eax@1

	
	extractFromBpa("MENU.BPA", textureTemp, "badtit.bpk");
	copyImageToBuffer((int)textureTemp, (int)graphics4.badtitBpk);
	extractFromBpa("MENU.BPA", textureTemp, "badsnap.bpk");
	copyImageToBuffer((int)textureTemp, (int)graphics4.badsnapBpk);
	extractFromBpa("MENU.BPA", textureTemp, "escbox.bpk");
	copyImageToBuffer((int)textureTemp, (int)graphics4.escboxBpk);
	extractFromBpa("MENU.BPA", textureTemp, "prep4.bpk");
	copyImageToBuffer((int)textureTemp, (int)graphics4.prep4Bpk);
	extractFromBpa("MENU.BPA", textureTemp, "signline.bpk");
	copyImageToBuffer((int)textureTemp, (int)graphics4.signlineBpk);
	extractFromBpa("MENU.BPA", textureTemp, "prepw1.bpk");
	copyImageToBuffer((int)textureTemp, (int)graphics4.prepw1Bpk);
}

//----- (004239C0) --------------------------------------------------------
void freeMemoryGraphics4()
{
	free(graphics4.badtitBpk);
	free(graphics4.badsnapBpk);
	free(graphics4.escboxBpk);
	free(graphics4.signlineBpk);
	free(graphics4.prep4Bpk);
	
	free(graphics4.prepw1Bpk);
}

//----- (00418CC0) --------------------------------------------------------
void loadGraphics1()
{
	graphicsGeneral.t15x150Bpk = (void *)malloc(0x18CAu);

	graphicsGeneral.corn3bBpk =(void *) malloc(0xA00u);
	graphicsGeneral.corn3aBpk =(void *) malloc(0xA00u);
	graphicsGeneral.copperPal =(void *) malloc(0x300u);
	graphicsGeneral.carcolPal =(void *) malloc(0x300u);
	graphicsGeneral.bgcopPal = (void *)malloc(0x600u);	
	graphicsGeneral.fbig3aBpk = (void *)malloc(0x18000u);
	graphicsGeneral.fsma3bBpk =(void *) malloc(0x6000u);
	graphicsGeneral.fsma3cBpk =(void *) malloc(0x6000u);
	graphicsGeneral.fsma3aBpk =(void *) malloc(0x6000u);
	graphicsGeneral.fmed1aBpk = (void *)malloc(0x1A28u);
	graphicsGeneral.menubg5Bpk = (void *)malloc(0x4B000u);
	graphicsGeneral.mulsbg2Bpk = (void *)malloc(0x2E00u);
	graphicsGeneral.rank1cBpk = (void *)malloc(0x516Cu);
	graphicsGeneral.resupok1Bpk = (void *)malloc(0x19A20u);
	graphicsGeneral.rankinf1Bpk = (void *)malloc(0x22Eu);
	graphicsGeneral.rankinf2Bpk =(void *) malloc(0x71Au);
	graphicsGeneral.rankinf3Bpk =(void *) malloc(0x3BAu);
	graphicsGeneral.raceeasBpk =(void *) malloc(0x3FC0u);
	graphicsGeneral.racemedBpk =(void *) malloc(0x3FC0u);
	graphicsGeneral.raceharBpk =(void *) malloc(0x3FC0u);
	graphicsGeneral.pnameBpk =(void *) malloc(0x71Au);
	graphicsGeneral.ppistBpk =(void *) malloc(0x3BAu);
	graphicsGeneral.prankBpk =(void *) malloc(0x22Eu);
	graphicsGeneral.ptseasyBpk =(void *) malloc(0x2F4u);
	graphicsGeneral.ptsmedBpk =(void *) malloc(0x2F4u);
	graphicsGeneral.ptshardBpk =(void *) malloc(0x2F4u);
	graphicsGeneral.placingBpk =(void *) malloc(0x3A64u);
	graphicsGeneral.carresBpk =(void *) malloc(0x1E780u);
	graphicsGeneral.face01Bpk =(void *) malloc(0x1000u);
	graphicsGeneral.face02Bpk =(void *) malloc(0x1000u);
	graphicsGeneral.face03Bpk =(void *) malloc(0x1000u);
	graphicsGeneral.face04Bpk =(void *) malloc(0x1000u);
	graphicsGeneral.face05Bpk =(void *) malloc(0x1000u);
	graphicsGeneral.face06Bpk = (void *)malloc(0x1000u);
	graphicsGeneral.face07Bpk = (void *)malloc(0x1000u);
	graphicsGeneral.face08Bpk = (void *)malloc(0x1000u);
	graphicsGeneral.face09Bpk = (void *)malloc(0x1000u);
	graphicsGeneral.face10Bpk = (void *)malloc(0x1000u);
	graphicsGeneral.face11Bpk = (void *)malloc(0x1000u);
	graphicsGeneral.face12Bpk = (void *)malloc(0x1000u);
	graphicsGeneral.face13Bpk = (void *)malloc(0x1000u);
	graphicsGeneral.face14Bpk = (void *)malloc(0x1000u);
	graphicsGeneral.face15Bpk =(void *) malloc(0x1000u);
	graphicsGeneral.face16Bpk =(void *) malloc(0x1000u);
	graphicsGeneral.face17Bpk =(void *) malloc(0x1000u);
	graphicsGeneral.face18Bpk =(void *) malloc(0x1000u);
	graphicsGeneral.face19Bpk =(void *) malloc(0x1000u);
	graphicsGeneral.face20Bpk =(void *) malloc(0x1000u);
	graphicsGeneral.facexxBpk =(void *) malloc(0x1000u);
	
	extractFromBpa("MENU.BPA", graphicsGeneral.bgcopPal, "bgcop.pal");
	extractFromBpa("MENU.BPA", textureTemp, "15x150.bpk");
	//copyImageToBuffer((int)textureTemp, graphicsGeneral.t15x150Bpk);
	extractFromBpa("MENU.BPA", textureTemp, "f-big3a.bpk");
	copyImageToBuffer((int)textureTemp,graphicsGeneral.fbig3aBpk);
	extractFromBpa("MENU.BPA", textureTemp, "f-sma3a.bpk");
	copyImageToBuffer((int)textureTemp, graphicsGeneral.fsma3aBpk);
	extractFromBpa("MENU.BPA", textureTemp, "f-sma3b.bpk");
	copyImageToBuffer((int)textureTemp, graphicsGeneral.fsma3bBpk);
	extractFromBpa("MENU.BPA", textureTemp, "f-sma3c.bpk");
	copyImageToBuffer((int)textureTemp,graphicsGeneral.fsma3cBpk);
	extractFromBpa("MENU.BPA", textureTemp, "f-med1a.bpk");
	copyImageToBuffer((int)textureTemp, graphicsGeneral.fmed1aBpk);
	extractFromBpa("MENU.BPA", textureTemp, "rank1c.bpk");
	copyImageToBuffer((int)textureTemp, graphicsGeneral.rank1cBpk);
	extractFromBpa("MENU.BPA", textureTemp, "resupok1.bpk");
	copyImageToBuffer((int)textureTemp, graphicsGeneral.resupok1Bpk);
	extractFromBpa("MENU.BPA", textureTemp, "mulsbg2.bpk");
	copyImageToBuffer((int)textureTemp, graphicsGeneral.mulsbg2Bpk);
	extractFromBpa("MENU.BPA", textureTemp, "rankinf1.bpk");
	copyImageToBuffer((int)textureTemp, graphicsGeneral.rankinf1Bpk);
	extractFromBpa("MENU.BPA", textureTemp, "rankinf2.bpk");
	copyImageToBuffer((int)textureTemp, graphicsGeneral.rankinf2Bpk);
	extractFromBpa("MENU.BPA", textureTemp, "rankinf3.bpk");
	copyImageToBuffer((int)textureTemp,graphicsGeneral.rankinf3Bpk);
	extractFromBpa("MENU.BPA", textureTemp, "race-eas.bpk");
	copyImageToBuffer((int)textureTemp, graphicsGeneral.raceeasBpk);
	extractFromBpa("MENU.BPA", textureTemp, "race-med.bpk");
	copyImageToBuffer((int)textureTemp, graphicsGeneral.racemedBpk);
	extractFromBpa("MENU.BPA", textureTemp, "race-har.bpk");
	copyImageToBuffer((int)textureTemp, graphicsGeneral.raceharBpk);
	extractFromBpa("MENU.BPA", textureTemp, "p-name.bpk");
	copyImageToBuffer((int)textureTemp, graphicsGeneral.pnameBpk);
	extractFromBpa("MENU.BPA", textureTemp, "p-pist.bpk");
	copyImageToBuffer((int)textureTemp, graphicsGeneral.ppistBpk);
	extractFromBpa("MENU.BPA", textureTemp, "p-rank.bpk");
	copyImageToBuffer((int)textureTemp, graphicsGeneral.prankBpk);
	extractFromBpa("MENU.BPA", textureTemp, "pts-easy.bpk");
	copyImageToBuffer((int)textureTemp, graphicsGeneral.ptseasyBpk);
	extractFromBpa("MENU.BPA", textureTemp, "pts-med.bpk");
	copyImageToBuffer((int)textureTemp, graphicsGeneral.ptsmedBpk);
	extractFromBpa("MENU.BPA", textureTemp, "pts-hard.bpk");
	copyImageToBuffer((int)textureTemp, graphicsGeneral.ptshardBpk);
	extractFromBpa("MENU.BPA", textureTemp, "placing.bpk");
	copyImageToBuffer((int)textureTemp, graphicsGeneral.placingBpk);
	extractFromBpa("MENU.BPA", textureTemp, "carres.bpk");
	copyImageToBuffer((int)textureTemp, graphicsGeneral.carresBpk);
	extractFromBpa("MENU.BPA", textureTemp, "face01.bpk");
	copyImageToBuffer((int)textureTemp, graphicsGeneral.face01Bpk);//cuidado que es  un array referenciado a este!!!!!!!!
	extractFromBpa("MENU.BPA", textureTemp, "face02.bpk");
	copyImageToBuffer((int)textureTemp, graphicsGeneral.face02Bpk);
	extractFromBpa("MENU.BPA", textureTemp, "face03.bpk");
	copyImageToBuffer((int)textureTemp, graphicsGeneral.face03Bpk);
	extractFromBpa("MENU.BPA", textureTemp, "face04.bpk");
	copyImageToBuffer((int)textureTemp, graphicsGeneral.face04Bpk);
	extractFromBpa("MENU.BPA", textureTemp, "face05.bpk");
	copyImageToBuffer((int)textureTemp, graphicsGeneral.face05Bpk);
	extractFromBpa("MENU.BPA", textureTemp, "face06.bpk");
	copyImageToBuffer((int)textureTemp, graphicsGeneral.face06Bpk);
	extractFromBpa("MENU.BPA", textureTemp, "face07.bpk");
	copyImageToBuffer((int)textureTemp, graphicsGeneral.face07Bpk);
	extractFromBpa("MENU.BPA", textureTemp, "face08.bpk");
	copyImageToBuffer((int)textureTemp, graphicsGeneral.face08Bpk);
	extractFromBpa("MENU.BPA", textureTemp, "face09.bpk");
	copyImageToBuffer((int)textureTemp, graphicsGeneral.face09Bpk);
	extractFromBpa("MENU.BPA", textureTemp, "face10.bpk");
	copyImageToBuffer((int)textureTemp,graphicsGeneral.face10Bpk);
	extractFromBpa("MENU.BPA", textureTemp, "face11.bpk");
	copyImageToBuffer((int)textureTemp, graphicsGeneral.face11Bpk);
	extractFromBpa("MENU.BPA", textureTemp, "face12.bpk");
	copyImageToBuffer((int)textureTemp, graphicsGeneral.face12Bpk);
	extractFromBpa("MENU.BPA", textureTemp, "face13.bpk");
	copyImageToBuffer((int)textureTemp, graphicsGeneral.face13Bpk);
	extractFromBpa("MENU.BPA", textureTemp, "face14.bpk");
	copyImageToBuffer((int)textureTemp, graphicsGeneral.face14Bpk);
	extractFromBpa("MENU.BPA", textureTemp, "face15.bpk");
	copyImageToBuffer((int)textureTemp, graphicsGeneral.face15Bpk);
	extractFromBpa("MENU.BPA", textureTemp, "face16.bpk");
	copyImageToBuffer((int)textureTemp, graphicsGeneral.face16Bpk);
	extractFromBpa("MENU.BPA", textureTemp, "face17.bpk");
	copyImageToBuffer((int)textureTemp, graphicsGeneral.face17Bpk);
	extractFromBpa("MENU.BPA", textureTemp, "face18.bpk");
	copyImageToBuffer((int)textureTemp,graphicsGeneral.face18Bpk);
	extractFromBpa("MENU.BPA", textureTemp, "face19.bpk");
	copyImageToBuffer((int)textureTemp, graphicsGeneral.face19Bpk);
	extractFromBpa("MENU.BPA", textureTemp, "face20.bpk");
	copyImageToBuffer((int)textureTemp,graphicsGeneral.face20Bpk);
	extractFromBpa("MENU.BPA", textureTemp, "facexx.bpk");
	copyImageToBuffer((int)textureTemp, graphicsGeneral.facexxBpk);
	extractFromBpa("MENU.BPA", graphicsGeneral.copperPal, "copper.pal");
	extractFromBpa("MENU.BPA", graphicsGeneral.carcolPal, "carcol.pal");
	extractFromBpa("MENU.BPA", textureTemp, "corn3a.bpk");
	copyImageToBuffer((int)textureTemp, graphicsGeneral.corn3aBpk);
	extractFromBpa("MENU.BPA", textureTemp, "corn3b.bpk");
	copyImageToBuffer((int)textureTemp, graphicsGeneral.corn3bBpk);
	extractFromBpa("MENU.BPA", textureTemp, "menubg5.bpk");
	copyImageToBuffer((int)textureTemp, graphicsGeneral.menubg5Bpk);
}

//----- (004196F0) --------------------------------------------------------
void freeMemoryGraphics1()
{
	free(graphicsGeneral.corn3bBpk);
	free(graphicsGeneral.corn3aBpk);
	free(graphicsGeneral.copperPal);
	free(graphicsGeneral.carcolPal);
	free(graphicsGeneral.bgcopPal);
	free(graphicsGeneral.t15x150Bpk);
	free(graphicsGeneral.fbig3aBpk);
	free(graphicsGeneral.menubg5Bpk);
	free(graphicsGeneral.fsma3bBpk);
	free(graphicsGeneral.fsma3cBpk);
	free(graphicsGeneral.fsma3aBpk);
	free(graphicsGeneral.fmed1aBpk);
	free(graphicsGeneral.mulsbg2Bpk);
	free(graphicsGeneral.rank1cBpk);
	free(graphicsGeneral.resupok1Bpk);
	free(graphicsGeneral.rankinf1Bpk);
	free(graphicsGeneral.rankinf2Bpk);
	free(graphicsGeneral.rankinf3Bpk);
	free(graphicsGeneral.raceeasBpk);
	free(graphicsGeneral.racemedBpk);
	free(graphicsGeneral.raceharBpk);
	free(graphicsGeneral.pnameBpk);
	free(graphicsGeneral.ppistBpk);
	free(graphicsGeneral.prankBpk);
	free(graphicsGeneral.ptseasyBpk);
	free(graphicsGeneral.ptsmedBpk);
	free(graphicsGeneral.ptshardBpk);
	free(graphicsGeneral.placingBpk);
	free(graphicsGeneral.carresBpk);
	free(graphicsGeneral.face01Bpk);
	free(graphicsGeneral.face02Bpk);
	free(graphicsGeneral.face03Bpk);
	free(graphicsGeneral.face04Bpk);
	free(graphicsGeneral.face05Bpk);
	free(graphicsGeneral.face06Bpk);
	free(graphicsGeneral.face07Bpk);
	free(graphicsGeneral.face08Bpk);
	free(graphicsGeneral.face09Bpk);
	free(graphicsGeneral.face10Bpk);
	free(graphicsGeneral.face11Bpk);
	free(graphicsGeneral.face12Bpk);
	free(graphicsGeneral.face13Bpk);
	free(graphicsGeneral.face14Bpk);
	free(graphicsGeneral.face15Bpk);
	free(graphicsGeneral.face16Bpk);
	free(graphicsGeneral.face17Bpk);
	free(graphicsGeneral.face18Bpk);
	free(graphicsGeneral.face19Bpk);
	free(graphicsGeneral.face20Bpk);
	free(graphicsGeneral.facexxBpk);
}