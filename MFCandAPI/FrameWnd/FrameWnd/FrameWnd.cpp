#include"stdafx.h"
//#include"afxwin.h"

LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam,
	LPARAM lParam);
BOOL InitApplication( HINSTANCE hInstance );
BOOL InitInstance( HINSTANCE hInstance, int nCmdShow);



LPCWSTR szClassName = L"FrameWndAPI";
LPCWSTR szTitle = L"Windows aplication";

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	if (!hPrevInstance)
	{
		if (!InitApplication(hInstance))
			return FALSE;
	}

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
	wc.lpszClassName = szClassName;

	return RegisterClass(&wc);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;

	
	hWnd = CreateWindow(szClassName, szTitle, WS_OVERLAPPEDWINDOW,0 , 0, 900, 800, NULL, NULL, hInstance, NULL);
	
	if (!hWnd)
		return FALSE;
	
	if (ShowWindow(hWnd, nCmdShow))
		return FALSE;

	if (!UpdateWindow(hWnd))
		return FALSE;
	return TRUE;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hDc;

	PAINTSTRUCT ps;	

	switch (message)
	{
	case WM_PAINT:
		COLORREF oldColor, oldBkColor;
		HBRUSH hNewBrush, hOldBrush;
		HPEN hNewPen, hOldPen;

		hDc = BeginPaint(hwnd, &ps);

		if (!hDc)
		{
			MessageBox(NULL, L"�������� ���������� �� ��������", L"������ 1", MB_OK);
				exit(1);
		}
		oldColor = SetTextColor(hDc, RGB(0, 255, 0));

		if (oldColor == CLR_INVALID)
		{
			MessageBox(NULL, L"������ SetTextColor", L"������ 2", MB_OK);
			exit(2);
		}

		oldBkColor = SetBkColor(hDc, RGB(0, 0, 0));


		if (oldBkColor == CLR_INVALID)
		{
			MessageBox(NULL, L"������ SetBkColor", L"������ 3", MB_OK);
			exit(3);
		}

		if (!TextOut(hDc, 300, 0, L"������ ������ ������", 21))
		{
			MessageBox(NULL, L"�������� ������������� TextOut", L"������ 4", MB_OK);
			exit(4);
		}

		SetTextColor(hDc, oldColor);
		SetBkColor(hDc, oldBkColor);

		TextOut(hDc, 300, 50, L"������ ��������� �����", 23);

		if(!MoveToEx(hDc, 300, 70, NULL))
		{
			MessageBox(NULL, L"�������� ������������� MoveToEx", L"������ 5", MB_OK);
			exit(5);
		}
		if (!LineTo(hDc, 500, 150))
		{
			MessageBox(NULL, L"�������� ������������� LineTo", L"������ 6", MB_OK);
			exit(6);
		}
		TextOut(hDc, 300, 160, L"������ ��������� �������", 25);

		hNewBrush = CreateSolidBrush(RGB(255, 0, 0));

		if (!hNewBrush)
		{
			MessageBox(NULL, L"�������� ������������� CreateSolidBrush", L"������ 7", MB_OK);
			exit(7);
		}

 		hOldBrush = static_cast<HBRUSH>(SelectObject(hDc, hNewBrush));

		if (!hOldBrush)
		{
			MessageBox(NULL, L"�������� ������������� SelectObject", L"������ 8", MB_OK);
			exit(8);
		}

		if (!Ellipse(hDc, 300, 200, 600, 300))
		{
			MessageBox(NULL, L"�������� ������������� Ellipse", L"������ 9", MB_OK);
			exit(9);
		}

		if (!DeleteObject(hNewBrush))
		{
			MessageBox(NULL, L"�������� ������������� DeleteObject", L"������ 10", MB_OK);
			exit(10);
		}
		SelectObject(hDc, hOldBrush);

		TextOut(hDc, 300, 350, L"������ ��������� ��������������", 30);

		hNewPen = CreatePen(PS_DASHDOT, 1, RGB(0, 0, 255));
		
		if(!hNewPen)
		{
			MessageBox(NULL, L"�������� ������������� CreatePen", L"������ 11", MB_OK);
			exit(11);
		}
		hOldPen = static_cast<HPEN>(SelectObject(hDc, hNewPen));

		if(!Rectangle(hDc, 300, 400, 600, 500))
		{
			MessageBox(NULL, L"�������� ������������� Rectangle", L"������ 12", MB_OK);
			exit(12);
		}
		DeleteObject(hNewPen);


		SelectObject(hDc, hOldPen);

		POINT pts[3];
		pts[0].x = 450;
		pts[0].y = 550;
		pts[1].x = 600;
		pts[1].y = 700;
		pts[2].x = 300;
		pts[2].y = 700;

		Polygon(hDc, pts, 3);

		if (!EndPaint(hwnd, &ps))
		{
			MessageBox(NULL, L"������� ���������� �� ����������", L"������ 13", MB_OK);
			exit(13);
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;	
}