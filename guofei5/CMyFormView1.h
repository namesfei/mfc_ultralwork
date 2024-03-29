﻿#pragma once
#include <vector>
#include "CMapObj.h"

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
//	virtual void OnInitialUpdate();
public:
	CBrush m_bgBrush;
//	CDC dcMem;

	//afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
//	afx_msg void OnBnClickedButton1();
//	afx_msg void OnPaint();
	virtual void OnDraw(CDC* /*pDC*/);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
//	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual void OnInitialUpdate();
	void m_resetval(bool);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
public:
	int m_select;	//选择菜单栏选项
private:
	std::vector<CPoint > m_tempvct;
	CMapObj m_mapdata;

public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	void m_drawmap(CDC &dcMem,std::vector<std::vector<CPoint>> &vec,int nwidth,COLORREF lineColor, COLORREF inColor);
//	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	bool m_checkpeng(int x, int y, std::vector<std::vector<CPoint>> m_drawland);
	void newmap();
	void savemap();
	void loadmap();
	void returnlast();
//	void m_selectstart();
private:
	CPoint m_shipstart;
public:
	bool isleft(int x, int y, CPoint a, CPoint b);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};


