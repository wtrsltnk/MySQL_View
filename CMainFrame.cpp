#include "CMainFrame.h"
#include "CApplication.h"

#include <sstream>

/////////////////////////////////////
// Constructors / Destructors      //
/////////////////////////////////////
CMainFrame::CMainFrame(class CApplication& application)
    : CWin(application), m_pDbLbl(this), m_pDb(this), m_pDbGo(this), m_pTableLbl(this),
      m_pTable(this), m_pFieldsLbl(this), m_pFields(this), m_pLimitLbl(this), m_pLimit(this),
      m_pSQL(this), m_pData(this), m_pStatus(this)
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
    this->m_hIcon			 = LoadIcon(Application(), MAKEINTRESOURCE(IDI_MYSQL));
    this->m_strWindowTitle	 = "MySQL Database View";
    this->m_hMenu			 = LoadMenu(Application(), MAKEINTRESOURCE(IDR_MENU));

    this->onCreate += [this] (const CreateArguments& args)
    {
        this->m_pDbLbl.create();
        this->m_pDbLbl.setText("Database Name");

        m_pDb.create();

        m_pDbGo.setText("GO").create();

        m_pTableLbl.setText("Table Name").create();

        m_pTable.create();

        m_pFieldsLbl.setText("Fields (divided with \",\")").create();

        m_pFields.create();

        m_pLimitLbl.setText("Limit").create();

        m_pLimit.create();

        m_pSQL.setText("select * from cpptest;").create();

        m_pData.create();
        m_pData.clear();
        m_pData.addCol("Enter SQL statement.", 400);

        int parts[] = { 300, 450, -1 };
        this->m_pStatus.setParts(3, parts).create();
    };

    this->onResize += [this] (const ResizeArguments& args)
    {
        m_pDbLbl.resize(2, 5, 148, 20);
        m_pDb.resize(2, 25, 148, 20);

        m_pTableLbl.resize(158, 5, 150, 20);
        m_pTable.resize(158, 25, 150, 20);

        m_pLimitLbl.resize(316, 5, 90, 20);
        m_pLimit.resize(316, 25, 90, 20);

        m_pFieldsLbl.resize(414, 5, args.newWidth - 454, 20);
        m_pFields.resize(414, 25, args.newWidth - 454, 20);

        m_pDbGo.resize(args.newWidth - 32, 25, 30, 20);
        m_pDbGo.onClicked += [this] (const ButtonClickedArgs& args) { this->onGo(args); };

        m_pSQL.resize(2, 50, args.newWidth - 4, 100);
        m_pData.resize(2, 155, args.newWidth - 4, args.newHeight - 178);

        m_pStatus.resize(0, 0, args.newWidth, args.newHeight);
    };

    this->onMenuItemClicked += [this] (const MenuItemClickedArguments& args)
    {
        if (args.id == IDM_QUERY)
        {
            exec_sql(m_pSQL.getText());
        }
    };
}

void CMainFrame::onGo(const ButtonClickedArgs& args)
{
    time(&ltime);

    stringstream strs, strsTime, strsNumRec;

    if (m_pSQL.getText() != "" )
    {
        strsNumRec << "Number of Records loaded : " << exec_sql(m_pSQL.getText()) << ends;
        m_pStatus.setItemText(2, strsNumRec.str());
    }
    else
    {
        if (m_pFields.getText() == "")
            if (m_pLimit.getText() != "")
                strs << "SELECT * FROM " << m_pTable.getText() << " LIMIT 0, " << m_pLimit.getText() << ";" << ends;
            else
                strs << "SELECT * FROM " << m_pTable.getText() << ";" << ends;
        else
            if (m_pLimit.getText() != "")
                strs << "SELECT " << m_pFields.getText() << " FROM " << m_pTable.getText() << " LIMIT 0, " << m_pLimit.getText() << ";" << ends;
            else
                strs << "SELECT " << m_pFields.getText() << " FROM " << m_pTable.getText() << ";" << ends;

        strsNumRec << "Number of Records loaded : " << exec_sql(strs.str()) << ends;
        m_pStatus.setItemText(2, strsNumRec.str());
    }
    time(&ntime);
    rtime = ntime - ltime;
    strsTime << "Records loaded within " << rtime << " seconds" << ends;
    m_pStatus.setItemText(1, strsTime.str());
}

CMainFrame::~CMainFrame()
{ }

int CMainFrame::exec_sql(string sql)
{
    int i, j;

    m_pMy = new CMySQL();
    try
    {
        m_pMy->my_connect(m_pDb.getText());
        m_pMy->my_query(sql);

        m_pData.clear();

        for (i=0; i < m_pMy->my_num_cols(); i++)
            m_pData.addCol(m_pMy->my_field(i), 100);

        for (i=0; i < m_pMy->my_num_rows(); i++)
        {
            m_pMy->my_next_row();
            m_pData.addItem(m_pMy->my_return_row()[0], i);
            for (j=0; j < m_pMy->my_num_cols(); j++)
            {
                if (m_pMy->my_return_row()[j] != NULL)
                    m_pData.addSubItem(m_pMy->my_return_row()[j], i, j);
            }
        }
        m_pMy->my_disconnect();
    }
    catch (char *error)
    {
        MessageBox(Window(), error, "ERROR:", MB_OK);
        return 0;
    }
    return m_pMy->my_num_rows();
}
