/*
Файл               : FrameWnd.cpp

Проект             : демонстрация созания Windows-приложения на
основе библиотеки классов MFC (ресурсы -
меню, акселераторы, строки)

Назначение         : реализация класса "FrameWnd", производного
от класса "CFrameWnd" библиотеки классов
MFC (обработка сообщений главного окна)

Microsoft Visual Studio C++ .NET 2005
*/

#include "StdAfx.h"                 // Прекомпилируемый файл
#include "FrameWnd.h"             // Объявление класса FrameWnd
// Идентификаторы ресурсов (поддержка редактором ресурсов)
#include "resource.h"

// Определение таблицы сообщений
BEGIN_MESSAGE_MAP(FrameWnd, CFrameWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_FILE_EXIT, OnMenuFileExit)
	ON_COMMAND(ID_PENSTYLE_SOLID, OnMenuPenstyleSolid)
	ON_COMMAND(ID_PENSTYLE_DASH, OnMenuPenstyleDash)
	ON_COMMAND(ID_PENSTYLE_DOT, OnMenuPenstyleDot)
END_MESSAGE_MAP()

// Конструктор умолчания (инициализация параметров карандаша)
FrameWnd::FrameWnd(void)
{
	m_PenWidth = 1;
	m_PenRGB = RGB(255, 0, 0);
	m_PenStyle = PS_SOLID;
}

// Обработка команды Файл | Выход
afx_msg void FrameWnd::OnMenuFileExit(void)
{
	BOOL                rc = MessageBeep(-1);
	if (!rc)
	{
		TRACE0("\n Ошибка 2. Неверное завершение MessageBeep \n");
		exit(2);
	}
	rc = DestroyWindow();
	if (!rc)
	{
		TRACE0("\n Ошибка 3. Окно не было разрушено \n");
		exit(3);
	}

	return afx_msg void();
}

// Обработчик сообщения WM_PAINT: рисование ромба
afx_msg void FrameWnd::OnPaint(void)
{
	// Создаем объект для рисования и вывода
	CPaintDC            PaintDC(this);

	// Рисуем ромб
	SetRhombVertexes();
	DrawRhomb(&PaintDC);

	return afx_msg void();
}

// Обработка команды Стиль карандаша | Сплошной
afx_msg void FrameWnd::OnMenuPenstyleSolid(void)
{
	m_PenStyle = PS_SOLID;
	CWnd::Invalidate();

	return afx_msg void();
}

// Обработка команды Стиль карандаша | Пунктир
afx_msg void FrameWnd::OnMenuPenstyleDash(void)
{
	m_PenStyle = PS_DASH;
	CWnd::Invalidate();

	return afx_msg void();
}

// Обработка команды Стиль карандаша | Точечный
afx_msg void FrameWnd::OnMenuPenstyleDot(void)
{
	m_PenStyle = PS_DOT;
	CWnd::Invalidate();

	return afx_msg void();
}

// Задание вершин ромба
void FrameWnd::SetRhombVertexes(void)
{
	CRect               ClientRect; // Клиентская область окна
									// Минимальное значение координаты x в клиентской области окна
	int                 MinX;
	// Среднее значение координаты x в клиентской области окна
	int                 MidX;
	// Максимальное значение координаты x в клиентской области окна
	int                 MaxX;
	// Минимальное значение координаты y в клиентской области окна
	int                 MinY;
	// Среднее значение координаты y в клиентской области окна
	int                 MidY;
	// Максимальное значение координаты y в клиентской области окна
	int                 MaxY;

	// Получение размеров клиентской области окна
	CWnd::GetClientRect(&ClientRect);

	MinX = 0;
	MaxX = ClientRect.Width() - 1;
	MidX = MaxX / 2;

	MinY = 0;
	MaxY = ClientRect.Height() - 1;
	MidY = MaxY / 2;

	// Задание координат вершин
	Vert0 = CPoint(MinX, MidY);
	Vert1 = CPoint(MidX, MinY);
	Vert2 = CPoint(MaxX, MidY);
	Vert3 = CPoint(MidX, MaxY);

	return;
}

// Рисование ромба
void FrameWnd::DrawRhomb(
	CDC					*pDC)      // Указатель на контекст
								   //   устройства
{
	CPen                NewPen;     // Новый карандаш
	CPen				*pOldPen;   // Указатель на старый карандаш

									// Создаем новый карандаш
	NewPen.CreatePen(m_PenStyle, m_PenWidth, m_PenRGB);

	// Включаем новый карандаш в контекст устройства и запоминаем
	//   параметры старого карандаша
	pOldPen = pDC->SelectObject(&NewPen);

	// Позиционируемся в позицию начальной вершины ромба
	pDC->MoveTo(Vert0);

	// Рисуем стороны ромба
	pDC->LineTo(Vert1);
	pDC->LineTo(Vert2);
	pDC->LineTo(Vert3);
	pDC->LineTo(Vert0);

	// Восстанавливаем параметры старого карандаша в контексте
	//   устройства
	pDC->SelectObject(pOldPen);

	return;
}
