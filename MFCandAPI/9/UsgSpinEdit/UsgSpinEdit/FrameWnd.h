#pragma once
#ifndef _FrameWnd_h
#define _FrameWnd_h

// Объявление класса
class FrameWnd : public CFrameWnd
{
	// Данные

private:

	// Вершины ромба
	CPoint          Vert0;      // Левая
	CPoint          Vert1;      // Верхняя
	CPoint          Vert2;      // Правая
	CPoint          Vert3;      // Нижняя

								// Параметры карандаша
	int             m_PenWidth; // Толщина
	COLORREF        m_PenRGB;   // RGB-цвет
	int             m_PenStyle; // Стиль линии

								// Методы

public:

	// Конструктор умолчания (инициализация параметров
	//   карандаша)
	FrameWnd(void);

	// Задание нового RGB-цвета
	void TryPenRGB(COLORREF  NewRGB);

protected:

	// Прототипы функций, обрабатывающих сообщения
	// Обработка сообщения WM_PAINT
	afx_msg void OnPaint(void);
	// Обработка команды Файл | Выход
	afx_msg void OnMenuFileExit(void);
	// Обработка команды Стиль карандаша | Сплошной
	afx_msg void OnMenuPenstyleSolid(void);
	// Обработка команды Стиль карандаша | Штриховой
	afx_msg void OnMenuPenstyleDash(void);
	// Обработка команды Стиль карандаша | Точечный
	afx_msg void OnMenuPenstyleDot(void);
	// Обработка команды Вращатели-Редактирование | Диалог
	afx_msg void OnMenuDialogRGB(void);

private:

	// Рисование ромба в клиентской области
	void SetRhombVertexes(void);
	void DrawRhomb(CDC *  pDC);

	// Объявление таблицы сообщений
	DECLARE_MESSAGE_MAP();
};

#endif