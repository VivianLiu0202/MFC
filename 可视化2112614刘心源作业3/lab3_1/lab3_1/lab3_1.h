
// lab3_1.h : lab3_1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// Clab3_1App:
// �йش����ʵ�֣������ lab3_1.cpp
//

class Clab3_1App : public CWinApp
{
public:
	Clab3_1App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Clab3_1App theApp;
