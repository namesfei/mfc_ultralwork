// CMyFormView0.cpp: ʵ���ļ�
//

#include "pch.h"
#include "guofei5.h"
#include "ship.h"
#include "CMyFormView0.h"
#include "CMyFormView1.h"
#include<vector>
#include"guofei5Dlg.h"
#include<string>
static vector<sta_shipdata> v_ship; //�������д�����Ϣ
static string strtemp; //��ʱ�����ַ���
// CMyFormView0

IMPLEMENT_DYNCREATE(CMyFormView0, CFormView)

CMyFormView0::CMyFormView0()
	: CFormView(IDD_DIALOG1)
{
	m_tempship =  { "",{'\0'}, {'\0'},0,0,0,0 };
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
	DDX_Control(pDX, IDC_SLIDER2, sp_slider);
	DDX_Control(pDX, IDC_SLIDER1, cous_slider);
	DDX_Control(pDX, IDC_BUTTON1, delet_button);
}

BEGIN_MESSAGE_MAP(CMyFormView0, CFormView)
	ON_EN_CHANGE(IDC_EDIT1, &CMyFormView0::OnEnChangeEdit1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CMyFormView0::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMyFormView0::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CMyFormView0::OnBnClickedButton1)
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER2, &CMyFormView0::OnNMCustomdrawSlider2)
END_MESSAGE_MAP()


// CMyFormView0 ���

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


// CMyFormView0 ��Ϣ�������


void CMyFormView0::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CFormView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	
}


void CMyFormView0::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���

	//�������Ĭ�ϴ�����Ϣ
	sta_shipdata mship = { "����",{'1','2','3','4','5','6','7','8','9','\0'}, {'8','8','8','8','\0'},90,18,5,2000 };
	sta_shipdata mship1= { "̩̹���",{'1','2','2','9','5','8','7','8','9','\0'}, {'4','5','6','7','\0'},100,30,5,2000 };
	v_ship.push_back(mship);
	v_ship.push_back(mship1);

	//����������䴬����Ϣ
	CString str;
	str = v_ship[0].name;
	selectship.AddString(str);
	str = v_ship[1].name;
	selectship.AddString(str);
	
	//�޶��ַ����볤��
	i_num.SetLimitText(4);
	i_mmsi.SetLimitText(9);

	//���û����ʼ��
	sp_slider.SetRange(0, 30);
	sp_slider.SetTicFreq(1);
	sp_slider.SetPos(25);
	cous_slider.SetRange(0, 160);
	cous_slider.SetTicFreq(1);
	cous_slider.SetPos(80);
}


void CMyFormView0::OnCbnSelchangeCombo1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//��λslider
	sp_slider.EnableWindow(); cous_slider.EnableWindow();
	sp_slider.SetPos(25); cous_slider.SetPos(80);
	delet_button.EnableWindow();
	//��⵱ǰ������ѡ������
	int index = selectship.GetCurSel();
	CString str;
	selectship.GetLBText(index, str);
	//�����Ӧ��ֻ����
	CString strname, strnum, strmmsi, strlen, strwid, strdraf, strdisp;
	for (auto i : v_ship) {

		if (str==i.name) {
			
			//CMyView* pView = (CMyView*)((CMainFrame*)AfxGetMainWnd())->m_wndSplitter.GetPane(0, 0));
			strname = i.name;
			strnum = i.number;
			strmmsi = i.MMSI;
			strlen.Format(_T("%.3f��"), i.length);
			strwid.Format(_T("%.3f��"), i.width);
			strdraf.Format(_T("%.3f��"), i.draft);
			strdisp.Format(_T("%.3f��"), i.displacement);
			o_name.SetWindowTextW(strname);
			o_num.SetWindowTextW(strnum);
			o_mmsi.SetWindowTextW(strmmsi);
			o_len.SetWindowTextW(strlen);
			o_wid.SetWindowTextW(strwid);
			o_draf.SetWindowTextW(strdraf);
			o_disp.SetWindowTextW(strdisp);
			//����Ϣ�������view1��ʹ��
			memcpy(&m_tempship, &i, sizeof(i));


		}
	}

	//����view1��ʾ����
	Cguofei5Dlg* pdlg = (Cguofei5Dlg*)AfxGetMainWnd();
	CMyFormView1* cf1= (CMyFormView1*)pdlg->m_cSplitter.GetPane(0, 1);
	cf1->m_resetval(1);
	pdlg->m_cSplitter.GetPane(0, 1)->Invalidate();

}


