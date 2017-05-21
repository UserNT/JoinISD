
// ex04aView.cpp : реализаци€ класса Cex04aView
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позвол€ет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "ex04a.h"
#endif

#include "ex04aDoc.h"
#include "ex04aView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cex04aView

IMPLEMENT_DYNCREATE(Cex04aView, CView)

BEGIN_MESSAGE_MAP(Cex04aView, CView)
	// —тандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cex04aView::OnFilePrintPreview)
//	ON_WM_CONTEXTMENU()
//	ON_WM_RBUTTONUP()
//	ON_WM_ACTIVATE()
ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// создание/уничтожение Cex04aView

Cex04aView::Cex04aView() : m_rectEllipce(0, 0, 4000, -4000)
{
	// TODO: добавьте код создани€

	m_nColor = GRAY_BRUSH;

}

Cex04aView::~Cex04aView()
{
}

BOOL Cex04aView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменени€
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// рисование Cex04aView

void Cex04aView::OnDraw(CDC* pDC)
{
	pDC->SelectStockObject(m_nColor);	
	pDC->Ellipse(m_rectEllipce);
	
	/*pDC->SetMapMode(MM_TEXT);
	pDC->SetWindowOrg(CPoint(100, 100));
	pDC->Rectangle(CRect(100, 100, 300, 300));*/

	/*CRect rectClient;
	GetClientRect(rectClient);
	pDC->SetMapMode(MM_ISOTROPIC);
	pDC->SetWindowExt(1000, 1000);
	pDC->SetViewportExt(rectClient.right, -rectClient.bottom);
	pDC->SetViewportOrg(rectClient.right / 2, rectClient.bottom / 2);*/

	pDC->Ellipse(CRect(-500, -500, 500, 500));
	// TODO: добавьте здесь код отрисовки дл€ собственных данных
}


// печать Cex04aView


void Cex04aView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cex04aView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void Cex04aView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void Cex04aView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}

//void Cex04aView::OnRButtonUp(UINT /* nFlags */, CPoint point)
//{
//	ClientToScreen(&point);
//	OnContextMenu(this, point);
//}

//void Cex04aView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
//{
//#ifndef SHARED_HANDLERS
//	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
//#endif
//}


// диагностика Cex04aView

#ifdef _DEBUG
void Cex04aView::AssertValid() const
{
	CView::AssertValid();
}

void Cex04aView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cex04aDoc* Cex04aView::GetDocument() const // встроена неотлаженна€ верси€
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cex04aDoc)));
	return (Cex04aDoc*)m_pDocument;
}
#endif //_DEBUG


// обработчики сообщений Cex04aView


//void Cex04aView::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
//{
//	CView::OnActivate(nState, pWndOther, bMinimized);
//
//	// TODO: Add your message handler code here
//}


void Cex04aView::OnLButtonDown(UINT nFlags, CPoint point)
{
	/*if (m_rectEllipce.PtInRect(point))
	{
		if (m_nColor == GRAY_BRUSH)
			m_nColor = WHITE_BRUSH;
		else
			m_nColor = GRAY_BRUSH;

		InvalidateRect(m_rectEllipce);	
	}*/

	CClientDC dc(this);
	OnPrepareDC(&dc);
	CRect rectDevice = m_rectEllipce;
	dc.LPtoDP(rectDevice);
	if (rectDevice.PtInRect(point))
	{
		if (m_nColor == GRAY_BRUSH)
			m_nColor = WHITE_BRUSH;
		else
			m_nColor = GRAY_BRUSH;

		InvalidateRect(rectDevice);
	}
}


void Cex04aView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo)
{
	// TODO: Add your specialized code here and/or call the base class
	pDC->SetMapMode(MM_HIMETRIC);
	CView::OnPrepareDC(pDC, pInfo);
}
