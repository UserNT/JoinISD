#pragma once
#ifndef _FrameWnd_h
#define _FrameWnd_h

// Объявление класса
class FrameWnd : public CFrameWnd
{
	// Данные

private:

	// Для текста однострочного редактора
	CString            e1;

	// Методы

public:

	// Конструктор умолчания (инициализация текста
	//   однострочного редактора)
	FrameWnd(void);

protected:

	// Прототипы функций, обрабатывающих сообщения
	// Обработка команды "Выход"
	afx_msg void OnMenuExit(void);
	// Обработка команды "Немодальный_диалог"
	afx_msg void OnMenuDialog(void);

	// Объявление таблицы сообщений
	DECLARE_MESSAGE_MAP();
};

#endif