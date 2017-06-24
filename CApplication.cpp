#include "capplication.h"
#include <vector>

ApplicationHandle IApplicationWindow::Application() const
{
    return this->_application.Instance();
}

WindowHandle IApplicationWindow::Window() const
{
    return this->_windowHandle;
}

CApplication::CApplication(ApplicationHandle instance)
    : m_hInstance(instance)
{ }

CApplication::~CApplication()
{ }

static std::vector<WindowHandle> openWindows;

void CApplication::addWindow(WindowHandle window)
{
    openWindows.push_back(window);
}

void CApplication::removeWindow(WindowHandle window)
{
    for (auto w = openWindows.begin(); w != openWindows.end(); ++w)
    {
        if (*w == window)
        {
            openWindows.erase(w);
            break;
        }
    }

    if (openWindows.empty()) PostQuitMessage(0);
}

ApplicationHandle CApplication::Instance() const
{
    return this->m_hInstance;
}

int CApplication::run()
{
    MSG msg;
    BOOL bRet;

    while((bRet = GetMessage(&msg, NULL, 0, 0)) != 0)
    {
        if (bRet == -1)
        {
            // handle the error and possibly exit
        }
        else
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return int(msg.wParam);
}
