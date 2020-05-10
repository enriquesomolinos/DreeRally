#include <SDL_stdinc.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util/anim.h"
#include "../defs.h"
#include "../dr.h"
#include "../drivers.h"
#include "../cars.h"
#include "../graphics.h"
#include "../config.h"
#include "blackMarketScreen.h"
#include "../variables.h"
#include "../imageUtil.h"
#include "util/menus.h"
#include "util/popup.h"

_UNKNOWN unk_444160;
 _UNKNOWN unk_45FDC4; // weak;
int minesAvailable_45EFF0; // weak
int spikesAvailable_45EFF4; // weak
int rocketAvailable_45EFF8; // weak
int sabotageAvailable_45EFFC; // weak
int minesCost_462D40; // idb
int spikesCost_dword_462D44; // idb
int rocketCost_462D48; // idb
int sabotageCost_462D4C; // idb

int undergroundOptionSelected_dword_461278; // weak

char aBorrow12000Pay[30] = "[Borrow $12,000 - Pay $18,000"; // weak
char byte_4520A0[40] =
{
  '\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'
}; // idb
char aWithBetterGear[34] = "With better gear you'd already be"; // weak
char aOnTheTopEh_SoH[30] = "on the top, eh? So how does a"; // weak
char aShortTermLoanO[36] = "short-term loan of [$12,000{ sound?"; // weak
char byte_452140[1000] =
{
  '\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','[','B','o','r','r','o','w',' ','$','9',',','0','0','0',' ','-',' ','P','a','y',' ','$','1','3',',','5','0','0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','W','i','t','h',' ','b','e','t','t','e','r',' ','g','e','a','r',' ','y','o','u','\'','d',' ','a','l','r','e','a','d','y',' ','b','e','\0','\0','\0','\0','\0','\0','\0','o','n',' ','t','h','e',' ','t','o','p',',',' ','e','h','?',' ','S','o',' ','h','o','w',' ','d','o','e','s',' ','a','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','s','h','o','r','t','-','t','e','r','m',' ','l','o','a','n',' ','o','f',' ','[','$','9',',','0','0','0','{',' ','s','o','u','n','d','?','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','[','B','o','r','r','o','w',' ','$','6',',','0','0','0',' ','-',' ','P','a','y',' ','$','9',',','0','0','0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','W','i','t','h',' ','b','e','t','t','e','r',' ','g','e','a','r',' ','y','o','u','\'','d',' ','a','l','r','e','a','d','y',' ','b','e','\0','\0','\0','\0','\0','\0','\0','o','n',' ','t','h','e',' ','t','o','p',',',' ','e','h','?',' ','S','o',' ','h','o','w',' ','d','o','e','s',' ','a','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','s','h','o','r','t','-','t','e','r','m',' ','l','o','a','n',' ','o','f',' ','[','$','6',',','0','0','0','{',' ','s','o','u','n','d','?','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','[','B','o','r','r','o','w',' ','$','3',',','0','0','0',' ','-',' ','P','a','y',' ','$','4',',','5','0','0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','W','i','t','h',' ','b','e','t','t','e','r',' ','g','e','a','r',' ','y','o','u','\'','d',' ','a','l','r','e','a','d','y',' ','b','e','\0','\0','\0','\0','\0','\0','\0','o','n',' ','t','h','e',' ','t','o','p',',',' ','e','h','?',' ','S','o',' ','h','o','w',' ','d','o','e','s',' ','a','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','s','h','o','r','t','-','t','e','r','m',' ','l','o','a','n',' ','o','f',' ','[','$','3',',','0','0','0','{',' ','s','o','u','n','d','?','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','[','B','o','r','r','o','w',' ','$','1',',','5','0','0',' ','-',' ','P','a','y',' ','$','2',',','2','5','0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','W','i','t','h',' ','b','e','t','t','e','r',' ','g','e','a','r',' ','y','o','u','\'','d',' ','a','l','r','e','a','d','y',' ','b','e','\0','\0','\0','\0','\0','\0','\0','o','n',' ','t','h','e',' ','t','o','p',',',' ','e','h','?',' ','S','o',' ','h','o','w',' ','d','o','e','s',' ','a','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','s','h','o','r','t','-','t','e','r','m',' ','l','o','a','n',' ','o','f',' ','[','$','1',',','5','0','0','{',' ','s','o','u','n','d','?','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'
}; // idb
char aLoanOf12000Gra[26] = "[Loan of $12,000 granted."; // weak
char byte_452550[40] =
{
  '\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'
}; // idb
char aYouHave3RacesT[36] = "You have 3 races to pay me back the"; // weak
char a18000_FairIsFa[34] = "[$18,000{. Fair is fair [<GRIN>{."; // weak
char byte_4525C8[40] =
{
  '\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'
}; // idb
char aPressEscToGoBa[36] = "Press [ESC{ to go back to the shop."; // weak
char aLoanDeniedVaga[31] = "[Loan denied, Vagabond driver."; // weak
_UNKNOWN unk_452A00; // weak
char aThisIsABusines[35] = "This is a business, not a charity."; // weak
char aWeDonTInvestIn[33] = "We don't invest in unproven wild"; // weak
char aCards_SoBuzzOf[25] = "cards. So buzz off, bug."; // weak
_UNKNOWN unk_452AA0; // weak
char byte_452AC8[] = { '[' }; // weak
_UNKNOWN unk_452AF0; // weak
char aPetrolBrainYou[32] = "Petrol brain, you owe me. You'd"; // weak
char aBetterBeHereTo[34] = "better be here to pay me back, or"; // weak
char aElseWeHaveNoth[33] = "else we have nothing to discuss."; // weak
_UNKNOWN unk_452B90; // weak
char aLoanPaidBack_[17] = "[Loan paid back."; // weak
_UNKNOWN unk_452BE0; // weak
char aItSAllHere_IKn[33] = "It's all here. I knew right from"; // weak
char aTheStartThatIC[34] = "the start that I could trust you."; // weak
char aLetSDoThisAgai[29] = "Let's do this again anytime."; // weak
_UNKNOWN unk_452C80; // weak

