#include <SDL_stdinc.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include "../../imageUtil.h"
#include "../../graphics.h"
#include "../../defs.h"
#include "../../dr.h"
#include "../../drivers.h"
#include "../../cars.h"
#include "../../config.h"
#include "../../variables.h"
#include "popup.h"

char aASlickSteroidR[30] = "[A slick steroid run, anyone?"; // weak
_UNKNOWN unk_452DE8; // weak
char byte_452E38[] = { '[' }; // weak
_UNKNOWN unk_452D70; // weak

char aMoneyTalksAndT[32] = "Money talks, and [the damage is"; // weak
char byte_452CD0[] = { '[' }; // weak
char byte_452CF8[] = { '[' }; // weak
char aDown_ThatSDoug[34] = "down. That's dough baked luck for"; // weak
char aYou_AndLuckShe[34] = "you. And luck, she ain't no lady."; // weak

char aWannaBeMyHitma[29] = "[Wanna be my hitman, driver?"; // weak
_UNKNOWN unk_453108; // weak
char aWannaGetRichTo[31] = "Wanna get rich, tough guy? OK."; // weak
char aHereSTheDeal_I[35] = "[Here's the deal{. I have put some"; // weak
char aMajorFundsOnTh[34] = "major funds on this race, betting"; // weak
char byte_453248[] = { 't' }; // weak
char aFinishLine_Mak[34] = "[finish line{. Make me right, and"; // weak
char byte_4532E8[] = { '[' }; // weak
_UNKNOWN unk_453338; // weak
_UNKNOWN unk_453388; // weak
char byte_447388[80] =
{
	'\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0','\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0','\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0'
}; // idb
char byte_4473D8[80] =
{
	'\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0','\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0','\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0'
}; // idb
char aNotTooShabbyDr[25] = "[Not too shabby, driver."; // weak
char byte_447478[80] =
{
	'\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0','\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0','\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0'
}; // idb
char aYourWildWinnin[37] = "[Your wild winning streak has earned"; // weak
char aYouAnExtra600B[36] = "[you an extra 600 bucks.{ But don't"; // weak
char aGetCockyThoseO[31] = "get cocky, those other wannabe"; // weak
char aVictoryHoundsA[33] = "victory hounds are going to zero"; // weak
char aRightIntoYourB[36] = "right into your blazing taillights."; // weak
char aAndTheyWantToG[30] = "And they want to get you bad."; // weak
char byte_448648[80] =
{
	'\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0','\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0','\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0'
}; // idb
char byte_448698[80] =
{
	'\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0','\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0','\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0'
}; // idb
char aInconceivableD[24] = "[Inconceivable, driver!"; // weak
char byte_448738[80] =
{
  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0','\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0','\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0'
}; // idb
char aItWasASnowball[36] = "It was a snowball's chance in hell."; // weak
char aThroughThatBli[36] = "Through that blitzkrieg battle, and"; // weak
char aNotAShadowOfAS[35] = "[not a shadow of a scratch on your"; // weak
char aPaintJob_MyBet[36] = "[paint job.{ My bet was on you, and"; // weak
char aItPaidMeBackBi[38] = "it paid me back big time. Here, [your"; // weak
char aShare350_GoKno[40] = "[share{, [$350{. Go knock yourself out."; // weak
char byte_449908[80] =
{
  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0','\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0','\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0'
}; // idb
char byte_449958[80] =
{
	'\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0','\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0','\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0'
}; // idb
char aIAmOneGrateful[35] = "[I am one grateful reaper, driver."; // weak
char byte_4499F8[80] =
{
	'\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0','\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0','\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0',  '\0'
}; // idb
char aEasyAsShifting[30] = "easy as shifting gears 1-2-3."; // weak
char aJustPickUpSome[35] = "[Just pick up some pills along the"; // weak
char aWayAndGetThemT[33] = "[way, and get them to the finish"; // weak
char aLineBeforeThin[37] = "[line before things get crowded{, be"; // weak
char aFirstLikeFloor[29] = "first, like, floor it, like."; // weak
_UNKNOWN unk_453018; // weak
_UNKNOWN unk_453068; // weak

char aWelcomeToDea_0[25] = "[Welcome to Death Rally."; // weak
_UNKNOWN unk_44C248; // weak
char aTheRaceIsOnInD[48] = "The race is on, in [Death Rally{, where life is"; // weak
char aShortHotFastDe[44] = "short & hot, fast & deadly. Watch the road,"; // weak
char aHearTheRumble_[43] = "hear the rumble. [Start out easy{, get the"; // weak
char aFeelOfIt_ButRe[42] = "feel of it. But remember: by the rules or"; // weak
char aFryTheRulesPla[46] = "fry the rules, [play to win{. 'nuff said. Now"; // weak
char aRideYourMachin[45] = "[ride your machine{, your motor-war-chariot."; // weak

char aMoreCarCorpses[38] = "[More car corpses{ for my domain. You"; // weak
char aAreMySweetestM[35] = "are my sweetest minion. Your dead-"; // weak
char aSeriousDedicat[34] = "serious dedication has earned you"; // weak
char aAParkingSpaceA[35] = "a parking space among my horsemen."; // weak
char aABonusOf600ToY[33] = "[A bonus of $600 to you{, horse-"; // weak
char aPoweredSerialA[28] = "powered serial-auto-killer."; // weak
char aWhatMotorizedS[34] = "[What motorized steroid peddling!"; // weak
_UNKNOWN unk_44AC18; // weak
char aWowMyMainMan_I[32] = "Wow, my main man. I didn't know"; // weak
char aThereWasThatMu[33] = "there was that much smoke in the"; // weak
char aWholeBurningHe[32] = "whole burning hell, and through"; // weak
char aItAllBearingGi[32] = "it all, bearing gifts like some"; // weak
char aBlessedBeastYo[35] = "blessed beast, you came. And [this"; // weak
char byte_44ADF8[] = { '[' }; // weak
_UNKNOWN unk_44AE48; // weak
_UNKNOWN unk_44AE98; // weak
char aWhereReMyStero[23] = "[Where're my steroids?"; // weak
_UNKNOWN unk_44AF38; // weak
char aTheWholeDealWe[35] = "[The whole deal went sour{ because"; // weak
char aOfYourIncompet[34] = "of your incompetence. A few slick"; // weak
char aTurnsOfTheWhee[34] = "turns of the wheel, but no, nope!"; // weak
char aIMNotHappyAndW[32] = "I'm not happy, and when I'm not"; // weak
char aHappyIAmMadAnd[30] = "happy I am mad, and when I am"; // weak
char aMadBadThingsHa[33] = "mad [bad things happen - to you!"; // weak
_UNKNOWN unk_44B168; // weak
_UNKNOWN unk_44B1B8; // weak
char aYouTotallySlew[28] = "[You totally slew that car."; // weak
_UNKNOWN unk_44B258; // weak
char aAKillerRaceThe[36] = "A killer race! The bullets took the"; // weak
char aSkyLikeCloudsO[32] = "sky like clouds of locusts, and"; // weak
char aTheScreamsOfMo[29] = "the screams of motors were a"; // weak
char aBansheeWail_De[32] = "banshee wail. [Death!{ You were"; // weak
char byte_44B3E8[] = { 'b' }; // weak
char byte_44B438[] = { '[' }; // weak
_UNKNOWN unk_44B488; // weak
_UNKNOWN unk_44B4D8; // weak
char aYourHitMissed[18] = "[Your hit missed!"; // weak
_UNKNOWN unk_44B578; // weak
char aYouSissySunday[30] = "You sissy Sunday driver. [The"; // weak
char aSimplestJobAnd[36] = "[simplest job, and you screw it up!"; // weak
char aIBetYouAreAfra[36] = "I bet you are afraid of the dark as"; // weak
char aWell_ILlShowYo[33] = "well. I'll show you what happens"; // weak
char aWhenYouBreakYo[36] = "when you break your promises to me."; // weak
char aIMGonnaMakeYou[25] = "[I'm gonna make you pay!"; // weak
_UNKNOWN unk_44B7A8; // weak
_UNKNOWN unk_44B7F8; // weak
_UNKNOWN unk_44B848; // weak
char aWelcomeToTheSh[21] = "[Welcome to The Shop"; // weak
_UNKNOWN unk_44B8E8; // weak
char aZillionsMoreMi[46] = "Zillions more miles to go. That junk of yours"; // weak
char aIsNoJuggernaut[41] = "is no juggernaut, she won't take you all"; // weak
char aTheWay_YouNeed[44] = "the way. [You need to gear up{, to upgrade,"; // weak
char aMakeHeadlongHe[41] = "make headlong headway, strive to stride,"; // weak
char aStrideToStrive[43] = "stride to strive, evolve, improve, better,"; // weak
char aBest_BuyBeOneS[41] = "best. [Buy & be one shining perfection.{"; // weak
_UNKNOWN unk_44BB18; // weak
_UNKNOWN unk_44BE88; // weak
char aPsst___yeahYou[26] = "[Psst...yeah you, driver."; // weak
_UNKNOWN unk_44BF28; // weak
char aJealousyBurnsY[45] = "Jealousy burns you like a dragon inside, you"; // weak
char aWantThatRoadAl[42] = "[want that road all to yourself?{ So jinx"; // weak
char aThoseRivalSuck[42] = "those rival suckers, let them go out in a"; // weak
char aBlazeYouTakeTh[43] = "blaze; you take the glory. [Welcome to the"; // weak
char aUndergroundM_0[45] = "[Underground Market.{ What you want, we got."; // weak
char aDigOutTheDough[40] = "Dig out the dough, this gonna cost you."; // weak
_UNKNOWN unk_44C158; // weak
_UNKNOWN unk_44C4C8;
char aItSPayBackTime[34] = "     [It's pay-back time, driver."; // weak
_UNKNOWN unk_44C568; // weak
char aThisIsWhatILik[39] = "     This is what I like to see, a guy"; // weak
char aWhoKeepsHisPar[40] = "     who keeps his part of the bargain."; // weak
char aAhTheSweetSmel[40] = "     Ah, the sweet smell of money. Come"; // weak
char aToPapaMyBabies[42] = "     to papa, my babies. [Real nice doing"; // weak
char aBusinessWithYo[39] = "     [business with you{, thunderboy.{"; // weak
char aThanksAndGoodR[39] = "     Thanks, and good racing riddance."; // weak
_UNKNOWN unk_44C798; // weak
_UNKNOWN unk_44C7E8; // weak
char aItSPayBackTi_0[34] = "     [It's pay-back time, driver."; // weak
_UNKNOWN unk_44C888; // weak
char aTutTutHotshotI[39] = "     Tut tut, hotshot, [I can't see my"; // weak
char aMoneyAnywhere_[39] = "     [money anywhere.{ I ain't amused,"; // weak
char aJoker_ADealIsA[38] = "     joker. A deal is a deal. I got a"; // weak
char aReputationToLo[40] = "     reputation to look after. Too bad."; // weak
char aNothingPersona[42] = "     Nothing personal, but [I got to hurt"; // weak
char aYouSomeNow_Hur[37] = "     [you some now.{ Hurt 'im, boyz."; // weak
_UNKNOWN unk_44CAB8; // weak

