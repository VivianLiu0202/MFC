
// Sample-0206View.h : CSample0206View ��Ľӿ�
//

#pragma once


class CSample0206View : public CView
{
protected: // �������л�����
	CSample0206View();
	DECLARE_DYNCREATE(CSample0206View)

// ����
public:
	CSample0206Doc* GetDocument() const;

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
	virtual ~CSample0206View();
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
	afx_msg void OnTestColordialog();
	afx_msg void OnTestMessagebox();
};

#ifndef _DEBUG  // Sample-0206View.cpp �еĵ��԰汾
inline CSample0206Doc* CSample0206View::GetDocument() const
   { return reinterpret_cast<CSample0206Doc*>(m_pDocument); }
#endif

