/*******************************************************************************
	File:		fmpData.h

	Contains:	fmp player data define header file.

	Written by:	Fenger King

	Change History (most recent first):
	2016-11-29		Fenger			Create file

*******************************************************************************/
#ifndef __fmpData_H__
#define __fmpData_H__

#include "fmpType.h"

#define	FMPIO_FLAG_READ			1                                   /**< read-only */
#define FMPIO_FLAG_WRITE		2                                   /**< write-only */
#define FMPIO_FLAG_READ_WRITE	(FMPIO_FLAG_READ | FMPIO_FLAG_WRITE)	/**< read-write pseudo flag */
#define	FMPIO_FLAG_URL			8                                   /**< connect with URL  */

#define FMPIO_SEEK_SIZE			0X1000
#define FMPIO_SEEK_BEGIN		0X2000
#define FMPIO_SEEK_CUR			0X3000
#define FMPIO_SEEK_END			0X4000

#define FMPIO_READ_DATA			0X0100
#define FMPIO_READ_HEAD			0X0200
#define FMPIO_READ_AUDIO		0X0400
#define FMPIO_READ_VIDEO		0X0800

// What is the source from.
typedef enum {
	FMP_SOURCE_FMP		= 1,
	FMP_SOURCE_FF		= 2,
	FMP_SOURCE_EX		= 4,
	FMP_SOURCE_MAX		= 0X7FFFFFFF
}FMPSourceType;

// the IO protocol
typedef enum {
    FMP_IOPROTOCOL_NONE,
    FMP_IOPROTOCOL_FILE,
    FMP_IOPROTOCOL_HTTP,
    FMP_IOPROTOCOL_RTMP,
	FMP_IOPROTOCOL_RTSP,
	FMP_IOPROTOCOL_EXTLIB,
	FMP_IOPROTOCOL_HTTPPD,
	FMP_IOPROTOCOL_EXTIO,
	FMP_IOPROTOCOL_QUIC,
	FMP_IOPROTOCOL_MAX = 0X7FFFFFFF
}FMPIOProtocol;

// the parser format 
typedef enum {
    FMP_PARSER_NONE,
    FMP_PARSER_M3U8,
    FMP_PARSER_MP4,
    FMP_PARSER_FLV,
	FMP_PARSER_BBDASH,
	FMP_PARSER_TS,
    FMP_PARSER_MP3,
    FMP_PARSER_AAC,
	FMP_PARSER_RTSP,
	FMP_PARSER_FFCAT,
	FMP_PARSER_MAX = 0X7FFFFFFF
}FMPParserFormat;

typedef enum {
    FMP_CODEC_ID_NONE,

    // video codecs 
    FMP_CODEC_ID_H264,
    FMP_CODEC_ID_H265,
    FMP_CODEC_ID_MPEG4,
	FMP_CODEC_ID_MJPEG,

    // audio codecs 
    FMP_CODEC_ID_AAC		= 0x10000,
    FMP_CODEC_ID_MP3, 
	FMP_CODEC_ID_MP2,
	FMP_CODEC_ID_SPEEX,
	FMP_CODEC_ID_PCM,
	FMP_CODEC_ID_LPCM,
	FMP_CODEC_ID_G711A,
	FMP_CODEC_ID_G711U,
	FMP_CODEC_ID_G722,
	FMP_CODEC_ID_G723,
	FMP_CODEC_ID_G726,
	FMP_CODEC_ID_MAX = 0X7FFFFFFF
}FMPCodecID;

// the video raw data format
typedef enum  {
	FMP_VDT_YUV420_P		= 0,
	FMP_VDT_NV12			= 1,
	FMP_VDT_YUYV422		= 2,
	FMP_VDT_YUV422_P		= 3,
	FMP_VDT_YUV444_P		= 4,
	FMP_VDT_YUV410_P		= 5,
	FMP_VDT_YUV411_P		= 6,
	FMP_VDT_RGB565		= 11,
	FMP_VDT_RGB24		= 12,
	FMP_VDT_RGBA			= 13,
	FMP_VDT_ARGB			= 14,
	FMP_VDT_MAX			= 0X7FFFFFFF
} FMPVideoType;

