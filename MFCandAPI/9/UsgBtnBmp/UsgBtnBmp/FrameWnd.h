#pragma once
#ifndef _FrameWnd_h
#define _FrameWnd_h
// Объявление класса
class FrameWnd : public CFrameWnd
{
	// Методы

protected:

	// Прототипы функций, обрабатывающих сообщения
	// Обработка команды Файл | Выход
	afx_msg void OnMenuFileExit(void);
	// Обработка команды Растровые кнопки | Диалог
	afx_msg void OnMenuBitmapButtons(void);

	// Объявление таблицы сообщений
	DECLARE_MESSAGE_MAP();

};

#endif