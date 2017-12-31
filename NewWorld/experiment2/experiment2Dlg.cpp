// experiment2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "experiment2.h"
#include "experiment2Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExperiment2Dlg dialog

struct What{
	int a;
	CExperiment2Dlg * p;
};

SOCKET* CExperiment2Dlg::sClients = new SOCKET[50];
int CExperiment2Dlg::clientNum = 0;
sockaddr_in* CExperiment2Dlg::remoteAddrs = new sockaddr_in[50];

CExperiment2Dlg::CExperiment2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CExperiment2Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExperiment2Dlg)
	m_sip = _T("");
	m_nport = 0;
	m_strMessage = _T("");
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExperiment2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CExperiment2Dlg)
	DDX_Control(pDX, IDC_MESSAGES, m_messages);
	DDX_Text(pDX, IDC_IP, m_sip);
	DDX_Text(pDX, IDC_PORT, m_nport);
	DDX_Text(pDX, IDC_MESSAGE, m_strMessage);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CExperiment2Dlg, CDialog)
	//{{AFX_MSG_MAP(CExperiment2Dlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SETUP, OnSetup)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExperiment2Dlg message handlers

BOOL CExperiment2Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	m_nport = 8899;
	UpdateData(FALSE);
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CExperiment2Dlg::OnPaint() 
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

HCURSOR CExperiment2Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CExperiment2Dlg::OnSetup() 
{
	WORD sockVersion = MAKEWORD(2, 2);
	WSAData wsaData;
	WSAStartup(sockVersion, &wsaData);
	//sClients = new SOCKET[50];
	clientNum=0;
	
	SOCKET slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(slisten == INVALID_SOCKET)
	{
		AfxMessageBox("创立监听端口出错!",MB_OK|MB_ICONSTOP);
		return;
	}

	UpdateData(TRUE);
	sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(m_nport);
	sin.sin_addr.S_un.S_addr = INADDR_ANY;
	if(bind(slisten, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR)
	{
		AfxMessageBox("绑定出错!",MB_OK|MB_ICONSTOP);
		return;
	}
	if(listen(slisten, 5) == SOCKET_ERROR)
	{
		AfxMessageBox("监听!",MB_OK|MB_ICONSTOP);
		return;
	}

	remoteAddrs = new sockaddr_in[50];
	hhhhh = slisten;
	CWinThread* pThread; //定义一个线程指针
	//pThread = ::AfxBeginThread(Accept,&slisten);
	pThread = ::AfxBeginThread(Accept,this);
	pThread->Run();
	return;
}



UINT CExperiment2Dlg::Accept(LPVOID pParam)
{
	int nAddrlen = sizeof(sockaddr_in);
	SOCKET slisten = ((CExperiment2Dlg *)pParam)->hhhhh;
	What *canshu;
	while (clientNum < 50)
	{
		AfxMessageBox("等待客户!",MB_OK|MB_ICONSTOP);
		sClients[clientNum] = accept(slisten, (SOCKADDR *)(remoteAddrs+clientNum), &nAddrlen);
		if(sClients[clientNum] == INVALID_SOCKET)
		{
			AfxMessageBox("链接出错!",MB_OK|MB_ICONSTOP);
			continue;
		}
		canshu = new What();
		canshu->a = clientNum;
		canshu->p = (CExperiment2Dlg *)pParam;
		CWinThread* pThread; //定义一个线程指针
		pThread = ::AfxBeginThread(comminute,canshu);
		clientNum++;
		pThread->Run();
	}
	closesocket(slisten);
	WSACleanup();
	return 0;
}

UINT CExperiment2Dlg::comminute(LPVOID pParam)
{
	int myC = ((What *)pParam)->a;
	CListBox* p	 = NULL;
	p = (CListBox*)(((What *)pParam)->p)->GetDlgItem(IDC_MESSAGES);
	char revData[255];

	while (true)
	{
		AfxMessageBox("开始接受",MB_OK|MB_ICONSTOP);
		int ret = recv(sClients[myC], revData, 255, 0);
		if(ret > 0)
		{
			revData[ret] = 0x00;
			AfxMessageBox(revData,MB_OK|MB_ICONSTOP);
		}
		char * sendData = "hello TCP client!\n";
		send(sClients[myC], sendData, strlen(sendData), 0);
	}
	return 0;
}


