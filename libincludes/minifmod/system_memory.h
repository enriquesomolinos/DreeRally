/******************************************************************************/
/* SYSTEM_MEMORY.H                                                            */
/* ----------------                                                           */
/* MiniFMOD public source code release.                                       */
/* This source is provided as-is.  Firelight Technologies will not support    */
/* or answer questions about the source provided.                             */
/* MiniFMOD Sourcecode is copyright (c) Firelight Technologies, 2000-2004.    */
/* MiniFMOD Sourcecode is in no way representative of FMOD 3 source.          */
/* Firelight Technologies is a registered company.                            */
/* This source must not be redistributed without this notice.                 */
/******************************************************************************/

#ifndef _SYSTEM_MEMORY_H_
#define _SYSTEM_MEMORY_H_

// include your system's header here
#include <stdlib.h>

// redefine here
#define FSOUND_Memory_Free(_ptr)			free(_ptr)
#define FSOUND_Memory_Alloc(_len)			calloc(_len, 1)
#define FSOUND_Memory_Calloc(_len)			calloc(_len, 1)
#define FSOUND_Memory_Realloc(_ptr, _len)	realloc(_ptr, _len)

#endif
