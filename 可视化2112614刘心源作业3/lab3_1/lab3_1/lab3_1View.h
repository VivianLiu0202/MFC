
// lab3_1View.h : Clab3_1View 类的接口
//

#pragma once


class Clab3_1View : public CView
{
protected: // 仅从序列化创建
	Clab3_1View();
	DECLARE_DYNCREATE(Clab3_1View)

// 特性
public:
	Clab3_1Doc* GetDocument() const;

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
	virtual ~Clab3_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnDrawline();
	afx_msg void OnDrawp();
	afx_msg void OnDrawrect();
	bool moveLoop;
	int drawSelect;
	CPoint point3[6];
	CPoint point2[2];
	CPoint point1[2];
	int x1;
	int y1;
	int movex1;
	int movey1;

	int x2;
	int y2;
	int movex2;
	int movey2;

	int x3;
	int y3;
	int movex3;
	int movey3;
};

#ifndef _DEBUG  // lab3_1View.cpp 中的调试版本
inline Clab3_1Doc* Clab3_1View::GetDocument() const
   { return reinterpret_cast<Clab3_1Doc*>(m_pDocument); }
#endif

