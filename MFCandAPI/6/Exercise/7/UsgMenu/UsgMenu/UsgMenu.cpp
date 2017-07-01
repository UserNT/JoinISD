/*
Файл               : UsgMenu.cpp

Проект             : приложение Win32API с использованием
стандартных функций API-SDK (акселераторы,
меню и горячие клавиши)

Microsoft Visual Studio C++ .NET 2005
*/

// Прекомпилируемый заголовочный файл
#include "stdafx.h"

#include "resource.h"               // Идентификаторы ресурсов

// Прототипы используемых функций
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam,
	LPARAM lParam);
BOOL InitApplication(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow);

// Указатель на имя регистрируемого класса
LPCSTR                  szClassName = "UsgMenuAPI";
// Указатель на заголовок окна приложения
LPCSTR                  szTitle = "Win32API: меню, акселераторы и "
"управление стилем карандаша";

// Параметры карандаша
// Толщина
int                     PenWidth = 1;
// RGB-цвет
COLORREF                PenRGB = RGB(255, 0, 0);
// Стиль - сплошной 
int                     PenStyle = PS_SOLID;

// Дескриптор главного окна
HWND                    hWnd;

// ****************************************************************
// Главная функция приложения
int WINAPI WinMain(                // Возвращает TRUE при успехе
								   // Дескриптор данного приложения    
	HINSTANCE           hInstance,
	// Дескриптор предыдущей запущенной копии приложения. В
	//   Win32API этот параметр всегда равен NULL и оставлен
	//   исключительно для совместимости с версиями ниже четвертой.
	//   Связано это с тем, что каждое 32-разрядное приложение
	//   запускается в собственном адресном пространстве, в
	//   котором, естественно, нет никаких копий или других 
	//   приложений
	HINSTANCE           hPrevInstance,
	// Указатель на командную строку, которую можно в
	//   интегрированной среде разработки задать по команде
	//   "Properties" контекстного меню проекта в элементе "Program
	//   arguments" вкладки "Debugging"
	LPSTR               lpCmdLine,
	// Режим начального отображения главного окна приложения -
	//   после вызова параметр получает значение SW_SHOWNORMAL (1),
	//   что соответствует отображению окна в нормальном виде
	int                 nCmdShow)
{
	// Инициализируем приложение - подготавливаем данные класса
	//   окна и регистрируем его
	if (!InitApplication(hInstance))
		return FALSE;

	// Завершаем создание приложения - создаем и отображаем главное
	//   окно приложения с меню и графикой
	if (!InitInstance(hInstance, nCmdShow))
		return FALSE;

	// Загрузка акселераторов
	HACCEL              hAccelTable;
	hAccelTable = LoadAccelerators(hInstance,
		reinterpret_cast< LPCTSTR >(IDR_MEINFRAME));
	MSG                 msg;        // Для очередного сообщения
									// Стандартный цикл обработки сообщений
	while (GetMessage(&msg, NULL, 0, 0))
	{
		// TranslateAccelerator( ) нужна только при использовании
		//   акселераторов
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return static_cast< int >(msg.wParam);
}


// ****************************************************************
// Регистрация класса главного окна
BOOL InitApplication(               // Возвращает TRUE при успешном
									//   завершении
									// Дескриптор (уникальное число), ассоциируемый с текущим
									//   приложением
	HINSTANCE           hInstance)
{
	// Сведения о регистрируемом классе
	WNDCLASS            wc;

	// Заполняем структуру класса главного окна
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

	// Регистрируем класс главного окна
	return RegisterClass(&wc);
}

// ****************************************************************
// Создание главного окна приложения с графикой и меню
BOOL InitInstance(                  // Возвращает TRUE при успехе
									// Дескриптор текущего приложения 
	HINSTANCE           hInstance,
	// Режим отображения главного окна - определяет в каком виде
	//   будет отображено окно приложения
	int                 nCmdShow)
{
	// Создание главного окна
	hWnd = CreateWindow(
		// Указатель на имя зарегистрированного класса
		szClassName,
		// Указатель на заголовок окна
		szTitle,
		WS_OVERLAPPEDWINDOW,        // Стиль окна
									// Горизонтальная координата левого верхнего угла окна
									//   (используется умалчиваемое значение)
		CW_USEDEFAULT,
		// Вертикальная координата левого верхнего угла окна
		//   (используется умалчиваемое значение)
		CW_USEDEFAULT,
		CW_USEDEFAULT,              // Ширина окна (используется
									//   умалчиваемое значение)
		CW_USEDEFAULT,              // Высота окна (используется
									//   умалчиваемое значение)
		NULL,                       // Дескриптор родительского
									//   окна (его нет)
		NULL,                       // Дескриптор меню окна
		hInstance,                  // Дескриптор экземпляра
									//   приложения
		NULL);                     // Указатель на дополнительные
								   //   данные окна (их нет)
	if (!hWnd)
		return FALSE;

	// Показать окно: передает в Windows информацию (nCmdShow) о
	//   том, в каком виде необходимо отобразить окно
	if (ShowWindow(hWnd, nCmdShow))
		return FALSE;

	// Перерисовать окно: для перерисовки окна функция предписывает
	//   Windows послать окну сообщение WM_PAINT
	if (!UpdateWindow(hWnd))
		return FALSE;

	return TRUE;
}

// ****************************************************************
// Оконная процедура главного окна
// Получает очередное сообщение и индивидуально обрабатывает его
LRESULT CALLBACK WndProc(           // Возвращает результат
									//   обработки сообщения,
									//   зависящий от посланного
									//   сообщения: 0 - успех
	HWND                hWnd,       // Дескриптор созданного окна
	UINT                message,    // Номер сообщения
	WPARAM              wParam,     // Дополнительная информация о 
	LPARAM              lParam)    //   сообщении, зависящая от
								   //   типа сообщения (wParam,
								   //   lParam))
{
	// Дескриптор контекста устройства
	HDC                 hDC;
	// Указатель на структуру с информацией для приложения о
	//   клиентской области окна
	PAINTSTRUCT         ps;

	// Обработчик сообщения - в данном случае приложение явно
	//   отвечает только на сообщения WM_DESTROY, WM_PAINT и
	//   WM_COMMAND при выборе команд меню, все остальные сообщения
	//   передаются в DefWindowProc( ) - функцию, управляющую
	//   поведением окна по умолчанию. Обработка сообщений
	//   WM_DESTROY и WM_PAINT подробно рассмотрена в проекте
	//   FrameWnd
	switch (message)
	{
		// Вывод в окно
	case WM_PAINT:

		// Получение контекста устройства
		hDC = BeginPaint(hWnd, &ps);
		if (!hDC)
		{
			MessageBox(NULL, "Контекст устройства не получен",
				"Ошибка 1", MB_OK);
			exit(1);
		}
		// Дескриптор нового карандаша
		HPEN            hPen;
		// Создание нового карандаша
		hPen = CreatePen(PenStyle, PenWidth, PenRGB);
		if (!hPen)
		{
			MessageBox(NULL, "Неверное использование "
				"CreatePen", "Ошибка 2", MB_OK);
			exit(2);
		}
		// Дескриптор старого карандаша
		HPEN            hOldPen;
		// Включение его в контекст
		hOldPen = static_cast< HPEN >(SelectObject(hDC, hPen));
		if (!hOldPen)
		{
			MessageBox(NULL, "Неверное использование "
				"SelectObject", "Ошибка 3", MB_OK);
			exit(3);
		}
		// Рисование двух линий
		if (!MoveToEx(hDC, 30, 30, NULL))
		{
			MessageBox(NULL, "Неверное использование MoveToEx",
				"Ошибка 4", MB_OK);
			exit(4);
		}
		if (!LineTo(hDC, 30, 300))
		{
			MessageBox(NULL, "Неверное использование LineTo",
				"Ошибка 5", MB_OK);
			exit(5);
		}
		if (!LineTo(hDC, 450, 300))
		{
			MessageBox(NULL, "Неверное использование LineTo",
				"Ошибка 6", MB_OK);
			exit(6);
		}
		// Удаление нового карандаша
		if (!DeleteObject(hPen))
		{
			MessageBox(NULL, "Неверное использование "
				"DeleteObject", "Ошибка 7", MB_OK);
			exit(7);
		}
		// Восстанавление старого карандаша
		if (!SelectObject(hDC, hOldPen))
		{
			MessageBox(NULL, "Неверное использование "
				"SelectObject", "Ошибка 8", MB_OK);
			exit(8);
		}
		// Освобождение контекста устройства
		if (!EndPaint(hWnd, &ps))
		{
			MessageBox(NULL, "Контекст устройства не освобожден",
				"Ошибка 8", MB_OK);
			exit(8);
		}
		break;

		// Обработка команд меню
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{

		case ID_FILE_EXIT:        // Выбрана команда "Файл-Выход"

								  // Указывает системе, что сделан запрос о
								  //   завершении приложения: 0 - код завершения.
								  //   Вызов этой функции обычно используется в ответ
								  //   на поступившее сообщение WM_DESTROY 
			PostQuitMessage(0);
			// Звуковой сигнал
			MessageBeep(MB_OK);
			break;

			// Выбрана команда "Стиль карандаша-Сплошной"
		case ID_PENSTYLE_SOLID:

			PenStyle = PS_SOLID;
			// Перерисовка клиентской области окна
			InvalidateRect(hWnd, 0, 0);
			break;

			// Выбрана команда "Стиль карандаша-Пунктир"
		case ID_PENSTYLE_DASH:

			PenStyle = PS_DASH;
			// Перерисовка клиентской области окна
			InvalidateRect(hWnd, 0, 0);
			break;

			// Выбрана команда "Стиль карандаша-Точечный"                            
		case ID_PENSTYLE_DOT:

			PenStyle = PS_DOT;
			// Перерисовка клиентской области окна
			InvalidateRect(hWnd, 0, 0);
			break;

		}
	}
	break;

	case WM_DESTROY:

		// Указывает системе, что сделан запрос о завершении
		//   приложения: 0 - код завершения. Вызов этой функции
		//   обычно используется в ответ на поступившее
		//   сообщение WM_DESTROY 
		PostQuitMessage(0);
		break;

	default:

		// Обработка сообщения по умолчанию
		return DefWindowProc(hWnd, message, wParam, lParam);

	}

	return 0;
}
