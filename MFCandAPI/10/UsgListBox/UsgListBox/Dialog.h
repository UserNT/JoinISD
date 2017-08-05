#pragma once
/*
Файл               : Dialog.hpp

Проект             : демонстрация Windows-приложения на основе
библиотеки классов MFC с окном модального
диалога, использующим списки

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

	// Указатель на левый список (MULTI) 
	CListBox        *m_plbMulti;
	// Указатель на правый список (SINGLE) 
	CListBox        *m_plbSingle;

public:

	// Переменные, связанные со списками

	// Левый список
	// Указатель на массив строк
	CString         *m_Enabled;
	// Индекс последней строки
	int             m_IxEnbLast;

	// Правый список
	// Указатель на массив строк
	CString         *m_Disabled;
	// Индекс последней строки
	int             m_IxDisLast;

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

	// Обработчик кнопки переноса данных из левого списка в
	//   правый
	afx_msg void OnButtonLRClick(void);
	// Обработчик кнопки переноса данных из правого списка в
	//   левый
	afx_msg void OnButtonRLClick(void);

	DECLARE_MESSAGE_MAP();
};

#endif
