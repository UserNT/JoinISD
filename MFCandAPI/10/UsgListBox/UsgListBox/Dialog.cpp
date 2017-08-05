/*
Файл               : Dialog.сpp

Проект             : демонстрация Windows-приложения на основе
библиотеки классов MFC с окном модального
диалога, использующим списки

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
	ON_BN_CLICKED(IDC_BUTTON_LR, OnButtonLRClick)
	ON_BN_CLICKED(IDC_BUTTON_RL, OnButtonRLClick)
END_MESSAGE_MAP()

// Конструктор
Dialog::Dialog(
	CWnd                *pParent)  // Указатель на родительское
								   //   окно (NULL - родительским
								   //   является главное окно)
	: CDialog(IDD_DIALOG_LISTBOXES, pParent)
{ }

// Инициализация окна диалога
BOOL Dialog::OnInitDialog(void)
{
	// Вызываем метод базового класса
	CDialog::OnInitDialog();

	// Получаем указатели на списки
	m_plbMulti = static_cast< CListBox * >
		(GetDlgItem(IDC_LIST_MULTI));
	m_plbSingle = static_cast< CListBox * >
		(GetDlgItem(IDC_LIST_SINGLE));

	int                 IxStr;      // Индекс элемента списка
									// Заносим элементы в левый список
	for (IxStr = 0; IxStr <= m_IxEnbLast; IxStr++)
	{
		m_plbMulti->AddString(m_Enabled[IxStr]);
	}

	// Заносим элементы в правый список
	for (IxStr = 0; IxStr <= m_IxDisLast; IxStr++)
	{
		m_plbSingle->AddString(m_Disabled[IxStr]);
	}

	return TRUE;
}

// Получение информации из окна диалога (обработчик кнопки OK)
void Dialog::OnOK(void)
{
	// Вызываем метод базового класса
	CDialog::OnOK();

	// Индекс элемента списка
	int                 IxStr;

	// Получаем индекс последнего элемента левого списка
	m_IxEnbLast = m_plbMulti->GetCount() - 1;
	// Извлекаем информацию из левого списка
	for (IxStr = 0; IxStr <= m_IxEnbLast; IxStr++)
	{
		m_plbMulti->GetText(IxStr, m_Enabled[IxStr]);
	}

	// Получаем индекс последнего элемента правого списка
	m_IxDisLast = m_plbSingle->GetCount() - 1;
	// Извлекаем информацию из правого списка
	for (IxStr = 0; IxStr <= m_IxDisLast; IxStr++)
	{
		m_plbSingle->GetText(IxStr, m_Disabled[IxStr]);
	}

	return;
}

// Обработчик кнопки "Move>>" переноса информации из левого списка
//   в правый
void Dialog::OnButtonLRClick(void)
{
	// Для индексов выделенных строк левого списка
	int                 Selected[10];
	// Индекс последней заполненной строки в Selected
	int                 IxSelLast;
	// Индекс текущей выделенной строки левого списка
	int                 IxSel;
	// Копия перемещаемой строки
	CString             Copy;
	// Индекс обрабатываемой строки
	int                 IxStr;

	// Получаем уменьшенное на 1 число выделенных строк левого
	//   списка
	IxSelLast = m_plbMulti->GetSelCount() - 1;
	if (IxSelLast < 0)              // Выделенных строк нет
		return;

	// Заносим индексы выделенных строк левого списка в Selected
	m_plbMulti->GetSelItems(10, Selected);
	// Переносим выделенные строки в правый список
	for (IxSel = IxSelLast; IxSel >= 0; IxSel--)
	{
		IxStr = Selected[IxSel];
		m_plbMulti->GetText(IxStr, Copy);
		m_plbMulti->DeleteString(IxStr);
		m_plbSingle->AddString(Copy);
	}

	return;
}

// Обработчик кнопки "Move<<" переноса информации из правого списка
//   в левый
void Dialog::OnButtonRLClick(void)
{
	// Копия перемещаемой строки
	CString             Copy;
	// Индекс обрабатываемой строки
	int                 IxStr;

	// Получаем индекс выделенной строки правого списка
	IxStr = m_plbSingle->GetCurSel();
	if (IxStr == LB_ERR)          // Выделенной строки нет
		return;

	// Переносим выделенную строку из правого списка в левый
	m_plbSingle->GetText(IxStr, Copy);
	m_plbSingle->DeleteString(IxStr);
	m_plbMulti->AddString(Copy);

	return;
}