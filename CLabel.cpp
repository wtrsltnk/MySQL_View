#include "CLabel.h"
#include <commctrl.h>

CLabel::CLabel(class CWin* parent)
    : CControl(parent, ControlTypes::Label, "STATIC")
{
    this->_windowStyles = WS_VISIBLE | WS_CHILD;
    this->_windowStylesEx = WS_EX_WINDOWEDGE;
}

CLabel::~CLabel( void )
{
}
