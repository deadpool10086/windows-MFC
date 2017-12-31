// notepad.h : main header file for the NOTEPAD application
//

#if !defined(AFX_NOTEPAD_H__6C42EA3E_7E33_442B_A20A_9D280BE6E6CE__INCLUDED_)
#define AFX_NOTEPAD_H__6C42EA3E_7E33_442B_A20A_9D280BE6E6CE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CNotepadApp:
// See notepad.cpp for the implementation of this class
//

class CNotepadApp : public CWinApp
{
public:
	CNotepadApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNotepadApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CNotepadApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NOTEPAD_H__6C42EA3E_7E33_442B_A20A_9D280BE6E6CE__INCLUDED_)
