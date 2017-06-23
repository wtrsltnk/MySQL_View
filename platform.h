#ifndef PLATFORM_H
#define PLATFORM_H

#ifdef _WIN32

#include <windows.h>

typedef HINSTANCE ApplicationHandle;
typedef HWND WindowHandle;

#endif // _WIN32

#endif // PLATFORM_H
