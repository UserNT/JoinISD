
// DocViewTest.h : ������� ���� ��������� ��� ���������� DocViewTest
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// CTestApp:
// � ���������� ������� ������ ��. DocViewTest.cpp
//

class CTestApp : public CWinApp
{
public:
	CTestApp();


// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����������
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTestApp theApp;
