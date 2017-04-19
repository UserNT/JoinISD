
// DlgDemo2.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CMyApp:
// О реализации данного класса см. DlgDemo2.cpp
//

class CMyApp : public CWinApp
{
public:
	CMyApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CMyApp theApp;