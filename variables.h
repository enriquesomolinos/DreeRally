/*void memset32(void *buf, uint32_t n, int32_t c)
{
  __asm {
  mov ecx, n
  mov eax, c
  mov edi, buf
  rep stosd
  }
}*/

typedef enum
{
	KEY_ESCAPE = 0x1,
	KEY_TAB = 15,
	KEY_Y = 21,
	KEY_P = 25,
	KEY_ENTER = 0x1C,
	KEY_N = 49,
	KEY_F1 = 59,
	KEY_F2 = 60,
	KEY_F3 = 61,
	KEY_F4 = 62,
	KEY_F5 = 63,
	KEY_UP = 0x48,
	KEY_LEFT = 0x4B,	
	KEY_RIGHT = 0x4D,
	KEY_DOWN = 0x50,
	KEY_F6 = 64,
	KEY_F12 = 88,	//SDLK_F12 cambiar a esto
	KEY_ESPACE = 0x39
	
	
}Keys;

typedef enum
{
	IN_RACE_ACELERATE = 0x1,
	IN_RACE_BRAKE = 0x2,
	IN_RACE_LEFT = 0x4,
	IN_RACE_RIGHT = 0x8,
	IN_RACE_TURBO = 0x10,
	IN_RACE_GUN = 0x20,
	IN_RACE_MINE = 0x40,
	IN_RACE_HORN = 0x42,
	IN_RACE_BRAKE_MINE = 0xFD
	
}InRaceKeys;


