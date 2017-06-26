#ifndef CMAINFRAME_H
#define CMAINFRAME_H

#include "CWin.h"
#include "CListView.h"
#include "CMySQL.h"
#include "CEdit.h"
#include "CRichEdit.h"
#include "CCombo.h"
#include "CButton.h"
#include "CLabel.h"
#include "CStatusBar.h"
#include "resource.h"

#include <time.h>
using namespace std;

class CMainFrame : public CWin
{
private:
    CLabel m_pDbLbl;
    CEdit m_pDb;
    CButton m_pDbGo;
    CLabel m_pTableLbl;
    CEdit m_pTable;
    CLabel m_pFieldsLbl;
    CEdit m_pFields;
    CLabel m_pLimitLbl;
    CEdit m_pLimit;
    CListView m_pData;
    CRichEdit m_pSQL;
    CStatusBar m_pStatus;
	CMySQL	*m_pMy;

	struct tm *newtime;
	long ltime;
	long ntime;
	long rtime;

public:
    CMainFrame(class CApplication& application);
    virtual ~CMainFrame();

	int exec_sql( string );

    void onGo(const ButtonClickedArgs& args);
};

#endif
