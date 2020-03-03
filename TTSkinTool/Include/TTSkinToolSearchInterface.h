/////////////////////////////////////////////////////////////
//	File name:       TTSKinToolSearchInterface.h
//	Author:	         
//  Version:         V1.0
//	Date:            2014/1/17
//	Description:     接口文件
//	Function List:	 BOOL SetTargetFile(const string& strTargetFile);
//                   LPBYTE Search(const string& strFilePath, DWORD* bufSize);
//	History:
//	Date:
//	Author:
//	Modification:
/////////////////////////////////////////////////////////////
#ifndef _TTSKINTOOLSEARCHINTERFACE_H
#define _TTSKINTOOLSEARCHINTERFACE_H
#include "TTSkinToolExport.h"

interface ITTSkinToolSearchInterface
{
    //设置目标文件路径
    virtual BOOL SetTargetFile(const TTSTRING& strTargetFile) = 0;
    //查找
    virtual LPBYTE Search(const TTSTRING& strFilePath, DWORD* bufSize) = 0;
};

extern "C" CLASS_DECLSPEC ITTSkinToolSearchInterface* CreateSkinToolSearchInstance();
extern "C" CLASS_DECLSPEC void DestorySkinToolSearchInstance(ITTSkinToolSearchInterface* pObj);

#endif