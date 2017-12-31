// FileCopyDlg.h : header file
//

#if !defined(AFX_FILECOPYDLG_H__5111A689_5F2A_4352_A04E_3F01B9B0B140__INCLUDED_)
#define AFX_FILECOPYDLG_H__5111A689_5F2A_4352_A04E_3F01B9B0B140__INCLUDED_

#include "FileOP.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFileCopyDlg dialog

class CFileCopyDlg : public CDialog
{
// Construction
public:
	CFileOP m_Fileop;
	CFileCopyDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFileCopyDlg)
	enum { IDD = IDD_FILECOPY_DIALOG };
	CString	m_Source;
	CString	m_locate;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileCopyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFileCopyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCopy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILECOPYDLG_H__5111A689_5F2A_4352_A04E_3F01B9B0B140__INCLUDED_)
