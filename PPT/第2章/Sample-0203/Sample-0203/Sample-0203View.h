
// Sample-0203View.h : CSample0203View ��Ľӿ�
//

#pragma once


class CSample0203View : public CView
{
protected: // �������л�����
	CSample0203View();
	DECLARE_DYNCREATE(CSample0203View)

// ����
public:
	CSample0203Doc* GetDocument() const;

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
	virtual ~CSample0203View();
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
private:
	int m_Num;
};

#ifndef _DEBUG  // Sample-0203View.cpp �еĵ��԰汾
inline CSample0203Doc* CSample0203View::GetDocument() const
   { return reinterpret_cast<CSample0203Doc*>(m_pDocument); }
#endif

