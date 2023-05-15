
// lab1-1View.cpp : Clab11View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "lab1-1.h"
#endif

#include "lab1-1Doc.h"
#include "lab1-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Clab11View

IMPLEMENT_DYNCREATE(Clab11View, CView)

BEGIN_MESSAGE_MAP(Clab11View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	//	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_CHAR()
	ON_MESSAGE(WM_MYMESSAGE, &Clab11View::OnMyMessage)
	ON_WM_CREATE()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

// Clab11View ����/����

Clab11View::Clab11View()
{
	// TODO: �ڴ˴���ӹ������
	p = 0;
}

Clab11View::~Clab11View()
{
}

BOOL Clab11View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Clab11View ����

void Clab11View::OnDraw(CDC* /*pDC*/)
{
	Clab11Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Clab11View ��ӡ

BOOL Clab11View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Clab11View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Clab11View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Clab11View ���

#ifdef _DEBUG
void Clab11View::AssertValid() const
{
	CView::AssertValid();
}

void Clab11View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Clab11Doc* Clab11View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Clab11Doc)));
	return (Clab11Doc*)m_pDocument;
}
#endif //_DEBUG


// Clab11View ��Ϣ�������


//void Clab11View::OnLButtonDblClk(UINT nFlags, CPoint point)
//{
//	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
//
//	CView::OnLButtonDblClk(nFlags, point);
//}


void Clab11View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString str1,str2;
	p = point;
	str1.Format(L"�����������꣨%d��%d��",p.x,p.y);
	str2.Format(L"������+Ctrl�������꣨%d��%d��",p.x,p.y);
	if(nFlags&MK_CONTROL){
		MessageBox(str2);
	}
	else MessageBox(str1);
	CView::OnLButtonDown(nFlags, point);
}


void Clab11View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString str;
	str.Format(L"%c��������������",nChar);
	CDC *pDC = GetDC();
	pDC->TextOutW(10,10,str);
	if(nChar == '#'){
		SendMessage(WM_MYMESSAGE,100,200);
	}
	CView::OnChar(nChar, nRepCnt, nFlags);
}


BOOL Clab11View::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	CDC * pDC = GetDC();
	if(pMsg->message == WM_KEYDOWN){
		if(pMsg->wParam==VK_UP) 
			pDC->TextOutW(100,100,L"UP��������!!");
		if(pMsg->wParam==VK_DOWN) 
			pDC->TextOutW(100,100,L"DOWN��������!!");
		if(pMsg->wParam==VK_LEFT)
			pDC->TextOutW(100,100,L"LEFT��������!!");
		if(pMsg->wParam==VK_RIGHT)
			pDC->TextOutW(100,100,L"RIGHT��������!!!");
		if(pMsg->wParam==VK_F1)
			pDC->TextOutW(100,100,L"F1��������!!");
		if(pMsg->wParam==VK_F2)
			pDC->TextOutW(100,100,L"F2��������!!");
		if(pMsg->wParam==VK_F3)
			pDC->TextOutW(100,100,L"F3��������!!");
		if(pMsg->wParam==VK_F4)
			pDC->TextOutW(100,100,L"F4��������!!");
		if(pMsg->wParam==VK_F5)
			pDC->TextOutW(100,100,L"F5��������!!");
		if(pMsg->wParam==VK_F6)
			pDC->TextOutW(100,100,L"F6��������!!");
	}
	return CView::PreTranslateMessage(pMsg);
}


LRESULT Clab11View::OnMyMessage(WPARAM wParam, LPARAM lParam)
{
	CString str;
	str.Format(L"QAQMessage Param is %d and %d",wParam,lParam);
	CDC *pDC = GetDC();
	pDC->TextOutW(200,200,str);
	return LRESULT();
}


int Clab11View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	MessageBox(L"Hello!!!!!���ȷ�Ͻ�����򣡲�Ȼ�ʹ����㣡");
	return 0;
}


void Clab11View::OnDestroy()
{
	CView::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	MessageBox(L"��������Ҫ�뿪�����������غ�����QAQ");
}
