#pragma once
/*
Файл               : FrameWnd.hpp

Проект             : демонстрация созания Windows-приложения на
основе библиотеки классов MFC (ресурс -
модальный диалог с радиокнопками)

Назначение         : объявление класса "FrameWnd", производного
от класса "CFrameWnd" библиотеки классов
MFC (обработка сообщений главного окна)

Microsoft Visual Studio C++ .NET 2005
*/

// Предотвращение возможности многократного подключения данного
//   файла
#ifndef _FrameWnd_hpp
#define _FrameWnd_hpp

// Объявление класса
class FrameWnd : public CFrameWnd
{
	// Данные

private:

	// Вершины ромба
	CPoint          Vert0;      // Левая вершина
	CPoint          Vert1;      // Верхняя вершина
	CPoint          Vert2;      // Правая вершина
	CPoint          Vert3;      // Нижняя вершина

								// Параметры карандаша
	int             m_PenWidth; // Толщина
	COLORREF        m_PenRGB;   // RGB-цвет
	int             m_PenStyle; // Стиль

								// Методы

public:

	// Конструктор умолчания (инициализация параметров
	//   карандаша)
	FrameWnd(void);

protected:

	// Прототипы функций, обрабатывающих сообщения
	// Перерисовка окна
	afx_msg void OnPaint(void);
	// Обработка команды Файл | Выход
	afx_msg void OnMenuFileExit(void);
	// Обработка команды Стиль карандаша | Сплошной
	afx_msg void OnMenuPenstyleSolid(void);
	// Обработка команды Стиль карандаша | Пунктирный
	afx_msg void OnMenuPenstyleDash(void);
	// Обработка команды Стиль карандаша | Точечный
	afx_msg void OnMenuPenstyleDot(void);
	// Обработчик команды Радиокнопки | Диалог
	afx_msg void OnMenuRadioButtonDialog(void);

private:

	// Изображение ромба в клиентской области окна
	// Задание вершин ромба
	void SetRhombVertexes(void);
	// Рисование ромба
	void DrawRhomb(CDC *pDC);

	// Объявление таблицы сообщений
	DECLARE_MESSAGE_MAP();
};

#endif

