
// Sample-0204View.cpp : CSample0204View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Sample-0204.h"
#endif

#include "Sample-0204Doc.h"
#include "Sample-0204View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSample0204View

IMPLEMENT_DYNCREATE(CSample0204View, CView)

BEGIN_MESSAGE_MAP(CSample0204View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSample0204View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CSample0204View 构造/析构

CSample0204View::CSample0204View()
	: m_Pos(0)
	, m_Str(_T(""))
{
	// TODO: 在此处添加构造代码

}

CSample0204View::~CSample0204View()
{
}

BOOL CSample0204View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CSample0204View 绘制

void CSample0204View::OnDraw(CDC* pDC)
{
	CSample0204Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->TextOut(m_Pos.x,m_Pos.y,m_Str);
}


// CSample0204View 打印


void CSample0204View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSample0204View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CSample0204View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CSample0204View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CSample0204View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSample0204View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSample0204View 诊断

#ifdef _DEBUG
void CSample0204View::AssertValid() const
{
	CView::AssertValid();
}

void CSample0204View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSample0204Doc* CSample0204View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSample0204Doc)));
	return (CSample0204Doc*)m_pDocument;
}
#endif //_DEBUG


// CSample0204View 消息处理程序


void CSample0204View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_Pos=point;
	if(nFlags & MK_CONTROL)
		m_Str="Mouse+Ctrl Clicked!";
	else
		m_Str="Mouse Clicked!";
	Invalidate(true);

	CView::OnLButtonDown(nFlags, point);
}
