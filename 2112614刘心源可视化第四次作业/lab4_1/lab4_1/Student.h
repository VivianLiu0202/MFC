#pragma once

// CStudent ÃüÁîÄ¿±ê

class CStudent : public CObject
{
public:
	CStudent();
	CStudent(CString name,CString sex,CString age,CString ethnic,CString origin,CString id,CString major,CString imageStr);

	virtual ~CStudent();
public:
	CString name;
	CString sex;
	CString age;
	CString ethnic;
	CString origin;
	CString id;
	CString major;
	CString imageStr;
};


