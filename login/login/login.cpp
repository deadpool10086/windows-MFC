// login.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"

BOOL CALLBACK MainProc(
  HWND hwndDlg,  // handle to dialog box
  UINT uMsg,     // message
  WPARAM wParam, // first message parameter
  LPARAM lParam  // second message parameter
)
{
	if (WM_COMMAND == uMsg)
	{
		if(LOWORD(wParam)==IDCANCEL)
		{
			EndDialog(hwndDlg,10086);
			return TRUE;
		}
		if(LOWORD(wParam)==IDOK)
		{
			char sName[20];
			char sPass[20];
			GetDlgItemText(hwndDlg,IDC_NAME,sName,20);
			GetDlgItemText(hwndDlg,IDC_PASS,sPass,20);
			if(!strcmp(sName, sPass))
			{
				MessageBox(hwndDlg,"the same","message",0);
				EndDialog(hwndDlg,100);
			}
			else
			{
				MessageBox(hwndDlg,"wrong anser","message",0);
			}

			return TRUE;
		}
	}
	return 0;
}


int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	int nRet = DialogBox(hInstance, (LPCSTR)IDD_DIALOG, NULL, MainProc);
	if (nRet == 10086)
	{
		MessageBox(NULL,"10086","·µ»ØÖµ", MB_OK);
	}
	return 0;
}



