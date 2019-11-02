/*******************************************************************************
	File:		fmpType.h

	Contains:	fmp player type define header file.

	Written by:	Fenger King

	Change History (most recent first):
	2016-11-29		Fenger			Create file

*******************************************************************************/
#ifndef __fmpType_H__
#define __fmpType_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
    
#ifdef __FMP_OS_WIN32__
#include "windows.h"
#include "tchar.h"
#elif defined __FMP_OS_NDK__ || defined __FMP_OS_IOS__
#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#endif // __FMP_OS_WIN32__

#ifdef __FMP_OS_WIN32__
#define FMP_API __cdecl
#define FMP_CBI __stdcall
#define DLLIMPORT_C extern __declspec(dllimport)
#define DLLEXPORT_C __declspec(dllexport)
#else
#define FMP_API
#define FMP_CBI
#define DLLIMPORT_C 
#define DLLEXPORT_C __attribute__ ((visibility("default")))
#define TCHAR	char
#endif // __FMP_OS_WIN32__
    
#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif // __fmpType_H__
