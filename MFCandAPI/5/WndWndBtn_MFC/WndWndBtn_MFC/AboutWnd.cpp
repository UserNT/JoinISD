#include "StdAfx.h"
#include "AboutWnd.h"


BEGIN_MESSAGE_MAP(AboutWnd, CFrameWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()

afx_msg void AboutWnd::OnPaint()
{
	CPaintDC PaintDC(this);
	
	CBrush  NewBrush, *OldBrush;
	COLORREF oldColor;

	NewBrush.CreateSolidBrush(RGB(48, 213, 200));
	OldBrush = PaintDC.SelectObject(&NewBrush);

	oldColor = PaintDC.SetTextColor(RGB(148, 0, 211));
	PaintDC.TextOut(100,20, "Îëå÷êà ");
	PaintDC.SetTextColor(RGB(255, 255, 0));
	PaintDC.TextOut(160, 20, "ËÓ×ØÅ");
	PaintDC.SetTextColor(RGB(0, 0, 255));
	PaintDC.TextOut(210, 20, "ÂÑÅÕ !!!");

	PaintDC.SetTextColor(oldColor);

	NewBrush.DeleteObject();
	PaintDC.SelectObject(OldBrush);

	return afx_msg void();
}
