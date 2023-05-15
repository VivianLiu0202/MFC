
// lab1-2View.cpp : Clab12View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
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

// Clab12View 构造/析构

Clab12View::Clab12View()
{
	// TODO: 在此处添加构造代码
	x = 0;
	y = 0;
	movex = 10;
	movey = 10;
	d=30;//半径设置为15
	my_color = RGB(0,0,0);
	interval = 300;
	IsRun = false;
}

Clab12View::~Clab12View()
{
}

BOOL Clab12View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Clab12View 绘制

void Clab12View::OnDraw(CDC* pDC)
{
	Clab12Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	//1.设置提示小球的各种属性
	CString str1,str2;
	str1.Format(L"当前时钟周期就是：%d ms",interval);
	pDC->TextOutW(100,10,str1);

	//2.保证异或画笔绘制的正确性
	//1.得到填充小球的真实颜色
	BYTE r = GetRValue(my_color)^RGB(255,255,255);
	BYTE g = GetGValue(my_color)^RGB(255,255,255);
	BYTE b = GetBValue(my_color)^RGB(255,255,255);
	COLORREF my_color2=RGB(r,g,b);

	//2.声明画笔的属性
	CBrush brush;//画刷对象
	brush.CreateSolidBrush(my_color2);//填充颜色
	pDC->SelectObject(&brush);//画刷使用
	pDC->SetROP2(R2_XORPEN);//异或画笔设置
	pDC->Ellipse(x,y,x+d,y+d);//小球绘制

	str1.Format(L"当前时钟周期就是：%d ms",interval);
	pDC->TextOutW(100,10,str1);
}


// Clab12View 打印

BOOL Clab12View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Clab12View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Clab12View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// Clab12View 诊断

#ifdef _DEBUG
void Clab12View::AssertValid() const
{
	CView::AssertValid();
}

void Clab12View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Clab12Doc* Clab12View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Clab12Doc)));
	return (Clab12Doc*)m_pDocument;
}
#endif //_DEBUG


// Clab12View 消息处理程序


int Clab12View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	SetTimer(1,interval,NULL);
	IsRun = true;
	return 0;
}


void Clab12View::OnDestroy()
{
	CView::OnDestroy();
	KillTimer(1);

	// TODO: 在此处添加消息处理程序代码
}


void Clab12View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnTimer(nIDEvent);
	if(nIDEvent==1)
	{
		CRect rect;
		GetClientRect(&rect);
		CDC* pDC = GetDC();

		//1.得到填充小球的真实颜色
		BYTE r = GetRValue(my_color)^RGB(255,255,255);
		BYTE g = GetGValue(my_color)^RGB(255,255,255);
		BYTE b = GetBValue(my_color)^RGB(255,255,255);
		COLORREF my_color2=RGB(r,g,b);

		//2.声明画笔的属性
		CBrush brush;//画刷对象
		brush.CreateSolidBrush(my_color2);//填充颜色
		pDC->SelectObject(&brush);//画刷使用
		pDC->SetROP2(R2_XORPEN);//异或画笔设置
		pDC->Ellipse(x,y,x+d,y+d);//小球绘制

		//3.设置边界的判断
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
	// TODO: 在此添加命令处理程序代码
	if(interval>50)
	interval-=50;
	else MessageBox(L"已经很快了不能再快了！！");
	//KillTimer(1);
	SetTimer(1,interval,NULL);
	CDC *pDC = GetDC();
	/*
	*为了让小球在得到命令后所有属性及时得到更改，则需要重新绘制小球，填充其颜色
	*由于异或画笔的原因，传入的颜色数据会先做一次异或，在传入数据前异或一次保证异或画笔再次异或可以得到最初的颜色
	*/
	BYTE r = GetRValue(my_color)^RGB(255,255,255);
	BYTE g = GetGValue(my_color)^RGB(255,255,255);
	BYTE b = GetBValue(my_color)^RGB(255,255,255);
	COLORREF my_color2 =RGB(r,g,b);

	//声明画笔的属性
	CBrush brush;
	brush.CreateSolidBrush(my_color2);
	pDC->SelectObject(&brush);
	pDC->SetROP2(R2_XORPEN);
	pDC->Ellipse(x,y,x+d,y+d);//小球绘制
	Invalidate(true);//重绘视图，消去不必要的球的绘制
    ReleaseDC(pDC);
}


