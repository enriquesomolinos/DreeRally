#ifndef ANIM_H
#define ANIM_H

typedef struct Message {
	char* title;
	char* line1;
	char* line2;
	char* line3;

} Message;

typedef struct ElementMessage {
	Message infoMessage;
	Message boughMessage;

} ElementMessage;


typedef struct ShopMessages{
	ElementMessage carMessage[6];
	ElementMessage carMessageNoWeapons[6];	
	ElementMessage engineMessage[4];
	Message engineMessageNoMoreUpgrades;
	ElementMessage tireMessage[4];
	Message tireMessageNoMoreUpgrades;	
	ElementMessage armorMessage[4];
	Message armorMessageNoMoreUpgrades;
	Message repairMessage[11];
	Message continueMessage;
	Message continueMessageNoWeapons;
	ElementMessage sabotageMessage[1];
	ElementMessage rocketMessage[1];
	ElementMessage spikesMessage[1];
	ElementMessage minesMessage[1];
	Message outOfStockMessage;

	
} ShopMessages;




ShopMessages initShopMessages();


int   drawMenuAnimation(int x, int y, int frame, int animation, int frameSizes[]);
int reloadContinueAnimation();
int reloadEngineAnimation();
int reloadTireAnimation();
int reloadArmourAnimation();
int reloadCarAnimation2();
int reloadEngineAnimation2();
int reloadTireAnimation2();
int reloadArmourAnimation2();
int reloadRepairAnimation();

extern int carAnimFrameSize_45FBA0[6*64];
extern int engineAnimFrameSize_445F68[];
extern int tireAnimFrameSize_4460E8[];
extern int armourAnimFrameSize_4461A8[];
extern int continueAnimFramesSize_4611D0[];
extern int repairAnimFrameSize_446308[];

extern int repairAnimCurrentFrame_45EEAC; // weak

extern int tireAnimCurrentFrame_45F034; // weak
extern int carAnimCurrentFrame_45FBA0; // weak
extern int continueAnimCurrentFrame_4611D0; // weak
extern int armourAnimCurrentFrame_461288; // weak

extern int engineAnimCurrentFrame_462D80; // weak
extern int armourAnimFrameDirection_45F034;

#endif