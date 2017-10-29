#pragma once
#include "afxcmn.h"


// CAttachments dialog

class CAttachments : public CDialogEx
{
	DECLARE_DYNAMIC(CAttachments)

public:
	CAttachments(CWnd* pParent = NULL);   // standard constructor
	virtual ~CAttachments();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ATTACHMENTS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_listAttachments;
	virtual BOOL OnInitDialog();
};
