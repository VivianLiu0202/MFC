
// Sample-0210View.h : CSample0210View 类的接口
//

#pragma once


class CSample0210View : public CView
{
protected: // 仅从序列化创建
	CSample0210View();
	DECLARE_DYNCREATE(CSample0210View)

// 特性
public:
	CSample0210Doc* GetDocument() const;

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
	virtual ~CSample0210View();
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
	CDC* m_pDC;
public:
	void DrawRect(int iX, int iY, int iR);
};

#ifndef _DEBUG  // Sample-0210View.cpp 中的调试版本
inline CSample0210Doc* CSample0210View::GetDocument() const
   { return reinterpret_cast<CSample0210Doc*>(m_pDocument); }
#endif

