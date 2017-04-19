
// MainDlg.cpp : ���� ����������
//

#include "stdafx.h"
#include "DlgDemo2.h"
#include "MainDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���������� ���� CAboutDlg ������������ ��� �������� �������� � ����������

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

// ����������
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// ���������� ���� CMainDlg



CMainDlg::CMainDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DLGDEMO2_DIALOG, pParent)
	, m_sFileIn(_T(""))
	, m_sFileOut(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_FILEIN, m_sFileIn);
	DDX_Text(pDX, IDC_EDIT_FILEOUT, m_sFileOut);
}

BEGIN_MESSAGE_MAP(CMainDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_GETFILEIN, &CMainDlg::OnGetFileIn)	
	ON_BN_CLICKED(IDC_BTN_GETFILEOUT, &CMainDlg::OnBtnGetFileOut)
	ON_BN_CLICKED(IDC_BUT_PROCESS, &CMainDlg::OnBnClickedButProcess)
END_MESSAGE_MAP()


// ����������� ��������� CMainDlg

BOOL CMainDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���������� ������ "� ���������..." � ��������� ����.

	// IDM_ABOUTBOX ������ ���� � �������� ��������� �������.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ������ ������ ��� ����� ����������� ����.  ����� ������ ��� �������������,
	//  ���� ������� ���� ���������� �� �������� ����������
	SetIcon(m_hIcon, TRUE);			// ������� ������
	SetIcon(m_hIcon, FALSE);		// ������ ������

	m_sFileIn = L"input.txt";
	m_sFileOut = L"output.txt";

	UpdateData(FALSE);

	return TRUE;  // ������� �������� TRUE, ���� ����� �� ������� �������� ����������
}

void CMainDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��� ���������� ������ ����������� � ���������� ���� ����� ��������������� ����������� ���� �����,
//  ����� ���������� ������.  ��� ���������� MFC, ������������ ������ ���������� ��� �������������,
//  ��� ������������� ����������� ������� ��������.

void CMainDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �������� ���������� ��� ���������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ������������ ������ �� ������ ����������� ��������������
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ��������� ������
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ������� �������� ��� ������� ��� ��������� ����������� ������� ��� �����������
//  ���������� ����.
HCURSOR CMainDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMainDlg::OnGetFileIn()
{
	/*UpdateData(TRUE);
	CString sMsg;
	sMsg = L"������������ ����: ";
	sMsg += m_sFileIn;
	MessageBox(sMsg, L"���������", MB_OK | MB_ICONINFORMATION);*/

	/*CFileDialog dlg(TRUE);

	if (dlg.DoModal() == IDOK)
	{
		m_sFileIn = dlg.m_ofn.lpstrFile;
		UpdateData(FALSE);
		m_sFileOut = m_sFileIn;
		CString temp = L"�� ������� ���� : ";
		temp += m_sFileOut;
		m_sFileOut = temp;
		UpdateData(FALSE);
	}
*/
	CFileDialog dlg(TRUE);

	if (dlg.DoModal() == IDOK)
	{
		m_sFileIn = dlg.m_ofn.lpstrFile;
		UpdateData(FALSE);		
	}
	


}




void CMainDlg::OnBtnGetFileOut()
{
	CFileDialog dlg(FALSE);

	if (dlg.DoModal() == IDOK)
	{
		m_sFileOut = dlg.m_ofn.lpstrFile;
		UpdateData(FALSE);
	}
}


void CMainDlg::OnBnClickedButProcess()
{
	UpdateData(TRUE);

	if (ProcessFiles(m_sFileIn, m_sFileOut) != TRUE)
	{
		MessageBox(L"��������� ����� ����������� � �������!", L"������", MB_OK | MB_ICONERROR);
	}
	else
		MessageBox(L"���� ��������� �������", L"���������", MB_OK | MB_ICONINFORMATION);
}


BOOL CMainDlg::ProcessFiles(CString m_sFileIn, CString m_sFileOut)
{
	CFile filein;

	if (filein.Open(m_sFileIn, CFile::modeRead) == FALSE)
	{
		
		CString sMsg;
		sMsg.Format(L"�� ���� ������� ���� %s", m_sFileIn);
		
		MessageBox(sMsg, L"������", MB_OK | MB_ICONERROR);
		return FALSE;
	}

	CFile fileOut;
	
	if (!(fileOut.Open(m_sFileOut, CFile::modeWrite | CFile::modeCreate)))
	{
		CString sMsg;
		sMsg.Format(L"�� ���� ������� ���� ����������%s", m_sFileOut);

		MessageBox(sMsg, L"������", MB_OK | MB_ICONERROR);
		return FALSE;
	}

	/*int a;
	filein.Read(&a, sizeof(int));
	fileOut.Write(&a, sizeof(int));*/

	return TRUE;
}