char aYouWereLappedY[29] = "[You were lapped, you loser!"; // weak
_UNKNOWN unk_44CBF8; // weak
char aThePainTheHumi[38] = "The pain, the humiliation! Your stunt"; // weak
char aMadeMeTheLaugh[34] = "made me the laughing stock of the"; // weak
char aRaces_WhatWere[35] = "races. What were you trying to do,"; // weak
char aMimicSlowMotio[35] = "mimic slow-motion? No one is going"; // weak
char aToTakeMeSeriou[33] = "to take me seriously after this."; // weak
char aNoMoneyOrPoint[29] = "[No money or points awarded."; // weak
_UNKNOWN unk_44CE28; // weak
_UNKNOWN unk_44CE78; // weak
char aTooSlowNoDough[21] = "[Too slow, no dough!"; // weak
_UNKNOWN unk_44CF18; // weak
char aDeathRallyIsFo[32] = "Death Rally is for winners. You"; // weak
char aTotallyLostThi[33] = "totally lost this race. [All the"; // weak
char aBonusYouCollec[35] = "[bonus $$ you collected on the way"; // weak
char aAreNullAndVoid[38] = "[are null and void.{ You get nothing,"; // weak
char aGetIt_ZeroNone[33] = "get it? Zero, none, naught, nix,"; // weak
char aNadaZilch_Next[35] = "nada, zilch. Next time, be better."; // weak

_UNKNOWN unk_454F58; // weak
_UNKNOWN unk_454F8A; // weak
char aItAinTOverTill[30] = "[It ain't over till I say so!"; // weak
_UNKNOWN unk_454FEE; // weak
char aSoTheyThinkThe[35] = "So they think they got you beaten,"; // weak
char aEh_IThinkThatT[36] = "eh? I think that this car-wreck has"; // weak
char aOnlyMadeYouStr[29] = "only made you stronger, iron"; // weak
char aTemperedWicked[35] = "tempered, wicked. So [get back out"; // weak
char aThereAndLetThe[33] = "[there{ and let them find out to"; // weak
char aTheirCost_This[31] = "their cost. [This one's on me."; // weak

_UNKNOWN unk_44C1A8; // weak

_UNKNOWN unk_44C478; // weak
_UNKNOWN unk_44CB08; // weak
_UNKNOWN unk_44CB58; // weak
_UNKNOWN unk_45FBE0; // weak

_UNKNOWN unk_454C38; // weak
char aEndOfTheRoadDr[26] = "[End of the road, driver."; // weak
_UNKNOWN unk_454CD8; // weak
char aThisThenIsHowI[49] = "[This then is how it ends{, not with a bang, but"; // weak
char aWithAWhimper_Y[43] = "with a whimper. You had your shot at glory"; // weak
char aRoadButYouBlew[46] = "road, but [you blew it{. Life is hard and all"; // weak
char aThat_InDeathRa[50] = "that. In [Death Rally{, you get only one go, only"; // weak
char aTheBestCanMake[45] = "the best can make it. But look at the bright"; // weak
char aSideAtLeastYou[43] = "side, at least you lived to tell the tale."; // weak
_UNKNOWN unk_454F08; // weak

 // weak
char bigLetterSpacing_445848[] ;

int dword_45678C = 5; // weak

//----- (0042E6F0) --------------------------------------------------------
char noCollectPopup_42E6F0()
{
  createPopup(33, 131, 497, 230, 1);
  drawImageWithPosition((int)spons1bBpk, 104, 128, (int)((char *)screenBuffer + 107565));
  writeTextInScreen((const char *)&unk_44CE28, 87201);
  writeTextInScreen((const char *)&unk_44CE78, 97441);
  writeTextInScreen(aTooSlowNoDough, 107681);
  writeTextInScreen((const char *)&unk_44CF18, 117921);
  writeTextInScreen(aDeathRallyIsFo, 128161);
  writeTextInScreen(aTotallyLostThi, 138401);
  writeTextInScreen(aBonusYouCollec, 148641);
  writeTextInScreen(aAreNullAndVoid, 158881);
  writeTextInScreen(aGetIt_ZeroNone, 169121);
  writeTextInScreen(aNadaZilch_Next, 179361);
  drawTextWithFont((int)graphicsGeneral.fbig3aBpk, (int)&bigLetterSpacing_445848, "CONTINUE", 202432);
  keysRead_45E0C0[KEY_ENTER] = 0;
  refreshAllScreen();
  return drawPopupCursor_42C780 ();
}

