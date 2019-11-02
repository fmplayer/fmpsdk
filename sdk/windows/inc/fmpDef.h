/*******************************************************************************
	File:		fmpDef.h

	Contains:	fmp player micro define header file.

	Written by:	Fenger King

	Change History (most recent first):
	2016-11-29		Fenger			Create file

*******************************************************************************/
#ifndef __fmpDef_H__
#define __fmpDef_H__
#include <stdlib.h>

#ifdef __FMP_OS_WIN32__
#pragma warning (disable : 4996)
#endif // __FMP_OS_WIN32__

// define the module ID
#define FMP_MOD_IO_BASE					0x41000000
#define FMP_MOD_IO_FILE					0x41100000
#define FMP_MOD_IO_HTTP					0x41200000
#define FMP_MOD_IO_RTMP					0x41300000
#define FMP_MOD_IO_RTSP					0x41400000

#define FMP_MOD_PARSER_MP4				0x42100000
#define FMP_MOD_PARSER_FLV				0x42200000
#define FMP_MOD_PARSER_TS				0x42300000
#define FMP_MOD_PARSER_M3U8				0x42400000

#define FMP_MOD_AUDIO_DEC_AAC			0x43100000
#define FMP_MOD_VIDEO_DEC_H264			0x44100000

#define FMP_MOD_SINK_AUDIO				0x45100000
#define FMP_MOD_SINK_VIDEO				0x45200000
#define FMP_MOD_SINK_DATA				0x45300000

#define FMP_MOD_MFW_PLAY					0x46000000


#define	FMP_DEL_P(p)   \
	if (p != NULL) {  \
		delete p;     \
		p = NULL; }   \

#define	FMP_DEL_A(a)   \
	if (a != NULL) {  \
		delete []a;   \
		a = NULL; }   \

#define	FMP_FREE_P(p)   \
	if (p != NULL) {  \
		free (p);     \
		p = NULL; }   \

#define	FMP_REL_P(a)   \
	if (a != NULL) {  \
		a->Release(); \
		a = NULL; }   \


#define FMP_MAX(a,b) ((a) > (b) ? (a) : (b))
#define FMP_MAX3(a,b,c) FMP_MAX(FMP_MAX(a,b),c)
#define FMP_MIN(a,b) ((a) > (b) ? (b) : (a))
#define FMP_MIN3(a,b,c) FMP_MIN(FMP_MIN(a,b),c)

#define FMP_MKTAG(a,b,c,d) ((a) | ((b) << 8) | ((c) << 16) | ((unsigned)(d) << 24))
#define FMP_MKBETAG(a,b,c,d) ((d) | ((c) << 8) | ((b) << 16) | ((unsigned)(a) << 24))

#ifndef __FMP_OS_WIN32__
typedef struct tagRECT
{
    int    left;
    int    top;
    int    right;
    int    bottom;
} RECT, *PRECT;

#ifndef MAKEFOURCC
#define MAKEFOURCC(ch0, ch1, ch2, ch3)                              \
                ((unsigned int)(unsigned char)(ch0) | ((unsigned int)(unsigned char)(ch1) << 8) |   \
                ((unsigned int)(unsigned char)(ch2) << 16) | ((unsigned int)(unsigned char)(ch3) << 24 ))
#endif // MAKEFOURCC

#endif // __FMP_OS_WIN32__


#define fmpReadUint16(buf)	(unsigned short)((buf[1] << 8) | buf[0])
#define fmpReadUint16BE(buf) (unsigned short)((buf[0] << 8) | buf[1])
#define fmpReadUint32(buf)	(unsigned int)((buf[3] << 24) | (buf[2] << 16) | (buf[1] << 8) | buf[0])
#define fmpReadUint32BE(buf)	(unsigned int)((buf[0] << 24) | (buf[1] << 16) | (buf[2] << 8) | buf[3])

#define FMP_MAX_NUM32	0XFFFFFFFF
#define FMP_MAX_NUM64	0XFFFFFFFFFFFFFFFF
#define FMP_MAX_NUM32_S	0X7FFFFFFF
#define FMP_MAX_NUM64_S	0X7FFFFFFFFFFFFFFF

#ifdef __FMP_OS_WIN32__
#pragma warning (disable : 4996)
#pragma warning (disable : 4390)
#endif // __FMP_OS_WIN32__

#ifdef __FMP_OS_IOS__
#ifndef time_t
typedef __darwin_time_t         time_t;
#endif //time_t
#endif // __FMP_OS_IOS__

#endif // __fmpDef_H__
