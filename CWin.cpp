#include "CWin.h"
#include "CApplication.h"
#include "CControl.h"
#include "CButton.h"

#include <tchar.h>
#include <stdio.h>
#include <iostream>

//////////////////////////////////////////////////////////////////
// Constructors/Destructors
//////////////////////////////////////////////////////////////////
CWin::CWin(CApplication& application)
    : IApplicationWindow(application)
{
    this->m_dwCreationFlags  = 0L;
    this->m_dwWindowStyle	 = WS_OVERLAPPEDWINDOW;
    this->m_dwExWindowStyle	 = WS_EX_OVERLAPPEDWINDOW;
    this->m_dwCreationFlags  = SW_SHOW;
    this->m_PosX			 = CW_USEDEFAULT;
    this->m_PosY			 = CW_USEDEFAULT;
    this->m_dwCreationWidth  = CW_USEDEFAULT;
    this->m_dwCreationHeight = CW_USEDEFAULT;
    this->m_hbrWindowColor	 = (HBRUSH)(COLOR_WINDOW+1);
    this->m_hIcon			 = LoadIcon(Application(), (LPCTSTR)IDI_APPLICATION);
    this->m_strWindowTitle	 = _T("Skelet Programma HI Blok 1.4");
    this->m_hMenu			 = NULL;
}

CWin::~CWin()
{ }

//////////////////////////////////////////////////////////////////
// Methoden
//////////////////////////////////////////////////////////////////
bool CWin::create()
{
    WNDCLASSEX wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style			= CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc	= (WNDPROC)WndProc;
    wcex.cbClsExtra		= 0;
    wcex.cbWndExtra		= 0;
    wcex.hInstance		= Application();
    wcex.hIcon			= m_hIcon;
    wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground	= m_hbrWindowColor;
    wcex.lpszMenuName	= NULL;
    wcex.lpszClassName	= _T("window");
    wcex.hIconSm		= NULL;

    ::RegisterClassEx(&wcex);

    _windowHandle = ::CreateWindowEx(m_dwExWindowStyle, _T("window"),
                              m_strWindowTitle, m_dwWindowStyle,
                              m_PosX, m_PosY, m_dwCreationWidth, m_dwCreationHeight,
                              NULL, m_hMenu, Application(), (LPVOID)this);

    if (!_windowHandle)
    {
        return false;
    }

    ::ShowWindow(_windowHandle, m_dwCreationFlags);
    ::UpdateWindow(_windowHandle);

    return true;

}

LRESULT CALLBACK CWin::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    auto cWin = (CWin*)GetWindowLongPtr(hWnd, GWL_USERDATA);

    if (cWin != nullptr)
    {
        if (uMsg == WM_DESTROY)
        {
            cWin->_application.removeWindow(cWin->Window());
            auto result = cWin->MsgProc(uMsg, wParam, lParam);
            SetWindowLongPtr(hWnd, GWL_USERDATA, (LONG_PTR)NULL);

            DestroyArguments args;
            cWin->onDestroy(args);

            delete cWin;
            return result;
        }
        return cWin->MsgProc(uMsg, wParam, lParam);
    }

    switch (uMsg)
    {
    case WM_CREATE:
    {
        cWin = (CWin*)(((LPCREATESTRUCT)lParam)->lpCreateParams);
        cWin->_windowHandle = hWnd;
        SetWindowLongPtr(hWnd, GWL_USERDATA, (LONG_PTR)cWin);
        return cWin->MsgProc(uMsg, wParam, lParam);
    }
    default:
    {
        return DefWindowProc(hWnd, uMsg, wParam, lParam);
    }
    }
}

LRESULT CWin::MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_CREATE:
    {
        CreateArguments args;
        this->onCreate(args);
        break;
    }
    case WM_SIZE:
    {
        ResizeArguments args;
        args.newWidth = LOWORD(lParam);
        args.newHeight = HIWORD(lParam);
        this->onResize(args);
        break;
    }
    case WM_COMMAND:
    {
        if (lParam != 0)
        {
            auto cc = reinterpret_cast<CControl*>((void*)GetWindowLongPtr((HWND)lParam, GWL_USERDATA));
            if (cc != nullptr && cc->getType() == ControlTypes::Button)
            {
                auto btn = dynamic_cast<CButton*>(cc);
                if (btn != nullptr)
                {
                    ButtonClickedArgs args;
                    btn->onClicked(args);
                }
            }
        }
        else
        {
            // Menu item clicked
            if (HIWORD(wParam) == 0)
            {
                MenuItemClickedArguments args;
                args.id = int(LOWORD(wParam));
                this->onMenuItemClicked(args);
            }
        }

        break;
    }
    }

    return DefWindowProc(this->_windowHandle, uMsg, wParam, lParam);
}
