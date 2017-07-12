/*
����               : Dialog.hpp

������             : ������������ �������� Windows-���������� ��
������ ���������� ������� MFC (������� -
������� ������ + ������������ ��������)

����������         : ���������� ������ "Dialog", ������������
�� ������ "CDialog" ���������� �������
MFC (��������� ��������� ���� �������)

Microsoft Visual Studio C++ .NET 2005
*/

// �������������� ����������� ������������� ����������� �������
//   �����
#ifndef _Dialog_h
#define _Dialog_h

// �������������� ��������
#include "resource.h"           

class Dialog : public CDialog
{
	// ������

private:

	// ��������� ������������� �������� ��������������
	CEdit           *pEdit;

public:

	// ��� ������ �������� ��������������
	CString         e1;

	// ������

public:

	BOOL Create(void);

private:

	// ������������� ���� ������� (���������� ������������
	//   ������)
	virtual BOOL OnInitDialog(void);
	// ��������� ���������� �� ���� ������� (����������
	//   ������������ ������)
	virtual void OnOK(void);
	// ��������� ������ �� ���� ������� (����� ����������
	//   ������������� �� ������ UpdateData( ))
	void DoDataExchange(CDataExchange* pDX);

};

#endif
