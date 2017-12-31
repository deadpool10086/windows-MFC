// Tcpdeom.h : main header file for the TCPDEOM application
//

#if !defined(AFX_TCPDEOM_H__3DA95581_46AE_49C0_8769_57DD24D273F8__INCLUDED_)
#define AFX_TCPDEOM_H__3DA95581_46AE_49C0_8769_57DD24D273F8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTcpdeomApp:
// See Tcpdeom.cpp for the implementation of this class
//

class CTcpdeomApp : public CWinApp
{
public:
	CTcpdeomApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTcpdeomApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTcpdeomApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TCPDEOM_H__3DA95581_46AE_49C0_8769_57DD24D273F8__INCLUDED_)
