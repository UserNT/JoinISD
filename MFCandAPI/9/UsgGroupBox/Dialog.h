/*
   ����               : Dialog.hpp

   ������             : ������������ Windows-���������� �� ������
                        ���������� ������� MFC � ����� ����������
                        �������, ������������ GroupBox

   ����������         : ���������� ������ "Dialog", ������������
                        �� ������ "CDialod" ���������� �������
                        MFC (��������� ��������� ���� �������)

   Microsoft Visual Studio C++ .NET 2005
*/

// �������������� ����������� ������������� ����������� �������
//   �����
#ifndef _Dialog_h
    #define _Dialog_h

    // ���������� ������
    class Dialog : public CDialog
    {
        // ������

    private:

        // ��������� �� ����������� 11 (������ 1, ������ 1)
        CButton         *m_pRadio11;
        // ��������� �� ����������� 12 (������ 1, ������ 2)
        CButton         *m_pRadio12;
        // ��������� �� ����������� 13 (������ 1, ������ 3)
        CButton         *m_pRadio13;
        // ��������� �� ����������� 21 (������ 2, ������ 1)
        CButton         *m_pRadio21;
        // ��������� �� ����������� 22 (������ 2, ������ 2)
        CButton         *m_pRadio22;
        // ��������� �� ����������� 23 (������ 2, ������ 3)
        CButton         *m_pRadio23;

    public:

        int             m_Radio1;   // ����������� 1
        int             m_Radio2;   // ����������� 2

    public:

        // ����������� - �������� ������������� ������� � �������
        //   �����
        Dialog( CWnd *pParent = 0 );

    protected:

        // ����������� ����������� ����� ��� ������������� �������
        virtual BOOL OnInitDialog( void );

        // ����������� �����������
        afx_msg void OnRadio11Click( void );
        afx_msg void OnRadio12Click( void );
        afx_msg void OnRadio13Click( void );
        afx_msg void OnRadio21Click( void );
        afx_msg void OnRadio22Click( void );
        afx_msg void OnRadio23Click( void );

        // ���������� ������� ���������
        DECLARE_MESSAGE_MAP( );
    };

#endif
