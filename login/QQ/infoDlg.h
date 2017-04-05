#if !defined(AFX_INFODLG_H__CCDA4BE3_48F0_4167_BAC8_D1915CEC0FD9__INCLUDED_)
#define AFX_INFODLG_H__CCDA4BE3_48F0_4167_BAC8_D1915CEC0FD9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// infoDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CinfoDlg dialog

class CinfoDlg : public CDialog
{
// Construction
public:
	CListCtrl m_list;
	CinfoDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CinfoDlg)
	enum { IDD = IDD_INFO_DLG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CinfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CinfoDlg)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnAdd();
	afx_msg void OnDel();
	afx_msg void OnMod();
	afx_msg void OnOpen();
	afx_msg void OnSave();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INFODLG_H__CCDA4BE3_48F0_4167_BAC8_D1915CEC0FD9__INCLUDED_)
