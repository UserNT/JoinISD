#pragma once
/*
����               : FrameWnd.hpp

������             : ������������ Windows-���������� �� ������
���������� ������� MFC � ����� ����������
�������, ������������ CheckBox

����������         : ���������� ������ "FrameWnd",
������������ �� ������ "CFrameWnd"
���������� ������� MFC (��������� ���������
�������� ����)

Microsoft Visual Studio C++ .NET 2005
*/

// �������������� ����������� ������������� ����������� �������
//   �����
#ifndef _FrameWnd_h
#define _FrameWnd_h

// ���������� ������
class FrameWnd : public CFrameWnd
{
	// ������

private:

	// ����������, ��������� � CheckBox
	bool            m_BoolFirst;// ��� ���������
	int             m_Second;   // ��� ��������� 

								// ������

public:

	// ����������� ��������� (������������� CheckBox)
	FrameWnd(void);

protected:

	// ��������� �������, �������������� ���������
	// ��������� ������� ���� | �����
	afx_msg void OnMenuFileExit(void);
	// ��������� ������� ���������� ������ | ������
	afx_msg void OnMenuCheckbox3State(void);

	// ���������� ������� ���������
	DECLARE_MESSAGE_MAP();
};

#endif

