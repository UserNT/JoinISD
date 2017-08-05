/*
����               : FrameWnd.cpp

������             : ������������ Windows-���������� �� ������
���������� ������� MFC � ����� ����������
�������, ������������ ������

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
	ON_COMMAND(ID_LISTBOXES_DIALOG, OnMenuListBoxDialog)
END_MESSAGE_MAP()

// ����������� ��������� (������������� �������)
FrameWnd::FrameWnd(void)
{
	// ����� ������
	m_IxEnbLast = 4;
	m_Enabled[0] = "Alpha";
	m_Enabled[1] = "Beta";
	m_Enabled[2] = "Gamma";
	m_Enabled[3] = "Delta";
	m_Enabled[4] = "Omega";

	// ������ ������ (������)
	m_IxDisLast = -1;
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

// ��������� ������� ������ | ������
afx_msg void FrameWnd::OnMenuListBoxDialog(void)
{
	// ������� ������ ������� - ������������� ����������
	//   �����������
	Dialog              Dlg(this);

	// �������� ���������� ��� ������� �� ������ FrameWnd � �����
	//   Dialog
	Dlg.m_Enabled = m_Enabled;
	Dlg.m_IxEnbLast = m_IxEnbLast;
	Dlg.m_Disabled = m_Disabled;
	Dlg.m_IxDisLast = m_IxDisLast;

	// ��������� ��������� ���������� ���� - ��� �����
	//   ������������� ������� ����� ������� OK ��� Cancel
	int                 DlgResult = static_cast<int>
		(Dlg.DoModal());
	if (DlgResult == IDOK)
	{                               // ����� �� ������� �� ��
									// �������� ������� ��������� ��������� ������� �� ������
									//   Dialog � ����� FrameWnd
		m_IxEnbLast = Dlg.m_IxEnbLast;
		m_IxDisLast = Dlg.m_IxDisLast;
	}

	return afx_msg void();
}
