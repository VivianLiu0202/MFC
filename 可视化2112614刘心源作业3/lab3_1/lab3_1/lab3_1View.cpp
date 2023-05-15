
// lab3_1View.cpp : Clab3_1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
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

// Clab3_1View 构造/析构

Clab3_1View::Clab3_1View()
{
	// TODO: 在此处添加构造代码
	moveLoop=false;
	drawSelect = 0;//1，2，3分别表示可以选择的三种图形
	//边长和速度进行设置
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
	给三种图形的顶点坐标进行定位，以便于后面bitmap图的移动
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
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Clab3_1View 绘制

void Clab3_1View::OnDraw(CDC* /*pDC*/)
{
	Clab3_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Clab3_1View 打印

BOOL Clab3_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Clab3_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Clab3_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// Clab3_1View 诊断

#ifdef _DEBUG
void Clab3_1View::AssertValid() const
{
	CView::AssertValid();
}

void Clab3_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Clab3_1Doc* Clab3_1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Clab3_1Doc)));
	return (Clab3_1Doc*)m_pDocument;
}
#endif //_DEBUG


// Clab3_1View 消息处理程序


void Clab3_1View::OnContextMenu(CWnd* /*pWnd*/, CPoint point)
{
	// TODO: 在此处添加消息处理程序代码
	CMenu menu; //声明一个menu对象
	menu.LoadMenu(IDR_POPUPMENU); //加载我们自定义的菜单栏
	CMenu* pMenu=menu.GetSubMenu(0); //定义指针逐级获取下一级（常用操作
	pMenu->TrackPopupMenu(TPM_LEFTALIGN, point.x,point.y,this); //弹出菜单

}


int Clab3_1View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	SetTimer(1,200,NULL);
	return 0;
}


void Clab3_1View::OnDestroy()
{
	CView::OnDestroy();
	KillTimer(1);
	// TODO: 在此处添加消息处理程序代码
}


void Clab3_1View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//按“V”键（不区分大小写）开始循环操作
	if(nChar=='v'||nChar=='V'){
		moveLoop=true;
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void Clab3_1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//设置鼠标左键按下时输出坐标，便于坐标点的定位
	CString str;
	str.Format(L"当前坐标为（%d,%d）",point.x,point.y);
	MessageBox(str);
	CView::OnLButtonDown(nFlags, point);
}


void Clab3_1View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CBitmap bm;
	bm.LoadBitmap(IDB_BITMAP1);
	CBrush brush1;
	brush1.CreatePatternBrush(&bm);
	
	CDC *pDC=GetDC();
	pDC->SelectObject(brush1);

	//计时器进行设置
	if(nIDEvent==1)
	{
		if(moveLoop)
		{
			//对于三种图形的边界顶点进行判断，控制位图的移动
			if(drawSelect==1)
			{
				if(x1<200 || x1>400){
					movex1=-movex1;}
				if(y1<200 || y1>400){
					movey1=-movey1;}
				pDC->PatBlt(x1,y1,8,8,PATCOPY);
				pDC->PatBlt(x1-movex1,y1-movey1,8,8,WHITENESS);
				if(x1!=200&&x1!=190&&x1!=400&&x1!=410){//边界判断
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
	// TODO: 在此添加命令处理程序代码
	drawSelect=1;
	//绘制倾斜45°的直线
	CBitmap bm;
	CDC *pDC=GetDC();
	pDC->PatBlt(0,0,1000,1000,WHITENESS);
	pDC->MoveTo(point1[0].x,point1[0].y);
	pDC->LineTo(point1[1].x,point1[1].y);
}


void Clab3_1View::OnDrawp()
{
	// TODO: 在此添加命令处理程序代码
	//绘制多边形
	drawSelect=3;
	CBitmap bm;
	CDC *pDC=GetDC();
	pDC->PatBlt(0,0,1000,1000,WHITENESS);
	pDC->Polygon(point3,6);
}


void Clab3_1View::OnDrawrect()
{
	// TODO: 在此添加命令处理程序代码
	//绘制矩形
	drawSelect=2;
	CBitmap bm;
	CDC *pDC=GetDC();
	pDC->PatBlt(0,0,1000,1000,WHITENESS);
	pDC->Rectangle(point2[0].x,point2[0].y,point2[1].x,point2[1].y);
}
