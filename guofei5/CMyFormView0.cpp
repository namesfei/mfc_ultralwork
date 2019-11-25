// CMyFormView0.cpp: 实现文件
//

#include "pch.h"
#include "guofei5.h"
#include "CMyFormView0.h"
#include "ship.h"
#include<vector>

//extern vector<sta_shipdata> v_ship;
static vector<sta_shipdata> v_ship;
static string strtemp;
// CMyFormView0

IMPLEMENT_DYNCREATE(CMyFormView0, CFormView)

CMyFormView0::CMyFormView0()
	: CFormView(IDD_DIALOG1)
{
}

CMyFormView0::~CMyFormView0()
{
}

void CMyFormView0::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, o_name);
	DDX_Control(pDX, IDC_EDIT2, o_num);
	DDX_Control(pDX, IDC_COMBO1, selectship);
	DDX_Control(pDX, IDC_EDIT3, o_mmsi);
	DDX_Control(pDX, IDC_EDIT4, o_len);
	DDX_Control(pDX, IDC_EDIT5, o_wid);
	DDX_Control(pDX, IDC_EDIT6, o_draf);
	DDX_Control(pDX, IDC_EDIT7, o_disp);

	DDX_Control(pDX, IDC_EDIT8, i_name);
	DDX_Control(pDX, IDC_EDIT9, i_num);
	DDX_Control(pDX, IDC_EDIT11, i_mmsi);
	DDX_Control(pDX, IDC_EDIT10, i_len);
	DDX_Control(pDX, IDC_EDIT13, i_wid);
	DDX_Control(pDX, IDC_EDIT12, i_draft);
	DDX_Control(pDX, IDC_EDIT14, i_disp);
}

BEGIN_MESSAGE_MAP(CMyFormView0, CFormView)
	ON_EN_CHANGE(IDC_EDIT1, &CMyFormView0::OnEnChangeEdit1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CMyFormView0::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMyFormView0::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CMyFormView0::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMyFormView0 诊断

#ifdef _DEBUG
void CMyFormView0::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CMyFormView0::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMyFormView0 消息处理程序


void CMyFormView0::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CFormView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	
}


void CMyFormView0::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	//selectship.AddString(_T("GUOFEI"));
	sta_shipdata mship = { "阳光",{'1','2','3','4','5','6','7','8','9','\0'}, {'8','8','8','8','\0'},90,18,5,2000 };
	sta_shipdata mship1= { "泰坦尼克",{'1','2','2','9','5','8','7','8','9','\0'}, {'4','5','6','7','\0'},90,18,5,2000 };

	v_ship.push_back(mship);
	v_ship.push_back(mship1);
	CString str;
	str = v_ship[0].name;
	selectship.AddString(str);
	//selectship.AddString(_T("第二"));
	str = v_ship[1].name;
	selectship.AddString(str);
	
	i_num.SetLimitText(4);
	i_mmsi.SetLimitText(9);
}


void CMyFormView0::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码

	int index = selectship.GetCurSel();
	CString str;
	selectship.GetLBText(index, str);
	CString strname, strnum, strmmsi, strlen, strwid, strdraf, strdisp;
	for (auto i : v_ship) {

		if (str==i.name) {
			strname = i.name;
			strnum = i.number;
			strmmsi = i.MMSI;
			strlen.Format(_T("%.3f米"), i.length);
			strwid.Format(_T("%.3f米"), i.width);
			strdraf.Format(_T("%.3f米"), i.draft);
			strdisp.Format(_T("%.3f吨"), i.displacement);
			o_name.SetWindowTextW(strname);
			o_num.SetWindowTextW(strnum);
			o_mmsi.SetWindowTextW(strmmsi);
			o_len.SetWindowTextW(strlen);
			o_wid.SetWindowTextW(strwid);
			o_draf.SetWindowTextW(strdraf);
			o_disp.SetWindowTextW(strdisp);
		}
	}
	//MessageBox(_T("haha"));
}


