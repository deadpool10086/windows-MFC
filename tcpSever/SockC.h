#if !defined(AFX_SOCKC_H__61D4C3C6_DD5C_44CF_88F1_0A73A4C208CB__INCLUDED_)
#define AFX_SOCKC_H__61D4C3C6_DD5C_44CF_88F1_0A73A4C208CB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SockC.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CSockC command target

class CSockC : public CSocket
{
// Attributes
public:

// Operations
public:
	CSockC();
	virtual ~CSockC();

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSockC)
	public:
	virtual void OnReceive(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CSockC)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SOCKC_H__61D4C3C6_DD5C_44CF_88F1_0A73A4C208CB__INCLUDED_)
