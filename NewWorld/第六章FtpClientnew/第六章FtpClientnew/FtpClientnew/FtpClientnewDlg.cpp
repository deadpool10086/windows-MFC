// FtpClientnewDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FtpClientnew.h"
#include "FtpClientnewDlg.h"
#include "Afxinet.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFtpClientnewDlg dialog

CFtpClientnewDlg::CFtpClientnewDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFtpClientnewDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFtpClientnewDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFtpClientnewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFtpClientnewDlg)
	DDX_Control(pDX, IDC_LIST_FILE, m_ListFile);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFtpClientnewDlg, CDialog)
	//{{AFX_MSG_MAP(CFtpClientnewDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, OnQury)
	ON_BN_CLICKED(IDC_BUT_DOWNLOAD, OnButDownload)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFtpClientnewDlg message handlers

BOOL CFtpClientnewDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFtpClientnewDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFtpClientnewDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFtpClientnewDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CFtpClientnewDlg::OnQury() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CString strSvr="";
	GetDlgItem(IDC_EDIT_SVRNAME)->GetWindowText(strSvr);
	if(strSvr=="")
		return;
   while(m_ListFile.GetCount ()!=0)
		m_ListFile.DeleteString (0);

	CInternetSession* pSession=NULL;
	CFtpConnection* pFtpCon=NULL;
	CFtpFileFind* pFtpFileFind=NULL;
	
	pSession=new CInternetSession(AfxGetAppName(),1,PRE_CONFIG_INTERNET_ACCESS);
	if(pSession==NULL)
		return;
	pFtpCon=pSession->GetFtpConnection (strSvr,"","");
	if(pFtpCon==NULL)
		return;
	pFtpFileFind=new CFtpFileFind(pFtpCon);
	if(pFtpFileFind==NULL)
		return;
	BOOL bFind=false;
	CString strFile="";
	bFind=pFtpFileFind->FindFile ("*");
	while(bFind)
	{
		bFind=pFtpFileFind->FindNextFile ();
		strFile=pFtpFileFind->GetFileName ();
		if(pFtpFileFind->IsDirectory ())
			strFile="["+strFile+"]";
		m_ListFile.AddString (strFile);
	}
	pFtpFileFind->Close ();
	delete pFtpFileFind;
	pFtpCon->Close();
	delete pFtpCon;
	pSession=NULL;
	delete pSession;




	
}

void CFtpClientnewDlg::OnButDownload() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	int iSel=0;
	iSel=m_ListFile.GetCurSel ();
	if(iSel<0)
		return;

	CString strDownFile="";
	CString strSaveFile="";
	m_ListFile.GetText (iSel,strDownFile);
	if(strDownFile.GetAt (0)!='[')//选择的是文件
	{
		CFileDialog dlg(FALSE,"","*.*");   //定义了一个文件对话框对象变量
		if (dlg.DoModal()==IDOK)        //激活文件对话框
		{
			strSaveFile=dlg.GetPathName ();
			if(!DownLoadFile(strDownFile,strSaveFile))
				AfxMessageBox("下载失败!",MB_OK|MB_ICONSTOP);
			else
				AfxMessageBox("下载成功!",MB_OK|MB_ICONINFORMATION);

		}
	}
//	DownLoadFile(CString strSFile, CString strDFile);
	
}

BOOL CFtpClientnewDlg::DownLoadFile(CString strSFile, CString strDFile)
{
	CInternetSession* pSession=NULL;
	CFtpConnection* pFtpCon=NULL;
    CString strSvr="";
	GetDlgItem(IDC_EDIT_SVRNAME)->GetWindowText(strSvr);
	if(strSvr=="")
		return false;
	
	pSession=new CInternetSession(AfxGetAppName(),1,PRE_CONFIG_INTERNET_ACCESS);
	if(pSession==NULL)
		return false;
	pFtpCon=pSession->GetFtpConnection (strSvr,"","");
	if(pFtpCon==NULL)
		return false;
    if(!pFtpCon->GetFile (strSFile,strDFile))
	{
		pFtpCon->Close();
		delete pFtpCon;
		pSession->Close ();
		delete pSession;
		return false;
	}
	pFtpCon->Close();
	delete pFtpCon;
	pSession=NULL;
	delete pSession;
	return true;





}
