
// lab2_1View.cpp : Clab2_1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
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

// Clab2_1View ����/����

Clab2_1View::Clab2_1View()
	: UnableEcllipse(false)
	, UnableRect(false)
	, PenWidth(5)
{
	// TODO: �ڴ˴���ӹ������
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
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Clab2_1View ����

void Clab2_1View::OnDraw(CDC* /*pDC*/)
{
	Clab2_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Clab2_1View ��ӡ

BOOL Clab2_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Clab2_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Clab2_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Clab2_1View ���

#ifdef _DEBUG
void Clab2_1View::AssertValid() const
{
	CView::AssertValid();
}

void Clab2_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Clab2_1Doc* Clab2_1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Clab2_1Doc)));
	return (Clab2_1Doc*)m_pDocument;
}
#endif //_DEBUG


// Clab2_1View ��Ϣ�������


void Clab2_1View::OnContextMenu(CWnd* /*pWnd*/, CPoint point)
{
	// TODO: �ڴ˴������Ϣ����������
	CMenu menu;
	menu.LoadMenu(IDR_POPUPMENU);
	CMenu *pm=menu.GetSubMenu(0);
	//menu.GetSubMenu(0)->SetMenuItemBitmaps(0,MF_BYPOSITION,&bm1,&bm1);//������Բλͼ
	//menu.GetSubMenu(0)->SetMenuItemBitmaps(1,MF_BYPOSITION,&bm2,&bm2);//���þ���λͼ
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
	// TODO: �ڴ���������������
	CRect rect;
	GetClientRect(&rect);
	int X=rect.right/2;
	int Y=rect.bottom/2;//�ҵ��ͻ������ĵ�x y����

	CDC *pDC=GetDC();
	CPen MyPen(PS_SOLID,PenWidth,m_clr);
	pDC->SelectObject(MyPen);//�Զ��廭�ʲ����û���
	pDC->PatBlt(0,0,rect.right,rect.bottom, WHITENESS);//ͨ��λͼ���������ʾ��������
	pDC->Ellipse(X-Eclx/2,Y-Ecly/2,X+Eclx/2,Y+Ecly/2);

		//��������
	LOGFONT lf; 
	lf.lfHeight=20; //�߶� 
	lf.lfWidth=0; //��� 
	lf.lfEscapement=0; //����10Ϊˮƽ�߽Ƕ� 
	lf.lfWeight=FW_BOLD; //���� 
	lf.lfUnderline=false; //���»��� 
	lf.lfItalic=false; //��б�� 
	lf.lfStrikeOut=false; //��ɾ���� 
	lf.lfCharSet=GB2312_CHARSET; //�ַ��� 
	CFont newFont; 
	newFont.CreateFontIndirect(&lf); 
	pDC->SelectObject(newFont); 

	CString temp1;
	temp1.Format(L"����ͼ��Ϊ��Բ�����Ͻ�����Ϊ(%d,%d)������Ϊ%d������Ϊ%d�����ʿ��Ϊ%d��",X-Eclx/2,Y-Ecly/2,Eclx,Ecly,PenWidth);
	pDC->TextOutW(50,50,temp1);
	Clab2_1Doc *pDoc=GetDocument();
	pDoc->SetStr(temp1);//��temp1����Clab2_1Doc�ı���str�У����������ĵ���д

    ReleaseDC(pDC);
}


void Clab2_1View::OnInvalidecllipse()
{
	// TODO: �ڴ���������������
	UnableEcllipse=true;
}


void Clab2_1View::OnInvalidrectangle()
{
	// TODO: �ڴ���������������
	UnableRect=true;
}


void Clab2_1View::OnRect()
{
	// TODO: �ڴ���������������
	CRect rect;
	GetClientRect(&rect);
	int X=rect.right/2;
	int Y=rect.bottom/2;//�ҵ��ͻ�������
	
	CDC *pDC=GetDC();
	CPen MyPen(PS_SOLID,PenWidth,m_clr);
	pDC->SelectObject(MyPen);//�Զ��廭�ʲ����û���
	pDC->PatBlt(0,0,rect.right,rect.bottom, WHITENESS);//ͨ��λͼ���������ʾ��������
	pDC->Rectangle(X-Rectx/2,Y-Recty/2,X+Rectx/2,Y+Recty/2);

	//��������
	LOGFONT lf; 
	lf.lfHeight=20; //�߶� 
	lf.lfWidth=0; //��� 
	lf.lfEscapement=0; //����10Ϊˮƽ�߽Ƕ� 
	lf.lfWeight=FW_BOLD; //���� 
	lf.lfUnderline=false; //���»��� 
	lf.lfItalic=false; //��б�� 
	lf.lfStrikeOut=false; //��ɾ���� 
	lf.lfCharSet=GB2312_CHARSET; //�ַ��� 
	CFont newFont; 
	newFont.CreateFontIndirect(&lf); 
	pDC->SelectObject(newFont); 

	CString temp1;
	temp1.Format(L"����ͼ��Ϊ���Σ����Ͻ�����Ϊ(%d,%d)����Ϊ%d����Ϊ%d�����ʿ��Ϊ%d��",X-Rectx/2,Y-Recty/2,Rectx,Recty,PenWidth);
	pDC->TextOutW(50,50,temp1);
	Clab2_1Doc *pDoc=GetDocument();
	pDoc->SetStr(temp1);//��temp����Clab2_1Doc�ı���str�У����������ĵ���д

	ReleaseDC(pDC);
}

//void Clab2_1View::OnCorlorchange()
//{
//	// TODO: �ڴ���������������
//}


void Clab2_1View::OnChangecolor()
{
	// TODO: �ڴ���������������
	CColorDialog dlg(m_clr);//������ɫ�Ի���
    if(IDOK==dlg.DoModal())//��ȡ��ѡ��ɫ
    {
		m_clr = dlg.GetColor();    //��ȡ������ɫ�Ի����е���ɫ���浽����m_clr��
    }
}


void Clab2_1View::OnValidall()
{
	// TODO: �ڴ���������������
	UnableRect=false;
	UnableEcllipse=false;
}


void Clab2_1View::OnBig()
{
	// TODO: �ڴ���������������
	if((Eclx<600 && Ecly<300) && (Rectx<600) && (Recty<300))
	{
		Eclx+=50;Ecly+=25;
		Rectx+=50;Recty+=25;
	}
	else MessageBox(L"�˼��Ѿ������˱�������QAQ��");
}


void Clab2_1View::OnSmall()
{
	// TODO: �ڴ���������������
	if((Eclx>200 && Ecly>100) && (Rectx>200) && (Recty>100))
	{
		Eclx-=50;Ecly-=25;
		Rectx-=50;Recty-=25;
	}
	else MessageBox(L"�˼��Ѿ������˱������QAQ��");
}


void Clab2_1View::OnThick()
{
	// TODO: �ڴ���������������
	if(PenWidth<10)
		PenWidth+=2;
	else
		MessageBox(L"�˼��Ѿ��ܿ��˰�ι(#`O��)");
}


void Clab2_1View::OnThin()
{
	// TODO: �ڴ���������������
	if(PenWidth>1)
		PenWidth-=2;
	else
		MessageBox(L"�Ѿ���ôϸ���㻹Ҫ�˼�զ����~");
}




void Clab2_1View::OnShowtext()
{
	// TODO: �ڴ���������������
	CString str1;
	Clab2_1Doc *pDoc1=GetDocument();
	pDoc1->Get(str1);
	MessageBox(str1);
}
