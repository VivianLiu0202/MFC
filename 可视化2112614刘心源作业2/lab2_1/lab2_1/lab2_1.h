
// lab2_1.h : lab2_1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// Clab2_1App:
// �йش����ʵ�֣������ lab2_1.cpp
//

class Clab2_1App : public CWinApp
{
public:
	Clab2_1App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Clab2_1App theApp;
