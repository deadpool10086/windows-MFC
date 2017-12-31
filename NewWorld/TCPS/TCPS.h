// TCPS.h : main header file for the TCPS application
//

#if !defined(AFX_TCPS_H__01D30783_ACF8_4BFF_9C0B_4BEF41BDFA04__INCLUDED_)
#define AFX_TCPS_H__01D30783_ACF8_4BFF_9C0B_4BEF41BDFA04__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTCPSApp:
// See TCPS.cpp for the implementation of this class
//

class CTCPSApp : public CWinApp
{
public:
	CTCPSApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTCPSApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTCPSApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TCPS_H__01D30783_ACF8_4BFF_9C0B_4BEF41BDFA04__INCLUDED_)
