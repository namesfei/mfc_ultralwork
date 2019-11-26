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
	ON_WM_CTLCOLOR()
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


void CMyFormView1::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类

	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP1);
	m_bgBrush.CreatePatternBrush(&bitmap);



	
}


HBRUSH CMyFormView1::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CFormView::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if (pWnd==this) {
		return m_bgBrush;
	}

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}
