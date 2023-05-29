
// lab4_2Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "lab4_2.h"
#include "lab4_2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
public:
	CButton m_btnOK;
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDOK, m_btnOK);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Clab4_2Dlg �Ի���




Clab4_2Dlg::Clab4_2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Clab4_2Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	expression = _T("");
	errorMessage = _T("");
	m_screen = _T("");
}

void Clab4_2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_screen);
	DDV_MaxChars(pDX, m_screen, 50);
	DDX_Control(pDX, IDC_EDIT1, m_controlScreen);
}

BEGIN_MESSAGE_MAP(Clab4_2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_MOD, &Clab4_2Dlg::OnBnClickedMod)
	ON_BN_CLICKED(IDC_0, &Clab4_2Dlg::OnBnClicked0)
	ON_BN_CLICKED(IDC_1, &Clab4_2Dlg::OnBnClicked1)
	ON_BN_CLICKED(IDC_2, &Clab4_2Dlg::OnBnClicked2)
	ON_BN_CLICKED(IDC_3, &Clab4_2Dlg::OnBnClicked3)
	ON_BN_CLICKED(IDC_4, &Clab4_2Dlg::OnBnClicked4)
	ON_BN_CLICKED(IDC_5, &Clab4_2Dlg::OnBnClicked5)
	ON_BN_CLICKED(IDC_6, &Clab4_2Dlg::OnBnClicked6)
	ON_BN_CLICKED(IDC_7, &Clab4_2Dlg::OnBnClicked7)
	ON_BN_CLICKED(IDC_8, &Clab4_2Dlg::OnBnClicked8)
	ON_BN_CLICKED(IDC_9, &Clab4_2Dlg::OnBnClicked9)
	ON_BN_CLICKED(IDC_DIV, &Clab4_2Dlg::OnBnClickedDiv)
	ON_BN_CLICKED(IDC_MULTI, &Clab4_2Dlg::OnBnClickedMulti)
	ON_BN_CLICKED(IDC_DEC, &Clab4_2Dlg::OnBnClickedDec)
	ON_BN_CLICKED(IDC_ADD, &Clab4_2Dlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_POW, &Clab4_2Dlg::OnBnClickedPow)
	ON_BN_CLICKED(IDC_LEFT, &Clab4_2Dlg::OnBnClickedLeft)
	ON_BN_CLICKED(IDC_RIGHT, &Clab4_2Dlg::OnBnClickedRight)
	ON_BN_CLICKED(IDC_POINT, &Clab4_2Dlg::OnBnClickedPoint)
	ON_BN_CLICKED(IDC_RESET, &Clab4_2Dlg::OnBnClickedReset)
	ON_BN_CLICKED(IDC_DELETE, &Clab4_2Dlg::OnBnClickedDelete)
	ON_BN_CLICKED(IDC_EQUAL, &Clab4_2Dlg::OnBnClickedEqual)
END_MESSAGE_MAP()


// Clab4_2Dlg ��Ϣ�������

BOOL Clab4_2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void Clab4_2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Clab4_2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
		// �����ڴ��豸������
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR Clab4_2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void Clab4_2Dlg::OnBnClickedMod()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	expression=m_screen;
	m_screen=m_screen+'%';
	UpdateData(false);
}



void Clab4_2Dlg::OnBnClicked0()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	expression=m_screen;
	m_screen=m_screen+'0';
	UpdateData(false);
}


void Clab4_2Dlg::OnBnClicked1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	expression=m_screen;
	m_screen=m_screen+'1';
	UpdateData(false);
}

void Clab4_2Dlg::OnBnClicked2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	expression=m_screen;
	m_screen=m_screen+'2';
	UpdateData(false);
}




void Clab4_2Dlg::OnBnClicked3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	expression=m_screen;
	m_screen=m_screen+'3';
	UpdateData(false);

}


void Clab4_2Dlg::OnBnClicked4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	expression=m_screen;
	m_screen=m_screen+'4';
	UpdateData(false);
}



void Clab4_2Dlg::OnBnClicked5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	expression=m_screen;
	m_screen=m_screen+'5';
	UpdateData(false);
}



void Clab4_2Dlg::OnBnClicked6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	expression=m_screen;
	m_screen=m_screen+'6';
	UpdateData(false);
}



void Clab4_2Dlg::OnBnClicked7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	expression=m_screen;
	m_screen=m_screen+'7';
	UpdateData(false);
}



void Clab4_2Dlg::OnBnClicked8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	expression=m_screen;
	m_screen=m_screen+'8';
	UpdateData(false);
}



void Clab4_2Dlg::OnBnClicked9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	expression=m_screen;
	m_screen=m_screen+'9';
	UpdateData(false);
}


void Clab4_2Dlg::OnBnClickedDiv()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	expression=m_screen;
	m_screen=m_screen+'/';
	UpdateData(false);
}


void Clab4_2Dlg::OnBnClickedMulti()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	expression=m_screen;
	m_screen=m_screen+'*';
	UpdateData(false);
}


void Clab4_2Dlg::OnBnClickedDec()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	expression=m_screen;
	m_screen=m_screen+'-';
	UpdateData(false);
}




void Clab4_2Dlg::OnBnClickedAdd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	expression=m_screen;
	m_screen=m_screen+'+';
	UpdateData(false);
}


void Clab4_2Dlg::OnBnClickedPow()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	expression=m_screen;
	m_screen=m_screen+'^';
	UpdateData(false);
}



void Clab4_2Dlg::OnBnClickedLeft()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	expression=m_screen;
	m_screen=m_screen+'(';
	UpdateData(false);
}


