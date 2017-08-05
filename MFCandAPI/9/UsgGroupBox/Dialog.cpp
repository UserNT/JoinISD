/*
   Файл               : Dialog.сpp

   Проект             : демонстрация Windows-приложения на основе
                        библиотеки классов MFC с окном модального
                        диалога, использующим GroupBox

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
BEGIN_MESSAGE_MAP( Dialog, CDialog )
    ON_BN_CLICKED( IDC_RADIO11, OnRadio11Click )
    ON_BN_CLICKED( IDC_RADIO12, OnRadio12Click )
    ON_BN_CLICKED( IDC_RADIO13, OnRadio13Click )
    ON_BN_CLICKED( IDC_RADIO21, OnRadio21Click )
    ON_BN_CLICKED( IDC_RADIO22, OnRadio22Click )
    ON_BN_CLICKED( IDC_RADIO23, OnRadio23Click )
END_MESSAGE_MAP( )


// Конструктор
Dialog :: Dialog( 
    CWnd                *pParent )  // Указатель на родительское
                                    //   окно (NULL - родительским
                                    //   является главное окно)
    : CDialog( IDD_DIALOG_RADIO, pParent )
    { }

// Инициализация окна диалога
BOOL Dialog :: OnInitDialog( void )
{
    // Вызываем метод базового класса
    CDialog :: OnInitDialog( );

    // Получаем указатели на радиокнопки
    m_pRadio11 = static_cast< CButton * >( GetDlgItem( IDC_RADIO11 ) );
    m_pRadio12 = static_cast< CButton * >( GetDlgItem( IDC_RADIO12 ) );
    m_pRadio13 = static_cast< CButton * >( GetDlgItem( IDC_RADIO13 ) );
    m_pRadio21 = static_cast< CButton * >( GetDlgItem( IDC_RADIO21 ) );
    m_pRadio22 = static_cast< CButton * >( GetDlgItem( IDC_RADIO22 ) );
    m_pRadio23 = static_cast< CButton * >( GetDlgItem( IDC_RADIO23 ) );

    // Устанавливаем активную радиокнопку в группе 1
    switch ( m_Radio1 )
    {
    case 1:
        m_pRadio11->SetCheck( 1 );
        break;

    case 2:
        m_pRadio12->SetCheck( 1 );
        break;

    case 3:
        m_pRadio13->SetCheck( 1 );
        break;
    }

    // Устанавливаем активную радиокнопку в группе 2
    switch ( m_Radio2 )
    {
    case 4:
        m_pRadio21->SetCheck( 1 );
        break;

    case 5:
        m_pRadio22->SetCheck( 1 );
        break;

    case 6:
        m_pRadio23->SetCheck( 1 );
        break;
    }

    return TRUE;
}

// Обработчики радиокнопок
// Обработчик радиокнопки 11
void Dialog :: OnRadio11Click( void )
{
    m_Radio1 = 1;

    return;
} 

// Обработчик радиокнопки 12
void Dialog :: OnRadio12Click( void )
{
    m_Radio1 = 2;

    return;
} 

// Обработчик радиокнопки 13
void Dialog :: OnRadio13Click( void )
{
    m_Radio1 = 3;

    return;
}

// Обработчик радиокнопки 21
void Dialog :: OnRadio21Click( void )
{
    m_Radio2 = 4;

    return;
}

// Обработчик радиокнопки 22
void Dialog :: OnRadio22Click( void )
{
    m_Radio2 = 5;

    return;
}

// Обработчик радиокнопки 23
void Dialog :: OnRadio23Click( void )
{
    m_Radio2 = 6;

    return;
}