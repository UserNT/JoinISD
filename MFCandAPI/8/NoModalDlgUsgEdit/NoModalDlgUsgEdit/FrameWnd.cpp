/*
����               : FrameWnd.cpp

������             : ������������ �������� Windows-���������� ��
������ ���������� ������� MFC (������� -
������� ������ + ������������ ��������)

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
	ON_COMMAND(ID_EXIT, OnMenuExit)
	ON_COMMAND(ID_DIALOG_EDIT, OnMenuDialog)
END_MESSAGE_MAP()

// ����������� ��������� (������������� ���� ��������������)
FrameWnd::FrameWnd(void)
{
	// ��� ������ ������������� ���������
	e1 = "��������";
}

// ��������� ������� "�����"
afx_msg void FrameWnd::OnMenuExit(void)
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

// ��������� ������� "�����������_������"
afx_msg void FrameWnd::OnMenuDialog(void)
{
	// ��������� ������ ���� ������������ ������� � ������������
	//   ������
	Dialog              *pDlg = new Dialog;
	ASSERT_VALID(pDlg);           // ��������� ������ ����������

								  // �������� ����� ��� �������� ��������������
	pDlg->e1 = e1;

	// ������� ����������� ���� �������
	if (!pDlg->Create())
	{
		TRACE0("\n ������ 4 - ����������� ���� ������� "
			"�� ������� \n");
		exit(4);
	}

	// ����������� ���� (��������� ��������� WM_PAINT)
	CWnd::Invalidate();

	return afx_msg void();
}
