#pragma once
/*
Файл               : FrameWnd.hpp

Проект             : демонстрация Windows-приложения на основе
библиотеки классов MFC с окном модального
диалога, использующим CheckBox

Назначение         : объявление класса "FrameWnd",
производного от класса "CFrameWnd"
библиотеки классов MFC (обработка сообщений
главного окна)

Microsoft Visual Studio C++ .NET 2005
*/

// Предотвращение возможности многократного подключения данного
//   файла
#ifndef _FrameWnd_h
#define _FrameWnd_h

// Объявление класса
class FrameWnd : public CFrameWnd
{
	// Данные

private:

	// Переменные, связанные с CheckBox
	bool            m_BoolFirst;// Два состояния
	int             m_Second;   // Три состояния 

								// Методы

public:

	// Конструктор умолчания (инициализация CheckBox)
	FrameWnd(void);

protected:

	// Прототипы функций, обрабатывающих сообщения
	// Обработка команды Файл | Выход
	afx_msg void OnMenuFileExit(void);
	// Обработка команды Отмечаемые кнопки | Диалог
	afx_msg void OnMenuCheckbox3State(void);

	// Объявление таблицы сообщений
	DECLARE_MESSAGE_MAP();
};

#endif

