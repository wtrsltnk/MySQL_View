#ifndef CEDIT_H
#define CEDIT_H

#include <windows.h>
#include <string>
#include <commctrl.h>
using namespace std;

class CEdit
{
private:
	HWND		m_hWnd, m_hParent;
	HINSTANCE	m_hInstance;
	int			m_nX, m_nY;
	int			m_nWidth, m_nHeight;
public:
	CEdit( HWND, HINSTANCE, int, int, int, int );
	~CEdit( void );
	void create( WORD );
	void resize( int, int, int, int );
	string getText( void );
	void setText( string );
};
#endif