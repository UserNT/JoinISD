#pragma once
#ifndef _FrameWnd_h
#define _FrameWnd_h
class FrameWnd : public CFrameWnd
{
private: 
	CButton *m_pBtnExit;
	// Указатель на стандартную нажимаемую кнопку (MessageBox,
	//   выбрана по умолчанию)
	CButton *m_pBtnAbout;
public:
	FrameWnd();
	~FrameWnd();
	virtual void CreateChildControls();
protected:
	afx_msg void OnPaint(void);
	// Обработчик кнопки "О кнопке"
	afx_msg void OnBtnAboutClick(void);
	// Обработчик кнопки "Выход"
	afx_msg void OnBtnExitClick(void);

	// Объявление таблицы сообщений
	DECLARE_MESSAGE_MAP();
};

#endif