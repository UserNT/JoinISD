
// TreeCtrlDemo.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CDemoApp:
// О реализации данного класса см. TreeCtrlDemo.cpp
//

class CDemoApp : public CWinApp
{
public:
	CDemoApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CDemoApp theApp;