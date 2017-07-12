#pragma once
/*
����               : Dialog.hpp

������             : ������������ ������� Windows-���������� ��
������ ���������� ������� MFC (������ -
��������� ������ � �������������)

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

	// ��������� �� ����������� ������� ����� "��������"
	CButton         *pRadioSolid;
	// ��������� �� ����������� ������� ����� "���������"
	CButton         *pRadioDash;
	// ��������� �� ����������� ������� ����� "��������"
	CButton         *pRadioDot;

public:

	int             m_PenStyle; // ����� ���������

public:

	// ����������� - �������� ������������� ������� � �������
	//   �����
	Dialog(CWnd *pParent = 0);

protected:

	// ����������� ����������� ����� ��� ������������� �������
	virtual BOOL OnInitDialog(void);
	// ����������� ����������� ����� ��� �������� ������� ��
	//   ������ ��
	virtual void OnOK(void);

	// ����������� ����������� (� ������ ������ ��� ���������)
	/*afx_msg void OnRadioSolidClick( void );
	afx_msg void OnRadioDashClick( void );
	afx_msg void OnRadioDotClick( void );*/

	// ���������� ������� ���������
	DECLARE_MESSAGE_MAP();
};

#endif

