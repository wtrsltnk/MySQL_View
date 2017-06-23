#include "CLabel.h"
#include <commctrl.h>

CLabel::CLabel(class CWin* parent)
    : CControl(parent)
{ }

CLabel::~CLabel( void )
{
}

bool CLabel::create()
{
    m_hWnd = CreateWindowEx(WS_EX_WINDOWEDGE, "STATIC", "Label",
                            WS_VISIBLE | WS_CHILD,
                            m_nX, m_nY, m_nWidth, m_nHeight,
                            ParentWindow(), (HMENU)0, Application(), NULL);

    return m_hWnd != NULL;
}
