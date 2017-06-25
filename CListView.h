#ifndef CLISTVIEW_H
#define CLISTVIEW_H

#include "CControl.h"
#include <commctrl.h>
#include <string>
#include <vector>
using namespace std;

class CListView : public CControl
{
    int num_cols;
    WindowHandle _header;
    vector<LVCOLUMN> _columns;
public:
    CListView(class CWin* parent);
    virtual ~CListView( void );

    CListView& addCol( string, int );
    CListView& addItem( string, int );
    CListView& addSubItem( string, int, int );
    CListView& clear();
};
#endif
