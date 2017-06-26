#include "StdAfx.h"
#include "FrameWnd.h"

#define IDC_BTNABOUT 100            // Кнопка "О кнопке"
#define IDC_BTNEXIT  101

BEGIN_MESSAGE_MAP(FrameWnd, CFrameWnd)
	ON_COMMAND(IDC_BTNABOUT, OnBtnAboutClick)
	ON_COMMAND(IDC_BTNEXIT, OnBtnExitClick)
	ON_WM_PAINT()
END_MESSAGE_MAP()

FrameWnd::FrameWnd()
{
	m_pBtnAbout = 0;
	m_pBtnExit = 0;
}


FrameWnd::~FrameWnd()
{
	if (m_pBtnAbout)
	{
		delete m_pBtnAbout;
		m_pBtnAbout = 0;
	}
	if (m_pBtnExit)
	{
		delete m_pBtnExit;
		m_pBtnExit = 0;
	}
}


void FrameWnd::CreateChildControls()
{
	// Размещаем в динамической памяти и создаем кнопку "О кнопке"
	//   (выбрана по умолчанию)
	m_pBtnAbout = new CButton;
	ASSERT_VALID(m_pBtnAbout);    // Обработка ошибки размещения
	BOOL                rc = m_pBtnAbout->Create("О кнопке",
		WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		CRect(424, 40, 513, 65), this, IDC_BTNABOUT);
	if (!rc)
	{
		TRACE0("\n Ошибка 2. Кнопка \"О кнопке\" не была"
			" создана \n");
		exit(2);
	}

	// Размещаем в динамической памяти и создаем кнопку "Выход"
	m_pBtnExit = new CButton;
	ASSERT_VALID(m_pBtnExit);     // Обработка ошибки размещения
	rc = m_pBtnExit->Create("Выход", WS_VISIBLE | WS_CHILD
		| BS_PUSHBUTTON, CRect(424, 8, 513, 33), this,
		IDC_BTNEXIT);
	if (!rc)
	{
		TRACE0("\n Ошибка 3. Кнопка \"Выход\" не была"
			" создана \n");
		exit(3);
	}

	return;
}

afx_msg void FrameWnd::OnPaint(void)
{
	// Создаем объект для рисования и вывода
	CPaintDC            PaintDC(this);

	// Вывод заданного текста (третий аргумент) в определенное
	//   место окна (первый и второй аргументы)
	PaintDC.TextOut(120, 0, "Обработка сообщения WM_PAINT");

	return afx_msg void();
}

afx_msg void FrameWnd::OnBtnAboutClick(void)
{
	// Звуковой сигнал
	BOOL                rc = MessageBeep(-1);
	/*
	В этой функции можно использовать следующие значения аргумента:
	0xFFFFFFFF - standard beep using the computer speaker
	(экв. -1),
	MB_ICONASTERISK - SystemAsterisk,
	MB_ICONEXCLAMATION - SystemExclamation,
	MB_ICONHAND - SystemHand,
	MB_ICONQUESTION - SystemQuestion,
	MB_OK - SystemDefault
	*/
	if (!rc)
	{
		TRACE0("\n Ошибка 4. Неверное завершение MessageBeep \n");
		exit(4);
	}
	AfxMessageBox("Активизирована кнопка \"О кнопке\"");

	return afx_msg void();
}

afx_msg void FrameWnd::OnBtnExitClick(void)
{
	BOOL                rc = MessageBeep(-1);
	if (!rc)
	{
		TRACE0("\n Ошибка 5. Неверное завершение MessageBeep \n");
		exit(5);
	}
	rc = DestroyWindow();
	if (!rc)
	{
		TRACE0("\n Ошибка 6. Окно не было разрушено \n");
		exit(6);
	}

	return afx_msg void();
}
