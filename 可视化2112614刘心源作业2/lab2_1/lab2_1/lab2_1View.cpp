
// lab2_1View.cpp : Clab2_1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "lab2_1.h"
#endif

#include "lab2_1Doc.h"
#include "lab2_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Clab2_1View

IMPLEMENT_DYNCREATE(Clab2_1View, CView)

BEGIN_MESSAGE_MAP(Clab2_1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_ECLLIPSE, &Clab2_1View::OnEcllipse)
	ON_COMMAND(ID_INVALIDECLLIPSE, &Clab2_1View::OnInvalidecllipse)
	ON_COMMAND(ID_INVALIDRECTANGLE, &Clab2_1View::OnInvalidrectangle)
	ON_COMMAND(ID_RECT, &Clab2_1View::OnRect)
//	ON_COMMAND(ID_CORLORCHANGE, &Clab2_1View::OnCorlorchange)
	ON_COMMAND(ID_CHANGECOLOR, &Clab2_1View::OnChangecolor)
	ON_COMMAND(ID_VALIDALL, &Clab2_1View::OnValidall)
	ON_COMMAND(ID_SMALL, &Clab2_1View::OnSmall)
	ON_COMMAND(ID_BIG, &Clab2_1View::OnBig)
	ON_COMMAND(ID_THICK, &Clab2_1View::OnThick)
	ON_COMMAND(ID_THIN, &Clab2_1View::OnThin)
//	ON_WM_LBUTTONDOWN()
ON_COMMAND(ID_SHOWTEXT, &Clab2_1View::OnShowtext)
END_MESSAGE_MAP()

// Clab2_1View 构造/析构

Clab2_1View::Clab2_1View()
	: UnableEcllipse(false)
	, UnableRect(false)
	, PenWidth(5)
{
	// TODO: 在此处添加构造代码
	m_clr=RGB(0,0,0);
	Eclx=400;
	Ecly=200;
	Rectx=400;
	Recty=200;

}

Clab2_1View::~Clab2_1View()
{
}

BOOL Clab2_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Clab2_1View 绘制

void Clab2_1View::OnDraw(CDC* /*pDC*/)
{
	Clab2_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Clab2_1View 打印

BOOL Clab2_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Clab2_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Clab2_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// Clab2_1View 诊断

#ifdef _DEBUG
void Clab2_1View::AssertValid() const
{
	CView::AssertValid();
}

void Clab2_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Clab2_1Doc* Clab2_1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Clab2_1Doc)));
	return (Clab2_1Doc*)m_pDocument;
}
#endif //_DEBUG


// Clab2_1View 消息处理程序


void Clab2_1View::OnContextMenu(CWnd* /*pWnd*/, CPoint point)
{
	// TODO: 在此处添加消息处理程序代码
	CMenu menu;
	menu.LoadMenu(IDR_POPUPMENU);
	CMenu *pm=menu.GetSubMenu(0);
	//menu.GetSubMenu(0)->SetMenuItemBitmaps(0,MF_BYPOSITION,&bm1,&bm1);//设置椭圆位图
	//menu.GetSubMenu(0)->SetMenuItemBitmaps(1,MF_BYPOSITION,&bm2,&bm2);//设置矩形位图
	if(UnableEcllipse)
	{
		menu.GetSubMenu(0)->EnableMenuItem(0,MF_BYPOSITION|MF_DISABLED|MF_GRAYED);
	}
	if(UnableRect)
	{
		menu.GetSubMenu(0)->EnableMenuItem(1,MF_BYPOSITION|MF_DISABLED|MF_GRAYED);
	}

	/*CString temp;
	temp.Format(L"%d,%d",unableElli,unableRect);
	MessageBox(temp);*/

	pm->TrackPopupMenu(TPM_LEFTALIGN,point.x,point.y,this);
}


void Clab2_1View::OnEcllipse()
{
	// TODO: 在此添加命令处理程序代码
	CRect rect;
	GetClientRect(&rect);
	int X=rect.right/2;
	int Y=rect.bottom/2;//找到客户区中心的x y坐标

	CDC *pDC=GetDC();
	CPen MyPen(PS_SOLID,PenWidth,m_clr);
	pDC->SelectObject(MyPen);//自定义画笔并设置画笔
	pDC->PatBlt(0,0,rect.right,rect.bottom, WHITENESS);//通过位图填充做到显示区域清屏
	pDC->Ellipse(X-Eclx/2,Y-Ecly/2,X+Eclx/2,Y+Ecly/2);

		//设置字体
	LOGFONT lf; 
	lf.lfHeight=20; //高度 
	lf.lfWidth=0; //宽度 
	lf.lfEscapement=0; //除以10为水平线角度 
	lf.lfWeight=FW_BOLD; //粗体 
	lf.lfUnderline=false; //无下划线 
	lf.lfItalic=false; //非斜体 
	lf.lfStrikeOut=false; //无删除线 
	lf.lfCharSet=GB2312_CHARSET; //字符集 
	CFont newFont; 
	newFont.CreateFontIndirect(&lf); 
	pDC->SelectObject(newFont); 

	CString temp1;
	temp1.Format(L"绘制图形为椭圆，左上角坐标为(%d,%d)，长轴为%d，短轴为%d，画笔宽度为%d！",X-Eclx/2,Y-Ecly/2,Eclx,Ecly,PenWidth);
	pDC->TextOutW(50,50,temp1);
	Clab2_1Doc *pDoc=GetDocument();
	pDoc->SetStr(temp1);//将temp1存入Clab2_1Doc的变量str中，后续用于文档读写

    ReleaseDC(pDC);
}


