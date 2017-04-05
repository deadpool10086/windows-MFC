// TcpdeomDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Tcpdeom.h"
#include "TcpdeomDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTcpdeomDlg dialog

CTcpdeomDlg::CTcpdeomDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTcpdeomDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTcpdeomDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTcpdeomDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTcpdeomDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTcpdeomDlg, CDialog)
	//{{AFX_MSG_MAP(CTcpdeomDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTcpdeomDlg message handlers

BOOL CTcpdeomDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	if(!m_sock.Create())
	{
		AfxMessageBox("ÍøÂç´´½¨Ê§°Ü");
	}
	if(!m_sock.Connect("192.168.47.129",8881))
	{
		int nErr = GetLastError(); 
		AfxMessageBox("ÍøÂçÁ¬½ÓÊ§°Ü");
	}
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTcpdeomDlg::OnPaint() 
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
HCURSOR CTcpdeomDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTcpdeomDlg::OnOK() 
{
	CString str;
	GetDlgItemText(IDC_INPUT,str);
	if(str.IsEmpty())
	{
		return;	
	}
	m_sock.Send(str,str.GetLength());
	
//	CDialog::OnOK();
}
