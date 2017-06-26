#pragma once
#ifndef _FrameWnd_h
#define _FrameWnd_h
class FrameWnd : public CFrameWnd
{
private: 
	CButton *m_pBtnExit;
	// ��������� �� ����������� ���������� ������ (MessageBox,
	//   ������� �� ���������)
	CButton *m_pBtnAbout;
public:
	FrameWnd();
	~FrameWnd();
	virtual void CreateChildControls();
protected:
	afx_msg void OnPaint(void);
	// ���������� ������ "� ������"
	afx_msg void OnBtnAboutClick(void);
	// ���������� ������ "�����"
	afx_msg void OnBtnExitClick(void);

	// ���������� ������� ���������
	DECLARE_MESSAGE_MAP();
};

#endif