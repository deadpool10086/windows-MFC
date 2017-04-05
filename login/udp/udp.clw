; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CUdpDlg
LastTemplate=CSocket
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "udp.h"

ClassCount=3
Class1=CUdpApp
Class2=CUdpDlg

ResourceCount=2
Resource1=IDR_MAINFRAME
Class3=CSockU
Resource2=IDD_UDP_DIALOG

[CLS:CUdpApp]
Type=0
HeaderFile=udp.h
ImplementationFile=udp.cpp
Filter=N

[CLS:CUdpDlg]
Type=0
HeaderFile=udpDlg.h
ImplementationFile=udpDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC



[DLG:IDD_UDP_DIALOG]
Type=1
Class=CUdpDlg
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_IP,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_PORT,edit,1350631552
Control7=IDC_HIST,edit,1352730628
Control8=IDC_INPUT,edit,1350631552

[CLS:CSockU]
Type=0
HeaderFile=SockU.h
ImplementationFile=SockU.cpp
BaseClass=CSocket
Filter=N
VirtualFilter=uq
LastObject=CSockU

