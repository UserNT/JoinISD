/*
����               : FrameWnd.cpp

������             : ���������� �� ������ ���������� ������� MFC
(������� - Bitmap, Dialog, Menu � String
Table)

����������         : ���������� ������ "FrameWnd", ������������
�� ������ "CFrameWnd" ���������� �������
MFC (��������� ��������� �������� ����)

Microsoft Visual Studio C++ .NET 2005
*/

#include "StdAfx.h"                 // ���������������� ����
#include "FrameWnd.h"             // ���������� ������ FrameWnd
#include "Dialog.h"               // ���������� ������ Dialog
// �������������� �������� (��������� ���������� ��������)
#include "resource.h"

// ����������� ������� ���������
BEGIN_MESSAGE_MAP(FrameWnd, CFrameWnd)
	ON_COMMAND(ID_FILE_EXIT, OnMenuFileExit)
	ON_COMMAND(ID_BITMAP_BUTTONS, OnMenuBitmapButtons)
END_MESSAGE_MAP()

// ��������� ������� ���� | �����
afx_msg void FrameWnd::OnMenuFileExit(void)
{
	BOOL                rc = DestroyWindow();
	if (!rc)
	{
		TRACE0("\n ������ 2. ���� �� ���� ��������� \n");
		exit(2);
	}

	return afx_msg void();
}

// ��������� ������� ��������� ������ | ������
afx_msg void FrameWnd::OnMenuBitmapButtons(void)
{
	// ������� ������ ������� - ������������� ����������
	//   ������� �����������
	Dialog              Dlg(this);

	// ��������� ��������� ���������� ���� - ��� �����
	//   ������������� ������� ����� ������� OK ��� Cancel
	Dlg.DoModal();

	return afx_msg void();
}
