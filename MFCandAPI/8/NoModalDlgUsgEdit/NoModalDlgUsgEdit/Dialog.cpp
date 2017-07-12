
#include "StdAfx.h"                 // ���������������� ����
#include "FrameWnd.h"             // ���������� ������ FrameWnd
#include "Dialog.h"               // ���������� ������ Dialog

// ������������� ������� (���������� ������������ ������)
BOOL Dialog::OnInitDialog(void)
{
	// �������� ����� �������� ������
	CDialog::OnInitDialog();

	// �������� ��������� �� ������������ ��������
	pEdit = static_cast< CEdit * >(GetDlgItem(IDC_EDIT));
	if (!pEdit)
	{
		TRACE0("\n ������ 5 - ������������ �������� �� "
			"������ \n");
		exit(5);
	}

	// ������������� ����� ������ (13) ��� �������� ��������������
	//   � ����� ���������� ������
	pEdit->SetLimitText(13);
	pEdit->SetWindowText(e1);

	return TRUE;
}

// ON OK: ��������� �������� ������� ������� "OK"
void Dialog::OnOK(void)
{
	// �������� ����� �������� ������
	CDialog::OnOK();

	// �� ����� ������ ������������� ���������� DoDataExchange( ),
	//   ����������� ������ �� ���� �������
	UpdateData(TRUE);

	// ������������ ����������� ������
	AfxMessageBox(static_cast< LPCTSTR >(e1));

	return;
}

// ��������� ������ �� ���� ������� (����� ���������� �������������
//   �� ������ UpdateData( ))
void Dialog::DoDataExchange(CDataExchange *pDX)
{
	// �������� ����� �������� ������
	CDialog::DoDataExchange(pDX);

	// �������� � e1 ����� �� ������������� ���������
	DDX_Text(pDX, IDC_EDIT, e1);

	return;
}

// �������� ������������ ������� !!! ��������, �����
BOOL Dialog::Create(void)
{
	return CDialog::Create(IDD_DIALOG_EDIT);
}