//----- (0042DD10) --------------------------------------------------------
int sabotageScreen()
{
  unsigned __int8 v0; // dl@1
  char v1; // bl@1
  unsigned __int8 v2; // al@1
  int v3; // esi@1
  int v4; // edx@1
  int v5; // ecx@1
//  signed int v6; // eax@1
  int result; // eax@7
  
//  signed int v9; // esi@8
//  int v10; // ecx@8
  int v11; // edx@26
  int v12; // edi@29
  unsigned __int8 v13; // bl@29
  int v14; // edx@29
  char *v15; // edi@29
  signed int v16; // ecx@29
  signed int v17; // eax@29
  int v18; // esi@43
  int v19; // edx@44
  unsigned int v20; // eax@45
  int v21; // eax@45
  unsigned int v22; // edi@45
  int v23; // ST20_4@45
  char *v24; // ecx@45
  char v25; // dl@46
  int v26; // eax@47
  char v27; // cl@48
  unsigned int v28; // eax@49
  char *v29; // edi@49
  char v30; // cl@50
  char *v31; // edi@51
  char v32; // al@52
  int v33; // eax@53
  char v34; // cl@54
  unsigned int v35; // eax@55
  char *v36; // edi@55
  char v37; // cl@56
  char *v38; // edi@57
  char v39; // al@58
  char v40; // [sp+8h] [bp-58h]@1
  unsigned __int8 v41; // [sp+9h] [bp-57h]@1
  unsigned __int8 v42; // [sp+Ah] [bp-56h]@1
  unsigned __int8 v43; // [sp+Bh] [bp-55h]@1
  int v44; // [sp+Ch] [bp-54h]@8
  char DstBuf; // [sp+10h] [bp-50h]@45
  char v46[16]; // [sp+1Ch] [bp-44h]@46
  char v47[2]; // [sp+2Ch] [bp-34h]@48
  unsigned __int8 v48; // [sp+2Eh] [bp-32h]@29
  unsigned __int8 v49; // [sp+2Fh] [bp-31h]@29
  int maxDriverPoints;

  //cambiar a racePositions[0][0];
  v0 = BYTE2(dword_45EB50[selectedRace_462CE8]);
  v1 = LOBYTE(dword_45EB50[selectedRace_462CE8]);
  v2 = BYTE3(dword_45EB50[selectedRace_462CE8]);
  v3 = isMultiplayerGame;
  v41 = BYTE1(dword_45EB50[selectedRace_462CE8]);
  v42 = v0;
  v4 = driverId;
  v43 = v2;
  v40 = v1;
  v5 = 0;
 // v6 = (signed int)dword_46084C;
  do
  {
    if ( v5 != v4 && !v3 )
      drivers[v5].damage = 0;
    //v6 += 108;
    ++v5;
  }
  while ( v5 < 20 );
  if ( isDemo_456B10 )
  {
    result = 0;
  }
  else
  {
    v44 = 1;
	maxDriverPoints = getMaxDriverPoints(driverId);
    if ( isMultiplayerGame || (v11 = 27 * v4, drivers[v11].points > maxDriverPoints) || !useWeapons || drivers[v11].sabotage != 1 )
    {
      result = 0;
    }
    else
    {
      v12 = (unsigned __int8)v1;
      v13 = LOBYTE(drivers[v41].rank);
      v12 *= 108;
	  //LOBYTE(v17) = *((BYTE *)dword_460888 + v12);
	  LOBYTE(v17) = *((int8*)drivers[v12].rank);
      v14 = drivers[v12].rank;
      v48 = LOBYTE(drivers[v42].rank);
      v15 = (char *)drivers[v12].rank;
      v49 = LOBYTE(drivers[v43].rank);
      v16 = (unsigned __int8)v17;
      v17 = (unsigned __int8)v17;
      if ( (unsigned __int8)v17 == v14 )
        v17 = v13;
      if ( v16 < v17 && v16 != v14 )
        v17 = v16;
      if ( v13 < v17 && v13 != v14 )
        v17 = v13;
      if ( v48 < v17 && v48 != v14 )
        v17 = v48;
      if ( v49 < v17 && v49 != v14 )
        v17 = v49;
      v18 = 0;
      if ( *(_DWORD *)v15 != v17 )
      {
        do
          v19 = *(&v41 + v18++);
        while (drivers[v19].rank != v17 );
      }
      v20 = SDL_GetTicks();
      srand(v20);
      v21 = rand();
      v22 = 108 * (unsigned __int8)*(&v40 + v18);
      v23 = v21 % 25 + 25;//calculo del sabotage aleatorio
      //dword_46084C[v22 / 4] = v23;
	  drivers[v22 / 4].damage = v23;
      SDL_itoa(v23, &DstBuf, 10);
      v24 =(char*) drivers[v22].damage;
      do
      {
        v25 = *v24;
		//v24[&v46[-v22] - byte_460840] = *v24;
		//esto ni idea de lo que hace TODO
      //  v24[&v46[-v22] - byte_460840] = *v24;
        ++v24;
      }
      while ( v25 );
      createPopup(45, 165, 458, 195, 1);
      writeTextInScreen(aMoneyTalksAndT, 131301);
      v26 = 0;
      do
      {
        v27 = byte_452CD0[v26];
        v47[v26++] = v27;
      }
      while ( v27 );
      v28 = strlen(&DstBuf) + 1;
      v29 = &v46[15];
      do
        v30 = (v29++)[1];
      while ( v30 );
      memcpy(v29, &DstBuf, v28);
      v31 = &v46[15];
      do
        v32 = (v31++)[1];
      while ( v32 );
      memcpy(v31, "% worth! Sabotage says that", 0x1Cu);
      writeTextInScreen(v47, 141541);
      v33 = 0;
      do
      {
        v34 = byte_452CF8[v33];
        v47[v33++] = v34;
      }
      while ( v34 );
      v35 = strlen(v46) + 1;
      v36 = &v46[15];
      do
        v37 = (v36++)[1];
      while ( v37 );
      memcpy(v36, v46, v35);
      v38 = &v46[15];
      do
        v39 = (v38++)[1];
      while ( v39 );
      memcpy(v38, " is going down{ and staying", 0x1Cu);
      writeTextInScreen(v47, 151781);
      writeTextInScreen(aDown_ThatSDoug, 162021);
      writeTextInScreen(aYou_AndLuckShe, 172261);
      writeTextInScreen((const char *)&unk_452D70, 179301);
      drawTextWithFont((int)graphicsGeneral.fbig3aBpk, (int)&bigLetterSpacing_445848, "CONTINUE", 201792);
      refreshAllScreen();
      drawPopupCursor_42C780 ();
      result = v44;
    }
  }
  return result;
}
//----- (00431B30) --------------------------------------------------------
int showHitmanScreen()
{
  int result; // eax@2
  int v1; // eax@6
  signed int v2; // ebx@7
  int v3; // eax@19
  char v4; // cl@20
  unsigned int v5; // eax@21
  void *v6; // edi@21
  char v7; // cl@22
  char *v8; // edi@23
  char v9; // al@24
  signed int v10; // esi@25
  signed int v11; // esi@27
  int v12; // eax@31
  signed int v13; // ebp@32
  int v14; // ebx@45
  int v15; // edx@45
  int v16; // eax@46
  char v17; // cl@47
  char *v18; // eax@48
  char *v19; // edx@48
  char v20; // cl@49
  unsigned int v21; // eax@50
  void *v22; // edi@50
  char v23; // cl@51
  char *v24; // edi@52
  char v25; // al@53
  int v26; // eax@54
  char v27; // cl@55
  unsigned int v28; // eax@56
  void *v29; // edi@56
  char v30; // cl@57
  char *v31; // edi@58
  char v32; // al@59
  signed int v33; // esi@60
  signed int v34; // esi@62
  int v35; // eax@65
  char *v36; // eax@65
  char *v37; // edx@65
  char v38; // cl@66
  int v39; // [sp+0h] [bp-48h]@29
  int v40; // [sp+4h] [bp-44h]@3
  int v41; // [sp+8h] [bp-40h]@7
  __int16 v42; // [sp+Ch] [bp-3Ch]@7
  char v43; // [sp+13h] [bp-35h]@21
  char v44[52]; // [sp+14h] [bp-34h]@20

  if ( isDemo_456B10 )
    return 0;
  v40 = 1;
  if ( rand() % 100 < dword_45678C && useWeapons )
  {
    dword_45678C = 5;
    if ( rand() % 100 >= 50 )
    {
		v12 = drivers[driverId].carType;
      if ( v12 == 5 )
      {
        v41 = 808464438;//6000
        LOBYTE(v42) = 0;
        v13 = 1;
      }
      else
      {
        v13 = v40;
      }
      if ( v12 == 4 )
      {
        v41 = 808464436;//4000
        LOBYTE(v42) = 0;
        v13 = 2;
      }
      if ( v12 == 3 )
      {
        v41 = 808464435; //3000
        LOBYTE(v42) = 0;
        v13 = 3;
      }
      if ( v12 == 2 )
      {
        v41 = 808464434; //2000
        LOBYTE(v42) = 0;
        v13 = 4;
      }
      if ( v12 == 1 )
      {
        v41 = 808464433;//1000
        LOBYTE(v42) = 0;
        v13 = 5;
      }
      if ( !v12 )
      {
        v41 = 3158069;
        v13 = 6;
      }
      createPopup(33, 131, 482, 230, 1);
      drawImageWithPosition((int)event2Bpk, 104, 128, (int)((char *)screenBuffer + 107565));
      writeTextInScreen(aWannaBeMyHitma, 107681);
      writeTextInScreen((const char *)&unk_453108, 117921);
      writeTextInScreen(aWannaGetRichTo, 128161);
      writeTextInScreen(aHereSTheDeal_I, 138401);
      writeTextInScreen(aMajorFundsOnTh, 148641);
      do
      {
        v14 = rand() % 4;
        v15 = selectedRace_462CE8;
      }
      while ( *((int8*)&dword_45EB50[selectedRace_462CE8] + v14) == driverId );
      v16 = 0;
      do
      {
        v17 = byte_453248[v16];
        v44[v16++] = v17;
      }
      while ( v17 );
	  //todo structura drivers
      v18 = &drivers[*((int8*)&dword_45EB50[v15] + v14)];
      v19 = &drivers[*((int8*)&dword_45EB50[v15] + v14)];
      do
        v20 = *v18++;
      while ( v20 );
      v21 = v18 - v19;
      v22 = &v43;
      do
      {
        v23 = *((int8*)v22 + 1);
        v22 = (char *)v22 + 1;
      }
      while ( v23 );
      memcpy(v22, v19, v21);
      v24 = &v43;
      do
        v25 = (v24++)[1];
      while ( v25 );
      *(_DWORD *)v24 = 1852798752;
      *((_DWORD *)v24 + 1) = 1914729511;
      *((_DWORD *)v24 + 2) = 1751343461;
      *((_DWORD *)v24 + 3) = 1701344288;
      v24[16] = 0;
      writeTextInScreen(v44, 158881);
      writeTextInScreen(aFinishLine_Mak, 169121);
      v26 = 0;
      do
      {
        v27 = byte_4532E8[v26];
        v44[v26++] = v27;
      }
      while ( v27 );
      v28 = strlen((const char *)&v41) + 1;
      v29 = &v43;
      do
      {
        v30 = *((int8*)v29 + 1);
        v29 = (char *)v29 + 1;
      }
      while ( v30 );
      memcpy(v29, &v41, v28);
      v31 = &v43;
      do
        v32 = (v31++)[1];
      while ( v32 );
      *(_WORD *)v31 = 46;
      writeTextInScreen(v44, 179361);
      writeTextInScreen((const char *)&unk_453338, 189601);
      writeTextInScreen((const char *)&unk_453388, 199841);
      refreshAllScreen();
      v33 = 50;
      do
      {
        refreshAndCheckConnection_42A570();
        --v33;
      }
      while ( v33 );
      loadMenuSoundEffect(5u, 5, 0, configuration.effectsVolume, 147456);
      v34 = 20;
      do
      {
        refreshAndCheckConnection_42A570();
        --v34;
      }
      while ( v34 );
      v39 = 1;
      drawYesNoMenu(161, 321, 0, &v39);
      if ( v39 == 1 )
      {
        v35 = *((int8*)&dword_45EB50[selectedRace_462CE8] + v14);
        killQuestDriverId_456BBC = v35;
		v36 = drivers[v35].name;
		// v36 = &byte_460840[108 * v35];
        killOneQuest_456BB8 = v13;
        v37 = (char *)(&unk_45FBE0 - (_UNKNOWN *)v36);
        do
        {
          v38 = *v36;
          v36[(_DWORD)v37] = *v36;
          ++v36;
        }
        while ( v38 );
      }
    }
    else
    {
		v1 = drivers[driverId].carType;
      if ( v1 == 5 )
      {
        v41 = 808464945;
        v42 = 48;
        v2 = 1;
      }
      else
      {
        v2 = v40;
      }
      if ( v1 == 4 )
      {
        v41 = 808464440;
        LOBYTE(v42) = 0;
        v2 = 2;
      }
      if ( v1 == 3 )
      {
        v41 = 808464438;
        LOBYTE(v42) = 0;
        v2 = 3;
      }
      if ( v1 == 2 )
      {
        v41 = 808464436;
        LOBYTE(v42) = 0;
        v2 = 4;
      }
      if ( v1 == 1 )
      {
        v41 = 808464434;
        LOBYTE(v42) = 0;
        v2 = 5;
      }
      if ( !v1 )
      {
        v41 = 808464433;
        LOBYTE(v42) = 0;
        v2 = 6;
      }
      createPopup(33, 131, 482, 230, 1);
      drawImageWithPosition((int)drugdealBpk, 104, 128, (int)((char *)screenBuffer + 107565));
      writeTextInScreen(aASlickSteroidR, 107681);
      writeTextInScreen((const char *)&unk_452DE8, 117921);
      v3 = 0;
      do
      {
        v4 = byte_452E38[v3];
        v44[v3++] = v4;
      }
      while ( v4 );
      v5 = strlen((const char *)&v41) + 1;
      v6 = &v43;
      do
      {
        v7 = *((int8*)v6 + 1);
        v6 = (char *)v6 + 1;
      }
      while ( v7 );
      memcpy(v6, &v41, v5);
      v8 = &v43;
      do
        v9 = (v8++)[1];
      while ( v9 );
      *(_DWORD *)v8 = 1629498491;
      *((_DWORD *)v8 + 1) = 1852799342;
      *((_DWORD *)v8 + 2) = 1495285605;
      *((_DWORD *)v8 + 3) = 541029743;
      *((_DWORD *)v8 + 4) = 1936287828;
      *((_DWORD *)v8 + 5) = 7563552;
      writeTextInScreen(v44, 128161);
      writeTextInScreen(aEasyAsShifting, 138401);
      writeTextInScreen(aJustPickUpSome, 148641);
      writeTextInScreen(aWayAndGetThemT, 158881);
      writeTextInScreen(aLineBeforeThin, 169121);
      writeTextInScreen(aFirstLikeFloor, 179361);
      writeTextInScreen((const char *)&unk_453018, 189601);
      writeTextInScreen((const char *)&unk_453068, 199841);
      refreshAllScreen();
      v10 = 50;
      do
      {
        refreshAndCheckConnection_42A570();
        --v10;
      }
      while ( v10 );
      loadMenuSoundEffect(5u, 5, 0, configuration.effectsVolume, 147456);
      v11 = 20;
      do
      {
        refreshAndCheckConnection_42A570();
        --v11;
      }
      while ( v11 );
      v39 = 1;
      drawYesNoMenu(161, 321, 0, &v39);
      if ( v39 == 1 )
      {
        drugQuest_456BB4 = v2;
        stopSoundChannel_43C3E0(5u);
        return v40;
      }
    }
    stopSoundChannel_43C3E0(5u);
    result = v40;
  }
  else
  {
    if ( dword_45678C < 97 )
      dword_45678C += 2;
    result = 0;
  }
  return result;

}

