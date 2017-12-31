// MyFtp.h : main header file for the MYFTP application
//

#if !defined(AFX_MYFTP_H__AFF2CA2F_D4B6_4950_914F_0881E4BDB386__INCLUDED_)
#define AFX_MYFTP_H__AFF2CA2F_D4B6_4950_914F_0881E4BDB386__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyFtpApp:
// See MyFtp.cpp for the implementation of this class
//

class CMyFtpApp : public CWinApp
{
public:
	CMyFtpApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyFtpApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMyFtpApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYFTP_H__AFF2CA2F_D4B6_4950_914F_0881E4BDB386__INCLUDED_)
