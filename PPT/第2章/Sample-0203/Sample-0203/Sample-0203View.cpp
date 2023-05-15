
// Sample-0203View.cpp : CSample0203View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Sample-0203.h"
#endif

#include "Sample-0203Doc.h"
#include "Sample-0203View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSample0203View

IMPLEMENT_DYNCREATE(CSample0203View, CView)

BEGIN_MESSAGE_MAP(CSample0203View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSample0203View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CREATE()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

// CSample0203View 构造/析构

CSample0203View::CSample0203View()
	: m_Num(0)
{
	// TODO: 在此处添加构造代码
}

CSample0203View::~CSample0203View()
{
}

BOOL CSample0203View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CSample0203View 绘制

void CSample0203View::OnDraw(CDC* pDC)
{
	CSample0203Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CString str;
	str.Format(L"Window %dth Painted!",m_Num++);
	pDC->TextOut(10,10,str);
}


// CSample0203View 打印


void CSample0203View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSample0203View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CSample0203View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CSample0203View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CSample0203View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSample0203View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSample0203View 诊断

#ifdef _DEBUG
void CSample0203View::AssertValid() const
{
	CView::AssertValid();
}

void CSample0203View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSample0203Doc* CSample0203View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSample0203Doc)));
	return (CSample0203Doc*)m_pDocument;
}
#endif //_DEBUG


// CSample0203View 消息处理程序


int CSample0203View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	//MessageBox(L"Windows Created!");

	return 0;
}


void CSample0203View::OnDestroy()
{
	CView::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
	//MessageBox(L"Windows Destroyed!");

}
