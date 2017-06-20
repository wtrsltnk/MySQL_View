#include "CMainFrame.h"

/////////////////////////////////////
// Constructors / Destructors      //
/////////////////////////////////////
CMainFrame::CMainFrame()
{
	this->m_dwCreationFlags  = 0L;
	this->m_dwWindowStyle	 = WS_OVERLAPPEDWINDOW;
	this->m_dwExWindowStyle	 = WS_EX_WINDOWEDGE;
	this->m_dwCreationFlags  = SW_SHOW;
	this->m_PosX			 = CW_USEDEFAULT;	
	this->m_PosY			 = CW_USEDEFAULT;	
	this->m_dwCreationWidth  = CW_USEDEFAULT;
	this->m_dwCreationHeight = CW_USEDEFAULT;
	this->m_hbrWindowColor	 = (HBRUSH)(COLOR_WINDOW);
	this->m_hIcon			 = LoadIcon(m_hInstance, MAKEINTRESOURCE( IDI_MYSQL ) );
	this->m_strWindowTitle	 = "MySQL Database View";
//	this->m_hMenu			 = LoadMenu( m_hInstance, MAKEINTRESOURCE( IDR_MENU ) );
}


CMainFrame::~CMainFrame()
{
}

/////////////////////////////////////
// Memberfuncties                  //
/////////////////////////////////////

LRESULT CMainFrame::MsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	int nWidth, nHeight;
	strstream strs, strsTime, strsNumRec;

	switch ( uMsg )
	{
	case WM_CREATE:
		m_pDbLbl = new CLabel(  m_hWnd, m_hInstance, 0, 0, 100, 100 );
		m_pDbLbl->create( ID_DBLBL );
		m_pDbLbl->setText( "Database Name" );

		m_pDb = new CEdit( m_hWnd, m_hInstance, 0, 0, 100, 100 );
		m_pDb->create( ID_DBWIN );

		m_pDbGo = new CButton( m_hWnd, m_hInstance, 0, 0, 100, 100 );
		m_pDbGo->create( ID_DBGO );
		m_pDbGo->setText( "GO" );

		m_pTableLbl = new CLabel(  m_hWnd, m_hInstance, 0, 0, 100, 100 );
		m_pTableLbl->create( ID_DBLBL );
		m_pTableLbl->setText( "Table Name" );

		m_pTable = new CEdit( m_hWnd, m_hInstance, 0, 0, 100, 100 );
		m_pTable->create( ID_TABLEWIN );

		m_pFieldsLbl = new CLabel(  m_hWnd, m_hInstance, 0, 0, 100, 100 );
		m_pFieldsLbl->create( ID_DBLBL );
		m_pFieldsLbl->setText( "Fields (divided with \",\")" ); 

		m_pFields = new CEdit( m_hWnd, m_hInstance, 0, 0, 100, 100 );
		m_pFields->create( ID_FIELDS );

		m_pLimitLbl = new CLabel(  m_hWnd, m_hInstance, 0, 0, 100, 100 );
		m_pLimitLbl->create( ID_LIMITLBL );
		m_pLimitLbl->setText( "Limit" ); 

		m_pLimit = new CEdit( m_hWnd, m_hInstance, 0, 0, 100, 100 );
		m_pLimit->create( ID_LIMIT );

		m_pSQL = new CEdit( m_hWnd, m_hInstance, 0, 0, 100, 100 );
		m_pSQL->create( ID_SQLWIN );

		m_pData = new CListView( m_hWnd, m_hInstance, 0, 0, 100, 100 );
		m_pData->create( ID_DATAWIN );
		m_pData->clear();	
		m_pData->addCol( "Enter SQL statement.", 400 );

		m_pStatus = new CStatusBar( m_hInstance, m_hWnd );
		m_pStatus->CreateStatusBar();
		break;
	case WM_SIZE:
		nWidth = LOWORD(lParam);
		nHeight = HIWORD(lParam);
		m_pDbLbl->resize( 2, 5, 148, 20 );
		m_pDb->resize( 2, 25, 148, 20 );

		m_pTableLbl->resize( 158, 5, 150, 20 );
		m_pTable->resize( 158, 25, 150, 20 );
		
		m_pLimitLbl->resize( 316, 5, 90, 20 );
		m_pLimit->resize( 316, 25, 90, 20 );
		
		m_pFieldsLbl->resize( 414, 5, nWidth - 454, 20 );
		m_pFields->resize( 414, 25, nWidth - 454, 20 );

		m_pDbGo->resize( nWidth - 32, 25, 30, 20 );
		
		m_pSQL->resize( 2, 50, nWidth - 4, 100 );
		m_pData->resize( 2, 155, nWidth - 4, nHeight - 178 );
		m_pStatus->Resize( wParam, lParam );
		break;
	case WM_COMMAND:
		switch ( LOWORD(wParam) )
		{
		case IDM_QUERY:
			exec_sql( m_pSQL->getText() );
			break;
		case ID_DBGO:
			time( &ltime );
			
			if ( m_pSQL->getText() != ""  )
			{
				strsNumRec << "Number of Records loaded : " << exec_sql( m_pSQL->getText() ) << ends;
				m_pStatus->setItemText( 2, strsNumRec.str() );
				delete strsNumRec.str();
			}
			else
			{
				if ( m_pFields->getText() == "" )
					if ( m_pLimit->getText() != "" )
						strs << "SELECT * FROM " << m_pTable->getText() << " LIMIT 0, " << m_pLimit->getText() << ";" << ends;
					else
						strs << "SELECT * FROM " << m_pTable->getText() << ";" << ends;
				else
					if ( m_pLimit->getText() != "" )
						strs << "SELECT " << m_pFields->getText() << " FROM " << m_pTable->getText() << " LIMIT 0, " << m_pLimit->getText() << ";" << ends;
					else
						strs << "SELECT " << m_pFields->getText() << " FROM " << m_pTable->getText() << ";" << ends;
				
				strsNumRec << "Number of Records loaded : " << exec_sql( strs.str() ) << ends;
				m_pStatus->setItemText( 2, strsNumRec.str() );

				delete strsNumRec.str();
				delete strs.str();
			}
			time( &ntime );
			rtime = ntime - ltime;
			strsTime << "Records loaded within " << rtime << " seconds" << ends;
			m_pStatus->setItemText( 1, strsTime.str() );
			delete strsTime.str();
			break;
		}
		break;
	}
	return CWin::MsgProc(hWnd, uMsg, wParam, lParam);
}

int CMainFrame::exec_sql( string sql )
{
	int i, j;

	m_pMy = new CMySQL();
	try
	{
		m_pMy->my_connect( m_pDb->getText() );
		m_pMy->my_query( sql );
		
		m_pData->clear();

		for ( i=0; i < m_pMy->my_num_cols(); i++ )
			m_pData->addCol( m_pMy->my_field( i ), 100 );

		for ( i=0; i < m_pMy->my_num_rows(); i++ )
		{
			m_pMy->my_next_row();
			m_pData->addItem( m_pMy->my_return_row()[0], i );
			for ( j=0; j < m_pMy->my_num_cols(); j++ )
			{
				if ( m_pMy->my_return_row()[j] != NULL )
					m_pData->addSubItem( m_pMy->my_return_row()[j], i, j );
			}
		}
		m_pMy->my_disconnect();
	}
	catch ( char *error )
	{
		MessageBox( m_hWnd, error, "ERROR:", MB_OK );
		return 0;
	}
	return m_pMy->my_num_rows();
}
