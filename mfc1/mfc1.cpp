// mfc1.cpp : Defines the entry point for the application.
//


#include "stdafx.h"
#include "resource.h"
#include <stdio.h>

BOOL CALLBACK LonlFunctiom(HWND hwndDlg,UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	char s[256];
	sprintf(s,"uMsg=0x%x,wParam=0x%x,lParam=0x%x\n",uMsg,wParam,lParam);
	OutputDebugString(s);
	if (WM_COMMAND == uMsg) 
	{
		if(LOWORD(wParam)==IDCANCEL)
		{
			EndDialog(hwndDlg,IDCANCEL);
			return TRUE;
		}
		if(LOWORD(wParam)==IDOK)
		{
			int nQues = GetDlgItemInt(hwndDlg, IDC_QUES,NULL,TRUE);
			if (nQues==2)
			{
				SetDlgItemInt(hwndDlg, IDC_ANSER, 2, TRUE);
			}
			else
			{
				SetDlgItemInt(hwndDlg, IDC_ANSER, 1, TRUE);
			}
		//	MessageBox(hwndDlg,"�������!","����̫˧�ˣ�",MB_OK);
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
	 
	DialogBox(hInstance,(LPCSTR)IDD_DIALOG1,NULL,LonlFunctiom);
	
	return 0;
}


/*
	HWND hWnd = ::FindWindow(NULL,"�ޱ��� - ���±�");
 	int nRet = MessageBox(hWnd,"�����ҿ����ĵ�һ��windows���!","�¸¸¸¸�",MB_YESNO|MB_ICONASTERISK);
	if (nRet == IDYES)
		MessageBox(NULL,"������YES!","��˵�Ķ�ô?",0);
	else if (nRet == IDNO)
		MessageBox(NULL,"������NO!","��˵�Ķ�ô��",0);
*/