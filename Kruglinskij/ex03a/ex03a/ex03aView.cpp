
// ex03aView.cpp : ���������� ������ Cex03aView
//

#include "stdafx.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
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
	// ����������� ������� ������
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cex03aView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// ��������/����������� Cex03aView

Cex03aView::Cex03aView()
{
	// TODO: �������� ��� ��������

}

Cex03aView::~Cex03aView()
{
}

BOOL Cex03aView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �������� ����� Window ��� ����� ����������� ���������
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// ��������� Cex03aView

void Cex03aView::OnDraw(CDC* pDC)
{
	Cex03aDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString Msg ("Hello, world!");
	// TODO: �������� ����� ��� ��������� ��� ����������� ������
	pDC->TextOutW(0, 0, Msg);
	pDC->SelectStockObject(BLACK_BRUSH);
	pDC->Ellipse(CRect(0, 40, 100, 140));
}


// ������ Cex03aView


void Cex03aView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cex03aView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ���������� �� ���������
	return DoPreparePrinting(pInfo);
}

void Cex03aView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� �������������� ������������� ����� �������
}

void Cex03aView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� ������� ����� ������
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


// ����������� Cex03aView

#ifdef _DEBUG
void Cex03aView::AssertValid() const
{
	CView::AssertValid();
}

void Cex03aView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cex03aDoc* Cex03aView::GetDocument() const // �������� ������������ ������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cex03aDoc)));
	return (Cex03aDoc*)m_pDocument;
}
#endif //_DEBUG


// ����������� ��������� Cex03aView
