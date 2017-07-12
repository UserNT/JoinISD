/*
Файл               : FrameWnd.cpp

Проект             : демонстрация создания Windows-приложения на
основе библиотеки классов MFC (ресурсы -
обычный диалог + однострочный редактор)

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
	ON_COMMAND(ID_EXIT, OnMenuExit)
	ON_COMMAND(ID_DIALOG_EDIT, OnMenuDialog)
END_MESSAGE_MAP()

// Конструктор умолчания (инициализация окна редактирования)
FrameWnd::FrameWnd(void)
{
	// Для текста однострочного редактора
	e1 = "Заставка";
}

// Обработка команды "Выход"
afx_msg void FrameWnd::OnMenuExit(void)
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

// Обработка команды "Немодальный_диалог"
afx_msg void FrameWnd::OnMenuDialog(void)
{
	// Размещаем объект окна немодального диалога в динамической
	//   памяти
	Dialog              *pDlg = new Dialog;
	ASSERT_VALID(pDlg);           // Обработка ошибки размещения

								  // Передаем текст для элемента редактирования
	pDlg->e1 = e1;

	// Создаем немодальное окно диалога
	if (!pDlg->Create())
	{
		TRACE0("\n Ошибка 4 - немодальное окно диалога "
			"не создано \n");
		exit(4);
	}

	// Перерисовка окна (формирует сообщение WM_PAINT)
	CWnd::Invalidate();

	return afx_msg void();
}
