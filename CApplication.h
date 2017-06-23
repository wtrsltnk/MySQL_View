#ifndef CAPPLICATION_H
#define CAPPLICATION_H

#include "IApplicationWindow.h"

class CApplication
{
    ApplicationHandle m_hInstance;
public:
    CApplication(ApplicationHandle app);
    virtual ~CApplication();

    ApplicationHandle Instance() const;

    int run();

    void addWindow(WindowHandle window);
    void removeWindow(WindowHandle window);

    template<class T>
    T* createWindow()
    {
        auto t = new T(*this);

        if (static_cast<IApplicationWindow*>(t) == nullptr)
        {
            delete t;
            return nullptr;
        }

        if (!t->create()) return nullptr;

        addWindow(t->Window());

        return t;
    }
};

#endif // CAPPLICATION_H