//----- (0041B400) --------------------------------------------------------
unsigned int lappedPopUp()
{
  createPopup(33, 131, 482, 230, 1);
  drawImageWithPosition((int)spons1bBpk, 104, 128, (int)((char *)screenBuffer + 107565));
  writeTextInScreen((const char *)&unk_44CB08, 87201);
  writeTextInScreen((const char *)&unk_44CB58, 97441);
  writeTextInScreen(aYouWereLappedY, 107681);
  writeTextInScreen((const char *)&unk_44CBF8, 117921);
  writeTextInScreen(aThePainTheHumi, 128161);
  writeTextInScreen(aMadeMeTheLaugh, 138401);
  writeTextInScreen(aRaces_WhatWere, 148641);
  writeTextInScreen(aMimicSlowMotio, 158881);
  writeTextInScreen(aToTakeMeSeriou, 169121);
  writeTextInScreen(aNoMoneyOrPoint, 179361);
  return drawTextWithFont((int)graphicsGeneral.fbig3aBpk, (int)&bigLetterSpacing_445848, "CONTINUE", 202432);
}

//----- (0041B4F0) --------------------------------------------------------
unsigned int winStreakPopUp()
{
  signed int v0; // esi@1
  
  int v2; // esi@13

  v0 = 0;
  createPopup(33, 131, 482, 230, 1);
  drawImageWithPosition((int)spons1bBpk, 104, 128, (int)((char *)screenBuffer + 107565));
  
  if ( drivers[driverId].carType == DELIVERATOR )
  {
	  drivers[driverId].money += 5000;
    v0 = 5;
  }
  if (drivers[driverId].carType == WRAITH)
  {
	  drivers[driverId].money += 4000;
    v0 = 4;
  }
  if (drivers[driverId].carType == SHRIEKER)
  {
	  drivers[driverId].money += 3000;
    v0 = 3;
  }
  if (drivers[driverId].carType ==SENTINEL)
  {
	  drivers[driverId].money += 2000;
    v0 = 2;
  }
  if (drivers[driverId].carType == DERVISH)
  {
	  drivers[driverId].money += 1000;
    v0 = 1;
  }
  if (drivers[driverId].carType == VAGABOND)
  {
	  drivers[driverId].money += 600;
    v0 = 0;
  }
  v2 = 800 * v0;
  writeTextInScreen(&byte_447388[v2], 87201);
  writeTextInScreen(&byte_4473D8[v2], 97441);
  writeTextInScreen(&aNotTooShabbyDr[v2], 107681);
  writeTextInScreen(&byte_447478[v2], 117921);
  writeTextInScreen(&aYourWildWinnin[v2], 128161);
  writeTextInScreen(&aYouAnExtra600B[v2], 138401);
  writeTextInScreen(&aGetCockyThoseO[v2], 148641);
  writeTextInScreen(&aVictoryHoundsA[v2], 158881);
  writeTextInScreen(&aRightIntoYourB[v2], 169121);
  writeTextInScreen(&aAndTheyWantToG[v2], 179361);
  return drawTextWithFont((int)graphicsGeneral.fbig3aBpk, (int)&bigLetterSpacing_445848, "CONTINUE", 202432);
}

