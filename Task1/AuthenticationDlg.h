#pragma once

#include"ListUser.h"
// AuthenticationDlg dialog

class AuthenticationDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AuthenticationDlg)

public:
	AuthenticationDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~AuthenticationDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AUTHENTICATION };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	List* ListUser;
	bool IsValidUser(CString login, CString password);
	afx_msg void OnIdok();
	afx_msg void OnIdcancel();
	CString m_sLogin;
	CString m_sPassword;
	afx_msg void OnLogin();
	afx_msg void OnRegister();
};
