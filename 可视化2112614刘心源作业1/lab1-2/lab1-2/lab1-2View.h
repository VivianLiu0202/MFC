
// lab1-2View.h : Clab12View 类的接口
//

#pragma once


class Clab12View : public CView
{
protected: // 仅从序列化创建
	Clab12View();
	DECLARE_DYNCREATE(Clab12View)

// 特性
public:
	Clab12Doc* GetDocument() const;

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
	virtual ~Clab12View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	int x;
	int y;
	int movex;
	int movey;
	int interval;
	bool IsRun;
	int d;//直径
	double degree;//度数
	COLORREF my_color;
	afx_msg void OnBecomeacc();
	afx_msg void OnBecomebig();
	afx_msg void OnBecomedec();
	afx_msg void OnBecomesmall();
	afx_msg void OnColor();
	afx_msg void OnButtonbegin();
	afx_msg void OnButtonend();
};

#ifndef _DEBUG  // lab1-2View.cpp 中的调试版本
inline Clab12Doc* Clab12View::GetDocument() const
   { return reinterpret_cast<Clab12Doc*>(m_pDocument); }
#endif

