
// lab1-2View.h : Clab12View ��Ľӿ�
//

#pragma once


class Clab12View : public CView
{
protected: // �������л�����
	Clab12View();
	DECLARE_DYNCREATE(Clab12View)

// ����
public:
	Clab12Doc* GetDocument() const;

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
	virtual ~Clab12View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	int x;
	int y;
	int movex;
	int movey;
	int interval;
	bool IsRun;
	int d;//ֱ��
	double degree;//����
	COLORREF my_color;
	afx_msg void OnBecomeacc();
	afx_msg void OnBecomebig();
	afx_msg void OnBecomedec();
	afx_msg void OnBecomesmall();
	afx_msg void OnColor();
	afx_msg void OnButtonbegin();
	afx_msg void OnButtonend();
};

#ifndef _DEBUG  // lab1-2View.cpp �еĵ��԰汾
inline Clab12Doc* Clab12View::GetDocument() const
   { return reinterpret_cast<Clab12Doc*>(m_pDocument); }
#endif

