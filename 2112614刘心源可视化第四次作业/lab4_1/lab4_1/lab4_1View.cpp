
// lab4_1View.cpp : Clab4_1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "lab4_1.h"
#endif

#include "lab4_1Doc.h"
#include "lab4_1View.h"
#include "NewDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Clab4_1View

IMPLEMENT_DYNCREATE(Clab4_1View, CView)

BEGIN_MESSAGE_MAP(Clab4_1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_OPENDLG, &Clab4_1View::OnOpendlg)
END_MESSAGE_MAP()

// Clab4_1View 构造/析构

Clab4_1View::Clab4_1View()
{
	// TODO: 在此处添加构造代码

}

Clab4_1View::~Clab4_1View()
{
}

BOOL Clab4_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Clab4_1View 绘制

void Clab4_1View::OnDraw(CDC* /*pDC*/)
{
	Clab4_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Clab4_1View 打印

BOOL Clab4_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Clab4_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Clab4_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// Clab4_1View 诊断

#ifdef _DEBUG
void Clab4_1View::AssertValid() const
{
	CView::AssertValid();
}

void Clab4_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Clab4_1Doc* Clab4_1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Clab4_1Doc)));
	return (Clab4_1Doc*)m_pDocument;
}
#endif //_DEBUG


// Clab4_1View 消息处理程序


void Clab4_1View::OnOpendlg()
{
	// TODO: 在此添加命令处理程序代码
	CNewDlg dlg;
	if (dlg.DoModal()==IDOK){

		CString str0;
		CString str1;
		CString str2;
		CString str3;
		CString str4;
		CString str5;
		CString str6;
		CString str7;
		int x=0;
		int y=0;
		int count=1;

		CString storeToDoc=L"";

		CTypedPtrList <CObList,CStudent*> *TheList=dlg.getList();
		POSITION pos = TheList->GetHeadPosition();
		while (pos != nullptr)
		{
			CStudent* pStudent = TheList->GetNext(pos);
			CString temp;
			temp.Format(_T("%d"), count);
			str0=L"记录"+temp;
			str1=L"Name:"+pStudent->name+L";  ";
			str2=L"Sex:："+pStudent->sex+L";  ";
			str3=L"Age:"+pStudent->age+L";  ";
			str4=L"Nation:"+pStudent->ethnic+L";  ";
			str5=L"Address:"+pStudent->origin+L";  ";
			str6=L"Telephone:"+pStudent->id+L";  ";
			str7=L"Department:"+pStudent->major+L";  ";
			CString str_image = pStudent->imageStr;

			CDC *pdc=GetDC();
			pdc->TextOutW(x,y,str0+str1+str2+str3+str4+str5+str6+str7);
			y+=50;
			count+=1;
			storeToDoc+=str0+str1+str2+str3+str4+str5+str6+str7+L"\r";


			CImage temp1;
			if (temp1.Load(str_image) == S_OK)
			{	
				temp1.Draw(GetDC()->m_hDC,
				10,
				y+-100+10,
				100,
				100); 
				temp1.Destroy();
			}
			if(str_image==L""){
				GetDC()->FillSolidRect(10 ,y-100+10 ,100,100, RGB(192, 192, 192));
			}
		}
		Clab4_1Doc *pdoc=GetDocument();
		pdoc->setInfo(storeToDoc);

	}

}
