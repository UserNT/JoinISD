#pragma once
/*
����               : Dialog.hpp

������             : ������������ Windows-���������� �� ������
���������� ������� MFC � ����� ����������
�������, ������������ ������

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

	// ��������� �� ����� ������ (MULTI) 
	CListBox        *m_plbMulti;
	// ��������� �� ������ ������ (SINGLE) 
	CListBox        *m_plbSingle;

public:

	// ����������, ��������� �� ��������

	// ����� ������
	// ��������� �� ������ �����
	CString         *m_Enabled;
	// ������ ��������� ������
	int             m_IxEnbLast;

	// ������ ������
	// ��������� �� ������ �����
	CString         *m_Disabled;
	// ������ ��������� ������
	int             m_IxDisLast;

	// ������

public:

	// ����������� - �������� ������������� ������� � �������
	//   �����
	Dialog(CWnd *pParent = 0);

protected:

	// ����������� ����������� ����� ��� ������������� �������
	virtual BOOL OnInitDialog(void);

	// ����������� ����������� ����� ��� ��������� ����������
	//   �� �������
	virtual void OnOK(void);

	// ���������� ������ �������� ������ �� ������ ������ �
	//   ������
	afx_msg void OnButtonLRClick(void);
	// ���������� ������ �������� ������ �� ������� ������ �
	//   �����
	afx_msg void OnButtonRLClick(void);

	DECLARE_MESSAGE_MAP();
};

#endif
