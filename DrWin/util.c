#include <stdio.h>
#include "util.h"

//----- (00402740) --------------------------------------------------------
FILE *__cdecl fileExists(char *Filename)
{
	FILE *result; // eax@1
	FILE *v2; // esi@1
	__int32 v3; // edi@2

	result = fopen(Filename, "rb");
	v2 = result;
	if (result)
	{
		fseek(result, 0, 2);
		v3 = ftell(v2);
		fclose(v2);
		result = (FILE *)v3;
	}
	return result;
}