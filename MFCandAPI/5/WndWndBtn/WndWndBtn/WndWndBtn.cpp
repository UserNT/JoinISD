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
	hWnd = CreateWindow("WndWndBtnAPI", "Приложение WndWndBtn (Win32API) с кнопками и дочерним окном", WS_VISIBLE | WS_OVERLAPPEDWINDOW,
						CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
	if (!hWnd)
		return FALSE;
	hWnd1 = CreateWindow("BUTTON", "Новое окно", WS_VISIBLE | WS_CHILD, 210,20, 80,
							20, hWnd, reinterpret_cast<HMENU>(BTN1), hInstance, NULL);
	if (!hWnd1)
	{
		MessageBox(NULL, "Кнопка \"Новое окно\" не создана", "Ошибка 1", MB_OK);
		exit(1);
	}

	hWnd2 = CreateWindow("BUTTON", "Выход", WS_VISIBLE | WS_CHILD, 210, 50, 80,
		20, hWnd, reinterpret_cast<HMENU>(BTN2), hInstance, NULL);
	if (!hWnd1)
	{
		MessageBox(NULL, "Кнопка \"Выход\" не создана", "Ошибка 2", MB_OK);
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
			MessageBox(NULL, "Контекст устройства не получен", "Ошибка 3", MB_OK);
			exit(3);
		}
		if (!TextOut(hDC, 130, 0, "Обработка сообщения WM_PAINT", 28))
		{
			MessageBox(NULL, "Неверное использование TextOut", "Ошибка 4", MB_OK);
			exit(4);
		}
		if (!EndPaint(hwnd, &ps))
		{
			MessageBox(NULL, "Контекст устройства не освобожден", "Ошибка 5", MB_OK);
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
			// Звуковой сигнал
			if (!MessageBeep(MB_OK))
			{
				MessageBox(NULL, "Ошибка MessageBeep",
					"Ошибка 6", MB_OK);
				exit(6);
			}
			// Дескриптор дочернего окна
			HWND    hWnd3;
			// Создание дочернего окна
			hWnd3 = CreateWindow(
				// Имя зарегистрированного класса
				"WndAPI",
				// Заголовок окна
				"Дочернее окно",
				// Стиль окна
				WS_VISIBLE | WS_OVERLAPPEDWINDOW,
				// Горизонтальная координата левого верхнего
				//   угла окна
				CW_USEDEFAULT,
				// Вертикальная координата левого верхнего
				//   угла окна
				CW_USEDEFAULT,
				// Ширина окна
				CW_USEDEFAULT,
				// Высота окна
				CW_USEDEFAULT,
				hWnd,           // Дескриптор родительского
								//   окна
				NULL,           // Дескриптор меню окна
				hInst,          // Дескриптор экземпляра
								//   приложения
				NULL);         // Указатель на дополнительные
							   //   данные окна
			if (!hWnd3)
			{
				MessageBox(NULL, "Дочернее окно не создано",
					"Ошибка 7", MB_OK);
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

LRESULT CALLBACK WndProc1(          // Возвращает результат
									//   обработки сообщения,
									//   зависящий от посланного
									//   сообщения: 0 - успех
	HWND                hwnd,       // Дескриптор созданного окна
	UINT                message,    // Номер сообщения
	WPARAM              wParam,     // Дополнительная информация о 
	LPARAM              lParam)    //   сообщении, зависящая от
								   //   типа сообщения (wParam,
								   //   lParam)
{

	// Обработчик сообщений - в данном случае приложение явно отвечает
	//   только на сообщение WM_PAINT, все остальные сообщения
	//   передаются в DefWindowProc( ) - функцию, управляющую
	//   поведением окна по умолчанию
	switch (message)
	{
	case WM_PAINT:

		// Дескриптор контекста устройства
		HDC             hDC;
		// Указатель на структуру с информацией для приложения
		//   о клиентской области окна
		PAINTSTRUCT     ps;
		// Получение контекста устройства
		hDC = BeginPaint(hwnd, &ps);
		if (!hDC)
		{
			MessageBox(NULL, "Контекст устройства не получен",
				"Ошибка 8", MB_OK);
			exit(8);
		}
		// Вывод заданного текста
		if (!TextOut(hDC, 130, 0,
			"Обработка сообщения WM_PAINT в дочернем окне", 44))
		{
			MessageBox(NULL, "Неверное использование TextOut",
				"Ошибка 9", MB_OK);
			exit(9);
		}
		// Освобождение контекста устройства
		if (!EndPaint(hwnd, &ps))
		{
			MessageBox(NULL, "Контекст устройства не освобожден",
				"Ошибка 10", MB_OK);
			exit(10);
		}
		break;

	default:

		// Обработка сообщения по умолчанию
		return DefWindowProc(hwnd, message, wParam, lParam);

	}

	return 0;
}