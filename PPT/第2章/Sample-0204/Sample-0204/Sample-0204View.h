
// Sample-0204View.h : CSample0204View ��Ľӿ�
//

#pragma once
#include "atltypes.h"


class CSample0204View : public CView
{
protected: // �������л�����
	CSample0204View();
	DECLARE_DYNCREATE(CSample0204View)

// ����
public:
	CSample0204Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CSample0204View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
private:
	CPoint m_Pos;
	CString m_Str;
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Sample-0204View.cpp �еĵ��԰汾
inline CSample0204Doc* CSample0204View::GetDocument() const
   { return reinterpret_cast<CSample0204Doc*>(m_pDocument); }
#endif

