// EnglishToolDlg.h : header file
//

#if !defined(AFX_ENGLISHTOOLDLG_H__9EB2A74C_B112_4A27_ACD0_5217B02CA26E__INCLUDED_)
#define AFX_ENGLISHTOOLDLG_H__9EB2A74C_B112_4A27_ACD0_5217B02CA26E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CEnglishToolDlg dialog

class CEnglishToolDlg : public CDialog
{
// Construction
public:
	int Checked;
	CEnglishToolDlg(CWnd* pParent = NULL);	// standard constructor
	void SetBottomMessage(CString* str);
// Dialog Data
	//{{AFX_DATA(CEnglishToolDlg)
	enum { IDD = IDD_ENGLISHTOOL_DIALOG };
	CSliderCtrl	m_slider;
	CStatic	m_MsgPicture;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEnglishToolDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	int DelayTime;
	CMenu * pMenu;
	HICON m_hIcon;
	int InOrder;
	int IsAuto;
	int ShowCn;
	// Generated message map functions
	//{{AFX_MSG(CEnglishToolDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnBtnRandom();
	afx_msg void OnBtnViewCn();
	afx_msg void OnBtnClc();
	afx_msg void OnCheckOrder();
	afx_msg void OnCheckAuto();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnCheckViewcn();
	afx_msg void OnDestroy();
	afx_msg void OnVersion();
	afx_msg void OnHelp();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENGLISHTOOLDLG_H__9EB2A74C_B112_4A27_ACD0_5217B02CA26E__INCLUDED_)
