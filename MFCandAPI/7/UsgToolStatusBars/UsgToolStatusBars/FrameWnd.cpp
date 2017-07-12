#include "StdAfx.h"                 // ���������������� ����
#include "FrameWnd.h"             // ���������� ������ FrameWnd
// �������������� �������� (��������� ���������� ��������)
#include "resource.h"

// ����������� ������� ���������
BEGIN_MESSAGE_MAP(FrameWnd, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_COMMAND(ID_FILE_EXIT, OnMenuFileExit)
	ON_COMMAND(ID_PENSTYLE_SOLID, OnMenuPenstyleSolid)
	ON_COMMAND(ID_PENSTYLE_DASH, OnMenuPenstyleDash)
	ON_COMMAND(ID_PENSTYLE_DOT, OnMenuPenstyleDot)
END_MESSAGE_MAP()

// ���������� ��� ������ �������
static UINT indicators[] =
{
	// ��������� ���������� � ������ ����� ������ �������
	//   (���� ��������� ������ �������, �� ����������
	//   ����� ��������� � ������ ������� �����)
	ID_SEPARATOR,
	ID_INDICATOR_CAPS,              // �������� Caps Lock
	ID_INDICATOR_NUM,               // �������� Num Lk
	ID_INDICATOR_SCRL               // �������� Scr Lk
};

// ����������� ��������� (������������� ���������� ���������)
FrameWnd::FrameWnd(void)
{
	m_PenWidth = 1;
	m_PenRGB = RGB(255, 0, 0);
	m_PenStyle = PS_SOLID;
}

// ���������� ��������� WM_CREATE: �������� � ������������ �������
//   ������������ � ������ �������
afx_msg int FrameWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	// ������� �������� ����� OnCreate �������� ������
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// ������� � ������������� ���� Windows ��� �������
	//   ������������
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD
		| WS_VISIBLE | CBRS_TOP/* | CBRS_GRIPPER */| CBRS_TOOLTIPS
		| CBRS_FLYBY | CBRS_SIZE_DYNAMIC /*| CBRS_SIZE_FIXED*/, CRect(0, 0, 0, 0)) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("\n ������ 2 �������� ������ ������������ \n");
		return 2;
	}

	// ������� � ������������� ���� Windows ��� ������ ������� �
	//   ���������� ��������� Caps Lock, Num Lk � Scr Lk
	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators, sizeof(indicators) /
			sizeof(UINT)))
	{
		TRACE0("\n ������ 3 �������� ������ ������� \n");
		return 3;
	}

	// ������ ��������� ��� �������� ����, ���� ������ ������������
	//   ����� � ��������� ������
	m_wndToolBar.SetWindowText("�����������");

	// ��������� �������� ������ ������������ � ����� �������
	//   ������
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);

	// �� �� ����� ����� ��������� �� ������� ������
	EnableDocking(CBRS_ALIGN_ANY);

	// � ������ ���������� �������� ������ ������������
	DockControlBar(&m_wndToolBar);

	return afx_msg int();
}

// ���������� ��������� WM_PAINT: �������������� ������
//   ������������ � ���������� ������������ ����
afx_msg void FrameWnd::OnPaint(void)
{
	// ������� ������ ��� ��������� � ������
	CPaintDC            PaintDC(this);

	// !!! ����� - �������������� ������ ������������
	m_wndToolBar.LoadToolBar(IDR_MAINFRAME);

	// ������ ����
	SetRhombVertexes();
	DrawRhomb(&PaintDC);

	return afx_msg void();
}

// ��������� ������� ���� | �����
afx_msg void FrameWnd::OnMenuFileExit(void)
{
	BOOL                rc = MessageBeep(-1);
	if (!rc)
	{
		TRACE0("\n ������ 4. �������� ���������� MessageBeep \n");
		exit(4);
	}
	rc = DestroyWindow();
	if (!rc)
	{
		TRACE0("\n ������ 5. ���� �� ���� ��������� \n");
		exit(5);
	}

	return afx_msg void();
}

// ��������� ������� ����� ��������� | ��������
afx_msg void FrameWnd::OnMenuPenstyleSolid(void)
{
	m_PenStyle = PS_SOLID;
	CWnd::Invalidate();

	return afx_msg void();
}

// ��������� ������� ����� ��������� | �������
afx_msg void FrameWnd::OnMenuPenstyleDash(void)
{
	m_PenStyle = PS_DASH;
	CWnd::Invalidate();

	return afx_msg void();
}

// ��������� ������� ����� ��������� | ��������
afx_msg void FrameWnd::OnMenuPenstyleDot(void)
{
	m_PenStyle = PS_DOT;
	CWnd::Invalidate();

	return afx_msg void();
}

// ������� ������ �����
void FrameWnd::SetRhombVertexes(void)
{
	CRect               ClientRect; // ���������� ������� ����
									// ����������� �������� ���������� x � ���������� ������� ����
	int                 MinX;
	// ������� �������� ���������� x � ���������� ������� ����
	int                 MidX;
	// ������������ �������� ���������� x � ���������� ������� ����
	int                 MaxX;
	// ����������� �������� ���������� y � ���������� ������� ����
	int                 MinY;
	// ������� �������� ���������� y � ���������� ������� ����
	int                 MidY;
	// ������������ �������� ���������� y � ���������� ������� ����
	int                 MaxY;

	// ��������� �������� ���������� ������� ����
	CWnd::GetClientRect(&ClientRect);

	MinX = 0;
	MaxX = ClientRect.Width() - 1;
	MidX = MaxX / 2;

	MinY = 0;
	MaxY = ClientRect.Height() - 1;
	MidY = MaxY / 2;

	// ������� ��������� ������
	Vert0 = CPoint(MinX, MidY);
	Vert1 = CPoint(MidX, MinY);
	Vert2 = CPoint(MaxX, MidY);
	Vert3 = CPoint(MidX, MaxY);

	return;
}

// ��������� �����
void FrameWnd::DrawRhomb(
	CDC                 *pDC)      // ��������� �� ��������
								   //   ����������
{
	CPen                NewPen;     // ����� ��������
	CPen                *pOldPen;   // ��������� �� ������ ��������

									// ������� ����� ��������
	NewPen.CreatePen(m_PenStyle, m_PenWidth, m_PenRGB);

	// �������� ����� �������� � �������� ���������� � ����������
	//   ��������� ������� ���������
	pOldPen = pDC->SelectObject(&NewPen);

	// ��������������� � ������� ��������� ������� �����
	pDC->MoveTo(Vert0);

	// ������ ������� �����
	pDC->LineTo(Vert1);
	pDC->LineTo(Vert2);
	pDC->LineTo(Vert3);
	pDC->LineTo(Vert0);

	// ��������������� ��������� ������� ��������� � ���������
	//   ����������
	pDC->SelectObject(pOldPen);

	return;
}