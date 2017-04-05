// SockC.cpp : implementation file
//

#include "stdafx.h"
#include "tcpSever.h"
#include "SockC.h"
#include "TcpSeverDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSockC

CSockC::CSockC()
{
}

CSockC::~CSockC()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CSockC, CSocket)
	//{{AFX_MSG_MAP(CSockC)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CSockC member functions



void CSockC::OnReceive(int nErrorCode) 
{
	char s[2048];
	CString szIP;
	UINT nPort;
	int nLen = Receive(s, sizeof(s));
	s[nLen] = 0;
	GetPeerName(szIP,nPort);
	CTcpSeverDlg * pDlg = (CTcpSeverDlg *)AfxGetMainWnd();
	pDlg ->OnReceive(s,szIP,nPort);
//	int nLen = ReceiveFrom(s,sizeof(s),szIP,nPort);
	CSocket::OnReceive(nErrorCode);
}
