// FtpDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Ftp.h"
#include "FtpDlg.h"
#include "Afxinet.h"
#include "mt.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFtpDlg dialog

CFtpDlg::CFtpDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFtpDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFtpDlg)
	m_strFtp = _T("");
	m_strName = _T("");
	m_strPwd = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFtpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFtpDlg)
	DDX_Control(pDX, IDC_UPLOAD, m_btnUpload);
	DDX_Control(pDX, IDC_DOWNLOAD, m_btnDownload);
	DDX_Control(pDX, IDOK, m_btnQuery);
	DDX_Control(pDX, IDC_LIST_FILE, m_listFile);
	DDX_Control(pDX, IDC_EDIT_PWD, m_editPwd);
	DDX_Control(pDX, IDC_EDIT_NAME, m_editName);
	DDX_Control(pDX, IDC_EDIT_FTP, m_editFtp);
	DDX_Control(pDX, IDC_STATIC_PWD, m_staPwd);
	DDX_Control(pDX, IDC_STATIC_NAME, m_staName);
	DDX_Control(pDX, IDC_STATIC_FTP, m_staFtp);
	DDX_Text(pDX, IDC_EDIT_FTP, m_strFtp);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_PWD, m_strPwd);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFtpDlg, CDialog)
	//{{AFX_MSG_MAP(CFtpDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, OnQuery)
	ON_BN_CLICKED(IDC_DOWNLOAD, OnDownload)
	ON_BN_CLICKED(IDC_UPLOAD, OnUpload)
	ON_LBN_SELCHANGE(IDC_LIST_FILE, OnSelchangeListFile)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFtpDlg message handlers

BOOL CFtpDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_strFtp=_T("");    // ��ʼ������������
	m_strName=_T("");     // ��ʼ����¼�û���
	m_strPwd=_T("");      //  ��ʼ����¼����
	UpdateData(FALSE);    //���½���

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFtpDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFtpDlg::OnPaint() 
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
HCURSOR CFtpDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

//���û���������ѯ����ťʱ��ִ�д˺������˺�������һ�����̣߳�ִ��ʵ�ʵĲ�ѯ
void  CFtpDlg::OnQuery()
{
	//����û��ڶԻ����еĵ�ǰ����
	UpdateData(TRUE);
	//���������߳̿��ƺ����������ݵĽṹ����
	FTP_INFO* pp = new FTP_INFO;
	pp->pList = &m_listFile;
	pp->strFtpSite = m_strFtp;
	pp->strName = m_strName;
	pp->strPwd = m_strPwd;
	// ����Ի������б�������
	while (m_listFile.GetCount() != 0) m_listFile.DeleteString(0);
	//�������������̣߳�ִ��ʵ�ʵĲ�ѯ����
	AfxBeginThread(mtQuery, pp);
}

//��ѯ�Ժ󣬵��û����б����ѡ����һ���ļ�ʱ��ִ�д˺�����
void CFtpDlg::OnSelchangeListFile() 
{
	// ��������������ı���ؼ�
	m_editFtp.EnableWindow(FALSE);          //���������������ı���
	m_editName.EnableWindow(FALSE);        //��¼�û��������ı��� 
	m_editPwd.EnableWindow(FALSE);          //���������ı���
	m_staFtp.EnableWindow(FALSE);
	m_staName.EnableWindow(FALSE);
	m_staPwd.EnableWindow(FALSE);

	//���ò�ѯ���ϴ���ť
	m_btnUpload.EnableWindow(FALSE);      //�ϴ���ť
	m_btnQuery.EnableWindow(FALSE);        //��ѯ��ť

	//�������ذ�ť
	m_btnDownload.EnableWindow(TRUE);
}

//���û����������ء���ťʱ��ִ�д˺���
void CFtpDlg::OnDownload()
{
	//����û��ڶԻ����еĵ�ǰ����
	UpdateData(TRUE);
	//���������߳̿��ƺ����������ݵĽṹ����
	FTP_INFO* pp = new FTP_INFO;
	//���û�����������Ϣ��ֵ���ṹ����ĳ�Ա������
	pp->pList = &m_listFile;
	pp->strFtpSite = m_strFtp;
	pp->strName = m_strName;
	pp->strPwd = m_strPwd;
	//�����������µ��̣߳����ʵ�ʵ���������
	AfxBeginThread(mtDownloadFile, pp);

	//���öԻ����еġ����ء���ť
	m_btnDownload.EnableWindow(FALSE);

	//����Ի����еġ���ѯ���͡��ϴ�����ť
	m_btnUpload.EnableWindow(TRUE);
	m_btnQuery.EnableWindow(TRUE);

	//����Ի���������������ı���ؼ�
	m_editFtp.EnableWindow(TRUE);
	m_editName.EnableWindow(TRUE);
	m_editPwd.EnableWindow(TRUE);
	m_staFtp.EnableWindow(TRUE);
	m_staName.EnableWindow(TRUE);
	m_staPwd.EnableWindow(TRUE);
}

//���û��������ϴ�����ťʱ��ִ�д��¼�������
void CFtpDlg::OnUpload()
{
	//����û��ڶԻ����еĵ�ǰ���룬������������û����Ϳ���
	UpdateData(TRUE);

	//���Ի���������������ı���ؼ�����
	m_editFtp.EnableWindow(FALSE);			//���������������ı���
	m_editName.EnableWindow(FALSE);			//��¼�ͻ��������ı���
	m_editPwd.EnableWindow(FALSE);			//���������ı���
	m_staFtp.EnableWindow(FALSE);			//��Ӧ�ľ�̬�ı�
	m_staName.EnableWindow(FALSE);
	m_staPwd.EnableWindow(FALSE);

	//���öԻ����еġ���ѯ����ť
	m_btnQuery.EnableWindow(FALSE);
	//���������߳̿��ƺ����������ݵĽṹ����
	FTP_INFO* pp = new FTP_INFO;
	//���û�����������Ϣ��ֵ���ṹ����ĳ�Ա������
	pp->pList = NULL;
	pp->strFtpSite = m_strFtp;
	pp->strName = m_strName;
	pp->strPwd = m_strPwd;
	//�����������µ��̣߳������ʵ�ʵ��ϴ�����
	AfxBeginThread(mtUploadFile, pp);

	//����Ի����еġ���ѯ����ť
	m_btnQuery.EnableWindow(TRUE);

	//����Ի���������������ı���ؼ�
	m_editFtp.EnableWindow(TRUE);
	m_editName.EnableWindow(TRUE);
	m_editPwd.EnableWindow(TRUE);
	m_staFtp.EnableWindow(TRUE);
	m_staName.EnableWindow(TRUE);
	m_staPwd.EnableWindow(TRUE);
}

