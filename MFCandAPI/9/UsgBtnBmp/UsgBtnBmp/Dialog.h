#pragma once

#ifndef _Dialog_h
#define _Dialog_h

// Объявление класса
class Dialog : public CDialog
{
	// Данные

private:

	// Создание рисованных кнопок - вызывается конструктор
	//   умолчания
	CBitmapButton   BmpBtn1;    // Кнопка 1
	CBitmapButton   BmpBtn2;    // Кнопка 2

								// Методы

public:

	// Конструктор - передает идентификатор диалога в базовый
	//   класс
	Dialog(CWnd *  pParent = 0);

protected:

	// Перегружаем виртуальный метод для инициализации диалога
	virtual BOOL OnInitDialog(void);

	// Обработчики рисованных кнопок
	afx_msg void OnBmpBtn1Click(void);
	afx_msg void OnBmpBtn2Click(void);

	// Объявление таблицы сообщений
	DECLARE_MESSAGE_MAP();
};

#endif
