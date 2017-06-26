#include "StdAfx.h"
#include "FrameWnd.h"

#define IDC_BTNABOUT 100            // ������ "� ������"
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
	// ��������� � ������������ ������ � ������� ������ "� ������"
	//   (������� �� ���������)
	m_pBtnAbout = new CButton;
	ASSERT_VALID(m_pBtnAbout);    // ��������� ������ ����������
	BOOL                rc = m_pBtnAbout->Create("� ������",
		WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		CRect(424, 40, 513, 65), this, IDC_BTNABOUT);
	if (!rc)
	{
		TRACE0("\n ������ 2. ������ \"� ������\" �� ����"
			" ������� \n");
		exit(2);
	}

	// ��������� � ������������ ������ � ������� ������ "�����"
	m_pBtnExit = new CButton;
	ASSERT_VALID(m_pBtnExit);     // ��������� ������ ����������
	rc = m_pBtnExit->Create("�����", WS_VISIBLE | WS_CHILD
		| BS_PUSHBUTTON, CRect(424, 8, 513, 33), this,
		IDC_BTNEXIT);
	if (!rc)
	{
		TRACE0("\n ������ 3. ������ \"�����\" �� ����"
			" ������� \n");
		exit(3);
	}

	return;
}

afx_msg void FrameWnd::OnPaint(void)
{
	// ������� ������ ��� ��������� � ������
	CPaintDC            PaintDC(this);

	// ����� ��������� ������ (������ ��������) � ������������
	//   ����� ���� (������ � ������ ���������)
	PaintDC.TextOut(120, 0, "��������� ��������� WM_PAINT");

	return afx_msg void();
}

afx_msg void FrameWnd::OnBtnAboutClick(void)
{
	// �������� ������
	BOOL                rc = MessageBeep(-1);
	/*
	� ���� ������� ����� ������������ ��������� �������� ���������:
	0xFFFFFFFF - standard beep using the computer speaker
	(���. -1),
	MB_ICONASTERISK - SystemAsterisk,
	MB_ICONEXCLAMATION - SystemExclamation,
	MB_ICONHAND - SystemHand,
	MB_ICONQUESTION - SystemQuestion,
	MB_OK - SystemDefault
	*/
	if (!rc)
	{
		TRACE0("\n ������ 4. �������� ���������� MessageBeep \n");
		exit(4);
	}
	AfxMessageBox("�������������� ������ \"� ������\"");

	return afx_msg void();
}

afx_msg void FrameWnd::OnBtnExitClick(void)
{
	BOOL                rc = MessageBeep(-1);
	if (!rc)
	{
		TRACE0("\n ������ 5. �������� ���������� MessageBeep \n");
		exit(5);
	}
	rc = DestroyWindow();
	if (!rc)
	{
		TRACE0("\n ������ 6. ���� �� ���� ��������� \n");
		exit(6);
	}

	return afx_msg void();
}
