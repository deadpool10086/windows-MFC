// notepadDlg.h : header file
//

#if !defined(AFX_NOTEPADDLG_H__CB1A189C_ACA1_4FE9_9B5F_076D2543F767__INCLUDED_)
#define AFX_NOTEPADDLG_H__CB1A189C_ACA1_4FE9_9B5F_076D2543F767__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CNotepadDlg dialog

class CNotepadDlg : public CDialog
{
// Construction
public:
	CNotepadDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CNotepadDlg)
	enum { IDD = IDD_NOTEPAD_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNotepadDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CNotepadDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnFileSave();
	afx_msg void OnFileOpen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NOTEPADDLG_H__CB1A189C_ACA1_4FE9_9B5F_076D2543F767__INCLUDED_)
