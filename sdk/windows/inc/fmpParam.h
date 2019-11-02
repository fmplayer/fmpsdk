/*******************************************************************************
	File:		fmpParam.h

	Contains:	fmp player type define header file.

	Written by:	Fenger King

	Change History (most recent first):
	2016-11-29		Fenger			Create file

*******************************************************************************/
#ifndef __fmpParam_H__
#define __fmpParam_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

// the video aspect ratio.
typedef struct {
	int		nWidth;
	int		nHeight;
} FMPLAY_ARInfo;

// The video disable type
#define	FMP_PLAY_VideoEnable				0
#define	FMP_PLAY_VideoDisable_Render		1
#define	FMP_PLAY_VideoDisable_Decoder		2

#define										FMP_PLAY_BASE	0X11000000

// set the user id. The paramer is int *
#define	FMPLAY_PID_USER_ID					FMP_PLAY_BASE + 0X0001

// set the user guid. The paramer is char *
#define	FMPLAY_PID_USER_UUID				FMP_PLAY_BASE + 0X0002

// set the app version. The paramer is char *
#define	FMPLAY_PID_APP_VERSION				FMP_PLAY_BASE + 0X0003

// set the app type. The paramer is int * 1. BBQ, 2 Live, 3 VOD
#define	FMPLAY_PID_APP_TYPE					FMP_PLAY_BASE + 0X0004

// set the video guid. The paramer is long *
#define	FMPLAY_PID_VIDEO_UUID				FMP_PLAY_BASE + 0X0005


// Set the log out level
// The parameter should be int *. 0, None, 1 error, 2 warning, 3 info, 4 debug, 5 dump.
#define	FMPLAY_PID_Log_Level				FMP_PLAY_BASE + 0X0011

// Set the playback loop or not
// The parameter should be int *. 0, no loop, 1 loop
#define	FMPLAY_PID_Playback_Loop			FMP_PLAY_BASE + 0X0012

// Set / get the max buffer time
// The parameter should be int *. (ms)
#define	FMPLAY_PID_PlayBuff_MaxTime			FMP_PLAY_BASE + 0X0013

// Set / get the min buffer time
// The parameter should be int *. (ms)
#define	FMPLAY_PID_PlayBuff_MinTime			FMP_PLAY_BASE + 0X0014

// Set / get the socket connect timeout time
// The parameter should be int *. (ms)
#define	FMPLAY_PID_Socket_ConnectTimeout	FMP_PLAY_BASE + 0X0015

// Set / get the socket read timeout time
// The parameter should be int *. (ms)
#define	FMPLAY_PID_Socket_ReadTimeout		FMP_PLAY_BASE + 0X0016

// Set the http header referer
// The parameter should be char *. 
#define	FMPLAY_PID_HTTP_HeadReferer			FMP_PLAY_BASE + 0X0017

// Set the http header user-agent
// The parameter should be char *. for example "User-Agent: QPlayer Engine"
#define FMPLAY_PID_HTTP_HeadUserAgent       FMP_PLAY_BASE + 0X0018

// Set the dns server
// The parameter should be char *. "127.0.0.1" use local. "0.0.0.0" use default.
#define	FMPLAY_PID_DNS_SERVER				FMP_PLAY_BASE + 0X0019

// detect the dns get best IP address
// The parameter should be char *. "www.qiniu.com"
#define	FMPLAY_PID_DNS_DETECT				FMP_PLAY_BASE + 0X001A

// detect the net work type had changed
// The parameter none
#define	FMPLAY_PID_NET_CHANGED				FMP_PLAY_BASE + 0X001B


// Set the seek mode. 0, key frame, 1 any pos. int *.
// This can be called anytime
// But it must be called before open if FMPLAY_PID_START_POS enabled.
#define	FMPLAY_PID_Seek_Mode				FMP_PLAY_BASE + 0X0031

// Set the start pos before play. long long *
// This should be called before open.
#define	FMPLAY_PID_START_POS				FMP_PLAY_BASE + 0X0032


// Set the video ratio. 
// The parameter should be FMPLAY_ARInfo *.
#define	FMPLAY_PID_VideoRatio				FMP_PLAY_BASE + 0X0041

// Set it to zoom video
// The parameter should RECT *. The pos could be divided by 4
// set {0, 0, 0, 0} to disable this feature
#define	FMPLAY_PID_Zoom_Video				FMP_PLAY_BASE + 0X0042