char aMines[7] = "[Mines"; // weak
_UNKNOWN unk_453400; // weak
char aSowTheseSeedsO[31] = "Sow these seeds of destruction"; // weak
char aAfterABlindBen[35] = "after a blind bend where headlight"; // weak
char aEyesAreTireSmo[27] = "eyes are tire-smoke tired."; // weak
char byte_4534A0[720] =
{
  '\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','[','S','p','i','k','e','d',' ','B','u','m','p','e','r','s','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','N','o','t','h','i','n','g',' ','w','a','k','e','s',' ','y','o','u',' ','u','p',' ','l','i','k','e',' ','a','n',' ','e','n','e','m','y','\0','\0','\0','\0','\0','\0','c','a','r',',',' ','c','l','o','s','i','n','g',' ','i','n',' ','t','o',' ','g','i','v','e',' ','y','o','u','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','a',' ','s','h','a','r','p',' ','k','i','s','s',' ','w','i','t','h',' ','s','p','i','k','e','d',' ','b','u','m','p','e','r','s','.','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','[','R','o','c','k','e','t',' ','F','u','e','l','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','T','h','i','s',' ','n','e','c','t','a','r',' ','i','n',' ','t','h','e',' ','v','e','i','n','s',' ','o','f',' ','y','o','u','r','\0','\0','\0','\0','\0','\0','\0','\0','v','e','h','i','c','l','e',' ','t','a','k','e','s',' ','y','o','u',' ','r','i','g','h','t',' ','i','n','t','o','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','o','r','b','i','t',',',' ','r','e','a','l',' ','s','p','e','e','d','y',' ','l','i','k','e','.','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','[','S','a','b','o','t','a','g','e','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','D','o',' ','y','o','u',' ','h','a','v','e',' ','b','a','d',' ','l','u','c','k',' ','a','l','w','a','y','s',' ','r','i','d','i','n','g','\0','\0','\0','\0','\0','\0','s','h','o','t','g','u','n','?',' ','T','i','m','e',' ','f','o','r',' ','t','h','a','t',' ','g','o','l','d','e','n','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','r','a','c','e','r',' ','b','o','y',' ','t','o',' ','g','e','t',' ','s','o','m','e','.',' ','R','i','g','h','t','?','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'
}; // idb
char aNoSabotage_NoW[22] = "[No sabotage. No way."; // weak
_UNKNOWN unk_4537C0; // weak
char aWhat_YouCrazyM[29] = "What? You crazy, man? Nobody"; // weak
char aTouchesTheAdve[30] = "touches the Adversary's auto-"; // weak
char aMobileAndLives[26] = "mobile and lives, nobody."; // weak
_UNKNOWN unk_453860; // weak
char aOutOfStock[14] = "[OUT OF STOCK"; // weak
_UNKNOWN unk_4538B0; // weak
char aSorryNoCanDo_T[32] = "Sorry, no can do. That's out of"; // weak
char aStock_HoldYour[31] = "stock. Hold your horse(power)s"; // weak
char aTillAfterTheNe[26] = "till after the next race."; // weak
_UNKNOWN unk_453950; // weak
char aHeldFromThisRa[21] = "[HELD FROM THIS RACE"; // weak
_UNKNOWN unk_4539A0; // weak
char aThisItemIsAlwa[37] = "This item is always available in the"; // weak
char aFullVersion_Re[38] = "full version. Register now to get all"; // weak
char aTheDirtyStuffI[31] = "the dirty stuff in every race."; // weak
_UNKNOWN unk_453A40; // weak
char a8MinesLoadedIn[30] = "[8 Mines loaded into your car"; // weak
_UNKNOWN unk_453A90; // weak
char aNowThoseRivalW[33] = "Now those rival wheels will reap"; // weak
char aOnlyBurningEng[31] = "only burning engine death, and"; // weak
char aThatRoadWillBe[29] = "that road will be all yours."; // weak
char byte_453B30[720] =
{
  '\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','[','S','p','i','k','e','d',' ','b','u','m','p','e','r','s',' ','i','n','s','t','a','l','l','e','d','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','N','o','w',' ','y','o','u',' ','a','r','e',' ','s','a','y','i','n','g',':',' ','\'','S','t','a','y',' ','b','a','c','k',' ','o','r','\0','\0','\0','\0','\0','\0','\0','y','o','u',' ','s','o','r','r','y',',',' ','y','o','u',' ','d','e','a','d','.','\'',' ','N','o','w',' ','t','h','a','t','\'','s','\0','\0','\0','\0','\0','\0','\0','\0','t','h','e',' ','a','t','t','i','t','u','d','e','.','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','[','R','o','c','k','e','t',' ','F','u','e','l',' ','b','o','u','g','h','t','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','W','a','r','n','i','n','g','!',' ','W','e','\'','r','e',' ','t','a','l','k','i','n','g',' ','\'','b','o','u','t',' ','a','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','b','a','c','k','d','r','a','f','t',' ','b','a','r','b','e','c','u','e',' ','p','a','r','t','y',' ','h','e','r','e','.','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','[','U','s','i','n','g',' ','t','h','e',' ','f','u','e','l',' ','c','a','u','s','e','s',' ','d','a','m','a','g','e','!','{','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','[','S','a','b','o','t','a','g','e',' ','i','n',' ','p','r','o','g','r','e','s','s','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','S','w','e','e','t',' ','d','e','a','l','.',' ','N','o','w',' ','y','o','u','r',' ','a','r','c','h','-','r','a','c','i','n','g','-','\0','\0','\0','\0','\0','\0','\0','r','i','v','a','l',' ','w','i','l','l',' ','t','a','i','l','s','l','i','d','e',' ','d','o','w','n',' ','t','h','a','t','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','v','i','l','e',' ','r','o','a','d',' ','t','o',' ','w','r','e','c','k','h','o','o','d',' ','o','b','l','i','v','i','o','n','.','\0','\0','\0','\0','\0','\0','\0','\0'
}; // idb

char aContinue_2[10] = "[CONTINUE"; // weak
_UNKNOWN unk_454B70; // weak
char aExitTheUndergr[32] = "Exit the Underground Market and"; // weak
char aEnterTheRaceSi[24] = "enter the Race Sign-Up."; // weak
_UNKNOWN unk_454BE8; // weak
char aPressEscForP_1[30] = "Press [Esc{ for previous menu"; // weak

//----- (00421FB0) --------------------------------------------------------
signed int setUndergroundMarketPrices()
{
  int v0; // eax@1
  bool v1; // zf@11
  signed int result; // eax@11

  v0 = drivers[driverId].carType;
  if ( v0 == DELIVERATOR )
  {
    minesCost_462D40 = 2525;
    spikesCost_dword_462D44 = 2750;
    rocketCost_462D48 = 3275;
    sabotageCost_462D4C = 2625;
  }
  if ( v0 == WRAITH )
  {
    minesCost_462D40 = 1250;
    spikesCost_dword_462D44 = 1750;
    rocketCost_462D48 = 2250;
    sabotageCost_462D4C = 2125;
  }
  if ( v0 == SHRIEKER )
  {
    minesCost_462D40 = 500;
    spikesCost_dword_462D44 = 550;
    rocketCost_462D48 = 625;
    sabotageCost_462D4C = 570;
  }
  if ( v0 == SENTINEL )
  {
    minesCost_462D40 = 450;
    spikesCost_dword_462D44 = 500;
    rocketCost_462D48 = 675;
    sabotageCost_462D4C = 550;
  }
  if ( v0 == DERVISH )
  {
    minesCost_462D40 = 200;
    spikesCost_dword_462D44 = 225;
    rocketCost_462D48 = 350;
    sabotageCost_462D4C = 325;
  }
  v1 = v0 == 0;
  result = 1;
  if ( v1 ) //si es vagabond
  {
    minesCost_462D40 = 150;
    spikesCost_dword_462D44 = 200;
    rocketCost_462D48 = 275;
    sabotageCost_462D4C = 250;
  }
  return result;
}
// 46085C: using guessed type int dword_46085C[];
// 463CE8: using guessed type int driverId;

int loadAcceptedText()
{
  char v0; // bl@1
  int v1; // esi@3

  v0 = 5 - drivers[driverId].carType;
  if ( !drivers[driverId].carType )
    v0 = 4;
  createPopup(144, 114, 384, 119, 1);
  v1 = 240 * (unsigned __int8)v0;
  writeTextInScreen(&aLoanOf12000Gra[v1], 79530);
  writeTextInScreen(&byte_452550[v1], 89770);
  writeTextInScreen(&aYouHave3RacesT[v1], 100010);
  writeTextInScreen(&a18000_FairIsFa[v1], 110250);
  writeTextInScreen(&byte_4525C8[v1], 120490);
  return writeTextInScreen(&aPressEscToGoBa[v1], 130730);
}

//----- (00422810) --------------------------------------------------------
int   getBlackMarketElementText(int a1)
{
  createPopup(144, 114, 384, 119, 1);
  writeTextInScreen(&aMines[240 * a1], 79530);
  writeTextInScreen((const char *)&unk_453400 + 240 * a1, 89770);
  writeTextInScreen(&aSowTheseSeedsO[240 * a1], 100010);
  writeTextInScreen(&aAfterABlindBen[240 * a1], 110250);
  writeTextInScreen(&aEyesAreTireSmo[240 * a1], 120490);
  return writeTextInScreen(&byte_4534A0[240 * a1], 130730);
}

