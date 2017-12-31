// FileCopy.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "FileCopy.h"
#include "FileCopyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFileCopyApp

BEGIN_MESSAGE_MAP(CFileCopyApp, CWinApp)
	//{{AFX_MSG_MAP(CFileCopyApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFileCopyApp construction

CFileCopyApp::CFileCopyApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CFileCopyApp object

CFileCopyApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CFileCopyApp initialization

BOOL CFileCopyApp::InitInstance()
{
	// Standard initialization

	CFileCopyDlg dlg;
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
