
// TreeCtrlDemo.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CDemoApp:
// � ���������� ������� ������ ��. TreeCtrlDemo.cpp
//

class CDemoApp : public CWinApp
{
public:
	CDemoApp();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CDemoApp theApp;