#pragma once
/*
Файл               : Dialog.hpp

Проект             : демонстрация созания Windows-приложения на
основе библиотеки классов MFC (ресурс -
модальный диалог с радиокнопками)

Назначение         : объявление класса "Dialog", производного
от класса "CDialod" библиотеки классов
MFC (обработка сообщений окна диалога)

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

	// Указатель на радиокнопку задания стиля "Сплошной"
	CButton         *pRadioSolid;
	// Указатель на радиокнопку задания стиля "Штриховой"
	CButton         *pRadioDash;
	// Указатель на радиокнопку задания стиля "Точечный"
	CButton         *pRadioDot;

public:

	int             m_PenStyle; // Стиль карандаша

public:

	// Конструктор - передает идентификатор диалога в базовый
	//   класс
	Dialog(CWnd *pParent = 0);

protected:

	// Перегружаем виртуальный метод для инициализации диалога
	virtual BOOL OnInitDialog(void);
	// Перегружаем виртуальный метод для закрытия диалога по
	//   кнопке ОК
	virtual void OnOK(void);

	// Обработчики радиокнопок (в данном случае они избыточны)
	/*afx_msg void OnRadioSolidClick( void );
	afx_msg void OnRadioDashClick( void );
	afx_msg void OnRadioDotClick( void );*/

	// Объявление таблицы сообщений
	DECLARE_MESSAGE_MAP();
};

#endif

