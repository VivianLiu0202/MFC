
// lab4_1View.cpp : Clab4_1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_OPENDLG, &Clab4_1View::OnOpendlg)
END_MESSAGE_MAP()

// Clab4_1View ����/����

Clab4_1View::Clab4_1View()
{
	// TODO: �ڴ˴���ӹ������

}

Clab4_1View::~Clab4_1View()
{
}

BOOL Clab4_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Clab4_1View ����

void Clab4_1View::OnDraw(CDC* /*pDC*/)
{
	Clab4_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Clab4_1View ��ӡ

BOOL Clab4_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Clab4_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Clab4_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Clab4_1View ���

#ifdef _DEBUG
void Clab4_1View::AssertValid() const
{
	CView::AssertValid();
}

void Clab4_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Clab4_1Doc* Clab4_1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Clab4_1Doc)));
	return (Clab4_1Doc*)m_pDocument;
}
#endif //_DEBUG


// Clab4_1View ��Ϣ�������


void Clab4_1View::OnOpendlg()
{
	// TODO: �ڴ���������������
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
			str0=L"��¼"+temp;
			str1=L"Name:"+pStudent->name+L";  ";
			str2=L"Sex:��"+pStudent->sex+L";  ";
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
