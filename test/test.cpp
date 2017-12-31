// test.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"

unsigned char KEY[8] = {0x13, 0xac, 0xa3, 0xcf, 0xf2, 0x9d, 0xc3, 0x5a};
int remove(unsigned char* data,int sum)
{
	if (sum > 23)
		return 0;
	unsigned char mark[] = {0x75,0xc0,0xc2,0xa8,0x89,0xf9,0xb4,0x5,0x60,0xc8,0xe5,0xbc,0x96,0xea,0x9c,0x3d,0x7b,0xc6,0xf6,0x90,0x96,0xfb,0xbe};
	int count = 0;
	for(int i=0; i<23 ; i++)
	{
		if ((KEY[count]^data[i]) != (mark[i]))
			return 0;
		count++;
		if (count == 8)
		count = 0; 
	}
	return 1;
}


BOOL CALLBACK MainProc(
  HWND hwndDlg,  // handle to dialog box
  UINT uMsg,     // message
  WPARAM wParam, // first message parameter
  LPARAM lParam  // second message parameter
)
{
	if(WM_COMMAND==uMsg)
	{
		if(LOWORD(wParam)==IDCANCEL)
		{
			EndDialog(hwndDlg,IDCANCEL);
		}
		if(LOWORD(wParam)==IDOK)
		{
			int sum;
			char data[40];
			if(sum = GetDlgItemText(hwndDlg,IDC_ANSER,data,40))
			{
				if(remove((unsigned char *)data,sum))
					MessageBox(hwndDlg,"很好你成功的拿到了flag","提示",MB_OK);
				else
					MessageBox(hwndDlg,"好像不太对哦","提示",MB_OK);
			}
			else
			{
				MessageBox(hwndDlg,"不能为空值","提示",MB_OK);
			}
		}
	}
	OutputDebugString("耐心是美德\n");
	return 0;
}


int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	DialogBox(hInstance,(LPCSTR)IDD_DIALOG1,NULL,MainProc);
	return 0;
}


/*
	int nRet = MessageBox(NULL,"这是内容","这是标题",MB_OKCANCEL);
	if (nRet==IDOK)
		MessageBox(NULL,"ok","返回值",0);
	if (nRet==IDCANCEL)
		MessageBox(NULL,"cancel","返回值",0);
*/