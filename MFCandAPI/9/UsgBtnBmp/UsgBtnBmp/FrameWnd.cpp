/*
Файл               : FrameWnd.cpp

Проект             : приложение на основе библиотеки классов MFC
(ресурсы - Bitmap, Dialog, Menu и String
Table)

Назначение         : реализация класса "FrameWnd", производного
от класса "CFrameWnd" библиотеки классов
MFC (обработка сообщений главного окна)

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
	ON_COMMAND(ID_BITMAP_BUTTONS, OnMenuBitmapButtons)
END_MESSAGE_MAP()

// Обработка команды Файл | Выход
afx_msg void FrameWnd::OnMenuFileExit(void)
{
	BOOL                rc = DestroyWindow();
	if (!rc)
	{
		TRACE0("\n Ошибка 2. Окно не было разрушено \n");
		exit(2);
	}

	return afx_msg void();
}

// Обработка команды Растровые кнопки | Диалог
afx_msg void FrameWnd::OnMenuBitmapButtons(void)
{
	// Создаем объект диалога - автоматически вызывается
	//   обычный конструктор
	Dialog              Dlg(this);

	// Создается модальное диалоговое окно - оно будет
	//   автоматически закрыто после нажатия OK или Cancel
	Dlg.DoModal();

	return afx_msg void();
}
