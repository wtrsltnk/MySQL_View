#ifndef CMYSQL_H
#define CMYSQL_H

#include	<stdio.h>
#include	<string>
using namespace std;

#include	<mysql.h>

class CMySQL
{
private:
	MYSQL		* myData ;
	MYSQL_RES	* res ;
	MYSQL_FIELD	* fd ;
	MYSQL_ROW	row ;
	int			num_rows, cur_row, num_cols, num_dbs;
public:
	CMySQL( void );
    virtual ~CMySQL( void );

    bool my_connect( string );
	bool my_disconnect( void );
    MYSQL_RES *my_return_query( string );
    void my_query( string );
	MYSQL_ROW my_return_row( void );
	MYSQL_ROW my_return_next_row( void );
	void my_next_row( void );
	string my_field( int );
	int my_num_cols( void );
	int my_num_rows( void );
};
#endif
