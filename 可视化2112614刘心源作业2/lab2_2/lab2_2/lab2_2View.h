
// lab2_2View.h : Clab2_2View ��Ľӿ�
//

#pragma once


class Clab2_2View : public CView
{
protected: // �������л�����
	Clab2_2View();
	DECLARE_DYNCREATE(Clab2_2View)

// ����
public:
	Clab2_2Doc* GetDocument() const;

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
	virtual ~Clab2_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTest();
	CString string;
	afx_msg void OnFont();
	COLORREF m_CurrentCr;
	LOGFONT m_Lofont;
	CPoint startPoint;
};

#ifndef _DEBUG  // lab2_2View.cpp �еĵ��԰汾
inline Clab2_2Doc* Clab2_2View::GetDocument() const
   { return reinterpret_cast<Clab2_2Doc*>(m_pDocument); }
#endif

