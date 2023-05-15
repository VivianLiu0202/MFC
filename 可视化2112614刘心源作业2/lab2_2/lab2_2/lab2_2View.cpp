
// lab2_2View.cpp : Clab2_2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_TEST, &Clab2_2View::OnTest)
	ON_COMMAND(ID_FONT, &Clab2_2View::OnFont)
END_MESSAGE_MAP()

// Clab2_2View ����/����

Clab2_2View::Clab2_2View()
{
	// TODO: �ڴ˴���ӹ������
	string="";
}

Clab2_2View::~Clab2_2View()
{
}

BOOL Clab2_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
	return CView::PreCreateWindow(cs);
}

// Clab2_2View ����

void Clab2_2View::OnDraw(CDC* pDC)
{
	Clab2_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDoc->Get(string);
	pDC->TextOutW(100,400,string);
}


// Clab2_2View ��ӡ

BOOL Clab2_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Clab2_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Clab2_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Clab2_2View ���

#ifdef _DEBUG
void Clab2_2View::AssertValid() const
{
	CView::AssertValid();
}

void Clab2_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Clab2_2Doc* Clab2_2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Clab2_2Doc)));
	return (Clab2_2Doc*)m_pDocument;
}
#endif //_DEBUG


// Clab2_2View ��Ϣ�������


void Clab2_2View::OnTest()
{
	// TODO: �ڴ���������������
	MyDialog dlg;
	dlg.DoModal();
	CDC* pDC=GetDC();
	pDC->TextOutW(100,400,dlg.str);;
	string=dlg.str;
	Clab2_2Doc *pDoc=GetDocument();
	pDoc->SetStr((string));//��temp����Clab2_1Doc�ı���str�У����������ĵ���д
}


void Clab2_2View::OnFont()
{
	// TODO: �ڴ���������������
	
	CFontDialog fdlg(&m_Lofont);
	fdlg.m_cf.rgbColors = m_CurrentCr;
	fdlg.m_cf.Flags |= CF_USESTYLE;
	if (fdlg.DoModal() == IDOK)
	{
		fdlg.GetCurrentFont(&m_Lofont);
		m_CurrentCr = fdlg.GetColor();
	}
}
