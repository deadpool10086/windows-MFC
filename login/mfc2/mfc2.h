// mfc2.h : main header file for the MFC2 application
//

#if !defined(AFX_MFC2_H__9D4DBA55_4BA0_4DD5_9BD5_F35757F79FF4__INCLUDED_)
#define AFX_MFC2_H__9D4DBA55_4BA0_4DD5_9BD5_F35757F79FF4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMfc2App:
// See mfc2.cpp for the implementation of this class
//

class CMfc2App : public CWinApp
{
public:
	CMfc2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMfc2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMfc2App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC2_H__9D4DBA55_4BA0_4DD5_9BD5_F35757F79FF4__INCLUDED_)
