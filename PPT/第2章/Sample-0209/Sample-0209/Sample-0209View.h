
// Sample-0209View.h : CSample0209View ��Ľӿ�
//

#pragma once
#define WM_MYMESSAGE WM_USER+1

class CSample0209View : public CView
{
protected: // �������л�����
	CSample0209View();
	DECLARE_DYNCREATE(CSample0209View)

// ����
public:
	CSample0209Doc* GetDocument() const;

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
	virtual ~CSample0209View();
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
	afx_msg LRESULT OnMyMessage(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()	
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // Sample-0209View.cpp �еĵ��԰汾
inline CSample0209Doc* CSample0209View::GetDocument() const
   { return reinterpret_cast<CSample0209Doc*>(m_pDocument); }
#endif

