#pragma once
#ifndef _FrameWnd_h
#define _FrameWnd_h

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

								// Строка статуса
	CStatusBar      m_wndStatusBar;
	// Панель инструментов
	CToolBar        m_wndToolBar;

	// Методы

public:

	// Конструктор умолчания (инициализация параметров
	//   карандаша)
	FrameWnd(void);

protected:

	// Так нужно записывать прототипы функций, обрабатывающих
	//   сообщения
	// Обработчик сообщения WM_CREATE: создание и визуализация
	//   панелей инструментов и строки статуса
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	// Перерисовка окна
	afx_msg void OnPaint(void);
	// Обработка команды Файл | Выход
	afx_msg void OnMenuFileExit(void);
	// Обработка команды Стиль карандаша | Сплошной
	afx_msg void OnMenuPenstyleSolid(void);
	// Обработка команды Стиль карандаша | Пунктир
	afx_msg void OnMenuPenstyleDash(void);
	// Обработка команды Стиль карандаша | Точечный
	afx_msg void OnMenuPenstyleDot(void);

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
