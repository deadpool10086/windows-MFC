// FtpClientnew.h : main header file for the FTPCLIENTNEW application
//

#if !defined(AFX_FTPCLIENTNEW_H__01808A9F_6B76_45BE_86C7_E487178228DF__INCLUDED_)
#define AFX_FTPCLIENTNEW_H__01808A9F_6B76_45BE_86C7_E487178228DF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFtpClientnewApp:
// See FtpClientnew.cpp for the implementation of this class
//

class CFtpClientnewApp : public CWinApp
{
public:
	CFtpClientnewApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFtpClientnewApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFtpClientnewApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FTPCLIENTNEW_H__01808A9F_6B76_45BE_86C7_E487178228DF__INCLUDED_)
