/*
����               : MainThread.cpp

������             : ������������ �������� Windows-����������
�� ������ ���������� ������� MFC,
������������ ����� � ������� ����

����������         : ���������� ������ "MainThread",
������������ �� ������ "CWinApp" ����������
������� MFC (������������� ���������� �����
��������)

Microsoft Visual Studio C++ .NET 2005
*/

#include "StdAfx.h"                 // ���������������� ����
#include "MainThread.h"           // ���������� ������ MainThread
#include "FrameWnd.h"             // ���������� ������ FrameWnd

// ��������������� ����������� ������� ��� ������������� ����������
//   ����� ��������
BOOL MainThread::InitInstance(void)
{
	// ��������� �� ����� ����
	FrameWnd            *pFrame;

	// ���������� ������ ���� � ������������ ������ � ����������
	//   ������
	pFrame = new FrameWnd;
	// ��������� ������ ����������
	/*
	������ ASSERT_VALID(������������� ������������)������������
	��� �������� ��������� ���������� �������, ������� ������
	����������� � ������ ����� ���������. ������ ���, �����
	���������� ��������� (� ����� ������ pFrame), ����������
	�������, ����� ��������� �������� 0 (FALSE) ����������
	���������� ����� ��������������� � �� ����� ����� ����������
	���� ���������. � ������ ���� ����������� ��� ������������
	����� (�� ������), ��� ��������� ����� � ����� ������, �
	������� ��������� ������
	*/
	ASSERT_VALID(pFrame);

	
	//�������������� �������
	// �������� ������ ����
	pFrame->Create(
	// ������������ ���������������� OS WINDOWS ��� ��������
	//   ������
	NULL,
	// ��������� ������ ����
	"�������� ������ � ��������� ��������� �� ������ MFC" );

	// ������� �������� � ������������ ������ ����
	pFrame->MoveWindow(
	// ���������� ����� ������� ������
	100,
	// ���������� ������� ������� ������
	200,
	600,                        // ������ ������
	300,                        // ������ �����
	FALSE );                    // ���� �� ����������������

	// ����� ���� �� �����
	pFrame->ShowWindow( 3 );
	// ����������� ����
	pFrame->UpdateWindow( );
	

	// �������� � ����������� �� ������ ���� ���������� - 
	//   ���������� �������������� ���� �������������������
	//   ��������� ���������
	//pFrame->Create(
	//	// ������������ ���������������� �� Windows ��� ��������
	//	//   ������
	//	NULL,
	//	// ��������� ������ ����
	//	"�������� �������� �� ������ MFC",
	//	WS_VISIBLE | WS_OVERLAPPEDWINDOW,    // ����� ����
	//										 // �������������� � ������� ����: 100 - ����� �������,
	//										 //   200 - ����, 700 - ������ �������, 500 - ��� ����
	//	CRect(0, 0, 1000, 1000));

	// ��������� ����� ������ ������� ����� ����������
	this->m_pMainWnd = pFrame;

	return TRUE;
}
