
// ListCtrlDemo.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CStudentsApp:
// О реализации данного класса см. ListCtrlDemo.cpp
//

class CStudentsApp : public CWinApp
{
public:
	CStudentsApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CStudentsApp theApp;