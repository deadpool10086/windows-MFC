// Sock.cpp : implementation file
//

#include "stdafx.h"
#include "tcpSever.h"
#include "Sock.h"
#include "SockC.h"
#include "TcpSeverDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSock

CSock::CSock()
{
}

CSock::~CSock()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CSock, CSocket)
	//{{AFX_MSG_MAP(CSock)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CSock member functions



void CSock::OnAccept(int nErrorCode) 
{
	CSockC* p = new CSockC;
	Accept(*p);	
	CString szIP;
	UINT nPort;
	p->GetPeerName(szIP,nPort);

	CTcpSeverDlg * pDlg = (CTcpSeverDlg *)AfxGetMainWnd();
	pDlg ->OnAccept(szIP,nPort);
	

	CSocket::OnAccept(nErrorCode);
}
