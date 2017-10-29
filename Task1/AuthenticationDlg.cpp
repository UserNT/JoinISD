// AuthenticationDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Task1.h"
#include "AuthenticationDlg.h"
#include "afxdialogex.h"
#include "Task1Doc.h"


// AuthenticationDlg dialog

IMPLEMENT_DYNAMIC(AuthenticationDlg, CDialogEx)

AuthenticationDlg::AuthenticationDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_AUTHENTICATION, pParent)
	, m_sLogin(_T(""))
	, m_sPassword(_T("")), ListUser(NULL)
{

}

AuthenticationDlg::~AuthenticationDlg()
{
}

void AuthenticationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_LOGIN, m_sLogin);
	DDX_Text(pDX, IDC_PASSWORD, m_sPassword);
}


BEGIN_MESSAGE_MAP(AuthenticationDlg, CDialogEx)
	ON_COMMAND(IDOK, &AuthenticationDlg::OnIdok)
	ON_COMMAND(IDCANCEL, &AuthenticationDlg::OnIdcancel)
	ON_BN_CLICKED(IDC_BUTTON1, &AuthenticationDlg::OnLogin)
	ON_BN_CLICKED(IDC_BUTTON2, &AuthenticationDlg::OnRegister)
END_MESSAGE_MAP()


// AuthenticationDlg message handlers


bool AuthenticationDlg::IsValidUser(CString login, CString password)
{
	/*IsValid(login, password)*/
	return 0 ;
}

void AuthenticationDlg::OnIdok()
{
	
}


void AuthenticationDlg::OnIdcancel()
{
	// TODO: Add your command handler code here
}


void AuthenticationDlg::OnLogin()
{
	UpdateData(TRUE);
	CString login = m_sLogin;
	CString password = m_sPassword;
	
	if (ListUser->IsValid(login, password))
		this->EndDialog(IDOK);
	else
		MessageBox(_T("Incorrect login or password"), _T("Error"), MB_OK | MB_ICONINFORMATION);
}


void AuthenticationDlg::OnRegister()
{
	UpdateData(TRUE);
	CString login = m_sLogin;
	CString password = m_sPassword;
	while (ListUser->IsValid(login, password))
	{
		MessageBox(_T("This user already exists! Try again."), _T("Error"), MB_OK | MB_ICONINFORMATION);
		UpdateData(TRUE);
		login = m_sLogin;
		password = m_sPassword;
	}
	User u;
	u.Setlogin(m_sLogin);
	u.SetPassword(m_sPassword);
	ListUser->PushBack(&u);
}
