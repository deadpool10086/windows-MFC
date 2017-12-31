// SockU.cpp : implementation file
//

#include "stdafx.h"
#include "udp.h"
#include "SockU.h"
#include "UdpDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/////////////////////////////////////////////////////////////////////////////
// CSockU

CSockU::CSockU()
{
}

CSockU::~CSockU()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CSockU, CSocket)
	//{{AFX_MSG_MAP(CSockU)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CSockU member functions

void CSockU::OnReceive(int nErrorCode) 
{
	CString szIP;
	UINT nPort;
	char s[512];
	int nLen = ReceiveFrom(s,sizeof(s),szIP,nPort);
	if(nLen < 0)
		return;
	s[nLen] = 0;
	CUdpDlg *pDlg = (CUdpDlg *)AfxGetMainWnd();
	pDlg->OnReceive(s,szIP); 
	CSocket::OnReceive(nErrorCode);
}
