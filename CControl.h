#ifndef CCONTROL_H
#define CCONTROL_H

#include "platform.h"
#include <string>

class CControl
{
protected:
    const class CWin* m_parent;
    WindowHandle m_hWnd;
    std::string m_strText;
    int m_nX, m_nY;
    int m_nWidth, m_nHeight;

    ApplicationHandle Application() const;
    WindowHandle ParentWindow() const;
public:
    CControl(class CWin* parent);
    virtual ~CControl();

    virtual bool create() = 0;
    virtual void resize(int x, int y, int width, int height);

    std::string getText() const;
    CControl& setText(const std::string& text);
};

#endif // CCONTROL_H
