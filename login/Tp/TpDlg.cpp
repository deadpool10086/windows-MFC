// TpDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Tp.h"
#include "TpDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTpDlg dialog

CTpDlg::CTpDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTpDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTpDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTpDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTpDlg, CDialog)
	//{{AFX_MSG_MAP(CTpDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOUSEMOVE()
	ON_WM_SETCURSOR()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTpDlg message handlers
CTpApp theApp;
BOOL CTpDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	int nleft = theApp.GetProfileInt("WindowRect","left",-1);
	int nright = theApp.GetProfileInt("WindowRect","right",-1);
	int ntop = theApp.GetProfileInt("WindowRect","top",-1);
	int nbottom = theApp.GetProfileInt("WindowRect","bottom",-1);
	MoveWindow(nleft,ntop,nright-nleft,nbottom-ntop);


	//SetWindowText(theApp.m_lpCmdLine);
	CString str;
	str.Format("%d",theApp.m_nCmdShow);
	SetWindowText(str);

	SetDlgItemText(IDC_AppName,theApp.m_pszAppName);
	SetDlgItemText(IDC_ExeName,theApp.m_pszExeName);
	SetDlgItemText(IDC_HelpName,theApp.m_pszHelpFilePath);
	SetDlgItemText(IDC_RegistKey,theApp.m_pszRegistryKey);
	SetDlgItemText(IDC_ProFile,theApp.m_pszProfileName);


	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
//	HICON hIcon = theApp.LoadIcon(IDI_ICON1);
//	HICON hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
//	HICON hIcon = ::LoadIcon(AfxGetInstanceHandle(),(LPSTR)IDI_ICON1);
	HICON hIcon = ::LoadIcon(NULL,(LPSTR)IDI_QUESTION);

	

	SetIcon(hIcon, TRUE);			// Set big icon
	SetIcon(hIcon, FALSE);		// Set small icon
	
	CWnd* pWnd = AfxGetMainWnd();

	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTpDlg::OnPaint() 
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
HCURSOR CTpDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTpDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
//	HCURSOR hCur = theApp.LoadCursor(IDC_CURSOR1);
//	SetCursor(hCur);	
	CDialog::OnMouseMove(nFlags, point);
}

BOOL CTpDlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	switch(pWnd ->GetDlgCtrlID())
	{
		case IDOK:
		case IDCANCEL:
			{
				HCURSOR hCur = theApp.LoadStandardCursor(IDC_CROSS);
				SetCursor(hCur);
				return true;	
			}
	}
	
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}

void CTpDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	CRect rect;
	GetWindowRect(rect);

	theApp.WriteProfileInt("WindowRect","left",rect.left);
	theApp.WriteProfileInt("WindowRect","right",rect.right);
	theApp.WriteProfileInt("WindowRect","top",rect.top);
	theApp.WriteProfileInt("WindowRect","bottom",rect.bottom);
	
}
