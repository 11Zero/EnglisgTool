; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CEnglishToolDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "EnglishTool.h"

ClassCount=4
Class1=CEnglishToolApp
Class2=CEnglishToolDlg

ResourceCount=5
Resource2=IDD_DIALOG_VERSION
Resource3=IDD_ENGLISHTOOL_DIALOG
Resource1=IDR_MAINFRAME
Class3=Version
Resource4=IDD_DIALOG_HELP
Class4=Help
Resource5=IDR_MENU1

[CLS:CEnglishToolApp]
Type=0
HeaderFile=EnglishTool.h
ImplementationFile=EnglishTool.cpp
Filter=N

[CLS:CEnglishToolDlg]
Type=0
HeaderFile=EnglishToolDlg.h
ImplementationFile=EnglishToolDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_SLIDER1



[DLG:IDD_ENGLISHTOOL_DIALOG]
Type=1
Class=CEnglishToolDlg
ControlCount=13
Control1=IDC_EDIT_EN,edit,1350631552
Control2=IDC_EDIT_CN,edit,1350631552
Control3=IDOK,button,1342242817
Control4=IDC_BTN_RANDOM,button,1342242816
Control5=IDC_BTN_VIEW_CN,button,1342242816
Control6=IDC_FRAME_MESSAGE,static,1342177286
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_BTN_CLC,button,1342242816
Control10=IDC_CHECK_ORDER,button,1342242819
Control11=IDC_CHECK_AUTO,button,1342242819
Control12=IDC_CHECK_VIEWCN,button,1342242819
Control13=IDC_SLIDER,msctls_trackbar32,1342242855

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=IDC_HELP
Command2=IDC_VERSION
CommandCount=2

[DLG:IDD_DIALOG_VERSION]
Type=1
Class=Version
ControlCount=3
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDOK,button,1342242816

[CLS:Version]
Type=0
HeaderFile=Version.h
ImplementationFile=Version.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_VERSION

[DLG:IDD_DIALOG_HELP]
Type=1
Class=Help
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352

[CLS:Help]
Type=0
HeaderFile=Help.h
ImplementationFile=Help.cpp
BaseClass=CDialog
Filter=D
LastObject=Help
VirtualFilter=dWC

