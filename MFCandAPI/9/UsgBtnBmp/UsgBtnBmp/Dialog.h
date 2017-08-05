#pragma once

#ifndef _Dialog_h
#define _Dialog_h

// ���������� ������
class Dialog : public CDialog
{
	// ������

private:

	// �������� ���������� ������ - ���������� �����������
	//   ���������
	CBitmapButton   BmpBtn1;    // ������ 1
	CBitmapButton   BmpBtn2;    // ������ 2

								// ������

public:

	// ����������� - �������� ������������� ������� � �������
	//   �����
	Dialog(CWnd *  pParent = 0);

protected:

	// ����������� ����������� ����� ��� ������������� �������
	virtual BOOL OnInitDialog(void);

	// ����������� ���������� ������
	afx_msg void OnBmpBtn1Click(void);
	afx_msg void OnBmpBtn2Click(void);

	// ���������� ������� ���������
	DECLARE_MESSAGE_MAP();
};

#endif
