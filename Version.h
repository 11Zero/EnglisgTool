#if !defined(AFX_VERSION_H__3B6B49B1_8C5C_436A_84AA_1ABE532A3160__INCLUDED_)
#define AFX_VERSION_H__3B6B49B1_8C5C_436A_84AA_1ABE532A3160__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Version.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Version dialog

class Version : public CDialog
{
// Construction
public:
	Version(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Version)
	enum { IDD = IDD_DIALOG_VERSION };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Version)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(Version)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VERSION_H__3B6B49B1_8C5C_436A_84AA_1ABE532A3160__INCLUDED_)
