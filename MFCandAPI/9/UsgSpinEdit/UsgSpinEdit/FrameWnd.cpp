/*
Файл               : FrameWnd.cpp

Проект             : демонстрация Windows-приложения на основе
библиотеки классов MFC с окном модального
диалога, использующим вращатели и окна
редактирования

Назначение         : реализация класса "FrameWnd",
производного от класса "CFrameWnd"
библиотеки классов MFC (обработка сообщений
главного окна)

Microsoft Visual Studio C++ .NET 2005
*/

#include "StdAfx.h"                 // Прекомпилируемый файл
#include "FrameWnd.h"             // Объявление класса FrameWnd
#include "Dialog.h"               // Объявление класса Dialog
// Идентификаторы ресурсов (поддержка редактором ресурсов)
#include "resource.h"

// Определение таблицы сообщений
BEGIN_MESSAGE_MAP(FrameWnd, CFrameWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_FILE_EXIT, OnMenuFileExit)
	ON_COMMAND(ID_PENSTYLE_SOLID, OnMenuPenstyleSolid)
	ON_COMMAND(ID_PENSTYLE_DASH, OnMenuPenstyleDash)
	ON_COMMAND(ID_PENSTYLE_DOT, OnMenuPenstyleDot)
	ON_COMMAND(ID_DIALOG_RGB, OnMenuDialogRGB)
END_MESSAGE_MAP()

// Конструктор умолчания (инициализация параметров карандаша)
FrameWnd::FrameWnd(void)
{
	m_PenWidth = 1;
	m_PenRGB = RGB(255, 0, 0);
	m_PenStyle = PS_SOLID;
}

// Обработка сообщения WM_PAINT
afx_msg void FrameWnd::OnPaint(void)
{
	// Создаем объект для рисования
	CPaintDC            PaintDC(this);

	// Рисование ромба в клиентской области окна
	SetRhombVertexes();
	DrawRhomb(&PaintDC);

	return afx_msg void();
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

// Обработка команды Стиль карандаша | Сплошной
afx_msg void FrameWnd::OnMenuPenstyleSolid(void)
{
	m_PenStyle = PS_SOLID;
	// Генерируем сообщение WM_PAINT и выполняем перерисовку окна
	CWnd::Invalidate();

	return afx_msg void();
}
// Обработка команды Стиль карандаша | Штриховой
afx_msg void FrameWnd::OnMenuPenstyleDash(void)
{
	m_PenStyle = PS_DASH;
	// Генерируем сообщение WM_PAINT и выполняем перерисовку окна
	CWnd::Invalidate();

	return afx_msg void();
}

// Обработка команды Стиль карандаша | Точечный
afx_msg void FrameWnd::OnMenuPenstyleDot(void)
{
	m_PenStyle = PS_DOT;
	// Генерируем сообщение WM_PAINT и выполняем перерисовку окна
	CWnd::Invalidate();

	return afx_msg void();
}

// Обработка команды Вращатели-Редактирование | Диалог
afx_msg void FrameWnd::OnMenuDialogRGB(void)
{
	// Создаем объект диалога - автоматически вызывается
	//   конструктор
	Dialog              Dlg(this);

	// Передаем информацию о цвете из класса FrameWnd в класс
	//   Dialog
	Dlg.m_OldRGB = m_PenRGB;

	// Создается модальное диалоговое окно - оно будет
	//   автоматически закрыто после нажатия OK или Cancel
	int                 DlgResult = static_cast<int>
		(Dlg.DoModal());
	if (DlgResult == IDOK)
	{                               // Выход из диалога по ОК
									// Передаем информацию о цвете из класса Dialog в класс
									//   FrameWnd
		m_PenRGB = Dlg.m_NewRGB;
	}
	else
	{
		m_PenRGB = Dlg.m_OldRGB;
	}

	// Генерируем сообщение WM_PAINT и перерисовываем окно
	CWnd::Invalidate();

	return afx_msg void();
}

// Задание нового RGB-цвета
void FrameWnd::TryPenRGB(
	COLORREF            NewRGB)    // Новый RGB-цвет
{
	m_PenRGB = NewRGB;

	// Генерируем сообщение WM_PAINT и перерисовываем окно
	CWnd::Invalidate();

	return;
}

// Размещение вершин ромба в клиентской области окна
void FrameWnd::SetRhombVertexes(void)
{
	// Для размеров клиентской области окна
	CRect               ClientRect;
	// Минимальное значение х-координаты клиентской области
	int                 MinX;
	// Среднее значение х-координаты клиентской области
	int                 MidX;
	// Максимальное значение х-координаты клиентской области
	int                 MaxX;
	// Минимальное значение y-координаты клиентской области
	int                 MinY;
	// Среднее значение y-координаты клиентской области
	int                 MidY;
	// Максимальное значение y-координаты клиентской области
	int                 MaxY;

	// Получаем параметры клиентской области окна
	CWnd::GetClientRect(&ClientRect);
	MinX = 0;
	MaxX = ClientRect.Width() - 1;
	MidX = MaxX / 2;
	MinY = 0;
	MaxY = ClientRect.Height() - 1;
	MidY = MaxY / 2;

	// Вычисляем координаты вершин ромба
	Vert0 = CPoint(MinX, MidY);
	Vert1 = CPoint(MidX, MinY);
	Vert2 = CPoint(MaxX, MidY);
	Vert3 = CPoint(MidX, MaxY);

	return;

}

// Рисование ромба в клиентской области окна
void FrameWnd::DrawRhomb(
	CDC                 *pDC)      // Указатель контекста 
{
	// Новый карандаш
	CPen                NewPen;
	// Указатель на старый карандаш
	CPen                *pOldPen;

	// Создаем новый карандаш  (обращаем внимание на то, что
	//   можно обрабатывать возвращаемое значение - для сокращения
	//   объема исходного текста мы это не делаем, но Вам
	//   предлагается выполнить такую модификацию)
	NewPen.CreatePen(m_PenStyle, m_PenWidth, m_PenRGB);

	// Включаем новый карандаш в контекст устройства
	pOldPen = pDC->SelectObject(&NewPen);

	// Устанавливаем текущую позицию для рисования
	pDC->MoveTo(Vert0);

	// Рисуем стороны ромба  (обращаем внимание на то, что можно
	//   обрабатывать возвращаемое значение - для сокращения объема
	//   исходного текста мы это не делаем, но Вам предлагается
	//   выполнить такую модификацию)
	pDC->LineTo(Vert1);
	pDC->LineTo(Vert2);
	pDC->LineTo(Vert3);
	pDC->LineTo(Vert0);

	// Помещаем старый карандаш в контекст устройства
	pDC->SelectObject(pOldPen);

	return;
}