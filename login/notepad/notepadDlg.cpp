// notepadDlg.cpp : implementation file
//

#include "stdafx.h"
#include "notepad.h"
#include "notepadDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNotepadDlg dialog

CNotepadDlg::CNotepadDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNotepadDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNotepadDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNotepadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNotepadDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CNotepadDlg, CDialog)
	//{{AFX_MSG_MAP(CNotepadDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNotepadDlg message handlers

BOOL CNotepadDlg::OnInitDialog()
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

void CNotepadDlg::OnPaint() 
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
HCURSOR CNotepadDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CNotepadDlg::OnFileSave() 
{
	CFile file;
	if(!file.Open("./text.txt",CFile::modeCreate|CFile::modeWrite))
	{
		AfxMessageBox("±£´æÎÄ¼þÊ§°Ü");
		return;
	}
	char s[2048] = {0};
	GetDlgItemText(IDC_TEXT,s,sizeof(s));
	file.Write(s,strlen(s));
	file.Close();
}

void CNotepadDlg::OnFileOpen() 
{
	CFile file;
	if(!file.Open("./text.txt",CFile::modeRead))
	{
		return;
	}
	char s[2048];
	int nLen = file.Read(s,sizeof(s));
	s[nLen] = 0;
	SetDlgItemText(IDC_TEXT,s);
}
