#ifndef CLISTVIEW_H
#define CLISTVIEW_H

#include "CControl.h"
#include <string>
using namespace std;

class CListView : public CControl
{
    int num_cols;
public:
    CListView(class CWin* parent);
    virtual ~CListView( void );

    virtual bool create();
    void addCol( string, int );
    void addItem( string, int );
    void addSubItem( string, int, int );
    void clear( void );
};
#endif
