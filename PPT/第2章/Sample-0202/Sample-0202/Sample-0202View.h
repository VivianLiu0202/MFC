
// Sample-0202View.h : CSample0202View ��Ľӿ�
//

#pragma once


class CSample0202View : public CView
{
protected: // �������л�����
	CSample0202View();
	DECLARE_DYNCREATE(CSample0202View)

// ����
public:
	CSample0202Doc* GetDocument() const;

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
	virtual ~CSample0202View();
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
};

#ifndef _DEBUG  // Sample-0202View.cpp �еĵ��԰汾
inline CSample0202Doc* CSample0202View::GetDocument() const
   { return reinterpret_cast<CSample0202Doc*>(m_pDocument); }
#endif

