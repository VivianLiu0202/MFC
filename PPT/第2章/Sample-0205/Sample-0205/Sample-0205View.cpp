
// Sample-0205View.cpp : CSample0205View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Sample-0205.h"
#endif

#include "Sample-0205Doc.h"
#include "Sample-0205View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSample0205View

IMPLEMENT_DYNCREATE(CSample0205View, CView)

BEGIN_MESSAGE_MAP(CSample0205View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSample0205View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CSample0205View ����/����

CSample0205View::CSample0205View()
{
	// TODO: �ڴ˴���ӹ������

}

CSample0205View::~CSample0205View()
{
}

BOOL CSample0205View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CSample0205View ����

void CSample0205View::OnDraw(CDC* /*pDC*/)
{
	CSample0205Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CSample0205View ��ӡ


void CSample0205View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSample0205View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CSample0205View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CSample0205View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CSample0205View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSample0205View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSample0205View ���

#ifdef _DEBUG
void CSample0205View::AssertValid() const
{
	CView::AssertValid();
}

void CSample0205View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSample0205Doc* CSample0205View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSample0205Doc)));
	return (CSample0205Doc*)m_pDocument;
}
#endif //_DEBUG


// CSample0205View ��Ϣ�������


void CSample0205View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString str;
	str.Format(L"%c Key Entered!",nChar);
	MessageBox(str);

	CView::OnChar(nChar, nRepCnt, nFlags);
}

BOOL CSample0205View::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if(pMsg->message==WM_KEYDOWN)
	{
		if(pMsg->wParam==VK_F1) 
			MessageBox(L"F1 Key Entered!");
		if(pMsg->wParam==VK_UP) 
			MessageBox(L"�� Key Entered!");
	}

	return CView::PreTranslateMessage(pMsg);
}
