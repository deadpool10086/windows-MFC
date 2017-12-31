// TCPS.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "TCPS.h"
#include "TCPSDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTCPSApp

BEGIN_MESSAGE_MAP(CTCPSApp, CWinApp)
	//{{AFX_MSG_MAP(CTCPSApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTCPSApp construction

CTCPSApp::CTCPSApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CTCPSApp object

CTCPSApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CTCPSApp initialization

BOOL CTCPSApp::InitInstance()
{
	// Standard initialization

	CTCPSDlg dlg;
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
