/*
Файл               : FrameWnd.cpp

Проект             : демонстрация Windows-приложения на основе
библиотеки классов MFC с окном модального
диалога, использующим списки

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
	ON_COMMAND(ID_LISTBOXES_DIALOG, OnMenuListBoxDialog)
END_MESSAGE_MAP()

// Конструктор умолчания (инициализация списков)
FrameWnd::FrameWnd(void)
{
	// Левый список
	m_IxEnbLast = 4;
	m_Enabled[0] = "Alpha";
	m_Enabled[1] = "Beta";
	m_Enabled[2] = "Gamma";
	m_Enabled[3] = "Delta";
	m_Enabled[4] = "Omega";

	// Правый список (пустой)
	m_IxDisLast = -1;
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

// Обработка команды Списки | Диалог
afx_msg void FrameWnd::OnMenuListBoxDialog(void)
{
	// Создаем объект диалога - автоматически вызывается
	//   конструктор
	Dialog              Dlg(this);

	// Передаем информацию для списков из класса FrameWnd в класс
	//   Dialog
	Dlg.m_Enabled = m_Enabled;
	Dlg.m_IxEnbLast = m_IxEnbLast;
	Dlg.m_Disabled = m_Disabled;
	Dlg.m_IxDisLast = m_IxDisLast;

	// Создается модальное диалоговое окно - оно будет
	//   автоматически закрыто после нажатия OK или Cancel
	int                 DlgResult = static_cast<int>
		(Dlg.DoModal());
	if (DlgResult == IDOK)
	{                               // Выход из диалога по ОК
									// Передаем индексы последних элементов списков из класса
									//   Dialog в класс FrameWnd
		m_IxEnbLast = Dlg.m_IxEnbLast;
		m_IxDisLast = Dlg.m_IxDisLast;
	}

	return afx_msg void();
}
