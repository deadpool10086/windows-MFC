// tcpSeverDlg.h : header file
//

#if !defined(AFX_TCPSEVERDLG_H__1DDD80A1_05E5_408D_8196_66DCC407B1A6__INCLUDED_)
#define AFX_TCPSEVERDLG_H__1DDD80A1_05E5_408D_8196_66DCC407B1A6__INCLUDED_

#include "Sock.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTcpSeverDlg dialog

class CTcpSeverDlg : public CDialog
{
// Construction
public:
	void OnAccept(LPCSTR szIP, UINT nPort);
	void OnReceive(LPCSTR szText, LPCSTR szIP,UINT nPort);
	CSock m_sock;
	CTcpSeverDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTcpSeverDlg)
	enum { IDD = IDD_TCPSEVER_DIALOG };
	CEdit	m_txt;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTcpSeverDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTcpSeverDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TCPSEVERDLG_H__1DDD80A1_05E5_408D_8196_66DCC407B1A6__INCLUDED_)
