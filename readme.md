Download the MySQL C-API (https://dev.mysql.com/downloads/connector/c/) and extract it to c:\temp

When on MinGW, open a command line in the "lib" folder and run the following commands:

```
pexports.exe libmysql.dll > libmysql.def 
dlltool -k --input-def libmysql.def --dllname libmysql.dll --output-lib libmysql.a
```

The run cmake on this project with the mysql connector directory as CMAKE_PREFIX_PATH