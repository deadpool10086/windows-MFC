// TestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Test.h"
#include "TestDlg.h"
#include "AboutDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestDlg dialog

CTestDlg::CTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTestDlg, CDialog)
	//{{AFX_MSG_MAP(CTestDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestDlg message handlers

BOOL CTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
//	GetDlgItem(IDC_BUTTON1) ->SetWindowText("测试");
	SetDlgItemText(IDC_BUTTON1,"aaa");
	SetTimer(1,500,NULL);
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTestDlg::OnPaint() 
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
HCURSOR CTestDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTestDlg::OnButton1() 
{	//模式对话框: DoModal
	CAboutDlg dlg;
	dlg.DoModal();
}

void CTestDlg::OnButton2() 
{
	//非模式对话框:Create
	if(!m_cdlg)
	{
		m_cdlg.Create(IDD_CHA_DLG,GetDesktopWindow());
	
	}
	m_cdlg.ShowWindow(SW_SHOW);	
	m_cdlg.SetActiveWindow();
//	CChatDlg * pDlg = new CChatDlg;
//	pDlg ->Create(IDD_CHA_DLG,GetDesktopWindow());
//	pDlg ->ShowWindow(SW_SHOW);
}

int CTestDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	
	return 0;
}

void CTestDlg::OnDestroy() 
{
//	AfxMessageBox("走了");
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	
}
//管理所有系统菜单和系统按纽消息
//DEL void CTestDlg::OnSysCommand(UINT nID, LPARAM lParam) 
//DEL {
//DEL 	switch(nID)
//DEL 	{
//DEL 	case SC_CLOSE:
//DEL 			ShowWindow(SW_MINIMIZE);
//DEL 			return;
//DEL 	}
//DEL 	CDialog::OnSysCommand(nID, lParam);
//DEL }

void CTestDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
//	ShowWindow(SW_MINIMIZE);
	CDialog::OnClose();
}

void CTestDlg::OnCancel() 
{
	//ShowWindow(SW_MINIMIZE);
	CDialog::OnCancel();
}

void CTestDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}

void CTestDlg::OnButton3() 
{
	CWnd* pWnd = GetDlgItem(IDOK);
	if(pWnd->GetSafeHwnd())
	pWnd ->DestroyWindow();
}

void CTestDlg::OnButton4() 
{
//	m_wnd.Create("Edit","as",WS_CHILD|WS_VISIBLE,CRect(10,150,110,180),this,IDC_NAMESS);
	if(!m_wnd)
	m_wnd.CreateEx(WS_EX_CLIENTEDGE,"Edit","as",WS_CHILD|WS_VISIBLE,CRect(10,150,110,180),this,IDC_NAMESS);
	if(!m_wndButton)
	m_wndButton.Create("button","测试Create",WS_CHILD|WS_VISIBLE,CRect(140,150,240,180),this,IDC_NAME);
	return;
}

void CTestDlg::OnButton5() 
{
	if(m_cdlg)
		m_cdlg.SetActiveWindow();
}

void CTestDlg::OnTimer(UINT nIDEvent) 
{
	CWnd * pWnd = GetActiveWindow();
	if(pWnd)
	{
		CString str;
		pWnd->GetWindowText(str);
		SetWindowText(str);
	}
	CDialog::OnTimer(nIDEvent);
}
