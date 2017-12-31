// MyFtpDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyFtp.h"
#include "MyFtpDlg.h"
#include "Afxinet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyFtpDlg dialog

CMyFtpDlg::CMyFtpDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyFtpDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyFtpDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyFtpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyFtpDlg)
	DDX_Control(pDX, IDC_LIST_FILES, m_ListFiles);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyFtpDlg, CDialog)
	//{{AFX_MSG_MAP(CMyFtpDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_QURY, OnQury)
	ON_BN_CLICKED(IDC_DOWNLOAD, OnDownload)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyFtpDlg message handlers

BOOL CMyFtpDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMyFtpDlg::OnPaint() 
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

HCURSOR CMyFtpDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMyFtpDlg::OnQury() 
{
	UpdateData(true);
	CString strSvr="";
	GetDlgItem(IDC_SERVER)->GetWindowText(strSvr);
	if(strSvr == "")
		return;
	while(m_ListFiles.GetCount() != 0)
		m_ListFiles.DeleteString(0);
	CInternetSession* pSession = NULL;
	CFtpConnection* pFtpCon = NULL;
	CFtpFileFind* pFtpFileFind = NULL;
	pSession = new CInternetSession(AfxGetAppName(), 1, PRE_CONFIG_INTERNET_ACCESS);
	if(pSession==NULL)
		return;
	pFtpCon=pSession->GetFtpConnection(strSvr,"","");
	if(pFtpCon==NULL)
		return;
	pFtpFileFind = new CFtpFileFind(pFtpCon);
	if(pFtpFileFind == NULL)
		return;
	BOOL bFind=false;
	CString strFile = "";
	bFind = pFtpFileFind->FindFile("*");
	while(bFind)
	{
		bFind = pFtpFileFind->FindNextFile();
		strFile=pFtpFileFind->GetFileName();
		if(pFtpFileFind->IsDirectory())
			strFile="["+strFile+"]";
		m_ListFiles.AddString(strFile);
	}
	pFtpFileFind->Close();
	delete pFtpFileFind;
	pFtpCon->Close();
	delete pFtpCon;
	pSession=NULL;
	delete pSession;
}

void CMyFtpDlg::OnDownload() 
{
	UpdateData(true);
	int iSel=0;
	iSel= m_ListFiles.GetCurSel();
	if(iSel<0)
		return;
	CString strDownFile="";
	CString strSaveFile="";
	m_ListFiles.GetText(iSel, strDownFile);
	if(strDownFile.GetAt(0) != '[')
	{
		CFileDialog dlg(FALSE,"","*.*");
		if(dlg.DoModal()==IDOK)
		{
			strSaveFile=dlg.GetPathName();
			if(!DownloadFile(strDownFile, strSaveFile))
				AfxMessageBox("下载失败",MB_OK);
			else
				AfxMessageBox("下载成功",MB_OK);
		}
	}
}

BOOL CMyFtpDlg::DownloadFile(CString strSfile, CString strDFile)
{
	CInternetSession* pSession = NULL;
	CFtpConnection* pFtpCon=NULL;
	CString strSvr="";
	GetDlgItem(IDC_SERVER)->GetWindowText(strSvr);
	if(strSvr == "")
		return false;
	pSession = new CInternetSession(AfxGetAppName(),1, PRE_CONFIG_INTERNET_ACCESS);
	if(pSession == NULL)
		return false;
	pFtpCon=pSession->GetFtpConnection(strSvr,"","");
	if(pFtpCon==NULL)
		return false;
	if(!pFtpCon->GetFile(strSfile,strDFile))
	{
		pFtpCon->Close();
		delete pFtpCon;
		pSession->Close();
		delete pSession;
		return false;
	}
	pFtpCon->Close();
	delete pFtpCon;
	pSession=NULL;
	delete pSession;
	return true;
}
