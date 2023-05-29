// NewDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "lab4_1.h"
#include "NewDlg.h"
#include "afxdialogex.h"


// CNewDlg 对话框

IMPLEMENT_DYNAMIC(CNewDlg, CDialogEx)

CNewDlg::CNewDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CNewDlg::IDD, pParent)
{

	m_majorID=1;
	m_major=L"计算机学院";
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


// CNewDlg 消息处理程序


void CNewDlg::OnClickedAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	if(m_id.GetLength()==0) 
		{ MessageBox(L"ID cannot empty!");
		(CEdit*)GetDlgItem(IDC_ID)->SetFocus(); return; }
	if(m_name.GetLength()==0) 
		{ MessageBox(L"Name cannot empty!");
		(CEdit*)GetDlgItem(IDC_NAME)->SetFocus(); return; }
	CStudent *pStudent; //向链表追加结点
	pStudent=new CStudent(m_name,m_sex,m_age,m_ethnic,m_origin,m_id,m_major,imageStr_now);
	pStudent->imageStr=imageStr_now;
	m_pDataList->AddTail(pStudent);
	m_pos=m_pDataList->GetTailPosition();
	CString str; //向ListBox追加字符串
	str=m_name+"  "+m_sex+"  "+m_age+"  "+m_ethnic+"  "+m_origin+"  "+m_id+"  "+m_major; 
	m_CtrlList.AddString(str);
	m_CtrlList.SetCurSel(m_CtrlList.GetCount()-1);
}

void CNewDlg::OnClickedClose()
{
	// TODO: 在此添加控件通知处理程序代码
	if(MessageBox(L"Close Dialog?",L"Close",MB_OKCANCEL|MB_ICONQUESTION)==IDOK)
		CDialog::OnCancel();
}


int CNewDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	return 0;
}


BOOL CNewDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_CtrlSpin.SetRange(0,100);
	m_CtrlSpin.SetPos(20);
	 //设置默认选项
	m_name=L"Please input your name!";
	m_age=L"Please input your age!";
	m_ethnic=L"Please input your nation!";
	m_origin=L"Please input your address!";
	m_id=L"Please input your telephone!";
	 m_pDataList=new CTypedPtrList<CObList, CStudent*>;
	return TRUE;  
	// return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CNewDlg::OnBnClickedSelectimage()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);//要加这句话把控件中值传到类变量中
	CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST, _T("Image Files (*.bmp;*.jpg;*.png)|*.bmp;*.jpg;*.png||"), this);

    if (dlg.DoModal() == IDOK)
    {
        CString m_strImagePath = dlg.GetPathName();
        UpdateData(FALSE);

        // 在静态控件中显示所选图片
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
	//重新设置默认选项
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
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
	//重新设置默认选项
	SetDlgItemText(IDC_NAME,m_name.GetBuffer());
	SetDlgItemText(IDC_AGE,m_age.GetBuffer());
	SetDlgItemText(IDC_ETHNIC,m_ethnic.GetBuffer());
	SetDlgItemText(IDC_ORIGIN,m_origin.GetBuffer());
	SetDlgItemText(IDC_ID,m_id.GetBuffer());
}


void CNewDlg::OnBnClickedCs()
{
	// TODO: 在此添加控件通知处理程序代码
	m_majorID=1;
	m_major=L"计算机学院";
}


void CNewDlg::OnBnClickedPythics()
{
	// TODO: 在此添加控件通知处理程序代码
	m_majorID=2;
	m_major=L"物理学院";
}



void CNewDlg::OnBnClickedChemical()
{
	// TODO: 在此添加控件通知处理程序代码
	m_majorID=3;
	m_major=L"化学学院";
}


void CNewDlg::OnBnClickedMath()
{
	// TODO: 在此添加控件通知处理程序代码
	m_majorID=4;
	m_major=L"数学学院";
}
