#include "CControl.h"
#include "CWin.h"
#include "CApplication.h"

CControl::CControl(CWin* parent)
    : m_parent(parent)
{ }

CControl::~CControl()
{ }

ApplicationHandle CControl::Application() const { return this->m_parent->Application(); }

WindowHandle CControl::ParentWindow() const { return this->m_parent->m_hWnd; }

void CControl::resize( int x, int y, int width, int height )
{
    this->m_nX = x;
    this->m_nY = y;
    this->m_nWidth = width;
    this->m_nHeight = height;

    MoveWindow( m_hWnd, m_nX, m_nY, m_nWidth, m_nHeight, true );
}

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
