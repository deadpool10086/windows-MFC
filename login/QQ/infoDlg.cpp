// infoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "qq.h"
#include "InputDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CinfoDlg dialog


CinfoDlg::CinfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CinfoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CinfoDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CinfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CinfoDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CinfoDlg, CDialog)
	//{{AFX_MSG_MAP(CinfoDlg)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_DEL, OnDel)
	ON_BN_CLICKED(IDC_MOD, OnMod)
	ON_BN_CLICKED(IDC_OPEN, OnOpen)
	ON_BN_CLICKED(IDC_SAVE, OnSave)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CinfoDlg message handlers

void CinfoDlg::OnOK() 
{
		
	CDialog::OnOK();
}

BOOL CinfoDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
//	CListCtrl * pList = (CListCtrl*)GetDlgItem(IDC_LIST);
	m_list.SubclassDlgItem(IDC_LIST,this);
	m_list.InsertColumn(0,"工号",0,80);
	m_list.InsertColumn(1,"姓名",0,100);
	m_list.InsertColumn(2,"生日",0,120);
	m_list.InsertColumn(3,"部门",0,80);
	m_list.InsertColumn(4,"工资",0,100);
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CinfoDlg::OnAdd() 
{
	CinputDlg dlg;
	dlg.m_pInfoDlg = this;
	dlg.DoModal();
}

void CinfoDlg::OnDel() 
{
	POSITION pos = m_list.GetFirstSelectedItemPosition();
	int nSel = m_list.GetNextSelectedItem(pos);
	if(nSel < 0)
	{
		AfxMessageBox("请选中一个再删除");
		return;
	}
	CString str;
	str.Format("确认要删除员工编号:%s 姓名:%s 么？",m_list.GetItemText(nSel,0),m_list.GetItemText(nSel,1));
	if(IDYES == AfxMessageBox(str,MB_YESNO))
		m_list.DeleteItem(nSel);
}

void CinfoDlg::OnMod() 
{
 	
}

void CinfoDlg::OnOpen() 
{
	CFileDialog dlg(TRUE);
	dlg.DoModal();
}

void CinfoDlg::OnSave() 
{
	// TODO: Add your control notification handler code here
	
}
