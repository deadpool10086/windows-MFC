// experiment2.h : main header file for the EXPERIMENT2 application
//

#if !defined(AFX_EXPERIMENT2_H__965BA58A_1282_4DF8_A0EB_074CA0BBB201__INCLUDED_)
#define AFX_EXPERIMENT2_H__965BA58A_1282_4DF8_A0EB_074CA0BBB201__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CExperiment2App:
// See experiment2.cpp for the implementation of this class
//

class CExperiment2App : public CWinApp
{
public:
	CExperiment2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExperiment2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CExperiment2App)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPERIMENT2_H__965BA58A_1282_4DF8_A0EB_074CA0BBB201__INCLUDED_)
