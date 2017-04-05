// TestWndDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TestWnd.h"
#include "TestWndDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestWndDlg dialog

CTestWndDlg::CTestWndDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestWndDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestWndDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestWndDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestWndDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTestWndDlg, CDialog)
	//{{AFX_MSG_MAP(CTestWndDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	ON_BN_CLICKED(IDC_BUTTON8, OnButton8)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON9, OnButton9)
	ON_BN_CLICKED(IDC_BUTTON10, OnButton10)
	ON_BN_CLICKED(IDC_BUTTON11, OnButton11)
	ON_BN_CLICKED(IDC_BUTTON12, OnButton12)
	ON_BN_CLICKED(IDC_BUTTON13, OnButton13)
	ON_BN_CLICKED(IDC_BUTTON14, OnButton14)
	ON_BN_CLICKED(IDC_BUTTON15, OnButton15)
	ON_BN_CLICKED(IDC_BUTTON16, OnButton16)
	ON_BN_CLICKED(IDC_BUTTON17, OnButton17)
	ON_BN_CLICKED(IDC_BUTTON18, OnButton18)
	ON_BN_CLICKED(IDC_BUTTON19, OnButton19)
	ON_BN_CLICKED(IDC_BUTTON20, OnButton20)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestWndDlg message handlers

BOOL CTestWndDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	if(!m_list)
	m_list.CreateEx(WS_EX_CLIENTEDGE,"SysListViEW32",NULL,
		WS_VISIBLE|WS_CHILD|LVS_SHOWSELALWAYS,
			CRect(10,20,300,250),this, 8921);	
	m_list.InsertColumn(0,"工号",0,100);
	m_list.InsertColumn(1,"姓名",0,100);
	m_list.InsertColumn(2,"工资",0,100);


	HWND hWnd = ::GetDlgItem(m_hWnd,IDC_EDIT1);//加入::表示使用的是全局函数不是类内部的
	m_edit.Attach(hWnd);  //把获得的句柄赋给一个空的对象 为一个CWnd对象嫁接和移除窗口句柄；
	hWnd = ::GetDlgItem(m_hWnd,IDC_BUTTON1);
	m_dest.SubclassWindow(hWnd);  //子类化
	m_cret.SubclassDlgItem(IDC_BUTTON2,this);
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

void CTestWndDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTestWndDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTestWndDlg::OnButton1() 
{
	DestroyWindow();
}

void CTestWndDlg::OnButton2() 
{
	//DirectUIHWND SysListViEW32
	//WX_****通用窗口风格
	//风格类型 0x00000000前四位是通用窗口风格后四位是单独窗口风格
// 	if(!m_list)
//		m_list.CreateEx(WS_EX_CLIENTEDGE,"SysListViEW32",NULL,WS_VISIBLE|WS_CHILD|LVS_REPORT,CRect(10,80,300,300),this, 8921);	
}

void CTestWndDlg::OnButton3() 
{
	CWnd * pWnd = GetDlgItem(IDOK);
//	if (pWnd)
//	{
		HWND hWnd = pWnd ->GetSafeHwnd();
		if(hWnd)
			pWnd ->DestroyWindow();
//	}
}

void CTestWndDlg::OnButton4() 
{
	HWND hWnd = ::GetDlgItem(m_hWnd,IDOK);
	CWnd* p = CWnd::FromHandle(hWnd);  //和GetDlgItem临时对象只限于用于当前函数
	p->SetWindowText("临时对象");
}

void CTestWndDlg::OnButton5() 
{
	m_edit.SetWindowText("长期有效");
}

void CTestWndDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	m_dest.UnsubclassWindow();
	m_edit.Detach(); //和Attach成对使用在此处释放句柄 返回值是句柄

	
}

void CTestWndDlg::OnButton6() 
{
	DWORD dsStyle = m_list.GetStyle();
	m_list.ModifyStyle(0,LVS_REPORT|LVS_NOSORTHEADER);
}

