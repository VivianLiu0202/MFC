
// Sample-0203View.h : CSample0203View 类的接口
//

#pragma once


class CSample0203View : public CView
{
protected: // 仅从序列化创建
	CSample0203View();
	DECLARE_DYNCREATE(CSample0203View)

// 特性
public:
	CSample0203Doc* GetDocument() const;

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
	virtual ~CSample0203View();
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
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
private:
	int m_Num;
};

#ifndef _DEBUG  // Sample-0203View.cpp 中的调试版本
inline CSample0203Doc* CSample0203View::GetDocument() const
   { return reinterpret_cast<CSample0203Doc*>(m_pDocument); }
#endif

