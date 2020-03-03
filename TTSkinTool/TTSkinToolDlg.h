
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
    CString m_strSkinPath;  //皮肤路径
    CString m_strOutPath;   //输出路径
    CString m_strSearchPath;//查找路径
    CString m_strOutFilePath; //二进制文件路径

public:
    afx_msg void OnDestroy();
    afx_msg void OnBnClickedBtnSelectSkinPath();//设置皮肤路径
    afx_msg void OnBnClickedBtnOutPath();//设置输出路径
    afx_msg void OnBnClickedBtnSearch();//开始查找
    afx_msg void OnBnClickedBtnStart();//开始转换
    afx_msg void OnBnClickedBtnOutFilePath();//设置目标文件路径
    CStatic m_LableTime;
    afx_msg void OnEnKillfocusEditSearchPath();
    afx_msg void OnEnKillfocusEditSkipPath();
    afx_msg void OnEnKillfocusEditOutPath();
};
