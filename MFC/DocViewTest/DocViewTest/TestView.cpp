
// TestView.cpp : реализация класса CTestView
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "DocViewTest.h"
#endif

#include "TestDoc.h"
#include "TestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "StudentEditDlg.h"
// CTestView

IMPLEMENT_DYNCREATE(CTestView, CListView)

BEGIN_MESSAGE_MAP(CTestView, CListView)
	ON_COMMAND(ID_MODIFY_ADD, OnAdd)
	ON_COMMAND(ID_MODIFY_DELETE, OnDelete)
	ON_UPDATE_COMMAND_UI(ID_MODIFY_DELETE, OnUpdateDelete)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// создание/уничтожение CTestView

CTestView::CTestView()
{
	// TODO: добавьте код создания

}

CTestView::~CTestView()
{
}

BOOL CTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CListView::PreCreateWindow(cs);
}

void CTestView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();

	GetListCtrl().DeleteAllItems();
	FillList();
	// TODO: ListView можно заполнить элементами посредством непосредственного обращения
	//  к элементам управления этого списка через вызов GetListCtr().
}


// диагностика CTestView

#ifdef _DEBUG
void CTestView::AssertValid() const
{
	CListView::AssertValid();
}

void CTestView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CTestDoc* CTestView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestDoc)));
	return (CTestDoc*)m_pDocument;
}
#endif //_DEBUG


// обработчики сообщений CTestView


int CTestView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CListView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here

	ModifyStyle(LVS_TYPEMASK, LVS_REPORT);

	GetListCtrl().InsertColumn(0, L"Name", LVCFMT_LEFT, 150);
	GetListCtrl().InsertColumn(1, L"Mark", LVCFMT_LEFT, 150);

	m_imageList.Create(16, 16, ILC_COLOR32 | ILC_MASK, 1, 1);
	m_imageList.Add(AfxGetApp()->LoadIcon(IDI_ICON_STUDENTS));

	GetListCtrl().SetImageList(&m_imageList, LVSIL_SMALL);

	return 0;
}

void  CTestView::OnAdd()
{
	CStudentEditDlg dlg;

	if (IDOK == dlg.DoModal())
	{
		//Добавить студента
		Student st;

		st.SetName(dlg.m_strName);
		st.SetMark(dlg.m_fMark);

		GetDocument()->m_list.PushBack(&st);

		GetDocument()->SetModifiedFlag(TRUE);

		GetDocument()->UpdateAllViews(NULL, UPDATE_ADD_STUDENT, NULL);

		FillList();
	}
}
void CTestView::OnDelete()
{
	if (IDYES != MessageBox(L"Удалить студента", L"Подтверждение", MB_YESNO | MB_ICONQUESTION))
	{
		return;
	}

	CListCtrl& rList = GetListCtrl();

	POSITION pos = rList.GetFirstSelectedItemPosition();

	while (pos)
	{
		int nItem = rList.GetNextSelectedItem(pos);

		Student* st = GetDocument()->m_list.GetFirst();

		while (st != NULL)
		{
			if (st == (Student*)rList.GetItemData(nItem))
			{
				GetDocument()->m_list.RemoveCurrent();
				break;
			}
			st = GetDocument()->m_list.GetNext();
		}
	}

	GetDocument()->SetModifiedFlag(TRUE);

	GetDocument()->UpdateAllViews(NULL, UPDATE_DEL_STUDENT, NULL);
}

void CTestView::OnUpdateDelete(CCmdUI* pCmdUI)
{
	BOOL bEnable = FALSE;
	if (GetListCtrl().GetSelectedCount() > 0)
		bEnable = TRUE;

	pCmdUI->Enable(bEnable);
}

void CTestView::FillList()
{
	CListCtrl& rList = GetListCtrl();


	rList.DeleteAllItems();

	Student* st = GetDocument()->m_list.GetFirst();

	for (; st!= NULL; st = GetDocument()->m_list.GetNext())
	{
		int nPos = rList.InsertItem(rList.GetItemCount(), st->GetName(), 0);

		CString sMark;
		sMark.Format(L"%g", st->GetMark());		
		rList.SetItemText(nPos, 1, sMark);
		rList.SetItemData(nPos, (DWORD_PTR) st);
	}
}

void CTestView::OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* pHint)
{
	FillList();
}
