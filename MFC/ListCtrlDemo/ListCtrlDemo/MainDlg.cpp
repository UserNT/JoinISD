
// MainDlg.cpp : ���� ����������


#include "stdafx.h"
#include "ListCtrlDemo.h"
#include "MainDlg.h"
#include "afxdialogex.h"
#include "StudentDlg.h"

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
	: CDialog(IDD_LISTCTRLDEMO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_STUDENTS, m_ctrlList);
}

BEGIN_MESSAGE_MAP(CMainDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_ABOUT, &CMainDlg::OnBtnAbout)
	ON_BN_CLICKED(IDC_BTN_DELETE, &CMainDlg::OnBtnDelete)
	ON_BN_CLICKED(IDC_BTN_EDIT, &CMainDlg::OnBtnEdit)
	ON_BN_CLICKED(IDC_BTN_ADD, &CMainDlg::OnBtnAdd)
END_MESSAGE_MAP()


// ����������� ��������� CMainDlg

BOOL CMainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

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

	m_ctrlList.InsertColumn(0, L"���", LVCFMT_LEFT, 200);
	m_ctrlList.InsertColumn(1, L"������", LVCFMT_LEFT, 50);

	/*for (int i = 0; i < 10; i++)
	{
		CString Name;
		Name.Format(L"������� %d", i + 1);
		
		Student st;
		st.SetName(Name);
		st.SetMark(rand() % 100 + 1);
		
		m_list.PushBack(&st);
	}

	FilList();*/
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
		CDialog::OnSysCommand(nID, lParam);
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
		CDialog::OnPaint();
	}
}

// ������� �������� ��� ������� ��� ��������� ����������� ������� ��� �����������
//  ���������� ����.
HCURSOR CMainDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMainDlg::FilList()
{
	m_ctrlList.DeleteAllItems();

	Student* st = m_list.GetFirst();

	while (st != NULL)
	{
		int nItem = m_ctrlList.InsertItem(m_ctrlList.GetItemCount(), st->GetName(), -1);

		CString sMark;
		sMark.Format(L"%g", st->GetMark());

		m_ctrlList.SetItemText(nItem, 1, sMark);

		m_ctrlList.SetItemData(nItem, (DWORD_PTR)st);

		st = m_list.GetNext();
	}
}


void CMainDlg::OnBtnAbout()
{
	CAboutDlg dlg;
	dlg.DoModal();
}


void CMainDlg::OnBtnDelete()
{
	POSITION pos = m_ctrlList.GetFirstSelectedItemPosition();

	if (pos == NULL)
	{
		MessageBox(L"�������� ������� ��� ��������", L"��������", MB_OK | MB_ICONINFORMATION);
		return;
	}

	int nIndex = m_ctrlList.GetNextSelectedItem(pos);

	Student* st = (Student*)m_ctrlList.GetItemData(nIndex);

	CString sMsg;

	sMsg.Format(L"������� �������� %s", st->GetName());

	if (IDYES != MessageBox(sMsg + "?", L"��������", MB_YESNO | MB_ICONQUESTION))
	{
		return;
	}

	for (Student* cur = m_list.GetFirst(); cur != NULL; cur = m_list.GetNext())
	{
		if (cur == st)
		{
			m_list.RemoveCurrent();
			break;
		}
	}

	FilList();
}


void CMainDlg::OnBtnEdit()
{
	if (m_ctrlList.GetSelectedCount() == 0)
	{
		MessageBox(L"�������� ������� ��� ��������������", L"����������", MB_OK | MB_ICONINFORMATION);
		return;
	}

	POSITION pos = m_ctrlList.GetFirstSelectedItemPosition();

	if (pos != NULL)
	{
		int nIndex = m_ctrlList.GetNextSelectedItem(pos);

		Student* st = (Student*)m_ctrlList.GetItemData(nIndex);

		if (st == NULL)
		{
			//todo ���������� ������
			return;
		}

		CStudentDlg dlg;

		dlg.m_sFIO = st->GetName();
		dlg.m_fMark = st->GetMark();

		if (IDOK == dlg.DoModal())
		{
			st->SetName(dlg.m_sFIO);
			st->SetMark(dlg.m_fMark);

			FilList();
		}
	}
	
}


void CMainDlg::OnBtnAdd()
{
	CStudentDlg dlg;	
	
	if (IDOK == dlg.DoModal())
	{
		Student st;
		
		st.SetName(dlg.m_sFIO);
		st.SetMark(dlg.m_fMark);
		

		m_list.PushBack(&st);
		FilList();
	}
}
