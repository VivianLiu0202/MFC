
// Sample-0201View.cpp : CSample0201View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Sample-0201.h"
#endif

#include "Sample-0201Doc.h"
#include "Sample-0201View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSample0201View

IMPLEMENT_DYNCREATE(CSample0201View, CView)

BEGIN_MESSAGE_MAP(CSample0201View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSample0201View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_EDIT_PASTE, &CSample0201View::OnEditPaste)
END_MESSAGE_MAP()

// CSample0201View 构造/析构

CSample0201View::CSample0201View()
{
	// TODO: 在此处添加构造代码

}

CSample0201View::~CSample0201View()
{
}

BOOL CSample0201View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CSample0201View 绘制

void CSample0201View::OnDraw(CDC* pDC)
{
	CSample0201Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->TextOut(20,20,L"Windows Painted!");
	pDC->SelectStockObject(GRAY_BRUSH);
	pDC->Ellipse(20,50,100,130);
}


// CSample0201View 打印


void CSample0201View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSample0201View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CSample0201View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CSample0201View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CSample0201View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSample0201View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSample0201View 诊断

#ifdef _DEBUG
void CSample0201View::AssertValid() const
{
	CView::AssertValid();
}

void CSample0201View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSample0201Doc* CSample0201View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSample0201Doc)));
	return (CSample0201Doc*)m_pDocument;
}
#endif //_DEBUG


// CSample0201View 消息处理程序


void CSample0201View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//CDC *pDC=GetDC();
	//pDC->TextOut(point.x,point.y,L"Mouse Clicked!");
	//ReleaseDC(pDC);
	//CClientDC DC(this);
	//DC.TextOut(point.x,point.y,L"Mouse Clicked!");

	CView::OnLButtonDown(nFlags, point);
}


void CSample0201View::OnEditPaste()
{
	// TODO: 在此添加命令处理程序代码
	//CDC *pDC=GetDC();
	//pDC->TextOut(10,10,L"Menu Clicked!");
	//ReleaseDC(pDC);
}
