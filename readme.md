Download the MySQL C-API (https://dev.mysql.com/downloads/connector/c/)

For mingw run the following commands:

pexports.exe libmysql.dll > libmysql.def 
dlltool -k --input-def libmysql.def --dllname libmysql.dll --output-lib libmysql.a