//----- (004228A0) --------------------------------------------------------
int   getBlackMarketElementPurchasedText(int a1)
{
  createPopup(144, 114, 384, 119, 1);
  writeTextInScreen(&a8MinesLoadedIn[240 * a1], 79530);
  writeTextInScreen((const char *)&unk_453A90 + 240 * a1, 89770);
  writeTextInScreen(&aNowThoseRivalW[240 * a1], 100010);
  writeTextInScreen(&aOnlyBurningEng[240 * a1], 110250);
  writeTextInScreen(&aThatRoadWillBe[240 * a1], 120490);
  return writeTextInScreen(&byte_453B30[240 * a1], 130730);
}

//----- (00422930) --------------------------------------------------------
int outOfStockPopup_422930()
{
  createPopup(144, 114, 384, 119, 1);
  writeTextInScreen(aOutOfStock, 79530);
  writeTextInScreen((const char *)&unk_4538B0, 89770);
  writeTextInScreen(aSorryNoCanDo_T, 100010);
  writeTextInScreen(aStock_HoldYour, 110250);
  writeTextInScreen(aTillAfterTheNe, 120490);
  return writeTextInScreen((const char *)&unk_453950, 130730);
}

//----- (004229B0) --------------------------------------------------------
int blackMarketSharewarePopup_4229B0()
{
  createPopup(144, 114, 384, 119, 1);
  writeTextInScreen(aHeldFromThisRa, 79530);
  writeTextInScreen((const char *)&unk_4539A0, 89770);
  writeTextInScreen(aThisItemIsAlwa, 100010);
  writeTextInScreen(aFullVersion_Re, 110250);
  writeTextInScreen(aTheDirtyStuffI, 120490);
  return writeTextInScreen((const char *)&unk_453A40, 130730);
}

//----- (00422A30) --------------------------------------------------------
int drawLoanShark()
{
 
  char v1; // cl@1
  int v2; // edi@3
  int v3; // esi@4
  int result; // eax@4
  int v5; // ecx@5
  char v6; // dl@6
  unsigned int v7; // eax@17
  void *v8; // edi@17
  char v9; // cl@18
  char *v10; // edi@19
  char v11; // al@20
  char *DstBuf=malloc(100); // [sp+4h] [bp-60h]@8
  char v13; // [sp+13h] [bp-51h]@17
  char v14[80]; // [sp+14h] [bp-50h]@6

  createPopup(144, 114, 384, 119, 1);
  v1 = 5 - drivers[driverId].carType;
  if ( !drivers[driverId].carType)
    v1 = 4;
  v2 = drivers[driverId].loanRaces;
  if ( v2 == -1 )
  {
    v3 = 240 * (unsigned __int8)v1;
    writeTextInScreen(&aBorrow12000Pay[v3], 79530);
    writeTextInScreen(&byte_4520A0[v3], 89770);
    writeTextInScreen(&aWithBetterGear[v3], 100010);
    writeTextInScreen(&aOnTheTopEh_SoH[v3], 110250);
    writeTextInScreen(&aShortTermLoanO[v3], 120490);
    result = writeTextInScreen(&byte_452140[v3], 130730);
  }
  else
  {
    v5 = 0;
    do
    {
      v6 = byte_452AC8[v5];
      v14[v5++] = v6;
    }
    while ( v6 );
    if ( drivers[driverId].loanType == LOAN_DELIVERATOR)
      SDL_itoa((unsigned __int64)((double)(drivers[driverId].loanRaces - 1) * 0.3333333333333333 * 6000.0 + 12000.0), DstBuf, 10);
    if (drivers[driverId].loanType == LOAN_WRAIGHT )
      SDL_itoa(
        (unsigned __int64)((double)(drivers[driverId].loanRaces - 1) * 0.3333333333333333 * 4500.0 + 9000.0),
        DstBuf,
        10);
    if (drivers[driverId].loanType == LOAN_SHRIEKER )
      SDL_itoa(
        (unsigned __int64)((double)(drivers[driverId].loanRaces - 1) * 0.3333333333333333 * 3000.0 + 6000.0),
        DstBuf,
        10);
    if (drivers[driverId].loanType == LOAN_SENTINEL )
      SDL_itoa(
        (unsigned __int64)((double)(drivers[driverId].loanRaces - 1) * 0.3333333333333333 * 1500.0 + 3000.0),
        DstBuf,
        10);
    if (drivers[driverId].loanType == LOAN_DERVISH )
      SDL_itoa(
        (unsigned __int64)((double)(drivers[driverId].loanRaces - 1) * 0.3333333333333333 * 750.0 + 1500.0),
        DstBuf,
        10);
    v7 = strlen(DstBuf) + 1;
    v8 = &v13;
    do
    {
      v9 = *((BYTE *)v8 + 1);
      v8 = (char *)v8 + 1;
    }
    while ( v9 );
    memcpy(v8, DstBuf, v7);
    v10 = &v13;
    do
      v11 = (v10++)[1];
    while ( v11 );
    *(_WORD *)v10 = 46;
    writeTextInScreen(v14, 79530);
    writeTextInScreen((const char *)&unk_452AF0, 89770);
    writeTextInScreen(aPetrolBrainYou, 100010);
    writeTextInScreen(aBetterBeHereTo, 110250);
    writeTextInScreen(aElseWeHaveNoth, 120490);
    result = writeTextInScreen((const char *)&unk_452B90, 130730);
  }
  return result;
}

//----- (00422D00) --------------------------------------------------------
int loanDeniedVagabondPopUp()
{
  createPopup(144, 114, 384, 119, 1);
  writeTextInScreen(aLoanDeniedVaga, 79530);
  writeTextInScreen((const char *)&unk_452A00, 89770);
  writeTextInScreen(aThisIsABusines, 100010);
  writeTextInScreen(aWeDonTInvestIn, 110250);
  writeTextInScreen(aCards_SoBuzzOf, 120490);
  return writeTextInScreen((const char *)&unk_452AA0, 130730);
}

//----- (00422D80) --------------------------------------------------------
int loanReturnPopup_422D80()
{
  createPopup(144, 114, 384, 119, 1);
  writeTextInScreen(aLoanPaidBack_, 79530);
  writeTextInScreen((const char *)&unk_452BE0, 89770);
  writeTextInScreen(aItSAllHere_IKn, 100010);
  writeTextInScreen(aTheStartThatIC, 110250);
  writeTextInScreen(aLetSDoThisAgai, 120490);
  return writeTextInScreen((const char *)&unk_452C80, 130730);
}

//----- (00422E00) --------------------------------------------------------
int drawBlackMarketElement0()
{
  unsigned int v0; // eax@2
  void *v1; // edi@2
  char v2; // cl@3
  int v3; // eax@4
  int result; // eax@5
  char v5; // [sp-1h] [bp-29h]@2
  __int16 v6; // [sp+0h] [bp-28h]@2
  char *DstBuf=malloc(100); // [sp+14h] [bp-14h]@2

  if ( minesAvailable_45EFF0 == 1 )
  {
    drawImageWithPosition2((int)maret1eBpk, 96, 96, (int)((char *)screenBuffer + 161936));
    getBlackMarketElementText(0);
    SDL_itoa(minesCost_462D40, DstBuf, 10);
    v6 = 36;
    v0 = strlen(DstBuf) + 1;
    v1 = &v5;
    do
    {
      v2 = *((BYTE *)v1 + 1);
      v1 = (char *)v1 + 1;
    }
    while ( v2 );
    memcpy(v1, DstBuf, v0);
    v3 = getBoxTextOffset((const char *)&v6);
    drawInGamePrices((const char *)&v6, v3 + 214416);
  }
  result = minesAvailable_45EFF0;
  if ( !minesAvailable_45EFF0 )
  {
    drawImageWithPosition2((int)((char *)maret1eBpk + 73728), 96, 96, (int)((char *)screenBuffer + 161936));
    result = outOfStockPopup_422930();
  }
  if ( minesAvailable_45EFF0 == -1 )
  {
    drawImageWithPosition2((int)((char *)maret1eBpk + 36864), 96, 96, (int)((char *)screenBuffer + 161936));
    result = blackMarketSharewarePopup_4229B0();
  }
  return result;
}
// 45EFF0: using guessed type int minesAvailable_45EFF0;

