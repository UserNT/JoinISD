
// Task01.h : interface of the CTask01 class
//

#pragma once
#include"ListUser.h"
#include"MyTabCtrl.h"
#include "afxcmn.h"
class CTask01 : public CFormView
{
protected: // create from serialization only
	CTask01();
	DECLARE_DYNCREATE(CTask01)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_TASK1_FORM };
#endif

// Attributes
public:	
	CTask1Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct

// Implementation
public:
	virtual ~CTask01();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	CString m_stringBugName;
	CMyTabCtrl m_tabMyTabCtrl;
	CListCtrl m_listBugStatus;
};

#ifndef _DEBUG  // debug version in Task01.cpp
inline CTask1Doc* CTask01::GetDocument() const
   { return reinterpret_cast<CTask1Doc*>(m_pDocument); }
#endif

