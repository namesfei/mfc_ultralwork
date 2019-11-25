// CMyFormView1.cpp: 实现文件
//

#include "pch.h"
#include "guofei5.h"
#include "CMyFormView1.h"


// CMyFormView1

IMPLEMENT_DYNCREATE(CMyFormView1, CFormView)

CMyFormView1::CMyFormView1()
	: CFormView(IDD_DIALOG2)
{

}

CMyFormView1::~CMyFormView1()
{
}

void CMyFormView1::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMyFormView1, CFormView)
END_MESSAGE_MAP()


// CMyFormView1 诊断

#ifdef _DEBUG
void CMyFormView1::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CMyFormView1::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMyFormView1 消息处理程序
