#pragma once
#include "afxcmn.h"


// CComments dialog

class CComments : public CDialogEx
{
	DECLARE_DYNAMIC(CComments)

public:
	CComments(CWnd* pParent = NULL);   // standard constructor
	virtual ~CComments();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COMMENTS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_ctrlListComments;
	virtual BOOL OnInitDialog();
	CString m_sringComment;
};
