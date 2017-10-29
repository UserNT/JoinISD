#pragma once


// CGeneral dialog

class CGeneral : public CDialogEx
{
	DECLARE_DYNAMIC(CGeneral)

public:
	CGeneral(CWnd* pParent = NULL);   // standard constructor
	virtual ~CGeneral();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GENERAL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_stingPerson;
	CString m_stringStatus;
};
