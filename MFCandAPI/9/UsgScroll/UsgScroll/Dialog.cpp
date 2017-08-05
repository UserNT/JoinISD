/*
Файл               : Dialog.сpp

Проект             : демонстрация Windows-приложения на основе
библиотеки классов MFC с окном модального
диалога, использующим полосы прокрутки

Назначение         : реализация класса "Dialog", производного
от класса "CDialod" библиотеки классов
MFC (обработка окна диалога)

Microsoft Visual Studio C++ .NET 2005
*/


#include "StdAfx.h"                 // Прекомпилируемый файл
#include "FrameWnd.h"             // Объявление класса FrameWnd
#include "Dialog.h"               // Объявление класса Dialog
// Идентификаторы ресурсов (поддержка редактором ресурсов)
#include "resource.h"

// Определение карты сообщений
BEGIN_MESSAGE_MAP(Dialog, CDialog)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()

// Конструктор
Dialog::Dialog(
	CWnd                *pParent)  // Указатель на родительское
								   //   окно (NULL - родительским
								   //   является главное окно)
	: CDialog(IDD_DIALOG_RGB, pParent)
{
}

// Инициализация окна диалога
BOOL Dialog::OnInitDialog(void)
{
	// Вызываем метод базового класса
	CDialog::OnInitDialog();

	BYTE                Red;        // Красная составляющая "m_RGB"
	BYTE                Green;      // Зеленая составляющая "m_RGB"
	BYTE                Blue;       // Синяя составляющая "m_RGB"

									// Получаем указатели на полосы прокрутки красного, зеленого и
									//   синего цветов    
	pScrollBarRed = static_cast< CScrollBar * >
		(GetDlgItem(IDC_SCROLLBARRED));
	pScrollBarGreen = static_cast< CScrollBar * >
		(GetDlgItem(IDC_SCROLLBARGREEN));
	pScrollBarBlue = static_cast< CScrollBar * >
		(GetDlgItem(IDC_SCROLLBARBLUE));

	// Установливаем диапазоны значений для полос прокрутки красного,
	//   зеленого и синего цветов (обращаем внимание на то, что
	//   можно обрабатывать возвращаемое значение - для сокращения
	//   объема исходного текста мы это не делаем, но Вам
	//   предлагается выполнить такую модификацию)
	pScrollBarRed->SetScrollRange(0, 255);
	pScrollBarGreen->SetScrollRange(0, 255);
	pScrollBarBlue->SetScrollRange(0, 255);

	// Выделяем красную, зеленую и синюю компоненты "старого"
	//   RGB-цвета
	Red = GetRValue(m_OldRGB);
	Green = GetGValue(m_OldRGB);
	Blue = GetBValue(m_OldRGB);

	// Устанавливаем значения цветов для полос прокрутки
	pScrollBarRed->SetScrollPos(Red);
	pScrollBarGreen->SetScrollPos(Green);
	pScrollBarBlue->SetScrollPos(Blue);

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

									// Получаем текущие значения цветов от полос прокрутки красного,
									//   зеленого и синего цветов
	Red = pScrollBarRed->GetScrollPos();
	Green = pScrollBarGreen->GetScrollPos();
	Blue = pScrollBarBlue->GetScrollPos();

	// Формируем новый RGB-цвет
	m_NewRGB = RGB(Red, Green, Blue);

	return;
}

// Обработчик сообщений от горизонтальной полосы прокрутки
afx_msg void Dialog::OnHScroll(
	// Код уведомления полосы прокрутки
	UINT                nSBCode,
	UINT                nPos,       // Текущая позиция бегунка
									// Указатель на полосу прокрутки
	CScrollBar          *pScrollBar)
{
	int                 nCurPos;    // Позиция бегунка

									// Получаем позицию бегунка
	nCurPos = pScrollBar->GetScrollPos();

	// Вызываем метод базового класса
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);

	// Обрабатываем сообщения полосы прокрутки
	switch (nSBCode)
	{
		// Нажата правая кнопка
	case SB_LINEDOWN:
		nCurPos += 1;
		break;

		// Нажата левая кнопка
	case SB_LINEUP:
		nCurPos -= 1;
		break;

		// Нажата кнопка мыши справа от бегунка
	case SB_PAGEDOWN:
		nCurPos += 10;
		break;

		// Нажата кнопка мыши слева от бегунка
	case SB_PAGEUP:
		nCurPos -= 10;
		break;

		// Выполнено протаскивание бегунка
	case SB_THUMBTRACK:
		nCurPos = nPos;
		break;
	}

	// Устанавливаем новое местоположение бегунка
	pScrollBar->SetScrollPos(nCurPos);

	return afx_msg void();
}
