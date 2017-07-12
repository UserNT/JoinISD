/*
����               : Dialog.�pp

������             : ������������ ������� Windows-���������� ��
������ ���������� ������� MFC (������ -
��������� ������ � �������������)

����������         : ���������� ������ "Dialog", ������������
�� ������ "CDialod" ���������� �������
MFC (��������� ��������� ���� �������)

Microsoft Visual Studio C++ .NET 2005
*/

#include "StdAfx.h"                 // ���������������� ����
// ���������� ������ Dialog
#include "Dialog.h"
// �������������� �������� (��������� ���������� ��������)
#include "resource.h"


// ����������� ������� ��������� (� ������ ������ ��� ���������)
BEGIN_MESSAGE_MAP(Dialog, CDialog)
	/*ON_BN_CLICKED( IDC_RADIO_SOLID, OnRadioSolidClick )
	ON_BN_CLICKED( IDC_RADIO_DASH, OnRadioDashClick )
	ON_BN_CLICKED( IDC_RADIO_DOT, OnRadioDotClick )*/
END_MESSAGE_MAP()


// �����������
Dialog::Dialog(
	CWnd                *pParent)  // ��������� �� ������������
								   //   ���� (NULL - ������������
								   //   �������� ������� ����)
	: CDialog(IDR_DIALOG, pParent)
{ }

// ������������� ���� �������
BOOL Dialog::OnInitDialog(void)
{
	// �������� ����� �������� ������
	CDialog::OnInitDialog();

	// �������� ��������� �� �����������
	pRadioSolid = static_cast< CButton * >
		(GetDlgItem(IDC_RADIO_SOLID));
	pRadioDash = static_cast< CButton * >
		(GetDlgItem(IDC_RADIO_DASH));
	pRadioDot = static_cast< CButton * >
		(GetDlgItem(IDC_RADIO_DOT));

	// ������������� �������� �����������
	switch (m_PenStyle)
	{

	case PS_SOLID:
		pRadioSolid->SetCheck(1);
		break;

	case PS_DASH:
		pRadioDash->SetCheck(1);
		break;

	case PS_DOT:
		pRadioDot->SetCheck(1);
		break;
	}

	return TRUE;
}

// ������������ �������� ������� �� ������ ��
void Dialog::OnOK(void)
{
	// �������� ����� �������� ������
	CDialog::OnOK();

	// ���������� ����������� ���
	/*pRadioSolid = static_cast< CButton * >
	( GetDlgItem( IDC_RADIO_SOLID ) );
	pRadioDash  = static_cast< CButton * >
	( GetDlgItem(  IDC_RADIO_DASH ) );
	pRadioDot   = static_cast< CButton * >
	( GetDlgItem(  IDC_RADIO_DOT ) );*/

	if (pRadioSolid->GetCheck() == 1)
	{
		m_PenStyle = PS_SOLID;
	}
	else if (pRadioDash->GetCheck() == 1)
	{
		m_PenStyle = PS_DASH;
	}
	else
	{
		m_PenStyle = PS_DOT;
	}

	return;
}

// ����������� ����������� - � ������ ������ ��� ���������
// ���������� ����������� "��������"
/*void Dialog :: OnRadioSolidClick( void )
{
m_PenStyle = PS_SOLID;

return;
}

// ���������� ����������� "����������"
void Dialog :: OnRadioDashClick( void )
{
m_PenStyle = PS_DASH;

return;
}

// ���������� ����������� "��������"
void Dialog :: OnRadioDotClick( void )
{
m_PenStyle = PS_DOT;

return;
}*/
