/*******************************************************************************
	File:		fmpMsg.h

	Contains:	fmp player message define header file.

	Written by:	Fenger King

	Change History (most recent first):
	2016-11-29		Fenger			Create file

*******************************************************************************/
#ifndef __FMPMSG_H__
#define __FMPMSG_H__

typedef struct {
	int			nMsgID;			/*!< The message ID */
	int			nValue;			/*!< The int 32 value */
	long long	llValue;		/*!< The int 64 value */
	char *		pValue;			/*!< The char * value */	
	void *		pInfo;			/*!< The message info depend on ID */
	int			nTime;			/*!< The happen time */
} fmpMsgInfo;

// define the IO msg ID
#define FMP_MSG_IO_BASE					0x11000000
#define FMP_MSG_IO_CONNECT_START		0x11000001		// Param: 
#define FMP_MSG_IO_CONNECT_FAILED		0x11000002		// Param: 
#define FMP_MSG_IO_CONNECT_SUCESS		0x11000003		// Param: 
#define FMP_MSG_IO_DNS_PARSER_START		0x11000004		// Param: 
#define FMP_MSG_IO_DNS_PARSER_IP		0x11000006		// Param: pValue is IP address
#define FMP_MSG_IO_GET_HEADDATA			0x11000010		// Param: pValue is head data
#define FMP_MSG_IO_CONTENT_SIZE			0x11000011		// Param: long long size.
#define FMP_MSG_IO_REDIRECT_URL			0x11000012		// Param: pValue is url
#define FMP_MSG_IO_DISCONNECT_START		0x11000021		// Param: 
#define FMP_MSG_IO_DISCONNECT_DONE		0x11000022		// Param: 
#define FMP_MSG_IO_RESPONSE_CODE		0x11000023		// Param: http response code 

#define FMP_MSG_IO_DOWNLOAD_SPEED		0x11000030		// Param: int speed
#define FMP_MSG_IO_DOWNLOAD_SIZE		0x11000031		// Param: long long size
#define FMP_MSG_IO_DISCONNECTED			0x11000050		// Param: 
#define FMP_MSG_IO_RECONNECT_START		0x11000051		// Param: 
#define FMP_MSG_IO_RECONNECT_FAILED		0x11000052		// Param: 
#define FMP_MSG_IO_RECONNECT_SUCESS		0x11000053		// Param:

#define FMP_MSG_IO_FIRST_BYTE_DONE		0x11020001		// Param:
#define FMP_MSG_IO_HANDSHAKE_START      0x11020003
#define FMP_MSG_IO_HANDSHAKE_FAILED     0x11020004
#define FMP_MSG_IO_HANDSHAKE_SUCESS     0x11020005


// define the parser msg ID
#define FMP_MSG_PARSER_BASE				0x12000000
// m_nValue is bitrate
#define FMP_MSG_PARSER_NEW_STREAM		0x12000001
#define FMP_MSG_PARSER_M3U8_ERROR		0x12000010
#define FMP_MSG_PARSER_FLV_ERROR		0x12000020
#define FMP_MSG_PARSER_MP4_ERROR		0x12000030


// define the Audio Dec msg ID
#define FMP_MSG_AUDIO_DEC				0x13000000


// define the Video Dec msg ID
#define FMP_MSG_VIDEO_DEC				0x14000000
#define FMP_MSG_VIDEO_HWDEC_FAILED		0x14000001

// define the Sink msg ID
#define FMP_MSG_SINK_BASE				0x15000000

// define the Audio Sink msg ID
#define FMP_MSG_SINK_AUDIO				0x15100000
#define FMP_MSG_SNKA_FIRST_FRAME		0x15100001
#define FMP_MSG_SNKA_EOS				0x15100002
// m_nValue is sample rate, m_llValue is channel
#define FMP_MSG_SNKA_NEW_FORMAT			0x15100003
// m_llValue is timestamp
#define FMP_MSG_SNKA_RENDER				0x15100004
// The m_pValue is FMP_DATA_BUFF
#define FMP_MSG_SNKA_BUFFER				0x15100006

// define the Video Sink msg ID
#define FMP_MSG_SINK_VIDEO				0x15200000
#define FMP_MSG_SNKV_FIRST_FRAME		0x15200001
#define FMP_MSG_SNKV_EOS				0x15200002
// m_nValue is width, m_llValue is Height
#define FMP_MSG_SNKV_NEW_FORMAT			0x15200003
// m_llValue is timestamp
#define FMP_MSG_SNKV_RENDER				0x15200004
// m_nValue is the rotate angle (90, 180, 270)
#define FMP_MSG_SNKV_ROTATE				0x15200005
// The m_pValue is FMP_VIDEO_BUFF
#define FMP_MSG_SNKV_BUFFER				0x15200006

// define the play msg ID
#define FMP_MSG_PLAY_BASE				0x16000000
#define FMP_MSG_PLAY_OPEN_DONE			0x16000001
#define FMP_MSG_PLAY_OPEN_FAILED		0x16000002
#define FMP_MSG_PLAY_CLOSE_DONE			0x16000003
#define FMP_MSG_PLAY_CLOSE_FAILED		0x16000004
#define FMP_MSG_PLAY_SEEK_DONE			0x16000005
#define FMP_MSG_PLAY_SEEK_FAILED		0x16000006
#define FMP_MSG_PLAY_COMPLETE			0x16000007  // the param is int *. 0 is normal ,1 is error.
#define FMP_MSG_PLAY_STATUS 			0x16000008
#define FMP_MSG_PLAY_DURATION			0x16000009
#define FMP_MSG_PLAY_POS				0x1600000F
#define FMP_MSG_PLAY_LOOP_TIMES			0x16000011
#define FMP_MSG_PLAY_GET_THUMB			0x16000012		//param m_pInfo FMP_VIDEO_BUFF pointer. 

#define FMP_MSG_BUFF_NEWSTREAM			0x18000014		//param: 
#define FMP_MSG_BUFF_START_BUFFERING	0x18000016		//param: playing time
#define FMP_MSG_BUFF_END_BUFFERING		0x18000017		//param:
#define	FMP_MSG_BUFF_VBUFFTIME			0x18000020
#define	FMP_MSG_BUFF_ABUFFTIME			0x18000021

#endif // __FMPMSG_H__
