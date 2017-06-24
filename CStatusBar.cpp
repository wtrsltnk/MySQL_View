#include "CStatusBar.h"
#include <commctrl.h>

/////////////////////////////////////
// Constructors / Destructors      //
/////////////////////////////////////

CStatusBar::CStatusBar(class CWin* parent)
    : CControl(parent, ControlTypes::StatusBar, STATUSCLASSNAME), _partCount(0)
{
    this->_windowStyles = WS_CHILD | WS_VISIBLE;
    this->onCreateControl += [this] (const CreateControlArgs& args)
    {
        if (this->_partCount > 0)
        {
            this->setParts(this->_partCount, this->_parts);
        }
    };
}

CStatusBar::~CStatusBar()
{ }

CStatusBar& CStatusBar::setParts(int count, int parts[])
{
    this->_partCount = count;
    this->_parts = parts;

    if (this->_windowHandle != 0)
    {
        SendMessage(_windowHandle, SB_SETPARTS, count, (LPARAM)parts);
    }

    return *this;
}

void CStatusBar::resize(int x, int y, int width, int height)
{
    SendMessage(_windowHandle, WM_SIZE, 0, MAKELPARAM(width, height));
}

CStatusBar& CStatusBar::setItemText(int index, string strText)
{
    //set de text in een van de statusbar vakjes
    SendMessage(_windowHandle, SB_SETTEXT, (WPARAM) index-1|0, (LPARAM)strText.c_str());

    return *this;
}
