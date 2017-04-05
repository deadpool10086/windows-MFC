// udpDlg.cpp : implementation file
//

#include "stdafx.h"
#include "udp.h"
#include "udpDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUdpDlg dialog

CUdpDlg::CUdpDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUdpDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUdpDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CUdpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUdpDlg)
	DDX_Control(pDX, IDC_HIST, m_hist);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CUdpDlg, CDialog)
	//{{AFX_MSG_MAP(CUdpDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUdpDlg message handlers

BOOL CUdpDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	BOOL b = m_sock.Create(8811,SOCK_DGRAM);
 	DWORD nErr = GetLastError();
	SetDlgItemText(IDC_IP,"192.168.1.110");
	SetDlgItemText(IDC_PORT,"8811");
	if(WSANOTINITIALISED == nErr)
	{    
		AfxMessageBox("asd");
	}
	if(WSAEADDRINUSE == nErr)
	{
		AfxMessageBox("asdasd");
	}
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CUdpDlg::OnPaint() 
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
HCURSOR CUdpDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}




void CUdpDlg::OnOK() 
{
	CString str;
	GetDlgItemText(IDC_INPUT,str);
	if(str.IsEmpty())
	{
		AfxMessageBox("不能发送空文字");
		return;
	}
	CString szIP;
	GetDlgItemText(IDC_IP,szIP);
	m_sock.SendTo(str,str.GetLength(),8811,szIP);
	SetDlgItemText(IDC_INPUT,"");

	CString Rstr = szIP;
	Rstr += ":\r\n";
	Rstr += str;
	Rstr += ":\r\n";
	int nLen = m_hist.GetWindowTextLength();
	m_hist.SetSel(nLen,-1);
	m_hist.ReplaceSel(Rstr);
	return;
	//CDialog::OnOK();
}



void CUdpDlg::OnReceive(LPCSTR szText, LPCSTR szIP)
{
	CString str = szIP;
	str += ":\r\n";
	str += szText;
	str += ":\r\n";
	int nLen = m_hist.GetWindowTextLength();
	m_hist.SetSel(nLen,-1);
	m_hist.ReplaceSel(str);

}
