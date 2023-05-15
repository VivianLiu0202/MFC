
// lab3_2View.cpp : Clab3_2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "lab3_2.h"
#endif

#include "lab3_2Doc.h"
#include "lab3_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Clab3_2View

IMPLEMENT_DYNCREATE(Clab3_2View, CScrollView)

BEGIN_MESSAGE_MAP(Clab3_2View, CScrollView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_COMMAND(ID_BIGGER, &Clab3_2View::OnBigger)
	ON_COMMAND(ID_SMALLER, &Clab3_2View::OnSmaller)
	ON_COMMAND(ID_ORIGIN, &Clab3_2View::OnOrigin)
	ON_COMMAND(ID_PIC1, &Clab3_2View::OnPic1)
	ON_COMMAND(ID_PIC2, &Clab3_2View::OnPic2)
END_MESSAGE_MAP()

// Clab3_2View ����/����

Clab3_2View::Clab3_2View()
	: chooseBit(1)
{
	// TODO: �ڴ˴���ӹ������

}

Clab3_2View::~Clab3_2View()
{
}

BOOL Clab3_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CScrollView::PreCreateWindow(cs);
}

// Clab3_2View ����

void Clab3_2View::OnDraw(CDC* pDC)
{
	Clab3_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CBitmap bm; 
	if(chooseBit==1) bm.LoadBitmap(IDB_BITMAP1);
	if(chooseBit==2) bm.LoadBitmap(IDB_BITMAP2);
	CDC memDC; 
	memDC.CreateCompatibleDC(pDC);
	memDC.SelectObject(&bm);
	BITMAP info; bm.GetBitmap(&info);

	if(drawselect==1)//ԭͼ
	{
		pDC->StretchBlt(0,0,info.bmWidth, 
		info.bmHeight,&memDC,0,0,info.bmWidth, 
		info.bmHeight,SRCCOPY);
		bm.DeleteObject();
	}
	if(drawselect==2)//�Ŵ��ı�
	{
		pDC->StretchBlt(0,0,info.bmWidth*2, 
		info.bmHeight*2,&memDC,0,0,info.bmWidth, 
		info.bmHeight,SRCCOPY);
		bm.DeleteObject();
	}
	if(drawselect==3)//��С�ı�
	{
		pDC->StretchBlt(0,0,info.bmWidth/2, 
		info.bmHeight/2,&memDC,0,0,info.bmWidth, 
		info.bmHeight,SRCCOPY);
		bm.DeleteObject();
	}
}

void Clab3_2View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: �������ͼ�ĺϼƴ�С
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// Clab3_2View ��ӡ

BOOL Clab3_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Clab3_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Clab3_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Clab3_2View ���

#ifdef _DEBUG
void Clab3_2View::AssertValid() const
{
	CScrollView::AssertValid();
}

void Clab3_2View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

Clab3_2Doc* Clab3_2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Clab3_2Doc)));
	return (Clab3_2Doc*)m_pDocument;
}
#endif //_DEBUG


// Clab3_2View ��Ϣ�������


void Clab3_2View::OnBigger()
{
	// TODO: �ڴ���������������
	drawselect=2;
	Invalidate();
}


void Clab3_2View::OnSmaller()
{
	// TODO: �ڴ���������������
	drawselect=3;
	Invalidate();
}


void Clab3_2View::OnOrigin()
{
	// TODO: �ڴ���������������
	drawselect=1;
	Invalidate();
}


void Clab3_2View::OnPic1()
{
	// TODO: �ڴ���������������
	chooseBit=1;
}


void Clab3_2View::OnPic2()
{
	// TODO: �ڴ���������������
	chooseBit=2;
}
