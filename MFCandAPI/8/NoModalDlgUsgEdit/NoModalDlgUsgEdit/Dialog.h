/*
Файл               : Dialog.hpp

Проект             : демонстрация создания Windows-приложения на
основе библиотеки классов MFC (ресурсы -
обычный диалог + однострочный редактор)

Назначение         : объявление класса "Dialog", производного
от класса "CDialog" библиотеки классов
MFC (обработка сообщений окна диалога)

Microsoft Visual Studio C++ .NET 2005
*/

// Предотвращение возможности многократного подключения данного
//   файла
#ifndef _Dialog_h
#define _Dialog_h

// Идентификаторы ресурсов
#include "resource.h"           

class Dialog : public CDialog
{
	// Данные

private:

	// Указатель однострочного элемента редактирования
	CEdit           *pEdit;

public:

	// Для текста элемента редактирования
	CString         e1;

	// Методы

public:

	BOOL Create(void);

private:

	// Инициализация окна диалога (перегрузка виртуального
	//   метода)
	virtual BOOL OnInitDialog(void);
	// Получение информации из окна диалога (перегрузка
	//   виртуального метода)
	virtual void OnOK(void);
	// Получение данных из окна диалога (метод вызывается
	//   автоматически из метода UpdateData( ))
	void DoDataExchange(CDataExchange* pDX);

};

#endif
