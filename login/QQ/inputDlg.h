#if !defined(AFX_INPUTDLG_H__5907EF97_BFEE_4ACA_8275_13E811FB55A9__INCLUDED_)
#define AFX_INPUTDLG_H__5907EF97_BFEE_4ACA_8275_13E811FB55A9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// inputDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CinputDlg dialog
#include "infoDlg.h"
class CinputDlg : public CDialog
{
// Construction
public:
	CinputDlg(CWnd* pParent = NULL);   // standard constructor
	CinfoDlg * m_pInfoDlg;
// Dialog Data
	//{{AFX_DATA(CinputDlg)
	enum { IDD = IDD_INPUT_DLG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CinputDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CinputDlg)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INPUTDLG_H__5907EF97_BFEE_4ACA_8275_13E811FB55A9__INCLUDED_)
