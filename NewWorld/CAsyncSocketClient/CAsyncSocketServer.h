// CAsyncSocketServer.h : main header file for the CASYNCSOCKETSERVER application
//

#if !defined(AFX_CASYNCSOCKETSERVER_H__5D9D2B50_1D8C_4661_B1AE_E329BB8ACC92__INCLUDED_)
#define AFX_CASYNCSOCKETSERVER_H__5D9D2B50_1D8C_4661_B1AE_E329BB8ACC92__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCAsyncSocketServerApp:
// See CAsyncSocketServer.cpp for the implementation of this class
//

class CCAsyncSocketServerApp : public CWinApp
{
public:
	CCAsyncSocketServerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCAsyncSocketServerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCAsyncSocketServerApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CASYNCSOCKETSERVER_H__5D9D2B50_1D8C_4661_B1AE_E329BB8ACC92__INCLUDED_)
