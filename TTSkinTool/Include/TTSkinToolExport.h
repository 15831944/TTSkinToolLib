/////////////////////////////////////////////////////////////
//	File name:       TTSKinTools.h
//	Author:	         
//  Version:         V1.0
//	Date:            2014/1/17
//	Description:     
//	Function List:	 
//	History:
//	Date:
//	Author:
//	Modification:
/////////////////////////////////////////////////////////////
#ifndef _TTSKINTOOLS_H_
#define _TTSKINTOOLS_H_

#include <string>
using namespace std;

#ifdef _UNICODE
#define TTSTRING wstring
#else
#define TTSTING string
#endif

#ifndef _DLLIMPORT
#define CLASS_DECLSPEC __declspec(dllexport)
#else
#define CLASS_DECLSPEC __declspec(dllimport)
#endif

#ifdef _DEBUG
#ifdef _UNICODE
#pragma comment(lib, "TTSkinToolLibUD.lib")
#else
#pragma comment(lib, "TTSkinToolLibD.lib")
#endif 
#else
#ifdef _UNICODE
#pragma comment(lib, "TTSkinToolLibU.lib")
#else
#pragma comment(lib, "TTSkinToolLib.lib")
#endif 
#endif

#endif