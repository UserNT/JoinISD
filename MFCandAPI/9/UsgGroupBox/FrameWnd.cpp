/*
   ����               : FrameWnd.cpp

   ������             : ������������ Windows-���������� �� ������
                        ���������� ������� MFC � ����� ����������
                        �������, ������������ GroupBox

   ����������         : ���������� ������ "FrameWnd", ������������
                        �� ������ "CFrameWnd" ���������� �������
                        MFC (��������� ��������� �������� ����)

   Microsoft Visual Studio C++ .NET 2005
*/

#include "StdAfx.h"                 // ���������������� ����
#include "FrameWnd.h"             // ���������� ������ FrameWnd
#include "Dialog.h"               // ���������� ������ Dialog
// �������������� �������� (��������� ���������� ��������)
#include "resource.h"

// ����������� ������� ���������
BEGIN_MESSAGE_MAP( FrameWnd, CFrameWnd )
    ON_COMMAND( ID_FILE_EXIT, OnMenuFileExit )
    ON_COMMAND( ID_RADIO_BUTTONS, OnMenuRadioButtons )
END_MESSAGE_MAP( )

// ����������� ��������� (������������� �����������)
FrameWnd :: FrameWnd( void )
{
    m_Radio1 = 1;
    m_Radio2 = 5;
}

// ��������� ������� ���� | �����
afx_msg void FrameWnd :: OnMenuFileExit( void )
{
    BOOL                rc = MessageBeep( -1 );
    if( !rc )
    {
        TRACE0( "\n ������ 2. �������� ���������� MessageBeep \n" );
        exit( 2 ); 
    }
    rc = DestroyWindow( );
    if( !rc )
    {
        TRACE0( "\n ������ 3. ���� �� ���� ��������� \n" );
        exit( 3 ); 
    }

    return afx_msg void( );
}

// ��������� ������� ������_�����_������ | ������
afx_msg void FrameWnd :: OnMenuRadioButtons( void )
{
    // ������� ������ ������� - ������������� ����������
    //   �����������
    Dialog              Dlg( this );

    // �������� ������ ����������� �� ������ FrameWnd � �����
    //   Dialog
    Dlg.m_Radio1 = m_Radio1;
    Dlg.m_Radio2 = m_Radio2;

    // ��������� ��������� ���������� ���� - ��� �����
    //   ������������� ������� ����� ������� OK ��� Cancel
    int                 DlgResult = static_cast<int>
                                    ( Dlg.DoModal( ) );
    if ( DlgResult == IDOK )
    {                               // ����� �� ������� �� ��
        // �������� ������ ����������� �� ������ Dialog � �����
        //   FrameWnd
        m_Radio1 = Dlg.m_Radio1;
        m_Radio2 = Dlg.m_Radio2;
    }

    return afx_msg void( );
}

