/*
����               : FrameWnd.cpp

������             : ������������ ������� Windows-���������� ��
������ ���������� ������� MFC � �������� �
������� ����, ������������ ���������� �
������� ������

����������         : ���������� ������ "FrameWnd", ������������
�� ������ "CFrameWnd" ���������� �������
MFC (��������� ��������� �������� ����)

Microsoft Visual Studio C++ .NET 2005
*/

#include "StdAFX.h"                 // ���������������� ����
#include "FrameWnd.h"             // ���������� ������ FrameWnd

// �������������� ����������� ���������
#define IDC_BTNREAD 100             // ������������ ������ "������"
#define IDC_BTNEXIT 101             // ������ "�����"
#define IDC_ECONE   102             // ������������ ��������

// ����������� ������� ���������
BEGIN_MESSAGE_MAP(FrameWnd, CFrameWnd)
	ON_COMMAND(IDC_BTNREAD, OnBtnReadClick)
	ON_COMMAND(IDC_BTNEXIT, OnBtnExitClick)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// ����������� ��������� (������������� ���������� �� ������ �
//   ��������)
FrameWnd::FrameWnd(void)
{
	m_pBtnRead = 0;
	m_pBtnExit = 0;
	m_pEdit = 0;
}

// ���������� (����������� ������, ������� �������� � ������������
//   ����������)
FrameWnd :: ~FrameWnd(void)
{
	if (m_pBtnRead)
	{
		delete m_pBtnRead;
		m_pBtnRead = 0;
	}
	if (m_pBtnExit)
	{
		delete m_pBtnExit;
		m_pBtnExit = 0;
	}
	if (m_pEdit)
	{
		delete m_pEdit;
		m_pEdit = 0;
	}
}

