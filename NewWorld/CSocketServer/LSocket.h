#if !defined(AFX_LSOCKET_H__49720364_EF9D_40CA_83B7_3E6A433C1D86__INCLUDED_)
#define AFX_LSOCKET_H__49720364_EF9D_40CA_83B7_3E6A433C1D86__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LSocket.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CLSocket command target
class CCSocketServerDlg;
class CLSocket : public CSocket
{
// Attributes
public:

// Operations
public:
	CLSocket(CCSocketServerDlg * pDlg);
	virtual ~CLSocket();

// Overrides
public:
	CCSocketServerDlg* m_pDlg;
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLSocket)
	public:
	virtual void OnAccept(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CLSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LSOCKET_H__49720364_EF9D_40CA_83B7_3E6A433C1D86__INCLUDED_)
