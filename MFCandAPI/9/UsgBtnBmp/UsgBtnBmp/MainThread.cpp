#include "StdAfx.h"                 // Прекомпилируемый файл
#include "MainThread.h"           // Объявление класса MainThread
#include "FrameWnd.h"             // Объявление класса FrameWnd
// Идентификаторы ресурсов (поддержка редактором ресурсов)
#include "resource.h"

// Переопределение виртуальной функции для инициализации приложения
//   перед запуском
BOOL MainThread::InitInstance(void)
{
	// Указатель на фрейм окна
	FrameWnd            *pFrame;

	// Размещение фрейма окна в динамической памяти
	pFrame = new FrameWnd;
	ASSERT_VALID(pFrame);         // Обработка ошибки размещения

								  // Загрузка ресурсов, регистрация класса окна и создание окна
	BOOL                rc = pFrame->LoadFrame(IDR_MAINFRAME);
	if (!rc)
	{
		TRACE0("\n Ошибка 1. Метод LoadFrame завершен с "
			"ошибкой \n");
		exit(1);
	}

	// Отображение окна
	pFrame->ShowWindow(SW_SHOW);
	// Обновление окна (генерирует WM_PAINT)
	pFrame->UpdateWindow();

	// Созданный фрейм делаем главным окном приложения
	this->m_pMainWnd = pFrame;

	return TRUE;
}