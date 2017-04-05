// TEST32.cpp : Defines the entry point for the application.
//



#include "stdafx.h"
#include "resource.h"
#include "stdio.h"

BOOL CALLBACK theProc(  HWND hwndDlg,  // handle to dialog box
  UINT uMsg,     // message  
  WPARAM wParam, // first message parameter
  LPARAM lParam  // second message parameter
  )
  
{
	switch(uMsg)
	{
	case WM_INITDIALOG:
		MoveWindow(hwndDlg,100,100,400,300,FALSE);
		SetWindowText(hwndDlg,"wcwcwc"); 
	return TRUE;
	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case IDOK:
		case IDCANCEL:
			EndDialog(hwndDlg,LOWORD(wParam));
			return TRUE;
		case IDC_BUTTON1:
			{
				HWND hWnd = FindWindow("notepad",NULL);
				SendMessage(hwndDlg,WM_LBUTTONDOWN,MK_LBUTTON,0x00230054);
			}
		}
		break;
	case WM_LBUTTONDOWN:
		{
			int x = LOWORD(lParam);
			int y = HIWORD(lParam);
			char s[200];
			sprintf(s,"x-%d,y-%d",x,y);
			MessageBox(hwndDlg,s,"wocao",0);
		}
	return TRUE;
	case WM_MOUSEMOVE:
		{
			int x = LOWORD(lParam);
			int y = HIWORD(lParam);
			char s[200];
			sprintf(s,"x-%d,y-%d",x,y);
			SetWindowText(hwndDlg,s);
		}
	return TRUE;
	case WM_PAINT:
		OutputDebugString("asdasd\n");
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwndDlg,&ps);
			Ellipse(hdc,0,0,300,200);
		EndPaint(hwndDlg,&ps);
	return TRUE;


	}
	return FALSE;
}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	 DialogBox(hInstance,(LPCTSTR)IDD_DIALOG1,NULL,theProc);

	return 0;
}



