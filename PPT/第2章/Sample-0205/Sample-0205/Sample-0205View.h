
// Sample-0205View.h : CSample0205View ��Ľӿ�
//

#pragma once


class CSample0205View : public CView
{
protected: // �������л�����
	CSample0205View();
	DECLARE_DYNCREATE(CSample0205View)

// ����
public:
	CSample0205Doc* GetDocument() const;

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
	virtual ~CSample0205View();
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
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};

#ifndef _DEBUG  // Sample-0205View.cpp �еĵ��԰汾
inline CSample0205Doc* CSample0205View::GetDocument() const
   { return reinterpret_cast<CSample0205Doc*>(m_pDocument); }
#endif

