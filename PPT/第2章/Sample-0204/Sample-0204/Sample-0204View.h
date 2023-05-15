
// Sample-0204View.h : CSample0204View 类的接口
//

#pragma once
#include "atltypes.h"


class CSample0204View : public CView
{
protected: // 仅从序列化创建
	CSample0204View();
	DECLARE_DYNCREATE(CSample0204View)

// 特性
public:
	CSample0204Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CSample0204View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
private:
	CPoint m_Pos;
	CString m_Str;
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Sample-0204View.cpp 中的调试版本
inline CSample0204Doc* CSample0204View::GetDocument() const
   { return reinterpret_cast<CSample0204Doc*>(m_pDocument); }
#endif

