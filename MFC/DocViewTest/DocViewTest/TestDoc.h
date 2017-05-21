
// TestDoc.h : ��������� ������ CTestDoc
//


#pragma once

#include "list.h"

#define UPDATE_ADD_STUDENT 1
#define UPDATE_DEL_STUDENT 2
#define UPDATE_EDIT_STUDENT 3

class CTestDoc : public CDocument
{
protected: // ������� ������ �� ������������
	CTestDoc();
	DECLARE_DYNCREATE(CTestDoc)

// ��������
public:
	List m_list;
// ��������
public:

// ���������������
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ����������
public:
	virtual ~CTestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ��������� ������� ����� ���������
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ��������������� �������, �������� ���������� ������ ��� ����������� ������
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	virtual void DeleteContents();
};
