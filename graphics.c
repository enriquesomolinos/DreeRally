#include "graphics.h"

int textureTemp[0xFFFFFu]; // weak

GraphicsGeneral graphicsGeneral;

Graphics4 graphics4;

void *screenBuffer;
void loadGraphics4()
{
	graphics4.badtitBpk = malloc(0x1B80u); // eax@1
	graphics4.badsnapBpk = malloc(0xE400u); // eax@1
	graphics4.escboxBpk = malloc(0x2EB8u); // eax@1
	graphics4.signlineBpk = malloc(0x110u); // eax@1
	graphics4.prep4Bpk = malloc(0x8700u); // eax@1
	
	graphics4.prepw1Bpk = malloc(0xF0D2u); // eax@1

	
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
	graphicsGeneral.t15x150Bpk = malloc(0x18CAu);

	graphicsGeneral.corn3bBpk = malloc(0xA00u);
	graphicsGeneral.corn3aBpk = malloc(0xA00u);
	graphicsGeneral.copperPal = malloc(0x300u);
	graphicsGeneral.carcolPal = malloc(0x300u);
	graphicsGeneral.bgcopPal = malloc(0x600u);	
	graphicsGeneral.fbig3aBpk = malloc(0x18000u);
	graphicsGeneral.fsma3bBpk = malloc(0x6000u);
	graphicsGeneral.fsma3cBpk = malloc(0x6000u);
	graphicsGeneral.fsma3aBpk = malloc(0x6000u);
	graphicsGeneral.fmed1aBpk = malloc(0x1A28u);
	graphicsGeneral.menubg5Bpk = malloc(0x4B000u);
	graphicsGeneral.mulsbg2Bpk = malloc(0x2E00u);
	graphicsGeneral.rank1cBpk = malloc(0x516Cu);
	graphicsGeneral.resupok1Bpk = malloc(0x19A20u);
	graphicsGeneral.rankinf1Bpk = malloc(0x22Eu);
	graphicsGeneral.rankinf2Bpk = malloc(0x71Au);
	graphicsGeneral.rankinf3Bpk = malloc(0x3BAu);
	graphicsGeneral.raceeasBpk = malloc(0x3FC0u);
	graphicsGeneral.racemedBpk = malloc(0x3FC0u);
	graphicsGeneral.raceharBpk = malloc(0x3FC0u);
	graphicsGeneral.pnameBpk = malloc(0x71Au);
	graphicsGeneral.ppistBpk = malloc(0x3BAu);
	graphicsGeneral.prankBpk = malloc(0x22Eu);
	graphicsGeneral.ptseasyBpk = malloc(0x2F4u);
	graphicsGeneral.ptsmedBpk = malloc(0x2F4u);
	graphicsGeneral.ptshardBpk = malloc(0x2F4u);
	graphicsGeneral.placingBpk = malloc(0x3A64u);
	graphicsGeneral.carresBpk = malloc(0x1E780u);
	graphicsGeneral.face01Bpk = malloc(0x1000u);
	graphicsGeneral.face02Bpk = malloc(0x1000u);
	graphicsGeneral.face03Bpk = malloc(0x1000u);
	graphicsGeneral.face04Bpk = malloc(0x1000u);
	graphicsGeneral.face05Bpk = malloc(0x1000u);
	graphicsGeneral.face06Bpk = malloc(0x1000u);
	graphicsGeneral.face07Bpk = malloc(0x1000u);
	graphicsGeneral.face08Bpk = malloc(0x1000u);
	graphicsGeneral.face09Bpk = malloc(0x1000u);
	graphicsGeneral.face10Bpk = malloc(0x1000u);
	graphicsGeneral.face11Bpk = malloc(0x1000u);
	graphicsGeneral.face12Bpk = malloc(0x1000u);
	graphicsGeneral.face13Bpk = malloc(0x1000u);
	graphicsGeneral.face14Bpk = malloc(0x1000u);
	graphicsGeneral.face15Bpk = malloc(0x1000u);
	graphicsGeneral.face16Bpk = malloc(0x1000u);
	graphicsGeneral.face17Bpk = malloc(0x1000u);
	graphicsGeneral.face18Bpk = malloc(0x1000u);
	graphicsGeneral.face19Bpk = malloc(0x1000u);
	graphicsGeneral.face20Bpk = malloc(0x1000u);
	graphicsGeneral.facexxBpk = malloc(0x1000u);
	
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