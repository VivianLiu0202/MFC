
// Sample-0204View.cpp : CSample0204View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Sample-0204.h"
#endif

#include "Sample-0204Doc.h"
#include "Sample-0204View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSample0204View

IMPLEMENT_DYNCREATE(CSample0204View, CView)

BEGIN_MESSAGE_MAP(CSample0204View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSample0204View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CSample0204View ����/����

CSample0204View::CSample0204View()
	: m_Pos(0)
	, m_Str(_T(""))
{
	// TODO: �ڴ˴���ӹ������

}

CSample0204View::~CSample0204View()
{
}

BOOL CSample0204View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CSample0204View ����

void CSample0204View::OnDraw(CDC* pDC)
{
	CSample0204Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->TextOut(m_Pos.x,m_Pos.y,m_Str);
}


// CSample0204View ��ӡ


void CSample0204View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSample0204View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CSample0204View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CSample0204View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CSample0204View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSample0204View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSample0204View ���

#ifdef _DEBUG
void CSample0204View::AssertValid() const
{
	CView::AssertValid();
}

void CSample0204View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSample0204Doc* CSample0204View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSample0204Doc)));
	return (CSample0204Doc*)m_pDocument;
}
#endif //_DEBUG


// CSample0204View ��Ϣ�������


void CSample0204View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_Pos=point;
	if(nFlags & MK_CONTROL)
		m_Str="Mouse+Ctrl Clicked!";
	else
		m_Str="Mouse Clicked!";
	Invalidate(true);

	CView::OnLButtonDown(nFlags, point);
}
