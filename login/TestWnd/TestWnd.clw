; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMyList
LastTemplate=CListCtrl
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "TestWnd.h"

ClassCount=4
Class1=CTestWndApp
Class2=CTestWndDlg

ResourceCount=2
Resource1=IDR_MAINFRAME
Class3=CMyButton
Class4=CMyList
Resource2=IDD_TESTWND_DIALOG

[CLS:CTestWndApp]
Type=0
HeaderFile=TestWnd.h
ImplementationFile=TestWnd.cpp
Filter=N

[CLS:CTestWndDlg]
Type=0
HeaderFile=TestWndDlg.h
ImplementationFile=TestWndDlg.cpp
Filter=W
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CTestWndDlg



[DLG:IDD_TESTWND_DIALOG]
Type=1
Class=CTestWndDlg
ControlCount=23
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_BUTTON1,button,1342242816
Control4=IDC_BUTTON2,button,1342242816
Control5=IDC_BUTTON3,button,1342242816
Control6=IDC_BUTTON4,button,1342242816
Control7=IDC_BUTTON5,button,1342242816
Control8=IDC_EDIT1,edit,1350631552
Control9=IDC_BUTTON6,button,1342242816
Control10=IDC_BUTTON7,button,1342242816
Control11=IDC_BUTTON8,button,1342242816
Control12=IDC_BUTTON9,button,1342242816
Control13=IDC_BUTTON10,button,1342242816
Control14=IDC_BUTTON11,button,1342242816
Control15=IDC_BUTTON12,button,1342242816
Control16=IDC_BUTTON13,button,1342242816
Control17=IDC_BUTTON14,button,1342242816
Control18=IDC_BUTTON15,button,1342242816
Control19=IDC_BUTTON16,button,1342242816
Control20=IDC_BUTTON17,button,1342242816
Control21=IDC_BUTTON18,button,1342242816
Control22=IDC_BUTTON19,button,1342242816
Control23=IDC_BUTTON20,button,1342242816

[CLS:CMyButton]
Type=0
HeaderFile=MyButton.h
ImplementationFile=MyButton.cpp
BaseClass=CWnd
Filter=D
VirtualFilter=WC

[CLS:CMyList]
Type=0
HeaderFile=MyList.h
ImplementationFile=MyList.cpp
BaseClass=CListCtrl
Filter=W

