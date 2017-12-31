// CSocketServer.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "CSocketServer.h"
#include "CSocketServerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCSocketServerApp

BEGIN_MESSAGE_MAP(CCSocketServerApp, CWinApp)
	//{{AFX_MSG_MAP(CCSocketServerApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCSocketServerApp construction

CCSocketServerApp::CCSocketServerApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CCSocketServerApp object

CCSocketServerApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CCSocketServerApp initialization

BOOL CCSocketServerApp::InitInstance()
{
	// Standard initialization

	CCSocketServerDlg dlg;
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
