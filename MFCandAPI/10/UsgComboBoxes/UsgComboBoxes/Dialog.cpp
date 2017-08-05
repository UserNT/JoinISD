/*
Файл               : Dialog.сpp

Проект             : демонстрация Windows-приложения на основе
библиотеки классов MFC с окном модального
диалога, использующим различные
комбинированные списки

Назначение         : реализация класса "Dialog", производного
от класса "CDialod" библиотеки классов
MFC (обработка сообщений окна диалога)

Microsoft Visual Studio C++ .NET 2005
*/


#include "StdAfx.h"                 // Прекомпилируемый файл
#include "Dialog.h"               // Объявление класса Dialog
// Идентификаторы ресурсов (поддержка редактором ресурсов)
#include "resource.h"

// Конструктор
Dialog::Dialog(
	CWnd                *pParent)  // Указатель на родительское
								   //   окно (NULL - родительским
								   //   является главное окно)
	: CDialog(IDD_DIALOG_COMBOBOXES, pParent)
{ }

// Инициализация окна диалога
BOOL Dialog::OnInitDialog(void)
{
	// Вызываем метод базового класса
	CDialog::OnInitDialog();

	// Получаем указатели на комбинированные списки
	m_pCombo1 = static_cast< CComboBox * >
		(GetDlgItem(IDC_COMBO3));
	m_pCombo2 = static_cast< CComboBox * >
		(GetDlgItem(IDC_COMBO2));
	m_pCombo3 = static_cast< CComboBox * >
		(GetDlgItem(IDC_COMBO1));

	int                 IxStr;      // Индекс элемента списка
									// Заносим элементы в простой комбинированный список и
									//   выбираем строку в окне редактирования
	for (IxStr = 0; IxStr <= m_IxLast1; IxStr++)
	{
		m_pCombo1->AddString(m_List1[IxStr]);
	}
	m_pCombo1->SetCurSel(0);

	// Заносим элементы в раскрывающийся комбинированный список и
	//   выбираем строку в окне редактирования
	for (IxStr = 0; IxStr <= m_IxLast2; IxStr++)
	{
		m_pCombo2->AddString(m_List2[IxStr]);
	}
	m_pCombo2->SetCurSel(0);

	// Заносим элементы в раскрывающийся список и выбираем строку
	//   в окне редактирования
	for (IxStr = 0; IxStr <= m_IxLast3; IxStr++)
	{
		m_pCombo3->AddString(m_List3[IxStr]);
	}
	m_pCombo3->SetCurSel(0);

	return TRUE;
}

// Получение информации из окна диалога (обработчик кнопки OK)
void Dialog::OnOK(void)
{
	// Вызываем метод базового класса
	CDialog::OnOK();

	m_pCombo1->GetWindowText(m_Str1);
	m_pCombo2->GetWindowText(m_Str2);
	m_pCombo3->GetWindowText(m_Str3);

	return;
}