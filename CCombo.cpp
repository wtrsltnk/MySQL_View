#include "CCombo.h"
#include <commctrl.h>

CCombo::CCombo(class CWin* parent)
    : CControl(parent)
{ }

CCombo::~CCombo( void )
{ }

bool CCombo::create()
{
    m_hWnd = CreateWindowEx( WS_EX_WINDOWEDGE, "COMBOBOX", "",
                             WS_BORDER | WS_VISIBLE | WS_CHILD | WS_TABSTOP |
                             CBS_DROPDOWN |  CBS_HASSTRINGS,
                             m_nX, m_nY, m_nWidth, m_nHeight,
                             ParentWindow(), (HMENU)0, Application(), (LPVOID)this);

    return m_hWnd != NULL;
}

void CCombo::addItem( string text )
{
    SendMessage( m_hWnd, CB_ADDSTRING, 0, (LPARAM)(LPCTSTR)&text );
}
