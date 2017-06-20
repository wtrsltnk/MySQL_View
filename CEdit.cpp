#include "CEdit.h"

CEdit::CEdit( HWND hParent, HINSTANCE hInstance, int nX, int nY, int nWidth, int nHeight )
{
	this->m_hParent = hParent;
	this->m_hInstance = hInstance;
	this->m_nX = nX;
	this->m_nY = nY;
	this->m_nWidth = nWidth;
	this->m_nHeight = nHeight;
}

CEdit::~CEdit( void )
{
}

void CEdit::create( WORD id )
{
	 m_hWnd = CreateWindowEx( WS_EX_WINDOWEDGE, "EDIT", "",
		WS_BORDER | WS_VISIBLE | WS_CHILD |
		ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 
		m_nX, m_nY, m_nWidth, m_nHeight, 
		m_hParent, (HMENU)id, m_hInstance, NULL);
 }

void CEdit::resize( int nX, int nY, int nWidth, int nHeight )
{
	this->m_nX = nX;
	this->m_nY = nY;
	this->m_nWidth = nWidth;
	this->m_nHeight = nHeight;

	MoveWindow( m_hWnd, m_nX, m_nY, m_nWidth, m_nHeight, true );
}

string CEdit::getText( void )
{
	char *buffer;
	long len;
	
	len = SendMessage( m_hWnd, WM_GETTEXTLENGTH, 0, 0 );
	buffer = (char *)malloc(len);

	SendMessage( m_hWnd, WM_GETTEXT, len + 1, (WPARAM)buffer );
	return buffer;
}

void CEdit::setText( string text )
{
	char *buffer;

	buffer = (char *)malloc(strlen(text.c_str()));
	strcpy( buffer, text.c_str() );

	SendMessage( m_hWnd, WM_SETTEXT, 0, (LPARAM) buffer );
}