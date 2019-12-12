// CDeepdlg.cpp: 实现文件
//

#include "pch.h"
#include "guofei5.h"
#include "CDeepdlg.h"
#include "afxdialogex.h"


// CDeepdlg 对话框

IMPLEMENT_DYNAMIC(CDeepdlg, CDialogEx)

CDeepdlg::CDeepdlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{
	m_deepdata = "";
}

CDeepdlg::~CDeepdlg()
{
}

void CDeepdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, deepdata);
}


BEGIN_MESSAGE_MAP(CDeepdlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDeepdlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CDeepdlg 消息处理程序


void CDeepdlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	deepdata.GetWindowTextW(m_deepdata);

	CDialogEx::OnOK();
}
