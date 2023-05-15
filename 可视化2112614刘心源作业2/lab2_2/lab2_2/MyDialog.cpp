// MyDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "lab2_2.h"
#include "MyDialog.h"
#include "afxdialogex.h"
#include<locale.h>


// MyDialog �Ի���

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


// MyDialog ��Ϣ�������


void MyDialog::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void MyDialog::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_EDIT1)->GetWindowText(str);  
	CDialog::OnOK();
}


void MyDialog::OnBnClickedReadfile()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void MyDialog::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strFilter,fileName;
	strFilter="Text Files(*.txt)|*.txt||";
	CFileDialog dlg(TRUE, NULL, NULL, OFN_EXPLORER|OFN_HIDEREADONLY|OFN_ENABLESIZING|OFN_FILEMUSTEXIST,strFilter);
	if(dlg.DoModal() == IDOK )//��ʾ���ļ��Ի���
	{
		fileName=dlg.GetPathName();
		CFile openfile(fileName,CFile::modeRead);//����CFile����
		DWORD length=(DWORD)openfile.GetLength();//��ȡ�ļ�����
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

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	::SetWindowTextA(m_hWnd,(LPCSTR)"����");
	CBitmap bitmap;
	//bitmap.LoadBitmapW(IDB_BITMAP1);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
