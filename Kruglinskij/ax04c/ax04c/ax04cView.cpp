
// ax04cView.cpp : ���������� ������ Cax04cView
//

#include "stdafx.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
#ifndef SHARED_HANDLERS
#include "ax04c.h"
#endif

#include "ax04cDoc.h"
#include "ax04cView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cax04cView

IMPLEMENT_DYNCREATE(Cax04cView, CScrollView)

BEGIN_MESSAGE_MAP(Cax04cView, CScrollView)
	// ����������� ������� ������
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cax04cView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// ��������/����������� Cax04cView

Cax04cView::Cax04cView() : m_rectEllipse(0, 0, 4000, -4000)
{
	// TODO: �������� ��� ��������
	m_nColor = GRAY_BRUSH;
}

Cax04cView::~Cax04cView()
{
}

BOOL Cax04cView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �������� ����� Window ��� ����� ����������� ���������
	//  CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

// ��������� Cax04cView

void Cax04cView::OnDraw(CDC* pDC)
{
	pDC->SelectStockObject(m_nColor);
	pDC->Ellipse(m_rectEllipse);

	// TODO: �������� ����� ��� ��������� ��� ����������� ������
}

void Cax04cView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal(20000, 30000);
	CSize sizePage(sizeTotal.cx / 2, sizeTotal.cy / 2);
	CSize sizeLine(sizeTotal.cx / 50, sizeTotal.cy / 50);
	SetScrollSizes(MM_HIMETRIC, sizeTotal, sizePage, sizeLine);
	// TODO: ����������� ������ ������ ����� �������������
	/*sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);*/
	
}


// ������ Cax04cView


void Cax04cView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cax04cView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ���������� �� ���������
	return DoPreparePrinting(pInfo);
}

void Cax04cView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� �������������� ������������� ����� �������
}

void Cax04cView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� ������� ����� ������
}

void Cax04cView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cax04cView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// ����������� Cax04cView

#ifdef _DEBUG
void Cax04cView::AssertValid() const
{
	CScrollView::AssertValid();
}

void Cax04cView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

Cax04cDoc* Cax04cView::GetDocument() const // �������� ������������ ������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cax04cDoc)));
	return (Cax04cDoc*)m_pDocument;
}
#endif //_DEBUG


// ����������� ��������� Cax04cView


void Cax04cView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default

	//CScrollView::OnKeyDown(nChar, nRepCnt, nFlags);

	switch (nChar)
	{
	case VK_HOME:
		OnVScroll(SB_TOP, 0, NULL);
		OnHScroll(SB_LEFT, 0, NULL);
		break;
	case VK_END:
		OnVScroll(SB_BOTTOM, 0, NULL);
		OnHScroll(SB_RIGHT, 0, NULL);
		break;
	case VK_UP:
		OnVScroll(SB_LINEUP, 0, NULL);
		break;
	case VK_DOWN:
		OnVScroll(SB_LINEDOWN, 0, NULL);
		break;
	case VK_PRIOR:
		OnVScroll(SB_PAGEUP, 0, NULL);
		break;
	case VK_NEXT:
		OnVScroll(SB_PAGEDOWN, 0, NULL);
		break;
	case VK_LEFT:
		OnHScroll(SB_LINELEFT, 0, NULL);
		break;
	case VK_RIGHT:
		OnHScroll(SB_LINERIGHT, 0, NULL);
		break;
	default:
		break;
	}
}


void Cax04cView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	//CScrollView::OnLButtonDown(nFlags, point);

	CClientDC dc(this);
	OnPrepareDC(&dc);
	CRect rectDevice = m_rectEllipse;
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