// �������� �������� ����������� ��������� (�������������
//   ����������� �����)
void FrameWnd::CreateChildControls(void)
{
	// ��������� � ������������ ������ � ������� ������������
	//   ������� ��������������
	m_pEdit = new CEdit;
	ASSERT_VALID(m_pEdit);        // ��������� ������ ����������
	BOOL                rc = m_pEdit->Create(WS_VISIBLE |
		WS_CHILD | ES_LEFT | WS_BORDER, CRect(120, 20, 370, 40),
		this, IDC_ECONE);
	if (!rc)
	{
		TRACE0("\n ������ 2. ������� �������������� �� ���"
			" ������ \n");
		exit(2);
	}
	/*
	������ �������� � ������ ������ Create( ) ������ ����� ����
	��������������.
	������� ��������� ����� ������� CEdit:
	ES_AUTOHSCROLL - �������������� ������������� ������ ������ ��
	10 �������� ��� ���������� ������ ������� ����
	(��� ������� ������� ENTER �����
	�������������� ������� � ������� 0);
	ES_AUTOVSCROLL - �������������� ������������� ������ �� ����
	�������� ����� � ������������� ����
	��������������, ����� ������������ ��������
	ENTER � ����� ��������� ������;
	ES_CENTER - ����������� ����� �� ������ � ������������� ����
	��������������;
	ES_LEFT - ����������� ����� �� ������ ����;
	ES_LOWERCASE - �� ���� ����� ������������� �������������� ���
	������� � ������ �������;
	ES_MULTILINE - ������ ������������� ���� ��������������
	(������������ �� ���������);
	ES_OEMCONVERT - ������������ ���������� �������������� ��������
	� ��������� DOS;
	ES_PASSWORD - ������� � ���� ��� ��������� ������� � ���� *;
	ES_READONLY - �� ��������� ������� ��� ������������� ����� �
	����;
	ES_RIGHT - ����������� ����� �� ������� ����;
	ES_UPPERCASE - �� ���� ����� ������������� �������������� ���
	������� � ������� �������.
	������������� ������ ����� �������������� ����� �������� �
	������ ������� ����, ���������� �������� ������ CWnd.
	*/
	m_pEdit->LimitText(20);       // ����������� ����� ������
								  // ��������� ������������� ���� ��������������
	m_pEdit->SetWindowText("����� ������ <=20");
	/*
	������ � �������������� ���� �������� Create( ),
	LimitText( ), SetWindowText( ) ���������� ��������� ������,
	���������� ��� ������������ � ������������� ����
	��������������:
	CanUndo( ) - ����������, ����� �� ���� �������� ��������
	��������������;
	Clear( ) - ������� ���������� �����, ���� �� ����;
	Copy( ) - �������� ���������� �����, ���� �� ����, � �����
	������;
	Cut( ) - �������� ���������� �����, ���� �� ����, � ��������
	��� � ����� ������;
	EmtyUndoBuffer( ) - ���������� ���� ������ ���� ��������������;
	DefFirstVisibleLine( ) - ���������� ������� ������� ������ �
	���� ��������������;
	GetModify( ) - ���������� ���� �� �������� ���������� ����
	��������������;
	GetPasswodChar( ) - ���������� ������-���������� ��� �����
	������;
	GetRect( ) - ���������� ������������� ���� ��������������;
	GetSel( ) - ���������� ������� ������� � ���������� ��������
	����������� ������;
	LineFromChar( ) - ���������� ����� ������, ���������� ������ �
	��������� ��������;
	Linelength( ) - ���������� ����� ������ � ���� ��������������;
	LineScroll( ) - ������������ ����� � ������������� ����
	��������������;
	Paste( ) - ��������� ������ �� ������ ������ � ������� �������
	�������;
	ReplaceSel( ) - �������� ���������� � ���� �������������� �����
	��������� �������;
	SetModify( ) - ������������� ��� ���������� ���� ���������;
	SetPasswordChar( ) - ��������� ��� ������� ������-����������
	��� ����� ������;
	SetReadOnly( ) - ������������� ����� ������� � ����
	�������������� "������ ��� ������";
	SetSel( ) - �������� ��������� �������� �������� � ����
	��������������;
	Undo( ) - �������� ��������� �������� ��������������.
	����� �������������, ������� ��� ������������� �������
	�������������� ���� ��������������.
	*/

	// ��������� � ������������ ������ � ������� ������ "������"
	//   (������� �� ���������)
	m_pBtnRead = new CButton;
	ASSERT_VALID(m_pBtnRead);
	rc = m_pBtnRead->Create("������", WS_VISIBLE | WS_CHILD |
		BS_DEFPUSHBUTTON, CRect(20, 20, 110, 40), this,
		IDC_BTNREAD);
	if (!rc)
	{
		TRACE0("\n ������ 3. ������ \"������\" �� ����"
			" ������� \n");
		exit(3);
	}

	// ��������� � ������������ ������ � ������� ������ "�����"
	m_pBtnExit = new CButton;
	ASSERT_VALID(m_pBtnExit);     // ��������� ������ ����������
	rc = m_pBtnExit->Create("�����", WS_VISIBLE | WS_CHILD
		| BS_PUSHBUTTON, CRect(424, 200, 513, 230), this,
		IDC_BTNEXIT);
	if (!rc)
	{
		TRACE0("\n ������ 4. ������ \"�����\" �� ����"
			" ������� \n");
		exit(4);
	}

	return;
}

// ���������� ������ "������"
afx_msg void FrameWnd::OnBtnReadClick(void)
{
	// �������� ������
	BOOL                rc = MessageBeep(-1);
	if (!rc)
	{
		TRACE0("\n ������ 5. �������� ���������� MessageBeep \n");
		exit(5);
	}

	// ������ � ������������ ������ �� ������������� ���������
	CString             string;        // ��� ������������ ������
	m_pEdit->GetWindowText(string);
	AfxMessageBox(string);

	return afx_msg void();
}

// ���������� ������ "�����"
afx_msg void FrameWnd::OnBtnExitClick(void)
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

// ���������� ��������� WM_PAINT: ������������� ����� �����������
//   ������
afx_msg void FrameWnd::OnPaint(void)
{
	// ������� ������ ��� ��������� � ������
	CPaintDC            PaintDC(this);

	// ����� ��������� ������ (������ ��������) � ������������
	//   ����� ���� (������ � ������ ���������)
	PaintDC.TextOut(120, 0, "������������ ���� ��������������");

	return afx_msg void();
}