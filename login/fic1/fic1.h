// fic1.h : main header file for the FIC1 application
//

#if !defined(AFX_FIC1_H__9FAC127A_3F10_42F7_9B71_8B2344E70DAD__INCLUDED_)
#define AFX_FIC1_H__9FAC127A_3F10_42F7_9B71_8B2344E70DAD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFic1App:
// See fic1.cpp for the implementation of this class
//

class CFic1App : public CWinApp
{
public:
	CFic1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFic1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFic1App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FIC1_H__9FAC127A_3F10_42F7_9B71_8B2344E70DAD__INCLUDED_)
