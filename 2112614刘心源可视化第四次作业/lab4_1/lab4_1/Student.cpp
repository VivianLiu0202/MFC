// Student.cpp : 实现文件
//

#include "stdafx.h"
#include "lab4_1.h"
#include "Student.h"


// CStudent

CStudent::CStudent(CString name,CString sex,CString age,CString ethnic,CString origin,CString id,CString major,CString imageStr){
	this->name=name;
	this->sex=sex;
	this->age=age;
	this->ethnic=ethnic;
	this->origin=origin;
	this->id=id;
	this->major=major;
	this->imageStr=imageStr;
}

CStudent::CStudent()
{
}

CStudent::~CStudent()
{
}


// CStudent 成员函数
