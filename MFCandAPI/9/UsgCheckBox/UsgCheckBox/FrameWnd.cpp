/*
����               : FrameWnd.cpp

������             : ������������ Windows-���������� �� ������
���������� ������� MFC � ����� ����������
�������, ������������ CheckBox

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
	ON_COMMAND(ID_FILE_EXIT, OnMenuFileExit)
	ON_COMMAND(ID_CHECKBOX_3STATE, OnMenuCheckbox3State)
END_MESSAGE_MAP()

// ����������� ��������� (������������� CheckBox)
FrameWnd::FrameWnd(void)
{
	m_BoolFirst = false;
	m_Second = 2;
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

// ��������� ������� ���������� ������ | ������
afx_msg void FrameWnd::OnMenuCheckbox3State(void)
{
	// ������� ������ ������� - ������������� ����������
	//   �����������
	Dialog              Dlg(this);

	// �������� ��������� CheckBox �� ������ FrameWnd � �����
	//   Dialog
	Dlg.m_bStdChk1 = m_BoolFirst;
	Dlg.m_3StChk2 = m_Second;

	// ��������� ��������� ���������� ���� - ��� �����
	//   ������������� ������� ����� ������� OK ��� Cancel
	int                 DlgResult = static_cast<int>
		(Dlg.DoModal());
	if (DlgResult == IDOK)
	{                               // ����� �� ������� �� ��
									// �������� ��������� CheckBox �� ������ Dialog � �����
									//   FrameWnd
		m_BoolFirst = Dlg.m_bStdChk1;
		m_Second = Dlg.m_3StChk2;
	}

	return afx_msg void();
}

