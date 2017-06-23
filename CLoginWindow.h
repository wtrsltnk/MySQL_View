#ifndef CLOGINWINDOW_H
#define CLOGINWINDOW_H

#include "CWin.h"
#include "CEdit.h"
#include "CLabel.h"
#include "CButton.h"

class CLoginWindow : public CWin
{
    CLabel m_HostLbl;
    CEdit m_Host;
    CLabel m_DbLbl;
    CEdit m_Db;
    CLabel m_UserLbl;
    CEdit m_User;
    CLabel m_PasswordLbl;
    CEdit m_Password;
    CButton m_Login;

public:
    CLoginWindow(class CApplication& application);
    virtual ~CLoginWindow();
};

#endif // CLOGINWINDOW_H
