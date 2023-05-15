
// Sample-0207View.cpp : CSample0207View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Sample-0207.h"
#endif

#include "Sample-0207Doc.h"
#include "Sample-0207View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSample0207View

IMPLEMENT_DYNCREATE(CSample0207View, CView)

BEGIN_MESSAGE_MAP(CSample0207View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSample0207View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CSample0207View 构造/析构

CSample0207View::CSample0207View()
	: x(0)
	, y(0)
	, movex(0)
	, movey(0)
{
	// TODO: 在此处添加构造代码
	movex=movey=5;
}

CSample0207View::~CSample0207View()
{
}

BOOL CSample0207View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CSample0207View 绘制

void CSample0207View::OnDraw(CDC* pDC)
{
	CSample0207Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->SetROP2(R2_XORPEN);
	pDC->Ellipse(x,y,x+15,y+15);
}


// CSample0207View 打印


void CSample0207View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSample0207View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CSample0207View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CSample0207View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CSample0207View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSample0207View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSample0207View 诊断

#ifdef _DEBUG
void CSample0207View::AssertValid() const
{
	CView::AssertValid();
}

void CSample0207View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSample0207Doc* CSample0207View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSample0207Doc)));
	return (CSample0207Doc*)m_pDocument;
}
#endif //_DEBUG


// CSample0207View 消息处理程序


int CSample0207View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	SetTimer(1,20,NULL);
	return 0;
}


void CSample0207View::OnDestroy()
{
	CView::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
	KillTimer(1);
}


void CSample0207View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(nIDEvent==1)
	{
		CRect rect;
		GetClientRect(&rect);
		CDC* pDC=GetDC();
		pDC->SetROP2(R2_XORPEN);
		pDC->Ellipse(x,y,x+15,y+15);
		x+=movex;
		y+=movey;
		if(x<0||x>rect.right-15)
			movex=0-movex;
		if(y<0||y>rect.bottom-15)
			movey=0-movey;
		pDC->Ellipse(x,y,x+15,y+15);
	}
	CView::OnTimer(nIDEvent);
}
