
// lab1-1View.cpp : Clab11View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "lab1-1.h"
#endif

#include "lab1-1Doc.h"
#include "lab1-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Clab11View

IMPLEMENT_DYNCREATE(Clab11View, CView)

BEGIN_MESSAGE_MAP(Clab11View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	//	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_CHAR()
	ON_MESSAGE(WM_MYMESSAGE, &Clab11View::OnMyMessage)
	ON_WM_CREATE()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

// Clab11View 构造/析构

Clab11View::Clab11View()
{
	// TODO: 在此处添加构造代码
	p = 0;
}

Clab11View::~Clab11View()
{
}

BOOL Clab11View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Clab11View 绘制

void Clab11View::OnDraw(CDC* /*pDC*/)
{
	Clab11Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Clab11View 打印

BOOL Clab11View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Clab11View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Clab11View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// Clab11View 诊断

#ifdef _DEBUG
void Clab11View::AssertValid() const
{
	CView::AssertValid();
}

void Clab11View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Clab11Doc* Clab11View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Clab11Doc)));
	return (Clab11Doc*)m_pDocument;
}
#endif //_DEBUG


// Clab11View 消息处理程序


//void Clab11View::OnLButtonDblClk(UINT nFlags, CPoint point)
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//
//	CView::OnLButtonDblClk(nFlags, point);
//}


void Clab11View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString str1,str2;
	p = point;
	str1.Format(L"鼠标左键，坐标（%d，%d）",p.x,p.y);
	str2.Format(L"鼠标左键+Ctrl键，坐标（%d，%d）",p.x,p.y);
	if(nFlags&MK_CONTROL){
		MessageBox(str2);
	}
	else MessageBox(str1);
	CView::OnLButtonDown(nFlags, point);
}


void Clab11View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString str;
	str.Format(L"%c键被按下啦！！",nChar);
	CDC *pDC = GetDC();
	pDC->TextOutW(10,10,str);
	if(nChar == '#'){
		SendMessage(WM_MYMESSAGE,100,200);
	}
	CView::OnChar(nChar, nRepCnt, nFlags);
}


BOOL Clab11View::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	CDC * pDC = GetDC();
	if(pMsg->message == WM_KEYDOWN){
		if(pMsg->wParam==VK_UP) 
			pDC->TextOutW(100,100,L"UP键被按下!!");
		if(pMsg->wParam==VK_DOWN) 
			pDC->TextOutW(100,100,L"DOWN键被按下!!");
		if(pMsg->wParam==VK_LEFT)
			pDC->TextOutW(100,100,L"LEFT键被按下!!");
		if(pMsg->wParam==VK_RIGHT)
			pDC->TextOutW(100,100,L"RIGHT键被按下!!!");
		if(pMsg->wParam==VK_F1)
			pDC->TextOutW(100,100,L"F1键被按下!!");
		if(pMsg->wParam==VK_F2)
			pDC->TextOutW(100,100,L"F2键被按下!!");
		if(pMsg->wParam==VK_F3)
			pDC->TextOutW(100,100,L"F3键被按下!!");
		if(pMsg->wParam==VK_F4)
			pDC->TextOutW(100,100,L"F4键被按下!!");
		if(pMsg->wParam==VK_F5)
			pDC->TextOutW(100,100,L"F5键被按下!!");
		if(pMsg->wParam==VK_F6)
			pDC->TextOutW(100,100,L"F6键被按下!!");
	}
	return CView::PreTranslateMessage(pMsg);
}


LRESULT Clab11View::OnMyMessage(WPARAM wParam, LPARAM lParam)
{
	CString str;
	str.Format(L"QAQMessage Param is %d and %d",wParam,lParam);
	CDC *pDC = GetDC();
	pDC->TextOutW(200,200,str);
	return LRESULT();
}


int Clab11View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	MessageBox(L"Hello!!!!!点击确认进入程序！不然就打死你！");
	return 0;
}


void Clab11View::OnDestroy()
{
	CView::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
	MessageBox(L"呜呜呜你要离开我了咩呜呜呜好伤心QAQ");
}
