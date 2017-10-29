/*
����               : MainThread.cpp

������             : ������������ ������� Windows-���������� ��
������ ���������� ������� MFC � �������� �
������� ����, ������������ ���������� �
������� ������

����������         : ���������� ������ "MainThread",
������������ �� ������ "CWinApp" ����������
������� MFC (������������� ���������� �����
��������)

Microsoft Visual Studio C++ .NET 2005
*/

#include "StdAFX.h"                 // ���������������� ����
#include "MainThread.h"           // ���������� ������ MainThread
#include "FrameWnd.h"             // ���������� ������ FrameWnd

// ��������������� ����������� ������� ��� ������������� ����������
//   ����� ��������
BOOL MainThread::InitInstance(void)
{
	// ��������� �� ����� ����
	FrameWnd            *pFrame;

	// ���������� ������ ���� � ������������ ������
	pFrame = new FrameWnd;
	ASSERT_VALID(pFrame);         // ��������� ������ ����������

								  // �������� ���� ����������
	BOOL                rc = pFrame->Create(
		// ������������ ���������������� OS WINDOWS ��� ��������
		//   ������
		NULL,
		// ��������� ������ ����
		"������������ ������������� ���� �������������� � ������ "
		"(MFC)",
		// ����� ����
		WS_SIZEBOX | WS_POPUPWINDOW | WS_DLGFRAME,
		// �������������� � ������� ����: 0 - ����� �������,
		//   0 - ����, 530 - ������ �������, 290 - ��� ����
		CRect(0, 0, 530, 290));
	if (!rc)
	{
		TRACE0("\n ������ 1. ����� ���� �� ��� ������ \n");
		exit(1);
	}

	// �������� ������
	pFrame->CreateChildControls();
	// ����������� ����
	pFrame->ShowWindow(SW_SHOW);

	// ��������� ����� ������ ������� ����� ����������
	this->m_pMainWnd = pFrame;

	return TRUE;
}