#if !defined(AFX_SOCKU_H__FB585E70_DCED_4045_BD05_78C7280FC26B__INCLUDED_)
#define AFX_SOCKU_H__FB585E70_DCED_4045_BD05_78C7280FC26B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SockU.h : header file
//
#include <afxsock.h>


/////////////////////////////////////////////////////////////////////////////
// CSockU command target

class CSockU : public CSocket
{  
// Attributes
public:

// Operations
public:
	CSockU();
	virtual ~CSockU();

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSockU)
	public:
	virtual void OnReceive(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CSockU)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SOCKU_H__FB585E70_DCED_4045_BD05_78C7280FC26B__INCLUDED_)