//----- (0041B6A0) --------------------------------------------------------
unsigned int noPaintJobPopUp()
{
  signed int v0; // esi@1
//  int v1; // eax@1
  int v2; // esi@13

  v0 = 0;
  createPopup(33, 131, 482, 230, 1);
  drawImageWithPosition((int)event2Bpk, 104, 128, (int)((char *)screenBuffer + 107565));
 
  if (drivers[driverId].carType == DELIVERATOR)
  {
	  drivers[driverId].money += 6000;
    v0 = 5;
  }
  if (drivers[driverId].carType == WRAITH)
  {
	  drivers[driverId].money += 4500;
    v0 = 4;
  }
  if (drivers[driverId].carType == SHRIEKER)
  {
	  drivers[driverId].money += 3000;
    v0 = 3;
  }
  if (drivers[driverId].carType == SENTINEL)
  {
	  drivers[driverId].money += 1500;
    v0 = 2;
  }
  if (drivers[driverId].carType == DERVISH)
  {
	  drivers[driverId].money += 750;
    v0 = 1;
  }
  if (drivers[driverId].carType == VAGABOND)
  {
	  drivers[driverId].money += 350;
    v0 = 0;
  }
  v2 = 800 * v0;
  writeTextInScreen(&byte_448648[v2], 87201);
  writeTextInScreen(&byte_448698[v2], 97441);
  writeTextInScreen(&aInconceivableD[v2], 107681);
  writeTextInScreen(&byte_448738[v2], 117921);
  writeTextInScreen(&aItWasASnowball[v2], 128161);
  writeTextInScreen(&aThroughThatBli[v2], 138401);
  writeTextInScreen(&aNotAShadowOfAS[v2], 148641);
  writeTextInScreen(&aPaintJob_MyBet[v2], 158881);
  writeTextInScreen(&aItPaidMeBackBi[v2], 169121);
  writeTextInScreen(&aShare350_GoKno[v2], 179361);
  return drawTextWithFont((int)graphicsGeneral.fbig3aBpk, (int)&bigLetterSpacing_445848, "CONTINUE", 202432);
}

//----- (0041B850) --------------------------------------------------------
unsigned int allCarsCrashPopUp()
{
  signed int v0; // esi@1
  int v1; // eax@1
  int v2; // esi@13

  v0 = 0;
  createPopup(33, 131, 482, 230, 1);
  drawImageWithPosition((int)reaperxBpk, 104, 128, (int)((char *)screenBuffer + 107565));
  v1 = 27 * driverId;

  //segun el tipo de coche
  if (drivers[driverId].carType == DELIVERATOR)
  {
	  drivers[driverId].money += 5000;
    v0 = 5;
  }
  if (drivers[driverId].carType == WRAITH)
  {
	  drivers[driverId].money += 4000;
    v0 = 4;
  }
  if (drivers[driverId].carType == SHRIEKER)
  {
	  drivers[driverId].money += 3000;
    v0 = 3;
  }
  if (drivers[driverId].carType == SENTINEL)
  {
	  drivers[driverId].money += 2000;
    v0 = 2;
  }
  if (drivers[driverId].carType == DERVISH)
  {
	  drivers[driverId].money += 1000;
    v0 = 1;
  }
  if (drivers[driverId].carType == VAGABOND)
  {
	  drivers[driverId].money += 600;
    v0 = 0;
  }
  v2 = 800 * v0;
  writeTextInScreen(&byte_449908[v2], 87201);
  writeTextInScreen(&byte_449958[v2], 97441);
  writeTextInScreen(&aIAmOneGrateful[v2], 107681);
  writeTextInScreen(&byte_4499F8[v2], 117921);
  writeTextInScreen(&aMoreCarCorpses[v2], 128161);
  writeTextInScreen(&aAreMySweetestM[v2], 138401);
  writeTextInScreen(&aSeriousDedicat[v2], 148641);
  writeTextInScreen(&aAParkingSpaceA[v2], 158881);
  writeTextInScreen(&aABonusOf600ToY[v2], 169121);
  writeTextInScreen(&aPoweredSerialA[v2], 179361);
  return drawTextWithFont((int)graphicsGeneral.fbig3aBpk, (int)&bigLetterSpacing_445848, "CONTINUE", 202432);
}

