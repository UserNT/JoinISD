/*
����               : Dialog.cpp

������             : ���������� �� ������ ���������� ������� MFC
(������� - Bitmap, Dialog, Menu � String
Table)

����������         : ���������� ������ "BitmapDialog",
������������ �� ������ "CDialog" ����������
������� MFC (��������� ��������� ����
�������)

Microsoft Visual Studio C++ .NET 2005
*/

#include "StdAfx.h"                 // ���������������� ����
#include "Dialog.h"               // ���������� ������ Dialog
// �������������� �������� (��������� ���������� ��������)
#include "resource.h"

// ����������� ������� ���������
BEGIN_MESSAGE_MAP(Dialog, CDialog)
	ON_BN_CLICKED(IDC_BITBTN1, OnBmpBtn1Click)
	ON_BN_CLICKED(IDC_BITBTN2, OnBmpBtn2Click)
END_MESSAGE_MAP()

// �����������
Dialog::Dialog(
	CWnd                *pParent)  // ��������� �� ������������
								   //   ���� (NULL - ������������
								   //   �������� ������� ����)
	: CDialog(IDD_DIALOG_BITMAP, pParent)
{ }

// ������������� ���� �������
BOOL Dialog::OnInitDialog(void)
{
	// ����� ������ �������� ������
	CDialog::OnInitDialog();

	// ���������� ������ � �������������
	if (!BmpBtn1.AutoLoad(IDC_BITBTN1, this))
	{
		TRACE0("\n ������ 4 ������������� AutoLoad \n");
		exit(4);
	}
	if (!BmpBtn2.AutoLoad(IDC_BITBTN2, this))
	{
		TRACE0("\n ������ 5 ������������� AutoLoad \n");
		exit(5);
	}

	return TRUE;
}

// ��������� ������, ���������� Paint
afx_msg void Dialog::OnBmpBtn1Click(void)
{
	// ������ ������������ ��������: ������ �������� - ���������
	//   ������, ������ - � ����� ���� ���������� ���� ��������
	WinExec("mspaint bmp.bmp", SW_SHOWNORMAL);

	return afx_msg void();
}

// ��������� ������, ���������� NotePad
afx_msg void Dialog::OnBmpBtn2Click(void)
{
	// ������ ������������ ��������: ������ �������� - ���������
	//   ������, ������ - � ����� ���� ���������� ���� ��������
	WinExec("notepad readme", SW_SHOWNORMAL);

	return afx_msg void();
}