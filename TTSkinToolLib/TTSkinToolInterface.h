/////////////////////////////////////////////////////////////
//	File name:       TTSKinToolInterface.h
//	Author:	         
//  Version:         V1.0
//	Date:            2014/1/17
//	Description:     接口文件
//	Function List:	 BOOL SetSkinFilePath(const string& strFilePath);
//                   BOOL SetOutPath(const string& strOutPath) = 0;
//                   BOOL Formatting();
//	History:
//	Date:
//	Author:
//	Modification:
/////////////////////////////////////////////////////////////
#ifndef _TTSKINTOOLINTERFACE_H
#define _TTSKINTOOLINTERFACE_H

#include "TTSkinToolExport.h"

interface ITTSkinToolInterface
{
public:
    //设置皮肤库路径
    virtual BOOL SetSkinFilePath(const TTSTRING& strFilePath) = 0;
    //设置输出路径
    virtual BOOL SetOutPath(const TTSTRING& strOutPath) = 0;
    //转换
    virtual BOOL Formatting() = 0;
};

#ifndef _DLLIMPORT
#define CLASS_DECLSPEC __declspec(dllexport)
#else
#define CLASS_DECLSPEC __declspec(dllimport)
#endif

extern "C" CLASS_DECLSPEC ITTSkinToolInterface* CreateSkinToolInstance();
extern "C" CLASS_DECLSPEC void DestorySkinToolInstance(ITTSkinToolInterface* pObj);

#endif