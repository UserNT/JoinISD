
// MainDlg.h : ���� ���������
//
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "afxcmn.h"
#include "list.h"


// ���������� ���� CMainDlg
class CMainDlg : public CDialog
{
// ��������
public:
	CMainDlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LISTCTRLDEMO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// ��������� DDX/DDV
	public:
		static int CALLBACK CompareFunc(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort);

// ����������
protected:
	HICON m_hIcon;
	List m_list;

	int m_nSortColumn;
	BOOL m_hSortAsc;
	// ��������� ������� ����� ���������
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
	afx_msg void OnDblclkListStudents(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnHdnItemclickListStudents(NMHDR *pNMHDR, LRESULT *pResult);
};
