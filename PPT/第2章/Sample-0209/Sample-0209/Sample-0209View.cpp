
// Sample-0209View.cpp : CSample0209View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Sample-0209.h"
#endif

#include "Sample-0209Doc.h"
#include "Sample-0209View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSample0209View

IMPLEMENT_DYNCREATE(CSample0209View, CView)

BEGIN_MESSAGE_MAP(CSample0209View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSample0209View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_MESSAGE(WM_MYMESSAGE,OnMyMessage)
	ON_WM_LBUTTONDOWN()
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CSample0209View 构造/析构

CSample0209View::CSample0209View()
{
	// TODO: 在此处添加构造代码

}

CSample0209View::~CSample0209View()
{
}

BOOL CSample0209View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CSample0209View 绘制

void CSample0209View::OnDraw(CDC* /*pDC*/)
{
	CSample0209Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CSample0209View 打印


void CSample0209View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSample0209View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CSample0209View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CSample0209View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CSample0209View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSample0209View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSample0209View 诊断

#ifdef _DEBUG
void CSample0209View::AssertValid() const
{
	CView::AssertValid();
}

void CSample0209View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSample0209Doc* CSample0209View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSample0209Doc)));
	return (CSample0209Doc*)m_pDocument;
}
#endif //_DEBUG


// CSample0209View 消息处理程序


LRESULT CSample0209View::OnMyMessage(WPARAM wParam, LPARAM lParam)
{
	CString str;
	str.Format(L"Message Param is %d and %d", wParam,lParam);
	MessageBox(str);

	return 0;
}


void CSample0209View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	PostMessage(WM_MYMESSAGE,1,2);

	CView::OnLButtonDown(nFlags, point);
}


void CSample0209View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	SendMessage(WM_MYMESSAGE,3,4);

	CView::OnChar(nChar, nRepCnt, nFlags);
}
