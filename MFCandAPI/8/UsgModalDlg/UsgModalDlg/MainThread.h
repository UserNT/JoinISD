#pragma once
/*
Файл               : MainThread.hpp

Проект             : любой проект на основе библиотеки классов
MFC

Назначение         : объявление класса "MainThread",
производного от класса "CWinApp" библиотеки
классов MFC (инициализация приложения перед
запуском)

Microsoft Visual Studio C++ .NET 2005
*/

// Предотвращение возможности многократного подключения данного
//   файла
#ifndef _MainThread_h
#define _MainThread_h

// Объявление класса
class MainThread : public CWinApp
{
	// Методы

public:

	// Инициализация приложения перед запуском
	virtual BOOL InitInstance(void);
};

#endif

