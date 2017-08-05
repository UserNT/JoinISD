/*
����               : FrameWnd.cpp

������             : ������������ Windows-���������� �� ������
���������� ������� MFC � ����� ����������
�������, ������������ ���������
��������������� ������

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
	ON_COMMAND(ID_COMBOBOX_DIALOG, OnMenuComboBoxDialog)
END_MESSAGE_MAP()

// ����������� ��������� (������������� ��������������� �������)
FrameWnd::FrameWnd(void)
{
	// ������� ��������������� ������
	m_List1[0] = "Alpha";
	m_List1[1] = "Beta";
	m_List1[2] = "Gamma";
	m_List1[3] = "Delta";
	m_List1[4] = "Omega";
	m_IxLast1 = 4;

	// �������������� ��������������� ������
	m_List2[0] = "First";
	m_List2[1] = "Second";
	m_List2[2] = "Third";
	m_List2[3] = "Fourth";
	m_IxLast2 = 3;

	// �������������� ������
	m_List3[0] = "Not use MFC";
	m_List3[1] = "Use MFC in a Static Library";
	m_List3[2] = "Use MFC in a Shared DLL";
	m_IxLast3 = 2;
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

// ��������� ������� ���������� | ������
afx_msg void FrameWnd::OnMenuComboBoxDialog(void)
{
	// ������� ������ ������� - ������������� ����������
	//   �����������
	Dialog              Dlg(this);

	// �������� ���������� ��� ��������������� ������� �� ������
	//   FrameWnd � ����� Dialog
	Dlg.m_List1 = m_List1;
	Dlg.m_IxLast1 = m_IxLast1;
	Dlg.m_List2 = m_List2;
	Dlg.m_IxLast2 = m_IxLast2;
	Dlg.m_List3 = m_List3;
	Dlg.m_IxLast3 = m_IxLast3;

	// ��������� ��������� ���������� ���� - ��� �����
	//   ������������� ������� ����� ������� OK ��� Cancel
	int                 DlgResult = static_cast<int>
		(Dlg.DoModal());
	if (DlgResult == IDOK)
	{                               // ����� �� ������� �� ��
									// �������� ��������� �������� ��������������� ������� ��
									//   ������ Dialog � ����� FrameWnd
		m_Str1 = Dlg.m_Str1;
		m_Str2 = Dlg.m_Str2;
		m_Str3 = Dlg.m_Str3;
		// ������������� ��������� ��������
		MessageBox(m_Str1 + "\n" + m_Str2 + "\n" + m_Str3,
			_T("������� ��������"),
			MB_OK | MB_ICONINFORMATION);
	}

	return afx_msg void();
}
