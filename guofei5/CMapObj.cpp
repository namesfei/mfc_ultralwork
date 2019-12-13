#include "pch.h"
#include "CMapObj.h"
#include<vector>
IMPLEMENT_SERIAL(CMapObj, CObject, VERSIONABLE_SCHEMA | 1);
CMapObj::CMapObj()
{
}
void CMapObj::clearmap()
{
	// TODO: 在此处添加实现代码.
	m_drawland.clear();
	m_drawline.clear();
	m_drawbeach.clear();
	m_deng.clear();
	m_deep.clear();
	m_deeptxt.empty();
}


void CMapObj::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{	// storing code
		ar << m_drawland.size();
		for (auto i:m_drawland) {
			ar << i.size();
			for (auto j : i) {
				ar << j;
			}
		}
		ar << m_drawline.size();
		for (auto i : m_drawline) {
			ar << i.size();
			for (auto j : i) {
				ar << j;
			}
		}
		ar << m_drawbeach.size();
		for (auto i : m_drawbeach) {
			ar << i.size();
			for (auto j : i) {
				ar << j;
			}
		}
		ar << m_deng.size();
		for (auto i : m_deng) {
			ar << i;
		}
		ar << m_deep.size();
		for (auto i : m_deep) {
			ar << i;
		}
		ar << m_deeptxt.size();
		for (auto i : m_deeptxt) {
			ar << i;
		}
	}
	else
	{	// loading code
		size_t counta,countb;
		ar >> counta;
		for (int i = 0; i < counta; ++i) {
			ar >> countb;
			CPoint temp;
			std::vector<CPoint> tempvec;
			for (int j = 0; j < countb; j++) {
				ar >> temp;
				tempvec.push_back(temp);
			}
			if(!tempvec.empty())
			m_drawland.push_back(tempvec);
		}
		ar >> counta;
		for (int i = 0; i < counta; ++i) {
			ar >> countb;
			CPoint temp;
			std::vector<CPoint> tempvec;
			for (int j = 0; j < countb; j++) {
				ar >> temp;
				tempvec.push_back(temp);
			}
			m_drawline.push_back(tempvec);
		}
		ar >> counta;
		for (int i = 0; i < counta; ++i) {
			ar >> countb;
			CPoint temp;
			std::vector<CPoint> tempvec;
			for (int j = 0; j < countb; j++) {
				ar >> temp;
				tempvec.push_back(temp);
			}
			m_drawbeach.push_back(tempvec);
		}
		CPoint temp;
		ar >> countb;
		for (int j = 0; j < countb; j++) {
			ar >> temp;
			m_deng.push_back(temp);
		}
		ar >> countb;
		for (int j = 0; j < countb; j++) {
			ar >> temp;
			m_deep.push_back(temp);
		}
		CString tempstr;
		ar >> countb;
		for (int j = 0; j < countb; j++) {
			ar >> tempstr;
			m_deeptxt.push_back(tempstr);
		}
	}
}
