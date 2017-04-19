
// MainDlg.h : файл заголовка
//
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "afxcmn.h"
#include "list.h"


// диалоговое окно CMainDlg
class CMainDlg : public CDialog
{
// Создание
public:
	CMainDlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LISTCTRLDEMO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;
	List m_list;
	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_ctrlList;
	void FilList();
	afx_msg void OnBtnAbout();
	afx_msg void OnBtnDelete();
	afx_msg void OnBtnEdit();
	afx_msg void OnBtnAdd();
};
