// fic1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "fic1.h"
#include "fic1Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFic1Dlg dialog

CFic1Dlg::CFic1Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFic1Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFic1Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFic1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFic1Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFic1Dlg, CDialog)
	//{{AFX_MSG_MAP(CFic1Dlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_DEL, OnDel)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_MOD, OnMod)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFic1Dlg message handlers

BOOL CFic1Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	CListCtrl *pList = (CListCtrl *)GetDlgItem(IDC_LIST1);
	pList ->InsertColumn(0,"工号",LVCFMT_LEFT,130);
	pList ->InsertColumn(1,"姓名",LVCFMT_LEFT,150);
	pList ->InsertColumn(2,"工资",LVCFMT_LEFT,150);
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

void CFic1Dlg::OnPaint() 
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
HCURSOR CFic1Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CFic1Dlg::OnDel() 
{
	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST1);

	//int nSel = pList ->GetSelectionMark();
	POSITION pos =pList ->GetFirstSelectedItemPosition();
	int nSel = pList ->GetNextSelectedItem(pos);
	if (nSel < 0)
	{
		AfxMessageBox("请先选中一行再删除!");
		return;
	}
	if(IDYES == AfxMessageBox("确认删除么?",MB_YESNO))
		pList ->DeleteItem(nSel);
}

void CFic1Dlg::OnAdd() 
{
	CString str;
	GetDlgItemText(IDC_NUMB,str);
	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST1);
	int nCount = pList ->GetItemCount();
	pList ->InsertItem(nCount,str);
	GetDlgItemText(IDC_NAME,str);
	pList ->SetItemText(nCount,1,str);
	GetDlgItemText(IDC_SALARY,str);
	pList ->SetItemText(nCount,2,str);

}
void CFic1Dlg::OnMod() 
{
	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST1);
	
	POSITION pos = pList ->GetFirstSelectedItemPosition();
	int nSel = pList ->GetNextSelectedItem(pos);
	if (nSel <0)
	{
		AfxMessageBox("请先选中一行再修改！");
		return;
	}
	CString str;
	GetDlgItemText(IDC_NUMB,str);
	if(IDNO==AfxMessageBox("确认修改选" + str + "的数据么?",MB_YESNO))
		return;
	GetDlgItemText(IDC_NAME,str);
	pList ->SetItemText(nSel,1,str);
	GetDlgItemText(IDC_SALARY,str);
	pList ->SetItemText(nSel,2,str);
}
