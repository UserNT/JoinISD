/*
����               : FrameWnd.cpp

������             : ������������ �������� Windows-����������
�� ������ ���������� ������� MFC,
������������ ����� � ������� ����

����������         : ���������� ������ "FrameWnd", ������������
�� ������ "CFrameWnd" ���������� �������
MFC (��������� ��������� �������� ����)

Microsoft Visual Studio C++ .NET 2005
*/

#include "StdAfx.h"                 // ���������������� ����
#include "FrameWnd.h"             // ���������� ������ FrameWnd

// ����������� ������� ���������
BEGIN_MESSAGE_MAP(FrameWnd, CFrameWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()
/*
!!! �������� �������� �� ����� ������������ ���������� �����
���������!!!
������ DECLARE_MESSAGE_MAP, ������������� � ����� ����������
������ LFramtWnd, ����������� ��� ���������� ������� ���������.
��������� ����� ��������� ���������� ������ � ������������ �����
����� ��������, ����������� � ����������� "����������� ������".
���������� ����� ��������� � ������ �������
BEGIN_MESSAGE_MAP( FrameWnd, CFrameWnd ), ������� ����� ���������
���������: FrameWnd - ������ ��� ������, ������� ��������
���������� ����� ���������; CFrameWnd - ���������� ��� ��������
������. ������������� ����� ��������� ������� �������
END_MESSAGE_MAP( ). ����� ����� ����� �������� �������������
����������� �������, ���������� ������������ ����� ���������. ���
���-��, ����������, � ��������� ����������� ��������� � ����������
������������.
��� ������� ������������ ��������� Windows ��������� ���� ������
� ����� ON_WM_XXX, ��� XXX - ��� ���������, ��������, ON_WM_PAINT.
����� ������������ ������������ ��� ���������� ���������� �������
��������� Windows, �� ������ �������� ����������. ����� ������������
������ ���������� � �������� On, �� ������� ������� ���
���������������� ��������� Windows (��� �������� WM_), ����������
��������� �������. ��������, ��� ��������� WM_PAINT � ������ CWnd
��������� ���������� (��. � ����� FrameWnd.hpp)
afx_msg void OnPaint( void );
�������� ���� ������������ ����������� ��������� Windows �����
����� � ����� afxwin.h � ���������� ������ CWnd.
������� �����, ��� ��� ��������� ��������� Windows �� ����,
������������� � ������ ������� ������������, ��� ������ ����������,
��� ���������, ���������� ��������� ������ ����� ���������, ���
������, ��������� ��������������, ������� � ��������������� �������
������������ ������ �������. ��� ����� ����������� � �����������
��������.
*/

// ���������� ��������� WM_PAINT: ������������� ������� ���������
//   ���������� (�����, �����, �����, ������� ����, ����� ��������
//   ������ � ��.)
afx_msg void FrameWnd::OnPaint(void)
{
	COLORREF            oldColor,   // ������ ���� ��������
		oldBkColor; // ������ ���� ���� ��������
	CBrush              NewBrush,   // ����� �����
		*OldBrush;  // ��������� �� ������ �����
	CPen                NewPen,     // ����� ����
		*OldPen;    // ��������� �� ������ ����

					// ������� ������ ��� ��������� � ������
	CPaintDC            PaintDC(this);
	/*
	�������� ����� ������ � ������� ������ CPaintDC. ������
	CPaintDC ������������ ����������� ����. ����� ��������� ������
	��� ����������, �������� ��� ����������� ��������� �
	�������������� SDK-API-�������:
	// ���������� ��������� ����������
	HDC                 hDC;
	// ��������� �� ��������� � ����������� ��� ���������� �
	//   ���������� ������� ����, ������������ ��� ������ � ����
	PAINTSTRUCT         ps;
	// ��� ������ ������ � ���� Windows ���������� ������������
	//   ������� GDI, ������� � �������� ��������� ����������
	//   �������� ����������. ������ �������� ���������� �������� �
	//   ������� ������ BeginPaint
	hDC = BeginPaint( hwnd, &ps );
	// ����� ��������� ������ (��������� ��������, 28 - �����
	//   ������) � ������������ ����� ���� (������ � ������
	//   ���������)
	TextOut( hDC, 150, 0, "��������� ��������� WM_PAINT", 28 );
	// ����� ���������� � ���� ����������� ������� ������� EndPaint
	//   (��� ������� ������ BeginPaint ������ ������������
	//   ��������������� ����� EndPaint)
	EndPaint( hwnd, &ps );
	������ CPaintDC ��������� �� �� ��������, �� ������
	������������ �� � ����� MFC. �������� ����� �������������
	������� CPaintDC:
	1. �������� ������� CPaintDC.
	2. ��������� �� ������� CPaintDC.
	3. ���������� ������� CPaintDC.
	����������� CPaintDC �������� ������� BeginPaint( ) �
	���������� ����������� DC ��� ���������. ���������� ��������
	EndPaint( )
	*/

	// ����� ��������� ������ (������ ��������) � ������������
	//   ����� ���� (������ � ������ ���������)
	PaintDC.TextOut(0, 0, "����� � ������ ���������");

	// ����� ��������� ������ (������ ��������) � ������������
	//   ����� ���� (������ � ������ ���������). ����� �������
	//   ������ �������� ���� �������� (�������) � ���� ����
	//   (������). ����� ������ ������ ����������������� �������
	//   �������� ��������� ����������. ����� ������ RGB(0, 255, 0)
	//   ������ ������ �����, ������������ ���� - ������ �����
	//   ���������� �������� ������� ������������, ������ - �������
	//   � ������ - �����
	oldColor = PaintDC.SetTextColor(RGB(0, 255, 0));
	oldBkColor = PaintDC.SetBkColor(RGB(0, 0, 0));
	PaintDC.TextOut(250, 0, "����� � ���������� �����");
	PaintDC.SetTextColor(oldColor);
	PaintDC.SetBkColor(oldBkColor);

	// ��������� �����: ������� ��������� ���������� �����
	//   (������������ ������� ���� � ���), � ����� - ��������
	//   �����. ����� �������� ������ �������� ���� �� �������
	//   ����. � ������� MoveTo( ) (125, 50) - ����� �������
	//   ������� � ����. ������� LineTo( ) ������ ����� �� �������
	//   ������� �� ����� (175, 100)
	PaintDC.TextOut(50, 30, "������ ������ ����� � ����");
	PaintDC.MoveTo(125, 50); PaintDC.LineTo(175, 100);

	// ��������� �������: ������� ��������� ���������� �����
	//   (������������ ������� ���� � ���), � ����� - ��������
	//   ������. � ������� Ellipse( ) (100, 140)  � (200, 240) - 
	//   ���������� ������ �������� � ������� ������� �����
	//   ��������������, � ������� ������ ������. ������ ��������
	//   ������������ �����, � ���������� ������� �������
	//   ������������� ����� ������ (�������). ����� ���������
	//   ������ ����� �����������������
	PaintDC.TextOut(50, 120, "������ ������ ������� � ����");
	// ������� ������� �����
	NewBrush.CreateSolidBrush(RGB(255, 0, 0));
	// �������� �� � ��������
	OldBrush = PaintDC.SelectObject(&NewBrush);
	PaintDC.Ellipse(100, 140, 200, 240);
	// ������� ����� �����
	NewBrush.DeleteObject();
	// ��������������� ������ �����
	PaintDC.SelectObject(OldBrush);

	// ��������� ��������������: ������� ��������� ����������
	//   �����, � ����� - �������� �������������. ����� ����������
	//   �������������� �������� ��������� ���� ��� ���������
	//   ��������������. � ������� Rectangle( ) (370, 140)  �
	//   (470, 200) - ���������� ������ �������� � ������� �������
	//   ����� ��������������. ������������� ������������� �������
	//   ������. ����� ��������� ������ ���� �����������������
	PaintDC.TextOut(300, 120,
		"������ ������ �������������� � ����");
	// ������� ����� ����: ��������, �������� 1, �������� �����
	NewPen.CreatePen(PS_DOT, 1, RGB(255, 0, 0));
	// �������� ��� � ��������
	OldPen = PaintDC.SelectObject(&NewPen);
	PaintDC.Rectangle(370, 140, 470, 200);
	// ������� ����� ����
	NewPen.DeleteObject();
	// ��������������� ������ ����
	PaintDC.SelectObject(OldPen);

	return afx_msg void();
}
