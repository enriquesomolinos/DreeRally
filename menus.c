#include "menus.h"
#include "util.h"
#include "savegame.h"

#include <stdio.h>

char * menu0[] = { "Start Racing", "Multiplayer Race", "Configure","See hall of fame","Credits","Exit to OS" };
char * menu1[] = { "Start a new game", "End current Game", "See current Stadistics","Load game","save game","Previous menu" };


char * menu3[] = { "Music volume", "Effect volume", "define Keyboard","Define Gamepad/Joystick","Gamepad/Joystick Disabled","Previous menu" };


char * menu5[] = { "Empty slot", "Empty slot", "Empty slot","Empty slot","Empty slot","Empty slot","Empty slot","Quicksave slot" };

char * menu6[] = { "Accelerate", "Brake", "Steer Left","Steer right","Turbo boost","Machine Gun","Drop Mine","Horn","Previous menu" };

char * menu8[] = { "Accelerate", "Brake", "Steer Left","Steer right","Turbo boost","Machine Gun","Drop Mine","Previous menu" };


char menuActive_4457F0[] = { '\x01','\x0','\x01','\x01','\x01','\x01','\x01','\x0','\x0',
						'\x01','\x0','\x0','\x01','\x0','\x01','\x0','\x0','\x0',
						'\x0','\x0','\x01','\x01','\x1','\x01','\x1','\x1','\x0',
						'\x1','\x1','\x01','\x01','\x1','\x01','\x0','\x0','\x0',
						'\x1','\x1','\x01','\x01','\x1','\x0','\x0','\x0','\x0',
						'\x1','\x1','\x01','\x01','\x1','\x1','\x1','\x1','\x0',
						'\x1','\x1','\x01','\x01','\x1','\x1','\x1','\x1','\x1',
						'\x1','\x1','\x01','\x01','\x1','\x1','\x1','\x1','\x0',
						'\x1','\x1','\x01','\x01','\x1','\x1','\x1','\x1','\x1'			}; // weak
char* getMenuText(int menu, int position) {
	
	switch (menu)
	{
	default:
		break;
	case INITIAL_MENU://menu principal
		return menu0[position];
		break;

	case START_NEW_GAME_MENU://
		return menu1[position];
		break;
	
	case CONFIGURE_MENU://
		return menu3[position];
		break;
	case LOAD_MENU://
		
		if (position == 8) {
			return menu5[position];
		}
		else {
			if (getSaveGameName(position) != NULL) {
				return getSaveGameName(position);
			}else return menu5[position];

		}
		
		break;
	case DEFINE_KEYBOARD_MENU://
		return menu6[position];
		break;
	case DEFINE_GAMEPAD_MENU://
		return menu8[position];
		break;
		

		
	}

}