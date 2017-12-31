// MainDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MainDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainDlg dialog


CMainDlg::CMainDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMainDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMainDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMainDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMainDlg, CDialog)
	//{{AFX_MSG_MAP(CMainDlg)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainDlg message handlers

BOOL CMainDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	SetWindowText("hello world");
	HICON hIcon = LoadIcon(AfxGetInstanceHandle(),(LPCSTR)IDI_ICON1);
	SetIcon(hIcon,FALSE);
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CMainDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CString str;
	str.Format("x=%d,y=%d",point.x,point.y);
	if (MK_CONTROL & nFlags)
		str += "按下了Ctrl";
	if (MK_SHIFT & nFlags)
		str += "按下了shift";
//	AfxMessageBox(str);
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnLButtonDown(nFlags, point);
}

void CMainDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
		CString str;
	str.Format("x=%d,y=%d",point.x,point.y);
	if (MK_CONTROL & nFlags)
		str += "按下了Ctrl";
	if (MK_SHIFT & nFlags)
		str += "按下了shift";
	if (MK_LBUTTON & nFlags)
		str += "按下了左键";
	if (MK_RBUTTON & nFlags)
		str += "按下了右键";
	SetWindowText(str);

	CDialog::OnMouseMove(nFlags, point);
}

void CMainDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	dc.Ellipse(10,10, 150, 100)	;
}
