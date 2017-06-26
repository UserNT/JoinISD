#include "StdAfx.h"

BOOL InitApplication(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow);
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProc1(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

HINSTANCE hInst;
HWND hWnd;
HWND hWnd1;
HWND hWnd2;

#define BTN1 1
#define BTN2 2


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	hInst = hInstance;

	if (!InitApplication(hInstance))
		return FALSE;

	if (!InitInstance(hInstance, nCmdShow))
		return FALSE;

	MSG msg;

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return static_cast<int>(msg.wParam);
}

BOOL InitApplication(HINSTANCE hInstance)
{
	WNDCLASS wc;

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = static_cast<WNDPROC>(WndProc);
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_ASTERISK);
	wc.hCursor = LoadCursor(NULL, IDC_CROSS);
	wc.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = "WndWndBtnAPI";

	if (!RegisterClass(&wc))
		return FALSE;

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = static_cast<WNDPROC>(WndProc);
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_ASTERISK);
	wc.hCursor = LoadCursor(NULL, IDC_CROSS);
	wc.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = "WndAPI";

	
		return RegisterClass(&wc);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hWnd = CreateWindow("WndWndBtnAPI", "���������� WndWndBtn (Win32API) � �������� � �������� �����", WS_VISIBLE | WS_OVERLAPPEDWINDOW,
						CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
	if (!hWnd)
		return FALSE;
	hWnd1 = CreateWindow("BUTTON", "����� ����", WS_VISIBLE | WS_CHILD, 210,20, 80,
							20, hWnd, reinterpret_cast<HMENU>(BTN1), hInstance, NULL);
	if (!hWnd1)
	{
		MessageBox(NULL, "������ \"����� ����\" �� �������", "������ 1", MB_OK);
		exit(1);
	}

	hWnd2 = CreateWindow("BUTTON", "�����", WS_VISIBLE | WS_CHILD, 210, 50, 80,
		20, hWnd, reinterpret_cast<HMENU>(BTN2), hInstance, NULL);
	if (!hWnd1)
	{
		MessageBox(NULL, "������ \"�����\" �� �������", "������ 2", MB_OK);
		exit(2);
	}
	return TRUE;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_PAINT:
		HDC hDC;
		PAINTSTRUCT ps;
		hDC = BeginPaint(hwnd, &ps);
		if (!hDC)
		{
			MessageBox(NULL, "�������� ���������� �� �������", "������ 3", MB_OK);
			exit(3);
		}
		if (!TextOut(hDC, 130, 0, "��������� ��������� WM_PAINT", 28))
		{
			MessageBox(NULL, "�������� ������������� TextOut", "������ 4", MB_OK);
			exit(4);
		}
		if (!EndPaint(hwnd, &ps))
		{
			MessageBox(NULL, "�������� ���������� �� ����������", "������ 5", MB_OK);
			exit(5);
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case BTN1:
			// �������� ������
			if (!MessageBeep(MB_OK))
			{
				MessageBox(NULL, "������ MessageBeep",
					"������ 6", MB_OK);
				exit(6);
			}
			// ���������� ��������� ����
			HWND    hWnd3;
			// �������� ��������� ����
			hWnd3 = CreateWindow(
				// ��� ������������������� ������
				"WndAPI",
				// ��������� ����
				"�������� ����",
				// ����� ����
				WS_VISIBLE | WS_OVERLAPPEDWINDOW,
				// �������������� ���������� ������ ��������
				//   ���� ����
				CW_USEDEFAULT,
				// ������������ ���������� ������ ��������
				//   ���� ����
				CW_USEDEFAULT,
				// ������ ����
				CW_USEDEFAULT,
				// ������ ����
				CW_USEDEFAULT,
				hWnd,           // ���������� �������������
								//   ����
				NULL,           // ���������� ���� ����
				hInst,          // ���������� ����������
								//   ����������
				NULL);         // ��������� �� ��������������
							   //   ������ ����
			if (!hWnd3)
			{
				MessageBox(NULL, "�������� ���� �� �������",
					"������ 7", MB_OK);
				exit(7);
			}
			break;
		case BTN2:
			PostQuitMessage(0);
			break;	

		}

	}
	break;

	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}

LRESULT CALLBACK WndProc1(          // ���������� ���������
									//   ��������� ���������,
									//   ��������� �� ����������
									//   ���������: 0 - �����
	HWND                hwnd,       // ���������� ���������� ����
	UINT                message,    // ����� ���������
	WPARAM              wParam,     // �������������� ���������� � 
	LPARAM              lParam)    //   ���������, ��������� ��
								   //   ���� ��������� (wParam,
								   //   lParam)
{

	// ���������� ��������� - � ������ ������ ���������� ���� ��������
	//   ������ �� ��������� WM_PAINT, ��� ��������� ���������
	//   ���������� � DefWindowProc( ) - �������, �����������
	//   ���������� ���� �� ���������
	switch (message)
	{
	case WM_PAINT:

		// ���������� ��������� ����������
		HDC             hDC;
		// ��������� �� ��������� � ����������� ��� ����������
		//   � ���������� ������� ����
		PAINTSTRUCT     ps;
		// ��������� ��������� ����������
		hDC = BeginPaint(hwnd, &ps);
		if (!hDC)
		{
			MessageBox(NULL, "�������� ���������� �� �������",
				"������ 8", MB_OK);
			exit(8);
		}
		// ����� ��������� ������
		if (!TextOut(hDC, 130, 0,
			"��������� ��������� WM_PAINT � �������� ����", 44))
		{
			MessageBox(NULL, "�������� ������������� TextOut",
				"������ 9", MB_OK);
			exit(9);
		}
		// ������������ ��������� ����������
		if (!EndPaint(hwnd, &ps))
		{
			MessageBox(NULL, "�������� ���������� �� ����������",
				"������ 10", MB_OK);
			exit(10);
		}
		break;

	default:

		// ��������� ��������� �� ���������
		return DefWindowProc(hwnd, message, wParam, lParam);

	}

	return 0;
}