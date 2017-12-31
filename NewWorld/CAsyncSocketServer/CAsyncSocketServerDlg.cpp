// CAsyncSocketServerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CAsyncSocketServer.h"
#include "CAsyncSocketServerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCAsyncSocketServerDlg dialog

CCAsyncSocketServerDlg::CCAsyncSocketServerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCAsyncSocketServerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCAsyncSocketServerDlg)
	m_strServName = _T("");
	m_nServPort = 0;
	m_strMsg = _T("");
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCAsyncSocketServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCAsyncSocketServerDlg)
	DDX_Control(pDX, IDC_LIST_RECEIVED, m_listReceived);
	DDX_Control(pDX, IDC_LIST_SENT, m_listSent);
	DDX_Control(pDX, IDC_BUTTON_LISTEN, m_btnListen);
	DDX_Text(pDX, IDC_EDIT_SERVNAME, m_strServName);
	DDX_Text(pDX, IDC_EDIT_SERVPORT, m_nServPort);
	DDX_Text(pDX, IDC_EDIT_MSG, m_strMsg);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCAsyncSocketServerDlg, CDialog)
	//{{AFX_MSG_MAP(CCAsyncSocketServerDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_CLOSE, OnButtonClose)
	ON_BN_CLICKED(IDC_BUTTON_LISTEN, OnButtonListen)
	ON_BN_CLICKED(IDOK, OnSendMsg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCAsyncSocketServerDlg message handlers

BOOL CCAsyncSocketServerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_strServName = "127.0.0.1";
	m_nServPort = 8899;
	UpdateData(FALSE);
	m_sListenSocket.SetParent(this);
	m_sConnectSocket.SetParent(this);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCAsyncSocketServerDlg::OnPaint() 
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

HCURSOR CCAsyncSocketServerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCAsyncSocketServerDlg::OnButtonClose() 
{
	// TODO: Add your control notification handler code here
	OnClose();
}

void CCAsyncSocketServerDlg::OnButtonListen() 
{
	// TODO: Add your control notification handler code here
	AfxSocketInit();
	UpdateData(TRUE);
	m_sListenSocket.Create(m_nServPort);
	m_sListenSocket.Listen();
	
}

void CCAsyncSocketServerDlg::OnSendMsg() 
{
	// TODO: Add your control notification handler code here
	int nLen;
	int nSent;
	UpdateData(TRUE);
	if (!m_strMsg.IsEmpty())
	{
		nLen = m_strMsg.GetLength();
		nSent = m_sConnectSocket.Send(LPCTSTR(m_strMsg), nLen);
		if(nSent != SOCKET_ERROR)
		{
			m_listSent.AddString(m_strMsg);
			UpdateData(FALSE);
		}else{
			AfxMessageBox("信息发送处错！",MB_OK|MB_ICONSTOP);
		}
		m_strMsg.Empty();
		UpdateData(FALSE);
	}
}

void CCAsyncSocketServerDlg::OnClose()
{
	m_listReceived.AddString("服务器关闭");
	m_sConnectSocket.Close();

	while(m_listSent.GetCount != 0) m_listSent.DeleteItem(0);
	while(m_listReceived.GetCount != 0) m_listReceived.DeleteItem(0);
}

void CCAsyncSocketServerDlg::OnAccept()
{
	m_listReceived.AddString("服务器收到了链接消息");
	m_sListenSocket.Accept(m_sConnectSocket);
}

void CCAsyncSocketServerDlg::OnReceive()
{
	char* pBuf = new char[1025];
	int nBufSize = 1024;
	int nReceived;
	CString strReceived;
	m_listReceived.AddString("服务器收到了消息");
	nReceived = m_sConnectSocket.Receive(pBuf, nBufSize);
	if (nReceived != SOCKET_ERROR)
	{
		pBuf[nReceived] = NULL;
		strReceived = pBuf;
		m_listReceived.AddString(strReceived);
	}else
	{
		AfxMessageBox("信息接收处错！",MB_OK|MB_ICONSTOP);
	}
}
