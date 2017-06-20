#ifndef CCOMBO_H
#define CCOMBO_H

#include <windows.h>
#include <string>
#include <commctrl.h>
using namespace std;

class CCombo
{
private:
	HWND		m_hWnd, m_hParent;
	HINSTANCE	m_hInstance;
	int			m_nX, m_nY;
	int			m_nWidth, m_nHeight;
public:
	CCombo( HWND, HINSTANCE, int, int, int, int );
	~CCombo( void );
	void create( WORD );
	void resize( int, int, int, int );
	void addItem( string );
	string getText( void );
	void setText( string );
};
#endif