/*
����               : FrameWnd.cpp

������             : ������������ Windows-���������� �� ������
���������� ������� MFC � ����� ����������
�������, ������������ ��������� � ����
��������������

����������         : ���������� ������ "FrameWnd",
������������ �� ������ "CFrameWnd"
���������� ������� MFC (��������� ���������
�������� ����)

Microsoft Visual Studio C++ .NET 2005
*/

#include "StdAfx.h"                 // ���������������� ����
#include "FrameWnd.h"             // ���������� ������ FrameWnd
#include "Dialog.h"               // ���������� ������ Dialog
// �������������� �������� (��������� ���������� ��������)
#include "resource.h"

// ����������� ������� ���������
BEGIN_MESSAGE_MAP(FrameWnd, CFrameWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_FILE_EXIT, OnMenuFileExit)
	ON_COMMAND(ID_PENSTYLE_SOLID, OnMenuPenstyleSolid)
	ON_COMMAND(ID_PENSTYLE_DASH, OnMenuPenstyleDash)
	ON_COMMAND(ID_PENSTYLE_DOT, OnMenuPenstyleDot)
	ON_COMMAND(ID_DIALOG_RGB, OnMenuDialogRGB)
END_MESSAGE_MAP()

// ����������� ��������� (������������� ���������� ���������)
FrameWnd::FrameWnd(void)
{
	m_PenWidth = 1;
	m_PenRGB = RGB(255, 0, 0);
	m_PenStyle = PS_SOLID;
}

// ��������� ��������� WM_PAINT
afx_msg void FrameWnd::OnPaint(void)
{
	// ������� ������ ��� ���������
	CPaintDC            PaintDC(this);

	// ��������� ����� � ���������� ������� ����
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
		TRACE0("\n ������ 2. �������� ���������� MessageBeep \n");
		exit(2);
	}
	rc = DestroyWindow();
	if (!rc)
	{
		TRACE0("\n ������ 3. ���� �� ���� ��������� \n");
		exit(3);
	}

	return afx_msg void();
}

// ��������� ������� ����� ��������� | ��������
afx_msg void FrameWnd::OnMenuPenstyleSolid(void)
{
	m_PenStyle = PS_SOLID;
	// ���������� ��������� WM_PAINT � ��������� ����������� ����
	CWnd::Invalidate();

	return afx_msg void();
}
// ��������� ������� ����� ��������� | ���������
afx_msg void FrameWnd::OnMenuPenstyleDash(void)
{
	m_PenStyle = PS_DASH;
	// ���������� ��������� WM_PAINT � ��������� ����������� ����
	CWnd::Invalidate();

	return afx_msg void();
}

// ��������� ������� ����� ��������� | ��������
afx_msg void FrameWnd::OnMenuPenstyleDot(void)
{
	m_PenStyle = PS_DOT;
	// ���������� ��������� WM_PAINT � ��������� ����������� ����
	CWnd::Invalidate();

	return afx_msg void();
}

// ��������� ������� ���������-�������������� | ������
afx_msg void FrameWnd::OnMenuDialogRGB(void)
{
	// ������� ������ ������� - ������������� ����������
	//   �����������
	Dialog              Dlg(this);

	// �������� ���������� � ����� �� ������ FrameWnd � �����
	//   Dialog
	Dlg.m_OldRGB = m_PenRGB;

	// ��������� ��������� ���������� ���� - ��� �����
	//   ������������� ������� ����� ������� OK ��� Cancel
	int                 DlgResult = static_cast<int>
		(Dlg.DoModal());
	if (DlgResult == IDOK)
	{                               // ����� �� ������� �� ��
									// �������� ���������� � ����� �� ������ Dialog � �����
									//   FrameWnd
		m_PenRGB = Dlg.m_NewRGB;
	}
	else
	{
		m_PenRGB = Dlg.m_OldRGB;
	}

	// ���������� ��������� WM_PAINT � �������������� ����
	CWnd::Invalidate();

	return afx_msg void();
}

// ������� ������ RGB-�����
void FrameWnd::TryPenRGB(
	COLORREF            NewRGB)    // ����� RGB-����
{
	m_PenRGB = NewRGB;

	// ���������� ��������� WM_PAINT � �������������� ����
	CWnd::Invalidate();

	return;
}

// ���������� ������ ����� � ���������� ������� ����
void FrameWnd::SetRhombVertexes(void)
{
	// ��� �������� ���������� ������� ����
	CRect               ClientRect;
	// ����������� �������� �-���������� ���������� �������
	int                 MinX;
	// ������� �������� �-���������� ���������� �������
	int                 MidX;
	// ������������ �������� �-���������� ���������� �������
	int                 MaxX;
	// ����������� �������� y-���������� ���������� �������
	int                 MinY;
	// ������� �������� y-���������� ���������� �������
	int                 MidY;
	// ������������ �������� y-���������� ���������� �������
	int                 MaxY;

	// �������� ��������� ���������� ������� ����
	CWnd::GetClientRect(&ClientRect);
	MinX = 0;
	MaxX = ClientRect.Width() - 1;
	MidX = MaxX / 2;
	MinY = 0;
	MaxY = ClientRect.Height() - 1;
	MidY = MaxY / 2;

	// ��������� ���������� ������ �����
	Vert0 = CPoint(MinX, MidY);
	Vert1 = CPoint(MidX, MinY);
	Vert2 = CPoint(MaxX, MidY);
	Vert3 = CPoint(MidX, MaxY);

	return;

}

// ��������� ����� � ���������� ������� ����
void FrameWnd::DrawRhomb(
	CDC                 *pDC)      // ��������� ��������� 
{
	// ����� ��������
	CPen                NewPen;
	// ��������� �� ������ ��������
	CPen                *pOldPen;

	// ������� ����� ��������  (�������� �������� �� ��, ���
	//   ����� ������������ ������������ �������� - ��� ����������
	//   ������ ��������� ������ �� ��� �� ������, �� ���
	//   ������������ ��������� ����� �����������)
	NewPen.CreatePen(m_PenStyle, m_PenWidth, m_PenRGB);

	// �������� ����� �������� � �������� ����������
	pOldPen = pDC->SelectObject(&NewPen);

	// ������������� ������� ������� ��� ���������
	pDC->MoveTo(Vert0);

	// ������ ������� �����  (�������� �������� �� ��, ��� �����
	//   ������������ ������������ �������� - ��� ���������� ������
	//   ��������� ������ �� ��� �� ������, �� ��� ������������
	//   ��������� ����� �����������)
	pDC->LineTo(Vert1);
	pDC->LineTo(Vert2);
	pDC->LineTo(Vert3);
	pDC->LineTo(Vert0);

	// �������� ������ �������� � �������� ����������
	pDC->SelectObject(pOldPen);

	return;
}