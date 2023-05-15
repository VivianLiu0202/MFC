
// Sample-0207View.h : CSample0207View 类的接口
//

#pragma once


class CSample0207View : public CView
{
protected: // 仅从序列化创建
	CSample0207View();
	DECLARE_DYNCREATE(CSample0207View)

// 特性
public:
	CSample0207Doc* GetDocument() const;

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
	virtual ~CSample0207View();
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
	afx_msg void OnTimer(UINT_PTR nIDEvent);
private:
	int x;
	int y;
	int movex;
	int movey;
};

#ifndef _DEBUG  // Sample-0207View.cpp 中的调试版本
inline CSample0207Doc* CSample0207View::GetDocument() const
   { return reinterpret_cast<CSample0207Doc*>(m_pDocument); }
#endif

