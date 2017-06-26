#include "StdAfx.h"                 // Прекомпилируемый файл
#include "MainThread.h"           // Объявление класса MainThread
#include "FrameWnd.h"


BOOL MainThread::InitInstance()
{
	// Указатель на фрейм окна
	FrameWnd            *pFrame;

	// Размещение фрейма окна в динамической памяти с обработкой
	//   ошибки
	pFrame = new FrameWnd;
	ASSERT_VALID(pFrame);

	// Создание окна приложения
	BOOL                rc = pFrame->Create(
		// Используется предопределенное OS WINDOWS имя оконного
		//   класса
		NULL,
		// Заголовок фрейма окна
		"Демонстрация MFC-кнопок и дочерних окон",
		// Стиль окна
		WS_SIZEBOX | WS_POPUPWINDOW | WS_DLGFRAME,
		// Местоположение и размеры окна: 0 - левая сторона,
		//   0 - верх, 530 - правая сторона, 290 - низ окна
		CRect(0, 0, 530, 290));
	if (!rc)
	{
		TRACE0("\n Ошибка 1. Фрейм окна не был создан \n");
		exit(1);
	}

	// Создание кнопок
	pFrame->CreateChildControls();
	// Отображение окна
	pFrame->ShowWindow(SW_SHOW);

	// Созданный фрейм делаем главным окном приложения
	this->m_pMainWnd = pFrame;

	return TRUE;
}
