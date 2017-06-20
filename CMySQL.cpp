#include "CMySQL.h"


//////////////////////////////////////////////
// (DE)CONSTRUCTOR
//////////////////////////////////////////////
CMySQL::CMySQL( void )
{
}

CMySQL::~CMySQL( void )
{
	mysql_free_result( res );
}


//////////////////////////////////////////////
// MEMBER FUNCTIES
//////////////////////////////////////////////
bool CMySQL::my_connect( string db )
{
	if ( (myData = mysql_init((MYSQL*) 0)) && 
       mysql_real_connect( myData, NULL, NULL, NULL, NULL, MYSQL_PORT,
			   NULL, 0 ) )
    {
		if ( mysql_select_db( myData, db.c_str() ) < 0 ) 
		{
			throw( "Can't select the database !\n" ) ;
			mysql_close( myData ) ;
			return false ;
		}
	}
	else 
	{
		throw( "Can't connect to the mysql server !\n" ) ;
		mysql_close( myData ) ;
		return false ;
	}
	return true;
}

bool CMySQL::my_disconnect( void )
{
	mysql_close( myData ) ;
	return true;
}

MYSQL_RES *CMySQL::my_return_query( string query )
{
	if ( ! mysql_query( myData, query.c_str() ) ) 
	{
		res = mysql_store_result( myData ) ;
		num_rows = (int) mysql_num_rows( res ) ;
		num_cols = mysql_num_fields( this->res ) ;
	}
	else throw( "Couldn't execute query on the server !\n" ) ;

	return this->res;
}

void CMySQL::my_query( string query )
{
	if ( ! mysql_query( myData, query.c_str() ) ) 
	{
		res = mysql_store_result( myData ) ;
		num_rows = (int) mysql_num_rows( res ) ;
		num_cols = mysql_num_fields( this->res ) ;
	}
	else throw( "Couldn't execute query on the server !\n" ) ;
}

MYSQL_ROW CMySQL::my_return_row( void )
{
	if ( this->row == NULL )
		throw( "Row is empty !" );
	return this->row;
}

MYSQL_ROW CMySQL::my_return_next_row( void )
{
	MYSQL_ROW row;
	row = mysql_fetch_row( this->res );
	return row;
}

void CMySQL::my_next_row( void )
{
	this->row = mysql_fetch_row( this->res );
}

string CMySQL::my_field( int index )
{
	MYSQL_FIELD *fd ;

	if ( !(index > num_cols) )
	{
		fd = mysql_fetch_field_direct( this->res, index );
		return fd->name;
	}
	return "";
}

int CMySQL::my_num_cols( void )
{
	return this->num_cols;
}

int CMySQL::my_num_rows( void )
{
	return this->num_rows;
}