void Clab4_2Dlg::OnBnClickedRight()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	expression=m_screen;
	m_screen=m_screen+')';
	UpdateData(false);
}



void Clab4_2Dlg::OnBnClickedPoint()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	expression=m_screen;
	m_screen=m_screen+'.';
	UpdateData(false);
}


void Clab4_2Dlg::OnBnClickedReset()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_screen="";
	expression=m_screen;
	UpdateData(false);
}


void Clab4_2Dlg::OnBnClickedDelete()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_screen.Delete(m_screen.GetLength()-1);
	expression=m_screen;
	UpdateData(false);
}


void Clab4_2Dlg::OnBnClickedEqual()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	expression=m_screen;
	//��������м��
	CString copy=expression;
	checkStr(copy);


	if(errorMessage.IsEmpty()){
		if(expression!=L""){
			//��ȷ�����룬ִ�м���������
			double result = EvaluateExpression(expression);
			CString resultString;
			resultString.Format(_T("%.2f"), result);

			MessageBox(resultString.GetString(),_T("message"), MB_OK | MB_ICONINFORMATION);
			resultString="";
		}
	}
	else{
		MessageBox(errorMessage.GetString(),_T("message"), MB_OK | MB_ICONINFORMATION);
		errorMessage="";
	}
}



void Clab4_2Dlg::checkStr(const CString& str){
	int leftBracketCount=0;
	int rightBracketCount=0;

	
	for(int i = 0; i < str.GetLength() ; i++)
	{
		if (str.GetAt(i) == '(')
		{
			leftBracketCount++;
		}
		if (str.GetAt(i) == ')')
		{
			rightBracketCount++;
		}
	}
	/*CString resultString;
	resultString.Format(_T("%.2d"),leftBracketCount );

	MessageBox(resultString.GetString(),_T("message"), MB_OK | MB_ICONINFORMATION);*/
	//MessageBox()
	if (leftBracketCount != rightBracketCount)
	{
		errorMessage = _T("���Ų�ƥ��");
	}
	else
	{
    // ������ŷǿ�
		CString emptyBracket=L"()";
		if (str.Find(emptyBracket)!=-1)
		{
			errorMessage = _T("�����в���û���ַ�");
		}
		else
		{
        // ��������Դ���
			CString operators = _T("+-*/^%");
			CString digits = _T("0123456789");
			int expressionLength = str.GetLength();
			for (int i = 0; i < expressionLength - 1; ++i)
			{
				char currentChar = str.GetAt(i);
				char nextChar = str.GetAt(i + 1);

				if (operators.Find(currentChar) != -1 && operators.Find(nextChar) != -1)
				{
					errorMessage = _T("������������������");
					break;
				}
			}
			// ������Ϊ�����
			if (str.Find(_T("/0")) != -1)
			{
				if(str.Find(_T("/0.")) == -1){
					errorMessage = _T("��������Ϊ��");
				}
			}
		}
	}
}

bool Clab4_2Dlg::IsOperator(char ch){
	return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '%';
}

int Clab4_2Dlg::GetPrecedence(char ch){
	if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/' || ch == '%')
        return 2;
    if (ch == '^')
        return 3;
    return 0;
}

double Clab4_2Dlg::ApplyOperator(double operand1, double operand2, char op){
	switch (op)
    {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
        case '^':
            return pow(operand1, operand2);
        case '%':
            return fmod(operand1, operand2);
    }
    return 0.0;
}

double Clab4_2Dlg::EvaluateExpression(const CString& expression){
	std::stack<double> operandStack;
    std::stack<char> operatorStack;

    CString str = expression;
    str.Remove(' ');

    int len = str.GetLength();
    for (int i = 0; i < len; ++i)
    {
        char ch = str.GetAt(i);

        if (ch == '(')
        {
            operatorStack.push(ch);
        }
        else if (isdigit(ch) || ch == '.')
        {
            CString numString;
            while (i < len && (isdigit(str.GetAt(i)) || str.GetAt(i) == '.'))
            {
                numString += str.GetAt(i);
                ++i;
            }
            --i;

            double operand = _ttof(numString);
            operandStack.push(operand);
        }
        else if (IsOperator(ch))
        {
            while (!operatorStack.empty() && operatorStack.top() != '(' &&
                   GetPrecedence(operatorStack.top()) >= GetPrecedence(ch))
            {
                double operand2 = operandStack.top();
                operandStack.pop();

                double operand1 = operandStack.top();
                operandStack.pop();

                char op = operatorStack.top();
                operatorStack.pop();

                double result = ApplyOperator(operand1, operand2, op);
                operandStack.push(result);
            }

            operatorStack.push(ch);
        }
        else if (ch == ')')
        {
            while (!operatorStack.empty() && operatorStack.top() != '(')
            {
                double operand2 = operandStack.top();
                operandStack.pop();

                double operand1 = operandStack.top();
                operandStack.pop();

                char op = operatorStack.top();
                operatorStack.pop();

                double result = ApplyOperator(operand1, operand2, op);
                operandStack.push(result);
            }

            if (!operatorStack.empty() && operatorStack.top() == '(')
                operatorStack.pop();  // ����������
        }
    }

    while (!operatorStack.empty())
    {
        double operand2 = operandStack.top();
        operandStack.pop();

        double operand1 = operandStack.top();
        operandStack.pop();

        char op = operatorStack.top();
        operatorStack.pop();

        double result = ApplyOperator(operand1, operand2, op);
        operandStack.push(result);
    }

    return operandStack.top();
}


