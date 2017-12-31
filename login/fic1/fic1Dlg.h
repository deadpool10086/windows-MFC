// fic1Dlg.h : header file
//

#if !defined(AFX_FIC1DLG_H__81EB780A_6F7C_4641_89A7_60C2C36170AB__INCLUDED_)
#define AFX_FIC1DLG_H__81EB780A_6F7C_4641_89A7_60C2C36170AB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFic1Dlg dialog

class CFic1Dlg : public CDialog
{
// Construction
public:
	CFic1Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFic1Dlg)
	enum { IDD = IDD_FIC1_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFic1Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFic1Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDel();
	afx_msg void OnAdd();
	afx_msg void OnMod();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FIC1DLG_H__81EB780A_6F7C_4641_89A7_60C2C36170AB__INCLUDED_)
