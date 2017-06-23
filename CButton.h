#ifndef CBUTTON_H
#define CBUTTON_H

#include "CControl.h"
#include "Delegate.h"

#include <string>
using namespace std;

class ButtonClickedArgs
{
public:
};

class CButton : public CControl
{
public:
    CButton(class CWin* parent);
    virtual ~CButton( void );

    virtual bool create();

    Delegate<const ButtonClickedArgs&> onClicked;
};
#endif
