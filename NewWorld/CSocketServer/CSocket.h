#if !defined(AFX_CSOCKET_H__6D1B709D_EC68_466B_8C0B_6BC9C475C537__INCLUDED_)
#define AFX_CSOCKET_H__6D1B709D_EC68_466B_8C0B_6BC9C475C537__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CSocket.h : header file
//

class CMsg;
class CCSocketServerDlg;
/////////////////////////////////////////////////////////////////////////////
// CCSocket command target

class CCSocket : public CSocket
{
// Attributes
public:

// Operations
public:
	CCSocket(CCSocketServerDlg * pDlg);
	virtual ~CCSocket();

// Overrides
public:
	void ReceiveMessage(CMsg* pMsg);
	void SendMessage(CMsg* pMsg);
	void Initialize();
	CArchive* m_pArchiveOut;
	CArchive* m_pArchiveIn;
	CSocketFile* m_pFile;
	CCSocketServerDlg* m_pDlg;
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCSocket)
	public:
	virtual void OnReceive(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CCSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CSOCKET_H__6D1B709D_EC68_466B_8C0B_6BC9C475C537__INCLUDED_)
