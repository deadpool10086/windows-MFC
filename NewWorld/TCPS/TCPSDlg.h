// TCPSDlg.h : header file
//

#if !defined(AFX_TCPSDLG_H__041F2968_0FAE_4464_8A98_C1682D54DA8B__INCLUDED_)
#define AFX_TCPSDLG_H__041F2968_0FAE_4464_8A98_C1682D54DA8B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTCPSDlg dialog

class CTCPSDlg : public CDialog
{
// Construction
public:
	CSockt m_sock;
	CTCPSDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTCPSDlg)
	enum { IDD = IDD_TCPS_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTCPSDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTCPSDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TCPSDLG_H__041F2968_0FAE_4464_8A98_C1682D54DA8B__INCLUDED_)
