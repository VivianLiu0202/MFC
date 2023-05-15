
// lab3_1View.cpp : Clab3_1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "lab3_1.h"
#endif

#include "lab3_1Doc.h"
#include "lab3_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Clab3_1View

IMPLEMENT_DYNCREATE(Clab3_1View, CView)

BEGIN_MESSAGE_MAP(Clab3_1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	ON_COMMAND(ID_DRAWLINE, &Clab3_1View::OnDrawline)
	ON_COMMAND(ID_DRAWP, &Clab3_1View::OnDrawp)
	ON_COMMAND(ID_DRAWRECT, &Clab3_1View::OnDrawrect)
END_MESSAGE_MAP()

// Clab3_1View ����/����

Clab3_1View::Clab3_1View()
{
	// TODO: �ڴ˴���ӹ������
	moveLoop=false;
	drawSelect = 0;//1��2��3�ֱ��ʾ����ѡ�������ͼ��
	//�߳����ٶȽ�������
	x1=200;
	y1=200;
	movex1=10;
	movey1=10;
	x2=200;
	y2=200;
	movex2=10;
	movey2=0;
	x3=300;
	y3=200;
	movex3=0;
	movey3=0;

	/*
	������ͼ�εĶ���������ж�λ���Ա��ں���bitmapͼ���ƶ�
	*/
	point3[0].x=300;
	point3[0].y=200;
	point3[1].x=200;
	point3[1].y=300;
	point3[2].x=200;
	point3[2].y=400;
	point3[3].x=300;
	point3[3].y=500;
	point3[4].x=400;
	point3[4].y=400;
	point3[5].x=400;
	point3[5].y=300;

	point2[0].x=200;
	point2[0].y=200;
	point2[1].x=400;
	point2[1].y=400;

	point1[0].x=200;
	point1[0].y=200;
	point1[1].x=400;
	point1[1].y=400;

}

Clab3_1View::~Clab3_1View()
{
}

BOOL Clab3_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Clab3_1View ����

void Clab3_1View::OnDraw(CDC* /*pDC*/)
{
	Clab3_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Clab3_1View ��ӡ

BOOL Clab3_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Clab3_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Clab3_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Clab3_1View ���

#ifdef _DEBUG
void Clab3_1View::AssertValid() const
{
	CView::AssertValid();
}

void Clab3_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Clab3_1Doc* Clab3_1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Clab3_1Doc)));
	return (Clab3_1Doc*)m_pDocument;
}
#endif //_DEBUG


// Clab3_1View ��Ϣ�������


void Clab3_1View::OnContextMenu(CWnd* /*pWnd*/, CPoint point)
{
	// TODO: �ڴ˴������Ϣ����������
	CMenu menu; //����һ��menu����
	menu.LoadMenu(IDR_POPUPMENU); //���������Զ���Ĳ˵���
	CMenu* pMenu=menu.GetSubMenu(0); //����ָ���𼶻�ȡ��һ�������ò���
	pMenu->TrackPopupMenu(TPM_LEFTALIGN, point.x,point.y,this); //�����˵�

}


int Clab3_1View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	SetTimer(1,200,NULL);
	return 0;
}


void Clab3_1View::OnDestroy()
{
	CView::OnDestroy();
	KillTimer(1);
	// TODO: �ڴ˴������Ϣ����������
}


void Clab3_1View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//����V�����������ִ�Сд����ʼѭ������
	if(nChar=='v'||nChar=='V'){
		moveLoop=true;
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void Clab3_1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//��������������ʱ������꣬���������Ķ�λ
	CString str;
	str.Format(L"��ǰ����Ϊ��%d,%d��",point.x,point.y);
	MessageBox(str);
	CView::OnLButtonDown(nFlags, point);
}


