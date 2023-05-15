
// lab3_2View.cpp : Clab3_2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_COMMAND(ID_BIGGER, &Clab3_2View::OnBigger)
	ON_COMMAND(ID_SMALLER, &Clab3_2View::OnSmaller)
	ON_COMMAND(ID_ORIGIN, &Clab3_2View::OnOrigin)
	ON_COMMAND(ID_PIC1, &Clab3_2View::OnPic1)
	ON_COMMAND(ID_PIC2, &Clab3_2View::OnPic2)
END_MESSAGE_MAP()

// Clab3_2View 构造/析构

Clab3_2View::Clab3_2View()
	: chooseBit(1)
{
	// TODO: 在此处添加构造代码

}

Clab3_2View::~Clab3_2View()
{
}

BOOL Clab3_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CScrollView::PreCreateWindow(cs);
}

// Clab3_2View 绘制

void Clab3_2View::OnDraw(CDC* pDC)
{
	Clab3_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CBitmap bm; 
	if(chooseBit==1) bm.LoadBitmap(IDB_BITMAP1);
	if(chooseBit==2) bm.LoadBitmap(IDB_BITMAP2);
	CDC memDC; 
	memDC.CreateCompatibleDC(pDC);
	memDC.SelectObject(&bm);
	BITMAP info; bm.GetBitmap(&info);

	if(drawselect==1)//原图
	{
		pDC->StretchBlt(0,0,info.bmWidth, 
		info.bmHeight,&memDC,0,0,info.bmWidth, 
		info.bmHeight,SRCCOPY);
		bm.DeleteObject();
	}
	if(drawselect==2)//放大四倍
	{
		pDC->StretchBlt(0,0,info.bmWidth*2, 
		info.bmHeight*2,&memDC,0,0,info.bmWidth, 
		info.bmHeight,SRCCOPY);
		bm.DeleteObject();
	}
	if(drawselect==3)//缩小四倍
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
	// TODO: 计算此视图的合计大小
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// Clab3_2View 打印

BOOL Clab3_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Clab3_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Clab3_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// Clab3_2View 诊断

#ifdef _DEBUG
void Clab3_2View::AssertValid() const
{
	CScrollView::AssertValid();
}

void Clab3_2View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

Clab3_2Doc* Clab3_2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Clab3_2Doc)));
	return (Clab3_2Doc*)m_pDocument;
}
#endif //_DEBUG


// Clab3_2View 消息处理程序


void Clab3_2View::OnBigger()
{
	// TODO: 在此添加命令处理程序代码
	drawselect=2;
	Invalidate();
}


void Clab3_2View::OnSmaller()
{
	// TODO: 在此添加命令处理程序代码
	drawselect=3;
	Invalidate();
}


void Clab3_2View::OnOrigin()
{
	// TODO: 在此添加命令处理程序代码
	drawselect=1;
	Invalidate();
}


void Clab3_2View::OnPic1()
{
	// TODO: 在此添加命令处理程序代码
	chooseBit=1;
}


void Clab3_2View::OnPic2()
{
	// TODO: 在此添加命令处理程序代码
	chooseBit=2;
}
