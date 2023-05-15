
// Sample-0202View.cpp : CSample0202View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Sample-0202.h"
#endif

#include "Sample-0202Doc.h"
#include "Sample-0202View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSample0202View

IMPLEMENT_DYNCREATE(CSample0202View, CView)

BEGIN_MESSAGE_MAP(CSample0202View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSample0202View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CSample0202View 构造/析构

CSample0202View::CSample0202View()
{
	// TODO: 在此处添加构造代码

}

CSample0202View::~CSample0202View()
{
}

BOOL CSample0202View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CSample0202View 绘制

void CSample0202View::OnDraw(CDC* pDC)
{
	CSample0202Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	int nTotalPoints=32000;
	CRect rect;
	GetClientRect(&rect);
	int nX=rect.right/2;
	int nY=rect.bottom*5/6;
	int nScale=(rect.right>rect.bottom?rect.bottom:rect.right)/15;
	COLORREF crColor=0x00FF00;
	double dX=0, dY=0;
	double dP; 
	for(int i=0;i<nTotalPoints;i++)
	{		
		dP=1.0*rand()/RAND_MAX;
		if(dP<=0.01)
		{
			dX=0;
			dY=0.16*dY;
		}
		if(dP>0.01 && dP<=0.86)   
		{
			dX=0.85*dX+0.04*dY;
			dY=-0.04*dX+0.85*dY+1.60;
		}
		if(dP>0.86 && dP<=0.93)    
		{
			dX=0.20*dX-0.26*dY;
			dY=0.44*dX+0.12*dY+1.60;
		}
		if(dP>0.93)                  
		{
			dX=-0.20*dX+0.26*dY;
			dY=0.44*dX+0.12*dY+1.00;
		}
		pDC->SetPixel(nX+int(dX*nScale),nY-int(dY*nScale),crColor);
	}
}


// CSample0202View 打印


void CSample0202View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSample0202View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CSample0202View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CSample0202View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CSample0202View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSample0202View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSample0202View 诊断

#ifdef _DEBUG
void CSample0202View::AssertValid() const
{
	CView::AssertValid();
}

void CSample0202View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSample0202Doc* CSample0202View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSample0202Doc)));
	return (CSample0202Doc*)m_pDocument;
}
#endif //_DEBUG


// CSample0202View 消息处理程序
