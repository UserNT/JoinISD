// General.cpp : implementation file
//

#include "stdafx.h"
#include "Task1.h"
#include "General.h"
#include "afxdialogex.h"


// CGeneral dialog

IMPLEMENT_DYNAMIC(CGeneral, CDialogEx)

CGeneral::CGeneral(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_GENERAL, pParent)
	, m_stingPerson(_T("Vitalij"))
	, m_stringStatus(_T("New"))
{

}

CGeneral::~CGeneral()
{
}

void CGeneral::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_COMBO_PERSON, m_stingPerson);
	DDX_CBString(pDX, IDC_COMBO_STATUS, m_stringStatus);
}


BEGIN_MESSAGE_MAP(CGeneral, CDialogEx)
END_MESSAGE_MAP()


// CGeneral message handlers
