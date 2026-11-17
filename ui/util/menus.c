#include "menus.h"
#include "../../util.h"
#include "../../savegame.h"
#include "../../i18n/i18n.h"

#include "../../config.h"
#include "keyNames.h"
#include "menuTexts.h"

#include <stdio.h>
#include <string.h>

extern char unk_462DA0[];
extern char unk_45EAC0[];
extern char aGamepadDisable[];

char * menu0[] = { "Start Racing", "Multiplayer Race", "Configure","See hall of fame","Credits","Exit to os" };
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
//Primeras opciones de los menus principal y de partida. En el original son un unico texto que
//se sobrescribe al empezar o cargar una partida ("Continue Racing" / "Enter The Shop") y se
//restaura al terminarla; el port tenia una copia por archivo y el menu nunca veia el cambio.
char menuaStartANewGam_0[17] = "Start A New Game";
char menuaStartRacing[16] = "Start Racing";

//Opciones de los menus de teclado y joystick. El original muestra su linea de 50 bytes: etiqueta,
//relleno y el nombre de la tecla que arma sub_41CA40 (el port solo mostraba la etiqueta). Con
//la etiqueta traducida no sirve el relleno del original: etiqueta traducida y tecla.
static char *keyMenuText(int menu, int position, char **labels, int keys) {
	static char line[MENU_TEXT_SIZE + KEY_NAME_SIZE];
	int keyboard[] = { configuration.accelerateKey, configuration.brakeKey, configuration.leftSteeringKey,
		configuration.rightSteeringKey, configuration.turboKey, configuration.gunKey, configuration.mineKey,
		configuration.hornKey };
	int gamepad[] = { configuration.accelerateGamepad, configuration.brakeGamepad,
		configuration.leftSteeringGamepad, configuration.rightSteeringGamepad, configuration.turboGamepad,
		configuration.gunGamepad, configuration.mineGamepad };
	char *label = getLanguageEntry(labels[position]);

	if (position >= keys)
		return label;
	if (label == labels[position])
		return MENU_TEXT(menu, position);
	snprintf(line, sizeof(line), "%s  %s", label, menu == DEFINE_KEYBOARD_MENU
		? unk_462DA0 + KEY_NAME_SIZE * keyboard[position] : unk_45EAC0 + KEY_NAME_SIZE * gamepad[position]);
	return line;
}

char* getMenuText(int menu, int position) {
	
	switch (menu)
	{
	default:
		break;
	case INITIAL_MENU://menu principal
		if (position == 0 && strcmp(menuaStartRacing, "Start Racing"))
			return getLanguageEntry(menuaStartRacing);
		return getLanguageEntry(menu0[position]);
		break;

	case START_NEW_GAME_MENU://
		if (position == 0 && strcmp(menuaStartANewGam_0, "Start A New Game"))
			return getLanguageEntry(menuaStartANewGam_0);
		return getLanguageEntry(menu1[position]);
		break;
	
	case CONFIGURE_MENU://
		//La opcion 4 la reescribe el menu al activar o desactivar el joystick.
		if (position == 4)
			return getLanguageEntry(aGamepadDisable);
		return getLanguageEntry(menu3[position]);
		break;
	case LOAD_MENU://
		
		if (position == 8) {
			return getLanguageEntry(menu5[position]);
		}
		else {
			if (getSaveGameName(position) != NULL) {
				return getSaveGameName(position);
			}else return getLanguageEntry(menu5[position]);

		}
		
		break;
	case DEFINE_KEYBOARD_MENU://
		return keyMenuText(menu, position, menu6, 8);
	case DEFINE_GAMEPAD_MENU://
		return keyMenuText(menu, position, menu8, 7);
	}
	return "";
	

}