// PriorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "QQ.h"
#include "PriorDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPriorDlg dialog


CPriorDlg::CPriorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPriorDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPriorDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPriorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPriorDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPriorDlg, CDialog)
	//{{AFX_MSG_MAP(CPriorDlg)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_DEL, OnDel)
	ON_BN_CLICKED(IDC_MODIFY, OnModify)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPriorDlg message handlers

void CPriorDlg::OnOK() 
{
	// TODO: Add extra validation here
	
//	CDialog::OnOK();
}

void CPriorDlg::ReadUser(CListCtrl *pList)
{
	CFile file;
	if (!file.Open("./user.dat",CFile::modeRead|CFile::shareDenyNone))
		return;
	pList ->DeleteAllItems();
	SUser u;
	int i=0;	
	while(file.Read(&u,sizeof(u)) == sizeof(u))
	{
		pList->InsertItem(i,u.sName);
		pList->SetItemText(i,1,u.sPass);
		pList->SetItemText(i,2,u.nPrior?"�߼�":"��ͨ");
		i++;
	}
	file.Close();
}

BOOL CPriorDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CListCtrl *pList = (CListCtrl*)GetDlgItem(IDC_LIST);
	pList->InsertColumn(0,"�ʻ�",0,100);
	pList->InsertColumn(0,"����",0,100);
	pList->InsertColumn(0,"Ȩ��",0,100);
//	pList->InsertColumn(0,"�ʻ�",0,100);
	ReadUser(pList);
	CComboBox * pComb = (CComboBox * )GetDlgItem(IDC_PRIOR);
	pComb->AddString("��ͨ");
	pComb->AddString("�߼�");
	pComb->SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPriorDlg::OnAdd() 
{
//	SUser u;
//	GetDlgItemText(IDC_NAME,u.sName,sizeof(u.sName));
	CString szName;
	GetDlgItemText(IDC_NAME, szName);
//	strlwr(u.sName);
	szName.MakeLower();
	CListCtrl * pList = (CListCtrl*)GetDlgItem(IDC_LIST);
	int i = 0, nCount = pList ->GetItemCount();
	while(i<nCount)
	{
		if(pList ->GetItemText(i, 0) == szName)
		{
			AfxMessageBox("�û��Ѿ�����!");
		}
		++i;
	}
	pList->InsertItem(nCount, szName);
	CString szPass;
	GetDlgItemText(IDC_PASS,szPass);
	pList->SetItemText(nCount,1,szPass);
	CComboBox * pComb = (CComboBox *)GetDlgItem(IDC_PRIOR);
	int nSel = pComb->GetCurSel();
	pList->SetItemText(nCount, 2, nSel?"�߼�":"��ͨ");
}

void CPriorDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	CFile file;
	if(!file.Open("./user.dat",CFile::modeCreate|CFile::modeWrite))
	{
		AfxMessageBox("�����ļ�ʱʧ��!");
		return;
	}
	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST);
	int i=0,nCount = pList->GetItemCount();
	SUser u;
	while(i<nCount)
	{
		pList ->GetItemText(i,0,u.sName,sizeof(u.sName));
		pList ->GetItemText(i,1,u.sPass,sizeof(u.sPass));
		u.nPrior =	pList ->GetItemText(i,2) == "�߼�";
		file.Write(&u,sizeof(u));
		++i;
	}

	file.Close();
}

//GetSelectionMark()�����ѡ��Ϊ׼
//�����GetSelectedCount����ʹ��Ч�����һЩ
void CPriorDlg::OnDel() 
{
	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST);
//	int nSel = pList ->GetSelectionMark();

	POSITION pos = pList->GetFirstSelectedItemPosition();
	int nSel = pList ->GetNextSelectedItem(pos);
//	if(pList->GetSelectedCount() <1)
	if(nSel < 0)
//	if(pos == NULL)
	{
		AfxMessageBox("��ѡ��һ���˻���ɾ��");
		return;
	}
	
	if(pList->GetItemText(nSel,0) == "admin")
		return ;

//	int nSel = pList ->GetSelectionMark();
	CString str;
	str.Format("ȷ��Ҫɾ�� %s ô?",pList ->GetItemText(nSel,0));
	if(IDYES == AfxMessageBox(str,MB_YESNO))
		pList ->DeleteItem(nSel);
}

void CPriorDlg::OnModify() 
{
	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST);
	POSITION pos = pList->GetFirstSelectedItemPosition();
	int nSel = pList ->GetNextSelectedItem(pos);
	if(nSel < 0)
	{
		AfxMessageBox("��ѡ��һ���˻����޸�");
		return;
	}
	char sPass[20];
	GetDlgItemText(IDC_PASS,sPass,sizeof(sPass));
	pList->SetItemText(nSel,1,sPass);
	CComboBox * pComb = (CComboBox*)GetDlgItem(IDC_PRIOR);
//	int nPrior =	pComb ->GetCurSel();
	CString str;
	pComb ->GetWindowText(str);

	if(pList ->GetItemText(nSel,0) !="admin")
		pList ->SetItemText(nSel,2,str);
}