// the stream media type
typedef enum {
	FMP_MEDIA_Data		= 0,
	FMP_MEDIA_Source		= 1,
	FMP_MEDIA_Video		= 11,
	FMP_MEDIA_Audio		= 12,
	FMP_MEDIA_Subtt		= 13,
	FMP_MEDIA_Image		= 14,
	FMP_MEDIA_VBuff		= 21,
	FMP_MEDIA_ABuff		= 22,
	FMP_MEDIA_All		= 255,
	FMP_MEDIA_MAX		= 0X7FFFFFFF
}FMPMediaType;

/**
 * General stream format
 */
typedef struct {
	FMPMediaType	nType;			/*!< Media type */
	int				nID;			/*!< Stream id */
	int				nBitrate;		/*!< bitrate */
	int				nWidth;			/*!< video width */
	int				nHeight;		/*!< video height */
	int				nLevel;			/*!< quality level */
	char			szDesp[64];		/*!< description */
	void *			pPrivateData;	/*!< Private data pointer*/
	int				nPrivateFlag;	/*!< Private data flag*/
} FMP_STREAM_FORMAT;

/**
 * General audio format
 */
typedef struct{
	FMPSourceType	nSourceType;	/*!< Souce Type*/
	int				nCodecID;		/*!< codec id*/
	int				nSampleRate;	/*!< Sample rate */
	int				nChannels;		/*!< Channel count */
	int				nBits;			/*!< Bits per sample 8, 16 */
	int				nFourCC;		/*!< Frame type */
	int				nHeadSize;		/*!< head data size*/
	unsigned char *	pHeadData;		/*!< head data*/
	int				nBitrate;		/*!< bitrate*/
	char			szName[32];		/*!< language name */
	void *			pPrivateData;	/*!< Private data pointer*/
	int				nPrivateFlag;	/*!< Private data flag*/
} FMP_AUDIO_FORMAT;

/**
 * General video Size
 */
typedef struct
{
	FMPSourceType	nSourceType;	/*!< Souce Type*/
	int				nCodecID;		/*!< codec id*/
	int				nWidth;			/*!< Video Width */
	int				nHeight;		/*!< Video Height */
	int				nNum;			/*!< aspect ratio numerator */
	int				nDen;			/*!< aspect ratio denominator */
	int				nFrameTime;		/*!< frame time*/
	int				nFourCC;		/*!< codec type */
	int				nHeadSize;		/*!< head data size*/
	unsigned char *	pHeadData;		/*!< head data*/
	int				nBitrate;		/*!< bitrate*/
	char			szDesp[32];		/*!< description text */
	void *			pPrivateData;	/*!< Private data pointer*/
	int				nPrivateFlag;	/*!< Private data flag*/
} FMP_VIDEO_FORMAT;

/**
 * General video Size
 */
typedef struct
{
	FMPSourceType	nSourceType;	/*!< Souce Type*/
	int				nCodecID;		/*!< codec id*/
	int				nType;			/*!< the type */
	char			szlang[32];		/*!< language info */
	unsigned char *	pHeadData;		/*!< head data*/
	int				nHeadSize;		/*!< head data size*/
	void *			pPrivateData;	/*!< Private data pointer*/
	int				nPrivateFlag;	/*!< Private data flag*/
} FMP_SUBTT_FORMAT;

// the buffer status
#define	FMPBUFF_NEW_POS			0X00000001
#define	FMPBUFF_NEW_FORMAT		0X00000002
#define	FMPBUFF_EOS				0X00000004
#define	FMPBUFF_KEY_FRAME		0X00000008
#define	FMPBUFF_FLUSH			0X00000010
#define	FMPBUFF_HEADDATA		0X00000020
#define	FMPBUFF_NEWSTREAM		0X00000040
#define	FMPBUFF_NEWSOURCE		0X00000080
#define	FMPBUFF_DISCONNECT		0X00000100
#define	FMPBUFF_DROP_FRAME		0X00000200

