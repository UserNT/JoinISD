#pragma once
/*
Файл               : Dialog.hpp

Проект             : демонстрация Windows-приложения на основе
библиотеки классов MFC с окном модального
диалога, использующим полосы прокрутки

Назначение         : объявление класса "Dialog", производного
от класса "CDialod" библиотеки классов
MFC (обработка окна диалога)

Microsoft Visual Studio C++ .NET 2005
*/

// Предотвращение возможности многократного подключения данного
//   файла
#ifndef _Dialog_h
#define _Dialog_h

// Объявление класса
class Dialog : public CDialog
{
	// Данные

private:

	// Указатели ползунков красного, зеленого и синего цветов
	CScrollBar      *pScrollBarRed;
	CScrollBar      *pScrollBarGreen;
	CScrollBar      *pScrollBarBlue;

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

	// Обработчик сообщений от горизонтальной полосы прокрутки
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos,
		CScrollBar *pScrollBar);

	// Объявление таблицы сообщений
	DECLARE_MESSAGE_MAP();
};

#endif
