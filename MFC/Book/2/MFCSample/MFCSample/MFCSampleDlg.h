
// MFCSampleDlg.h : файл заголовка
//

#pragma once
#include "afxwin.h"


// диалоговое окно CMFCSampleDlg
class CMFCSampleDlg : public CDialog
{
// Создание
public:
	CMFCSampleDlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCSAMPLE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	COLORREF m_currentColor;
	void DrawBitmapWithColor();
	HICON m_hIcon;
	CBitmap m_bmpColor;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnNeedToolTipText(UINT id, NMHDR* pTTTStruct, LRESULT* pResult);
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CButton m_pbFile;
//	afx_msg void OnNcXButtonDblClk(short nFlags, UINT nButton, CPoint point);
	afx_msg void OnPbFile();
	CButton m_stColor;
	CButton m_stFont;
	CString m_foleName;
	CButton m_pbCustomModeless;
	afx_msg void OnPbColor();
	CString m_stFont2;
	afx_msg void OnPbFont();
	CEdit m_ctrlFont;
};
