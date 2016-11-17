void memset32(void *buf, uint32_t n, int32_t c)
{
  __asm {
  mov ecx, n
  mov eax, c
  mov edi, buf
  rep stosd
  }
}


typedef enum
{
	KEY_DOWN = 0x50,
	KEY_UP = 0x48,
	KEY_LEFT = 0x4B,
	KEY_RIGHT = 0x4D,
	KEY_ENTER = 0x1C,
	KEY_ESCAPE = 0x1,
	KEY_ESPACE = 0x39,
	KEY_F1 = 0x3B,
	
}Keys;

