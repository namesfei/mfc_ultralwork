#pragma once



// CMyFormView1 窗体视图

class CMyFormView1 : public CFormView
{
	DECLARE_DYNCREATE(CMyFormView1)

protected:
	CMyFormView1();           // 动态创建所使用的受保护的构造函数
	virtual ~CMyFormView1();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
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
	virtual void OnInitialUpdate();
public:
	CBrush m_bgBrush;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};


