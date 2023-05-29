
// lab4_1View.h : Clab4_1View 类的接口
//

#pragma once


class Clab4_1View : public CView
{
protected: // 仅从序列化创建
	Clab4_1View();
	DECLARE_DYNCREATE(Clab4_1View)

// 特性
public:
	Clab4_1Doc* GetDocument() const;

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
	virtual ~Clab4_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnOpendlg();
};

#ifndef _DEBUG  // lab4_1View.cpp 中的调试版本
inline Clab4_1Doc* Clab4_1View::GetDocument() const
   { return reinterpret_cast<Clab4_1Doc*>(m_pDocument); }
#endif

