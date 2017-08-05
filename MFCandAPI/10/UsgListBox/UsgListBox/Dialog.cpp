/*
����               : Dialog.�pp

������             : ������������ Windows-���������� �� ������
���������� ������� MFC � ����� ����������
�������, ������������ ������

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
	ON_BN_CLICKED(IDC_BUTTON_LR, OnButtonLRClick)
	ON_BN_CLICKED(IDC_BUTTON_RL, OnButtonRLClick)
END_MESSAGE_MAP()

// �����������
Dialog::Dialog(
	CWnd                *pParent)  // ��������� �� ������������
								   //   ���� (NULL - ������������
								   //   �������� ������� ����)
	: CDialog(IDD_DIALOG_LISTBOXES, pParent)
{ }

// ������������� ���� �������
BOOL Dialog::OnInitDialog(void)
{
	// �������� ����� �������� ������
	CDialog::OnInitDialog();

	// �������� ��������� �� ������
	m_plbMulti = static_cast< CListBox * >
		(GetDlgItem(IDC_LIST_MULTI));
	m_plbSingle = static_cast< CListBox * >
		(GetDlgItem(IDC_LIST_SINGLE));

	int                 IxStr;      // ������ �������� ������
									// ������� �������� � ����� ������
	for (IxStr = 0; IxStr <= m_IxEnbLast; IxStr++)
	{
		m_plbMulti->AddString(m_Enabled[IxStr]);
	}

	// ������� �������� � ������ ������
	for (IxStr = 0; IxStr <= m_IxDisLast; IxStr++)
	{
		m_plbSingle->AddString(m_Disabled[IxStr]);
	}

	return TRUE;
}

// ��������� ���������� �� ���� ������� (���������� ������ OK)
void Dialog::OnOK(void)
{
	// �������� ����� �������� ������
	CDialog::OnOK();

	// ������ �������� ������
	int                 IxStr;

	// �������� ������ ���������� �������� ������ ������
	m_IxEnbLast = m_plbMulti->GetCount() - 1;
	// ��������� ���������� �� ������ ������
	for (IxStr = 0; IxStr <= m_IxEnbLast; IxStr++)
	{
		m_plbMulti->GetText(IxStr, m_Enabled[IxStr]);
	}

	// �������� ������ ���������� �������� ������� ������
	m_IxDisLast = m_plbSingle->GetCount() - 1;
	// ��������� ���������� �� ������� ������
	for (IxStr = 0; IxStr <= m_IxDisLast; IxStr++)
	{
		m_plbSingle->GetText(IxStr, m_Disabled[IxStr]);
	}

	return;
}

// ���������� ������ "Move>>" �������� ���������� �� ������ ������
//   � ������
void Dialog::OnButtonLRClick(void)
{
	// ��� �������� ���������� ����� ������ ������
	int                 Selected[10];
	// ������ ��������� ����������� ������ � Selected
	int                 IxSelLast;
	// ������ ������� ���������� ������ ������ ������
	int                 IxSel;
	// ����� ������������ ������
	CString             Copy;
	// ������ �������������� ������
	int                 IxStr;

	// �������� ����������� �� 1 ����� ���������� ����� ������
	//   ������
	IxSelLast = m_plbMulti->GetSelCount() - 1;
	if (IxSelLast < 0)              // ���������� ����� ���
		return;

	// ������� ������� ���������� ����� ������ ������ � Selected
	m_plbMulti->GetSelItems(10, Selected);
	// ��������� ���������� ������ � ������ ������
	for (IxSel = IxSelLast; IxSel >= 0; IxSel--)
	{
		IxStr = Selected[IxSel];
		m_plbMulti->GetText(IxStr, Copy);
		m_plbMulti->DeleteString(IxStr);
		m_plbSingle->AddString(Copy);
	}

	return;
}

// ���������� ������ "Move<<" �������� ���������� �� ������� ������
//   � �����
void Dialog::OnButtonRLClick(void)
{
	// ����� ������������ ������
	CString             Copy;
	// ������ �������������� ������
	int                 IxStr;

	// �������� ������ ���������� ������ ������� ������
	IxStr = m_plbSingle->GetCurSel();
	if (IxStr == LB_ERR)          // ���������� ������ ���
		return;

	// ��������� ���������� ������ �� ������� ������ � �����
	m_plbSingle->GetText(IxStr, Copy);
	m_plbSingle->DeleteString(IxStr);
	m_plbMulti->AddString(Copy);

	return;
}