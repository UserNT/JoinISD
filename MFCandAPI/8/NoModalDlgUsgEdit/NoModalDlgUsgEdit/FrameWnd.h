#pragma once
#ifndef _FrameWnd_h
#define _FrameWnd_h

// ���������� ������
class FrameWnd : public CFrameWnd
{
	// ������

private:

	// ��� ������ ������������� ���������
	CString            e1;

	// ������

public:

	// ����������� ��������� (������������� ������
	//   ������������� ���������)
	FrameWnd(void);

protected:

	// ��������� �������, �������������� ���������
	// ��������� ������� "�����"
	afx_msg void OnMenuExit(void);
	// ��������� ������� "�����������_������"
	afx_msg void OnMenuDialog(void);

	// ���������� ������� ���������
	DECLARE_MESSAGE_MAP();
};

#endif