//----- (00422F10) --------------------------------------------------------
int drawBlackMarketElement1()
{
  unsigned int v0; // eax@2
  void *v1; // edi@2
  char v2; // cl@3
  int v3; // eax@4
  int result; // eax@5
  char v5; // [sp-1h] [bp-29h]@2
  __int16 v6; // [sp+0h] [bp-28h]@2
char *DstBuf = malloc(100); // [sp+14h] [bp-14h]@2

if (spikesAvailable_45EFF4 == 1)
{
	drawImageWithPosition2((int)((char *)maret1eBpk + 9216), 96, 96, (int)((char *)screenBuffer + 162040));
	getBlackMarketElementText(1);
	SDL_itoa(spikesCost_dword_462D44, DstBuf, 10);
	v6 = 36;
	v0 = strlen(DstBuf) + 1;
	v1 = &v5;
	do
	{
		v2 = *((BYTE *)v1 + 1);
		v1 = (char *)v1 + 1;
	} while (v2);
	memcpy(v1, DstBuf, v0);
	v3 = getBoxTextOffset((const char *)&v6);
	drawInGamePrices((const char *)&v6, v3 + 214520);
}
result = spikesAvailable_45EFF4;
if (!spikesAvailable_45EFF4)
{
	drawImageWithPosition2((int)((char *)maret1eBpk + 82944), 96, 96, (int)((char *)screenBuffer + 162040));
	result = outOfStockPopup_422930();
}
if (spikesAvailable_45EFF4 == -1)
{
	drawImageWithPosition2((int)((char *)maret1eBpk + 46080), 96, 96, (int)((char *)screenBuffer + 162040));
	result = blackMarketSharewarePopup_4229B0();
}
return result;
}
// 45EFF4: using guessed type int spikesAvailable_45EFF4;

//----- (00423020) --------------------------------------------------------
int drawBlackMarketElement2()
{
	unsigned int v0; // eax@2
	char *v1; // edi@2
	char v2; // cl@3
	int v3; // eax@4
	int result; // eax@5
	char v5; // [sp-1h] [bp-29h]@2
	__int16 v6; // [sp+0h] [bp-28h]@2
	char *DstBuf = malloc(100); // [sp+14h] [bp-14h]@2

	if (rocketAvailable_45EFF8 == 1)
	{
		drawImageWithPosition2((int)((char *)maret1eBpk + 18432), 96, 96, (int)((char *)screenBuffer + 162144));
		getBlackMarketElementText(2);
		SDL_itoa(rocketCost_462D48, DstBuf, 10);
		//v6 = 36; // es el dolar $
		v0 = strlen(DstBuf) + 1;

		v1 = malloc(v0); //coste + el $
	//	v1 = &v5;
		strcpy(v1,"$"); /* copy name into the new var */
		strcat(v1, DstBuf);
		
		/*do
		{
			v2 = *((BYTE *)v1 + 1);
			v1 = (char *)v1 + 1;
		} while (v2);*/
		//strcat(v1,DstBuf);
		//memcpy(&v1+1, DstBuf, v0);

		v3 = getBoxTextOffset(v1);//get small text size

		
 //drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, v1, v3 + 214624);
		drawInGamePrices(v1, v3 + 214624);//write small text
	}
	result = rocketAvailable_45EFF8;
	if (!rocketAvailable_45EFF8)
	{
		drawImageWithPosition2((int)((char *)maret1eBpk + 92160), 96, 96, (int)((char *)screenBuffer + 162144));
		result = outOfStockPopup_422930();
	}
	if (rocketAvailable_45EFF8 == -1)
	{
		drawImageWithPosition2((int)((char *)maret1eBpk + 55296), 96, 96, (int)((char *)screenBuffer + 162144));
		result = blackMarketSharewarePopup_4229B0();
	}
	return result;
}
// 45EFF8: using guessed type int rocketAvailable_45EFF8;

//----- (00423130) --------------------------------------------------------
int drawBlackMarketElement3()
{

//	signed int v1; // ecx@1
//	int v2; // eax@1
	unsigned int v3; // eax@19
	char *v4; // edi@19
	char v5; // cl@20
	int v6; // eax@21
	int result; // eax@22
	char v8; // [sp+Bh] [bp-29h]@19
	__int16 v9; // [sp+Ch] [bp-28h]@19
	char *DstBuf = malloc(100); // [sp+14h] [bp-14h]@2

	int maxDriverPoints = getMaxDriverPoints(driverId);
  
  if ( sabotageAvailable_45EFFC == 1 )
  {
    drawImageWithPosition2((int)((char *)maret1eBpk + 27648), 96, 96, (int)((char *)screenBuffer + 162248));
    getBlackMarketElementText(3);
    SDL_itoa(sabotageCost_462D4C, DstBuf, 10);
    v3 = strlen(DstBuf) + 1;

	v4 = malloc(v3); //coste + el $
	strcpy(v4,"$"); /* copy name into the new var */
	strcat(v4, DstBuf);
	v6 = getBoxTextOffset(v4);//get small text size

    drawInGamePrices(v4, v6 + 214728);
  }
  result = sabotageAvailable_45EFFC;
  if ( !sabotageAvailable_45EFFC )
  {
    drawImageWithPosition2((int)((char *)maret1eBpk + 101376), 96, 96, (int)((char *)screenBuffer + 162248));
    if ( isMultiplayerGame || drivers[driverId].points <= maxDriverPoints)
    {
      result = outOfStockPopup_422930();
    }
    else
    {
      createPopup(144, 114, 384, 119, 1);
      writeTextInScreen(aNoSabotage_NoW, 79530);
      writeTextInScreen((const char *)&unk_4537C0, 89770);
      writeTextInScreen(aWhat_YouCrazyM, 100010);
      writeTextInScreen(aTouchesTheAdve, 110250);
      writeTextInScreen(aMobileAndLives, 120490);
      result = writeTextInScreen((const char *)&unk_453860, 130730);
    }
  }
  if ( sabotageAvailable_45EFFC == -1 )
  {
    drawImageWithPosition2((int)((char *)maret1eBpk + 64512), 96, 96, (int)((char *)screenBuffer + 162248));
    result = blackMarketSharewarePopup_4229B0();
  }
  return result;
}

//----- (00423350) --------------------------------------------------------
int drawBlackMarketContinue()
{
  drawImageWithPosition2((int)bases45Bpk, 96, 96, (int)((char *)screenBuffer + 162352));
  createPopup(144, 114, 384, 119, 1);
  writeTextInScreen(aContinue_2, 79530);
  writeTextInScreen((const char *)&unk_454B70, 89770);
  writeTextInScreen(aExitTheUndergr, 100010);
  writeTextInScreen(aEnterTheRaceSi, 110250);
  writeTextInScreen((const char *)&unk_454BE8, 120490);
  writeTextInScreen(aPressEscForP_1, 130730);
  return drawMenuAnimation(432, 269, continueAnimCurrentFrame_4611D0, (int)contaniBpk, continueAnimFramesSize_4611D0);
}
// 4462A8: using guessed type int continueAnimFramesSize_4611D0[];
// 4611D0: using guessed type int continueAnimCurrentFrame_4611D0;

