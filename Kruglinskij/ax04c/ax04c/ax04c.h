
// ax04c.h : ������� ���� ��������� ��� ���������� ax04c
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// Cax04cApp:
// � ���������� ������� ������ ��. ax04c.cpp
//

class Cax04cApp : public CWinAppEx
{
public:
	Cax04cApp();


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

extern Cax04cApp theApp;