void CTestWndDlg::OnButton7() 
{ 
	DWORD dsStyle = m_edit.GetExStyle();
	m_edit.ModifyStyleEx(dsStyle,WS_EX_DLGMODALFRAME);
	CRect rect;
	m_edit.GetWindowRect(rect);
	ScreenToClient(rect);
	m_edit.MoveWindow(rect);
//	m_edit.MoveWindow(10,260,400,40);
	Invalidate();
}

void CTestWndDlg::OnButton8() 
{
	SetTimer(12,500,NULL);
	SetTimer(1,100,NULL);
	
}

void CTestWndDlg::OnTimer(UINT nIDEvent) 
{
	if (nIDEvent == 12)
	{
		CString str;
		GetWindowText(str);
		if(str == "Timer...")
			str = "Setting";
		else
			str = "Timer...";
		SetWindowText(str);
	}
	if (nIDEvent == 1)
	{
		CRect rect, rt;
		m_cret.GetWindowRect(rect);
		ScreenToClient(rect);
		rect.OffsetRect(8,1);
		GetClientRect(rt);
		if(rect.right >= rt.right)
		{
			rect.OffsetRect(-rect.left,0);
			KillTimer(1);
		}
		m_cret.MoveWindow(rect);
		
	}
	CDialog::OnTimer(nIDEvent);
}

void CTestWndDlg::OnButton9() 
{
	CWnd *pCanc = GetDlgItem(IDCANCEL);
	if(pCanc -> IsWindowVisible())
		pCanc -> ShowWindow(SW_HIDE);	
	else
		pCanc -> ShowWindow(SW_SHOW);
}

void CTestWndDlg::OnButton10() 
{
	CWnd * pCanc = GetDlgItem(IDCANCEL);
	pCanc ->EnableWindow(!pCanc->IsWindowEnabled());
}

void CTestWndDlg::OnButton11() 
{
	CWnd * pWnd = FindWindow("CabinetWClass",NULL);
	if(pWnd && pWnd->IsIconic())
		pWnd ->ShowWindow(SW_MAXIMIZE);
}

void CTestWndDlg::OnButton12() 
{
	if(IsZoomed())
		SetWindowText("是最大化的");
	else
		SetWindowText("不是最大化");
}

void CTestWndDlg::OnButton13() 
{
	CenterWindow();	
}

void CTestWndDlg::OnButton14() 
{
	CRect rect, rt;
	m_cret.GetWindowRect(rect);
	ScreenToClient(rect);
	rect.OffsetRect(8,1);
//	m_cret.SetWindowPos(&wndBottom,rect.left,rect.top,rect.Width(),rect.Height(),0);
//	m_cret.SetWindowPos(&wndBottom,rect.left,rect.top,0,0,SWP_NOSIZE);
//	m_list.SetWindowPos(&wndTop,0,0,0,0,SWP_NOSIZE|SWP_NOMOVE);
//	Invalidate();
	if(GetExStyle() & WS_EX_TOPMOST)
		SetWindowPos(&wndNoTopMost,0,0,0,0,SWP_NOSIZE|SWP_NOMOVE);
	else
		SetWindowPos(&wndTopMost,0,0,0,0,SWP_NOSIZE|SWP_NOMOVE);
}

void CTestWndDlg::OnButton15() 
{
	m_list.BringWindowToTop();
	Invalidate();
}

void CTestWndDlg::OnButton16() 
{
	CWnd* pWnd = GetTopWindow();
	CString str;
	pWnd->GetWindowText(str);
	SetWindowText(str);
}

void CTestWndDlg::OnButton17() 
{
	CWnd *pWnd = FindWindow("notepad",NULL);
	if(pWnd)
		pWnd ->SetForegroundWindow();
}

void CTestWndDlg::OnButton18() 
{
	CWnd *pWnd = FindWindow("notepad",NULL);
	if(pWnd)
		pWnd->FlashWindow(1);
}

void CTestWndDlg::OnButton19() 
{
	if(this->IsChild(&m_list))	
	{
		::AfxMessageBox("是孩子");
	}
}

void CTestWndDlg::OnButton20() 
{
	CWnd* pWnd = GetWindow(GW_CHILD);
	CString str;
	while(pWnd)
	{
		pWnd->GetWindowText(str);
		pWnd =pWnd->GetWindow(GW_HWNDNEXT);
	}
}
