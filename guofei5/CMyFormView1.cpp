// CMyFormView1.cpp: 实现文件
//

#include "pch.h"
#include "guofei5.h"
#include "CMyFormView1.h"
#include "CMyFormView0.h"
#include"guofei5Dlg.h"
#include "ship.h"
#include<string>
// CMyFormView1

static double dx = 0, dy = 0,dcours=0;

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
//	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON1, &CMyFormView1::OnBnClickedButton1)
//	ON_WM_PAINT()
ON_WM_ERASEBKGND()
//ON_WM_CTLCOLOR()
ON_WM_TIMER()
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


//void CMyFormView1::OnInitialUpdate()
//{
//	CFormView::OnInitialUpdate();
//
//	// TODO: 在此添加专用代码和/或调用基类
//
//	//CBitmap bitmap;
//	//bitmap.LoadBitmap(IDB_BITMAP1);
//	//m_bgBrush.CreatePatternBrush(&bitmap);
//
//
//
//	
//}


//HBRUSH CMyFormView1::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
//{
//	HBRUSH hbr = CFormView::OnCtlColor(pDC, pWnd, nCtlColor);
//
//	// TODO:  在此更改 DC 的任何特性
//	if (pWnd==this) {
//		return m_bgBrush;
//	}
//
//	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
//	return hbr;
//}


void CMyFormView1::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	Cguofei5Dlg* pdlg = (Cguofei5Dlg*)AfxGetMainWnd();
	CMyFormView0* cf=(CMyFormView0*) pdlg->m_cSplitter.GetPane(0, 0);
	MessageBox(cf->sentship[0]);
}


//void CMyFormView1::OnPaint()
//{
//	CPaintDC dc(this); // device context for painting
//					   // TODO: 在此处添加消息处理程序代码
//					   // 不为绘图消息调用 CFormView::OnPaint()
//
//}


void CMyFormView1::OnDraw(CDC* pDC)
{
	// TODO: 在此添加专用代码和/或调用基类

	Cguofei5Dlg* pdlg = (Cguofei5Dlg*)AfxGetMainWnd();
	CMyFormView0* cf = (CMyFormView0*)pdlg->m_cSplitter.GetPane(0, 0);
	sta_shipdata shipdata;
	//strtemp = CStringA(strname);//CStringA是Ansi的CString
	string str = CStringA(cf->sentship[0]);
	shipdata.name = str.c_str();
	strcpy_s(shipdata.number, CStringA(cf->sentship[1]));
	strcpy_s(shipdata.MMSI, CStringA(cf->sentship[2]));
	shipdata.length = float(_ttof(cf->sentship[3]));
	shipdata.width = float(_ttof(cf->sentship[4]));
	shipdata.draft = float(_ttof(cf->sentship[5]));
	shipdata.displacement = float(_ttof(cf->sentship[6]));


	CPoint ptCenter;
	CRect rect;
	GetClientRect(&rect);
	ptCenter = rect.CenterPoint();
	CDC dcMem;//用于缓冲作图的内存DC
	CBitmap bmp;//内存中承载临时图象的位图
	dcMem.CreateCompatibleDC(pDC);//依附窗口DC创建兼容内存DC
	//bmp.CreateCompatibleBitmap(&dcMem, rect.Width(), rect.Height());//创建兼容位图
	bmp.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());//创建兼容位图

	dcMem.SelectObject(&bmp);//将位图选择进内存DC
	dcMem.FillSolidRect(rect, pDC->GetBkColor());//按原来背景填充客户区，不然会是黑色
	//bmp.LoadBitmapW(IDB_BITMAP1);
	
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP1);   //这个IDB_BITMAP1要自己添加
	CBrush  brush;
	brush.CreatePatternBrush(&bitmap);
	CBrush* pOldBrush = dcMem.SelectObject(&brush);
	GetClientRect(&rect);
	dcMem.Rectangle(0, 0, rect.Width(), rect.Height());  // 这些参数可以调整图片添加位置和大小
	dcMem.SelectObject(pOldBrush);
	if (cf->sentship[0]!="") {

		Ship myship(shipdata);
		myship.set_position(38.918055 + dy / 111000,121.630964+dx/1000000);
		myship.set_ship_profile();
		double course = (double)cf->cous_slider.GetPos()-8;
		myship.set_course(dcours);
		myship.set_speed((double)cf->sp_slider.GetPos()-5);

		//显示动态信息
		CString str, strcous, strspe, strpos("船舶位置：");
		strcous.Format(TEXT("航向：%.3f°"), myship.outdm()->course);
		strspe.Format(TEXT("速度：%.3fKm/h"), myship.outdm()->speed);
		str.Format(_T("%.6f"), myship.outdm()->latitude); strpos += str; strpos += "° ";
		//strpos.Format(TEXT("船舶位置：%.3f°"), myship.outsm()->width);
		if (myship.outdm()->latitude < 0)
			strpos += "S   ";
		else
			strpos += "N   ";
		str.Format(_T("%.6f"), myship.outdm()->longitude); strpos += str; strpos += "° ";
		if (myship.outdm()->longitude < 0)
			strpos += "W";
		else
			strpos += "E";
		dcMem.TextOutW(0, 40, strcous);
		dcMem.TextOutW(0, 70, strspe);
		dcMem.TextOutW(0, 100, strpos);
		//显示船舶信息
		double cx = 100;//调整起始位置
		double cy = 600;
		double scale = 0.5;
		/*CString ddd;
		ddd.Format(_T("%f"), dx);
		MessageBox(ddd);*/
		for (int i = 0; i < 5; i++) {
			CPen pNewPen;
			pNewPen.CreatePen(PS_SOLID, 2, RGB(rand() % 255, rand() % 255, i*20 % 255)); // 随机色
			CPen* poldPen = dcMem.SelectObject(&pNewPen);
			dcMem.MoveTo(int(myship.outdm()->ship_profile[i].x * scale + cx + dx), int(-myship.outdm()->ship_profile[i].y * scale + cy - dy));
			if (4 == i) {
				dcMem.LineTo(int(myship.outdm()->ship_profile[0].x * scale + cx + dx), int(-myship.outdm()->ship_profile[0].y * scale + cy - dy));
			}
			else {
				dcMem.LineTo(int(myship.outdm()->ship_profile[i + 1].x * scale + cx + dx), int(-myship.outdm()->ship_profile[i + 1].y * scale + cy - dy));
			}
		}
	}
	/*CBitmap bitmap;
	bitmap.LoadBitmapW(IDB_BITMAP1);
	CDC dcCompatible;
	dcCompatible.CreateCompatibleDC(&dcMem);
	dcCompatible.SelectObject(&bitmap);
	CRect rect1;
	GetClientRect(&rect1);
	dcMem.BitBlt(0,43, rect1.Width(), rect1.Height(), &dcCompatible, 0, 0, SRCCOPY);*/

	pDC->BitBlt(0, 43, rect.Width(), rect.Height(), &dcMem, 0, 0, SRCCOPY);//将内存DC上的图象拷贝到前台
	dcMem.DeleteDC();//删除DC
	bmp.DeleteObject();

}


