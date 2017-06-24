#include "CCombo.h"
#include <commctrl.h>

CCombo::CCombo(class CWin* parent)
    : CControl(parent, ControlTypes::Combo, "COMBOBOX")
{
    this->_windowStyles = WS_BORDER | WS_VISIBLE | WS_CHILD | WS_TABSTOP |
            CBS_DROPDOWN |  CBS_HASSTRINGS;
    this->_windowStylesEx = WS_EX_WINDOWEDGE;
}

CCombo::~CCombo( void )
{ }

void CCombo::addItem( string text )
{
    SendMessage( m_hWnd, CB_ADDSTRING, 0, (LPARAM)(LPCTSTR)&text );
}
