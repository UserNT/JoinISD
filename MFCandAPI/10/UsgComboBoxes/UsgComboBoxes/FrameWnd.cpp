/*
Файл               : FrameWnd.cpp

Проект             : демонстрация Windows-приложения на основе
библиотеки классов MFC с окном модального
диалога, использующим различные
комбинированные списки

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
	ON_COMMAND(ID_COMBOBOX_DIALOG, OnMenuComboBoxDialog)
END_MESSAGE_MAP()

// Конструктор умолчания (инициализация комбинированных списков)
FrameWnd::FrameWnd(void)
{
	// Простой комбинированный список
	m_List1[0] = "Alpha";
	m_List1[1] = "Beta";
	m_List1[2] = "Gamma";
	m_List1[3] = "Delta";
	m_List1[4] = "Omega";
	m_IxLast1 = 4;

	// Раскрывающийся комбинированный список
	m_List2[0] = "First";
	m_List2[1] = "Second";
	m_List2[2] = "Third";
	m_List2[3] = "Fourth";
	m_IxLast2 = 3;

	// Раскрывающийся список
	m_List3[0] = "Not use MFC";
	m_List3[1] = "Use MFC in a Static Library";
	m_List3[2] = "Use MFC in a Shared DLL";
	m_IxLast3 = 2;
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

// Обработка команды КомбСписок | Диалог
afx_msg void FrameWnd::OnMenuComboBoxDialog(void)
{
	// Создаем объект диалога - автоматически вызывается
	//   конструктор
	Dialog              Dlg(this);

	// Передаем информацию для комбинированных списков из класса
	//   FrameWnd в класс Dialog
	Dlg.m_List1 = m_List1;
	Dlg.m_IxLast1 = m_IxLast1;
	Dlg.m_List2 = m_List2;
	Dlg.m_IxLast2 = m_IxLast2;
	Dlg.m_List3 = m_List3;
	Dlg.m_IxLast3 = m_IxLast3;

	// Создается модальное диалоговое окно - оно будет
	//   автоматически закрыто после нажатия OK или Cancel
	int                 DlgResult = static_cast<int>
		(Dlg.DoModal());
	if (DlgResult == IDOK)
	{                               // Выход из диалога по ОК
									// Передаем выбранные элементы комбинированных списков из
									//   класса Dialog в класс FrameWnd
		m_Str1 = Dlg.m_Str1;
		m_Str2 = Dlg.m_Str2;
		m_Str3 = Dlg.m_Str3;
		// Визуализируем выбранные элементы
		MessageBox(m_Str1 + "\n" + m_Str2 + "\n" + m_Str3,
			_T("Выбраны элементы"),
			MB_OK | MB_ICONINFORMATION);
	}

	return afx_msg void();
}
