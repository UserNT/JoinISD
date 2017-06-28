
#ifndef _FrameWnd_h
#define _FrameWnd_h

// ���������� ������
class FrameWnd : public CFrameWnd
{
	// ������

private:

	// ������� �����
	CPoint          Vert0;      // ����� �������
	CPoint          Vert1;      // ������� �������
	CPoint          Vert2;      // ������ �������
	CPoint          Vert3;      // ������ �������

								// ��������� ���������
	int             m_PenWidth; // �������
	COLORREF        m_PenRGB;   // RGB-����
	int             m_PenStyle; // �����

								// ������

public:

	// ����������� ��������� (������������� ����������
	//   ���������)
	FrameWnd(void);

protected:

	// ��������� �������, �������������� ���������
	// ����������� ����
	afx_msg void OnPaint(void);
	// ��������� ������� ���� | �����
	afx_msg void OnMenuFileExit(void);
	// ��������� ������� ����� ��������� | ��������
	afx_msg void OnMenuPenstyleSolid(void);
	// ��������� ������� ����� ��������� | �������
	afx_msg void OnMenuPenstyleDash(void);
	// ��������� ������� ����� ��������� | ��������
	afx_msg void OnMenuPenstyleDot(void);

private:

	// ����������� ����� � ���������� ������� ����
	// ������� ������ �����
	void SetRhombVertexes(void);
	// ��������� �����
	void DrawRhomb(CDC *pDC);

	// ���������� ������� ���������
	DECLARE_MESSAGE_MAP();
};

#endif
