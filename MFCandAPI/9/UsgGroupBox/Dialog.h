/*
   Файл               : Dialog.hpp

   Проект             : демонстрация Windows-приложения на основе
                        библиотеки классов MFC с окном модального
                        диалога, использующим GroupBox

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

        // Указатель на радиокнопку 11 (группа 1, кнопка 1)
        CButton         *m_pRadio11;
        // Указатель на радиокнопку 12 (группа 1, кнопка 2)
        CButton         *m_pRadio12;
        // Указатель на радиокнопку 13 (группа 1, кнопка 3)
        CButton         *m_pRadio13;
        // Указатель на радиокнопку 21 (группа 2, кнопка 1)
        CButton         *m_pRadio21;
        // Указатель на радиокнопку 22 (группа 2, кнопка 2)
        CButton         *m_pRadio22;
        // Указатель на радиокнопку 23 (группа 2, кнопка 3)
        CButton         *m_pRadio23;

    public:

        int             m_Radio1;   // Радиокнопка 1
        int             m_Radio2;   // Радиокнопка 2

    public:

        // Конструктор - передает идентификатор диалога в базовый
        //   класс
        Dialog( CWnd *pParent = 0 );

    protected:

        // Перегружаем виртуальный метод для инициализации диалога
        virtual BOOL OnInitDialog( void );

        // Обработчики радиокнопок
        afx_msg void OnRadio11Click( void );
        afx_msg void OnRadio12Click( void );
        afx_msg void OnRadio13Click( void );
        afx_msg void OnRadio21Click( void );
        afx_msg void OnRadio22Click( void );
        afx_msg void OnRadio23Click( void );

        // Объявление таблицы сообщений
        DECLARE_MESSAGE_MAP( );
    };

#endif
