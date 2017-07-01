/*
����               : UsgMenu.cpp

������             : ���������� Win32API � ��������������
����������� ������� API-SDK (������������,
���� � ������� �������)

Microsoft Visual Studio C++ .NET 2005
*/

// ���������������� ������������ ����
#include "stdafx.h"

#include "resource.h"               // �������������� ��������

// ��������� ������������ �������
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam,
	LPARAM lParam);
BOOL InitApplication(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow);

// ��������� �� ��� ��������������� ������
LPCSTR                  szClassName = "UsgMenuAPI";
// ��������� �� ��������� ���� ����������
LPCSTR                  szTitle = "Win32API: ����, ������������ � "
"���������� ������ ���������";

// ��������� ���������
// �������
int                     PenWidth = 1;
// RGB-����
COLORREF                PenRGB = RGB(255, 0, 0);
// ����� - �������� 
int                     PenStyle = PS_SOLID;

// ���������� �������� ����
HWND                    hWnd;

// ****************************************************************
// ������� ������� ����������
int WINAPI WinMain(                // ���������� TRUE ��� ������
								   // ���������� ������� ����������    
	HINSTANCE           hInstance,
	// ���������� ���������� ���������� ����� ����������. �
	//   Win32API ���� �������� ������ ����� NULL � ��������
	//   ������������� ��� ������������� � �������� ���� ���������.
	//   ������� ��� � ���, ��� ������ 32-��������� ����������
	//   ����������� � ����������� �������� ������������, �
	//   �������, �����������, ��� ������� ����� ��� ������ 
	//   ����������
	HINSTANCE           hPrevInstance,
	// ��������� �� ��������� ������, ������� ����� �
	//   ��������������� ����� ���������� ������ �� �������
	//   "Properties" ������������ ���� ������� � �������� "Program
	//   arguments" ������� "Debugging"
	LPSTR               lpCmdLine,
	// ����� ���������� ����������� �������� ���� ���������� -
	//   ����� ������ �������� �������� �������� SW_SHOWNORMAL (1),
	//   ��� ������������� ����������� ���� � ���������� ����
	int                 nCmdShow)
{
	// �������������� ���������� - �������������� ������ ������
	//   ���� � ������������ ���
	if (!InitApplication(hInstance))
		return FALSE;

	// ��������� �������� ���������� - ������� � ���������� �������
	//   ���� ���������� � ���� � ��������
	if (!InitInstance(hInstance, nCmdShow))
		return FALSE;

	// �������� �������������
	HACCEL              hAccelTable;
	hAccelTable = LoadAccelerators(hInstance,
		reinterpret_cast< LPCTSTR >(IDR_MEINFRAME));
	MSG                 msg;        // ��� ���������� ���������
									// ����������� ���� ��������� ���������
	while (GetMessage(&msg, NULL, 0, 0))
	{
		// TranslateAccelerator( ) ����� ������ ��� �������������
		//   �������������
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return static_cast< int >(msg.wParam);
}


// ****************************************************************
// ����������� ������ �������� ����
BOOL InitApplication(               // ���������� TRUE ��� ��������
									//   ����������
									// ���������� (���������� �����), ������������� � �������
									//   �����������
	HINSTANCE           hInstance)
{
	// �������� � �������������� ������
	WNDCLASS            wc;

	// ��������� ��������� ������ �������� ����
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = static_cast< WNDPROC >(WndProc);
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_ASTERISK);
	wc.hCursor = LoadCursor(NULL, IDC_CROSS);
	wc.hbrBackground =
		reinterpret_cast< HBRUSH >(COLOR_WINDOW + 1);
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MEINFRAME);
	wc.lpszClassName = szClassName;

	// ������������ ����� �������� ����
	return RegisterClass(&wc);
}

// ****************************************************************
// �������� �������� ���� ���������� � �������� � ����
BOOL InitInstance(                  // ���������� TRUE ��� ������
									// ���������� �������� ���������� 
	HINSTANCE           hInstance,
	// ����� ����������� �������� ���� - ���������� � ����� ����
	//   ����� ���������� ���� ����������
	int                 nCmdShow)
{
	// �������� �������� ����
	hWnd = CreateWindow(
		// ��������� �� ��� ������������������� ������
		szClassName,
		// ��������� �� ��������� ����
		szTitle,
		WS_OVERLAPPEDWINDOW,        // ����� ����
									// �������������� ���������� ������ �������� ���� ����
									//   (������������ ������������ ��������)
		CW_USEDEFAULT,
		// ������������ ���������� ������ �������� ���� ����
		//   (������������ ������������ ��������)
		CW_USEDEFAULT,
		CW_USEDEFAULT,              // ������ ���� (������������
									//   ������������ ��������)
		CW_USEDEFAULT,              // ������ ���� (������������
									//   ������������ ��������)
		NULL,                       // ���������� �������������
									//   ���� (��� ���)
		NULL,                       // ���������� ���� ����
		hInstance,                  // ���������� ����������
									//   ����������
		NULL);                     // ��������� �� ��������������
								   //   ������ ���� (�� ���)
	if (!hWnd)
		return FALSE;

	// �������� ����: �������� � Windows ���������� (nCmdShow) �
	//   ���, � ����� ���� ���������� ���������� ����
	if (ShowWindow(hWnd, nCmdShow))
		return FALSE;

	// ������������ ����: ��� ����������� ���� ������� ������������
	//   Windows ������� ���� ��������� WM_PAINT
	if (!UpdateWindow(hWnd))
		return FALSE;

	return TRUE;
}

