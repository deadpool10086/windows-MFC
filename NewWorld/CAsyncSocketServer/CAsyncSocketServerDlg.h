// CAsyncSocketServerDlg.h : header file
//

#if !defined(AFX_CASYNCSOCKETSERVERDLG_H__9EE07853_3648_4E0E_88A2_95958B547716__INCLUDED_)
#define AFX_CASYNCSOCKETSERVERDLG_H__9EE07853_3648_4E0E_88A2_95958B547716__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


/////////////////////////////////////////////////////////////////////////////
// CCAsyncSocketServerDlg dialog
#include "MySocket.h"
class CCAsyncSocketServerDlg : public CDialog
{
// Construction
public:
	void OnReceive();
	void OnAccept();
	void OnClose();
	CMysocket m_sConnectSocket;
	CMysocket m_sListenSocket;
	CCAsyncSocketServerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCAsyncSocketServerDlg)
	enum { IDD = IDD_CASYNCSOCKETSERVER_DIALOG };
	CListBox	m_listReceived;
	CListBox	m_listSent;
	CButton	m_btnListen;
	CString	m_strServName;
	int		m_nServPort;
	CString	m_strMsg;
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
	afx_msg void OnButtonClose();
	afx_msg void OnButtonListen();
	afx_msg void OnSendMsg();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CASYNCSOCKETSERVERDLG_H__9EE07853_3648_4E0E_88A2_95958B547716__INCLUDED_)
