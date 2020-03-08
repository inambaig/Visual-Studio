#include "stdafx.h"
#include "Calc.h"
#include "Options.h"
#include "afxdialogex.h"


// Options dialog

IMPLEMENT_DYNAMIC(Options, CDialog)

Options::Options(CWnd* pParent /*=NULL*/)
: CDialog(Options::IDD, pParent)
, width(0)
, length(0)
, m_text(0)
, result(_T(""))
{

}

Options::~Options()
{
}

void Options::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, width);
	DDX_Text(pDX, IDC_EDIT2, length);

	DDX_Text(pDX, IDC_EDIT3, result);
}


BEGIN_MESSAGE_MAP(Options, CDialog)



END_MESSAGE_MAP()
