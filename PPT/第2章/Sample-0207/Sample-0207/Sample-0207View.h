
// Sample-0207View.h : CSample0207View ��Ľӿ�
//

#pragma once


class CSample0207View : public CView
{
protected: // �������л�����
	CSample0207View();
	DECLARE_DYNCREATE(CSample0207View)

// ����
public:
	CSample0207Doc* GetDocument() const;

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
	virtual ~CSample0207View();
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
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
private:
	int x;
	int y;
	int movex;
	int movey;
};

#ifndef _DEBUG  // Sample-0207View.cpp �еĵ��԰汾
inline CSample0207Doc* CSample0207View::GetDocument() const
   { return reinterpret_cast<CSample0207Doc*>(m_pDocument); }
#endif

