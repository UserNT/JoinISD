
// DocViewTest.h : главный файл заголовка для приложения DocViewTest
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CTestApp:
// О реализации данного класса см. DocViewTest.cpp
//

class CTestApp : public CWinApp
{
public:
	CTestApp();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTestApp theApp;
