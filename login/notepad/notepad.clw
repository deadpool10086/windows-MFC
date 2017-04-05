; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CNotepadDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "notepad.h"

ClassCount=4
Class1=CNotepadApp
Class2=CNotepadDlg

ResourceCount=4
Resource2=IDR_MAINFRAME
Resource3=IDD_NOTEPAD_DIALOG
Resource4=IDR_MENU1

[CLS:CNotepadApp]
Type=0
HeaderFile=notepad.h
ImplementationFile=notepad.cpp
Filter=N

[CLS:CNotepadDlg]
Type=0
HeaderFile=notepadDlg.h
ImplementationFile=notepadDlg.cpp
Filter=W
BaseClass=CDialog
VirtualFilter=dWC



[DLG:IDD_NOTEPAD_DIALOG]
Type=1
Class=CNotepadDlg
ControlCount=1
Control1=IDC_TEXT,edit,1352732676

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=ID_FILE_OPEN
Command2=ID_FILE_SAVE
Command3=ID_APP_EXIT
CommandCount=3