// ****************************************************************
// ������� ��������� �������� ����
// �������� ��������� ��������� � ������������� ������������ ���
LRESULT CALLBACK WndProc(           // ���������� ���������
									//   ��������� ���������,
									//   ��������� �� ����������
									//   ���������: 0 - �����
	HWND                hWnd,       // ���������� ���������� ����
	UINT                message,    // ����� ���������
	WPARAM              wParam,     // �������������� ���������� � 
	LPARAM              lParam)    //   ���������, ��������� ��
								   //   ���� ��������� (wParam,
								   //   lParam))
{
	// ���������� ��������� ����������
	HDC                 hDC;
	// ��������� �� ��������� � ����������� ��� ���������� �
	//   ���������� ������� ����
	PAINTSTRUCT         ps;

	// ���������� ��������� - � ������ ������ ���������� ����
	//   �������� ������ �� ��������� WM_DESTROY, WM_PAINT �
	//   WM_COMMAND ��� ������ ������ ����, ��� ��������� ���������
	//   ���������� � DefWindowProc( ) - �������, �����������
	//   ���������� ���� �� ���������. ��������� ���������
	//   WM_DESTROY � WM_PAINT �������� ����������� � �������
	//   FrameWnd
	switch (message)
	{
		// ����� � ����
	case WM_PAINT:

		// ��������� ��������� ����������
		hDC = BeginPaint(hWnd, &ps);
		if (!hDC)
		{
			MessageBox(NULL, "�������� ���������� �� �������",
				"������ 1", MB_OK);
			exit(1);
		}
		// ���������� ������ ���������
		HPEN            hPen;
		// �������� ������ ���������
		hPen = CreatePen(PenStyle, PenWidth, PenRGB);
		if (!hPen)
		{
			MessageBox(NULL, "�������� ������������� "
				"CreatePen", "������ 2", MB_OK);
			exit(2);
		}
		// ���������� ������� ���������
		HPEN            hOldPen;
		// ��������� ��� � ��������
		hOldPen = static_cast< HPEN >(SelectObject(hDC, hPen));
		if (!hOldPen)
		{
			MessageBox(NULL, "�������� ������������� "
				"SelectObject", "������ 3", MB_OK);
			exit(3);
		}
		// ��������� ���� �����
		if (!MoveToEx(hDC, 30, 30, NULL))
		{
			MessageBox(NULL, "�������� ������������� MoveToEx",
				"������ 4", MB_OK);
			exit(4);
		}
		if (!LineTo(hDC, 30, 300))
		{
			MessageBox(NULL, "�������� ������������� LineTo",
				"������ 5", MB_OK);
			exit(5);
		}
		if (!LineTo(hDC, 450, 300))
		{
			MessageBox(NULL, "�������� ������������� LineTo",
				"������ 6", MB_OK);
			exit(6);
		}
		// �������� ������ ���������
		if (!DeleteObject(hPen))
		{
			MessageBox(NULL, "�������� ������������� "
				"DeleteObject", "������ 7", MB_OK);
			exit(7);
		}
		// �������������� ������� ���������
		if (!SelectObject(hDC, hOldPen))
		{
			MessageBox(NULL, "�������� ������������� "
				"SelectObject", "������ 8", MB_OK);
			exit(8);
		}
		// ������������ ��������� ����������
		if (!EndPaint(hWnd, &ps))
		{
			MessageBox(NULL, "�������� ���������� �� ����������",
				"������ 8", MB_OK);
			exit(8);
		}
		break;

		// ��������� ������ ����
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{

		case ID_FILE_EXIT:        // ������� ������� "����-�����"

								  // ��������� �������, ��� ������ ������ �
								  //   ���������� ����������: 0 - ��� ����������.
								  //   ����� ���� ������� ������ ������������ � �����
								  //   �� ����������� ��������� WM_DESTROY 
			PostQuitMessage(0);
			// �������� ������
			MessageBeep(MB_OK);
			break;

			// ������� ������� "����� ���������-��������"
		case ID_PENSTYLE_SOLID:

			PenStyle = PS_SOLID;
			// ����������� ���������� ������� ����
			InvalidateRect(hWnd, 0, 0);
			break;

			// ������� ������� "����� ���������-�������"
		case ID_PENSTYLE_DASH:

			PenStyle = PS_DASH;
			// ����������� ���������� ������� ����
			InvalidateRect(hWnd, 0, 0);
			break;

			// ������� ������� "����� ���������-��������"                            
		case ID_PENSTYLE_DOT:

			PenStyle = PS_DOT;
			// ����������� ���������� ������� ����
			InvalidateRect(hWnd, 0, 0);
			break;

		}
	}
	break;

	case WM_DESTROY:

		// ��������� �������, ��� ������ ������ � ����������
		//   ����������: 0 - ��� ����������. ����� ���� �������
		//   ������ ������������ � ����� �� �����������
		//   ��������� WM_DESTROY 
		PostQuitMessage(0);
		break;

	default:

		// ��������� ��������� �� ���������
		return DefWindowProc(hWnd, message, wParam, lParam);

	}

	return 0;
}
