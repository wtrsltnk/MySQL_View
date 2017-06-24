#ifndef CLABEL_H
#define CLABEL_H

#include "CControl.h"
#include <string>
using namespace std;

class CLabel : public CControl
{
public:
    CLabel(class CWin* parent);
    virtual ~CLabel( void );
};
#endif
