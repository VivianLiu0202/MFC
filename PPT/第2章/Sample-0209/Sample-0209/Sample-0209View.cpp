
// Sample-0209View.cpp : CSample0209View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Sample-0209.h"
#endif

#include "Sample-0209Doc.h"
#include "Sample-0209View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSample0209View

IMPLEMENT_DYNCREATE(CSample0209View, CView)

BEGIN_MESSAGE_MAP(CSample0209View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSample0209View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_MESSAGE(WM_MYMESSAGE,OnMyMessage)
	ON_WM_LBUTTONDOWN()
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CSample0209View ����/����

CSample0209View::CSample0209View()
{
	// TODO: �ڴ˴���ӹ������

}

CSample0209View::~CSample0209View()
{
}

BOOL CSample0209View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CSample0209View ����

void CSample0209View::OnDraw(CDC* /*pDC*/)
{
	CSample0209Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CSample0209View ��ӡ


void CSample0209View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSample0209View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CSample0209View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CSample0209View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CSample0209View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSample0209View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSample0209View ���

#ifdef _DEBUG
void CSample0209View::AssertValid() const
{
	CView::AssertValid();
}

void CSample0209View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSample0209Doc* CSample0209View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSample0209Doc)));
	return (CSample0209Doc*)m_pDocument;
}
#endif //_DEBUG


// CSample0209View ��Ϣ�������


LRESULT CSample0209View::OnMyMessage(WPARAM wParam, LPARAM lParam)
{
	CString str;
	str.Format(L"Message Param is %d and %d", wParam,lParam);
	MessageBox(str);

	return 0;
}


void CSample0209View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	PostMessage(WM_MYMESSAGE,1,2);

	CView::OnLButtonDown(nFlags, point);
}


void CSample0209View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	SendMessage(WM_MYMESSAGE,3,4);

	CView::OnChar(nChar, nRepCnt, nFlags);
}
