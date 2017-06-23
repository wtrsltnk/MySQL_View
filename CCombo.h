#ifndef CCOMBO_H
#define CCOMBO_H

#include "CControl.h"
#include <string>
using namespace std;

class CCombo : public CControl
{
public:
    CCombo(class CWin* parent);
    virtual ~CCombo( void );

    virtual bool create();
    void addItem( string );
};
#endif
