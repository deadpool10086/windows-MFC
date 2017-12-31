// Mysocket.cpp : implementation file
//

#include "stdafx.h"
#include "CAsyncSocketServer.h"
#include "Mysocket.h"
#include "CAsyncSocketServerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMysocket

CMysocket::CMysocket()
{
	m_pDlg = NULL;
}

CMysocket::~CMysocket()
{
	m_pDlg = NULL;
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CMysocket, CAsyncSocket)
	//{{AFX_MSG_MAP(CMysocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CMysocket member functions

void CMysocket::OnAccept(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	CAsyncSocket::OnAccept(nErrorCode);
	if (nErrorCode == 0) m_pDlg->OnAccept();
}

void CMysocket::OnClose(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	CAsyncSocket::OnClose(nErrorCode);
	if (nErrorCode == 0) m_pDlg->OnClose();
}

void CMysocket::OnReceive(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	CAsyncSocket::OnReceive(nErrorCode);
	if (nErrorCode == 0) m_pDlg->OnReceive();
}

void CMysocket::SetParent(CCAsyncSocketServerDlg *pDlg)
{
	m_pDlg = pDlg;
}
