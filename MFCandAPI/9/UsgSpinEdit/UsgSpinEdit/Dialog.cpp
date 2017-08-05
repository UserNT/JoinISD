/*
����               : Dialog.�pp

������             : ������������ Windows-���������� �� ������
���������� ������� MFC � ����� ����������
�������, ������������ ��������� � ����
��������������

����������         : ���������� ������ "Dialog", ������������
�� ������ "CDialod" ���������� �������
MFC (��������� ��������� ���� �������)

Microsoft Visual Studio C++ .NET 2005
*/


#include "StdAfx.h"                 // ���������������� ����
#include "FrameWnd.h"             // ���������� ������ FrameWnd
#include "Dialog.h"               // ���������� ������ Dialog
// �������������� �������� (��������� ���������� ��������)
#include "resource.h"

// ����������� ������� ���������
BEGIN_MESSAGE_MAP(Dialog, CDialog)
	ON_EN_UPDATE(IDC_EDIT_RED, OnEditColor)
	ON_EN_UPDATE(IDC_EDIT_GREEN, OnEditColor)
	ON_EN_UPDATE(IDC_EDIT_BLUE, OnEditColor)
END_MESSAGE_MAP()

// �����������
Dialog::Dialog(
	CWnd                *pParent)  // ��������� �� ������������
								   //   ���� (NULL - ������������
								   //   �������� ������� ����)
	: CDialog(IDD_DIALOG_RGB, pParent)
{
	m_InitIsDone = false;
}

// ������������� ���� �������
BOOL Dialog::OnInitDialog(void)
{
	// �������� ����� �������� ������
	CDialog::OnInitDialog();

	BYTE                Red;        // ������� ������������ "m_RGB"
	BYTE                Green;      // ������� ������������ "m_RGB"
	BYTE                Blue;       // ����� ������������ "m_RGB"

									// �������� ��������� �� ��������� � �������� ��������������
									//   ��������, �������� � ������ ������        
	pSpinRed = static_cast< CSpinButtonCtrl * >
		(GetDlgItem(IDC_SPIN_RED));
	pSpinGreen = static_cast< CSpinButtonCtrl * >
		(GetDlgItem(IDC_SPIN_GREEN));
	pSpinBlue = static_cast< CSpinButtonCtrl * >
		(GetDlgItem(IDC_SPIN_BLUE));
	// ������������� ��������� ����� ������ ��� ������� �����������
	//   �� ����� ��������� ������
	pEditRed = static_cast< CEdit * >
		(GetDlgItem(IDC_EDIT_RED));
	pEditGreen = static_cast< CEdit * >
		(GetDlgItem(IDC_EDIT_GREEN));
	pEditBlue = static_cast< CEdit * >
		(GetDlgItem(IDC_EDIT_BLUE));

	// ������������� ��������� �������� ��� ���������� ��������,
	//   �������� � ������ ������ (�������� �������� �� ��, ���
	//   ����� ������������ ������������ �������� - ��� ����������
	//   ������ ��������� ������ �� ��� �� ������, �� ���
	//   ������������ ��������� ����� �����������)
	pSpinRed->SetRange(0, 255);
	pSpinGreen->SetRange(0, 255);
	pSpinBlue->SetRange(0, 255);

	// �������� �������, ������� � ����� ���������� "�������"
	//   RGB-�����
	Red = GetRValue(m_OldRGB);
	Green = GetGValue(m_OldRGB);
	Blue = GetBValue(m_OldRGB);

	// ������������� �������� ������ ��� ����������
	pSpinRed->SetPos(Red);
	pSpinGreen->SetPos(Green);
	pSpinBlue->SetPos(Blue);

	// ������������� ����� ������ � ������ (3) ��� ���������
	//   �������������� ������
	pEditRed->SetLimitText(3);
	pEditGreen->SetLimitText(3);
	pEditBlue->SetLimitText(3);

	// ������������� ������� ���������
	m_InitIsDone = true;

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

									// �������� ������� �������� ������ �� ���������� ��������,
									//   �������� � ������ ������
	Red = pSpinRed->GetPos();
	Green = pSpinGreen->GetPos();
	Blue = pSpinBlue->GetPos();

	// ��������� ����� RGB-����
	m_NewRGB = RGB(Red, Green, Blue);

	return;
}

// �������������� ������������ �����
void Dialog::OnEditColor(void)
{
	BYTE                Red;        // ������� ������������ "m_RGB"
	BYTE                Green;      // ������� ������������ "m_RGB"
	BYTE                Blue;       // ����� ������������ "m_RGB"
									// ��������� ������������� ����
	FrameWnd           *pParent;

	if (!m_InitIsDone)
		return;                     // �����, ���� �� ���� ��������
									//   �������������

									// �������� ������� �������� ������ �� ���������� ��������,
									//   �������� � ������ ������
	Red = pSpinRed->GetPos();
	Green = pSpinGreen->GetPos();
	Blue = pSpinBlue->GetPos();

	// ��������� ����� RGB-����
	m_NewRGB = RGB(Red, Green, Blue);

	// �������� ��������� ������������� ���� � ������������� ���
	//   ���� ����� RGB-����
	pParent = static_cast< FrameWnd * >(GetParent());
	pParent->TryPenRGB(m_NewRGB);

	return;
}