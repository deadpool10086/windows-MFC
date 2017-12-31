// TestMFCDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TestMFC.h"
#include "TestMFCDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

enum {UM_TEST = WM_USER+132};
/////////////////////////////////////////////////////////////////////////////
// CTestMFCDlg dialog

CTestMFCDlg::CTestMFCDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestMFCDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestMFCDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestMFCDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTestMFCDlg, CDialog)
	ON_MESSAGE(UM_TEST,OnTestMsg)
	//{{AFX_MSG_MAP(CTestMFCDlg)
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestMFCDlg message handlers

BOOL CTestMFCDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetWindowText("测试");
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTestMFCDlg::OnPaint() 
{
		CPaintDC dc(this); // device context for painting
	dc.Ellipse(10,10,100,100);
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.


void CTestMFCDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
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

void CTestMFCDlg::OnButton1() 
{ 
//	CWnd* p = FindWindow(NULL,"无标题 - 记事本");
//	if (p)
//		 p ->SendMessage(WM_CLOSE);
//	SendMessage(WM_MOUSEMOVE,MK_LBUTTON|MK_CONTROL,0x12345678);
	this ->SendMessage(WM_LBUTTONDOWN,MK_LBUTTON|MK_CONTROL|MK_SHIFT,0x00230015);

}

void CTestMFCDlg::OnLButtonDown(UINT nFlags, CPoint point) 
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
	AfxMessageBox(str);
	CDialog::OnLButtonDown(nFlags, point);
}

void CTestMFCDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	int nRet = SendMessage(UM_TEST,1246,191);
}

LRESULT CTestMFCDlg::OnTestMsg(WPARAM w, LPARAM l)
{
	AfxMessageBox("测试非系统 消息");
	return 100;
}
