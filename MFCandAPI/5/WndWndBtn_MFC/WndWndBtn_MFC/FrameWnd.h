#pragma once
#ifndef _FrameWnd_h
#define _FrameWnd_h
class FrameWnd :
	public CFrameWnd
{
public:
	FrameWnd();
	~FrameWnd();
	virtual void CreateChildControls();
private:
	CButton* m_pBtnExit;
	CButton* m_pBtnWnd;
	CButton* m_pBtnAbout;
protected:
	afx_msg void OnPaint();
	afx_msg void OnBtnExitClick();
	afx_msg void OnBtnWndClick();
	afx_msg void OnBtnAboutClick();
		DECLARE_MESSAGE_MAP();
};

#endif