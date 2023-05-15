
// Sample-0206View.cpp : CSample0206View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Sample-0206.h"
#endif

#include "Sample-0206Doc.h"
#include "Sample-0206View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSample0206View

IMPLEMENT_DYNCREATE(CSample0206View, CView)

BEGIN_MESSAGE_MAP(CSample0206View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSample0206View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_TEST_COLORDIALOG, &CSample0206View::OnTestColordialog)
	ON_COMMAND(ID_TEST_MESSAGEBOX, &CSample0206View::OnTestMessagebox)
END_MESSAGE_MAP()

// CSample0206View ����/����

CSample0206View::CSample0206View()
{
	// TODO: �ڴ˴���ӹ������

}

CSample0206View::~CSample0206View()
{
}

BOOL CSample0206View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CSample0206View ����

void CSample0206View::OnDraw(CDC* /*pDC*/)
{
	CSample0206Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CSample0206View ��ӡ


void CSample0206View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSample0206View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CSample0206View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CSample0206View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CSample0206View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSample0206View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSample0206View ���

#ifdef _DEBUG
void CSample0206View::AssertValid() const
{
	CView::AssertValid();
}

void CSample0206View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSample0206Doc* CSample0206View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSample0206Doc)));
	return (CSample0206Doc*)m_pDocument;
}
#endif //_DEBUG


// CSample0206View ��Ϣ�������


void CSample0206View::OnTestColordialog()
{
	// TODO: �ڴ���������������
	CColorDialog Dlg;
	Dlg.DoModal();
}


void CSample0206View::OnTestMessagebox()
{
	// TODO: �ڴ���������������
	MessageBox(L"MessageBox Clicked!");
}
