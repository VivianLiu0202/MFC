
// Sample-0205View.cpp : CSample0205View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Sample-0205.h"
#endif

#include "Sample-0205Doc.h"
#include "Sample-0205View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSample0205View

IMPLEMENT_DYNCREATE(CSample0205View, CView)

BEGIN_MESSAGE_MAP(CSample0205View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSample0205View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CSample0205View 构造/析构

CSample0205View::CSample0205View()
{
	// TODO: 在此处添加构造代码

}

CSample0205View::~CSample0205View()
{
}

BOOL CSample0205View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CSample0205View 绘制

void CSample0205View::OnDraw(CDC* /*pDC*/)
{
	CSample0205Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CSample0205View 打印


void CSample0205View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSample0205View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CSample0205View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CSample0205View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CSample0205View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSample0205View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSample0205View 诊断

#ifdef _DEBUG
void CSample0205View::AssertValid() const
{
	CView::AssertValid();
}

void CSample0205View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSample0205Doc* CSample0205View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSample0205Doc)));
	return (CSample0205Doc*)m_pDocument;
}
#endif //_DEBUG


// CSample0205View 消息处理程序


void CSample0205View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString str;
	str.Format(L"%c Key Entered!",nChar);
	MessageBox(str);

	CView::OnChar(nChar, nRepCnt, nFlags);
}

BOOL CSample0205View::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if(pMsg->message==WM_KEYDOWN)
	{
		if(pMsg->wParam==VK_F1) 
			MessageBox(L"F1 Key Entered!");
		if(pMsg->wParam==VK_UP) 
			MessageBox(L"↑ Key Entered!");
	}

	return CView::PreTranslateMessage(pMsg);
}
