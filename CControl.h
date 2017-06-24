#ifndef CCONTROL_H
#define CCONTROL_H

#include "platform.h"
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

class CControl
{
protected:
    const ControlTypes _type;
    const char* _className;
    DWORD _windowStyles, _windowStylesEx;
    const class CWin* m_parent;
    WindowHandle m_hWnd;
    std::string m_strText;
    int m_nX, m_nY;
    int m_nWidth, m_nHeight;

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
};

#endif // CCONTROL_H
