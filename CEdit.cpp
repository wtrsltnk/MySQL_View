#include "CEdit.h"
#include <commctrl.h>

CEdit::CEdit(class CWin* parent )
    : CControl(parent, ControlTypes::Edit, "EDIT")
{
    this->_windowStyles = WS_BORDER | WS_VISIBLE | WS_TABSTOP |
            WS_CHILD | ES_MULTILINE | ES_AUTOVSCROLL |
            ES_AUTOHSCROLL;
    this->_windowStylesEx = WS_EX_STATICEDGE;
}

CEdit::~CEdit( void )
{ }
