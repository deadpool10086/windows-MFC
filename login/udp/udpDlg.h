// udpDlg.h : header file
//

#if !defined(AFX_UDPDLG_H__DB2E131D_5666_4BA6_89FD_BF0D7510E139__INCLUDED_)
#define AFX_UDPDLG_H__DB2E131D_5666_4BA6_89FD_BF0D7510E139__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CUdpDlg dialog
#include <afxsock.h>
#include "SockU.h"	// Added by ClassView


class CUdpDlg : public CDialog
{
// Construction
public:
	void OnReceive(LPCSTR szText,LPCSTR szIP);
	CSockU m_sock;
	CUdpDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CUdpDlg)
	enum { IDD = IDD_UDP_DIALOG };
	CEdit	m_hist;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUdpDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CUdpDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UDPDLG_H__DB2E131D_5666_4BA6_89FD_BF0D7510E139__INCLUDED_)
