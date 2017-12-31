#if !defined(AFX_SOCK_H__1FBD79F7_A97C_4E96_B8B7_73FC3F846FBB__INCLUDED_)
#define AFX_SOCK_H__1FBD79F7_A97C_4E96_B8B7_73FC3F846FBB__INCLUDED_

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

#endif // !defined(AFX_SOCK_H__1FBD79F7_A97C_4E96_B8B7_73FC3F846FBB__INCLUDED_)