// The following message for advance user
// Set the video aspect ratio. 
// The parameter should be FMPLAY_ARInfo *.
#define	FMPLAY_PID_AspectRatio				FMP_PLAY_BASE + 0X0043

// Set it to disable video. Playback audio only.
// The parameter should int *. 1 disable render, 2 decoder, 0, enable
#define	FMPLAY_PID_Disable_Video			FMP_PLAY_BASE + 0X0044

// Background color for video render. Param should  FMP_COLOR *
// This should be called before open. Default value is black, {0.0, 0.0, 0.0, 1.0}
#define	FMPLAY_PID_BG_COLOR					FMP_PLAY_BASE + 0X0045

// Set the video size change done
// The parameter should int *. 1 done.
#define	FMPLAY_PID_VideoSize_Done			FMP_PLAY_BASE + 0X0046

// Set the video thumbnail
// The parameter should Bitmap (Android), FMP_VIDEO_BUFF * (others)
#define	FMPLAY_PID_Video_Thumb				FMP_PLAY_BASE + 0X0048

// Set the save video on view.
// The parameter the int * . the ID which back with GetParam
#define	FMPLAY_PID_Video_Save				FMP_PLAY_BASE + 0X0049

// Set delete the saved video
// The parameter the int * . the ID which back with GetParam
#define	FMPLAY_PID_Video_Delete				FMP_PLAY_BASE + 0X004A

// Set clock offset time. The parameter int *.
#define	FMPLAY_PID_Clock_OffTime			FMP_PLAY_BASE + 0X0051

// Set the play speed.
// The parameter should be double *. it is 0.2 - 32.0
// This should be called after open done event.
#define	FMPLAY_PID_Speed					FMP_PLAY_BASE + 0X0052

// Set enable stretch audio or not for live
// The parameter should be int *, 1 enable default. 0 disable
#define	FMPLAY_PID_Stretch					FMP_PLAY_BASE + 0X0053

// Set the mp4 preload time
// The parameter should be int *. it is ms to preload
#define	FMPLAY_PID_MP4_PRELOAD				FMP_PLAY_BASE + 0X0061


// Get Stream number.
// The parameter should be int *.
#define	FMPLAY_PID_StreamNum				FMP_PLAY_BASE + 0X0071

// Set Stream play. The parameter should be int * (0, ... Num - 1).
//								 -1 is auto select stream
// Get Stream play. The parameter should be int *.
#define	FMPLAY_PID_StreamPlay				FMP_PLAY_BASE + 0X0072

// Get Audio track number.
// The parameter should be int *.
#define	FMPLAY_PID_AudioTrackNum			FMP_PLAY_BASE + 0X0073

// Set Audio track play. The parameter should be int * (0, ... Num - 1).
// Get Audio track play. The parameter should be int *.
#define	FMPLAY_PID_AudioTrackPlay			FMP_PLAY_BASE + 0X0074

// Get Video track number.
// The parameter should be int *.
#define	FMPLAY_PID_VideoTrackNum			FMP_PLAY_BASE + 0X0075

// Set Video track play. The parameter should be int * (0, ... Num - 1).
// Get Video track play. The parameter should be int *.
#define	FMPLAY_PID_VideoTrackPlay			FMP_PLAY_BASE + 0X0076

// Get Stream info. The parameter should be FMP_STREAM_FORMAT * 
#define	FMPLAY_PID_StreamInfo				FMP_PLAY_BASE + 0X0077

// Set cache file path. The parameter should be char * 
#define	FMPLAY_PID_Cache_Path				FMP_PLAY_BASE + 0X0080

// Set cache file number. The parameter should be int *
#define	FMPLAY_PID_Cache_Num				FMP_PLAY_BASE + 0X0081

// Set new cache url. The parameter should be char *
#define	FMPLAY_PID_Cache_URL				FMP_PLAY_BASE + 0X0088


// Internal usage
// Set / Get Audio volume.
// The parameter should be int *. (0 - 100)
#define	FMPLAY_PID_Audio_Volume				FMP_PLAY_BASE + 0X1001

// Set Video View
// The parameter should be void *.
#define	FMPLAY_PID_Video_View				FMP_PLAY_BASE + 0X1011

// Set Video draw rect
// The parameter should be RECT *.
#define	FMPLAY_PID_Video_Rect				FMP_PLAY_BASE + 0X1012

// Set Video format from parser
// The parameter is NULL.
#define	FMPLAY_PID_Video_SrcFormat			FMP_PLAY_BASE + 0X1013

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif // __fmpParam_H__
