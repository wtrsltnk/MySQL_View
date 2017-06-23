#include "CButton.h"
#include <commctrl.h>

CButton::CButton(class CWin* parent)
    : CControl(parent)
{ }

CButton::~CButton()
{ }

bool CButton::create()
{
    m_hWnd = CreateWindowEx( WS_EX_STATICEDGE, "BUTTON", "->",
                             WS_VISIBLE | WS_CHILD,
                             m_nX, m_nY, m_nWidth, m_nHeight,
                             ParentWindow(), (HMENU)0, Application(), NULL);

    SetWindowLongPtr(m_hWnd, GWL_USERDATA, (LONG_PTR)this);

    return m_hWnd != NULL;
}