//----- (0041BA00) --------------------------------------------------------
int steriodsNotFoundPopup()
{
  int v0; // ecx@3
  int *v1; // eax@3
  int v2; // ecx@3
  int v3; // ecx@5
  int v4; // ecx@9
  int v5; // ecx@11
  int v6; // eax@15
  char v7; // cl@16
  unsigned int v8; // eax@17
  void *v9; // edi@17
  char v10; // cl@18
  char *v11; // edi@19
  char v12; // al@20
  signed int v13; // esi@23
//  int v14; // ecx@34
  int v15; // eax@34
  int v16; // eax@35
  int v17; // eax@36
  signed int v19=0; // [sp+4h] [bp-44h]@0
  int v20; // [sp+8h] [bp-40h]@3
  __int16 v21; // [sp+Ch] [bp-3Ch]@3
  char v22; // [sp+13h] [bp-35h]@17
  char v23[52]; // [sp+14h] [bp-34h]@16

  createPopup(33, 131, 482, 230, 1);
  drawImageWithPosition((int)drugdealBpk, 104, 128, (int)((char *)screenBuffer + 107565));
  if ( drugQuest_456BB4 <= 0 )
  {
    switch ( drugQuest_456BB4 )
    {
      case -1:
        v13 = 6000;
        break;
      case -2:
        v13 = 4000;
        break;
      case -3:
        v13 = 3000;
        break;
      case -4:
        v13 = 2000;
        break;
      case -5:
        v13 = 1000;
        break;
      default:
        v13 = 500;
        if ( drugQuest_456BB4 != -6 )
          v13 = v19;
        break;
    }
    writeTextInScreen(aWhereReMyStero, 107681);
    writeTextInScreen((const char *)&unk_44AF38, 117921);
    writeTextInScreen(aTheWholeDealWe, 128161);
    writeTextInScreen(aOfYourIncompet, 138401);
    writeTextInScreen(aTurnsOfTheWhee, 148641);
    writeTextInScreen(aIMNotHappyAndW, 158881);
    writeTextInScreen(aHappyIAmMadAnd, 169121);
    writeTextInScreen(aMadBadThingsHa, 179361);
    writeTextInScreen((const char *)&unk_44B168, 189601);
    writeTextInScreen((const char *)&unk_44B1B8, 199841);
    
    v15 = drivers[driverId].money;
    if ( v15 < v13 )
    {
      v17 = drivers[driverId].engine;
      if ( v17 > 0 )
      {
		  drivers[driverId].engine = v17 - 1;
        goto LABEL_40;
      }
      v16 = drivers[driverId].money / 2;
    }
    else
    {
      v16 = v15 - v13;
    }
	drivers[driverId].money = v16;
    goto LABEL_40;
  }
  switch ( drugQuest_456BB4 )
  {
    case 1:
      v21 = 48;
      v0 = drivers[driverId].money;
      v1 = &drivers[driverId].money;
      v20 = 808464945;
      v2 = v0 + 12000;
      break;
    case 2:
      v20 = 808464440;
      v3 = drivers[driverId].money;
      v1 = &drivers[driverId].money;
      LOBYTE(v21) = 0;
      v2 = v3 + 8000;
      break;
    case 3:
      v20 = 808464438;
      LOBYTE(v21) = 0;
      v1 = &drivers[driverId].money;
      v2 = drivers[driverId].money + 6000;
      break;
    case 4:
      LOBYTE(v21) = 0;
      v4 = drivers[driverId].money;
      v1 = &drivers[driverId].money;
      v20 = 808464436;
      v2 = v4 + 4000;
      break;
    case 5:
      v20 = 808464434;
      v5 = drivers[driverId].money;
      v1 = &drivers[driverId].money;
      LOBYTE(v21) = 0;
      v2 = v5 + 2000;
      break;
    default:
      if ( drugQuest_456BB4 != 6 )
        goto LABEL_15;
      v20 = 808464433;
      LOBYTE(v21) = 0;
      v1 = &drivers[driverId].money;
      v2 = drivers[driverId].money + 1000;
      break;
  }
  *v1 = v2;
LABEL_15:
  writeTextInScreen(aWhatMotorizedS, 107681);
  writeTextInScreen((const char *)&unk_44AC18, 117921);
  writeTextInScreen(aWowMyMainMan_I, 128161);
  writeTextInScreen(aThereWasThatMu, 138401);
  writeTextInScreen(aWholeBurningHe, 148641);
  writeTextInScreen(aItAllBearingGi, 158881);
  writeTextInScreen(aBlessedBeastYo, 169121);
  v6 = 0;
  do
  {
    v7 = byte_44ADF8[v6];
    v23[v6++] = v7;
  }
  while ( v7 );
  v8 = strlen((const char *)&v20) + 1;
  v9 = &v22;
  do
  {
    v10 = *((int8*)v9 + 1);
    v9 = (char *)v9 + 1;
  }
  while ( v10 );
  memcpy(v9, &v20, v8);
  v11 = &v22;
  do
    v12 = (v11++)[1];
  while ( v12 );
  *(_DWORD *)v11 = 1869881388;
  *((_DWORD *)v11 + 1) = 1970239776;
  *((_WORD *)v11 + 4) = 46;
  writeTextInScreen(v23, 179361);
  writeTextInScreen((const char *)&unk_44AE48, 189601);
  writeTextInScreen((const char *)&unk_44AE98, 199841);
LABEL_40:
  drawTextWithFont((int)graphicsGeneral.fbig3aBpk, (int)&bigLetterSpacing_445848, "CONTINUE", 202432);
  return 0;
}
// 456BB4: using guessed type int drugQuest_456BB4;
// 460850: using guessed type int dword_460850[];
// 460870: using guessed type int dword_460870[];
// 463CE8: using guessed type int driverId;
// 41BA00: using guessed type char var_34[52];

//----- (0041BDE0) --------------------------------------------------------
int killOnePopup()
{
  int v0; // ecx@3
  int *v1; // eax@3
  int v2; // ecx@3
  int v3; // ecx@5
  int v4; // ecx@9
  int v5; // ecx@11
  int v6; // ecx@13
  int v7; // eax@15
  char v8; // cl@16
  unsigned int v9; // eax@17
  void *v10; // edi@17
  char v11; // cl@18
  char *v12; // edi@19
  char v13; // al@20
  int v14; // eax@21
  char v15; // cl@22
  unsigned int v16; // eax@23
  void *v17; // edi@23
  char v18; // cl@24
  char *v19; // edi@25
  char v20; // al@26
  signed int v21; // esi@29
//  int v22; // ecx@40
  int v23; // eax@40
  int v24; // eax@41
  int v25; // eax@42
  signed int v27=0; // [sp+4h] [bp-44h]@0
  int v28; // [sp+8h] [bp-40h]@3
  char v29; // [sp+Ch] [bp-3Ch]@3
  char v30; // [sp+13h] [bp-35h]@17
  char v31[52]; // [sp+14h] [bp-34h]@16

  createPopup(33, 131, 482, 230, 1);
  drawImageWithPosition((int)event2Bpk, 104, 128, (int)((char *)screenBuffer + 107565));
  if ( killOneQuest_456BB8 <= 0 )
  {
    switch ( killOneQuest_456BB8 )
    {
      case -1:
        v21 = 3000;
        break;
      case -2:
        v21 = 2000;
        break;
      case -3:
        v21 = 1000;
        break;
      case -4:
        v21 = 750;
        break;
      case -5:
        v21 = 500;
        break;
      default:
        v21 = 250;
        if ( killOneQuest_456BB8 != -6 )
          v21 = v27;
        break;
    }
    writeTextInScreen(aYourHitMissed, 107681);
    writeTextInScreen((const char *)&unk_44B578, 117921);
    writeTextInScreen(aYouSissySunday, 128161);
    writeTextInScreen(aSimplestJobAnd, 138401);
    writeTextInScreen(aIBetYouAreAfra, 148641);
    writeTextInScreen(aWell_ILlShowYo, 158881);
    writeTextInScreen(aWhenYouBreakYo, 169121);
    writeTextInScreen(aIMGonnaMakeYou, 179361);
    writeTextInScreen((const char *)&unk_44B7A8, 189601);
    writeTextInScreen((const char *)&unk_44B7F8, 199841);
   
    v23 = drivers[driverId].money;
    if ( v23 < v21 )
    {
      v25 = drivers[driverId].engine;
      if ( v25 > 0 )
      {
		  drivers[driverId].engine = v25 - 1;
        goto LABEL_46;
      }
      v24 = drivers[driverId].money / 2;
    }
    else
    {
      v24 = v23 - v21;
    }
	drivers[driverId].money = v24;
    goto LABEL_46;
  }
  switch ( killOneQuest_456BB8 )
  {
    case 1:
      v29 = 0;
      v0 = drivers[driverId].money;
      v1 = &drivers[driverId].money;
      v28 = 808464438;
      v2 = v0 + 6000;
      break;
    case 2:
      v28 = 808464436;
      v3 = drivers[driverId].money;
      v1 = &drivers[driverId].money;
      v29 = 0;
      v2 = v3 + 4000;
      break;
    case 3:
      v28 = 808464435;
      v29 = 0;
      v1 = &drivers[driverId].money;
      v2 = drivers[driverId].money + 3000;
      break;
    case 4:
      v29 = 0;
      v4 = drivers[driverId].money;
      v1 = &drivers[driverId].money;
      v28 = 808464434;
      v2 = v4 + 2000;
      break;
    case 5:
      v28 = 808464433;
      v5 = drivers[driverId].money;
      v1 = &drivers[driverId].money;
      v29 = 0;
      v2 = v5 + 1000;
      break;
    default:
      if ( killOneQuest_456BB8 != 6 )
        goto LABEL_15;
      v6 = drivers[driverId].money;
      v1 = &drivers[driverId].money;
      v28 = 3158069;
      v2 = v6 + 500;
      break;
  }
  *v1 = v2;
LABEL_15:
  writeTextInScreen(aYouTotallySlew, 107681);
  writeTextInScreen((const char *)&unk_44B258, 117921);
  writeTextInScreen(aAKillerRaceThe, 128161);
  writeTextInScreen(aSkyLikeCloudsO, 138401);
  writeTextInScreen(aTheScreamsOfMo, 148641);
  writeTextInScreen(aBansheeWail_De, 158881);
  v7 = 0;
  do
  {
    v8 = byte_44B3E8[v7];
    v31[v7++] = v8;
  }
  while ( v8 );
  v9 = strlen((const char *)&unk_45FBE0) + 1;
  v10 = &v30;
  do
  {
    v11 = *((int8*)v10 + 1);
    v10 = (char *)v10 + 1;
  }
  while ( v11 );
  memcpy(v10, &unk_45FBE0, v9);
  v12 = &v30;
  do
    v13 = (v12++)[1];
  while ( v13 );
  *(_DWORD *)v12 = 544434464;
  *((_DWORD *)v12 + 1) = 1629515369;
  *((_DWORD *)v12 + 2) = 1918984992;
  *((_WORD *)v12 + 6) = 45;
  writeTextInScreen(v31, 169121);
  v14 = 0;
  do
  {
    v15 = byte_44B438[v14];
    v31[v14++] = v15;
  }
  while ( v15 );
  v16 = strlen((const char *)&v28) + 1;
  v17 = &v30;
  do
  {
    v18 = *((int8*)v17 + 1);
    v17 = (char *)v17 + 1;
  }
  while ( v18 );
  memcpy(v17, &v28, v16);
  v19 = &v30;
  do
    v20 = (v19++)[1];
  while ( v20 );
  *(_DWORD *)v19 = 1870209068;
  *((_DWORD *)v19 + 1) = 1830842997;
  *((_DWORD *)v19 + 2) = 2036690543;
  *((_WORD *)v19 + 6) = 46;
  writeTextInScreen(v31, 179361);
  writeTextInScreen((const char *)&unk_44B488, 189601);
  writeTextInScreen((const char *)&unk_44B4D8, 199841);
LABEL_46:
  drawTextWithFont((int)graphicsGeneral.fbig3aBpk, (int)&bigLetterSpacing_445848, "CONTINUE", 202432);
  return 0;
}

