// Tp.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Tp.h"
#include "TpDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTpApp

BEGIN_MESSAGE_MAP(CTpApp, CWinApp)
	//{{AFX_MSG_MAP(CTpApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTpApp construction

CTpApp::CTpApp():CWinApp("allow world")
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CTpApp object



/////////////////////////////////////////////////////////////////////////////
// CTpApp initialization

BOOL CTpApp::InitInstance()
{

	SetRegistryKey("FuckYou");
	SetDialogBkColor(RGB(225,225,225),RGB(0,225,0));
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.
	AfxMessageBox("≤‚ ‘theAppname");
	CTpDlg dlg;
	m_pMainWnd = &dlg;
	CWnd * pMain= AfxGetMainWnd();
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
