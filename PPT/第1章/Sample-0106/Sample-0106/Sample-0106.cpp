// Sample-0106.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>

class base
{
public:
	virtual void display()
	{
		std::cout<<"Virtual function!"<<"\n";
	}
};
class derived: public base
{
public:
	void display()
	{
		std::cout<<"Derived display!"<<"\n";
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	base x;
	derived y;
	x.display();
	y.display();
	return 0;
}

