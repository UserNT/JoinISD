
// TestDoc.cpp : ���������� ������ CTestDoc
//

#include "stdafx.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
#ifndef SHARED_HANDLERS
#include "DocViewTest.h"
#endif

#include "TestDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CTestDoc

IMPLEMENT_DYNCREATE(CTestDoc, CDocument)

BEGIN_MESSAGE_MAP(CTestDoc, CDocument)
END_MESSAGE_MAP()


// ��������/����������� CTestDoc

CTestDoc::CTestDoc()
{
	// TODO: �������� ��� ��� ������������ ������ ������������

}

CTestDoc::~CTestDoc()
{
}

BOOL CTestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �������� ��� ��������� �������������
	// (��������� SDI ����� �������� ������������ ���� ��������)

	//AfxMessageBox(L"CTestDoc::OnNewDocument()");

	return TRUE;
}




// ������������ CTestDoc

void CTestDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		int nCount = m_list.GetCount();

		ar << nCount;

		Student* st = m_list.GetFirst();
		while (st != NULL)
		{
			st->Serialize(ar);
			st = m_list.GetNext();
		}
	}
	else
	{
		int nCount = 0;
		ar >> nCount;

		for (int i = 0; i < nCount; ++i)
		{
			Student st;
			st.Serialize(ar);

			m_list.PushBack(&st);
		}
	}
}

#ifdef SHARED_HANDLERS

// ��������� ��� �������
void CTestDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �������� ���� ��� ��� ����������� ������ ���������
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ��������� ������������ ������
void CTestDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������� ���������� ������ �� ������ ���������. 
	// ����� ����������� ������ ����������� ������ � ������� ";"

	// ��������:  strSearchContent = _T("�����;�������������;����;������ ole;");
	SetSearchContent(strSearchContent);
}

void CTestDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// ����������� CTestDoc

#ifdef _DEBUG
void CTestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// ������� CTestDoc


void CTestDoc::DeleteContents()
{
	m_list.Clear();
	CDocument::DeleteContents();
}
