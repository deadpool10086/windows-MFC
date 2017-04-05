// mfc2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "mfc2.h"
#include "mfc2Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMfc2Dlg dialog

CMfc2Dlg::CMfc2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMfc2Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMfc2Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMfc2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMfc2Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMfc2Dlg, CDialog)
	//{{AFX_MSG_MAP(CMfc2Dlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMfc2Dlg message handlers

BOOL CMfc2Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

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

void CMfc2Dlg::OnPaint() 
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
HCURSOR CMfc2Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMfc2Dlg::OnButton1() 
{
	CTime t = CTime::GetCurrentTime();
	int nYear = t.GetYear();
	int nDay = t.GetDay();
	int nMonth = t.GetMonth();
	int nHour = t.GetHour();
	int nMin = t.GetMinute();
	int nSec = t.GetSecond();
	int nWeek = t.GetDayOfWeek();
	CString str;
	str.Format("当前时间为 %d年%d月%d日 %02d:%02d:%02d",nYear, nMonth, nDay, nHour, nMin, 
		nSec);
	//AfxMessageBox(str);
	SetWindowText(str);
}

void CMfc2Dlg::OnButton2() 
{
 time_t tt = time(NULL); 	
}
