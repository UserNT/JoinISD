#pragma once


// CStudentDlg dialog

class CStudentDlg : public CDialog
{
	DECLARE_DYNAMIC(CStudentDlg)

public:
	CStudentDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CStudentDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_STUDENT_EDIT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_sFIO;
	float m_sMark;
	float m_fMark;
	CString m_fFIO;
};
