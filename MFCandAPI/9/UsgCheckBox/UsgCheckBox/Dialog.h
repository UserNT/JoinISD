#pragma once
/*
Файл               : Dialog.hpp

Проект             : демонстрация Windows-приложения на основе
библиотеки классов MFC с окном модального
диалога, использующим CheckBox

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

	// Указатель на CheckBox с двумя состояниями
	CButton         *m_pStdChk1;
	// Указатель на CheckBox с тремя состояниями
	CButton         *m_p3StChk2;

public:

	// Состояние стандартного CheckBox
	bool            m_bStdChk1;
	// Состояние нестандартного CheckBox
	int             m_3StChk2;

	// Методы

public:

	// Конструктор - передает идентификатор диалога в базовый
	//   класс
	Dialog(CWnd *pParent = 0);

protected:

	// Перегружаем виртуальный метод для инициализации диалога
	virtual BOOL OnInitDialog(void);

	// Обработчики CheckBox
	afx_msg void OnBtn1Click(void);
	afx_msg void OnBtn2Click(void);

	// Объявление таблицы сообщений
	DECLARE_MESSAGE_MAP();
};

#endif