//----- (0041C230) --------------------------------------------------------
unsigned int welcomeShopPopup()
{
  createPopup(45, 131, 458, 230, 1);
  writeTextInScreen((const char *)&unk_44B848, 90300);
  writeTextInScreen(aWelcomeToTheSh, 100540);
  writeTextInScreen((const char *)&unk_44B8E8, 110780);
  writeTextInScreen(aZillionsMoreMi, 121020);
  writeTextInScreen(aIsNoJuggernaut, 131260);
  writeTextInScreen(aTheWay_YouNeed, 141500);
  writeTextInScreen(aMakeHeadlongHe, 151740);
  writeTextInScreen(aStrideToStrive, 161980);
  writeTextInScreen(aBest_BuyBeOneS, 172220);
  writeTextInScreen((const char *)&unk_44BB18, 182460);
  return drawTextWithFont((int)graphicsGeneral.fbig3aBpk, (int)&bigLetterSpacing_445848, "CONTINUE", 202432);
}

//----- (0041C300) --------------------------------------------------------
unsigned int endGamePopup()
{
  unsigned int result; // eax@4

  createPopup(33, 131, 482, 230, 1);
  if ( isMultiplayerGame )
  {
    drawImageWithPosition((int)event2Bpk, 104, 128, (int)((char *)screenBuffer + 107565));
    writeTextInScreen((const char *)&unk_454F58, 87201);
    writeTextInScreen((const char *)&unk_454F8A, 97441);
    writeTextInScreen(aItAinTOverTill, 107681);
    writeTextInScreen((const char *)&unk_454FEE, 117921);
    writeTextInScreen(aSoTheyThinkThe, 128161);
    writeTextInScreen(aEh_IThinkThatT, 138401);
    writeTextInScreen(aOnlyMadeYouStr, 148641);
    writeTextInScreen(aTemperedWicked, 158881);
    writeTextInScreen(aThereAndLetThe, 169121);
    writeTextInScreen(aTheirCost_This, 179361);
  }
  else
  {
    writeTextInScreen((const char *)&unk_454C38, 90300);
    writeTextInScreen(aEndOfTheRoadDr, 100540);
    writeTextInScreen((const char *)&unk_454CD8, 110780);
    writeTextInScreen(aThisThenIsHowI, 121020);
    writeTextInScreen(aWithAWhimper_Y, 131260);
    writeTextInScreen(aRoadButYouBlew, 141500);
    writeTextInScreen(aThat_InDeathRa, 151740);
    writeTextInScreen(aTheBestCanMake, 161980);
    writeTextInScreen(aSideAtLeastYou, 172220);
    writeTextInScreen((const char *)&unk_454F08, 182460);
  }
  result = drawTextWithFont((int)graphicsGeneral.fbig3aBpk, (int)&bigLetterSpacing_445848, "CONTINUE", 202432);
  isDemo_456B10 = 0;
  keysRead_45E0C0[KEY_ENTER] = 0;
  return result;
}
//----- (0042DC70) --------------------------------------------------------
char   confirmationPopup(const char *a1)
{
  int v1; // eax@1

  createPopup(110, 210, 428, 90, 1);
  v1 = getBigTextMidSize(a1);
  drawTextWithFont((int)graphicsGeneral.fbig3aBpk, (int)&bigLetterSpacing_445848, a1, 147524 -v1);
  drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, "Press any key to continue.", 173648);
  refreshAllScreen();
  eventDetected();
  sub_418090();
  while ( !eventDetected() )
    refreshAndCheckConnection_42A570();
  keysRead_45E0C0[KEY_F2] = 0;
  keysRead_45E0C0[KEY_F3] = 0;
  eventDetected();
  return sub_418090();
}
// 4458B0: using guessed type char letterSpacing_4458B0;
// 45E0FC: using guessed type char keysRead_45E0C0[KEY_F2];
// 45E0FD: using guessed type char keysRead_45E0C0[KEY_F3];

