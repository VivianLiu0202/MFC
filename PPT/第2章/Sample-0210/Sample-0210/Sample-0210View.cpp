
// Sample-0210View.cpp : CSample0210View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Sample-0210.h"
#endif

#include "Sample-0210Doc.h"
#include "Sample-0210View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSample0210View

IMPLEMENT_DYNCREATE(CSample0210View, CView)

BEGIN_MESSAGE_MAP(CSample0210View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSample0210View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CSample0210View 构造/析构

CSample0210View::CSample0210View()
{
	// TODO: 在此处添加构造代码

}

CSample0210View::~CSample0210View()
{
}

BOOL CSample0210View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CSample0210View 绘制

void CSample0210View::OnDraw(CDC* pDC)
{
	CSample0210Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	m_pDC=pDC;
    CRect rect;
	GetClientRect(&rect);
    int iOx=rect.right/2;
	int iOy=rect.bottom/2; 
    DrawRect(iOx,iOy,(iOx>iOy?iOy:iOx)/3);
}


// CSample0210View 打印


void CSample0210View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSample0210View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CSample0210View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CSample0210View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CSample0210View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSample0210View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSample0210View 诊断

#ifdef _DEBUG
void CSample0210View::AssertValid() const
{
	CView::AssertValid();
}

void CSample0210View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSample0210Doc* CSample0210View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSample0210Doc)));
	return (CSample0210Doc*)m_pDocument;
}
#endif //_DEBUG


// CSample0210View 消息处理程序


void CSample0210View::DrawRect(int iX, int iY, int iR)
{
	if(iR>0)
    {
        DrawRect(iX-iR,iY+iR,iR/2);
		DrawRect(iX+iR,iY+iR,iR/2);
        DrawRect(iX-iR,iY-iR,iR/2);
		DrawRect(iX+iR,iY-iR,iR/2);
        m_pDC->Rectangle(iX-iR,iY-iR,iX+iR,iY+iR);
    }
}
