
// guofei5Dlg.h: 头文件
//

#pragma once


// Cguofei5Dlg 对话框
class Cguofei5Dlg : public CDialogEx
{
// 构造
public:
	Cguofei5Dlg(CWnd* pParent = nullptr);	// 标准构造函数
	//~Cguofei5Dlg();
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GUOFEI5_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	CFrameWnd* m_pMyFrame;
	afx_msg void OnDestroy();
public:
	CSplitterWnd m_cSplitter;

public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
//public:
	//sta_shipdata ff;
private:
	CMenu m_menu;
public:
	afx_msg void OnUu32771();
	afx_msg void Onland();
	afx_msg void Online();
	/*afx_msg void OnPland();
	afx_msg void OnPline();*/
	afx_msg void OnShatan();
	afx_msg void Ondeng();
	afx_msg void OnDeep();
	afx_msg void OnNewmap();
	afx_msg void OnSavemap();
	afx_msg void OnLoadmap();
};
