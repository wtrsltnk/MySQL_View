#include "CControl.h"
#include "CWin.h"
#include "CApplication.h"

CControl::CControl(CWin* parent, const ControlTypes type, const char* className)
    : _type(type), _className(className), m_parent(parent)
{ }

CControl::~CControl()
{ }

bool CControl::create()
{
    m_hWnd = CreateWindowExA(this->_windowStylesEx, this->_className,
                             this->getText().c_str(), this->_windowStyles,
                             this->m_nX, this->m_nY, this->m_nWidth, this->m_nHeight,
                             ParentWindow(), (HMENU)0, Application(), NULL);

    SetWindowLongPtr(m_hWnd, GWL_USERDATA, (LONG_PTR)this);

    return m_hWnd != NULL;
}

ApplicationHandle CControl::Application() const { return this->m_parent->Application(); }

WindowHandle CControl::ParentWindow() const { return this->m_parent->_windowHandle; }

void CControl::resize( int x, int y, int width, int height )
{
    this->m_nX = x;
    this->m_nY = y;
    this->m_nWidth = width;
    this->m_nHeight = height;

    MoveWindow( m_hWnd, m_nX, m_nY, m_nWidth, m_nHeight, true );
}

ControlTypes CControl::getType() const { return this->_type; }

std::string CControl::getText() const
{
//    auto len = SendMessage(m_hWnd, WM_GETTEXTLENGTH, 0, 0);
//    auto buffer = new char[len + 1];
//    SendMessage(m_hWnd, WM_GETTEXT, len + 1, (WPARAM)buffer);

//    this->m_strText = std::string(buffer);
//    delete []buffer;

    return this->m_strText;
}

CControl& CControl::setText(const std::string& text)
{
    this->m_strText = text;
    if (m_hWnd != nullptr)
    {
        SendMessage(m_hWnd, WM_SETTEXT, 0, (LPARAM)text.c_str());
    }

    return *this;
}
