#ifndef CCONTROL_H
#define CCONTROL_H

#include "platform.h"
#include "Delegate.h"
#include "Log.h"
#include <string>

enum class ControlTypes
{
    Button,
    Combo,
    Edit,
    Label,
    ListView,
    StatusBar,
};

class CreateControlArgs
{
public:
};

class CControl
{
    static Log* _logger;
protected:
    const ControlTypes _type;
    const char* _className;
    DWORD _windowStyles, _windowStylesEx;
    const class CWin* _parentHandle;
    WindowHandle _windowHandle;
    std::string _text;
    int _x, _y;
    int _width, _height;

    ApplicationHandle Application() const;
    WindowHandle ParentWindow() const;

    CControl(class CWin* parent, const ControlTypes type, const char* className);
public:
    virtual ~CControl();

    virtual bool create();
    virtual void resize(int x, int y, int width, int height);

    ControlTypes getType() const;
    std::string getText() const;
    CControl& setText(const std::string& text);

    Delegate<const CreateControlArgs&> onCreateControl;
};

#endif // CCONTROL_H
