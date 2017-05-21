
// ex03aView.h : интерфейс класса Cex03aView
//

#pragma once


class Cex03aView : public CView
{
protected: // создать только из сериализации
	Cex03aView();
	DECLARE_DYNCREATE(Cex03aView)

// Атрибуты
public:
	Cex03aDoc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Реализация
public:
	virtual ~Cex03aView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // отладочная версия в ex03aView.cpp
inline Cex03aDoc* Cex03aView::GetDocument() const
   { return reinterpret_cast<Cex03aDoc*>(m_pDocument); }
#endif