void CMyFormView0::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	//UpdateData(true);
	CString strname, strnum, strmmsi, strlen, strwid, strdraf, strdisp;
	i_name.GetWindowTextW(strname);
	i_num.GetWindowTextW(strnum);
	i_mmsi.GetWindowTextW(strmmsi);
	i_len.GetWindowTextW(strlen);
	i_wid.GetWindowTextW(strwid);
	i_draft.GetWindowTextW(strdraf);
	i_disp.GetWindowTextW(strdisp);

	if (strname.IsEmpty() || strnum.IsEmpty() || strmmsi.IsEmpty() || strlen.IsEmpty() || strwid.IsEmpty() || strdraf.IsEmpty() || strdisp.IsEmpty()) {
	
		MessageBox(_T("请输入正确数据"));
	}
	else {
		sta_shipdata addship;

		strtemp = CStringA(strname);//CStringA是Ansi的CString
		addship.name = strtemp.c_str();

		//char temp[0x100]="0";
		//::wsprintfA(temp, "%ls", (LPCTSTR)strname);
		//addship.name = temp;

		//addship.name = CStringA(strname);
		strcpy_s(addship.number, CStringA(strnum));
		strcpy_s(addship.MMSI, CStringA(strmmsi));

		//addship.name= CT2A(strname.GetString());
		//wsprintfA(addship.number, "%ls", strnum);
		//wsprintfA(addship.MMSI, "%ls", strmmsi);

		//addship.name =strname.GetBuffer(strname.GetLength());

		//USES_CONVERSION;
		//addship.name = T2A(strname);
		//int n = strnum.GetLength(); //获取str的字符数  
		//int len = WideCharToMultiByte(CP_ACP, 0, strnum, n, NULL, 0, NULL, NULL);
		//WideCharToMultiByte(CP_ACP, 0, strnum, n, addship.number, len, NULL, NULL);
		//addship.number[len + 1] = '\0';
		//n = strmmsi.GetLength();
		//len = WideCharToMultiByte(CP_ACP, 0, strmmsi, n, NULL, 0, NULL, NULL);
		//WideCharToMultiByte(CP_ACP, 0, strmmsi, n, addship.MMSI, len, NULL, NULL);
		//addship.name = "郭飞";
		     ////字符转换方法2
		//int n = strnum.GetLength(); //获取str的字符数  
		//int len = WideCharToMultiByte(CP_ACP, 0, strnum, n, NULL, 0, NULL, NULL);
		//WideCharToMultiByte(CP_ACP, 0, strnum, n, addship.number, len, NULL, NULL);
		//addship.number[len + 1] = '\0';
		///*strcpy_s(addship.MMSI, "123456789");*/
		//n = strmmsi.GetLength();
		//len = WideCharToMultiByte(CP_ACP, 0, strmmsi, n, NULL, 0, NULL, NULL);
		//WideCharToMultiByte(CP_ACP, 0, strmmsi, n, addship.MMSI, len, NULL, NULL);
		
		addship.length = float(_ttof(strlen));
		addship.width = float(_ttof(strwid));
		addship.draft =float(_ttof(strdraf));
		addship.displacement= float(_ttof(strdisp));
		//strname = "郭";
		v_ship.push_back(addship);
		selectship.AddString(strname);

		//CString str1;
		//str1=v_ship[2].name;
		//MessageBox(str1);
		MessageBox(_T("添加成功"));
		i_name.SetWindowTextW(_T(""));
		i_num.SetWindowTextW(_T(""));
		i_mmsi.SetWindowTextW(_T(""));
		i_len.SetWindowTextW(_T(""));
		i_wid.SetWindowTextW(_T(""));
		i_draft.SetWindowTextW(_T(""));
		i_disp.SetWindowTextW(_T(""));
	}


}


void CMyFormView0::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	int index = selectship.GetCurSel();
	CString str;
	selectship.GetLBText(index, str);
	selectship.DeleteString(index);
	if (!v_ship.empty()) {
		for (vector<sta_shipdata>::iterator it = v_ship.begin(); it != v_ship.end();) {
			if (it->name == str) {
				it = v_ship.erase(it);
				break;
			}
			else {
				++it;
			}	
		}
	}
	//else {
	//	MessageBox(_T("已删除所有项！"));
	//}
	o_name.SetWindowTextW(_T(""));
	o_num.SetWindowTextW(_T(""));
	o_mmsi.SetWindowTextW(_T(""));
	o_len.SetWindowTextW(_T(""));
	o_wid.SetWindowTextW(_T(""));
	o_draf.SetWindowTextW(_T(""));
	o_disp.SetWindowTextW(_T(""));
	MessageBox(_T("已删除！"));
}
