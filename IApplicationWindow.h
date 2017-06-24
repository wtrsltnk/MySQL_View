#ifndef IAPPLICATIONWINDOW_H
#define IAPPLICATIONWINDOW_H

#include "platform.h"
#include "Delegate.h"

class CreateArguments
{
public:
    virtual ~CreateArguments() { }
};


class DestroyArguments
{
public:
    virtual ~DestroyArguments() { }
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
    class CApplication& _application;
    WindowHandle  _windowHandle;

    IApplicationWindow(class CApplication& application)
        : _application(application), _windowHandle(0)
    { }
public:
    virtual ~IApplicationWindow() { }

    ApplicationHandle Application() const;
    WindowHandle Window() const;

    virtual bool create() = 0;

    Delegate<const CreateArguments&> onCreate;
    Delegate<const DestroyArguments&> onDestroy;
    Delegate<const ResizeArguments&> onResize;
    Delegate<const MenuItemClickedArguments&> onMenuItemClicked;

};

#endif // IAPPLICATIONWINDOW_H
