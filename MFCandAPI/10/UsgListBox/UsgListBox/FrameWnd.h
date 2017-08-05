/*
Файл               : FrameWnd.hpp

Проект             : демонстрация Windows-приложения на основе
библиотеки классов MFC с окном модального
диалога, использующим списки

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

	// Переменные, связанные со списками

	// Левый список
	// Строки для списка
	CString         m_Enabled[10];
	// Индекс последнего элемента в "m_Enabled"
	int             m_IxEnbLast;

	// Правый список
	// Строки для списка
	CString         m_Disabled[10];
	// Индекс последнего элемента в "m_Disabled"
	int             m_IxDisLast;

	// Методы

public:

	// Конструктор умолчания (инициализация списков)
	FrameWnd(void);

protected:

	// Прототипы функций, обрабатывающих сообщения
	// Обработка команды Файл | Выход
	afx_msg void OnMenuFileExit(void);
	// Обработка команды Списки | Диалог
	afx_msg void OnMenuListBoxDialog(void);

	// Объявление таблицы сообщений
	DECLARE_MESSAGE_MAP();
};

#endif
