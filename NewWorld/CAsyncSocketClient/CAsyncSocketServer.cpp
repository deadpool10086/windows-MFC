// CAsyncSocketServer.cpp : Defines the class behaviors for the application.
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
// CCAsyncSocketServerApp

BEGIN_MESSAGE_MAP(CCAsyncSocketServerApp, CWinApp)
	//{{AFX_MSG_MAP(CCAsyncSocketServerApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCAsyncSocketServerApp construction

CCAsyncSocketServerApp::CCAsyncSocketServerApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CCAsyncSocketServerApp object

CCAsyncSocketServerApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CCAsyncSocketServerApp initialization

BOOL CCAsyncSocketServerApp::InitInstance()
{
	// Standard initialization

	CCAsyncSocketServerDlg dlg;
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
