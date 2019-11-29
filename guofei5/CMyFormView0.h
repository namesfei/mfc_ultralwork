#pragma once


// CMyFormView0 窗体视图
class CMyFormView0 : public CFormView
{
	DECLARE_DYNCREATE(CMyFormView0)

protected:
	CMyFormView0();           // 动态创建所使用的受保护的构造函数
	virtual ~CMyFormView0();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
private:
	CComboBox selectship;
public:
	virtual void OnInitialUpdate();
	afx_msg void OnCbnSelchangeCombo1();
private:
	CEdit o_name;
	CEdit o_num;
	CEdit o_mmsi;
private:
	CEdit o_len;
	CEdit o_wid;
	CEdit o_draf;
	CEdit o_disp;
	CEdit i_name;
	CEdit i_num;
	CEdit i_mmsi;
	CEdit i_len;
	CEdit i_wid;
	CEdit i_draft;
	CEdit i_disp;
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
public:
	CString m_sentship[7];  //传递船舶信息
	CSliderCtrl sp_slider;
	CSliderCtrl cous_slider;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
private:
	CButton delet_button;
public:
	afx_msg void OnNMCustomdrawSlider2(NMHDR* pNMHDR, LRESULT* pResult);
};


