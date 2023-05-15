
// Sample-0207View.cpp : CSample0207View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Sample-0207.h"
#endif

#include "Sample-0207Doc.h"
#include "Sample-0207View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSample0207View

IMPLEMENT_DYNCREATE(CSample0207View, CView)

BEGIN_MESSAGE_MAP(CSample0207View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSample0207View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CSample0207View ����/����

CSample0207View::CSample0207View()
	: x(0)
	, y(0)
	, movex(0)
	, movey(0)
{
	// TODO: �ڴ˴���ӹ������
	movex=movey=5;
}

CSample0207View::~CSample0207View()
{
}

BOOL CSample0207View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CSample0207View ����

void CSample0207View::OnDraw(CDC* pDC)
{
	CSample0207Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->SetROP2(R2_XORPEN);
	pDC->Ellipse(x,y,x+15,y+15);
}


// CSample0207View ��ӡ


void CSample0207View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSample0207View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CSample0207View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CSample0207View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CSample0207View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSample0207View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSample0207View ���

#ifdef _DEBUG
void CSample0207View::AssertValid() const
{
	CView::AssertValid();
}

void CSample0207View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSample0207Doc* CSample0207View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSample0207Doc)));
	return (CSample0207Doc*)m_pDocument;
}
#endif //_DEBUG


// CSample0207View ��Ϣ�������


int CSample0207View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	SetTimer(1,20,NULL);
	return 0;
}


void CSample0207View::OnDestroy()
{
	CView::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	KillTimer(1);
}


void CSample0207View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(nIDEvent==1)
	{
		CRect rect;
		GetClientRect(&rect);
		CDC* pDC=GetDC();
		pDC->SetROP2(R2_XORPEN);
		pDC->Ellipse(x,y,x+15,y+15);
		x+=movex;
		y+=movey;
		if(x<0||x>rect.right-15)
			movex=0-movex;
		if(y<0||y>rect.bottom-15)
			movey=0-movey;
		pDC->Ellipse(x,y,x+15,y+15);
	}
	CView::OnTimer(nIDEvent);
}
