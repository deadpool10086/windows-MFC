// LSocket.cpp : implementation file
//

#include "stdafx.h"
#include "CSocketServer.h"
#include "LSocket.h"
#include "CSocketServerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLSocket

CLSocket::CLSocket(CCSocketServerDlg * pDlg)
{
	m_pDlg =pDlg;
}

CLSocket::~CLSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CLSocket, CSocket)
	//{{AFX_MSG_MAP(CLSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CLSocket member functions

void CLSocket::OnAccept(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	CSocket::OnAccept(nErrorCode);
	m_pDlg->OnAccept();
}

