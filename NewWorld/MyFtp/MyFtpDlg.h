// MyFtpDlg.h : header file
//

#if !defined(AFX_MYFTPDLG_H__11F08A05_A40A_461D_A6D3_B3157B6606B1__INCLUDED_)
#define AFX_MYFTPDLG_H__11F08A05_A40A_461D_A6D3_B3157B6606B1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMyFtpDlg dialog

class CMyFtpDlg : public CDialog
{
// Construction
public:
	BOOL DownloadFile(CString strSfile, CString strDFile);
	CMyFtpDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMyFtpDlg)
	enum { IDD = IDD_MYFTP_DIALOG };
	CListBox	m_ListFiles;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyFtpDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMyFtpDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnQury();
	afx_msg void OnDownload();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYFTPDLG_H__11F08A05_A40A_461D_A6D3_B3157B6606B1__INCLUDED_)
