#if !defined(AFX_SOCK_H__7330B368_3B04_4A4C_98FB_71DBF632ACE7__INCLUDED_)
#define AFX_SOCK_H__7330B368_3B04_4A4C_98FB_71DBF632ACE7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Sock.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CSock command target

class CSock : public CSocket
{
// Attributes
public:

// Operations
public:
	CSock();
	virtual ~CSock();

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSock)
	public:
	virtual void OnAccept(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CSock)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SOCK_H__7330B368_3B04_4A4C_98FB_71DBF632ACE7__INCLUDED_)
