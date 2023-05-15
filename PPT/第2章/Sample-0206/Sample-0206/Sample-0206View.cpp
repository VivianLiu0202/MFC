
// Sample-0206View.cpp : CSample0206View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Sample-0206.h"
#endif

#include "Sample-0206Doc.h"
#include "Sample-0206View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSample0206View

IMPLEMENT_DYNCREATE(CSample0206View, CView)

BEGIN_MESSAGE_MAP(CSample0206View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSample0206View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_TEST_COLORDIALOG, &CSample0206View::OnTestColordialog)
	ON_COMMAND(ID_TEST_MESSAGEBOX, &CSample0206View::OnTestMessagebox)
END_MESSAGE_MAP()

// CSample0206View 构造/析构

CSample0206View::CSample0206View()
{
	// TODO: 在此处添加构造代码

}

CSample0206View::~CSample0206View()
{
}

BOOL CSample0206View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CSample0206View 绘制

void CSample0206View::OnDraw(CDC* /*pDC*/)
{
	CSample0206Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CSample0206View 打印


void CSample0206View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSample0206View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CSample0206View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CSample0206View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CSample0206View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSample0206View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSample0206View 诊断

#ifdef _DEBUG
void CSample0206View::AssertValid() const
{
	CView::AssertValid();
}

void CSample0206View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSample0206Doc* CSample0206View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSample0206Doc)));
	return (CSample0206Doc*)m_pDocument;
}
#endif //_DEBUG


// CSample0206View 消息处理程序


void CSample0206View::OnTestColordialog()
{
	// TODO: 在此添加命令处理程序代码
	CColorDialog Dlg;
	Dlg.DoModal();
}


void CSample0206View::OnTestMessagebox()
{
	// TODO: 在此添加命令处理程序代码
	MessageBox(L"MessageBox Clicked!");
}
