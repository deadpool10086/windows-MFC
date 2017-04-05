// LoginDlg.cpp : implementation file
//

#include "stdafx.h"
#include "QQ.h"
#include "LoginDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CQQApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg dialog


CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLoginDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLoginDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialog)
	//{{AFX_MSG_MAP(CLoginDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg message handlers

void CLoginDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CLoginDlg::OnOK() 
{
	if(CheckUser())
		CDialog::OnOK();
	else
	{
		AfxMessageBox("用户名或者密码错误");
		SetDlgItemText(IDC_NAME,"");
		SetDlgItemText(IDC_PASS,"");
		GetDlgItem(IDC_NAME)->SetFocus();
	}
}

BOOL CLoginDlg::CheckUser()
{
	CString szName,szPass;
	GetDlgItemText(IDC_NAME,szName);
	GetDlgItemText(IDC_PASS,szPass);
	CFile file;
	if(!file.Open("./user.dat",CFile::modeRead|CFile::shareDenyNone))
	{
		CreateUser();
		if(!file.Open("./user.dat",CFile::modeRead))
		return FALSE;
	}
	SUser u;
	while(file.Read(&u,sizeof(u))==sizeof(u))
	{
		if(szName == u.sName && szPass == u.sPass)
		{
			theApp.m_user = u;
			return TRUE;
		}
	}
	return FALSE;
}

void CLoginDlg::CreateUser()
{
	CFile file;
	if(!file.Open("./user.dat",CFile::modeCreate|CFile::modeWrite))
	{
		AfxMessageBox("用户文件创建失败");
		return;
	}
	SUser u = {"admin","admin",1};
	file.Write(&u,sizeof(u));
	file.Close;
}
