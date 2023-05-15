
// lab1-2View.cpp : Clab12View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "lab1-2.h"
#endif

#include "lab1-2Doc.h"
#include "lab1-2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Clab12View

IMPLEMENT_DYNCREATE(Clab12View, CView)

BEGIN_MESSAGE_MAP(Clab12View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_TIMER()
	ON_COMMAND(ID_BECOMEACC, &Clab12View::OnBecomeacc)
	ON_COMMAND(ID_BECOMEBIG, &Clab12View::OnBecomebig)
	ON_COMMAND(ID_BECOMEDEC, &Clab12View::OnBecomedec)
	ON_COMMAND(ID_BECOMESMALL, &Clab12View::OnBecomesmall)
	ON_COMMAND(ID_COLOR, &Clab12View::OnColor)
	ON_COMMAND(ID_BUTTONBEGIN, &Clab12View::OnButtonbegin)
	ON_COMMAND(ID_BUTTONEND, &Clab12View::OnButtonend)
END_MESSAGE_MAP()

// Clab12View ����/����

Clab12View::Clab12View()
{
	// TODO: �ڴ˴���ӹ������
	x = 0;
	y = 0;
	movex = 10;
	movey = 10;
	d=30;//�뾶����Ϊ15
	my_color = RGB(0,0,0);
	interval = 300;
	IsRun = false;
}

Clab12View::~Clab12View()
{
}

BOOL Clab12View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Clab12View ����

void Clab12View::OnDraw(CDC* pDC)
{
	Clab12Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	//1.������ʾС��ĸ�������
	CString str1,str2;
	str1.Format(L"��ǰʱ�����ھ��ǣ�%d ms",interval);
	pDC->TextOutW(100,10,str1);

	//2.��֤��򻭱ʻ��Ƶ���ȷ��
	//1.�õ����С�����ʵ��ɫ
	BYTE r = GetRValue(my_color)^RGB(255,255,255);
	BYTE g = GetGValue(my_color)^RGB(255,255,255);
	BYTE b = GetBValue(my_color)^RGB(255,255,255);
	COLORREF my_color2=RGB(r,g,b);

	//2.�������ʵ�����
	CBrush brush;//��ˢ����
	brush.CreateSolidBrush(my_color2);//�����ɫ
	pDC->SelectObject(&brush);//��ˢʹ��
	pDC->SetROP2(R2_XORPEN);//��򻭱�����
	pDC->Ellipse(x,y,x+d,y+d);//С�����

	str1.Format(L"��ǰʱ�����ھ��ǣ�%d ms",interval);
	pDC->TextOutW(100,10,str1);
}


// Clab12View ��ӡ

BOOL Clab12View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Clab12View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Clab12View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Clab12View ���

#ifdef _DEBUG
void Clab12View::AssertValid() const
{
	CView::AssertValid();
}

void Clab12View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Clab12Doc* Clab12View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Clab12Doc)));
	return (Clab12Doc*)m_pDocument;
}
#endif //_DEBUG


// Clab12View ��Ϣ�������


int Clab12View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	SetTimer(1,interval,NULL);
	IsRun = true;
	return 0;
}


void Clab12View::OnDestroy()
{
	CView::OnDestroy();
	KillTimer(1);

	// TODO: �ڴ˴������Ϣ����������
}


void Clab12View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CView::OnTimer(nIDEvent);
	if(nIDEvent==1)
	{
		CRect rect;
		GetClientRect(&rect);
		CDC* pDC = GetDC();

		//1.�õ����С�����ʵ��ɫ
		BYTE r = GetRValue(my_color)^RGB(255,255,255);
		BYTE g = GetGValue(my_color)^RGB(255,255,255);
		BYTE b = GetBValue(my_color)^RGB(255,255,255);
		COLORREF my_color2=RGB(r,g,b);

		//2.�������ʵ�����
		CBrush brush;//��ˢ����
		brush.CreateSolidBrush(my_color2);//�����ɫ
		pDC->SelectObject(&brush);//��ˢʹ��
		pDC->SetROP2(R2_XORPEN);//��򻭱�����
		pDC->Ellipse(x,y,x+d,y+d);//С�����

		//3.���ñ߽���ж�
		x+=movex;
		y+=movey;
		if(y<0 || y>rect.bottom-d)
			movey=0-movey;
		if(x<0 || x>rect.right-d)
			movex=0-movex;
		pDC->Ellipse(x,y,x+d,y+d);
	}
	CView::OnTimer(nIDEvent);
}


