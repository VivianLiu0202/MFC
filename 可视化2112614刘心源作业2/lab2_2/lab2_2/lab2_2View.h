
// lab2_2View.h : Clab2_2View 类的接口
//

#pragma once


class Clab2_2View : public CView
{
protected: // 仅从序列化创建
	Clab2_2View();
	DECLARE_DYNCREATE(Clab2_2View)

// 特性
public:
	Clab2_2Doc* GetDocument() const;

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
	virtual ~Clab2_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTest();
	CString string;
	afx_msg void OnFont();
	COLORREF m_CurrentCr;
	LOGFONT m_Lofont;
	CPoint startPoint;
};

#ifndef _DEBUG  // lab2_2View.cpp 中的调试版本
inline Clab2_2Doc* Clab2_2View::GetDocument() const
   { return reinterpret_cast<Clab2_2Doc*>(m_pDocument); }
#endif

