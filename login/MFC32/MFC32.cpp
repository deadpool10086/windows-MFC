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
 	MessageBox(NULL,"Win32���������ʽ","Win32���",0);
	return 0;
}

*/

