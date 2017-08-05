#pragma once
#ifndef _Dialog_h
#define _Dialog_h

// Объявление класса
class Dialog : public CDialog
{
	// Данные

private:

	// Указатели элементов редактирования красного, зеленого и
	//   синего цветов
	CEdit           *pEditRed;
	CEdit           *pEditGreen;
	CEdit           *pEditBlue;

	// Указатели вращателей для красного, зеленого и синего
	//   цветов
	CSpinButtonCtrl *pSpinRed;
	CSpinButtonCtrl *pSpinGreen;
	CSpinButtonCtrl *pSpinBlue;

	// true - инициализация окна диалога была успешной
	bool            m_InitIsDone;

public:

	COLORREF        m_OldRGB;   // Старый RGB-цвет
	COLORREF        m_NewRGB;   // Новый RGB-цвет

								// Методы

public:

	// Конструктор - передает идентификатор диалога в базовый
	//   класс
	Dialog(CWnd *pParent = 0);

protected:

	// Перегружаем виртуальный метод для инициализации диалога
	virtual BOOL OnInitDialog(void);

	// Перегружаем виртуальный метод для получения информации
	//   из диалога
	virtual void OnOK(void);

	// Обработчик сообщений вращателей
	afx_msg void OnEditColor(void);

	DECLARE_MESSAGE_MAP();
};

#endif