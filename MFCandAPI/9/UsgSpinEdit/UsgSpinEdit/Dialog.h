#pragma once
#ifndef _Dialog_h
#define _Dialog_h

// ���������� ������
class Dialog : public CDialog
{
	// ������

private:

	// ��������� ��������� �������������� ��������, �������� �
	//   ������ ������
	CEdit           *pEditRed;
	CEdit           *pEditGreen;
	CEdit           *pEditBlue;

	// ��������� ���������� ��� ��������, �������� � ������
	//   ������
	CSpinButtonCtrl *pSpinRed;
	CSpinButtonCtrl *pSpinGreen;
	CSpinButtonCtrl *pSpinBlue;

	// true - ������������� ���� ������� ���� ��������
	bool            m_InitIsDone;

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

	// ���������� ��������� ����������
	afx_msg void OnEditColor(void);

	DECLARE_MESSAGE_MAP();
};

#endif