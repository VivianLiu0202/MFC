
// lab3_2View.h : Clab3_2View ��Ľӿ�
//

#pragma once


class Clab3_2View : public CScrollView
{
protected: // �������л�����
	Clab3_2View();
	DECLARE_DYNCREATE(Clab3_2View)

// ����
public:
	Clab3_2Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ������һ�ε���
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~Clab3_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBigger();
	afx_msg void OnSmaller();
	afx_msg void OnOrigin();
	int drawselect;
	afx_msg void OnPic1();
	afx_msg void OnPic2();
	// ѡ��ͼƬ
	int chooseBit;
};

#ifndef _DEBUG  // lab3_2View.cpp �еĵ��԰汾
inline Clab3_2Doc* Clab3_2View::GetDocument() const
   { return reinterpret_cast<Clab3_2Doc*>(m_pDocument); }
#endif

