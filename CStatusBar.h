#ifndef CSTATUSBAR_H
#define CSTATUSBAR_H

#include "CControl.h"
#include "resource.h"
#include <string>
using namespace std;

class CStatusBar : public CControl
{
public:
    CStatusBar(class CWin* parent);
    virtual ~CStatusBar();

    virtual bool create();
    void setItemText(int, string);
    virtual void resize(int x, int y, int width, int height);
};
#endif
