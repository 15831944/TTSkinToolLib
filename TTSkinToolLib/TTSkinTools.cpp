//////////////////////////////////////////////
//	File name:  TTSkinTool.cpp
//	Author:	    
//  Version:    V1.0
//	Date:       2014/1/17
//	Description:Æ¤·ô¿â´ò°ü 
//	Function List:	 ITTSkinToolInterface* CreateSkinToolInstance();
//                   void DestorySkinToolInstance(ITTSkinToolInterface* pObj);
//	History:
//	Date:
//	Author:
//	Modification:
//////////////////////////////////////////////////

//#include "stdafx.h"

#include "TTSkinTool.h"
#include "TTSkinToolInterface.h"
#include "TTSkinToolSearchInterface.h"

ITTSkinToolInterface* CreateSkinToolInstance()
{
    CTTSkinTool *pObj = new CTTSkinTool;
    if (NULL != pObj)
    {
        return ((ITTSkinToolInterface*)pObj);
    }

    return NULL;
}

void DestorySkinToolInstance(ITTSkinToolInterface* pObj)
{
    if (NULL != pObj)
    {
        CTTSkinTool *p = static_cast<CTTSkinTool *>(pObj);
        delete p;
        p = NULL;
    }
}

ITTSkinToolSearchInterface* CreateSkinToolSearchInstance()
{
    CTTSkinTool *pObj = new CTTSkinTool;
    if (NULL != pObj)
    {
        return ((ITTSkinToolSearchInterface*)pObj);
    }

    return NULL;
}

void DestorySkinToolSearchInstance(ITTSkinToolSearchInterface* pObj)
{
    if (NULL != pObj)
    {
        CTTSkinTool *p = static_cast<CTTSkinTool *>(pObj);
        delete p;
        p = NULL;
    }
}

