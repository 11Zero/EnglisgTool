// Version.cpp : implementation file
//

#include "stdafx.h"
#include "EnglishTool.h"
#include "Version.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Version dialog


Version::Version(CWnd* pParent /*=NULL*/)
	: CDialog(Version::IDD, pParent)
{
	//{{AFX_DATA_INIT(Version)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void Version::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Version)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Version, CDialog)
	//{{AFX_MSG_MAP(Version)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Version message handlers

//DEL void Version::OnHelp() 
//DEL {
//DEL }

//DEL void Version::OnVersion() 
//DEL {
//DEL 	Version dlg;
//DEL 	dlg.DoModal();
//DEL 	// TODO: Add your command handler code here
//DEL 	
//DEL }

void Version::OnOK() 
{
	
	CDialog::OnOK();
}

BOOL Version::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
