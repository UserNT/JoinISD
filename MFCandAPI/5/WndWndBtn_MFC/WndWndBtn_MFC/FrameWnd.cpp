#include "StdAfx.h"
#include "FrameWnd.h"
#include "AboutWnd.h"

#define IDC_BTNWND 100              // ������ "����"
#define IDC_BTNEXIT 101             // ������ "�����"
#define IDC_BTNABOUT 102

// ����������� ������� ���������
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
	BOOL rc = m_pBtnWnd->Create("����� ����", WS_VISIBLE | WS_CHILD
		| BS_PUSHBUTTON, CRect(424, 40, 513, 65), this, IDC_BTNWND);
	if (!rc)
	{
		TRACE0("\n ������ 2. ������ \"����� ����\" �� ����"
			" ������� \n");
		exit(2);
	}

	m_pBtnExit = new CButton;
	ASSERT_VALID(m_pBtnExit);
	rc = m_pBtnExit->Create("�����", WS_VISIBLE | WS_CHILD
		| BS_PUSHBUTTON, CRect(424, 8, 513, 33), this, IDC_BTNEXIT);
	if (!rc)
	{
		TRACE0("\n ������ 3. ������ \"�����\" �� ����"
			" ������� \n");
		exit(3);
	}

	m_pBtnAbout = new CButton;
	m_pBtnAbout->Create("�� ������", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, CRect(424, 72, 513, 97), this, IDC_BTNABOUT);
	return;
}

afx_msg void FrameWnd::OnPaint()
{
	CPaintDC PaintDC(this);
	PaintDC.TextOut(120, 0, "��������� ��������� WM_PAINT");

	return afx_msg void();
}

afx_msg void FrameWnd::OnBtnExitClick()
{
	BOOL                rc = MessageBeep(-1);
	if (!rc)
	{
		TRACE0("\n ������ 6. �������� ���������� MessageBeep \n");
		exit(6);
	}
	rc = DestroyWindow();
	if (!rc)
	{
		TRACE0("\n ������ 7. ���� �� ���� ��������� \n");
		exit(7);
	}

	return afx_msg void();
}

afx_msg void FrameWnd::OnBtnWndClick()
{	
	BOOL                rc = MessageBeep(-1);
	if (!rc)
	{
		TRACE0("\n ������ 4. �������� ���������� MessageBeep \n");
		exit(4);
	}

	AfxMessageBox("����������� ����� ����!", MB_YESNO | MB_ICONHAND);

	FrameWnd* pFrame;
	pFrame = new FrameWnd;
	ASSERT_VALID(pFrame);
	rc = pFrame->Create(// ������������ ���������������� OS WINDOWS ��� ��������
        //   ������
		NULL,
		// ��������� ������ ����
		"��� ���� ���� ������� �� ������ \"����\"",
		// ����� ����
		WS_SIZEBOX | WS_POPUPWINDOW | WS_DLGFRAME,
		// �������������� � ������� ����: 20 - ����� �������,
		//   60 - ����, 430 - ������ �������, 190 - ��� ����
		CRect(20, 60, 530, 200));
	if (!rc)
	{
		TRACE0("\n ������ 5. ����� ��������� ���� �� ��� "
			"������ \n");
		exit(5);
	}
	pFrame->CreateChildControls();
	// ����������� ����
	pFrame->ShowWindow(SW_SHOW);

	return afx_msg void();
}

afx_msg void FrameWnd::OnBtnAboutClick()
{
	AboutWnd* AbW;

	AbW = new AboutWnd;

	AbW->Create(NULL, "����������!!!", WS_VISIBLE | WS_OVERLAPPEDWINDOW, CRect(20, 60, 530, 200));
	AbW->ShowWindow(SW_SHOW);

	return afx_msg void();
}