//----- (00423410) --------------------------------------------------------
void underGroundMenuLeft()
{
  if ( undergroundOptionSelected_dword_461278 > 0 )
    loadMenuSoundEffect(1u, 26, 0, configuration.effectsVolume, dword_445198);
  switch ( undergroundOptionSelected_dword_461278 )
  {
    case MINES:
      undergroundOptionSelected_dword_461278 = LOANSHARK;
      drawLoanShark();
      drawBorder2(10, 243, 0x6Cu, 114);
      drawBorder(10, 115, 108, 114);
      refreshAllScreen();
      break;
    case SPIKES:
      undergroundOptionSelected_dword_461278 = MINES;
      drawBlackMarketElement0();
      drawBorder2(114, 243, 0x6Cu, 114);
      drawBorder(10, 243, 108, 114);
      refreshAllScreen();
      break;
    case ROCKET:
      undergroundOptionSelected_dword_461278 = SPIKES;
      drawBlackMarketElement1();
      drawBorder2(218, 243, 0x6Cu, 114);
      drawBorder(114, 243, 108, 114);
      refreshAllScreen();
      break;
    case SABOTAGE:
      undergroundOptionSelected_dword_461278 = ROCKET;
      drawBlackMarketElement2();
      drawBorder2(322, 243, 0x6Cu, 114);
      drawBorder(218, 243, 108, 114);
      refreshAllScreen();
      break;
    case CONTINUE:
      undergroundOptionSelected_dword_461278 = SABOTAGE;
      drawBlackMarketElement3();
      drawBorder2(426, 243, 0x6Cu, 114);
      drawBorder(322, 243, 108, 114);
      refreshAllScreen();
      break;
    default:
      return;
  }
}
// 445198: using guessed type int dword_445198;
// 45DC18: using guessed type int configuration.effectsVolume;
// 461278: using guessed type int undergroundOptionSelected_dword_461278;

//----- (00423590) --------------------------------------------------------
void underGroundMenuRight()
{
  if ( undergroundOptionSelected_dword_461278 < 5 )
    loadMenuSoundEffect(1u, 26, 0, configuration.effectsVolume, dword_445198);
  switch ( undergroundOptionSelected_dword_461278 )
  {
    case MINES:
      undergroundOptionSelected_dword_461278 = SPIKES;
      drawBlackMarketElement1();
      drawBorder2(10, 243, 0x6Cu, 114);
      drawBorder(114, 243, 108, 114);
      refreshAllScreen();
      break;
    case SPIKES:
      undergroundOptionSelected_dword_461278 = ROCKET;
      drawBlackMarketElement2();
      drawBorder2(114, 243, 0x6Cu, 114);
      drawBorder(218, 243, 108, 114);
      refreshAllScreen();
      break;
    case ROCKET:
      undergroundOptionSelected_dword_461278 = SABOTAGE;
      drawBlackMarketElement3();
      drawBorder2(218, 243, 0x6Cu, 114);
      drawBorder(322, 243, 108, 114);
      refreshAllScreen();
      break;
    case SABOTAGE:
      undergroundOptionSelected_dword_461278 = SABOTAGE;
      drawBlackMarketContinue();
      drawBorder2(322, 243, 0x6Cu, 114);
      drawBorder(426, 243, 108, 114);
      refreshAllScreen();
      break;
    default:
      return;
  }
}

//----- (004236D0) --------------------------------------------------------
int reInitUnderGroundMarketStock()
{
//  signed int v1; // edx@3
 // int v2; // ecx@3
	 int maxDriverPoints = getMaxDriverPoints(driverId);
  minesAvailable_45EFF0 = 1;
  spikesAvailable_45EFF4 = 1;
  rocketAvailable_45EFF8 = 1;
  if ( isMultiplayerGame )
  {
    minesAvailable_45EFF0 = 1;
    spikesAvailable_45EFF4 = 1;
    rocketAvailable_45EFF8 = 1;
  }
 
 

  if ( !isMultiplayerGame && drivers[driverId].points > maxDriverPoints || (sabotageAvailable_45EFFC = 1, isMultiplayerGame) )
    sabotageAvailable_45EFFC = 0;
  return maxDriverPoints;
}

//----- (004237A0) --------------------------------------------------------
int drawBlackMarketScreen()
{
  void *v1; // [sp-8h] [bp-10h]@2
  int v2; // [sp+4h] [bp-4h]@2

  memcpy((char *)screenBuffer + 58880, (char *)graphicsGeneral.menubg5Bpk + 58880, 0x2A580u);
  if ( isMultiplayerGame )
  {
    v2 = (int)((char *)screenBuffer + 58880);
    v1 = blacktx2Bpk;
  }
  else
  {
    v2 = (int)((char *)screenBuffer + 58880);
    v1 = blacktx1Bpk;
  }
  drawImageWithPosition((int)v1, 640, 16, v2);
  drawCarRightSide();
  drawImageWithPosition2((int)dealer2bBpk, 96, 96, (int)((char *)screenBuffer + 80016));
  drawImageWithPosition2((int)bases45Bpk, 96, 96, (int)((char *)screenBuffer + 162352));
  drawBlackMarketElement0();
  drawBlackMarketElement1();
  drawBlackMarketElement2();
  drawBlackMarketElement3();
  return drawBlackMarketContinue();
}

