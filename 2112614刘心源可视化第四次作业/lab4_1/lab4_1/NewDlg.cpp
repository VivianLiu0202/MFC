// NewDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "lab4_1.h"
#include "NewDlg.h"
#include "afxdialogex.h"


// CNewDlg �Ի���

IMPLEMENT_DYNAMIC(CNewDlg, CDialogEx)

CNewDlg::CNewDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CNewDlg::IDD, pParent)
{

	m_majorID=1;
	m_major=L"�����ѧԺ";
	imageStr_now=L"";


	m_ethnic = _T("");
	m_origin = _T("");
	m_name = _T("");

	m_id = _T("");
	m_age = _T("");
	m_majorID = 0;
	m_sex = _T("");
}

CNewDlg::~CNewDlg()
{
}

void CNewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST, m_CtrlList);
	DDX_Text(pDX, IDC_ETHNIC, m_ethnic);
	DDV_MaxChars(pDX, m_ethnic, 20);
	DDX_Text(pDX, IDC_ORIGIN, m_origin);
	DDV_MaxChars(pDX, m_origin, 20);
	DDX_Text(pDX, IDC_NAME, m_name);
	DDV_MaxChars(pDX, m_name, 20);

	DDX_Text(pDX, IDC_ID, m_id);
	DDV_MaxChars(pDX, m_id, 20);
	DDX_Text(pDX, IDC_AGE, m_age);
	DDV_MaxChars(pDX, m_age, 20);
	DDX_Radio(pDX, IDC_XINAN, m_majorID);
	DDV_MinMaxInt(pDX, m_majorID, 0, 10);
	DDX_CBString(pDX, IDC_SEX, m_sex);
	DDV_MaxChars(pDX, m_sex, 20);
	DDX_Control(pDX, IDC_SPIN1, m_CtrlSpin);
	DDX_Control(pDX, IDC_SEX, m_CtrlSex);
	DDX_Control(pDX, IDC_IMAGE, m_CtrlImage);
}


BEGIN_MESSAGE_MAP(CNewDlg, CDialogEx)
	ON_BN_CLICKED(IDC_ADD, &CNewDlg::OnClickedAdd)
	ON_BN_CLICKED(IDC_CLOSE, &CNewDlg::OnClickedClose)
	ON_WM_CREATE()
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_SELECTIMAGE, &CNewDlg::OnBnClickedSelectimage)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_CS, &CNewDlg::OnBnClickedCs)
	ON_BN_CLICKED(IDC_PYTHICS, &CNewDlg::OnBnClickedPythics)
	ON_BN_CLICKED(IDC_CHEMICAL, &CNewDlg::OnBnClickedChemical)
	ON_BN_CLICKED(IDC_MATH, &CNewDlg::OnBnClickedMath)
END_MESSAGE_MAP()


// CNewDlg ��Ϣ�������


void CNewDlg::OnClickedAdd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	if(m_id.GetLength()==0) 
		{ MessageBox(L"ID cannot empty!");
		(CEdit*)GetDlgItem(IDC_ID)->SetFocus(); return; }
	if(m_name.GetLength()==0) 
		{ MessageBox(L"Name cannot empty!");
		(CEdit*)GetDlgItem(IDC_NAME)->SetFocus(); return; }
	CStudent *pStudent; //������׷�ӽ��
	pStudent=new CStudent(m_name,m_sex,m_age,m_ethnic,m_origin,m_id,m_major,imageStr_now);
	pStudent->imageStr=imageStr_now;
	m_pDataList->AddTail(pStudent);
	m_pos=m_pDataList->GetTailPosition();
	CString str; //��ListBox׷���ַ���
	str=m_name+"  "+m_sex+"  "+m_age+"  "+m_ethnic+"  "+m_origin+"  "+m_id+"  "+m_major; 
	m_CtrlList.AddString(str);
	m_CtrlList.SetCurSel(m_CtrlList.GetCount()-1);
}

void CNewDlg::OnClickedClose()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(MessageBox(L"Close Dialog?",L"Close",MB_OKCANCEL|MB_ICONQUESTION)==IDOK)
		CDialog::OnCancel();
}


int CNewDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	return 0;
}


BOOL CNewDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_CtrlSpin.SetRange(0,100);
	m_CtrlSpin.SetPos(20);
	 //����Ĭ��ѡ��
	m_name=L"Please input your name!";
	m_age=L"Please input your age!";
	m_ethnic=L"Please input your nation!";
	m_origin=L"Please input your address!";
	m_id=L"Please input your telephone!";
	 m_pDataList=new CTypedPtrList<CObList, CStudent*>;
	return TRUE;  
	// return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CNewDlg::OnBnClickedSelectimage()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);//Ҫ����仰�ѿؼ���ֵ�����������
	CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST, _T("Image Files (*.bmp;*.jpg;*.png)|*.bmp;*.jpg;*.png||"), this);

    if (dlg.DoModal() == IDOK)
    {
        CString m_strImagePath = dlg.GetPathName();
        UpdateData(FALSE);

        // �ھ�̬�ؼ�����ʾ��ѡͼƬ
		CImage temp;
		imageStr_now=m_strImagePath;
		CRect rect1;
		m_CtrlImage.GetClientRect(&rect1); 
		m_CtrlImage.GetDC()->FillSolidRect(rect1.left ,rect1.top ,rect1.Width(),rect1.Height(), RGB(255, 255, 255));
        
        if (temp.Load(m_strImagePath) == S_OK)
        {
			temp.Draw(m_CtrlImage.GetDC()->m_hDC,
			rect1.left,
			rect1.top,
			rect1.Width(),
			rect1.Height()); 
			temp.Destroy();
        }	
    }
	//��������Ĭ��ѡ��
	SetDlgItemText(IDC_NAME,m_name.GetBuffer());
	SetDlgItemText(IDC_AGE,m_age.GetBuffer());
	SetDlgItemText(IDC_ETHNIC,m_ethnic.GetBuffer());
	SetDlgItemText(IDC_ORIGIN,m_origin.GetBuffer());
	SetDlgItemText(IDC_ID,m_id.GetBuffer());
}

CTypedPtrList <CObList,CStudent*> *CNewDlg::getList(){
	return m_pDataList;
}

void CNewDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	//��������Ĭ��ѡ��
	SetDlgItemText(IDC_NAME,m_name.GetBuffer());
	SetDlgItemText(IDC_AGE,m_age.GetBuffer());
	SetDlgItemText(IDC_ETHNIC,m_ethnic.GetBuffer());
	SetDlgItemText(IDC_ORIGIN,m_origin.GetBuffer());
	SetDlgItemText(IDC_ID,m_id.GetBuffer());
}


void CNewDlg::OnBnClickedCs()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_majorID=1;
	m_major=L"�����ѧԺ";
}


void CNewDlg::OnBnClickedPythics()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_majorID=2;
	m_major=L"����ѧԺ";
}



void CNewDlg::OnBnClickedChemical()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_majorID=3;
	m_major=L"��ѧѧԺ";
}


void CNewDlg::OnBnClickedMath()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_majorID=4;
	m_major=L"��ѧѧԺ";
}
