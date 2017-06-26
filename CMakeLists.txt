cmake_minimum_required(VERSION 3.7)

project(MySQL_View)

find_library(MYSQL_LIBRARY
    NAMES mysql libmysql
    PATHS ${CMAKE_PREFIX_PATH}
    )

find_path(MYSQL_INCLUDE_DIR
    NAMES mysql.h
    PATHS ${CMAKE_PREFIX_PATH}
    )

add_executable(MySQL_View WIN32
    Log.cpp
    Log.h
    CApplication.cpp
    CApplication.h
    CButton.cpp
    CButton.h
    CCombo.cpp
    CCombo.h
    CControl.cpp
    CControl.h
    CEdit.cpp
    CEdit.h
    CLabel.cpp
    CLabel.h
    CListView.cpp
    CListView.h
    CLoginWindow.cpp
    CLoginWindow.h
    CMainFrame.cpp
    CMainFrame.h
    CMySQL.cpp
    CMySQL.h
    CRichEdit.cpp
    CRichEdit.h
    CStatusBar.cpp
    CStatusBar.h
    CWin.cpp
    CWin.h
    Delegate.h
    IApplicationWindow.h
    MySqlSession.cpp
    MySqlSession.h
    platform.h
    platform-win32.cpp
    resource.h
    resource.rc
    fmt/fmt/format.cc
    )

target_compile_features(MySQL_View
    PRIVATE cxx_auto_type
    PRIVATE cxx_nullptr
    PRIVATE cxx_range_for
    )

target_include_directories(MySQL_View
    PRIVATE ${MYSQL_INCLUDE_DIR}
    PRIVATE fmt
    )

target_link_libraries(MySQL_View
    ${MYSQL_LIBRARY}
    Comctl32
    )
