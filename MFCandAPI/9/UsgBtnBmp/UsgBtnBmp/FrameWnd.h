#pragma once
#ifndef _FrameWnd_h
#define _FrameWnd_h
// ���������� ������
class FrameWnd : public CFrameWnd
{
	// ������

protected:

	// ��������� �������, �������������� ���������
	// ��������� ������� ���� | �����
	afx_msg void OnMenuFileExit(void);
	// ��������� ������� ��������� ������ | ������
	afx_msg void OnMenuBitmapButtons(void);

	// ���������� ������� ���������
	DECLARE_MESSAGE_MAP();

};

#endif