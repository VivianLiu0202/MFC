
// Sample-0210View.cpp : CSample0210View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Sample-0210.h"
#endif

#include "Sample-0210Doc.h"
#include "Sample-0210View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSample0210View

IMPLEMENT_DYNCREATE(CSample0210View, CView)

BEGIN_MESSAGE_MAP(CSample0210View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSample0210View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CSample0210View ����/����

CSample0210View::CSample0210View()
{
	// TODO: �ڴ˴���ӹ������

}

CSample0210View::~CSample0210View()
{
}

BOOL CSample0210View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CSample0210View ����

void CSample0210View::OnDraw(CDC* pDC)
{
	CSample0210Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	m_pDC=pDC;
    CRect rect;
	GetClientRect(&rect);
    int iOx=rect.right/2;
	int iOy=rect.bottom/2; 
    DrawRect(iOx,iOy,(iOx>iOy?iOy:iOx)/3);
}


// CSample0210View ��ӡ


void CSample0210View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSample0210View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CSample0210View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CSample0210View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CSample0210View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSample0210View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSample0210View ���

#ifdef _DEBUG
void CSample0210View::AssertValid() const
{
	CView::AssertValid();
}

void CSample0210View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSample0210Doc* CSample0210View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSample0210Doc)));
	return (CSample0210Doc*)m_pDocument;
}
#endif //_DEBUG


// CSample0210View ��Ϣ�������


void CSample0210View::DrawRect(int iX, int iY, int iR)
{
	if(iR>0)
    {
        DrawRect(iX-iR,iY+iR,iR/2);
		DrawRect(iX+iR,iY+iR,iR/2);
        DrawRect(iX-iR,iY-iR,iR/2);
		DrawRect(iX+iR,iY-iR,iR/2);
        m_pDC->Rectangle(iX-iR,iY-iR,iX+iR,iY+iR);
    }
}