//----- (0041C4C0) --------------------------------------------------------
int payBackTimePopup()
{
  int v0; // eax@1
  int v1; // ecx@1
  int v2; // esi@1
  int v3; // eax@17
  int v4; // ecx@27
  int v5; // eax@27

  v0 =  driverId;
  v1 = drivers[driverId].loanType;
  v2 = 0;
  if ( v1== LOAN_DELIVERATOR && drivers[driverId].money < 18000 )
    v2 = 1;
  if ( v1 == LOAN_WRAIGHT && drivers[driverId].money < 13500 )
    v2 = drivers[driverId].loanType;
  if ( v1 == LOAN_SHRIEKER && drivers[driverId].money < 9000 )
    v2 = 1;
  if ( v1 == LOAN_SENTINEL && drivers[driverId].money < 4500 )
    v2 = 1;
  if ( v1 == LOAN_DERVISH && drivers[driverId].money < 2250 )
    v2 = 1;
  createPopup(33, 131, 482, 230, 1);
  drawImageWithPosition2((int)dealer2bBpk, 96, 96, (int)((char *)screenBuffer + 117805));
  if ( v2 )
  {
    writeTextInScreen((const char *)&unk_44C7E8, 87168);
    writeTextInScreen(aItSPayBackTi_0, 97408);
    writeTextInScreen((const char *)&unk_44C888, 107648);
    writeTextInScreen(aTutTutHotshotI, 117888);
    writeTextInScreen(aMoneyAnywhere_, 128128);
    writeTextInScreen(aJoker_ADealIsA, 138368);
    writeTextInScreen(aReputationToLo, 148608);
    writeTextInScreen(aNothingPersona, 158848);
    writeTextInScreen(aYouSomeNow_Hur, 169088);
    writeTextInScreen((const char *)&unk_44CAB8, 179328);
    v4 = driverId;
    v5 = drivers[driverId].engine;
    if ( v5 <= 0 )
		drivers[driverId].money /= 2;
    else
		drivers[driverId].engine = v5 - 1;
  }
  else
  {
    writeTextInScreen((const char *)&unk_44C4C8, 87168);
    writeTextInScreen(aItSPayBackTime, 97408);
    writeTextInScreen((const char *)&unk_44C568, 107648);
    writeTextInScreen(aThisIsWhatILik, 117888);
    writeTextInScreen(aWhoKeepsHisPar, 128128);
    writeTextInScreen(aAhTheSweetSmel, 138368);
    writeTextInScreen(aToPapaMyBabies, 148608);
    writeTextInScreen(aBusinessWithYo, 158848);
    writeTextInScreen(aThanksAndGoodR, 169088);
    writeTextInScreen((const char *)&unk_44C798, 179328);
    v3 = 27 * driverId;
    if (drivers[driverId].loanType == LOAN_DELIVERATOR )
		drivers[driverId].money -= 18000;
    if (drivers[driverId].loanType == LOAN_WRAIGHT )
		drivers[driverId].money -= 13500;
    if (drivers[driverId].loanType == LOAN_SHRIEKER )
		drivers[driverId].money -= 9000;
    if (drivers[driverId].loanType == LOAN_SENTINEL )
		drivers[driverId].money -= 4500;
    if (drivers[driverId].loanType == LOAN_DERVISH )
		drivers[driverId].money -= 2250;
  }
  drawTextWithFont((int)graphicsGeneral.fbig3aBpk, (int)&bigLetterSpacing_445848, "CONTINUE", 202432);
  return 0;
}

//----- (0041C770) --------------------------------------------------------
unsigned int undergroundMarketPopup()
{
  createPopup(45, 131, 458, 230, 1);
  writeTextInScreen((const char *)&unk_44BE88, 90300);
  writeTextInScreen(aPsst___yeahYou, 100540);
  writeTextInScreen((const char *)&unk_44BF28, 110780);
  writeTextInScreen(aJealousyBurnsY, 121020);
  writeTextInScreen(aWantThatRoadAl, 131260);
  writeTextInScreen(aThoseRivalSuck, 141500);
  writeTextInScreen(aBlazeYouTakeTh, 151740);
  writeTextInScreen(aUndergroundM_0, 161980);
  writeTextInScreen(aDigOutTheDough, 172220);
  writeTextInScreen((const char *)&unk_44C158, 182460);
  return drawTextWithFont((int)graphicsGeneral.fbig3aBpk, (int)&bigLetterSpacing_445848, "CONTINUE", 202432);
}

unsigned int welcomePopup()
{
  createPopup(45, 131, 458, 230, 1);
  writeTextInScreen((const char *)&unk_44C1A8, 90300);
  writeTextInScreen(aWelcomeToDea_0, 100540);
  writeTextInScreen((const char *)&unk_44C248, 110780);
  writeTextInScreen(aTheRaceIsOnInD, 121020);
  writeTextInScreen(aShortHotFastDe, 131260);
  writeTextInScreen(aHearTheRumble_, 141500);
  writeTextInScreen(aFeelOfIt_ButRe, 151740);
  writeTextInScreen(aFryTheRulesPla, 161980);
  writeTextInScreen(aRideYourMachin, 172220);
  writeTextInScreen((const char *)&unk_44C478, 182460);
  return drawTextWithFont((int)graphicsGeneral.fbig3aBpk, (int)&bigLetterSpacing_445848, "CONTINUE", 202432);
}

//----- (0041A530) esto pinta el recuadro parece que es x , offset x , y , offset y --------------------------------------------------------
signed int   createPopup(int x, int xLenght, int y, int yLenght, int cornerType)
{
  int v5; // ebp@1
  int v6; // edx@2
  unsigned int v7; // ecx@3
  char *v8; // edi@3
  void *v9; // edi@3
  int v10; // edi@4
  int v11; // ebx@5
  signed int result; // eax@5
  int v13; // edx@7
  int i; // ecx@7
  int v15; // ecx@9
  int v16; // edx@11
  int v17; // ecx@12
  char *v18; // ebx@13
  int v19; // ecx@15
  char *v20; // edx@16
  int v21; // [sp+10h] [bp-4h]@2
  int v22; // [sp+24h] [bp+10h]@11

  v5 = y;
  if (yLenght - 8 > 0 )
  {
    v6 = 640 * xLenght;
    v21 = yLenght - 8;
    do
    {
      v7 = (unsigned int)(v5 - 6) >> 2;
      v8 = (char *)screenBuffer + v6 + x + 1282;
      memset(v8, 0xC4u, 4 * v7);
      v9 = &v8[4 * v7];
	  
      //LOBYTE(v7) = v5 - 6;
      v5 = y;
      memset(v9, -60, v7 & 3);
      v6 += 640;
      --v21;
    }
    while ( v21 );
  }
  v10 = 640 * xLenght;
  if (cornerType)
  {
    drawImageWithPosition((int)graphicsGeneral.corn3aBpk, 32, 20, (int)((char *)screenBuffer + v10 + x));
    drawImageWithPosition((int)((char *)graphicsGeneral.corn3aBpk + 640), 32, 20, (int)((char *)screenBuffer + v10 + x + v5 - 32));
    drawImageWithPosition(
      (int)((char *)graphicsGeneral.corn3aBpk + 1280),
      32,
      20,
      (int)((char *)screenBuffer + 128 * (5 * (yLenght + xLenght) - 100) + x));
    v11 = 640 * (yLenght + xLenght);
    drawImageWithPosition((int)((char *)graphicsGeneral.corn3aBpk + 1920), 32, 20, (int)((char *)screenBuffer + v11 + x + v5 - 12832));
    result = 7;
  }
  else
  {
    drawImageWithPosition((int)graphicsGeneral.corn3bBpk, 32, 20, (int)((char *)screenBuffer + v10 + x));
    drawImageWithPosition((int)((char *)graphicsGeneral.corn3bBpk + 640), 32, 20, (int)((char *)screenBuffer + v10 + x + v5 - 32));
    drawImageWithPosition(
      (int)((char *)graphicsGeneral.corn3bBpk + 1280),
      32,
      20,
      (int)((char *)screenBuffer + 128 * (5 * (yLenght + xLenght) - 100) + x));
    v11 = 640 * (yLenght + xLenght);
    drawImageWithPosition((int)((char *)graphicsGeneral.corn3bBpk + 1920), 32, 20, (int)((char *)screenBuffer + v11 + x + v5 - 12832));
    result = 4;
  }
  v13 = v5 - 64;
  for ( i = 0; i < v5 - 64; v13 = v5 - 64 )
    *((int8*)screenBuffer + v10 + i++ + x + 672) = result;
  v15 = 0;
  if ( v13 > 0 )
  {
    do
      *((char *)screenBuffer + v11 + v15++ + x - 4448) = result;
    while ( v15 < v5 - 64 );
  }
  v16 = yLenght - 40;
  v22 = yLenght - 40;
  if ( v22 > 0 )
  {
    v17 = 640 * xLenght;
    do
    {
      v18 = (char *)screenBuffer + v17;
      v17 += 640;
      --v16;
      v18[x + 12801] = result;
    }
    while ( v16 );
    if ( v22 > 0 )
    {
      v19 = v22;
      do
      {
        v20 = (char *)screenBuffer + v10 + x;
        v10 += 640;
        --v19;
        v20[v5 + 12795] = result;
      }
      while ( v19 );
    }
  }
  return result;
}