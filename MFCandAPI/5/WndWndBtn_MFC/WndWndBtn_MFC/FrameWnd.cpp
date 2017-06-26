#include "StdAfx.h"
#include "FrameWnd.h"
#include "AboutWnd.h"

#define IDC_BTNWND 100              // Кнопка "Окно"
#define IDC_BTNEXIT 101             // Кнопка "Выход"
#define IDC_BTNABOUT 102

// Определение таблицы сообщений
BEGIN_MESSAGE_MAP(FrameWnd, CFrameWnd)
	ON_COMMAND(IDC_BTNWND, OnBtnWndClick)
	ON_COMMAND(IDC_BTNEXIT, OnBtnExitClick)
	ON_COMMAND(IDC_BTNABOUT, OnBtnAboutClick)
	ON_WM_PAINT()
END_MESSAGE_MAP()

FrameWnd::FrameWnd()
{
	m_pBtnExit = 0;
	m_pBtnWnd = 0;
	m_pBtnAbout = 0;
}


FrameWnd::~FrameWnd()
{
	if (m_pBtnWnd)
	{
		delete m_pBtnWnd;
		m_pBtnWnd = 0;
	}
	if (m_pBtnExit)
	{
		delete m_pBtnExit;
		m_pBtnExit = 0;
	}
	if (m_pBtnAbout)
	{
		delete m_pBtnAbout;
		m_pBtnAbout = 0;
	}
}


void FrameWnd::CreateChildControls()
{

	m_pBtnWnd = new CButton;

	ASSERT_VALID(m_pBtnWnd);
	BOOL rc = m_pBtnWnd->Create("Новое окно", WS_VISIBLE | WS_CHILD
		| BS_PUSHBUTTON, CRect(424, 40, 513, 65), this, IDC_BTNWND);
	if (!rc)
	{
		TRACE0("\n Ошибка 2. Кнопка \"Новое окно\" не была"
			" создана \n");
		exit(2);
	}

	m_pBtnExit = new CButton;
	ASSERT_VALID(m_pBtnExit);
	rc = m_pBtnExit->Create("Выход", WS_VISIBLE | WS_CHILD
		| BS_PUSHBUTTON, CRect(424, 8, 513, 33), this, IDC_BTNEXIT);
	if (!rc)
	{
		TRACE0("\n Ошибка 3. Кнопка \"Выход\" не была"
			" создана \n");
		exit(3);
	}

	m_pBtnAbout = new CButton;
	m_pBtnAbout->Create("об ОЛЕЧКЕ", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, CRect(424, 72, 513, 97), this, IDC_BTNABOUT);
	return;
}

afx_msg void FrameWnd::OnPaint()
{
	CPaintDC PaintDC(this);
	PaintDC.TextOut(120, 0, "Обработка сообщения WM_PAINT");

	return afx_msg void();
}

afx_msg void FrameWnd::OnBtnExitClick()
{
	BOOL                rc = MessageBeep(-1);
	if (!rc)
	{
		TRACE0("\n Ошибка 6. Неверное завершение MessageBeep \n");
		exit(6);
	}
	rc = DestroyWindow();
	if (!rc)
	{
		TRACE0("\n Ошибка 7. Окно не было разрушено \n");
		exit(7);
	}

	return afx_msg void();
}

afx_msg void FrameWnd::OnBtnWndClick()
{	
	BOOL                rc = MessageBeep(-1);
	if (!rc)
	{
		TRACE0("\n Ошибка 4. Неверное завершение MessageBeep \n");
		exit(4);
	}

	AfxMessageBox("Запускается новое окно!", MB_YESNO | MB_ICONHAND);

	FrameWnd* pFrame;
	pFrame = new FrameWnd;
	ASSERT_VALID(pFrame);
	rc = pFrame->Create(// Используется предопределенное OS WINDOWS имя оконного
        //   класса
		NULL,
		// Заголовок фрейма окна
		"Это окно было создано по кнопке \"Окно\"",
		// Стиль окна
		WS_SIZEBOX | WS_POPUPWINDOW | WS_DLGFRAME,
		// Местоположение и размеры окна: 20 - левая сторона,
		//   60 - верх, 430 - правая сторона, 190 - низ окна
		CRect(20, 60, 530, 200));
	if (!rc)
	{
		TRACE0("\n Ошибка 5. Фрейм дочернего окна не был "
			"создан \n");
		exit(5);
	}
	pFrame->CreateChildControls();
	// Отображение окна
	pFrame->ShowWindow(SW_SHOW);

	return afx_msg void();
}

afx_msg void FrameWnd::OnBtnAboutClick()
{
	AboutWnd* AbW;

	AbW = new AboutWnd;

	AbW->Create(NULL, "Комплимент!!!", WS_VISIBLE | WS_OVERLAPPEDWINDOW, CRect(20, 60, 530, 200));
	AbW->ShowWindow(SW_SHOW);

	return afx_msg void();
}

