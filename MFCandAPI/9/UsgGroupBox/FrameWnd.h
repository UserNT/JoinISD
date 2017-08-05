/*
   ����               : FrameWnd.hpp

   ������             : ������������ Windows-���������� �� ������
                        ���������� ������� MFC � ����� ����������
                        �������, ������������ GroupBox

   ����������         : ���������� ������ "FrameWnd", ������������
                        �� ������ "CFrameWnd" ���������� �������
                        MFC (��������� ��������� �������� ����)

   Microsoft Visual Studio C++ .NET 2005
*/

// �������������� ����������� ������������� ����������� �������
//   �����
#ifndef _FrameWnd_h
    #define _FrameWnd_h

    // ���������� ������
    class FrameWnd : public CFrameWnd
    {
        // ������

    private:

        // ����������, ��������� � GroupBox
        int             m_Radio1;   // ����������� 1
        int             m_Radio2;   // ����������� 2

        // ������

    public:

        // ����������� ��������� (������������� �����������)
        FrameWnd( void );
    
    protected:

        // ��������� �������, �������������� ���������
        // ��������� ������� ���� | �����
        afx_msg void OnMenuFileExit( void );
        // ��������� ������� ������_�����_������ | ������
        afx_msg void OnMenuRadioButtons( void );

        // ���������� ������� ���������
        DECLARE_MESSAGE_MAP( );
    };

#endif
