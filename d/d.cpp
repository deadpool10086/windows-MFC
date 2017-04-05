// login.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

BOOL CALLBACK MainProc(
  HWND hwndDlg,  // handle to dialog box
  UINT uMsg,     // message
  WPARAM wParam, // first message parameter
  LPARAM lParam  // second message parameter
)
{
	return 0;
}


int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
   int nRet = DialogBox(hInstance, (LPCSTR)IDD_DIALOG1, NULL, MainProc);
	int i=0;
	return 0;
}



