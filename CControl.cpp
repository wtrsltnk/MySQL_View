#include "CControl.h"
#include "CWin.h"
#include "CApplication.h"
#include<fmt/format.h>

Log* CControl::_logger = Log::Create<CControl>();

CControl::CControl(CWin* parent, const ControlTypes type, const char* className)
    : _type(type), _className(className), _windowStyles(0), _windowStylesEx(0), _parentHandle(parent)
{ }

CControl::~CControl()
{ }

bool CControl::create()
{
    _windowHandle = CreateWindowEx(this->_windowStylesEx, this->_className,
                             this->getText().c_str(), this->_windowStyles,
                             this->_x, this->_y, this->_width, this->_height,
                             ParentWindow(), (HMENU)0, Application(), NULL);

    auto err = GetLastError();
    if (err != ERROR_SUCCESS)
    {
        _logger->error(fmt::format("error creating CControl due to error code {}", err));
        return false;
    }

    SetWindowLongPtr(_windowHandle, GWL_USERDATA, (LONG_PTR)this);

    CreateControlArgs args;
    this->onCreateControl(args);

    return _windowHandle != NULL;
}

ApplicationHandle CControl::Application() const { return this->_parentHandle->Application(); }

WindowHandle CControl::ParentWindow() const { return this->_parentHandle->_windowHandle; }

void CControl::resize( int x, int y, int width, int height )
{
    this->_x = x;
    this->_y = y;
    this->_width = width;
    this->_height = height;

    MoveWindow( _windowHandle, _x, _y, _width, _height, true );
}

ControlTypes CControl::getType() const { return this->_type; }

std::string CControl::getText() const
{
//    auto len = SendMessage(m_hWnd, WM_GETTEXTLENGTH, 0, 0);
//    auto buffer = new char[len + 1];
//    SendMessage(m_hWnd, WM_GETTEXT, len + 1, (WPARAM)buffer);

//    this->m_strText = std::string(buffer);
//    delete []buffer;

    return this->_text;
}

CControl& CControl::setText(const std::string& text)
{
    this->_text = text;
    if (_windowHandle != nullptr)
    {
        SendMessage(_windowHandle, WM_SETTEXT, 0, (LPARAM)text.c_str());
    }

    return *this;
}
