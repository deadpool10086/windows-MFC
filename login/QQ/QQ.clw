; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CinputDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "qq.h"
LastPage=0

ClassCount=6
Class1=CLoginDlg
Class2=CPriorDlg
Class3=CQQApp
Class4=CQQDlg

ResourceCount=5
Resource1=IDD_INFO_DLG
Resource2=IDD_QQ_DIALOG
Resource3=IDD_PRIOR_DLG
Class5=CinfoDlg
Resource4=IDD_LOGIN_DLG
Class6=CinputDlg
Resource5=IDD_INPUT_DLG

[CLS:CLoginDlg]
Type=0
BaseClass=CDialog
HeaderFile=LoginDlg.h
ImplementationFile=LoginDlg.cpp
LastObject=CLoginDlg

[CLS:CPriorDlg]
Type=0
BaseClass=CDialog
HeaderFile=PriorDlg.h
ImplementationFile=PriorDlg.cpp
Filter=D
VirtualFilter=dWC

[CLS:CQQApp]
Type=0
BaseClass=CWinApp
HeaderFile=QQ.h
ImplementationFile=QQ.cpp

[CLS:CQQDlg]
Type=0
BaseClass=CDialog
HeaderFile=QQDlg.h
ImplementationFile=QQDlg.cpp
Filter=D
VirtualFilter=dWC

[DLG:IDD_LOGIN_DLG]
Type=1
Class=CLoginDlg
ControlCount=6
Control1=IDC_STATIC,static,1342308352
Control2=IDC_NAME,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_PASS,edit,1350631584
Control5=IDOK,button,1342242817
Control6=IDCANCEL,button,1342242816

[DLG:IDD_PRIOR_DLG]
Type=1
Class=CPriorDlg
ControlCount=10
Control1=IDC_STATIC,static,1342308352
Control2=IDC_NAME,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_PASS,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_ADD,button,1342242816
Control7=IDC_DEL,button,1342242816
Control8=IDC_MODIFY,button,1342242816
Control9=IDC_LIST,SysListView32,1350631437
Control10=IDC_PRIOR,combobox,1344339971

[DLG:IDD_QQ_DIALOG]
Type=1
Class=CQQDlg
ControlCount=4
Control1=IDC_RELOGIN,button,1342242816
Control2=IDC_INFO,button,1342242816
Control3=IDC_ADMIN,button,1342242816
Control4=IDC_EXIT,button,1342242816

[DLG:IDD_INFO_DLG]
Type=1
Class=CinfoDlg
ControlCount=6
Control1=IDC_LIST,SysListView32,1350631425
Control2=IDC_ADD,button,1342242816
Control3=IDC_DEL,button,1342242816
Control4=IDC_MOD,button,1342242816
Control5=IDC_OPEN,button,1342242816
Control6=IDC_SAVE,button,1342242816

[CLS:CinfoDlg]
Type=0
HeaderFile=infoDlg.h
ImplementationFile=infoDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CinfoDlg
VirtualFilter=dWC

[DLG:IDD_INPUT_DLG]
Type=1
Class=CinputDlg
ControlCount=12
Control1=IDC_STATIC,static,1342308352
Control2=IDC_NUMB,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_NAME,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_BIRTH,SysDateTimePick32,1342242853
Control7=IDC_STATIC,static,1342308352
Control8=IDC_DEPT,combobox,1344339971
Control9=IDC_STATIC,static,1342308352
Control10=IDC_SALA,edit,1350631552
Control11=IDOK,button,1342242817
Control12=IDCANCEL,button,1342242816

[CLS:CinputDlg]
Type=0
HeaderFile=inputDlg.h
ImplementationFile=inputDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CinputDlg
VirtualFilter=dWC

