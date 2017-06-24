#include "CListView.h"
#include <commctrl.h>

CListView::CListView(class CWin* parent)
    : CControl(parent, ControlTypes::ListView, WC_LISTVIEW)
{
    this->num_cols = 0;
    this->_windowStyles = WS_BORDER | WS_VISIBLE | WS_CHILD | WS_TABSTOP |
            LVS_REPORT | LVS_SHOWSELALWAYS;
    this->_windowStylesEx = WS_EX_WINDOWEDGE;
    this->onCreateControl += [this] (const CreateControlArgs& args)
    {
        ListView_SetExtendedListViewStyleEx( _windowHandle,
                                             LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT|LVS_EX_FLATSB ,
                                             LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT|LVS_EX_FLATSB );

        this->_header = CreateWindow( WC_HEADER,"",
                                     HDS_HORZ|HDS_BUTTONS,
                                     _x, _y, _width+10, _height,
                                     _windowHandle, NULL, Application(), NULL );
    };
}

CListView::~CListView( void )
{ }

void CListView::addCol( string text, int nWidth )
{
    LVCOLUMN lvc;

    lvc.mask = LVCF_TEXT | LVCF_WIDTH ;
    lvc.pszText = const_cast <char *>(text.c_str());
    lvc.cchTextMax = 255;
    lvc.cx = nWidth;

    ListView_InsertColumn( _windowHandle, 100, &lvc );
    num_cols++;
}

void CListView::addItem( string text, int row )
{
    LV_ITEM lvi;

    //vul de listview item structure
    lvi.mask = LVIF_TEXT|LVIF_IMAGE|LVIF_STATE;
    lvi.state = 0;
    lvi.stateMask = -1;
    lvi.iItem = (row);
    lvi.iSubItem = 0;
    lvi.pszText = const_cast<char *>(text.c_str());

    ListView_InsertItem(_windowHandle, &lvi);
}

void CListView::addSubItem( string text, int row, int col )
{
    ListView_SetItemText( _windowHandle, row, col, const_cast<char *>(text.c_str()) );
}


void CListView::clear()
{
    for ( int i=0; i < num_cols; i++ )
    {
        ListView_DeleteColumn( _windowHandle, 0 );
    }
    ListView_DeleteAllItems(_windowHandle);
}
