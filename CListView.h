#ifndef CLISTVIEW_H
#define CLISTVIEW_H

#include <windows.h>
#include <string>
#include <commctrl.h>
using namespace std;

class CListView
{
private:
	HWND		m_hWnd, m_hParent;
	HINSTANCE	m_hInstance;
	int			m_nX, m_nY;
	int			m_nWidth, m_nHeight;
	int			num_cols;
public:
	CListView( HWND, HINSTANCE, int, int, int, int );
	~CListView( void );
	void create( WORD );
	void resize( int, int, int, int );

	void addCol( string, int );
	void addItem( string, int );
	void addSubItem( string, int, int );
	void clear( void );
};
#endif