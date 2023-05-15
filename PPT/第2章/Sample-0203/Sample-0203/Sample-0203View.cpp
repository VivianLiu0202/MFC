
// Sample-0203View.cpp : CSample0203View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Sample-0203.h"
#endif

#include "Sample-0203Doc.h"
#include "Sample-0203View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSample0203View

IMPLEMENT_DYNCREATE(CSample0203View, CView)

BEGIN_MESSAGE_MAP(CSample0203View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSample0203View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CREATE()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

// CSample0203View ����/����

CSample0203View::CSample0203View()
	: m_Num(0)
{
	// TODO: �ڴ˴���ӹ������
}

CSample0203View::~CSample0203View()
{
}

BOOL CSample0203View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CSample0203View ����

void CSample0203View::OnDraw(CDC* pDC)
{
	CSample0203Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CString str;
	str.Format(L"Window %dth Painted!",m_Num++);
	pDC->TextOut(10,10,str);
}


// CSample0203View ��ӡ


void CSample0203View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSample0203View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CSample0203View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CSample0203View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CSample0203View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSample0203View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSample0203View ���

#ifdef _DEBUG
void CSample0203View::AssertValid() const
{
	CView::AssertValid();
}

void CSample0203View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSample0203Doc* CSample0203View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSample0203Doc)));
	return (CSample0203Doc*)m_pDocument;
}
#endif //_DEBUG


// CSample0203View ��Ϣ�������


int CSample0203View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	//MessageBox(L"Windows Created!");

	return 0;
}


void CSample0203View::OnDestroy()
{
	CView::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	//MessageBox(L"Windows Destroyed!");

}
