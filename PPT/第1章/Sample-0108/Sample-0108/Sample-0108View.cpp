
// Sample-0108View.cpp : CSample0108View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Sample-0108.h"
#endif

#include "Sample-0108Doc.h"
#include "Sample-0108View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSample0108View

IMPLEMENT_DYNCREATE(CSample0108View, CView)

BEGIN_MESSAGE_MAP(CSample0108View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSample0108View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CSample0108View 构造/析构

CSample0108View::CSample0108View()
{
	// TODO: 在此处添加构造代码

}

CSample0108View::~CSample0108View()
{
}

BOOL CSample0108View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CSample0108View 绘制

void CSample0108View::OnDraw(CDC* pDC)
{
	CSample0108Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CRect rect;
	GetClientRect(&rect);
	pDC->PatBlt(0,0,rect.right,rect.bottom,BLACKNESS);
}


// CSample0108View 打印


void CSample0108View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSample0108View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CSample0108View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CSample0108View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CSample0108View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSample0108View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSample0108View 诊断

#ifdef _DEBUG
void CSample0108View::AssertValid() const
{
	CView::AssertValid();
}

void CSample0108View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSample0108Doc* CSample0108View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSample0108Doc)));
	return (CSample0108Doc*)m_pDocument;
}
#endif //_DEBUG


// CSample0108View 消息处理程序


void CSample0108View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDC* pDC=GetDC();
	MessageBox(L"Mouse Clicked!",L"Message 1",MB_OK);
	pDC->TextOut(0,0,L"Mouse Clicked!");
	CView::OnLButtonDown(nFlags, point);
}
