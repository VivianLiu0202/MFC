
// Sample-0202View.cpp : CSample0202View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Sample-0202.h"
#endif

#include "Sample-0202Doc.h"
#include "Sample-0202View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSample0202View

IMPLEMENT_DYNCREATE(CSample0202View, CView)

BEGIN_MESSAGE_MAP(CSample0202View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSample0202View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CSample0202View ����/����

CSample0202View::CSample0202View()
{
	// TODO: �ڴ˴���ӹ������

}

CSample0202View::~CSample0202View()
{
}

BOOL CSample0202View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CSample0202View ����

void CSample0202View::OnDraw(CDC* pDC)
{
	CSample0202Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	int nTotalPoints=32000;
	CRect rect;
	GetClientRect(&rect);
	int nX=rect.right/2;
	int nY=rect.bottom*5/6;
	int nScale=(rect.right>rect.bottom?rect.bottom:rect.right)/15;
	COLORREF crColor=0x00FF00;
	double dX=0, dY=0;
	double dP; 
	for(int i=0;i<nTotalPoints;i++)
	{		
		dP=1.0*rand()/RAND_MAX;
		if(dP<=0.01)
		{
			dX=0;
			dY=0.16*dY;
		}
		if(dP>0.01 && dP<=0.86)   
		{
			dX=0.85*dX+0.04*dY;
			dY=-0.04*dX+0.85*dY+1.60;
		}
		if(dP>0.86 && dP<=0.93)    
		{
			dX=0.20*dX-0.26*dY;
			dY=0.44*dX+0.12*dY+1.60;
		}
		if(dP>0.93)                  
		{
			dX=-0.20*dX+0.26*dY;
			dY=0.44*dX+0.12*dY+1.00;
		}
		pDC->SetPixel(nX+int(dX*nScale),nY-int(dY*nScale),crColor);
	}
}


// CSample0202View ��ӡ


void CSample0202View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSample0202View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CSample0202View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CSample0202View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CSample0202View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSample0202View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSample0202View ���

#ifdef _DEBUG
void CSample0202View::AssertValid() const
{
	CView::AssertValid();
}

void CSample0202View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSample0202Doc* CSample0202View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSample0202Doc)));
	return (CSample0202Doc*)m_pDocument;
}
#endif //_DEBUG


// CSample0202View ��Ϣ�������
