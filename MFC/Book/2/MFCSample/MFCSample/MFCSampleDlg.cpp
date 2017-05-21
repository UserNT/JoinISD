
// MFCSampleDlg.cpp : файл реализации
//

#include "stdafx.h"
#include "MFCSample.h"
#include "MFCSampleDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
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


// диалоговое окно CMFCSampleDlg



CMFCSampleDlg::CMFCSampleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_MFCSAMPLE_DIALOG, pParent), m_currentColor(RGB(0,0,225))
	, m_foleName(_T(""))
	, m_stFont2(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PB_FILE, m_pbFile);
	DDX_Control(pDX, IDC_PB_COLOR, m_stColor);
	DDX_Control(pDX, IDC_PB_FONT, m_stFont);
	DDX_Text(pDX, IDC_EDIT1, m_foleName);
	DDX_Control(pDX, IDC_PB_CUSTOM_MODELESS, m_pbCustomModeless);
	//DDX_Text(pDX, IDC_EDIT2, m_stFont2);
	DDX_Control(pDX, IDC_EDIT2, m_ctrlFont);
}

BEGIN_MESSAGE_MAP(CMFCSampleDlg, CDialog)
	//ON_NOTIFY_EX(TTN_NEEDTEXT, 0, OnNeedToolTipText)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//	ON_WM_NCXBUTTONDBLCLK()
ON_BN_CLICKED(IDC_PB_FILE, &CMFCSampleDlg::OnPbFile)
ON_BN_CLICKED(IDC_PB_COLOR, &CMFCSampleDlg::OnPbColor)
ON_BN_CLICKED(IDC_PB_FONT, &CMFCSampleDlg::OnPbFont)
END_MESSAGE_MAP()


// обработчики сообщений CMFCSampleDlg

BOOL CMFCSampleDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
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

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	EnableToolTips();
	DrawBitmapWithColor();

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CMFCSampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CMFCSampleDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CMFCSampleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



//void CMFCSampleDlg::OnNcXButtonDblClk(short nFlags, UINT nButton, CPoint point)
//{
//	// This feature requires Windows 2000 or greater.
//	// The symbols _WIN32_WINNT and WINVER must be >= 0x0500.
//	// TODO: Add your message handler code here and/or call default
//
//	CDialog::OnNcXButtonDblClk(nFlags, nButton, point);
//}

//BOOL CMFCSampleDlg::OnNeedToolTipText(UINT id, NMHDR* pNMHdr, LRESULT* pResult)
//{
//	TOOLTIPTEXT* pTTT = (TOOLTIPTEXT*)pNMHdr;
//	if (pTTT->uFlags & TTF_IDISHWND)
//	{
//		UINT idCtrl = ::GetDlgCtrlID(HWND(pTTT->hdr.idFrom));
//		if (idCtrl == IDC_PB_CUSTOM_MODELESS && m_customDlg.m_hWnd)
//			pTTT->lpszText = MAKEINTRESOURCE(IDS_TT_PB_CUSTOM_MODELESS2);
//		else
//			pTTT->lpszText = MAKEINTRESOURCE(idCtrl);
//
//		pTTT->hinst = AfxGetResourceHandle();
//		return TRUE;
//	}
//
//	return FALSE;
//}

void CMFCSampleDlg::OnPbFile()
{
	CFileDialog fileDlg(TRUE);
	if (fileDlg.DoModal() == IDOK)
	{
		m_foleName = fileDlg.GetFileName();
		UpdateData(FALSE);
	}
}


void CMFCSampleDlg::OnPbColor()
{
	CColorDialog colorDlg(m_currentColor);
	if (colorDlg.DoModal() == IDOK)
	{
		m_currentColor = colorDlg.GetColor();
		DrawBitmapWithColor();
	}
}
void CMFCSampleDlg::DrawBitmapWithColor()
{
	CWindowDC wndDC(this);
	CDC       memDC;
	CRect     rcColor;
	CBrush    brush(m_currentColor);

	m_stColor.GetClientRect(&rcColor);

	memDC.CreateCompatibleDC(&wndDC);

	m_stColor.SetBitmap(0);
	m_bmpColor.Detach();
	m_bmpColor.CreateCompatibleBitmap(&wndDC, rcColor.right, rcColor.bottom);

	memDC.SelectObject(&m_bmpColor);
	memDC.SelectObject(&brush);
	memDC.Rectangle(&rcColor);

	m_stColor.SetBitmap(m_bmpColor);
	m_stColor.Invalidate();	
}

void CMFCSampleDlg::OnPbFont()
{
	CFontDialog fontDlg;
	if (fontDlg.DoModal() == IDOK)
	{
		CFont font;
		LOGFONT logFont;

		fontDlg.GetCurrentFont(&logFont);
		font.CreateFontIndirectW(&logFont);

		m_ctrlFont.SetFont(&font);
	}
}
