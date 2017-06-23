#include "CListView.h"
#include <commctrl.h>

CListView::CListView(class CWin* parent)
    : CControl(parent)
{
    this->num_cols = 0;
}

CListView::~CListView( void )
{ }

bool CListView::create()
{
    m_hWnd = CreateWindowEx( WS_EX_WINDOWEDGE, WC_LISTVIEW, "",
                             WS_BORDER | WS_VISIBLE | WS_CHILD | WS_TABSTOP |
                             LVS_REPORT | LVS_SHOWSELALWAYS,
                             m_nX, m_nY, m_nWidth, m_nHeight,
                             ParentWindow(), (HMENU)0, Application(), NULL);

    ListView_SetExtendedListViewStyleEx( m_hWnd,
                                         LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT|LVS_EX_FLATSB ,
                                         LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT|LVS_EX_FLATSB );

    auto hHeader = CreateWindow( WC_HEADER,"",
                                 HDS_HORZ|HDS_BUTTONS,
                                 m_nX, m_nY, m_nWidth+10, m_nHeight,
                                 m_hWnd, NULL, Application(), NULL );

    return m_hWnd != NULL;
}

void CListView::addCol( string text, int nWidth )
{
    LVCOLUMN lvc;

    lvc.mask = LVCF_TEXT | LVCF_WIDTH ;
    lvc.pszText = const_cast <char *>(text.c_str());
    lvc.cchTextMax = 255;
    lvc.cx = nWidth;

    ListView_InsertColumn( m_hWnd, 100, &lvc );
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

    ListView_InsertItem(m_hWnd, &lvi);
}

void CListView::addSubItem( string text, int row, int col )
{
    ListView_SetItemText( m_hWnd, row, col, const_cast<char *>(text.c_str()) );
}


void CListView::clear()
{
    for ( int i=0; i < num_cols; i++ )
    {
        ListView_DeleteColumn( m_hWnd, 0 );
    }
    ListView_DeleteAllItems(m_hWnd);
}
