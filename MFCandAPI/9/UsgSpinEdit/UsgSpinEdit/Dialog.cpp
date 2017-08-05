/*
Файл               : Dialog.сpp

Проект             : демонстрация Windows-приложения на основе
библиотеки классов MFC с окном модального
диалога, использующим вращатели и окна
редактирования

Назначение         : реализация класса "Dialog", производного
от класса "CDialod" библиотеки классов
MFC (обработка сообщений окна диалога)

Microsoft Visual Studio C++ .NET 2005
*/


#include "StdAfx.h"                 // Прекомпилируемый файл
#include "FrameWnd.h"             // Объявление класса FrameWnd
#include "Dialog.h"               // Объявление класса Dialog
// Идентификаторы ресурсов (поддержка редактором ресурсов)
#include "resource.h"

// Определение таблицы сообщений
BEGIN_MESSAGE_MAP(Dialog, CDialog)
	ON_EN_UPDATE(IDC_EDIT_RED, OnEditColor)
	ON_EN_UPDATE(IDC_EDIT_GREEN, OnEditColor)
	ON_EN_UPDATE(IDC_EDIT_BLUE, OnEditColor)
END_MESSAGE_MAP()

// Конструктор
Dialog::Dialog(
	CWnd                *pParent)  // Указатель на родительское
								   //   окно (NULL - родительским
								   //   является главное окно)
	: CDialog(IDD_DIALOG_RGB, pParent)
{
	m_InitIsDone = false;
}

// Инициализация окна диалога
BOOL Dialog::OnInitDialog(void)
{
	// Вызываем метод базового класса
	CDialog::OnInitDialog();

	BYTE                Red;        // Красная составляющая "m_RGB"
	BYTE                Green;      // Зеленая составляющая "m_RGB"
	BYTE                Blue;       // Синяя составляющая "m_RGB"

									// Получаем указатели на вращатели и элементы редактирования
									//   красного, зеленого и синего цветов        
	pSpinRed = static_cast< CSpinButtonCtrl * >
		(GetDlgItem(IDC_SPIN_RED));
	pSpinGreen = static_cast< CSpinButtonCtrl * >
		(GetDlgItem(IDC_SPIN_GREEN));
	pSpinBlue = static_cast< CSpinButtonCtrl * >
		(GetDlgItem(IDC_SPIN_BLUE));
	// Нижеследующие указатели нужны только для задания ограничения
	//   на длину вводимого текста
	pEditRed = static_cast< CEdit * >
		(GetDlgItem(IDC_EDIT_RED));
	pEditGreen = static_cast< CEdit * >
		(GetDlgItem(IDC_EDIT_GREEN));
	pEditBlue = static_cast< CEdit * >
		(GetDlgItem(IDC_EDIT_BLUE));

	// Установливаем диапазоны значений для вращателей красного,
	//   зеленого и синего цветов (обращаем внимание на то, что
	//   можно обрабатывать возвращаемое значение - для сокращения
	//   объема исходного текста мы это не делаем, но Вам
	//   предлагается выполнить такую модификацию)
	pSpinRed->SetRange(0, 255);
	pSpinGreen->SetRange(0, 255);
	pSpinBlue->SetRange(0, 255);

	// Выделяем красную, зеленую и синюю компоненты "старого"
	//   RGB-цвета
	Red = GetRValue(m_OldRGB);
	Green = GetGValue(m_OldRGB);
	Blue = GetBValue(m_OldRGB);

	// Устанавливаем значения цветов для вращателей
	pSpinRed->SetPos(Red);
	pSpinGreen->SetPos(Green);
	pSpinBlue->SetPos(Blue);

	// Устанавливаем длины текста в байтах (3) для элементов
	//   редактирования цветов
	pEditRed->SetLimitText(3);
	pEditGreen->SetLimitText(3);
	pEditBlue->SetLimitText(3);

	// Инициализация диалога выполнена
	m_InitIsDone = true;

	return TRUE;
}

// Получение информации из окна диалога (обработчик кнопки OK)
void Dialog::OnOK(void)
{
	// Вызываем метод базового класса
	CDialog::OnOK();

	BYTE                Red;        // Красная составляющая "m_RGB"
	BYTE                Green;      // Зеленая составляющая "m_RGB"
	BYTE                Blue;       // Синяя составляющая "m_RGB"

									// Получаем текущие значения цветов от вращателей красного,
									//   зеленого и синего цветов
	Red = pSpinRed->GetPos();
	Green = pSpinGreen->GetPos();
	Blue = pSpinBlue->GetPos();

	// Формируем новый RGB-цвет
	m_NewRGB = RGB(Red, Green, Blue);

	return;
}

// Редактирование составляющих цвета
void Dialog::OnEditColor(void)
{
	BYTE                Red;        // Красная составляющая "m_RGB"
	BYTE                Green;      // Зеленая составляющая "m_RGB"
	BYTE                Blue;       // Синяя составляющая "m_RGB"
									// Указатель родительского окна
	FrameWnd           *pParent;

	if (!m_InitIsDone)
		return;                     // Выход, если не было успешной
									//   инициализации

									// Получаем текущия значения цветов от вращателей красного,
									//   зеленого и синего цветов
	Red = pSpinRed->GetPos();
	Green = pSpinGreen->GetPos();
	Blue = pSpinBlue->GetPos();

	// Формируем новый RGB-цвет
	m_NewRGB = RGB(Red, Green, Blue);

	// Получаем указатель родительского окна и устанавливаем для
	//   него новый RGB-цвет
	pParent = static_cast< FrameWnd * >(GetParent());
	pParent->TryPenRGB(m_NewRGB);

	return;
}