BOOL CMyFormView1::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	/*CBitmap bitmap;
	bitmap.LoadBitmapW(IDB_BITMAP1);
	CDC dcCompatible;
	dcCompatible.CreateCompatibleDC(pDC);
	dcCompatible.SelectObject(&bitmap);
	CRect rect;
	GetClientRect(&rect);
	pDC->BitBlt(0,43, rect.Width(), rect.Height(), &dcCompatible, 0, 0, SRCCOPY);*/

	//return CFormView::OnEraseBkgnd(pDC);
	return TRUE;
}





void CMyFormView1::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	Cguofei5Dlg* pdlg = (Cguofei5Dlg*)AfxGetMainWnd();
	CMyFormView0* cf = (CMyFormView0*)pdlg->m_cSplitter.GetPane(0, 0);
	if (cf->sentship[0] != "") {

		double dspeed;
		dspeed = ((double)cf->sp_slider.GetPos() - 5) * 0.1 * 1000 / 3600;
		dcours += ((double)cf->cous_slider.GetPos() - 8)*dspeed;
		if (dcours > 360||dcours==360) {
			dcours -= 360;
		}
		dx += sin(dcours * 3.14159 / 180) * dspeed;
		dy += cos(dcours * 3.14159 / 180) * dspeed;

		/*dx += sin(((double)cf->cous_slider.GetPos() - 45) *3.14/ 180) * dspeed;
		dy += cos(((double)cf->cous_slider.GetPos() - 45)*3.14 / 180) * dspeed;
		*/
		Invalidate();
	}
	
	CFormView::OnTimer(nIDEvent);

}


void CMyFormView1::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	SetTimer(1, 100, NULL);
	// TODO: 在此添加专用代码和/或调用基类
}


void CMyFormView1::resetval(bool i)
{
	// TODO: 在此处添加实现代码.

	dx = 0;
	dy = 0;
	dcours = 0;
	KillTimer(1);
	if (i) {
		SetTimer(1, 100, NULL);
	}
}
