/*
Файл               : FrameWnd.cpp

Проект             : демонстрация Windows-приложения на основе
библиотеки классов MFC с окном модального
диалога, использующим CheckBox

Назначение         : реализация класса "FrameWnd",
производного от класса "CFrameWnd"
библиотеки классов MFC (обработка сообщений
главного окна)

Microsoft Visual Studio C++ .NET 2005
*/

#include "StdAfx.h"                 // Прекомпилируемый файл
#include "FrameWnd.h"             // Объявление класса FrameWnd
#include "Dialog.h"               // Объявление класса Dialog
// Идентификаторы ресурсов (поддержка редактором ресурсов)
#include "resource.h"

// Определение таблицы сообщений
BEGIN_MESSAGE_MAP(FrameWnd, CFrameWnd)
	ON_COMMAND(ID_FILE_EXIT, OnMenuFileExit)
	ON_COMMAND(ID_CHECKBOX_3STATE, OnMenuCheckbox3State)
END_MESSAGE_MAP()

// Конструктор умолчания (инициализация CheckBox)
FrameWnd::FrameWnd(void)
{
	m_BoolFirst = false;
	m_Second = 2;
}

// Обработка команды Файл | Выход
afx_msg void FrameWnd::OnMenuFileExit(void)
{
	BOOL                rc = MessageBeep(-1);
	if (!rc)
	{
		TRACE0("\n Ошибка 2. Неверное завершение MessageBeep \n");
		exit(2);
	}
	rc = DestroyWindow();
	if (!rc)
	{
		TRACE0("\n Ошибка 3. Окно не было разрушено \n");
		exit(3);
	}

	return afx_msg void();
}

// Обработка команды Отмечаемые кнопки | Диалог
afx_msg void FrameWnd::OnMenuCheckbox3State(void)
{
	// Создаем объект диалога - автоматически вызывается
	//   конструктор
	Dialog              Dlg(this);

	// Передаем состояния CheckBox из класса FrameWnd в класс
	//   Dialog
	Dlg.m_bStdChk1 = m_BoolFirst;
	Dlg.m_3StChk2 = m_Second;

	// Создается модальное диалоговое окно - оно будет
	//   автоматически закрыто после нажатия OK или Cancel
	int                 DlgResult = static_cast<int>
		(Dlg.DoModal());
	if (DlgResult == IDOK)
	{                               // Выход из диалога по ОК
									// Передаем состояния CheckBox из класса Dialog в класс
									//   FrameWnd
		m_BoolFirst = Dlg.m_bStdChk1;
		m_Second = Dlg.m_3StChk2;
	}

	return afx_msg void();
}

