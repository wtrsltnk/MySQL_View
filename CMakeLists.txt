cmake_minimum_required(VERSION 3.7)

project(MySQL_View)

find_library(MYSQL_LIBRARY
    NAMES mysql libmysql
    PATHS ${CMAKE_PREFIX_PATH}
    )

FIND_PATH(MYSQL_INCLUDE_DIR
    NAMES mysql.h
    PATHS ${CMAKE_PREFIX_PATH}
    )

add_executable(MySQL_View WIN32
    CButton.cpp
    CButton.h
    CCombo.cpp
    CCombo.h
    CEdit.cpp
    CEdit.h
    CLabel.cpp
    CLabel.h
    CListView.cpp
    CListView.h
    CMainFrame.cpp
    CMainFrame.h
    CMySQL.cpp
    CMySQL.h
    CStatusBar.cpp
    CStatusBar.h
    CWin.cpp
    CWin.h
    resource.h
    resource.rc
    WinMain.cpp
    )

target_compile_features(MySQL_View
    PRIVATE cxx_auto_type
    PRIVATE cxx_nullptr
    PRIVATE cxx_range_for
    )

target_include_directories(MySQL_View
    PRIVATE ${MYSQL_INCLUDE_DIR}
    )

target_link_libraries(MySQL_View
    ${MYSQL_LIBRARY}
    Comctl32
    )
