#include "CListView.h"

CListView::CListView( HWND hParent, HINSTANCE hInstance, int nX, int nY, int nWidth, int nHeight )
{
	this->m_hParent = hParent;
	this->m_hInstance = hInstance;
	this->m_nX = nX;
	this->m_nY = nY;
	this->m_nWidth = nWidth;
	this->m_nHeight = nHeight;

	this->num_cols = 0;
}

CListView::~CListView( void )
{
}

void CListView::create( WORD id )
{
	 m_hWnd = CreateWindowEx( WS_EX_WINDOWEDGE, WC_LISTVIEW, "",
		WS_BORDER | WS_VISIBLE | WS_CHILD | WS_TABSTOP |
		LVS_REPORT | LVS_SHOWSELALWAYS, 
		m_nX, m_nY, m_nWidth, m_nHeight, 
		m_hParent, (HMENU)id, m_hInstance, NULL);
 
	ListView_SetExtendedListViewStyleEx( m_hWnd,
		LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT|LVS_EX_FLATSB , 
		LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT|LVS_EX_FLATSB );
 
	HWND hHeader = CreateWindow( WC_HEADER,"", 
		HDS_HORZ|HDS_BUTTONS, 
		m_nX, m_nY, m_nWidth+10, m_nHeight, 
		m_hWnd, NULL, m_hInstance, NULL );
}

void CListView::resize( int nX, int nY, int nWidth, int nHeight )
{
	this->m_nX = nX;
	this->m_nY = nY;
	this->m_nWidth = nWidth;
	this->m_nHeight = nHeight;

	MoveWindow( m_hWnd, m_nX, m_nY, m_nWidth, m_nHeight, true );
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
