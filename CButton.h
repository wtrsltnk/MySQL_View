#ifndef CBUTTON_H
#define CBUTTON_H

#include <windows.h>
#include <string>
#include <commctrl.h>
using namespace std;

class CButton
{
private:
	HWND		m_hWnd, m_hParent;
	HINSTANCE	m_hInstance;
	int			m_nX, m_nY;
	int			m_nWidth, m_nHeight;
public:
	CButton( HWND, HINSTANCE, int, int, int, int );
	~CButton( void );
	void create( WORD );
	void resize( int, int, int, int );
	void setText( string );
};
#endif