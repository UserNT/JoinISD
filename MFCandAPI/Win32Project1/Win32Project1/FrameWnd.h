#pragma once
/*
����               : FrameWnd.hpp

������             : ������������ �������� Windows-����������
�� ������ ���������� ������� MFC,
������������ ����� � ������� ����

����������         : ���������� ������ "FrameWnd", ������������
�� ������ "CFrameWnd" ���������� �������
MFC (��������� ��������� �������� ����)

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

protected:

	// ��� ����� ���������� �������� �������, ��������������
	//   ��������� WM_PAINT
	afx_msg void OnPaint(void);

	// ���������� ������� ���������
	DECLARE_MESSAGE_MAP();
	/*
	���������� ������� MFC ������������� ������������ ��������������
	���������� switch, ������������ � �������������� Windows-
	����������� ��� ��������� ���������, ���������� ����. �����������
	��������� � �� ������������ ����� ���� ���������� ����� �������,
	���, ����� ��������� ��������� � ������� ���������, �������������
	���������� ��������������� ����������. ���������� ����� �����������
	�������� �� ������� ����� (��� �������) ��������� (message map).
	����� ��������� ������������ ����� �������� ��������� ���������
	� ������ Windows � ����, ������������� � ������ ������� ����������,
	�������������� �� ���� MFC. ����� ����� ����������� ���������
	Windows, ��������� ��������� ����������, � ����� ������� ����,
	������ ������� ������������, ������������� ���������� � ������
	������� ��������������� �������, ������� �� ������������. ���
	������������� ����� ����� ��������� ����������� �� �������� �
	������������ ��������� �++, �� ����� �������������� ������������,
	����������� ��� ���. ������ �����, ������� ����� ��������
	���������, ������ ����� ���� ����� ���������, ����� �����
	����������� ��������������� ������� ������������ ���������. ���
	���� ������� ����� �����, ��� ����� ��������� ������ ������������
	��� ����� ���� ������� ��� ���������� ������. ��� ����� �� �����
	����������� ������ �����.
	��� ����������� ����� ��������� ������������ ��� �������:
	BEGIN_MESSAGE_MAP, END_MESSAGE_MAP  � DECLARE_MESSAGE_MAP. ������
	DECLARE_MESSAGE_MAP ������������� � ����� ���������� ������,
	������������� ����� ���������, ��� ��� ���� �������� ����.
	*/
};

#endif
