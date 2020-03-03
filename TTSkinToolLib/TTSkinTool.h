//////////////////////////////////////////////
//	File name:      TTSkinTool.h
//	Author:	        
//  Version:        V1.0
//	Date:           2014/1/17
//	Description:    Ƥ������ 
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

/*������ *��Ϊhash_map��hash����  *stringû��Ĭ�ϵ�hash����*/ 
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
    TCHAR szPath[MAX_PATH];     //Ƥ���ļ�·��   
    unsigned int nPos;          //Ƥ�������ڶ������ļ��е���ʼλ��
    unsigned int nSizeByte;     //Ƥ�����ݴ�С
}TTSkinNode;	

typedef struct _TTSkinInfo
{
    TCHAR szName[20];    //Ƥ������
    TCHAR szVersion[20]; //�ļ��汾
    int nNum;            //�ļ�����
}TTSkinInfo;

class CTTSkinTool : public ITTSkinToolInterface, public ITTSkinToolSearchInterface
{
public:
    CTTSkinTool(void);
    ~CTTSkinTool(void);

public:
    //����Ƥ����·��
    BOOL SetSkinFilePath(const TTSTRING& strFilePath);
    //�������·��
    BOOL SetOutPath(const TTSTRING& strOutPath);
    //ת��
    BOOL Formatting();
    //����
    LPBYTE Search(const TTSTRING& strFilePath, DWORD* bufSize);
    //����Ŀ���ļ�·��
    BOOL SetTargetFile(const TTSTRING& strTargetFile);

private:
    CString  m_strTepPath;                       //Ƥ����ǰ��ľ���·��
    CString  m_strSkinPackName;                  //�������ļ���
    bool     m_bIndexOfFirst;                    //��һ�ν�������
    int      m_nSkinNum;                         //Ƥ���ļ�����
    fstream  m_InFile;                           //�������ļ�����
    fstream  m_OutFile;                          //������ļ�
    TTSkinInfo m_SkinInfo;                       //�������ļ�������Ϣ�ṹ��
    //vector <wstring> m_vTTSkinPath;              //����ÿ��Ƥ���ļ�����·��
    vector <TTSkinNode> m_vTTSkin;               //��������Ƥ����Ϣ��������
    hash_map<wstring, TTSkinNode> m_mapTTSkinNodeHM; //�����ϣӳ��
    hash_map<wstring, TTSkinNode>::iterator m_Iter;   //���ҵ�����

    CString m_strOutPutPath;                     //���·��
    CString m_strSkinPath;                       //Ƥ��·��
    vector<LPBYTE> m_FileData;                   //Ƥ���ļ�����
    CString m_strTargetFile;                     //Ҫ����Ŀ���ļ���
    LPBYTE  m_pData;                             //���������ݣ���������ʱ�������ݶ�����buf��
    unsigned int m_nDataHeadSize;

private:
    //����Ƥ����
    BOOL GetSkinFilePath(const CString& strFilePath);

    //��ȡƤ���ļ�������Ϣ
    BOOL GetSkinFileInfo(const CString& strFilePath);

    //��·��������ӦƤ���ļ�ת��������ļ�
    BOOL OnSkinToBin();

    //����Ƥ����·����������·����Ƥ���ļ���ȡ��Ϣ��ѹ���ɶ������ļ�
    BOOL OnSetSkinPackagePath(const CString& strPath);

    //��Ƥ���ļ�ת��������ļ���
    BOOL OnCovToBin();

    //���ݴ���·���������ڴ���ļ��в��Ҷ�ӦƤ������
    LPBYTE OnIndexStart(const CString& strIndexPath, DWORD* bufSize);

    //�ļ����ˣ��жϺ�׺
    BOOL IsFilter(LPCTSTR lpFilter, const CString& strSource);
};
