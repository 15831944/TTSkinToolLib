
// TTSkinToolDlg.h : header file
//

#pragma once
#include "./Include/TTSkinToolInterface.h"
#include "./Include/TTSkinToolSearchInterface.h"
#include "./Include/TTSkinToolExport.h"
#include "afxwin.h"


// CTTSkinToolDlg dialog
class CTTSkinToolDlg : public CDialog
{
// Construction
public:
	CTTSkinToolDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_TTSKINTOOL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
    ITTSkinToolInterface *m_pTTSin;
    ITTSkinToolSearchInterface *m_pTTSkinSearch;
    CString m_strSkinPath;  //Ƥ��·��
    CString m_strOutPath;   //���·��
    CString m_strSearchPath;//����·��
    CString m_strOutFilePath; //�������ļ�·��

public:
    afx_msg void OnDestroy();
    afx_msg void OnBnClickedBtnSelectSkinPath();//����Ƥ��·��
    afx_msg void OnBnClickedBtnOutPath();//�������·��
    afx_msg void OnBnClickedBtnSearch();//��ʼ����
    afx_msg void OnBnClickedBtnStart();//��ʼת��
    afx_msg void OnBnClickedBtnOutFilePath();//����Ŀ���ļ�·��
    CStatic m_LableTime;
    afx_msg void OnEnKillfocusEditSearchPath();
    afx_msg void OnEnKillfocusEditSkipPath();
    afx_msg void OnEnKillfocusEditOutPath();
};
