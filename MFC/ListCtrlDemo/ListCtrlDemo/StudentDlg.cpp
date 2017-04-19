// StudentDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ListCtrlDemo.h"
#include "StudentDlg.h"
#include "afxdialogex.h"


// CStudentDlg dialog

IMPLEMENT_DYNAMIC(CStudentDlg, CDialog)

CStudentDlg::CStudentDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DLG_STUDENT_EDIT, pParent)
	, m_sFIO(_T(""))
	, m_sMark(0)
	, m_fMark(0)
	, m_fFIO(_T(""))
{

}

CStudentDlg::~CStudentDlg()
{
}

void CStudentDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_FIO, m_sFIO);
	/*DDX_Text(pDX, IDC_EDIT2, m_sMark);*/
	DDX_Text(pDX, IDC_EDIT_MARK, m_fMark);
	/*DDX_Text(pDX, IDC_EDIT_FIO, m_fFIO);*/
}


BEGIN_MESSAGE_MAP(CStudentDlg, CDialog)
END_MESSAGE_MAP()


// CStudentDlg message handlers
