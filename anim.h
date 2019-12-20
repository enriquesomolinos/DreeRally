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
	
} ShopMessages;


ShopMessages initShopMessages();