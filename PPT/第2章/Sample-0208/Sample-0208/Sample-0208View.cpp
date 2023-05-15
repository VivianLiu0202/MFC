
// Sample-0208View.cpp : CSample0208View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Sample-0208.h"
#endif

#include "Sample-0208Doc.h"
#include "Sample-0208View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSample0208View

IMPLEMENT_DYNCREATE(CSample0208View, CView)

BEGIN_MESSAGE_MAP(CSample0208View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSample0208View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_HOTKEY()
	ON_WM_CREATE()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

// CSample0208View 构造/析构

CSample0208View::CSample0208View()
{
	// TODO: 在此处添加构造代码

}

CSample0208View::~CSample0208View()
{
}

BOOL CSample0208View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CSample0208View 绘制

void CSample0208View::OnDraw(CDC* /*pDC*/)
{
	CSample0208Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CSample0208View 打印


void CSample0208View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSample0208View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CSample0208View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CSample0208View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CSample0208View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSample0208View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSample0208View 诊断

#ifdef _DEBUG
void CSample0208View::AssertValid() const
{
	CView::AssertValid();
}

void CSample0208View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSample0208Doc* CSample0208View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSample0208Doc)));
	return (CSample0208Doc*)m_pDocument;
}
#endif //_DEBUG


// CSample0208View 消息处理程序


void CSample0208View::OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(nHotKeyId==1001||nHotKeyId==1002)
		MessageBox(L"Hot Key Clicked!");

	CView::OnHotKey(nHotKeyId, nKey1, nKey2);
}


int CSample0208View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	RegisterHotKey(m_hWnd,1001,MOD_CONTROL|MOD_ALT,'z');
	RegisterHotKey(m_hWnd,1002,MOD_CONTROL|MOD_ALT,'Z');

	return 0;
}


void CSample0208View::OnDestroy()
{
	CView::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
	UnregisterHotKey(m_hWnd,1001);
	UnregisterHotKey(m_hWnd,1002);
}
