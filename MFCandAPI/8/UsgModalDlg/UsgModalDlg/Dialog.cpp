/*
Файл               : Dialog.сpp

Проект             : демонстрация созания Windows-приложения на
основе библиотеки классов MFC (ресурс -
модальный диалог с радиокнопками)

Назначение         : реализация класса "Dialog", производного
от класса "CDialod" библиотеки классов
MFC (обработка сообщений окна диалога)

Microsoft Visual Studio C++ .NET 2005
*/

#include "StdAfx.h"                 // Прекомпилируемый файл
// Объявление класса Dialog
#include "Dialog.h"
// Идентификаторы ресурсов (поддержка редактором ресурсов)
#include "resource.h"


// Определение таблицы сообщений (в данном случае она избыточна)
BEGIN_MESSAGE_MAP(Dialog, CDialog)
	/*ON_BN_CLICKED( IDC_RADIO_SOLID, OnRadioSolidClick )
	ON_BN_CLICKED( IDC_RADIO_DASH, OnRadioDashClick )
	ON_BN_CLICKED( IDC_RADIO_DOT, OnRadioDotClick )*/
END_MESSAGE_MAP()


// Конструктор
Dialog::Dialog(
	CWnd                *pParent)  // Указатель на родительское
								   //   окно (NULL - родительским
								   //   является главное окно)
	: CDialog(IDR_DIALOG, pParent)
{ }

// Инициализация окна диалога
BOOL Dialog::OnInitDialog(void)
{
	// Вызываем метод базового класса
	CDialog::OnInitDialog();

	// Получаем указатели на радиокнопки
	pRadioSolid = static_cast< CButton * >
		(GetDlgItem(IDC_RADIO_SOLID));
	pRadioDash = static_cast< CButton * >
		(GetDlgItem(IDC_RADIO_DASH));
	pRadioDot = static_cast< CButton * >
		(GetDlgItem(IDC_RADIO_DOT));

	// Устанавливаем активную радиокнопку
	switch (m_PenStyle)
	{

	case PS_SOLID:
		pRadioSolid->SetCheck(1);
		break;

	case PS_DASH:
		pRadioDash->SetCheck(1);
		break;

	case PS_DOT:
		pRadioDot->SetCheck(1);
		break;
	}

	return TRUE;
}

// Обрабатываем закрытие диалога по кнопке ОК
void Dialog::OnOK(void)
{
	// Вызываем метод базового класса
	CDialog::OnOK();

	// Избыточный программный код
	/*pRadioSolid = static_cast< CButton * >
	( GetDlgItem( IDC_RADIO_SOLID ) );
	pRadioDash  = static_cast< CButton * >
	( GetDlgItem(  IDC_RADIO_DASH ) );
	pRadioDot   = static_cast< CButton * >
	( GetDlgItem(  IDC_RADIO_DOT ) );*/

	if (pRadioSolid->GetCheck() == 1)
	{
		m_PenStyle = PS_SOLID;
	}
	else if (pRadioDash->GetCheck() == 1)
	{
		m_PenStyle = PS_DASH;
	}
	else
	{
		m_PenStyle = PS_DOT;
	}

	return;
}

// Обработчики радиокнопок - в данном случае они избыточны
// Обработчик радиокнопки "Сплошной"
/*void Dialog :: OnRadioSolidClick( void )
{
m_PenStyle = PS_SOLID;

return;
}

// Обработчик радиокнопки "Пунктирный"
void Dialog :: OnRadioDashClick( void )
{
m_PenStyle = PS_DASH;

return;
}

// Обработчик радиокнопки "Точечный"
void Dialog :: OnRadioDotClick( void )
{
m_PenStyle = PS_DOT;

return;
}*/
