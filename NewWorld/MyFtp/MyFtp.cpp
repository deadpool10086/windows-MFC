// MyFtp.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "MyFtp.h"
#include "MyFtpDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyFtpApp

BEGIN_MESSAGE_MAP(CMyFtpApp, CWinApp)
	//{{AFX_MSG_MAP(CMyFtpApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyFtpApp construction

CMyFtpApp::CMyFtpApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CMyFtpApp object

CMyFtpApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CMyFtpApp initialization

BOOL CMyFtpApp::InitInstance()
{
	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}

	// Standard initialization

	CMyFtpDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
	}
	else if (nResponse == IDCANCEL)
	{
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
