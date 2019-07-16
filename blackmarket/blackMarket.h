typedef enum
{
	LOANSHARK = 0,
	MINES = 1,
	SPIKES = 2,
	ROCKET = 3,
	SABOTAGE = 4

}UnderGroundMenu;

int __cdecl getBlackMarketElementText(int a1);
int __cdecl getBlackMarketElementPurchasedText(int a1);
int outOfStockPopup_422930();
int blackMarketSharewarePopup_4229B0();
int drawLoanShark();
int loanDeniedVagabondPopUp();
int loanReturnPopup_422D80();
int drawBlackMarketElement0();
int drawBlackMarketElement1();
int drawBlackMarketElement2();
int drawBlackMarketElement3();
int drawBlackMarketContinue();
void underGroundMenuLeft();
void underGroundMenuRight();
int reInitUnderGroundMarketStock(void); // weak
int drawBlackMarketScreen();
int loadAcceptedText();
void  underGroundMenuEnter(void *);
signed int setUndergroundMarketPrices();


void enterBlackMarketScreen();


extern int minesAvailable_45EFF0; // weak
extern int spikesAvailable_45EFF4; // weak
extern int rocketAvailable_45EFF8; // weak
extern int sabotageAvailable_45EFFC; // weak

extern int minesCost_462D40; // idb
extern int spikesCost_dword_462D44; // idb
extern int rocketCost_462D48; // idb
extern int sabotageCost_462D4C; // idb
extern int undergroundOptionSelected_dword_461278; // weak