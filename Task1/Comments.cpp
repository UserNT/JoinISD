// Comments.cpp : implementation file
//

#include "stdafx.h"
#include "Task1.h"
#include "Comments.h"
#include "afxdialogex.h"


// CComments dialog

IMPLEMENT_DYNAMIC(CComments, CDialogEx)

CComments::CComments(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_COMMENTS, pParent)
	, m_sringComment(_T("New Comment"))
{

}

CComments::~CComments()
{
}

void CComments::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_COMMENTS, m_ctrlListComments);

	DDX_Text(pDX, IDC_EDIT1, m_sringComment);
}


BEGIN_MESSAGE_MAP(CComments, CDialogEx)
END_MESSAGE_MAP()


// CComments message handlers


BOOL CComments::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_ctrlListComments.InsertColumn(0, _T("Author"), LVCFMT_CENTER, 50);
	m_ctrlListComments.InsertColumn(1, _T("Comment"), LVCFMT_CENTER, 105);
	m_ctrlListComments.InsertColumn(2, _T("Date"), LVCFMT_CENTER, 70);

	int nItem = m_ctrlListComments.InsertItem(m_ctrlListComments.GetItemCount(), _T("Andrey"));
	m_ctrlListComments.SetItemText(nItem, 1, _T("Loks Good"));
	m_ctrlListComments.SetItemText(nItem, 2, _T("2/9/2017"));

	nItem = m_ctrlListComments.InsertItem(m_ctrlListComments.GetItemCount(), _T("..."));
	m_ctrlListComments.SetItemText(nItem, 1, _T("..."));
	m_ctrlListComments.SetItemText(nItem, 2, _T("..."));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
