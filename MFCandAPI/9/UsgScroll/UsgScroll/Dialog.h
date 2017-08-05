#pragma once
/*
����               : Dialog.hpp

������             : ������������ Windows-���������� �� ������
���������� ������� MFC � ����� ����������
�������, ������������ ������ ���������

����������         : ���������� ������ "Dialog", ������������
�� ������ "CDialod" ���������� �������
MFC (��������� ���� �������)

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

	// ��������� ��������� ��������, �������� � ������ ������
	CScrollBar      *pScrollBarRed;
	CScrollBar      *pScrollBarGreen;
	CScrollBar      *pScrollBarBlue;

public:

	COLORREF        m_OldRGB;   // ������ RGB-����
	COLORREF        m_NewRGB;   // ����� RGB-����

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

	// ���������� ��������� �� �������������� ������ ���������
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos,
		CScrollBar *pScrollBar);

	// ���������� ������� ���������
	DECLARE_MESSAGE_MAP();
};

#endif
