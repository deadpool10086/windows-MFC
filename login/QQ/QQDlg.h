// QQDlg.h : header file
//

#if !defined(AFX_QQDLG_H__CFA3F1B2_D5EA_4993_8D9C_74FA9374512A__INCLUDED_)
#define AFX_QQDLG_H__CFA3F1B2_D5EA_4993_8D9C_74FA9374512A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CQQDlg dialog

class CQQDlg : public CDialog
{
// Construction
public:
	CQQDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CQQDlg)
	enum { IDD = IDD_QQ_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQQDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CQQDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnExit();
	afx_msg void OnRelogin();
	afx_msg void OnAdmin();
	afx_msg void OnInfo();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QQDLG_H__CFA3F1B2_D5EA_4993_8D9C_74FA9374512A__INCLUDED_)
