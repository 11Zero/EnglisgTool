// EnglishToolDlg.cpp : implementation file
//

#include "stdafx.h"
#include "EnglishTool.h"
#include "EnglishToolDlg.h"
#include "Version.h"
#include "Help.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern CString GB2312ToUTF8(char* str);
extern CString UTF8ToGB2312(char* str);
	char En[100];
	char Cn[100];
	char EnCheck[100];
	char CnCheck[100];
	int SelCount=0;
	int RandomSel=0;
	int FindFlag=0;
	int check_callback(void* pData,int nCount,char** pValue,char** pName)
	{
		if(strcmp(pValue[1],EnCheck)==0)
		{
			CString str = "";
			FindFlag=1;
			str = UTF8ToGB2312(pValue[2]);
			sprintf(CnCheck,"%s",str);
		}
		if(RandomSel==SelCount)
		{
			CString str = "";
			str = UTF8ToGB2312(pValue[1]);
			sprintf(En,"%s",str);
			str = UTF8ToGB2312(pValue[2]);
			sprintf(Cn,"%s",str);
		}
		SelCount++;
		return 0;
	}

/////////////////////////////////////////////////////////////////////////////
// CEnglishToolDlg dialog

CEnglishToolDlg::CEnglishToolDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEnglishToolDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEnglishToolDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEnglishToolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEnglishToolDlg)
	DDX_Control(pDX, IDC_FRAME_MESSAGE, m_MsgPicture);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CEnglishToolDlg, CDialog)
	//{{AFX_MSG_MAP(CEnglishToolDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_RANDOM, OnBtnRandom)
	ON_BN_CLICKED(IDC_BTN_VIEW_CN, OnBtnViewCn)
	ON_BN_CLICKED(IDC_BTN_CLC, OnBtnClc)
	ON_BN_CLICKED(IDC_CHECK_ORDER, OnCheckOrder)
	ON_BN_CLICKED(IDC_CHECK_AUTO, OnCheckAuto)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_CHECK_VIEWCN, OnCheckViewcn)
	ON_WM_DESTROY()
	ON_COMMAND(IDC_VERSION, OnVersion)
	ON_COMMAND(IDC_HELP, OnHelp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEnglishToolDlg message handlers

BOOL CEnglishToolDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	pMenu=new CMenu; 
    pMenu->LoadMenu(IDR_MENU1); 
    SetMenu(pMenu);
	sprintf(En,"");
	sprintf(Cn,"");
	Checked=0;
	InOrder=0;
	IsAuto=0;
	ShowCn=0;
	((CButton*)GetDlgItem(IDC_CHECK_ORDER))->SetCheck(InOrder);
	((CButton*)GetDlgItem(IDC_CHECK_AUTO))->SetCheck(IsAuto);
	((CButton*)GetDlgItem(IDC_CHECK_VIEWCN))->SetCheck(ShowCn);
	OnBtnRandom();
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CEnglishToolDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CEnglishToolDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CEnglishToolDlg::OnOK() 
{
	sqlite3 *db=NULL;
	CString FileName = "dict.dat";
	//CString FilePathName = "";
	CString sqlcmd = "";
    int rc;
	char pBuf[MAX_PATH];                //存放路径的变量
	GetCurrentDirectory(MAX_PATH,pBuf);                   //获取程序的当前目录
	FileName.Format("%s\\Dictionary\\dict.dat",pBuf);
	sprintf(pBuf,"%s",FileName);
	FileName = GB2312ToUTF8(pBuf);
    rc = sqlite3_open(FileName, &db);
	char* ExeErrorMsg = "";
	//rc = sqlite3_exec( db, "drop table MyTable_4", NULL, NULL, &ExeErrorMsg);
	//sqlcmd = "create table dict1(ID integer primary key autoincrement,EN CHAR(30),CN CHAR(50));";
	CString EditEnstr="";
	GetDlgItem(IDC_EDIT_EN)->GetWindowText(EditEnstr);
	CString EditCnstr="";
	GetDlgItem(IDC_EDIT_CN)->GetWindowText(EditCnstr);
	if(strcmp(EditEnstr,"")==0)
		return;
	FindFlag=0;
	SelCount=0;
	sprintf(EnCheck,"%s",EditEnstr);
	sqlite3_exec(db,"select * from dict1",check_callback,NULL,&ExeErrorMsg);//callback1为回调函数
	if(FindFlag)
	{
		if(Checked)
		{
			sqlcmd.Format("update dict1 set CN='%s' where EN='%s'",EditCnstr,EditEnstr);
			sprintf(pBuf,"%s",sqlcmd);
			sqlcmd = GB2312ToUTF8(pBuf);
			rc = sqlite3_exec( db, sqlcmd, NULL, NULL, &ExeErrorMsg);
			sqlite3_close(db);
			EditCnstr.Format("%s已更新！",EditEnstr);
			SetBottomMessage(&EditCnstr);
			Checked=0;
			return;
		}
		GetDlgItem(IDC_EDIT_CN)->SetWindowText(CnCheck);
		EditCnstr.Format("%s已在库，核对中文意思再确认！",EditEnstr);
		Checked=1;
		SetBottomMessage(&EditCnstr);
		return;
	}
	sqlcmd.Format("insert into dict1 (EN,CN) values ('%s','%s')",EditEnstr,EditCnstr);
	sprintf(pBuf,"%s",sqlcmd);
	sqlcmd = GB2312ToUTF8(pBuf);
	rc = sqlite3_exec( db, sqlcmd, NULL, NULL, &ExeErrorMsg);
	sqlite3_close(db);
	EditCnstr.Format("%s已添加！",EditEnstr);
	SetBottomMessage(&EditCnstr);
	return;
	/*sqlcmd = "INSERT INTO phone	VALUES (1,'张长会','13866120701')";
	sqlcmd = "INSERT INTO phone	VALUES (2,'孟再生','15155133889')";
	sprintf(pBuf,"%s",sqlcmd);
	sqlcmd = GB2312ToUTF8(pBuf);
	rc = sqlite3_exec( db, sqlcmd, NULL, NULL, &ExeErrorMsg);*/
	//SelCount = 0;
	//memset(Name,0,sizeof(Name)/sizeof(Name[0][0]));
	//sqlite3_exec(db,"select * from phone",phone_callback,NULL,&ExeErrorMsg);//callback1为回调函数
	//return ;}
}

void CEnglishToolDlg::OnBtnRandom() 
{
	sqlite3 *db=NULL;
	CString FileName = "dict.dat";
	//CString FilePathName = "";
	CString sqlcmd = "";
    int rc;
	char pBuf[MAX_PATH];                //存放路径的变量
	GetCurrentDirectory(MAX_PATH,pBuf);                   //获取程序的当前目录
	FileName.Format("%s\\Dictionary\\dict.dat",pBuf);
	sprintf(pBuf,"%s",FileName);
	FileName = GB2312ToUTF8(pBuf);
    rc = sqlite3_open(FileName, &db);
	char* ExeErrorMsg = "";
	//rc = sqlite3_exec( db, "drop table MyTable_4", NULL, NULL, &ExeErrorMsg);
	//sqlcmd = "create table dict1(ID integer primary key autoincrement,EN CHAR(30),CN CHAR(50));";
	SelCount=0;
	sqlite3_exec(db,"select * from dict1",check_callback,NULL,&ExeErrorMsg);//callback1为回调函数
	if(InOrder)
	{
		RandomSel++;
		if(RandomSel>SelCount)
			RandomSel=0;
	}
	else
	{
		srand((int)time(0));
		RandomSel=rand()%SelCount;
	}
	SelCount=0;	
	sqlite3_exec(db,"select * from dict1",check_callback,NULL,&ExeErrorMsg);
	sqlite3_close(db);
	GetDlgItem(IDC_EDIT_EN)->SetWindowText(En);
	if(ShowCn)
		GetDlgItem(IDC_EDIT_CN)->SetWindowText(Cn);
	else
		GetDlgItem(IDC_EDIT_CN)->SetWindowText("");
	Invalidate();
	//sqlcmd.Format("insert into dict1 (EN,CN) values ('%s','%s')",EditEnstr,EditCnstr);
	//sprintf(pBuf,"%s",sqlcmd);
	//sqlcmd = GB2312ToUTF8(pBuf);
	//rc = sqlite3_exec( db, sqlcmd, NULL, NULL, &ExeErrorMsg);
	/*sqlcmd = "INSERT INTO phone	VALUES (1,'张长会','13866120701')";
	sqlcmd = "INSERT INTO phone	VALUES (2,'孟再生','15155133889')";
	sprintf(pBuf,"%s",sqlcmd);
	sqlcmd = GB2312ToUTF8(pBuf);
	rc = sqlite3_exec( db, sqlcmd, NULL, NULL, &ExeErrorMsg);*/
	//SelCount = 0;
	//memset(Name,0,sizeof(Name)/sizeof(Name[0][0]));
	//sqlite3_exec(db,"select * from phone",phone_callback,NULL,&ExeErrorMsg);//callback1为回调函数

}

void CEnglishToolDlg::OnBtnViewCn() 
{
	GetDlgItem(IDC_EDIT_CN)->SetWindowText(Cn);	
	CString str="";
	str.Format("%s,%s",En,Cn);
	SetBottomMessage(&str);
}
void CEnglishToolDlg::SetBottomMessage(CString* str)
{

		CDC* pDC = m_MsgPicture.GetDC();
		CRect rc;
		m_MsgPicture.GetClientRect(&rc);
		CBrush br;
		br.CreateSolidBrush(RGB(200,200,200));// 白色
		pDC->FillRect(&rc,&br);
		pDC->SetBkMode(TRANSPARENT);
		CFont font;
		font.CreatePointFont(100, "宋体");
		pDC->SelectObject(&font);
		//CString MsgText = _T("");
		//MsgText.Format("扫描时间间已修改为%dms",Delay_Time);//修复提醒消息刷新问题
		pDC->SetTextColor(RGB(rand()%180,rand()%180,rand()%180));
		pDC->TextOut(3,3,*str);
		ReleaseDC(pDC);
}

void CEnglishToolDlg::OnBtnClc() 
{
	GetDlgItem(IDC_EDIT_CN)->SetWindowText("");	
	GetDlgItem(IDC_EDIT_EN)->SetWindowText("");	
	
}

void CEnglishToolDlg::OnCheckOrder() 
{
	InOrder=!InOrder;
	((CButton*)GetDlgItem(IDC_CHECK_ORDER))->SetCheck(InOrder);
}

void CEnglishToolDlg::OnCheckAuto() 
{
	if(IsAuto)
	{
		KillTimer(1);
	}
	else
	{
		SetTimer(1,1000,NULL);
	}
	IsAuto=!IsAuto;
	((CButton*)GetDlgItem(IDC_CHECK_AUTO))->SetCheck(IsAuto);
}

void CEnglishToolDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if(nIDEvent==1)
	{
		OnBtnRandom();
	}
	CDialog::OnTimer(nIDEvent);
}

void CEnglishToolDlg::OnCheckViewcn() 
{
	ShowCn=!ShowCn;
	((CButton*)GetDlgItem(IDC_CHECK_VIEWCN))->SetCheck(ShowCn);
	if(ShowCn)
		GetDlgItem(IDC_EDIT_CN)->SetWindowText(Cn);
	else
		GetDlgItem(IDC_EDIT_CN)->SetWindowText("");
}

void CEnglishToolDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	delete pMenu;	
}

void CEnglishToolDlg::OnVersion() 
{
 	Version dlg;
 	dlg.DoModal();
}

void CEnglishToolDlg::OnHelp() 
{
	Help dlg;
 	dlg.DoModal();
	
}
