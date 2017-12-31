; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCAsyncSocketServerDlg
LastTemplate=CAsyncSocket
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "CAsyncSocketServer.h"

ClassCount=3
Class1=CCAsyncSocketServerApp
Class2=CCAsyncSocketServerDlg

ResourceCount=2
Resource1=IDR_MAINFRAME
Class3=CMysocket
Resource2=IDD_CASYNCSOCKETSERVER_DIALOG

[CLS:CCAsyncSocketServerApp]
Type=0
HeaderFile=CAsyncSocketServer.h
ImplementationFile=CAsyncSocketServer.cpp
Filter=N

[CLS:CCAsyncSocketServerDlg]
Type=0
HeaderFile=CAsyncSocketServerDlg.h
ImplementationFile=CAsyncSocketServerDlg.cpp
Filter=D
LastObject=CCAsyncSocketServerDlg
BaseClass=CDialog
VirtualFilter=dWC



[DLG:IDD_CASYNCSOCKETSERVER_DIALOG]
Type=1
Class=CCAsyncSocketServerDlg
ControlCount=13
Control1=IDC_BUTTON_CLOSE,button,1342242817
Control2=IDOK,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_BUTTON_LISTEN,button,1342242816
Control5=IDC_EDIT_SERVNAME,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT_SERVPORT,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_EDIT_MSG,edit,1350631552
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_LIST_SENT,listbox,1352728835
Control13=IDC_LIST_RECEIVED,listbox,1352728835

[CLS:CMysocket]
Type=0
HeaderFile=Mysocket.h
ImplementationFile=Mysocket.cpp
BaseClass=CAsyncSocket
Filter=N
VirtualFilter=q
LastObject=CMysocket

