
// ex03aView.h : ��������� ������ Cex03aView
//

#pragma once


class Cex03aView : public CView
{
protected: // ������� ������ �� ������������
	Cex03aView();
	DECLARE_DYNCREATE(Cex03aView)

// ��������
public:
	Cex03aDoc* GetDocument() const;

// ��������
public:

// ���������������
public:
	virtual void OnDraw(CDC* pDC);  // �������������� ��� ��������� ����� �������������
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ����������
public:
	virtual ~Cex03aView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ��������� ������� ����� ���������
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ���������� ������ � ex03aView.cpp
inline Cex03aDoc* Cex03aView::GetDocument() const
   { return reinterpret_cast<Cex03aDoc*>(m_pDocument); }
#endif

