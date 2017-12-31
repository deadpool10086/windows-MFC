; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSockC
LastTemplate=CSocket
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "TCPS.h"

ClassCount=7
Class1=CTCPSApp
Class2=CTCPSDlg

ResourceCount=2
Resource1=IDR_MAINFRAME
Class5=CSock
Class6=CSockt
Class7=CSockC
Resource2=IDD_TCPS_DIALOG

[CLS:CTCPSApp]
Type=0
HeaderFile=TCPS.h
ImplementationFile=TCPS.cpp
Filter=N

[CLS:CTCPSDlg]
Type=0
HeaderFile=TCPSDlg.h
ImplementationFile=TCPSDlg.cpp
Filter=D



[DLG:IDD_TCPS_DIALOG]
Type=1
Class=CTCPSDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT2,edit,1484849280

[CLS:CSock]
Type=0
HeaderFile=Sock.h
ImplementationFile=Sock.cpp
BaseClass=CSocket
Filter=N

[CLS:CSockt]
Type=0
HeaderFile=Sockt.h
ImplementationFile=Sockt.cpp
BaseClass=CSocket
Filter=N

[CLS:CSockC]
Type=0
HeaderFile=SockC.h
ImplementationFile=SockC.cpp
BaseClass=CSocket
Filter=N

