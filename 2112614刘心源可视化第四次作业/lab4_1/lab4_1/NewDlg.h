#pragma once

#include "Student.h";
// CNewDlg 对话框

class CNewDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CNewDlg)

public:
	CNewDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CNewDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_CtrlList;

	CString m_ethnic;
	CString m_origin;
	CString m_name;

	CString m_id;
	CString m_age;

public:
	POSITION m_pos;
	CTypedPtrList <CObList,CStudent*> *m_pDataList;

public:
	CString m_major;

public:
	afx_msg void OnClickedAdd();
	int m_majorID;
	CString m_sex;
	afx_msg void OnClickedClose();
	CSpinButtonCtrl m_CtrlSpin;
	CComboBox m_CtrlSex;

	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedSelectimage();
	CStatic m_CtrlImage;
public:
	CTypedPtrList <CObList,CStudent*> * getList();
	CString imageStr_now;
	afx_msg void OnPaint();
	afx_msg void OnBnClickedCs();
	afx_msg void OnBnClickedPythics();
	afx_msg void OnBnClickedChemical();
	afx_msg void OnBnClickedMath();
};
