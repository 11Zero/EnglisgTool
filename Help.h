#if !defined(AFX_HELP_H__43F392EB_7803_43E4_9687_EDBCEBA59B3B__INCLUDED_)
#define AFX_HELP_H__43F392EB_7803_43E4_9687_EDBCEBA59B3B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Help.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Help dialog

class Help : public CDialog
{
// Construction
public:
	Help(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Help)
	enum { IDD = IDD_DIALOG_HELP };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Help)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(Help)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HELP_H__43F392EB_7803_43E4_9687_EDBCEBA59B3B__INCLUDED_)
