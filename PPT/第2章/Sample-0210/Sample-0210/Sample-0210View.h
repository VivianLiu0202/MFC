
// Sample-0210View.h : CSample0210View ��Ľӿ�
//

#pragma once


class CSample0210View : public CView
{
protected: // �������л�����
	CSample0210View();
	DECLARE_DYNCREATE(CSample0210View)

// ����
public:
	CSample0210Doc* GetDocument() const;

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
	virtual ~CSample0210View();
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
private:
	CDC* m_pDC;
public:
	void DrawRect(int iX, int iY, int iR);
};

#ifndef _DEBUG  // Sample-0210View.cpp �еĵ��԰汾
inline CSample0210Doc* CSample0210View::GetDocument() const
   { return reinterpret_cast<CSample0210Doc*>(m_pDocument); }
#endif

