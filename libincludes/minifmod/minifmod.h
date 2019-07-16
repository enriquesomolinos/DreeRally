/******************************************************************************/
/* MINIFMOD.H                                                                 */
/* ----------------                                                           */
/* MiniFMOD public source code release.                                       */
/* This source is provided as-is.  Firelight Technologies will not support    */
/* or answer questions about the source provided.                             */
/* MiniFMOD Sourcecode is copyright (c) Firelight Technologies, 2000-2004.    */
/* MiniFMOD Sourcecode is in no way representative of FMOD 3 source.          */
/* Firelight Technologies is a registered company name.                       */
/* This source must not be redistributed without this notice.                 */
/******************************************************************************/

//==========================================================================================
// MINIFMOD Main header file. Copyright (c), Firelight Technologies, 2000-2004.
// Based on FMOD, copyright (c), Firelight Technologies, 2000-2004.
//==========================================================================================

#ifndef _MINIFMOD_H_
#define _MINIFMOD_H_

//===============================================================================================
//= DEFINITIONS
//===============================================================================================

// fmod defined types
typedef struct FMUSIC_MODULE	FMUSIC_MODULE;

//===============================================================================================
//= FUNCTION PROTOTYPES
//===============================================================================================

#ifdef __cplusplus
extern "C" {
#endif

char _fltused;	// for POLINK ;)


// ==================================
// Initialization / Global functions.
// ==================================
typedef void (*SAMPLELOADCALLBACK)(void *buff, int lenbytes, int numbits, int instno, int sampno);
typedef void (*FMUSIC_CALLBACK)(FMUSIC_MODULE *mod, unsigned char param);

// this must be called before FSOUND_Init!
extern void PB_FSOUND_File_SetCallbacks(unsigned int	(*OpenCallback)(char *name),
                              void			(*CloseCallback)(unsigned int handle),
                              int			(*ReadCallback)(void *buffer, int size, unsigned int handle),
                              void			(*SeekCallback)(unsigned int handle, int pos, signed char mode),
                              int			(*TellCallback)(unsigned int handle));

// =============================================================================================
// FMUSIC API
// =============================================================================================

// Song management / playback functions.
// =====================================

extern FMUSIC_MODULE *  PB_FMUSIC_LoadSong(char *data, SAMPLELOADCALLBACK sampleloadcallback);
extern signed char		PB_FMUSIC_FreeSong(FMUSIC_MODULE *mod);
extern signed char		PB_FMUSIC_PlaySong(FMUSIC_MODULE *mod);
extern signed char		PB_FMUSIC_StopSong(FMUSIC_MODULE *mod);

// Runtime song information.
// =========================

extern int				PB_FMUSIC_GetOrder(FMUSIC_MODULE *mod);
extern int				PB_FMUSIC_GetRow(FMUSIC_MODULE *mod);
extern unsigned int		PB_FMUSIC_GetTime(FMUSIC_MODULE *mod);
  
#ifdef __cplusplus
}
#endif

#endif
