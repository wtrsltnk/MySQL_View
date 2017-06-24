#ifndef CEDIT_H
#define CEDIT_H

#include "CControl.h"
#include <string>
using namespace std;

class CEdit : public CControl
{
public:
    CEdit(class CWin* parent);
    virtual ~CEdit( void );

};
#endif
