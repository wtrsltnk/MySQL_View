#include "CEdit.h"
#include <commctrl.h>

CEdit::CEdit(class CWin* parent )
    : CControl(parent)
{ }

CEdit::~CEdit( void )
{ }

bool CEdit::create()
{
    m_hWnd = CreateWindowEx( WS_EX_WINDOWEDGE, "EDIT", "",
                             WS_BORDER | WS_VISIBLE | WS_CHILD |
                             ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL,
                             m_nX, m_nY, m_nWidth, m_nHeight,
                             ParentWindow(), (HMENU)0, Application(), NULL);

    return m_hWnd != NULL;
}
