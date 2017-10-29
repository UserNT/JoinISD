
// Task01.cpp : implementation of the CTask01 class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Task1.h"
#endif

#include "AuthenticationDlg.h"
#include "Task1Doc.h"
#include "Task01.h"
#include "Attachments.h"
#include "Comments.h"
#include "General.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTask01

IMPLEMENT_DYNCREATE(CTask01, CFormView)

BEGIN_MESSAGE_MAP(CTask01, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CTask01 construction/destruction

CTask01::CTask01()
	: CFormView(IDD_TASK1_FORM)
	, m_stringBugName(_T("Hello World"))
{
	// TODO: add construction code here

}

CTask01::~CTask01()
{
}

void CTask01::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);

	//{{AFX_DATA_MAP (CTask01)
	DDX_Control(pDX, IDC_TAB1, m_tabMyTabCtrl);
	//}}AFX_DATA_MAP

	DDX_Text(pDX, IDC_EDIT, m_stringBugName);
	DDX_Control(pDX, IDC_LIST1, m_listBugStatus);
}

BOOL CTask01::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CTask01::OnInitialUpdate()
{
	
	AuthenticationDlg dlg;
	dlg.ListUser = GetDocument()->ListUser;
	dlg.m_sLogin = _T("Insert login");
	dlg.DoModal();

	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	m_listBugStatus.InsertColumn(0, _T("Bug"), LVCFMT_CENTER, 70);
	m_listBugStatus.InsertColumn(1, _T("Date"), LVCFMT_CENTER, 70);
	m_listBugStatus.InsertColumn(2, _T("Assigned to"), LVCFMT_CENTER, 70);
	m_listBugStatus.InsertColumn(3, _T("Status"), LVCFMT_CENTER, 70);

	int nItem = m_listBugStatus.InsertItem(m_listBugStatus.GetItemCount(), _T("Hello World"));
	m_listBugStatus.SetItemText(nItem, 1, _T("2/9/2017"));
	m_listBugStatus.SetItemText(nItem, 2, _T("Vitalij"));
	m_listBugStatus.SetItemText(nItem, 3, _T("Closed"));

	nItem = m_listBugStatus.InsertItem(m_listBugStatus.GetItemCount(), _T("Lessons #20"));
	m_listBugStatus.SetItemText(nItem, 1, _T("2/9/2017"));
	m_listBugStatus.SetItemText(nItem, 2, _T("Vitalij"));
	m_listBugStatus.SetItemText(nItem, 3, _T("New"));
	/*CGeneral dlgTabG;
	dlgTabG.m_stingPerson = _T("Vitalij");*/
	//dlgTabG.UpdateData(FALSE);
	m_tabMyTabCtrl.InsertItem(0, _T("General"));
	m_tabMyTabCtrl.InsertItem(1, _T("Comments"));
	m_tabMyTabCtrl.InsertItem(2, _T("Attachments"));

	m_tabMyTabCtrl.Init();

	
}

void CTask01::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTask01::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CTask01 diagnostics

#ifdef _DEBUG
void CTask01::AssertValid() const
{
	CFormView::AssertValid();
}

void CTask01::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CTask1Doc* CTask01::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTask1Doc)));
	return (CTask1Doc*)m_pDocument;
}
#endif //_DEBUG


// CTask01 message handlers
