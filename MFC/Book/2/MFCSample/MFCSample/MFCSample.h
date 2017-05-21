
// MFCSample.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CMFCSampleApp:
// О реализации данного класса см. MFCSample.cpp
//

class CMFCSampleApp : public CWinApp
{
public:
	CMFCSampleApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CMFCSampleApp theApp;