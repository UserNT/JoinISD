
// ex03aView.cpp : реализаци€ класса Cex03aView
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позвол€ет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "ex03a.h"
#endif

#include "ex03aDoc.h"
#include "ex03aView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cex03aView

IMPLEMENT_DYNCREATE(Cex03aView, CView)

BEGIN_MESSAGE_MAP(Cex03aView, CView)
	// —тандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cex03aView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// создание/уничтожение Cex03aView

Cex03aView::Cex03aView()
{
	// TODO: добавьте код создани€

}

Cex03aView::~Cex03aView()
{
}

BOOL Cex03aView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменени€
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// рисование Cex03aView

void Cex03aView::OnDraw(CDC* pDC)
{
	Cex03aDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString Msg ("Hello, world!");
	// TODO: добавьте здесь код отрисовки дл€ собственных данных
	pDC->TextOutW(0, 0, Msg);
	pDC->SelectStockObject(BLACK_BRUSH);
	pDC->Ellipse(CRect(0, 40, 100, 140));
}


// печать Cex03aView


void Cex03aView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cex03aView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void Cex03aView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void Cex03aView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}

void Cex03aView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cex03aView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// диагностика Cex03aView

#ifdef _DEBUG
void Cex03aView::AssertValid() const
{
	CView::AssertValid();
}

void Cex03aView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cex03aDoc* Cex03aView::GetDocument() const // встроена неотлаженна€ верси€
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cex03aDoc)));
	return (Cex03aDoc*)m_pDocument;
}
#endif //_DEBUG


// обработчики сообщений Cex03aView
