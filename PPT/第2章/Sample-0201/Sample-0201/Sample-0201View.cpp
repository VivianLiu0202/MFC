
// Sample-0201View.cpp : CSample0201View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Sample-0201.h"
#endif

#include "Sample-0201Doc.h"
#include "Sample-0201View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSample0201View

IMPLEMENT_DYNCREATE(CSample0201View, CView)

BEGIN_MESSAGE_MAP(CSample0201View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSample0201View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_EDIT_PASTE, &CSample0201View::OnEditPaste)
END_MESSAGE_MAP()

// CSample0201View ����/����

CSample0201View::CSample0201View()
{
	// TODO: �ڴ˴���ӹ������

}

CSample0201View::~CSample0201View()
{
}

BOOL CSample0201View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CSample0201View ����

void CSample0201View::OnDraw(CDC* pDC)
{
	CSample0201Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->TextOut(20,20,L"Windows Painted!");
	pDC->SelectStockObject(GRAY_BRUSH);
	pDC->Ellipse(20,50,100,130);
}


// CSample0201View ��ӡ


void CSample0201View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSample0201View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CSample0201View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CSample0201View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CSample0201View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSample0201View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSample0201View ���

#ifdef _DEBUG
void CSample0201View::AssertValid() const
{
	CView::AssertValid();
}

void CSample0201View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSample0201Doc* CSample0201View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSample0201Doc)));
	return (CSample0201Doc*)m_pDocument;
}
#endif //_DEBUG


// CSample0201View ��Ϣ�������


void CSample0201View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//CDC *pDC=GetDC();
	//pDC->TextOut(point.x,point.y,L"Mouse Clicked!");
	//ReleaseDC(pDC);
	//CClientDC DC(this);
	//DC.TextOut(point.x,point.y,L"Mouse Clicked!");

	CView::OnLButtonDown(nFlags, point);
}


void CSample0201View::OnEditPaste()
{
	// TODO: �ڴ���������������
	//CDC *pDC=GetDC();
	//pDC->TextOut(10,10,L"Menu Clicked!");
	//ReleaseDC(pDC);
}
