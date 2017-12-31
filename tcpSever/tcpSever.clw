; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTcpSeverDlg
LastTemplate=CSocket
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "tcpSever.h"

ClassCount=4
Class1=CTcpSeverApp
Class2=CTcpSeverDlg

ResourceCount=2
Resource1=IDR_MAINFRAME
Class3=CSock
Class4=CSockC
Resource2=IDD_TCPSEVER_DIALOG

[CLS:CTcpSeverApp]
Type=0
HeaderFile=tcpSever.h
ImplementationFile=tcpSever.cpp
Filter=N

[CLS:CTcpSeverDlg]
Type=0
HeaderFile=tcpSeverDlg.h
ImplementationFile=tcpSeverDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CTcpSeverDlg



[DLG:IDD_TCPSEVER_DIALOG]
Type=1
Class=CTcpSeverDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_TEXT,edit,1352734724

[CLS:CSock]
Type=0
HeaderFile=Sock.h
ImplementationFile=Sock.cpp
BaseClass=CSocket
Filter=N
VirtualFilter=uq

[CLS:CSockC]
Type=0
HeaderFile=SockC.h
ImplementationFile=SockC.cpp
BaseClass=CSocket
Filter=N
VirtualFilter=uq

