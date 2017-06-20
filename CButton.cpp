#include "CButton.h"

CButton::CButton( HWND hParent, HINSTANCE hInstance, int nX, int nY, int nWidth, int nHeight )
{
	this->m_hParent = hParent;
	this->m_hInstance = hInstance;
	this->m_nX = nX;
	this->m_nY = nY;
	this->m_nWidth = nWidth;
	this->m_nHeight = nHeight;
}

CButton::~CButton( void )
{
}

void CButton::create( WORD id )
{
	 m_hWnd = CreateWindowEx( WS_EX_STATICEDGE, "BUTTON", "->",
		WS_VISIBLE | WS_CHILD, 
		m_nX, m_nY, m_nWidth, m_nHeight, 
		m_hParent, (HMENU)id, m_hInstance, NULL);
 }

void CButton::resize( int nX, int nY, int nWidth, int nHeight )
{
	this->m_nX = nX;
	this->m_nY = nY;
	this->m_nWidth = nWidth;
	this->m_nHeight = nHeight;

	MoveWindow( m_hWnd, m_nX, m_nY, m_nWidth, m_nHeight, true );
}

void CButton::setText( string text )
{
	char *buffer;

	buffer = (char *)malloc(strlen(text.c_str()));
	strcpy( buffer, text.c_str() );

	SendMessage( m_hWnd, WM_SETTEXT, 0, (LPARAM) buffer );
}
