
// Sample-0201View.h : CSample0201View 类的接口
//

#pragma once


class CSample0201View : public CView
{
protected: // 仅从序列化创建
	CSample0201View();
	DECLARE_DYNCREATE(CSample0201View)

// 特性
public:
	CSample0201Doc* GetDocument() const;

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
	virtual ~CSample0201View();
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
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnEditPaste();
};

#ifndef _DEBUG  // Sample-0201View.cpp 中的调试版本
inline CSample0201Doc* CSample0201View::GetDocument() const
   { return reinterpret_cast<CSample0201Doc*>(m_pDocument); }
#endif

