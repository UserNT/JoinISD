/*
����               : MainThread.cpp

������             : ������������ ������� Windows-���������� ��
������ ���������� ������� MFC (������ -
��������� ������ � �������������)

����������         : ���������� ������ "MainThread",
������������ �� ������ "CWinApp" ����������
������� MFC (������������� ���������� �����
��������)

Microsoft Visual Studio C++ .NET 2005
*/

#include "StdAfx.h"                 // ���������������� ����
#include "MainThread.h"           // ���������� ������ MainThread
#include "FrameWnd.h"             // ���������� ������ FrameWnd
// �������������� �������� (��������� ���������� ��������)
#include "resource.h"

// ��������������� ����������� ������� ��� ������������� ����������
//   ����� ��������
BOOL MainThread::InitInstance(void)
{
	// ��������� �� ����� ����
	FrameWnd            *pFrame;

	// ���������� ������ ���� � ������������ ������
	pFrame = new FrameWnd;
	ASSERT_VALID(pFrame);         // ��������� ������ ����������

								  // �������� ��������, ����������� ������ ���� � �������� ����
	BOOL                rc = pFrame->LoadFrame(IDR_MAINFRAME);
	if (!rc)
	{
		TRACE0("\n ������ 1. ����� LoadFrame �������� � "
			"������� \n");
		exit(1);
	}

	// ����������� ����
	pFrame->ShowWindow(SW_SHOW);
	// ���������� ���� (���������� WM_PAINT)
	pFrame->UpdateWindow();

	// ��������� ����� ������ ������� ����� ����������
	this->m_pMainWnd = pFrame;

	return TRUE;
}