//----- (004360B0) --------------------------------------------------------
void  underGroundMenuEnter(void *this)
{
  int v1; // eax@1
  int v2; // esi@1
  char v3; // bl@1
//  int v4; // eax@6
  int v5; // ebx@19
  int v6; // edi@19
  int v7; // ebp@20
  int v8; // esi@21
  int v9; // eax@32
  int v10; // edx@36
  int v11; // edx@44
//  int v12; // edx@53
//  int *v13; // eax@53
//  signed int v14; // edi@53
  void *v15; // [sp+0h] [bp-4h]@1

  v15 = this;
  v1 = driverId;
  v2 = 0;
  v3 = 5 - drivers[driverId].carType;
  if ( !drivers[driverId].carType)
    v3 = 4;
  switch ( undergroundOptionSelected_dword_461278 )
  {
    case LOANSHARK:
      if (drivers[driverId].loanRaces == -1 )
      {
        if (  drivers[driverId].carType )
        {
          loadMenuSoundEffect(1u, 29, 0, configuration.effectsVolume, dword_4451A4);
          
		  drivers[driverId].loanRaces = 1;
		  drivers[driverId].loanType = (unsigned __int8)v3;
          if ( v3 )
          {
            switch ( v3 )
            {
              case 1:
				  drivers[driverId].money += 9000;
                loadAcceptedText();
                break;
              case 2:
				  drivers[driverId].money += 6000;
                loadAcceptedText();
                break;
              case 3:
				  drivers[driverId].money += 3000;
                loadAcceptedText();
                break;
              default:
                if ( v3 == 4 )
					drivers[driverId].money += 1500;
                loadAcceptedText();
                break;
            }
          }
          else
          {
			  drivers[driverId].money += 12000;
            loadAcceptedText();
          }
          goto LABEL_48;
        }
        if ( !drivers[driverId].carType)
        {
          loadMenuSoundEffect(2u, 23, 0, configuration.effectsVolume, dword_44518C);
          framesToWaitAfterBuy_456B70 = 310;
          loanDeniedVagabondPopUp();
          refreshAllScreen();
        }
      }
      v5 =  driverId;
      v6 = drivers[driverId].loanRaces;
      if ( v6 != -1 )
      {
        v7 = drivers[driverId].loanType;
        if ( v7 )
          v8 = (int)v15;
        else
          v8 = (unsigned __int64)((double)(v6 - 1) * 0.3333333333333333 * 6000.0 + 12000.0);
        if ( v7 == 1 )
          v8 = (unsigned __int64)((double)(v6 - 1) * 0.3333333333333333 * 4500.0 + 9000.0);
        if ( v7 == 2 )
          v8 = (unsigned __int64)((double)(v6 - 1) * 0.3333333333333333 * 3000.0 + 6000.0);
        if ( v7 == 3 )
          v8 = (unsigned __int64)((double)(v6 - 1) * 0.3333333333333333 * 1500.0 + 3000.0);
        if ( v7 == 4 )
          v8 = (unsigned __int64)((double)(v6 - 1) * 0.3333333333333333 * 750.0 + 1500.0);
        if (drivers[driverId].money < v8 )
        {
			//SOUND RISA
          loadMenuSoundEffect(2u, 23, 0, configuration.effectsVolume, dword_44518C);
        }
        else
        {
          loadMenuSoundEffect(1u, 29, 0, configuration.effectsVolume, dword_4451A4);
          v9 = driverId;
		  drivers[driverId].money -= v8;
		  drivers[driverId].loanRaces = -1;
		  drivers[driverId].loanType = NO_LOAN;
          framesToWaitAfterBuy_456B70 = 310;
          loanReturnPopup_422D80();
          drawCarRightSide();
          refreshAllScreen();
        }
      }
      return;
    case MINES:
      if ( minesAvailable_45EFF0 != 1 || hasInsuficientMoneyToBuy(minesCost_462D40) )
        goto LABEL_37;
      loadMenuSoundEffect(1u, 28, 0, configuration.effectsVolume, dword_4451A0);
      v10 = drivers[driverId].money - minesCost_462D40;
      minesAvailable_45EFF0 = 0;
	  drivers[driverId].money = v10;
      drawBlackMarketElement0();
      drivers[driverId].mines = 8;
      getBlackMarketElementPurchasedText(0);
      goto LABEL_48;
    case SPIKES:
      if ( spikesAvailable_45EFF4 != 1 || hasInsuficientMoneyToBuy(spikesCost_dword_462D44) )
        goto LABEL_41;
      loadMenuSoundEffect(1u, 28, 0, configuration.effectsVolume, dword_4451A0);
      spikesAvailable_45EFF4 = 0;
	  drivers[driverId].money -= spikesCost_dword_462D44;
      drawBlackMarketElement1();
	  drivers[driverId].spikes = 1;
      getBlackMarketElementPurchasedText(1);
      goto LABEL_48;
    case ROCKET:
      if ( rocketAvailable_45EFF8 != 1 || hasInsuficientMoneyToBuy(rocketCost_462D48) )
      {
LABEL_37:
        loadMenuSoundEffect(2u, 23, 0, configuration.effectsVolume, dword_44518C);
        return;
      }
      loadMenuSoundEffect(1u, 28, 0, configuration.effectsVolume, dword_4451A0);
      v11 = drivers[driverId].money - rocketCost_462D48;
      rocketAvailable_45EFF8 = 0;
	  drivers[driverId].money = v11;
      drawBlackMarketElement2();
      drivers[driverId].rocket = 1;
      getBlackMarketElementPurchasedText(2);
      goto LABEL_48;
    case SABOTAGE:
      if ( sabotageAvailable_45EFFC != 1 || hasInsuficientMoneyToBuy(sabotageCost_462D4C) )
      {
LABEL_41:
        loadMenuSoundEffect(2u, 23, 0, configuration.effectsVolume, dword_44518C);
      }
      else
      {
        loadMenuSoundEffect(1u, 28, 0, configuration.effectsVolume, dword_4451A0);
        sabotageAvailable_45EFFC = 0;
		drivers[driverId].money -= sabotageCost_462D4C;
        drawBlackMarketElement3();
        drivers[driverId].sabotage = 1;
        getBlackMarketElementPurchasedText(3);
LABEL_48:
        framesToWaitAfterBuy_456B70 = 310;
        drawCarRightSide();
        refreshAllScreen();
      }
      return;
    case CONTINUE:
      if ( drivers[driverId].damage == 100 )
      {
        createPopup(144, 114, 384, 119, 1);
        writeTextInScreen("[Repair your car first.", 79530);
        writeTextInScreen((const char *)&unk_444160, 89770);
        writeTextInScreen("What'cha gonna do with that pile of", 100010);
        writeTextInScreen("junk, carry it around? Let me spell", 110250);
        writeTextInScreen("this to you: R-E-P-A-I-R.", 120490);
        refreshAllScreen();
        loadMenuSoundEffect(2u, 23, 0, configuration.effectsVolume, dword_44518C);
      }
      else
      {
        loadMenuSoundEffect(1u, 24, 0, configuration.effectsVolume, dword_445190);
        if ( isMultiplayerGame )
        {
          previewRaceScreen(raceDrivers_456758);
        }
        else
        {
		  //este calculo es para sacar que tienes el que mas puntos
          /*v12 = 0;
          v13 = dword_460884;
          v14 = 20;
          do
          {
            if ( *v13 > v2 && v12 != driverId )
              v2 = *v13;
            ++v12;
            v13 += 27;
            --v14;
          }
          while ( v14 );*/
          if (drivers[driverId].rank > 1 )
            selectRaceScreen();
          else
            adversaryPreviewScreen((const char **)(108 * driverId));
        }
        undergroundOptionSelected_dword_461278 = 4;
        dword_456B58 = 1;
      }
      return;
    default:
      return;
  }
}

