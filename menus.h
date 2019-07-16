

typedef enum
{
	INITIAL_MENU = 0,
	START_NEW_GAME_MENU = 1,

	CONFIGURE_MENU = 3,
	LOAD_MENU = 5,
	DEFINE_KEYBOARD_MENU = 6,

	DEFINE_GAMEPAD_MENU = 8,
}Menus;


typedef enum
{
	START_CONTINUE_GAME = 0,
	END_CURRENT_GAME = 1,
	SEE_STADISTICS = 2,
	LOAD_GAME = 3,
	SAVE_GAME = 4,
	PREVIOUS_MENU =5
}StartNewGameMenu;

typedef enum
{
	BUY_CAR = 0,
	BUY_ENGINE = 1,
	BUY_TIRE = 2,
	BUY_ARMOUR = 3,
	REPAIR = 4,
	CONTINUE = 5,
	
}ShopMenu;





extern char menuActive_4457F0[];
char* getMenuText(int menu, int position);