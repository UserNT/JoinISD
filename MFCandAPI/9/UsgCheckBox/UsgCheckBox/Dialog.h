#pragma once
/*
����               : Dialog.hpp

������             : ������������ Windows-���������� �� ������
���������� ������� MFC � ����� ����������
�������, ������������ CheckBox

����������         : ���������� ������ "Dialog", ������������
�� ������ "CDialod" ���������� �������
MFC (��������� ��������� ���� �������)

Microsoft Visual Studio C++ .NET 2005
*/

// �������������� ����������� ������������� ����������� �������
//   �����
#ifndef _Dialog_h
#define _Dialog_h

// ���������� ������
class Dialog : public CDialog
{
	// ������

private:

	// ��������� �� CheckBox � ����� �����������
	CButton         *m_pStdChk1;
	// ��������� �� CheckBox � ����� �����������
	CButton         *m_p3StChk2;

public:

	// ��������� ������������ CheckBox
	bool            m_bStdChk1;
	// ��������� �������������� CheckBox
	int             m_3StChk2;

	// ������

public:

	// ����������� - �������� ������������� ������� � �������
	//   �����
	Dialog(CWnd *pParent = 0);

protected:

	// ����������� ����������� ����� ��� ������������� �������
	virtual BOOL OnInitDialog(void);

	// ����������� CheckBox
	afx_msg void OnBtn1Click(void);
	afx_msg void OnBtn2Click(void);

	// ���������� ������� ���������
	DECLARE_MESSAGE_MAP();
};

#endif


