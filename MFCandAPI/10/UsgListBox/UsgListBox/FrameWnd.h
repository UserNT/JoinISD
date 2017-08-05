/*
����               : FrameWnd.hpp

������             : ������������ Windows-���������� �� ������
���������� ������� MFC � ����� ����������
�������, ������������ ������

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

	// ����������, ��������� �� ��������

	// ����� ������
	// ������ ��� ������
	CString         m_Enabled[10];
	// ������ ���������� �������� � "m_Enabled"
	int             m_IxEnbLast;

	// ������ ������
	// ������ ��� ������
	CString         m_Disabled[10];
	// ������ ���������� �������� � "m_Disabled"
	int             m_IxDisLast;

	// ������

public:

	// ����������� ��������� (������������� �������)
	FrameWnd(void);

protected:

	// ��������� �������, �������������� ���������
	// ��������� ������� ���� | �����
	afx_msg void OnMenuFileExit(void);
	// ��������� ������� ������ | ������
	afx_msg void OnMenuListBoxDialog(void);

	// ���������� ������� ���������
	DECLARE_MESSAGE_MAP();
};

#endif
