
// lab4_1View.h : Clab4_1View ��Ľӿ�
//

#pragma once


class Clab4_1View : public CView
{
protected: // �������л�����
	Clab4_1View();
	DECLARE_DYNCREATE(Clab4_1View)

// ����
public:
	Clab4_1Doc* GetDocument() const;

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
	virtual ~Clab4_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnOpendlg();
};

#ifndef _DEBUG  // lab4_1View.cpp �еĵ��԰汾
inline Clab4_1Doc* Clab4_1View::GetDocument() const
   { return reinterpret_cast<Clab4_1Doc*>(m_pDocument); }
#endif

