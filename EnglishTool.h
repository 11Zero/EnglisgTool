// EnglishTool.h : main header file for the ENGLISHTOOL application
//

#if !defined(AFX_ENGLISHTOOL_H__2B918344_2664_4A83_A367_F35FD3066CEE__INCLUDED_)
#define AFX_ENGLISHTOOL_H__2B918344_2664_4A83_A367_F35FD3066CEE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CEnglishToolApp:
// See EnglishTool.cpp for the implementation of this class
//

class CEnglishToolApp : public CWinApp
{
public:
	CEnglishToolApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEnglishToolApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CEnglishToolApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENGLISHTOOL_H__2B918344_2664_4A83_A367_F35FD3066CEE__INCLUDED_)
