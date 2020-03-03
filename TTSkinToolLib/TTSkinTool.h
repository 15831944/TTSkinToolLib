//////////////////////////////////////////////
//	File name:      TTSkinTool.h
//	Author:	        
//  Version:        V1.0
//	Date:           2014/1/17
//	Description:    皮肤库打包 
//	Function List:	BOOL GetSkinFilePath(const CString& strFilePath);
//                  BOOL GetSkinFileInfo(const CString& strFilePath);
//                  BOOL OnSkinToBin();
//                  BOOL OnSetSkinPackagePath(const CString& strPath);
//                  BOOL OnCovToBin();
//                  LPBYTE OnIndexStart(const CString& strIndexPath, DWORD* bufSize);
//                  BOOL IsFilter(LPCTSTR lpFilter, const CString& strSource);
//                  BOOL SetSkinFilePath(const CString& strFilePath);
//                  BOOL SetOutPath(const CString& strOutPath);
//                  BOOL Formatting();
//                  BOOL Search(const CString& strFilePath);
//                  BOOL SetTargetFile(const CString& strTargetFile);
//	History:
//	Date:
//	Author:
//	Modification:
//////////////////////////////////////////////////
#pragma once

#include <afxwin.h>

#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <map>
#include <hash_map>
#include <cstring>
#include "TTSkinToolInterface.h"
#include "TTSkinToolSearchInterface.h"
using namespace std;
using stdext::hash_map;

/*函数类 *作为hash_map的hash函数  *string没有默认的hash函数*/ 
struct str_hash
{
    size_t operator()(const string& str) const
    {
        unsigned long __h = 0;
        for (size_t i = 0; i < str.size();i ++)
            __h = 5*__h + str[i];
        return size_t(__h);
    } 
};

typedef struct _TTSkinNode 
{
    TCHAR szPath[MAX_PATH];     //皮肤文件路径   
    unsigned int nPos;          //皮肤数据在二进制文件中的起始位置
    unsigned int nSizeByte;     //皮肤数据大小
}TTSkinNode;	

typedef struct _TTSkinInfo
{
    TCHAR szName[20];    //皮肤库名
    TCHAR szVersion[20]; //文件版本
    int nNum;            //文件数量
}TTSkinInfo;

class CTTSkinTool : public ITTSkinToolInterface, public ITTSkinToolSearchInterface
{
public:
    CTTSkinTool(void);
    ~CTTSkinTool(void);

public:
    //设置皮肤库路径
    BOOL SetSkinFilePath(const TTSTRING& strFilePath);
    //设置输出路径
    BOOL SetOutPath(const TTSTRING& strOutPath);
    //转换
    BOOL Formatting();
    //查找
    LPBYTE Search(const TTSTRING& strFilePath, DWORD* bufSize);
    //设置目标文件路径
    BOOL SetTargetFile(const TTSTRING& strTargetFile);

private:
    CString  m_strTepPath;                       //皮肤库前面的绝对路径
    CString  m_strSkinPackName;                  //打包后的文件名
    bool     m_bIndexOfFirst;                    //第一次建立索引
    int      m_nSkinNum;                         //皮肤文件数量
    fstream  m_InFile;                           //二进制文件定义
    fstream  m_OutFile;                          //输出流文件
    TTSkinInfo m_SkinInfo;                       //二进制文件基本信息结构体
    //vector <wstring> m_vTTSkinPath;              //保存每个皮肤文件所在路径
    vector <TTSkinNode> m_vTTSkin;               //定义所有皮肤信息保存向量
    hash_map<wstring, TTSkinNode> m_mapTTSkinNodeHM; //定义哈希映射
    hash_map<wstring, TTSkinNode>::iterator m_Iter;   //查找迭代器

    CString m_strOutPutPath;                     //输出路径
    CString m_strSkinPath;                       //皮肤路径
    vector<LPBYTE> m_FileData;                   //皮肤文件数据
    CString m_strTargetFile;                     //要查找目标文件名
    LPBYTE  m_pData;                             //二进制数据，建立索引时，把数据读到此buf中
    unsigned int m_nDataHeadSize;

private:
    //遍历皮肤库
    BOOL GetSkinFilePath(const CString& strFilePath);

    //获取皮肤文件基本信息
    BOOL GetSkinFileInfo(const CString& strFilePath);

    //将路径参数对应皮肤文件转存二进制文件
    BOOL OnSkinToBin();

    //设置皮肤库路径，并遍历路径下皮肤文件获取信息并压缩成二进制文件
    BOOL OnSetSkinPackagePath(const CString& strPath);

    //将皮肤文件转存二进制文件中
    BOOL OnCovToBin();

    //根据传入路径参数，在打包文件中查找对应皮肤数据
    LPBYTE OnIndexStart(const CString& strIndexPath, DWORD* bufSize);

    //文件过滤，判断后缀
    BOOL IsFilter(LPCTSTR lpFilter, const CString& strSource);
};
