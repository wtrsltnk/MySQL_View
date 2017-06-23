#ifndef IAPPLICATIONWINDOW_H
#define IAPPLICATIONWINDOW_H

#include "platform.h"
#include "Delegate.h"

class CreateArguments
{
public:
    virtual ~CreateArguments() { }
};

class ResizeArguments
{
public:
    virtual ~ResizeArguments() { }

    int newWidth;
    int newHeight;
};

class MenuItemClickedArguments
{
public:
    virtual ~MenuItemClickedArguments() { }

    int id;
};

class IApplicationWindow
{
protected:
    class CApplication& m_application;
    WindowHandle  m_hWnd;

    IApplicationWindow(class CApplication& application)
        : m_application(application), m_hWnd(0)
    { }
public:
    virtual ~IApplicationWindow() { }

    ApplicationHandle Application() const;
    WindowHandle Window() const;

    virtual bool create() = 0;

    Delegate<const CreateArguments&> onCreate;
    Delegate<const ResizeArguments&> onResize;
    Delegate<const MenuItemClickedArguments&> onMenuItemClicked;

};

#endif // IAPPLICATIONWINDOW_H
