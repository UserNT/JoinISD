#pragma once
/*
����               : MainThread.hpp

������             : ����� ������ �� ������ ���������� �������
MFC

����������         : ���������� ������ "MainThread",
������������ �� ������ "CWinApp" ����������
������� MFC (������������� ���������� �����
��������)

Microsoft Visual Studio C++ .NET 2005
*/

// �������������� ����������� ������������� ����������� �������
//   �����
#ifndef _MainThread_h
#define _MainThread_h

// ���������� ������
class MainThread : public CWinApp
{
	// ������

public:

	// ������������� ���������� ����� ��������
	virtual BOOL InitInstance(void);
};

#endif