void Clab2_1View::OnInvalidecllipse()
{
	// TODO: 在此添加命令处理程序代码
	UnableEcllipse=true;
}


void Clab2_1View::OnInvalidrectangle()
{
	// TODO: 在此添加命令处理程序代码
	UnableRect=true;
}


void Clab2_1View::OnRect()
{
	// TODO: 在此添加命令处理程序代码
	CRect rect;
	GetClientRect(&rect);
	int X=rect.right/2;
	int Y=rect.bottom/2;//找到客户区中心
	
	CDC *pDC=GetDC();
	CPen MyPen(PS_SOLID,PenWidth,m_clr);
	pDC->SelectObject(MyPen);//自定义画笔并设置画笔
	pDC->PatBlt(0,0,rect.right,rect.bottom, WHITENESS);//通过位图填充做到显示区域清屏
	pDC->Rectangle(X-Rectx/2,Y-Recty/2,X+Rectx/2,Y+Recty/2);

	//设置字体
	LOGFONT lf; 
	lf.lfHeight=20; //高度 
	lf.lfWidth=0; //宽度 
	lf.lfEscapement=0; //除以10为水平线角度 
	lf.lfWeight=FW_BOLD; //粗体 
	lf.lfUnderline=false; //无下划线 
	lf.lfItalic=false; //非斜体 
	lf.lfStrikeOut=false; //无删除线 
	lf.lfCharSet=GB2312_CHARSET; //字符集 
	CFont newFont; 
	newFont.CreateFontIndirect(&lf); 
	pDC->SelectObject(newFont); 

	CString temp1;
	temp1.Format(L"绘制图形为矩形，左上角坐标为(%d,%d)，长为%d，宽为%d，画笔宽度为%d！",X-Rectx/2,Y-Recty/2,Rectx,Recty,PenWidth);
	pDC->TextOutW(50,50,temp1);
	Clab2_1Doc *pDoc=GetDocument();
	pDoc->SetStr(temp1);//将temp存入Clab2_1Doc的变量str中，后续用于文档读写

	ReleaseDC(pDC);
}

//void Clab2_1View::OnCorlorchange()
//{
//	// TODO: 在此添加命令处理程序代码
//}


void Clab2_1View::OnChangecolor()
{
	// TODO: 在此添加命令处理程序代码
	CColorDialog dlg(m_clr);//声明颜色对话框
    if(IDOK==dlg.DoModal())//获取所选颜色
    {
		m_clr = dlg.GetColor();    //获取到的颜色对话框中的颜色保存到变量m_clr中
    }
}


void Clab2_1View::OnValidall()
{
	// TODO: 在此添加命令处理程序代码
	UnableRect=false;
	UnableEcllipse=false;
}


void Clab2_1View::OnBig()
{
	// TODO: 在此添加命令处理程序代码
	if((Eclx<600 && Ecly<300) && (Rectx<600) && (Recty<300))
	{
		Eclx+=50;Ecly+=25;
		Rectx+=50;Recty+=25;
	}
	else MessageBox(L"人家已经很胖了别增肥啦QAQ！");
}


void Clab2_1View::OnSmall()
{
	// TODO: 在此添加命令处理程序代码
	if((Eclx>200 && Ecly>100) && (Rectx>200) && (Recty>100))
	{
		Eclx-=50;Ecly-=25;
		Rectx-=50;Recty-=25;
	}
	else MessageBox(L"人家已经很瘦了别减肥啦QAQ！");
}


void Clab2_1View::OnThick()
{
	// TODO: 在此添加命令处理程序代码
	if(PenWidth<10)
		PenWidth+=2;
	else
		MessageBox(L"人家已经很宽了啊喂(#`O′)");
}


void Clab2_1View::OnThin()
{
	// TODO: 在此添加命令处理程序代码
	if(PenWidth>1)
		PenWidth-=2;
	else
		MessageBox(L"已经这么细了你还要人家咋样吗~");
}




void Clab2_1View::OnShowtext()
{
	// TODO: 在此添加命令处理程序代码
	CString str1;
	Clab2_1Doc *pDoc1=GetDocument();
	pDoc1->Get(str1);
	MessageBox(str1);
}
