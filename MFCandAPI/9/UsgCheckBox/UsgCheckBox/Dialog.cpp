/*
Файл               : Dialog.сpp

Проект             : демонстрация Windows-приложения на основе
библиотеки классов MFC с окном модального
диалога, использующим CheckBox

Назначение         : реализация класса "Dialog", производного
от класса "CDialod" библиотеки классов
MFC (обработка сообщений окна диалога)

Microsoft Visual Studio C++ .NET 2005
*/


#include "StdAfx.h"                 // Прекомпилируемый файл
#include "Dialog.h"               // Объявление класса Dialog
// Идентификаторы ресурсов (поддержка редактором ресурсов)
#include "resource.h"

// Определение таблицы сообщений
BEGIN_MESSAGE_MAP(Dialog, CDialog)
	ON_BN_CLICKED(IDC_STDCHK1, OnBtn1Click)
	ON_BN_CLICKED(IDC_3STCHK2, OnBtn2Click)
END_MESSAGE_MAP()

// Конструктор
Dialog::Dialog(
	CWnd                *pParent)  // Указатель на родительское
								   //   окно (NULL - родительским
								   //   является главное окно)
	: CDialog(IDD_DIALOG_3STATE, pParent)
{ }

// Инициализация окна диалога
BOOL Dialog::OnInitDialog(void)
{
	// Вызываем метод базового класса
	CDialog::OnInitDialog();

	// Получаем указатели на CheckBox
	m_pStdChk1 = static_cast< CButton * >(GetDlgItem(IDC_STDCHK1));
	m_p3StChk2 = static_cast< CButton * >(GetDlgItem(IDC_3STCHK2));

	// Устанавливаем состояние обычного CheckBox
	if (m_bStdChk1)
	{
		m_pStdChk1->SetCheck(1);
	}

	// Устанавливаем состояние необычного CheckBox
	switch (m_3StChk2)
	{
	case 1:
		m_p3StChk2->SetCheck(1);
		break;

	case 2:
		m_p3StChk2->SetCheck(2);
		break;
	}

	return TRUE;
}

// Обработчики CheckBox
// Обработчик обычного CheckBox
void Dialog::OnBtn1Click(void)
{
	if (m_pStdChk1->GetCheck())
	{
		m_bStdChk1 = true;
	}
	else
	{
		m_bStdChk1 = false;
	}

	return;
}

// Обработчик CheckBox с тремя состояниями
void Dialog::OnBtn2Click(void)
{
	m_3StChk2 = m_p3StChk2->GetCheck();

	return;
}
