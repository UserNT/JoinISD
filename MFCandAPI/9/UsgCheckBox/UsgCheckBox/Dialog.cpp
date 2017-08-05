/*
����               : Dialog.�pp

������             : ������������ Windows-���������� �� ������
���������� ������� MFC � ����� ����������
�������, ������������ CheckBox

����������         : ���������� ������ "Dialog", ������������
�� ������ "CDialod" ���������� �������
MFC (��������� ��������� ���� �������)

Microsoft Visual Studio C++ .NET 2005
*/


#include "StdAfx.h"                 // ���������������� ����
#include "Dialog.h"               // ���������� ������ Dialog
// �������������� �������� (��������� ���������� ��������)
#include "resource.h"

// ����������� ������� ���������
BEGIN_MESSAGE_MAP(Dialog, CDialog)
	ON_BN_CLICKED(IDC_STDCHK1, OnBtn1Click)
	ON_BN_CLICKED(IDC_3STCHK2, OnBtn2Click)
END_MESSAGE_MAP()

// �����������
Dialog::Dialog(
	CWnd                *pParent)  // ��������� �� ������������
								   //   ���� (NULL - ������������
								   //   �������� ������� ����)
	: CDialog(IDD_DIALOG_3STATE, pParent)
{ }

// ������������� ���� �������
BOOL Dialog::OnInitDialog(void)
{
	// �������� ����� �������� ������
	CDialog::OnInitDialog();

	// �������� ��������� �� CheckBox
	m_pStdChk1 = static_cast< CButton * >(GetDlgItem(IDC_STDCHK1));
	m_p3StChk2 = static_cast< CButton * >(GetDlgItem(IDC_3STCHK2));

	// ������������� ��������� �������� CheckBox
	if (m_bStdChk1)
	{
		m_pStdChk1->SetCheck(1);
	}

	// ������������� ��������� ���������� CheckBox
	switch (m_3StChk2)
	{
	case 1:
		m_p3StChk2->SetCheck(1);
		break;

	case 2:
		m_p3StChk2->SetCheck(2);
		break;
	}

	return TRUE;
}

// ����������� CheckBox
// ���������� �������� CheckBox
void Dialog::OnBtn1Click(void)
{
	if (m_pStdChk1->GetCheck())
	{
		m_bStdChk1 = true;
	}
	else
	{
		m_bStdChk1 = false;
	}

	return;
}

// ���������� CheckBox � ����� �����������
void Dialog::OnBtn2Click(void)
{
	m_3StChk2 = m_p3StChk2->GetCheck();

	return;
}
