; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCSocket
LastTemplate=CSocket
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "CSocketServer.h"

ClassCount=4
Class1=CCSocketServerApp
Class2=CCSocketServerDlg

ResourceCount=2
Resource1=IDR_MAINFRAME
Class3=CCSocket
Class4=CLSocket
Resource2=IDD_CSOCKETSERVER_DIALOG

[CLS:CCSocketServerApp]
Type=0
HeaderFile=CSocketServer.h
ImplementationFile=CSocketServer.cpp
Filter=N

[CLS:CCSocketServerDlg]
Type=0
HeaderFile=CSocketServerDlg.h
ImplementationFile=CSocketServerDlg.cpp
Filter=D
LastObject=CCSocketServerDlg
BaseClass=CDialog
VirtualFilter=dWC



[DLG:IDD_CSOCKETSERVER_DIALOG]
Type=1
Class=CCSocketServerDlg
ControlCount=6
Control1=IDC_BUTTON_LISTEN,button,1342242817
Control2=IDOK,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_PORT,edit,1350631552
Control5=IDC_LIST_MSG,listbox,1352728833
Control6=IDC_STATIC_NUM,static,1342308352

[CLS:CCSocket]
Type=0
HeaderFile=CSocket.h
ImplementationFile=CSocket.cpp
BaseClass=CSocket
Filter=N
LastObject=CCSocket
VirtualFilter=uq

[CLS:CLSocket]
Type=0
HeaderFile=LSocket.h
ImplementationFile=LSocket.cpp
BaseClass=CSocket
Filter=N
LastObject=CLSocket
VirtualFilter=uq

