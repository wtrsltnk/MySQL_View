#include "CLoginWindow.h"
#include "resource.h"
#include <iostream>

CLoginWindow::CLoginWindow(class CApplication& application)
    : CWin(application), m_Host(this), m_HostLbl(this), m_Db(this), m_DbLbl(this),
      m_User(this), m_UserLbl(this), m_Password(this), m_PasswordLbl(this), m_Login(this)
{
    this->m_dwCreationFlags  = 0L;
    this->m_dwWindowStyle	 = WS_OVERLAPPED | WS_CAPTION;
    this->m_dwExWindowStyle	 = WS_EX_WINDOWEDGE;
    this->m_dwCreationFlags  = SW_SHOW;
    this->m_PosX			 = CW_USEDEFAULT;
    this->m_PosY			 = CW_USEDEFAULT;
    this->m_dwCreationWidth  = 400;
    this->m_dwCreationHeight = 250;
    this->m_hbrWindowColor	 = (HBRUSH)(COLOR_WINDOW);
    this->m_hIcon			 = LoadIcon(Application(), MAKEINTRESOURCE( IDI_MYSQL ) );
    this->m_strWindowTitle	 = "MySQL Database View - Login";

    this->onCreate += [this] (const CreateArguments& args)
    {
        m_HostLbl.setText("Host Name").create();
        m_Host.create();

        m_DbLbl.setText("Database Name").create();
        m_Db.create();

        m_UserLbl.setText("User Name").create();
        m_User.create();

        m_PasswordLbl.setText("Password").create();
        m_Password.create();

        m_Login.setText("Login").create();
        m_Login.onClicked += [this] (const ButtonClickedArgs& args)
        {
            std::cout << "Clicked login!" << std::endl;
        };
    };

    this->onResize += [this] (const ResizeArguments& args)
    {
        m_HostLbl.resize( 5, 5, 148, 20 );
        m_Host.resize( 5, 25, 248, 20 );

        m_DbLbl.resize( 5, 55, 148, 20 );
        m_Db.resize( 5, 75, 248, 20 );

        m_UserLbl.resize( 5, 105, 148, 20 );
        m_User.resize( 5, 125, 248, 20 );

        m_PasswordLbl.resize( 5, 155, 148, 20 );
        m_Password.resize( 5, 175, 248, 20 );

        m_Login.resize(300, 175, 75, 24);
    };
}

CLoginWindow::~CLoginWindow()
{ }
