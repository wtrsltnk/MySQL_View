#ifndef CSTATUSBAR_H
#define CSTATUSBAR_H

#include "CControl.h"
#include "resource.h"
#include <string>
using namespace std;

class CStatusBar : public CControl
{
    int _partCount;
    int* _parts;
public:
    CStatusBar(class CWin* parent);
    virtual ~CStatusBar();

    CStatusBar& setParts(int count, int parts[]);
    CStatusBar& setItemText(int, string);
    virtual void resize(int x, int y, int width, int height);
};
#endif