void CMyFormView0::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	//ʵ����Ӵ�ֻ
	CString strname, strnum, strmmsi, strlen, strwid, strdraf, strdisp;
	i_name.GetWindowTextW(strname);
	i_num.GetWindowTextW(strnum);
	i_mmsi.GetWindowTextW(strmmsi);
	i_len.GetWindowTextW(strlen);
	i_wid.GetWindowTextW(strwid);
	i_draft.GetWindowTextW(strdraf);
	i_disp.GetWindowTextW(strdisp);

	if (strname.IsEmpty() || strnum.IsEmpty() || strmmsi.IsEmpty() || strlen.IsEmpty() || strwid.IsEmpty() || strdraf.IsEmpty() || strdisp.IsEmpty()) {
	
		MessageBox(_T("��������ȷ����"));
	}
	else {
		sta_shipdata addship;

		strtemp = CStringA(strname);//CStringA��Ansi��CString
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
		//int n = strnum.GetLength(); //��ȡstr���ַ���  
		//int len = WideCharToMultiByte(CP_ACP, 0, strnum, n, NULL, 0, NULL, NULL);
		//WideCharToMultiByte(CP_ACP, 0, strnum, n, addship.number, len, NULL, NULL);
		//addship.number[len + 1] = '\0';
		//n = strmmsi.GetLength();
		//len = WideCharToMultiByte(CP_ACP, 0, strmmsi, n, NULL, 0, NULL, NULL);
		//WideCharToMultiByte(CP_ACP, 0, strmmsi, n, addship.MMSI, len, NULL, NULL);
		//addship.name = "����";
		     ////�ַ�ת������2
		//int n = strnum.GetLength(); //��ȡstr���ַ���  
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
		//strname = "��";
		v_ship.push_back(addship);
		selectship.AddString(strname);
		//�ÿձ༭��
		MessageBox(_T("��ӳɹ�"));
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//���ɾ����������
	if (v_ship.size()) {
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
			Cguofei5Dlg* pdlg = (Cguofei5Dlg*)AfxGetMainWnd();
			CMyFormView1* cf1 = (CMyFormView1*)pdlg->m_cSplitter.GetPane(0, 1);
			cf1->m_resetval(0);
		}
		o_name.SetWindowTextW(_T(""));
		o_num.SetWindowTextW(_T(""));
		o_mmsi.SetWindowTextW(_T(""));
		o_len.SetWindowTextW(_T(""));
		o_wid.SetWindowTextW(_T(""));
		o_draf.SetWindowTextW(_T(""));
		o_disp.SetWindowTextW(_T(""));
		MessageBox(_T("��ɾ����"));
	}
	else
	{
		MessageBox(_T("��ɾ�����У�"));
	}
}


void CMyFormView0::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	//������������ˢ����ͼ����
	Cguofei5Dlg* pdlg = (Cguofei5Dlg*)AfxGetMainWnd();
	pdlg->m_cSplitter.GetPane(0, 1)->Invalidate();

	CFormView::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CMyFormView0::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	//������������ˢ����ͼ����
	Cguofei5Dlg* pdlg = (Cguofei5Dlg*)AfxGetMainWnd();
	pdlg->m_cSplitter.GetPane(0, 1)->Invalidate();

	CFormView::OnVScroll(nSBCode, nPos, pScrollBar);
}


void CMyFormView0::OnNMCustomdrawSlider2(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}
