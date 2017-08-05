/*
   Файл               : FrameWnd.hpp

   Проект             : демонстрация Windows-приложения на основе
                        библиотеки классов MFC с окном модального
                        диалога, использующим GroupBox

   Назначение         : объявление класса "FrameWnd", производного
                        от класса "CFrameWnd" библиотеки классов
                        MFC (обработка сообщений главного окна)

   Microsoft Visual Studio C++ .NET 2005
*/

// Предотвращение возможности многократного подключения данного
//   файла
#ifndef _FrameWnd_h
    #define _FrameWnd_h

    // Объявление класса
    class FrameWnd : public CFrameWnd
    {
        // Данные

    private:

        // Переменные, связанные с GroupBox
        int             m_Radio1;   // Радиокнопка 1
        int             m_Radio2;   // Радиокнопка 2

        // Методы

    public:

        // Конструктор умолчания (инициализация радиокнопок)
        FrameWnd( void );
    
    protected:

        // Прототипы функций, обрабатывающих сообщения
        // Обработка команды Файл | Выход
        afx_msg void OnMenuFileExit( void );
        // Обработка команды Группы_радио_кнопок | Диалог
        afx_msg void OnMenuRadioButtons( void );

        // Объявление таблицы сообщений
        DECLARE_MESSAGE_MAP( );
    };

#endif
