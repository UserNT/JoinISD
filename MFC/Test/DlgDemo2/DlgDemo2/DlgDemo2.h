
// DlgDemo2.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CMyApp:
// � ���������� ������� ������ ��. DlgDemo2.cpp
//

class CMyApp : public CWinApp
{
public:
	CMyApp();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CMyApp theApp;