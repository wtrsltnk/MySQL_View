// WinClass.cpp : Defines the entry point for the application.
//
#include "CLoginWindow.h"
#include "CMainFrame.h"
#include "CApplication.h"

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
    CApplication app(hInstance);

    auto window = app.createWindow<CLoginWindow>();

    if (window == nullptr) return 0;

    return app.run();
}
