
// ListCtrlDemo.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CStudentsApp:
// � ���������� ������� ������ ��. ListCtrlDemo.cpp
//

class CStudentsApp : public CWinApp
{
public:
	CStudentsApp();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CStudentsApp theApp;