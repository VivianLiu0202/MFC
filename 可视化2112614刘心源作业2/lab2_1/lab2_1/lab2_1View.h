
// lab2_1View.h : Clab2_1View 类的接口
//

#pragma once


class Clab2_1View : public CView
{
protected: // 仅从序列化创建
	Clab2_1View();
	DECLARE_DYNCREATE(Clab2_1View)

// 特性
public:
	Clab2_1Doc* GetDocument() const;

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
	virtual ~Clab2_1View();
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
	afx_msg void OnEcllipse();
	afx_msg void OnInvalidecllipse();
	afx_msg void OnInvalidrectangle();
	afx_msg void OnRect();
//	afx_msg void OnCorlorchange();
	afx_msg void OnChangecolor();
	int PenWidth;
	COLORREF m_clr;
private:
	bool UnableEcllipse;
	bool UnableRect;
public:
	afx_msg void OnValidall();
	//控制椭圆和矩形的大小
	int Eclx,Ecly;
	int Rectx,Recty;
	afx_msg void OnSmall();
	afx_msg void OnBig();
	afx_msg void OnThick();
	afx_msg void OnThin();
//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnShowtext();
};

#ifndef _DEBUG  // lab2_1View.cpp 中的调试版本
inline Clab2_1Doc* Clab2_1View::GetDocument() const
   { return reinterpret_cast<Clab2_1Doc*>(m_pDocument); }
#endif

