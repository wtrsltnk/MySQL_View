#ifndef CWIN_H
#define CWIN_H

#include "iapplicationwindow.h"

class CWin : public IApplicationWindow
{
    friend class CControl;
    static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
protected:
    DWORD   m_PosX;
    DWORD   m_PosY;
    DWORD   m_dwWindowStyle;
    DWORD   m_dwExWindowStyle;
    DWORD   m_dwCreationFlags;
    DWORD   m_dwCreationHeight;
    DWORD   m_dwCreationWidth;
    LPCTSTR m_strWindowTitle;
    HBRUSH  m_hbrWindowColor;
    HICON   m_hIcon;
    HMENU   m_hMenu;

    virtual LRESULT MsgProc(UINT, WPARAM, LPARAM);

public:
    CWin(class CApplication& application);
    virtual ~CWin();

    virtual bool create();
};

#endif
