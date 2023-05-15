// MyDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "lab2_2.h"
#include "MyDialog.h"
#include "afxdialogex.h"
#include<locale.h>


// MyDialog 对话框

IMPLEMENT_DYNAMIC(MyDialog, CDialog)

MyDialog::MyDialog(CWnd* pParent /*=NULL*/)
	: CDialog(MyDialog::IDD, pParent)//,str(_T(""))
{
}

MyDialog::~MyDialog()
{
}

void MyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Edit1);
	DDX_Control(pDX, IDOK, m_Button1);
}


BEGIN_MESSAGE_MAP(MyDialog, CDialog)
	ON_EN_CHANGE(IDC_EDIT1, &MyDialog::OnEnChangeEdit1)
	ON_BN_CLICKED(IDOK, &MyDialog::OnBnClickedOk)
	ON_BN_CLICKED(IDC_READFILE, &MyDialog::OnBnClickedReadfile)
END_MESSAGE_MAP()


// MyDialog 消息处理程序


void MyDialog::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void MyDialog::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_EDIT1)->GetWindowText(str);  
	CDialog::OnOK();
}


void MyDialog::OnBnClickedReadfile()
{
	// TODO: 在此添加控件通知处理程序代码
}


void MyDialog::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strFilter,fileName;
	strFilter="Text Files(*.txt)|*.txt||";
	CFileDialog dlg(TRUE, NULL, NULL, OFN_EXPLORER|OFN_HIDEREADONLY|OFN_ENABLESIZING|OFN_FILEMUSTEXIST,strFilter);
	if(dlg.DoModal() == IDOK )//显示打开文件对话框
	{
		fileName=dlg.GetPathName();
		CFile openfile(fileName,CFile::modeRead);//构造CFile对象
		DWORD length=(DWORD)openfile.GetLength();//获取文件长度
		char *strText=new char[length+100];
		openfile.Read(strText,length);
		strText[length]='\0';
		SetWindowTextA(m_Edit1,(LPCSTR)strText);
		delete [] strText;
		openfile.Close();
	}
}


BOOL MyDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	::SetWindowTextA(m_hWnd,(LPCSTR)"测试");
	CBitmap bitmap;
	//bitmap.LoadBitmapW(IDB_BITMAP1);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
