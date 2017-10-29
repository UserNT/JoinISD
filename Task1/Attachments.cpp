// Attachments.cpp : implementation file
//

#include "stdafx.h"
#include "Task1.h"
#include "Attachments.h"
#include "afxdialogex.h"


// CAttachments dialog

IMPLEMENT_DYNAMIC(CAttachments, CDialogEx)

CAttachments::CAttachments(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ATTACHMENTS, pParent)
{

}

CAttachments::~CAttachments()
{
}

void CAttachments::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listAttachments);
}


BEGIN_MESSAGE_MAP(CAttachments, CDialogEx)
END_MESSAGE_MAP()


// CAttachments message handlers


BOOL CAttachments::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_listAttachments.InsertColumn(0, _T("File Name"), LVCFMT_CENTER, 115);
	m_listAttachments.InsertColumn(0, _T("Action"), LVCFMT_CENTER, 115);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
