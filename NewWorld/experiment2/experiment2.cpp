// experiment2.cpp : Defines the class behaviors for the application.
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
// CExperiment2App

BEGIN_MESSAGE_MAP(CExperiment2App, CWinApp)
	//{{AFX_MSG_MAP(CExperiment2App)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExperiment2App construction

CExperiment2App::CExperiment2App()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CExperiment2App object

CExperiment2App theApp;

/////////////////////////////////////////////////////////////////////////////
// CExperiment2App initialization

BOOL CExperiment2App::InitInstance()
{
	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}

	// Standard initialization

	CExperiment2Dlg dlg;
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