//----- (00436700) --------------------------------------------------------
void enterBlackMarketScreen()
{
//  int v0; // eax@1
//  signed int v1; // edx@1
  int v2; // ecx@1
  int v3; // edi@21
  signed int v4; // ebp@21
  int v5; // eax@23
  int i; // ecx@23
//  bool v7; // zf@25
//  bool v8; // sf@25
///  unsigned __int8 v9; // of@25
  unsigned __int8 v10; // bl@27
  signed int v11; // esi@27
  int v12; // ST3C_4@28
  int v13; // ST38_4@28
  int v14; // eax@28
  unsigned __int8 v15; // bl@29
  signed int v16; // esi@29
  int v17; // ST3C_4@30
  int v18; // ST38_4@30
  int v19; // eax@30
  signed int v20; // ebp@32
  int v21; // edi@35
  int v22; // eax@38
  int j; // ecx@38
  unsigned __int8 v24; // bl@45
  signed int v25; // esi@45
  int v26; // ST3C_4@46
  int v27; // ST38_4@46
  int v28; // eax@46
  unsigned __int8 v29; // bl@47
  signed int v30; // esi@47
  int v31; // ST3C_4@48
  int v32; // ST38_4@48
  int v33; // eax@48
  unsigned __int8 v34; // si@52
  int v35; // eax@54
  int v36; // eax@67
  int k; // ecx@67
  void *v38=malloc(1); // ecx@71
  signed int v39; // ebp@82
  unsigned __int8 v40; // di@83
  signed int v41; // esi@83
  int v42; // ST3C_4@84
  int v43; // ST38_4@84
  int v44; // eax@84
  int v45; // edi@114
  signed int v46; // ebp@114
  int v47; // eax@118
  int l; // ecx@118
  unsigned __int8 v49; // bl@124
  signed int v50; // esi@124
  int v51; // ST3C_4@125
  int v52; // ST38_4@125
  int v53; // eax@125
  unsigned __int8 v54; // bl@126
  signed int v55; // esi@126
  int v56; // ST3C_4@127
  int v57; // ST38_4@127
  int v58; // eax@127
  signed int v59; // [sp+10h] [bp-8h]@21
  signed int v60; // [sp+10h] [bp-8h]@35
  signed int v61; // [sp+10h] [bp-8h]@114
  signed int v62; // [sp+14h] [bp-4h]@52

 
  int maxDriverPoints = getMaxDriverPoints(driverId);
  if ( !isMultiplayerGame && drivers[driverId].points > maxDriverPoints )
    sabotageAvailable_45EFFC = 0;
  sub_4224E0();
  v59 = 50;
  v3 = 6553600;
  v4 = 65500;
  do
  {
    waitWithRefresh();
    setMusicVolume(v4);
    if ( v59 % 2 )
    {
      v5 = 0;
      for ( i = 0; i < continueAnimCurrentFrame_4611D0; ++i )
        v5 += continueAnimFramesSize_4611D0[i];
      copyImageToBuffer((int)((char *)contaniBpk + v5), (int)dword_461EA4);
      drawImageWithPosition2((int)dword_461EA4, 96, 64, (int)((char *)screenBuffer + 172592));	  
      drawKeyCursor(172592, (char *)screenBuffer + 172592, 0x60u, 64);
	  continueAnimCurrentFrame_4611D0 = continueAnimCurrentFrame_4611D0 % 2;//% 24;
    }
    v10 = 0;
    v11 =0;
	//v11 = (signed int)dword_45FC44;
    do
    {
      v12 = (convertColorToPaletteColor((palette1[v11+2]), v3) + 0x8000) >> 16;
      v13 = (convertColorToPaletteColor(palette1[v11 + 1], v3) + 0x8000) >> 16;
      v14 = convertColorToPaletteColor((palette1[v11]), v3);
      setPaletteAndGetValue(v10, (v14 + 0x8000) >> 16, v13, v12);
      v11 += 3;
      ++v10;
    }
    while ( v11 < 288 );
	//while (v11 < (signed int)&unk_4600C4);
    v15 = -128;
    v16 = 384;
	//v16 = (signed int)&unk_460244;
    do
    {
      v17 = (convertColorToPaletteColor((palette1[v16 + 2]), v3) + 0x8000) >> 16;
      v18 = (convertColorToPaletteColor((palette1[v16 + 1]), v3) + 0x8000) >> 16;
      v19 = convertColorToPaletteColor((palette1[v16]), v3);
      setPaletteAndGetValue(v15, (v19 + 0x8000) >> 16, v18, v17);
      v16 += 3;
      ++v15;
	  /* v17 = (convertColorToPaletteColor(*(_DWORD *)(v16 + 4), v3) + 0x8000) >> 16;
      v18 = (convertColorToPaletteColor(*(_DWORD *)v16, v3) + 0x8000) >> 16;
      v19 = convertColorToPaletteColor(*(_DWORD *)(v16 - 4), v3);
      setPaletteAndGetValue(v15, (v19 + 0x8000) >> 16, v18, v17);
      v16 += 3;
      ++v15;*/
    }
    while ( v16 <maxPaletteEntries );
    v4 -= 1310;
    v3 -= 0x20000;
    --v59;
  }
  while ( v4 >= 0 );
  LOWORD(dword_462D7C) = sub_43C1F0() & 0xFF00;
  dword_462D7C = (unsigned __int16)dword_462D7C;
  musicSetOrder(12544);
  undergroundOptionSelected_dword_461278 = 5;
  drawBlackMarketScreen();
  v20 = 0;
  if ( showUndergroundPopup_456B78 || (drawBorder(426, 243, 108, 114), showUndergroundPopup_456B78) )
    undergroundMarketPopup();
  refreshAllScreen();
  sub_4224E0();
  v60 = 0;
  v21 = 0;
  do
  {
    waitWithRefresh();
    setMusicVolume(v20);
    if ( v60 % 2 && !showUndergroundPopup_456B78 )
    {
      v22 = 0;
      for ( j = 0; j < continueAnimCurrentFrame_4611D0; ++j )
        v22 += continueAnimFramesSize_4611D0[j];
      copyImageToBuffer((int)((char *)contaniBpk + v22), (int)dword_461EA4);
      drawImageWithPosition2((int)dword_461EA4, 96, 64, (int)((char *)screenBuffer + 172592));
      drawKeyCursor(172592, (char *)screenBuffer + 172592, 0x60u, 64);
	  continueAnimCurrentFrame_4611D0 = continueAnimCurrentFrame_4611D0 % 24;
    }
    if ( v60 % 2 && showUndergroundPopup_456B78 )
      drawCursor(164, 321);
    v24 = 0;
    //v25 = (signed int)dword_45FC44;
	v25 = 0;
    do
    {
      v26 = (convertColorToPaletteColor((palette1[v25+2]), v21) + 0x8000) >> 16;
      v27 = (convertColorToPaletteColor(palette1[v25 + 1], v21) + 0x8000) >> 16;
      v28 = convertColorToPaletteColor((palette1[v25 ]), v21);
      setPaletteAndGetValue(v24, (v28 + 0x8000) >> 16, v27, v26);
      v25 += 3;
      ++v24;
    }
    while ( v25 < 289 );
	//while (v25 < (signed int)&unk_4600C4);
    v29 = -128;
	v30 = 384;
	//v30 = (signed int)&unk_460244;
    do
    {
      v31 = (convertColorToPaletteColor((palette1[v30 + 2]), v21) + 0x8000) >> 16;
      v32 = (convertColorToPaletteColor((palette1[v30 + 1]), v21) + 0x8000) >> 16;
      v33 = convertColorToPaletteColor((palette1[v30]), v21);
      setPaletteAndGetValue(v29, (v33 + 0x8000) >> 16, v32, v31);
      v30 += 3;
      ++v29;
	  /*v31 = (convertColorToPaletteColor(*(_DWORD *)(v30 + 4), v21) + 0x8000) >> 16;
      v32 = (convertColorToPaletteColor(*(_DWORD *)v30, v21) + 0x8000) >> 16;
      v33 = convertColorToPaletteColor(*(_DWORD *)(v30 - 4), v21);
      setPaletteAndGetValue(v29, (v33 + 0x8000) >> 16, v32, v31);
      v30 += 12;
      ++v29;*/
    }
    while ( v30 < maxPaletteEntries );
    v20 += 1310;
    v21 += 0x20000;
    ++v60;
  }
  while ( v20 < 65500 );
  if ( showUndergroundPopup_456B78 )
  {
    drawPopupCursor_42C780 ();
    showUndergroundPopup_456B78 = 0;
    drawBlackMarketScreen();
    drawBorder(426, 243, 108, 114);
    refreshAllScreen();
  }
  v62 = 0;
  v34 = 1;
  while ( !dword_456B58 )
  {
    refreshAndCheckConnection_42A570();
    refreshAndCheckConnection_42A570();
    v35 = framesToWaitAfterBuy_456B70;
    if ( framesToWaitAfterBuy_456B70 > 0 )
      v35 = framesToWaitAfterBuy_456B70-- - 1;
    switch ( undergroundOptionSelected_dword_461278 )
    {
      case LOANSHARK:
        if ( v35 == 1 )
        {
          drawLoanShark();
          refreshAllScreen();
        }
        break;
      case MINES:
        if ( v35 == 1 )
        {
          drawBlackMarketElement0();
          refreshAllScreen();
        }
        break;
      case SPIKES:
        if ( v35 == 1 )
        {
          drawBlackMarketElement1();
          refreshAllScreen();
        }
        break;
      case ROCKET:
        if ( v35 == 1 )
        {
          drawBlackMarketElement2();
          refreshAllScreen();
        }
        break;
      case SABOTAGE:
        if ( v35 == 1 )
        {
          drawBlackMarketElement3();
          refreshAllScreen();
        }
        break;
      case CONTINUE:
        v36 = 0;
        for ( k = 0; k < continueAnimCurrentFrame_4611D0; ++k )
          v36 += continueAnimFramesSize_4611D0[k];
        copyImageToBuffer((int)((char *)contaniBpk + v36), (int)dword_461EA4);
        drawImageWithPosition2((int)dword_461EA4, 96, 64, (int)((char *)screenBuffer + 172592));
        drawKeyCursor(172592, (char *)screenBuffer + 172592, 0x60u, 64);
		continueAnimCurrentFrame_4611D0 = continueAnimCurrentFrame_4611D0 % 24;
        break;
      default:
        break;
    }
    switch ( eventDetected() )
    {
      case KEY_F1:
       // if ( isMultiplayerGame )
         // multiplayer_sub_42CCF0();
        break;
      case KEY_UP:
      case 0xC8:
        if ( undergroundOptionSelected_dword_461278 == MINES )
        {
          loadMenuSoundEffect(v34, 26, 0, configuration.effectsVolume, dword_445198);
          undergroundOptionSelected_dword_461278 = LOANSHARK;
          drawLoanShark();
          drawBorder2(10, 243, 0x6Cu, 114);
          drawBorder(10, 115, 108, 114);
          refreshAllScreen();
        }
        break;
      case KEY_DOWN:
      case 0xD0:
        if ( undergroundOptionSelected_dword_461278== LOANSHARK )
        {
          loadMenuSoundEffect(v34, 26, 0, configuration.effectsVolume, dword_445198);
          undergroundOptionSelected_dword_461278 = MINES;
          drawBlackMarketElement0();
          drawBorder2(10, 115, 0x6Cu, 114);
          drawBorder(10, 243, 108, 114);
          refreshAllScreen();
        }
        break;
      case KEY_LEFT:
      case 0xCB:
        underGroundMenuLeft();
        break;
      case KEY_RIGHT:
      case 0xCD:
        underGroundMenuRight();
        break;
      case KEY_ENTER:
      case 0x9C:
        underGroundMenuEnter(v38);
        break;
      case KEY_ESCAPE:
        dword_456B60 = 1;
        v62 = -1;
        break;
      default:
        break;
    }
    v39 = autoLoadSave();
    if ( v39 > 0 )
    {
      memcpy((char *)screenBuffer + 61440, (char *)graphicsGeneral.menubg5Bpk + 61440, 0x29B80u);
      drawBlackMarketScreen();
      sub_4224E0();
      v40 = 32;
      v41 = (signed int)&unk_45FDC4;
      do
      {
        v42 = (convertColorToPaletteColor(*(_DWORD *)(v41 + 4), 6553600) + 0x8000) >> 16;
        v43 = (convertColorToPaletteColor(*(_DWORD *)v41, 6553600) + 0x8000) >> 16;
        v44 = convertColorToPaletteColor(*(_DWORD *)(v41 - 4), 6553600);
        setPaletteAndGetValue(v40, (v44 + 0x8000) >> 16, v43, v42);
        v41 += 12;
        ++v40;
      }
      while ( v41 < maxPaletteEntries );
      drawBorder2(426, 243, 0x6Cu, 114);
      drawBorder2(10, 115, 0x6Cu, 114);
      drawBorder2(10, 243, 0x6Cu, 114);
      drawBorder2(114, 243, 0x6Cu, 114);
      drawBorder2(218, 243, 0x6Cu, 114);
      drawBorder2(322, 243, 0x6Cu, 114);
      if ( undergroundOptionSelected_dword_461278 = LOANSHARK )
      {
        drawBorder(10, 115, 108, 114);
        drawLoanShark();
      }
      if ( undergroundOptionSelected_dword_461278 == MINES )
      {
        drawBorder(10, 243, 108, 114);
        drawBlackMarketElement0();
      }
      if ( undergroundOptionSelected_dword_461278 == SPIKES )
      {
        drawBorder(114, 243, 108, 114);
        drawBlackMarketElement1();
      }
      if ( undergroundOptionSelected_dword_461278 == ROCKET )
      {
        drawBorder(218, 243, 108, 114);
        drawBlackMarketElement2();
      }
      if ( undergroundOptionSelected_dword_461278 == SABOTAGE )
      {
        drawBorder(322, 243, 108, 114);
        drawBlackMarketElement3();
      }
      if ( undergroundOptionSelected_dword_461278 == CONTINUE )
      {
        drawBorder(426, 243, 108, 114);
        drawBlackMarketContinue();
      }
      drawTransparentBlock(0, 371, 639, 109);
      if ( isMultiplayerGame )
      {
        drawTextWithFont((int)graphicsGeneral.fsma3bBpk, (int)&letterSpacing_4458B0, "press   to enter chat mode", 233635);
        drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, "F1", 233689);
      }
      drawBottomMenuText();
      refreshAllScreen();
      memcpy(dword_461ED8, screenBuffer, 0x4B000u);
      switch ( v39 )
      {
        case 1:
          confirmationPopup("Game Saved.");
          break;
        case 2:
          confirmationPopup("Game Loaded.");
          break;
        case 3:
          confirmationPopup("Game not found.");
          break;
      }
      memcpy(screenBuffer, dword_461ED8, 0x4B000u);
      refreshAllScreen();
      v34 = 1;
    }
    if ( isMultiplayerGame && dword_456B9C )
    {
      v62 = -1;
      break;
    }
    if ( v62 )
      break;
  }
  dword_456B58 = 1;
  if ( dword_456B9C )
  {
    dword_456B6C = 1;
    return;
  }
  if ( !dword_456B64 )
  {
    sub_4224E0();
    v61 = 50;
    v45 = 6553600;
    v46 = 65500;
    do
    {
      waitWithRefresh();
      if ( v61 % 2 && undergroundOptionSelected_dword_461278 == CONTINUE )
      {
        if ( v62 != -1 )
          goto LABEL_124;
        v47 = 0;
        for ( l = 0; l < continueAnimCurrentFrame_4611D0; ++l )
          v47 += continueAnimFramesSize_4611D0[l];
        copyImageToBuffer((int)((char *)contaniBpk + v47), (int)dword_461EA4);
        drawImageWithPosition2((int)dword_461EA4, 96, 64, (int)((char *)screenBuffer + 172592));
        drawKeyCursor(172592, (char *)screenBuffer + 172592, 0x60u, 64);
		continueAnimCurrentFrame_4611D0 = continueAnimCurrentFrame_4611D0 % 24;
      }
      else if ( v62 != -1 )
      {
        goto LABEL_124;
      }
      setMusicVolume(v46);
LABEL_124:
      v49 = 0;
      v50 = 0;
	  //v50 = (signed int)dword_45FC44;
      do
      {
        v51 = (convertColorToPaletteColor((palette1[v50+2]), v45) + 0x8000) >> 16;
        v52 = (convertColorToPaletteColor(palette1[v50 + 1], v45) + 0x8000) >> 16;
        v53 = convertColorToPaletteColor((palette1[v50 ]), v45);
        setPaletteAndGetValue(v49, (v53 + 0x8000) >> 16, v52, v51);
        v50 += 3;
        ++v49;
      }
      while ( v50 < 289 );
	  //while (v50 < (signed int)&unk_4600C4);
      v54 = -128;
	  //v55 = (signed int)&unk_460244;
      v55 = 384;
      do
      {
        v56 = (convertColorToPaletteColor((palette1[v55 + 2]), v45) + 0x8000) >> 16;
        v57 = (convertColorToPaletteColor((palette1[v55 + 1]), v45) + 0x8000) >> 16;
        v58 = convertColorToPaletteColor((palette1[v55 ]), v45);
        setPaletteAndGetValue(v54, (v58 + 0x8000) >> 16, v57, v56);
        v55 += 3;
        ++v54;
      }
      while ( v55 < maxPaletteEntries );
      v46 -= 1310;
      v45 -= 0x20000;
      --v61;
    }
    while ( v46 >= 0 );
  }
}