void Clab12View::OnBecomebig()
{
	// TODO: 在此添加命令处理程序代码
	if(d<60) d += 5;
	else MessageBox(L"本小球的尺寸已经达到最大！不要瞎点了！");
	CDC *pDC = GetDC();
	/*
	*为了让小球在得到命令后所有属性及时得到更改，则需要重新绘制小球，填充其颜色
	*由于异或画笔的原因，传入的颜色数据会先做一次异或，在传入数据前异或一次保证异或画笔再次异或可以得到最初的颜色
	*/
	BYTE r = GetRValue(my_color)^RGB(255,255,255);
	BYTE g = GetGValue(my_color)^RGB(255,255,255);
	BYTE b = GetBValue(my_color)^RGB(255,255,255);
	COLORREF my_color2 =RGB(r,g,b);

	//声明画笔的属性
	CBrush brush;
	brush.CreateSolidBrush(my_color2);
	pDC->SelectObject(&brush);
	pDC->SetROP2(R2_XORPEN);
	pDC->Ellipse(x,y,x+d,y+d);//小球绘制
	Invalidate(true);//重绘视图，消去不必要的球的绘制
    ReleaseDC(pDC);
}


void Clab12View::OnBecomedec()
{
	// TODO: 在此添加命令处理程序代码
	interval+=50;
	SetTimer(1,interval,NULL);
	CDC *pDC = GetDC();
	/*
	*为了让小球在得到命令后所有属性及时得到更改，则需要重新绘制小球，填充其颜色
	*由于异或画笔的原因，传入的颜色数据会先做一次异或，在传入数据前异或一次保证异或画笔再次异或可以得到最初的颜色
	*/
	BYTE r = GetRValue(my_color)^RGB(255,255,255);
	BYTE g = GetGValue(my_color)^RGB(255,255,255);
	BYTE b = GetBValue(my_color)^RGB(255,255,255);
	COLORREF my_color2 =RGB(r,g,b);

	//声明画笔的属性
	CBrush brush;
	brush.CreateSolidBrush(my_color2);
	pDC->SelectObject(&brush);
	pDC->SetROP2(R2_XORPEN);
	pDC->Ellipse(x,y,x+d,y+d);//小球绘制
	Invalidate(true);//重绘视图，消去不必要的球的绘制
    ReleaseDC(pDC);
}


void Clab12View::OnBecomesmall()
{
	// TODO: 在此添加命令处理程序代码
	if(d>5) d -= 5;
	else MessageBox(L"本大球的尺寸已经达到最小！不要瞎点了！");
	CDC *pDC = GetDC();
	/*
	*为了让小球在得到命令后所有属性及时得到更改，则需要重新绘制小球，填充其颜色
	*由于异或画笔的原因，传入的颜色数据会先做一次异或，在传入数据前异或一次保证异或画笔再次异或可以得到最初的颜色
	*/
	BYTE r = GetRValue(my_color)^RGB(255,255,255);
	BYTE g = GetGValue(my_color)^RGB(255,255,255);
	BYTE b = GetBValue(my_color)^RGB(255,255,255);
	COLORREF my_color2 =RGB(r,g,b);

	//声明画笔的属性
	CBrush brush;
	brush.CreateSolidBrush(my_color2);
	pDC->SelectObject(&brush);
	pDC->SetROP2(R2_XORPEN);
	pDC->Ellipse(x,y,x+d,y+d);//小球绘制
	Invalidate(true);//重绘视图，消去不必要的球的绘制
    ReleaseDC(pDC);
}


void Clab12View::OnColor()
{
	// TODO: 在此添加命令处理程序代码
	CColorDialog dlg(my_color);
	if(IDOK == dlg.DoModal())
	{
		//获取到的颜色保存到变量my_color中
		my_color = dlg.GetColor();
	}
	Invalidate(true);
}


void Clab12View::OnButtonbegin()
{
	// TODO: 在此添加命令处理程序代码
	if(!IsRun){
	SetTimer(1,interval,NULL);
	IsRun=true;
	}
}


void Clab12View::OnButtonend()
{
	// TODO: 在此添加命令处理程序代码
	if(IsRun){
	KillTimer(1);
	IsRun=false;
	}
}
