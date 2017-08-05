/*
����               : Dialog.�pp

������             : ������������ Windows-���������� �� ������
���������� ������� MFC � ����� ����������
�������, ������������ ������ ���������

����������         : ���������� ������ "Dialog", ������������
�� ������ "CDialod" ���������� �������
MFC (��������� ���� �������)

Microsoft Visual Studio C++ .NET 2005
*/


#include "StdAfx.h"                 // ���������������� ����
#include "FrameWnd.h"             // ���������� ������ FrameWnd
#include "Dialog.h"               // ���������� ������ Dialog
// �������������� �������� (��������� ���������� ��������)
#include "resource.h"

// ����������� ����� ���������
BEGIN_MESSAGE_MAP(Dialog, CDialog)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()

// �����������
Dialog::Dialog(
	CWnd                *pParent)  // ��������� �� ������������
								   //   ���� (NULL - ������������
								   //   �������� ������� ����)
	: CDialog(IDD_DIALOG_RGB, pParent)
{
}

// ������������� ���� �������
BOOL Dialog::OnInitDialog(void)
{
	// �������� ����� �������� ������
	CDialog::OnInitDialog();

	BYTE                Red;        // ������� ������������ "m_RGB"
	BYTE                Green;      // ������� ������������ "m_RGB"
	BYTE                Blue;       // ����� ������������ "m_RGB"

									// �������� ��������� �� ������ ��������� ��������, �������� �
									//   ������ ������    
	pScrollBarRed = static_cast< CScrollBar * >
		(GetDlgItem(IDC_SCROLLBARRED));
	pScrollBarGreen = static_cast< CScrollBar * >
		(GetDlgItem(IDC_SCROLLBARGREEN));
	pScrollBarBlue = static_cast< CScrollBar * >
		(GetDlgItem(IDC_SCROLLBARBLUE));

	// ������������� ��������� �������� ��� ����� ��������� ��������,
	//   �������� � ������ ������ (�������� �������� �� ��, ���
	//   ����� ������������ ������������ �������� - ��� ����������
	//   ������ ��������� ������ �� ��� �� ������, �� ���
	//   ������������ ��������� ����� �����������)
	pScrollBarRed->SetScrollRange(0, 255);
	pScrollBarGreen->SetScrollRange(0, 255);
	pScrollBarBlue->SetScrollRange(0, 255);

	// �������� �������, ������� � ����� ���������� "�������"
	//   RGB-�����
	Red = GetRValue(m_OldRGB);
	Green = GetGValue(m_OldRGB);
	Blue = GetBValue(m_OldRGB);

	// ������������� �������� ������ ��� ����� ���������
	pScrollBarRed->SetScrollPos(Red);
	pScrollBarGreen->SetScrollPos(Green);
	pScrollBarBlue->SetScrollPos(Blue);

	return TRUE;
}

// ��������� ���������� �� ���� ������� (���������� ������ OK)
void Dialog::OnOK(void)
{
	// �������� ����� �������� ������
	CDialog::OnOK();

	BYTE                Red;        // ������� ������������ "m_RGB"
	BYTE                Green;      // ������� ������������ "m_RGB"
	BYTE                Blue;       // ����� ������������ "m_RGB"

									// �������� ������� �������� ������ �� ����� ��������� ��������,
									//   �������� � ������ ������
	Red = pScrollBarRed->GetScrollPos();
	Green = pScrollBarGreen->GetScrollPos();
	Blue = pScrollBarBlue->GetScrollPos();

	// ��������� ����� RGB-����
	m_NewRGB = RGB(Red, Green, Blue);

	return;
}

// ���������� ��������� �� �������������� ������ ���������
afx_msg void Dialog::OnHScroll(
	// ��� ����������� ������ ���������
	UINT                nSBCode,
	UINT                nPos,       // ������� ������� �������
									// ��������� �� ������ ���������
	CScrollBar          *pScrollBar)
{
	int                 nCurPos;    // ������� �������

									// �������� ������� �������
	nCurPos = pScrollBar->GetScrollPos();

	// �������� ����� �������� ������
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);

	// ������������ ��������� ������ ���������
	switch (nSBCode)
	{
		// ������ ������ ������
	case SB_LINEDOWN:
		nCurPos += 1;
		break;

		// ������ ����� ������
	case SB_LINEUP:
		nCurPos -= 1;
		break;

		// ������ ������ ���� ������ �� �������
	case SB_PAGEDOWN:
		nCurPos += 10;
		break;

		// ������ ������ ���� ����� �� �������
	case SB_PAGEUP:
		nCurPos -= 10;
		break;

		// ��������� ������������� �������
	case SB_THUMBTRACK:
		nCurPos = nPos;
		break;
	}

	// ������������� ����� �������������� �������
	pScrollBar->SetScrollPos(nCurPos);

	return afx_msg void();
}
