
// ex03a.h : ������� ���� ��������� ��� ���������� ex03a
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// Cex03aApp:
// � ���������� ������� ������ ��. ex03a.cpp
//

class Cex03aApp : public CWinAppEx
{
public:
	Cex03aApp();


// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����������
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cex03aApp theApp;
