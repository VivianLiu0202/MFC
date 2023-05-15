
// Sample-0208View.cpp : CSample0208View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Sample-0208.h"
#endif

#include "Sample-0208Doc.h"
#include "Sample-0208View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSample0208View

IMPLEMENT_DYNCREATE(CSample0208View, CView)

BEGIN_MESSAGE_MAP(CSample0208View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSample0208View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_HOTKEY()
	ON_WM_CREATE()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

// CSample0208View ����/����

CSample0208View::CSample0208View()
{
	// TODO: �ڴ˴���ӹ������

}

CSample0208View::~CSample0208View()
{
}

BOOL CSample0208View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CSample0208View ����

void CSample0208View::OnDraw(CDC* /*pDC*/)
{
	CSample0208Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CSample0208View ��ӡ


void CSample0208View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSample0208View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CSample0208View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CSample0208View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CSample0208View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSample0208View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSample0208View ���

#ifdef _DEBUG
void CSample0208View::AssertValid() const
{
	CView::AssertValid();
}

void CSample0208View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSample0208Doc* CSample0208View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSample0208Doc)));
	return (CSample0208Doc*)m_pDocument;
}
#endif //_DEBUG


// CSample0208View ��Ϣ�������


void CSample0208View::OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(nHotKeyId==1001||nHotKeyId==1002)
		MessageBox(L"Hot Key Clicked!");

	CView::OnHotKey(nHotKeyId, nKey1, nKey2);
}


int CSample0208View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	RegisterHotKey(m_hWnd,1001,MOD_CONTROL|MOD_ALT,'z');
	RegisterHotKey(m_hWnd,1002,MOD_CONTROL|MOD_ALT,'Z');

	return 0;
}


void CSample0208View::OnDestroy()
{
	CView::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	UnregisterHotKey(m_hWnd,1001);
	UnregisterHotKey(m_hWnd,1002);
}
