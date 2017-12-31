; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=wwer
LastTemplate=CButton
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "CAsyncSocketServer.h"

ClassCount=5
Class1=CCAsyncSocketServerApp
Class2=CCAsyncSocketServerDlg

ResourceCount=2
Resource1=IDR_MAINFRAME
Class3=CMySocket
Class4=asd
Class5=wwer
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
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CCAsyncSocketServerDlg



[DLG:IDD_CASYNCSOCKETSERVER_DIALOG]
Type=1
Class=CCAsyncSocketServerDlg
ControlCount=13
Control1=IDC_BUTTON_CLOSE,button,1342242817
Control2=IDOK,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_SERVNAME,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT2_SERVPORT,edit,1350631552
Control7=IDC_BUTTON_CONNRCT,button,1342242816
Control8=IDC_STATIC,static,1342308865
Control9=IDC_EDIT_MSG,edit,1350631552
Control10=IDC_LIST_SENT,listbox,1352728835
Control11=IDC_LIST_RECEIVED,listbox,1352728835
Control12=IDC_STATIC,static,1342308353
Control13=IDC_STATIC,static,1342308353

[CLS:CMySocket]
Type=0
HeaderFile=MySocket.h
ImplementationFile=MySocket.cpp
BaseClass=CAsyncSocket
Filter=N
LastObject=CMySocket
VirtualFilter=q

[CLS:asd]
Type=0
HeaderFile=asd.h
ImplementationFile=asd.cpp
BaseClass=CAsyncMonikerFile
Filter=N

[CLS:wwer]
Type=0
HeaderFile=wwer.h
ImplementationFile=wwer.cpp
BaseClass=CButton
Filter=W

