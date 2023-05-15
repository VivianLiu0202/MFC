
// lab2_1View.h : Clab2_1View ��Ľӿ�
//

#pragma once


class Clab2_1View : public CView
{
protected: // �������л�����
	Clab2_1View();
	DECLARE_DYNCREATE(Clab2_1View)

// ����
public:
	Clab2_1Doc* GetDocument() const;

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
	virtual ~Clab2_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	afx_msg void OnEcllipse();
	afx_msg void OnInvalidecllipse();
	afx_msg void OnInvalidrectangle();
	afx_msg void OnRect();
//	afx_msg void OnCorlorchange();
	afx_msg void OnChangecolor();
	int PenWidth;
	COLORREF m_clr;
private:
	bool UnableEcllipse;
	bool UnableRect;
public:
	afx_msg void OnValidall();
	//������Բ�;��εĴ�С
	int Eclx,Ecly;
	int Rectx,Recty;
	afx_msg void OnSmall();
	afx_msg void OnBig();
	afx_msg void OnThick();
	afx_msg void OnThin();
//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnShowtext();
};

#ifndef _DEBUG  // lab2_1View.cpp �еĵ��԰汾
inline Clab2_1Doc* Clab2_1View::GetDocument() const
   { return reinterpret_cast<Clab2_1Doc*>(m_pDocument); }
#endif

