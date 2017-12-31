// FtpClientnewDlg.h : header file
//

#if !defined(AFX_FTPCLIENTNEWDLG_H__A317359A_EA7A_4F5C_9CB3_052CBD3B3D5A__INCLUDED_)
#define AFX_FTPCLIENTNEWDLG_H__A317359A_EA7A_4F5C_9CB3_052CBD3B3D5A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFtpClientnewDlg dialog

class CFtpClientnewDlg : public CDialog
{
// Construction
public:
	CFtpClientnewDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFtpClientnewDlg)
	enum { IDD = IDD_FTPCLIENTNEW_DIALOG };
	CListBox	m_ListFile;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFtpClientnewDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFtpClientnewDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnQury();
	afx_msg void OnButDownload();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	BOOL DownLoadFile(CString strSFile,CString strDFile);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FTPCLIENTNEWDLG_H__A317359A_EA7A_4F5C_9CB3_052CBD3B3D5A__INCLUDED_)
