#include "CStatusBar.h"
#include <commctrl.h>

/////////////////////////////////////
// Constructors / Destructors      //
/////////////////////////////////////

CStatusBar::CStatusBar(class CWin* parent)
    : CControl(parent)
{ }

CStatusBar::~CStatusBar()
{ }

/////////////////////////////////////
// Memberfuncties                  //
/////////////////////////////////////

bool CStatusBar::create()
{
    const int noParts = 3;
    int parts[noParts];

    //maak drie statusbar vakjes aan
    parts[0] = 300;
    parts[1] = parts[0] + 350;
    parts[2] = -1;

    //creeer de statusbar window
    m_hWnd = CreateStatusWindow(WS_CHILD | WS_VISIBLE, "", ParentWindow(), 1);

    //voeg de aangemaakte vakjes toe
    SendMessage(m_hWnd, SB_SETPARTS, noParts, (LPARAM)parts);
    SendMessage(m_hWnd, SB_SETMINHEIGHT, 16, 0);

    return m_hWnd != NULL;
}

void CStatusBar::resize(int x, int y, int width, int height)
{
    SendMessage(m_hWnd, WM_SIZE, NULL, MAKELPARAM(width, height));
}

void CStatusBar::setItemText(int index, string strText)
{
    //set de text in een van de statusbar vakjes
    SendMessage(m_hWnd, SB_SETTEXT, (WPARAM) index-1|0, (LPARAM)strText.c_str());
}
