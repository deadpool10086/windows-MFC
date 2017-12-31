#if !defined(AFX_MYSOCKET_H__E83E2578_EBB5_44E3_AC61_362A321832D4__INCLUDED_)
#define AFX_MYSOCKET_H__E83E2578_EBB5_44E3_AC61_362A321832D4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Mysocket.h : header file
//

#include "afxsock.h"
class CCAsyncSocketServerDlg;
/////////////////////////////////////////////////////////////////////////////
// CMysocket command target

class CMysocket : public CAsyncSocket
{
// Attributes
public:

// Operations
public:
	CMysocket();
	virtual ~CMysocket();

// Overrides
public:
	void SetParent(CCAsyncSocketServerDlg * pDlg);
	CCAsyncSocketServerDlg* m_pDlg;
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMysocket)
	public:
	virtual void OnAccept(int nErrorCode);
	virtual void OnClose(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CMysocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYSOCKET_H__E83E2578_EBB5_44E3_AC61_362A321832D4__INCLUDED_)
