
// lab3_2View.h : Clab3_2View 类的接口
//

#pragma once


class Clab3_2View : public CScrollView
{
protected: // 仅从序列化创建
	Clab3_2View();
	DECLARE_DYNCREATE(Clab3_2View)

// 特性
public:
	Clab3_2Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~Clab3_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBigger();
	afx_msg void OnSmaller();
	afx_msg void OnOrigin();
	int drawselect;
	afx_msg void OnPic1();
	afx_msg void OnPic2();
	// 选择图片
	int chooseBit;
};

#ifndef _DEBUG  // lab3_2View.cpp 中的调试版本
inline Clab3_2Doc* Clab3_2View::GetDocument() const
   { return reinterpret_cast<Clab3_2Doc*>(m_pDocument); }
#endif

