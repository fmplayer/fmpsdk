/*******************************************************************************
	File:		fmPlayer.h

	Contains:	yy media engine define header file.

	Written by:	Fenger King

	Change History (most recent first):
	2016-12-18		Fenger			Create file

*******************************************************************************/
#ifndef __fmPlayer_h__
#define __fmPlayer_h__
#include "fmpDef.h"
#include "fmpType.h"
#include "fmpErr.h"
#include "fmpMsg.h"
#include "fmpData.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef enum FMP_PLAY_State {
	FMP_PLAY_None		= 0,
	FMP_PLAY_Init		= 1,
	FMP_PLAY_Open		= 2,		
	FMP_PLAY_Opening	= 3,
	FMP_PLAY_Pause		= 4,
	FMP_PLAY_Play		= 5,
	FMP_PLAY_Stop		= 6,
	FMP_PLAY_Close		= 7,
	FMP_PLAY_Uninit		= 8,
	FMP_PLAY_Max		= 0X7FFFFFFF
} FMPLAY_STATUS;

// the flag for open source
#define	FMPLAY_OPEN_SAME_SOURCE				0X01000000
#define	FMPLAY_OPEN_SAME_VIDEO				0X02000000
#define	FMPLAY_OPEN_SAVE_FILE				0X04000000
#define	FMPLAY_OPEN_MEM_SOURCE				0X08000000

#define	FMPLAY_OPEN_VIDDEC_HW				0X10000000
#define	FMPLAY_OPEN_AUDDEC_HW				0X20000000

#define	FMPLAY_OPEN_GET_THUMB				0X80000000

// Call back function of player notify event
typedef void (FMP_API * FMPPlayerNotifyEvent) (void * pUserData, fmpMsgInfo * pMsgInfo);

/**
 * the yy media player interface 
 * The parameter void * hPlayer should be FMP_Player which was created from yyMediaCreate
 */
typedef struct {
	// Define the version of the player.
	int				nVersion;
	// The player engine handle.
	void *			hPlayer;
	// It will recieve the message if you set the notify function.
	int				(* SetNotify)	(void * hPlayer, FMPPlayerNotifyEvent pFunc, void * pUserData);
	// This function must call before open.
	int				(* SetView)		(void * hPlayer, void * hView, RECT * pRect);
	// Open the source. The format should be 0, the player will auto detect the format.
	int 			(* Open)		(void * hPlayer, const char * pURL, int nFlag, long long llStartPos);
	// Close the source to release the resource
	int 			(* Close)		(void * hPlayer);
	int 			(* Run)			(void * hPlayer);
	int 			(* Pause)		(void * hPlayer);
	int 			(* Stop)		(void * hPlayer);
	FMPLAY_STATUS	(* GetStatus)	(void * hPlayer);
	// The time is ms.
	long long		(* GetDur)		(void * hPlayer);
	long long		(* GetPos)		(void * hPlayer);
	long long		(* SetPos)		(void * hPlayer, long long llPos);
	// The volume 100 is orignal volume. 0-99 is low, > 100 is loud.
	int				(* SetVolume)	(void * hPlayer, int nVolume);
	int				(* GetVolume)	(void * hPlayer);
	// for extend function later.
	int 			(* GetParam)	(void * hPlayer, int nID, void * pParam);
	int 			(* SetParam)	(void * hPlayer, int nID, int nParam, long long llParam, void * pParam);
} FMP_Player;

DLLEXPORT_C int FMP_API fmpCreatePlayer(FMP_Player * fPlayer, void * hInst);
typedef int (FMP_API FMPCREATEPLAYER) (FMP_Player * fPlayer, void * hInst);

DLLEXPORT_C int FMP_API fmpDestroyPlayer(FMP_Player * fPlayer);
typedef int (FMP_API FMPDESTROYPLAYER) (FMP_Player * fPlayer);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif // __fmPlayer_h__
