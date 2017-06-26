#include "CRichEdit.h"
#include <richedit.h>

CRichEdit::CRichEdit(class CWin* parent)
    : CControl(parent, ControlTypes::RichEdit, RICHEDIT_CLASS)
{
    LoadLibrary("RichEd20.dll");

    this->_windowStyles = ES_MULTILINE | WS_VISIBLE | WS_CHILD | WS_BORDER | WS_TABSTOP;
    this->_windowStylesEx = WS_EX_STATICEDGE;
}

CRichEdit::~CRichEdit()
{ }
