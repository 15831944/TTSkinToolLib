
// TTSkinToolDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TTSkinTool.h"
#include "TTSkinToolDlg.h"
#include <string>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//#pragma comment(lib, "TTSkinToolLibUD.lib")


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CTTSkinToolDlg dialog




CTTSkinToolDlg::CTTSkinToolDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTTSkinToolDlg::IDD, pParent)
    , m_strSkinPath(_T(""))
    , m_strOutPath(_T(""))
    , m_strSearchPath(_T(""))
    , m_strOutFilePath(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

    m_pTTSin = NULL;
    m_pTTSkinSearch = NULL;
}

void CTTSkinToolDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT_SKIP_PATH, m_strSkinPath);
    DDX_Text(pDX, IDC_EDIT_OUT_PATH, m_strOutPath);
    DDX_Text(pDX, IDC_EDIT_SEARCH_PATH, m_strSearchPath);
    DDX_Text(pDX, IDC_EDIT_OUT_FILE_PATH, m_strOutFilePath);
    DDX_Control(pDX, IDC_STATIC_TIME, m_LableTime);
}

BEGIN_MESSAGE_MAP(CTTSkinToolDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
    ON_WM_DESTROY()
    ON_BN_CLICKED(IDC_BTN_SELECT_SKIN_PATH, &CTTSkinToolDlg::OnBnClickedBtnSelectSkinPath)
    ON_BN_CLICKED(IDC_BTN_OUT_PATH, &CTTSkinToolDlg::OnBnClickedBtnOutPath)
    ON_BN_CLICKED(IDC_BTN_SEARCH, &CTTSkinToolDlg::OnBnClickedBtnSearch)
    ON_BN_CLICKED(IDC_BTN_START, &CTTSkinToolDlg::OnBnClickedBtnStart)
    ON_BN_CLICKED(IDC_BTN_OUT_FILE_PATH, &CTTSkinToolDlg::OnBnClickedBtnOutFilePath)
    ON_EN_KILLFOCUS(IDC_EDIT_SEARCH_PATH, &CTTSkinToolDlg::OnEnKillfocusEditSearchPath)
    ON_EN_KILLFOCUS(IDC_EDIT_SKIP_PATH, &CTTSkinToolDlg::OnEnKillfocusEditSkipPath)
    ON_EN_KILLFOCUS(IDC_EDIT_OUT_PATH, &CTTSkinToolDlg::OnEnKillfocusEditOutPath)
END_MESSAGE_MAP()


// CTTSkinToolDlg message handlers

BOOL CTTSkinToolDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
    m_pTTSin = CreateSkinToolInstance();
    m_pTTSkinSearch = CreateSkinToolSearchInstance();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTTSkinToolDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTTSkinToolDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTTSkinToolDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//�˳��Ի���
void CTTSkinToolDlg::OnDestroy()
{
    CDialog::OnDestroy();

    if (NULL != m_pTTSin)
    {
        DestorySkinToolInstance(m_pTTSin);
        m_pTTSin = NULL;
    }

    if (NULL != m_pTTSkinSearch)
    {
        DestorySkinToolSearchInstance(m_pTTSkinSearch);
        m_pTTSkinSearch = NULL;
    }
}

//ѡ��Ƥ��·��BUTTON
void CTTSkinToolDlg::OnBnClickedBtnSelectSkinPath()
{
    UpdateData(TRUE);
    TCHAR szDir[MAX_PATH];
    BROWSEINFO browserinfo;
    ITEMIDLIST *pItemDList;

    browserinfo.hwndOwner = this->m_hWnd;
    browserinfo.pidlRoot = NULL;
    browserinfo.pszDisplayName = szDir;
    browserinfo.lpszTitle = _T("��ѡ��Ƥ��Ŀ¼");
    browserinfo.ulFlags = BIF_STATUSTEXT | BIF_USENEWUI | BIF_RETURNONLYFSDIRS;
    browserinfo.lpfn = NULL;
    browserinfo.lParam = 0;
    browserinfo.iImage = 0;
    pItemDList = SHBrowseForFolder(&browserinfo);

    if (NULL == pItemDList)
    {
        return;
    }
    if (!SHGetPathFromIDList(pItemDList, szDir))
    {
        return;
    }
    else
    {
        m_strSkinPath = szDir;
    }

    UpdateData(FALSE);

    if (NULL != m_pTTSin)
    {
        //����Ƥ��·��
        wstring strTmp = m_strSkinPath.GetBuffer(0);
        m_pTTSin->SetSkinFilePath(strTmp);
    }
}

//ѡ�����·��BUTTON
void CTTSkinToolDlg::OnBnClickedBtnOutPath()
{
    UpdateData(TRUE);
    TCHAR szDir[MAX_PATH];
    BROWSEINFO browserinfo;
    ITEMIDLIST *pItemDList;

    browserinfo.hwndOwner = this->m_hWnd;
    browserinfo.pidlRoot = NULL;
    browserinfo.pszDisplayName = szDir;
    browserinfo.lpszTitle = _T("��ѡ�����Ŀ¼");
    browserinfo.ulFlags = BIF_STATUSTEXT | BIF_USENEWUI | BIF_RETURNONLYFSDIRS;
    browserinfo.lpfn = NULL;
    browserinfo.lParam = 0;
    browserinfo.iImage = 0;
    pItemDList = SHBrowseForFolder(&browserinfo);

    if (NULL == pItemDList)
    {
        return;
    }

    if (!SHGetPathFromIDList(pItemDList, szDir))
    {
        return;
    }
    else
    {
        m_strOutPath = szDir;
    }

    UpdateData(FALSE);

    if (NULL != m_pTTSin)
    {
        //�������·��
        m_pTTSin->SetOutPath(m_strOutPath.GetBuffer(0));
    }
}


void CTTSkinToolDlg::OnBnClickedBtnSearch()
{
    UpdateData(TRUE);
    if(m_strSearchPath.IsEmpty())
    {
        MessageBox(L"��ָ���ļ���", L"�������ļ���", MB_ICONEXCLAMATION);
        return;
    }

    if (m_strOutFilePath.IsEmpty())
    {
        MessageBox(L"��ָ��Ŀ���ļ���", L"������Ŀ���ļ���", MB_ICONEXCLAMATION);
        return;
    }

    if(NULL != m_pTTSkinSearch)
    {
        if (m_pTTSkinSearch->SetTargetFile(m_strOutFilePath.GetBuffer(0)))
        {
            DWORD dwStart = GetTickCount();
            LPBYTE pData = NULL;
            DWORD dwBufSize = 0;
            pData = m_pTTSkinSearch->Search(m_strSearchPath.GetBuffer(0), &dwBufSize);
            if (NULL != pData)
            {
                //�Զ�����д�ķ�ʽ���ļ�
                FILE *fp = fopen("c:\\out.bmp","wb");
                if(NULL == fp)
                {
                    return ;
                }

                //дλͼ���ݽ��ļ�
                fwrite(pData, dwBufSize, 1, fp);
                //delete[] pData;
                pData = NULL;

                //�ر��ļ�
                fclose(fp);

                DWORD dwEnd = GetTickCount();
                DWORD dwTime = dwEnd - dwStart;
                CString strTime;
                strTime.Format(L"%d (ms)",dwTime);
                m_LableTime.SetWindowText(strTime);
                if(MessageBox(L"��ϲ�㣬�ҵ��ˣ�~Ҫ��ʾô?", L"����", MB_YESNO) == IDYES)
                {
                    //����shell����ʾͼƬ
                    ShellExecute(NULL, L"open", L"mspaint.exe", L"c:\\out.bmp",NULL,SW_SHOW);
                }
            }else
            {
                MessageBox(L"�ף������Ʒ���ã�û�ҵ�!~", L"���ҽ��",MB_ICONEXCLAMATION );
            }
        }    
    }
}

void CTTSkinToolDlg::OnBnClickedBtnStart()
{
    UpdateData(TRUE);
   if (m_strSkinPath.IsEmpty())
   {
       MessageBox(L"������Ƥ��·��", L"������·��", MB_ICONEXCLAMATION);
       return;
   }

   if (m_strOutPath.IsEmpty())
   {
       MessageBox(L"���������·��", L"������·��", MB_ICONEXCLAMATION);
       return;
   }

   if (NULL != m_pTTSin)
   {
        //ת��
        DWORD dwStart = GetTickCount();
        if (m_pTTSin->Formatting())
        {
            DWORD dwEnd = GetTickCount();
            DWORD dwTime = dwEnd - dwStart;
            CString strTime;
            strTime.Format(L"%d (ms)",dwTime);
            m_LableTime.SetWindowText(strTime);
            MessageBox(L"ת���ɹ�", L"ת���ɹ�", MB_OK);
        }
        else
        {
            MessageBox(L"ת��ʧ��", L"ת��ʧ��", MB_ICONERROR);
        }
   }
}

void CTTSkinToolDlg::OnBnClickedBtnOutFilePath()
{
    // TODO: Add your control notification handler code here
    const TCHAR pszFilter[] = _T("All Files (*.*)|*.*||");
    CFileDialog fileDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, pszFilter, this);

    fileDlg.m_ofn.lpstrInitialDir = L"c:\\";  //���öԻ���Ĭ�ϳ��ֵ�·��

    if(fileDlg.DoModal() == IDOK)
    {
        m_strOutFilePath = fileDlg.GetPathName();
        UpdateData(FALSE);
    }
}

void CTTSkinToolDlg::OnEnKillfocusEditSearchPath()
{
    // TODO: Add your control notification handler code here
    GetDlgItemText(IDC_EDIT_SEARCH_PATH, m_strSearchPath);
}

void CTTSkinToolDlg::OnEnKillfocusEditSkipPath()
{
    // TODO: Add your control notification handler code here
    GetDlgItemText(IDC_EDIT_SKIP_PATH, m_strSkinPath);
    if (NULL != m_pTTSin)
    {
        //����Ƥ��·��
        m_pTTSin->SetSkinFilePath(m_strSkinPath.GetBuffer(0));
    }
}

void CTTSkinToolDlg::OnEnKillfocusEditOutPath()
{
    // TODO: Add your control notification handler code here
    GetDlgItemText(IDC_EDIT_OUT_PATH, m_strOutPath);
    if (NULL != m_pTTSin)
    {
        //�������·��
        m_pTTSin->SetOutPath(m_strOutPath.GetBuffer(0));
    }
}
