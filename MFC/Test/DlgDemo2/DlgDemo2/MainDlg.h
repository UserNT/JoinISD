
// MainDlg.h : ���� ���������
//

#pragma once


// ���������� ���� CMainDlg
class CMainDlg : public CDialogEx
{
// ��������
public:
	CMainDlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLGDEMO2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// ��������� DDX/DDV


// ����������
protected:
	HICON m_hIcon;

	// ��������� ������� ����� ���������
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnGetFileIn();
	CString m_sFileIn;	
	CString m_sFileOut;
	afx_msg void OnBtnGetFileOut();
	afx_msg void OnBnClickedButProcess();
	BOOL ProcessFiles(CString m_sFileIn, CString m_sFileOut);
};
