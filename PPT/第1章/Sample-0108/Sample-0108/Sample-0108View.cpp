
// Sample-0108View.cpp : CSample0108View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Sample-0108.h"
#endif

#include "Sample-0108Doc.h"
#include "Sample-0108View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSample0108View

IMPLEMENT_DYNCREATE(CSample0108View, CView)

BEGIN_MESSAGE_MAP(CSample0108View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSample0108View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CSample0108View ����/����

CSample0108View::CSample0108View()
{
	// TODO: �ڴ˴���ӹ������

}

CSample0108View::~CSample0108View()
{
}

BOOL CSample0108View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CSample0108View ����

void CSample0108View::OnDraw(CDC* pDC)
{
	CSample0108Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CRect rect;
	GetClientRect(&rect);
	pDC->PatBlt(0,0,rect.right,rect.bottom,BLACKNESS);
}


// CSample0108View ��ӡ


void CSample0108View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSample0108View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CSample0108View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CSample0108View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CSample0108View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSample0108View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSample0108View ���

#ifdef _DEBUG
void CSample0108View::AssertValid() const
{
	CView::AssertValid();
}

void CSample0108View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSample0108Doc* CSample0108View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSample0108Doc)));
	return (CSample0108Doc*)m_pDocument;
}
#endif //_DEBUG


// CSample0108View ��Ϣ�������


void CSample0108View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CDC* pDC=GetDC();
	MessageBox(L"Mouse Clicked!",L"Message 1",MB_OK);
	pDC->TextOut(0,0,L"Mouse Clicked!");
	CView::OnLButtonDown(nFlags, point);
}
