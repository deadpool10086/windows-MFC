// CSocketServer.h : main header file for the CSOCKETSERVER application
//

#if !defined(AFX_CSOCKETSERVER_H__4345DBD0_8BC9_4E62_A245_4E93100C7B55__INCLUDED_)
#define AFX_CSOCKETSERVER_H__4345DBD0_8BC9_4E62_A245_4E93100C7B55__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCSocketServerApp:
// See CSocketServer.cpp for the implementation of this class
//

class CCSocketServerApp : public CWinApp
{
public:
	CCSocketServerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCSocketServerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCSocketServerApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CSOCKETSERVER_H__4345DBD0_8BC9_4E62_A245_4E93100C7B55__INCLUDED_)
