// CSocketServerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CSocketServer.h"
#include "CSocketServerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include "msg.h"
/////////////////////////////////////////////////////////////////////////////
// CCSocketServerDlg dialog

CCSocketServerDlg::CCSocketServerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCSocketServerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCSocketServerDlg)
	m_nPort = 0;
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pLSocket = NULL;
}

void CCSocketServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCSocketServerDlg)
	DDX_Control(pDX, IDC_LIST_MSG, m_listMsg);
	DDX_Control(pDX, IDOK, m_btnClose);
	DDX_Control(pDX, IDC_BUTTON_LISTEN, m_btnListen);
	DDX_Control(pDX, IDC_STATIC_NUM, m_staNum);
	DDX_Text(pDX, IDC_EDIT_PORT, m_nPort);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCSocketServerDlg, CDialog)
	//{{AFX_MSG_MAP(CCSocketServerDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, OnClose)
	ON_BN_CLICKED(IDC_BUTTON_LISTEN, OnButtonListen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCSocketServerDlg message handlers

BOOL CCSocketServerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	m_nPort = 8899;
	UpdateData(FALSE);
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCSocketServerDlg::OnPaint() 
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

HCURSOR CCSocketServerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCSocketServerDlg::OnClose() 
{
	// TODO: Add your control notification handler code here
	CMsg msg;
	msg.m_strText="服务器终止服务！";
	delete m_pLSocket;
	m_pLSocket = NULL;
	while(!m_connList.IsEmpty())
	{
		CCSocket* pSocket = (CCSocket*)m_connList.RemoveHead();
		pSocket->SendMessage(&msg);
		delete pSocket;
	}
	while(m_listMsg.GetCount()!=0) m_listMsg.DeleteString(0);
}

void CCSocketServerDlg::OnButtonListen() 
{
	// TODO: Add your control notification handler code here
	AfxSocketInit();
	UpdateData(TRUE);
	m_pLSocket = new CLSocket(this);
	if(!m_pLSocket->Create(m_nPort))
	{
		delete m_pLSocket;
		m_pLSocket = NULL;
		CString strTemp;
		strTemp.Format("在线人数：%d",GetLastError());
		AfxMessageBox(strTemp);
		return;
	}
	if(!m_pLSocket->Listen())
	{
		delete m_pLSocket;
		m_pLSocket = NULL;
		AfxMessageBox("启动监听错误");
		return;
	}
}

void CCSocketServerDlg::OnAccept()
{
	CCSocket* pSocket = new CCSocket(this);
	if(m_pLSocket->Accept(*pSocket))
	{
		pSocket->Initialize();
		m_connList.AddTail(pSocket);
		CString strTemp;
		strTemp.Format("在线人数：%d",m_connList.GetCount());
		m_staNum.SetWindowText(strTemp);
	} else delete pSocket;
}

void CCSocketServerDlg::OnReceive(CCSocket* pSocket)
{
	static CMsg msg;
	do{
		pSocket->ReceiveMessage(&msg);
		m_listMsg.AddString(msg.m_strText);
		UpdateData(FALSE);
		backClients(&msg);
		if(msg.m_bClose)
		{
			pSocket->Close();
			POSITION pos,temp;
			for(pos=m_connList.GetHeadPosition();pos!=NULL;)
			{
				temp = pos;
				CCSocket* pSock = (CCSocket*)m_connList.GetNext(pos);
				if(pSock == pSocket)
				{
					m_connList.RemoveAt(temp);
					CString strTemp;
					strTemp.Format("在线人数：%d",m_connList.GetCount());
					m_staNum.SetWindowText(strTemp);
					break;
				}
			}
			delete pSocket;
			break;
		}
	}while(!pSocket->m_pArchiveIn->IsBufferEmpty());
}

void CCSocketServerDlg::backClients(CMsg *pMsg)
{
	for (POSITION pos = m_connList.GetHeadPosition(); pos!=NULL;)
	{
		CCSocket* pSocket = (CCSocket*)m_connList.GetNext(pos);
		pSocket->SendMessage(pMsg);
	}
}