void Clab12View::OnBecomeacc()
{
	// TODO: �ڴ���������������
	if(interval>50)
	interval-=50;
	else MessageBox(L"�Ѿ��ܿ��˲����ٿ��ˣ���");
	//KillTimer(1);
	SetTimer(1,interval,NULL);
	CDC *pDC = GetDC();
	/*
	*Ϊ����С���ڵõ�������������Լ�ʱ�õ����ģ�����Ҫ���»���С���������ɫ
	*������򻭱ʵ�ԭ�򣬴������ɫ���ݻ�����һ������ڴ�������ǰ���һ�α�֤��򻭱��ٴ������Եõ��������ɫ
	*/
	BYTE r = GetRValue(my_color)^RGB(255,255,255);
	BYTE g = GetGValue(my_color)^RGB(255,255,255);
	BYTE b = GetBValue(my_color)^RGB(255,255,255);
	COLORREF my_color2 =RGB(r,g,b);

	//�������ʵ�����
	CBrush brush;
	brush.CreateSolidBrush(my_color2);
	pDC->SelectObject(&brush);
	pDC->SetROP2(R2_XORPEN);
	pDC->Ellipse(x,y,x+d,y+d);//С�����
	Invalidate(true);//�ػ���ͼ����ȥ����Ҫ����Ļ���
    ReleaseDC(pDC);
}


void Clab12View::OnBecomebig()
{
	// TODO: �ڴ���������������
	if(d<60) d += 5;
	else MessageBox(L"��С��ĳߴ��Ѿ��ﵽ��󣡲�ҪϹ���ˣ�");
	CDC *pDC = GetDC();
	/*
	*Ϊ����С���ڵõ�������������Լ�ʱ�õ����ģ�����Ҫ���»���С���������ɫ
	*������򻭱ʵ�ԭ�򣬴������ɫ���ݻ�����һ������ڴ�������ǰ���һ�α�֤��򻭱��ٴ������Եõ��������ɫ
	*/
	BYTE r = GetRValue(my_color)^RGB(255,255,255);
	BYTE g = GetGValue(my_color)^RGB(255,255,255);
	BYTE b = GetBValue(my_color)^RGB(255,255,255);
	COLORREF my_color2 =RGB(r,g,b);

	//�������ʵ�����
	CBrush brush;
	brush.CreateSolidBrush(my_color2);
	pDC->SelectObject(&brush);
	pDC->SetROP2(R2_XORPEN);
	pDC->Ellipse(x,y,x+d,y+d);//С�����
	Invalidate(true);//�ػ���ͼ����ȥ����Ҫ����Ļ���
    ReleaseDC(pDC);
}


void Clab12View::OnBecomedec()
{
	// TODO: �ڴ���������������
	interval+=50;
	SetTimer(1,interval,NULL);
	CDC *pDC = GetDC();
	/*
	*Ϊ����С���ڵõ�������������Լ�ʱ�õ����ģ�����Ҫ���»���С���������ɫ
	*������򻭱ʵ�ԭ�򣬴������ɫ���ݻ�����һ������ڴ�������ǰ���һ�α�֤��򻭱��ٴ������Եõ��������ɫ
	*/
	BYTE r = GetRValue(my_color)^RGB(255,255,255);
	BYTE g = GetGValue(my_color)^RGB(255,255,255);
	BYTE b = GetBValue(my_color)^RGB(255,255,255);
	COLORREF my_color2 =RGB(r,g,b);

	//�������ʵ�����
	CBrush brush;
	brush.CreateSolidBrush(my_color2);
	pDC->SelectObject(&brush);
	pDC->SetROP2(R2_XORPEN);
	pDC->Ellipse(x,y,x+d,y+d);//С�����
	Invalidate(true);//�ػ���ͼ����ȥ����Ҫ����Ļ���
    ReleaseDC(pDC);
}


void Clab12View::OnBecomesmall()
{
	// TODO: �ڴ���������������
	if(d>5) d -= 5;
	else MessageBox(L"������ĳߴ��Ѿ��ﵽ��С����ҪϹ���ˣ�");
	CDC *pDC = GetDC();
	/*
	*Ϊ����С���ڵõ�������������Լ�ʱ�õ����ģ�����Ҫ���»���С���������ɫ
	*������򻭱ʵ�ԭ�򣬴������ɫ���ݻ�����һ������ڴ�������ǰ���һ�α�֤��򻭱��ٴ������Եõ��������ɫ
	*/
	BYTE r = GetRValue(my_color)^RGB(255,255,255);
	BYTE g = GetGValue(my_color)^RGB(255,255,255);
	BYTE b = GetBValue(my_color)^RGB(255,255,255);
	COLORREF my_color2 =RGB(r,g,b);

	//�������ʵ�����
	CBrush brush;
	brush.CreateSolidBrush(my_color2);
	pDC->SelectObject(&brush);
	pDC->SetROP2(R2_XORPEN);
	pDC->Ellipse(x,y,x+d,y+d);//С�����
	Invalidate(true);//�ػ���ͼ����ȥ����Ҫ����Ļ���
    ReleaseDC(pDC);
}


void Clab12View::OnColor()
{
	// TODO: �ڴ���������������
	CColorDialog dlg(my_color);
	if(IDOK == dlg.DoModal())
	{
		//��ȡ������ɫ���浽����my_color��
		my_color = dlg.GetColor();
	}
	Invalidate(true);
}


void Clab12View::OnButtonbegin()
{
	// TODO: �ڴ���������������
	if(!IsRun){
	SetTimer(1,interval,NULL);
	IsRun=true;
	}
}


void Clab12View::OnButtonend()
{
	// TODO: �ڴ���������������
	if(IsRun){
	KillTimer(1);
	IsRun=false;
	}
}
