// experiment2Dlg.h : header file
//

#if !defined(AFX_EXPERIMENT2DLG_H__4A46704E_7AF8_4D41_9E71_92405001D0EB__INCLUDED_)
#define AFX_EXPERIMENT2DLG_H__4A46704E_7AF8_4D41_9E71_92405001D0EB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CExperiment2Dlg dialog

class CExperiment2Dlg : public CDialog
{
// Construction
public:
	static sockaddr_in * remoteAddrs;
	static UINT comminute (LPVOID pParam);
	static UINT Accept (LPVOID pParam);
	static int clientNum;
	static SOCKET* sClients;
	UINT hhhhh;
	CExperiment2Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CExperiment2Dlg)
	enum { IDD = IDD_EXPERIMENT2_DIALOG };
	CListBox	m_messages;
	CString	m_sip;
	int		m_nport;
	CString	m_strMessage;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExperiment2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CExperiment2Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSetup();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};



//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPERIMENT2DLG_H__4A46704E_7AF8_4D41_9E71_92405001D0EB__INCLUDED_)
