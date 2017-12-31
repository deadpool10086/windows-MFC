// CSocketServerDlg.h : header file
//

#if !defined(AFX_CSOCKETSERVERDLG_H__3A184E57_E06B_400D_A1A8_9A58F9679146__INCLUDED_)
#define AFX_CSOCKETSERVERDLG_H__3A184E57_E06B_400D_A1A8_9A58F9679146__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCSocketServerDlg dialog
#include "CSocket.h"
#include "LSocket.h"
class CMsg;
class CCSocketServerDlg : public CDialog
{
// Construction
public:
	void backClients(CMsg* pMsg);
	void OnReceive(CCSocket* pSocket);
	void OnAccept();
	CPtrList m_connList;
	CLSocket* m_pLSocket;
	CCSocketServerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCSocketServerDlg)
	enum { IDD = IDD_CSOCKETSERVER_DIALOG };
	CListBox	m_listMsg;
	CButton	m_btnClose;
	CButton	m_btnListen;
	CStatic	m_staNum;
	UINT	m_nPort;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCSocketServerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCSocketServerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	afx_msg void OnButtonListen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CSOCKETSERVERDLG_H__3A184E57_E06B_400D_A1A8_9A58F9679146__INCLUDED_)
