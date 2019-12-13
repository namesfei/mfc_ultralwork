#pragma once
#include <afx.h>
#include <vector>
class CMapObj :
	public CObject
{
	DECLARE_SERIAL(CMapObj)
public:
	CMapObj();

public:
	std::vector<std::vector<CPoint>> m_drawland;
	std::vector<std::vector<CPoint>> m_drawline;
	std::vector<std::vector<CPoint>> m_drawbeach;
	std::vector<CPoint> m_deng;
	std::vector<CPoint> m_deep;
	std::vector<CString> m_deeptxt;
public:
	void clearmap();
	virtual void Serialize(CArchive& ar);
};

