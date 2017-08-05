/*
����               : Dialog.�pp

������             : ������������ Windows-���������� �� ������
���������� ������� MFC � ����� ����������
�������, ������������ ���������
��������������� ������

����������         : ���������� ������ "Dialog", ������������
�� ������ "CDialod" ���������� �������
MFC (��������� ��������� ���� �������)

Microsoft Visual Studio C++ .NET 2005
*/


#include "StdAfx.h"                 // ���������������� ����
#include "Dialog.h"               // ���������� ������ Dialog
// �������������� �������� (��������� ���������� ��������)
#include "resource.h"

// �����������
Dialog::Dialog(
	CWnd                *pParent)  // ��������� �� ������������
								   //   ���� (NULL - ������������
								   //   �������� ������� ����)
	: CDialog(IDD_DIALOG_COMBOBOXES, pParent)
{ }

// ������������� ���� �������
BOOL Dialog::OnInitDialog(void)
{
	// �������� ����� �������� ������
	CDialog::OnInitDialog();

	// �������� ��������� �� ��������������� ������
	m_pCombo1 = static_cast< CComboBox * >
		(GetDlgItem(IDC_COMBO3));
	m_pCombo2 = static_cast< CComboBox * >
		(GetDlgItem(IDC_COMBO2));
	m_pCombo3 = static_cast< CComboBox * >
		(GetDlgItem(IDC_COMBO1));

	int                 IxStr;      // ������ �������� ������
									// ������� �������� � ������� ��������������� ������ �
									//   �������� ������ � ���� ��������������
	for (IxStr = 0; IxStr <= m_IxLast1; IxStr++)
	{
		m_pCombo1->AddString(m_List1[IxStr]);
	}
	m_pCombo1->SetCurSel(0);

	// ������� �������� � �������������� ��������������� ������ �
	//   �������� ������ � ���� ��������������
	for (IxStr = 0; IxStr <= m_IxLast2; IxStr++)
	{
		m_pCombo2->AddString(m_List2[IxStr]);
	}
	m_pCombo2->SetCurSel(0);

	// ������� �������� � �������������� ������ � �������� ������
	//   � ���� ��������������
	for (IxStr = 0; IxStr <= m_IxLast3; IxStr++)
	{
		m_pCombo3->AddString(m_List3[IxStr]);
	}
	m_pCombo3->SetCurSel(0);

	return TRUE;
}

// ��������� ���������� �� ���� ������� (���������� ������ OK)
void Dialog::OnOK(void)
{
	// �������� ����� �������� ������
	CDialog::OnOK();

	m_pCombo1->GetWindowText(m_Str1);
	m_pCombo2->GetWindowText(m_Str2);
	m_pCombo3->GetWindowText(m_Str3);

	return;
}