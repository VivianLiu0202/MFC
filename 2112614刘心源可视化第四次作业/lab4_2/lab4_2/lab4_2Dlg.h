
// lab4_2Dlg.h : 头文件
//

#include <stack>
#include <string>
#include <sstream>
#include <cmath>

#pragma once


// Clab4_2Dlg 对话框
class Clab4_2Dlg : public CDialogEx
{
// 构造
public:
	Clab4_2Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_LAB4_2_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedMod();
	CString expression;
	CString errorMessage;
	CString m_screen;
	CEdit m_controlScreen;
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClicked0();
	afx_msg void OnBnClicked1();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClicked2();
	afx_msg void OnBnClicked3();
	afx_msg void OnBnClicked4();
	afx_msg void OnBnClicked5();
	afx_msg void OnBnClicked6();
	afx_msg void OnBnClicked7();
	afx_msg void OnBnClicked8();
	afx_msg void OnBnClicked9();	
	afx_msg void OnBnClickedDiv();
	afx_msg void OnBnClickedMulti();
	afx_msg void OnBnClickedDec();
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedPow();
	afx_msg void OnBnClickedLeft();
	afx_msg void OnBnClickedRight();
	afx_msg void OnBnClickedPoint();
	afx_msg void OnBnClickedReset();
	afx_msg void OnBnClickedDelete();

public:
	bool IsOperator(char ch);
	int GetPrecedence(char ch);
	double ApplyOperator(double operand1, double operand2, char op);
	double EvaluateExpression(const CString& expression);

	void checkStr(const CString& str);


	CStatic m_ctrlPicture;
	afx_msg void OnBnClickedEqual();
};