void Clab3_1View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CBitmap bm;
	bm.LoadBitmap(IDB_BITMAP1);
	CBrush brush1;
	brush1.CreatePatternBrush(&bm);
	
	CDC *pDC=GetDC();
	pDC->SelectObject(brush1);

	//��ʱ����������
	if(nIDEvent==1)
	{
		if(moveLoop)
		{
			//��������ͼ�εı߽綥������жϣ�����λͼ���ƶ�
			if(drawSelect==1)
			{
				if(x1<200 || x1>400){
					movex1=-movex1;}
				if(y1<200 || y1>400){
					movey1=-movey1;}
				pDC->PatBlt(x1,y1,8,8,PATCOPY);
				pDC->PatBlt(x1-movex1,y1-movey1,8,8,WHITENESS);
				if(x1!=200&&x1!=190&&x1!=400&&x1!=410){//�߽��ж�
				pDC->MoveTo(x1-movex1,x1-movey1);
				pDC->LineTo(x1-movex1+8,x1-movey1+8);
				}
				x1+=movex1;
				y1+=movey1;
			}
			if(drawSelect==2)
			{
				pDC->PatBlt(x2-8,y2-8,8,8,PATCOPY);
				pDC->PatBlt(x2-movex2-8,y2-movey2-8,8,8,WHITENESS);
				if(y2==200){
					movex2=10;
					movey2=0;
					x2+=movex2;
				}
				if(x2==410){
					movex2=0;
					movey2=10;
					y2+=10;
					pDC->PatBlt(400-8,200-8,8,8,WHITENESS);
				}
				if(y2==410){
					movex2=-10;
					movey2=0;
					x2+=movex2;
					pDC->PatBlt(402,392,8,8,WHITENESS);
				}
				if(x2==200){
					movey2=-10;
					movex2=0;
					y2+=movey2;
					pDC->PatBlt(202,402,8,8,WHITENESS);
				}
			}
			if(drawSelect==3)
			{
				pDC->PatBlt(x3+10,y3-10,8,8,PATCOPY);
				pDC->PatBlt(x3-movex3+10,y3-movey3-10,8,8,WHITENESS);
				if(x3==300&&y3==200){
					movex3=10;
					movey3=10;
					pDC->PatBlt(310,150,8,8,WHITENESS);
					pDC->MoveTo(300,200);
					pDC->LineTo(308,208);
				}
				if(x3==400&&y3==300)
				{
					movex3=0;
					movey3=10;
				}
				if(x3==400&&y3==410)
				{
					movex3=-10;
					movey3=10;
				}
				if(x3==280&&y3==530)
				{
					movex3=-10;
					movey3=-10;
				}
				if(x3==180&&y3==430)
				{
					movex3=0;
					movey3=-10;
				}
				if(x3==180&&y3==280)
				{
					movex3=+10;
					movey3=-10;
				}
				if(x3==300&&y3==160)
				{
					x3=290;
					y3=210;	
				}
				x3+=movex3;
				y3+=movey3;
			}
		}
	}

	CView::OnTimer(nIDEvent);
}


void Clab3_1View::OnDrawline()
{
	// TODO: �ڴ���������������
	drawSelect=1;
	//������б45���ֱ��
	CBitmap bm;
	CDC *pDC=GetDC();
	pDC->PatBlt(0,0,1000,1000,WHITENESS);
	pDC->MoveTo(point1[0].x,point1[0].y);
	pDC->LineTo(point1[1].x,point1[1].y);
}


void Clab3_1View::OnDrawp()
{
	// TODO: �ڴ���������������
	//���ƶ����
	drawSelect=3;
	CBitmap bm;
	CDC *pDC=GetDC();
	pDC->PatBlt(0,0,1000,1000,WHITENESS);
	pDC->Polygon(point3,6);
}


void Clab3_1View::OnDrawrect()
{
	// TODO: �ڴ���������������
	//���ƾ���
	drawSelect=2;
	CBitmap bm;
	CDC *pDC=GetDC();
	pDC->PatBlt(0,0,1000,1000,WHITENESS);
	pDC->Rectangle(point2[0].x,point2[0].y,point2[1].x,point2[1].y);
}
