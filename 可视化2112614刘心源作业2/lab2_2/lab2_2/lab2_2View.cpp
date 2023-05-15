
// lab2_2View.cpp : Clab2_2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "lab2_2.h"
#endif

#include "lab2_2Doc.h"
#include "lab2_2View.h"
#include "MyDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Clab2_2View

IMPLEMENT_DYNCREATE(Clab2_2View, CView)

BEGIN_MESSAGE_MAP(Clab2_2View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_TEST, &Clab2_2View::OnTest)
	ON_COMMAND(ID_FONT, &Clab2_2View::OnFont)
END_MESSAGE_MAP()

// Clab2_2View 构造/析构

Clab2_2View::Clab2_2View()
{
	// TODO: 在此处添加构造代码
	string="";
}

Clab2_2View::~Clab2_2View()
{
}

BOOL Clab2_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式
	return CView::PreCreateWindow(cs);
}

// Clab2_2View 绘制

void Clab2_2View::OnDraw(CDC* pDC)
{
	Clab2_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 在此处为本机数据添加绘制代码
	pDoc->Get(string);
	pDC->TextOutW(100,400,string);
}


// Clab2_2View 打印

BOOL Clab2_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Clab2_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Clab2_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// Clab2_2View 诊断

#ifdef _DEBUG
void Clab2_2View::AssertValid() const
{
	CView::AssertValid();
}

void Clab2_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Clab2_2Doc* Clab2_2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Clab2_2Doc)));
	return (Clab2_2Doc*)m_pDocument;
}
#endif //_DEBUG


// Clab2_2View 消息处理程序


void Clab2_2View::OnTest()
{
	// TODO: 在此添加命令处理程序代码
	MyDialog dlg;
	dlg.DoModal();
	CDC* pDC=GetDC();
	pDC->TextOutW(100,400,dlg.str);;
	string=dlg.str;
	Clab2_2Doc *pDoc=GetDocument();
	pDoc->SetStr((string));//将temp存入Clab2_1Doc的变量str中，后续用于文档读写
}


void Clab2_2View::OnFont()
{
	// TODO: 在此添加命令处理程序代码
	
	CFontDialog fdlg(&m_Lofont);
	fdlg.m_cf.rgbColors = m_CurrentCr;
	fdlg.m_cf.Flags |= CF_USESTYLE;
	if (fdlg.DoModal() == IDOK)
	{
		fdlg.GetCurrentFont(&m_Lofont);
		m_CurrentCr = fdlg.GetColor();
	}
}
