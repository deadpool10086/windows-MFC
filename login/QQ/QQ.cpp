// QQ.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "QQ.h"
#include "QQDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CQQApp

BEGIN_MESSAGE_MAP(CQQApp, CWinApp)
	//{{AFX_MSG_MAP(CQQApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQQApp construction

CQQApp::CQQApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CQQApp object

CQQApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CQQApp initialization
#include "loginDlg.h"
BOOL CQQApp::InitInstance()
{
	CLoginDlg loginDlg;
	if(IDCANCEL == loginDlg.DoModal())
		return FALSE;
	CQQDlg dlg;
//	m_pMainWnd = &dlg;
	dlg.DoModal();
	return FALSE;
}
 