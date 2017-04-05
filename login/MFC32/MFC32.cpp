// MFC32.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "MainDlg.h"
class CMyApp:public CWinApp
{
	virtual BOOL InitInstance()
	{
		CMainDlg dlg;
		dlg.DoModal();
	//	AfxMessageBox("succeed!");
		return TRUE;
	}
};
CMyApp theApp;
/*
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	MessageBox(NULL,"Win32软件启动方式","Win32软件",0);
	return 0;
}

*/

