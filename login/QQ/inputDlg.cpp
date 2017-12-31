// inputDlg.cpp : implementation file
//

#include "stdafx.h"
#include "qq.h"
#include "inputDlg.h"
#include "InfoDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CinputDlg dialog


CinputDlg::CinputDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CinputDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CinputDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CinputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CinputDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CinputDlg, CDialog)
	//{{AFX_MSG_MAP(CinputDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CinputDlg message handlers

void CinputDlg::OnOK() 
{
	if(GetFocus() != GetDlgItem(IDC_SALA) && GetFocus() != GetDlgItem(IDOK))
	{
		CDialog::NextDlgCtrl();
		return;
	}

	CString str;
	GetDlgItemText(IDC_NUMB,str);
	int i=0;
	CListCtrl& list = m_pInfoDlg->m_list;
	int nCount=list.GetItemCount();
	while(i<nCount)
	{
		if(list.GetItemText(i,0) == str)
		{
			CString szMsg;
			szMsg.Format("员工编号 %s 已经存在!",str);
			AfxMessageBox(szMsg);
			return;
		}
		i++;
	}
	if(IDNO == AfxMessageBox("确定添加记录？",MB_YESNO))
	{
		SetDlgItemText(IDC_NUMB,"");
		SetDlgItemText(IDC_NAME,"");
		SetDlgItemText(IDC_BIRTH,"");
		SetDlgItemText(IDC_DEPT,"");
		SetDlgItemText(IDC_SALA,"");
		return;
	}
	list.InsertItem(nCount,str);
	GetDlgItemText(IDC_NAME,str);
	list.SetItemText(nCount,1,str);
	GetDlgItemText(IDC_BIRTH,str);
	list.SetItemText(nCount,2,str);
	GetDlgItemText(IDC_DEPT,str);
	list.SetItemText(nCount,3,str);
	GetDlgItemText(IDC_SALA,str);
	list.SetItemText(nCount,4,str);
	GetDlgItem(IDC_NUMB)->SetFocus();
	
//	CDialog::OnOK();
}

BOOL CinputDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CDateTimeCtrl* pDate = (CDateTimeCtrl*)GetDlgItem(IDC_BIRTH);
	CTime time(1990,1,1,0,0,0);
	pDate ->SetTime(&time);

	CComboBox* pCombo = (CComboBox*)GetDlgItem(IDC_DEPT);
	pCombo ->SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
