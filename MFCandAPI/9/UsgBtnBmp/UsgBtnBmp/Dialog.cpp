/*
Файл               : Dialog.cpp

Проект             : приложение на основе библиотеки классов MFC
(ресурсы - Bitmap, Dialog, Menu и String
Table)

Назначение         : реализация класса "BitmapDialog",
производного от класса "CDialog" библиотеки
классов MFC (обработка сообщений окна
диалога)

Microsoft Visual Studio C++ .NET 2005
*/

#include "StdAfx.h"                 // Прекомпилируемый файл
#include "Dialog.h"               // Объявление класса Dialog
// Идентификаторы ресурсов (поддержка редактором ресурсов)
#include "resource.h"

// Определение таблицы сообщений
BEGIN_MESSAGE_MAP(Dialog, CDialog)
	ON_BN_CLICKED(IDC_BITBTN1, OnBmpBtn1Click)
	ON_BN_CLICKED(IDC_BITBTN2, OnBmpBtn2Click)
END_MESSAGE_MAP()

// Конструктор
Dialog::Dialog(
	CWnd                *pParent)  // Указатель на родительское
								   //   окно (NULL - родительским
								   //   является главное окно)
	: CDialog(IDD_DIALOG_BITMAP, pParent)
{ }

// Инициализация окна диалога
BOOL Dialog::OnInitDialog(void)
{
	// Вызов метода базового класса
	CDialog::OnInitDialog();

	// Связывание кнопок с изображениями
	if (!BmpBtn1.AutoLoad(IDC_BITBTN1, this))
	{
		TRACE0("\n Ошибка 4 использования AutoLoad \n");
		exit(4);
	}
	if (!BmpBtn2.AutoLoad(IDC_BITBTN2, this))
	{
		TRACE0("\n Ошибка 5 использования AutoLoad \n");
		exit(5);
	}

	return TRUE;
}

// Обработка кнопки, вызывающей Paint
afx_msg void Dialog::OnBmpBtn1Click(void)
{
	// Запуск постороннего процесса: первый аргумент - командная
	//   строка, второй - в каком виде отображать окно процесса
	WinExec("mspaint bmp.bmp", SW_SHOWNORMAL);

	return afx_msg void();
}

// Обработка кнопки, вызывающей NotePad
afx_msg void Dialog::OnBmpBtn2Click(void)
{
	// Запуск постороннего процесса: первый аргумент - командная
	//   строка, второй - в каком виде отображать окно процесса
	WinExec("notepad readme", SW_SHOWNORMAL);

	return afx_msg void();
}