
// Sample-0201View.h : CSample0201View ��Ľӿ�
//

#pragma once


class CSample0201View : public CView
{
protected: // �������л�����
	CSample0201View();
	DECLARE_DYNCREATE(CSample0201View)

// ����
public:
	CSample0201Doc* GetDocument() const;

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
	virtual ~CSample0201View();
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
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnEditPaste();
};

#ifndef _DEBUG  // Sample-0201View.cpp �еĵ��԰汾
inline CSample0201Doc* CSample0201View::GetDocument() const
   { return reinterpret_cast<CSample0201Doc*>(m_pDocument); }
#endif