// for dec
#define	FMPBUFF_DEC_DISABLE			0X00010000	// disable dec
#define	FMPBUFF_DEC_DISA_DEBLOCK	0X00020000	// disable deblock
#define	FMPBUFF_DEC_SKIP_BFRAME		0X00040000	// skip the b frame in dec
#define	FMPBUFF_DEC_RENDER			0X00080000	// Video had render in dec
#define	FMPBUFF_DEC_SOFT			0X00100000	// use soft dec

// for render
#define	FMPBUFF_RND_DISABLE			0X01000000

// the stream media type
typedef enum {
	FMP_BUFF_TYPE_Data		= 0,	// the buff is normal data type
	FMP_BUFF_TYPE_Video		= 1,	// the buff is video buffer
	FMP_BUFF_TYPE_Packet	= 2,	// the buff is packet format from ffmpeg
	FMP_BUFF_TYPE_FFFrame	= 3,	// the buff is avframe format from ffmpeg
	FMP_BUFF_TYPE_FFSubtt	= 4,	// the buff is subtitle format from ffmpeg
	FMP_BUFF_TYPE_PPointer	= 5,	// the buff is pointer pointer.
	FMP_BUFF_TYPE_Text		= 6,	// the buff is text
	FMP_BUFF_TYPE_MAX		= 0X7FFFFFFF
}FMPBufferType;

// the BA mode
#define FMP_BA_MODE_AUTO		0X00000001
#define FMP_BA_MODE_MANUAL		0X00000002
typedef int (*FMP_FREE_BUFF) (void * pUser, void * pBuff);

typedef struct {
	FMPMediaType		nMediaType;		/*!< buffer type    */
	FMPBufferType		uBuffType;		/*!< buffer flags    */
	unsigned int		uFlag;			/*!< the flag of the buffer  */
	unsigned char *		pBuff;			/*!< Buffer pointer */
	void *				pBuffPtr;		/*!< if type was not FMP_BUFF_TYPE_Data, the pointer is special data */
	unsigned int		uSize;			/*!< Buffer size in byte */
	long long			llTime;			/*!< The time of the buffer */
	long long			llDelay;		/*!< The time of delay */
	void *				pFormat;		/*!< new format type info (AVT)  */
	int					nValue;			/*!< the value depend on the flag   */
	void *				pData;			/*!< the reverse data point  */
	int					nDataType;		/*!< the reverse data type  */
	unsigned int		uBuffSize;		/*!< Buffer size alloced */
	void *				pUserData;
	FMP_FREE_BUFF		fFreeBuff;
} FMP_DATA_BUFF;

/**
 * General video buffer structure
 */
typedef struct {
	unsigned char *		pBuff[3];		/*!< Video buffer */
	int					nStride[3];     /*!< Video buffer stride */
	FMPVideoType		nType;			/*!< Video buffer type */
	int					nWidth;			/*!< Video width*/
	int					nHeight;		/*!< Video height*/
	int					nRatioNum;		///< Numerator
	int					nRatioDen;		///< Denominator
} FMP_VIDEO_BUFF;

/**
 * Resource information
 */
typedef struct {
	char *		pszURL;			/*!< the URL of current stream*/
	char *		pszDomain;		/*!< domain*/
	char *		pszFormat;		/*!< foramt of resource, m3u8, mp4*/
	long long	llDuration;		/*!< duration of resource*/
	int			nVideoCodec;	/*!< video codec*/
	int			nAudioCodec;	/*!< audio codec*/
	int			nBitrate;		/*!< video bitrate*/
	int			nFrameRate;		/*!< frame rate*/
	int			nWidth;			/*!< width of video*/
	int			nHeight;		/*!< height of video*/
} FMP_RESOURCE_INFO;

/**
 * Color definition
 */
typedef struct {
    float fRed;			/*!< value of red, 0.0 ~ 1.0 */
    float fGreen;		/*!< value of green, 0.0 ~ 1.0 */
    float fBlue;		/*!< value of blue, 0.0 ~ 1.0 */
    float fAlpha;		/*!< value of alpha, 0.0 ~ 1.0 */
} FMP_COLOR;

#endif // __fmpData_H__
