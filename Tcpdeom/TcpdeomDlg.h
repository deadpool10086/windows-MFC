// TcpdeomDlg.h : header file
//

#if !defined(AFX_TCPDEOMDLG_H__62653BAB_72D8_4241_AD0A_888F2789C937__INCLUDED_)
#define AFX_TCPDEOMDLG_H__62653BAB_72D8_4241_AD0A_888F2789C937__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTcpdeomDlg dialog

class CTcpdeomDlg : public CDialog
{
// Construction
public:
	CSocket m_sock;
	CTcpdeomDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTcpdeomDlg)
	enum { IDD = IDD_TCPDEOM_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTcpdeomDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTcpdeomDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TCPDEOMDLG_H__62653BAB_72D8_4241_AD0A_888F2789C937__INCLUDED_)
