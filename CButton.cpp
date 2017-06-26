#include "CButton.h"
#include <commctrl.h>

CButton::CButton(class CWin* parent)
    : CControl(parent, ControlTypes::Button, "BUTTON")
{
    this->_windowStyles = WS_VISIBLE | WS_CHILD | WS_TABSTOP;
    this->_windowStylesEx = WS_EX_STATICEDGE;
}

CButton::~CButton()
{ }
