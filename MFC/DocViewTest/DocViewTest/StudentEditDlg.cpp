// StudentEditDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DocViewTest.h"
#include "StudentEditDlg.h"
#include "afxdialogex.h"


// CStudentEditDlg dialog

IMPLEMENT_DYNAMIC(CStudentEditDlg, CDialog)

CStudentEditDlg::CStudentEditDlg(CWnd* pParent /*= NULL*/)
	: CDialog(IDD_DLG_STUDENT, pParent)
	, m_strName(_T(""))
	, m_fMark(0)
{

}

CStudentEditDlg::~CStudentEditDlg()
{
}

void CStudentEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_MARK, m_fMark);
}


BEGIN_MESSAGE_MAP(CStudentEditDlg, CDialog)
END_MESSAGE_MAP()


// CStudentEditDlg message handlers
