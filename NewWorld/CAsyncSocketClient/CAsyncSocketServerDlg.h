// CAsyncSocketServerDlg.h : header file
//

#if !defined(AFX_CASYNCSOCKETSERVERDLG_H__B6CB1C65_7686_44B8_ABDA_BE07B2D77C9F__INCLUDED_)
#define AFX_CASYNCSOCKETSERVERDLG_H__B6CB1C65_7686_44B8_ABDA_BE07B2D77C9F__INCLUDED_

#include "MySocket.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCAsyncSocketServerDlg dialog

class CCAsyncSocketServerDlg : public CDialog
{
// Construction
public:
	void OnReceive();
	void OcConnect();
	void OnClose();
	CMySocket m_sConnectSocket;
	CCAsyncSocketServerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCAsyncSocketServerDlg)
	enum { IDD = IDD_CASYNCSOCKETSERVER_DIALOG };
	CListBox	m_listSent;
	CListBox	m_listReceived;
	CButton	m_btnConnect;
	CString	m_strMsg;
	int		m_nServName;
	CString	m_strServName;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCAsyncSocketServerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCAsyncSocketServerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSendMsg();
	afx_msg void OnButtonConnrct();
	afx_msg void OnButtonClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CASYNCSOCKETSERVERDLG_H__B6CB1C65_7686_44B8_ABDA_BE07B2D77C9F__INCLUDED_)
