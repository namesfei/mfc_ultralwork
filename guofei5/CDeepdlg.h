#pragma once


// CDeepdlg 对话框

class CDeepdlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDeepdlg)

public:
	CDeepdlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDeepdlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CEdit deepdata;
public:
	afx_msg void OnBnClickedOk();
public:
	CString m_deepdata;
};
