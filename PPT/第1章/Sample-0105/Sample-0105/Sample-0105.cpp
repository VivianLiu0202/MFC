// Sample-0105.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

class oper
{
	int x;
public:
	oper(int x0=0)
	{
		x=x0;
	}
	oper operator+(oper);
	void display()
	{
		std::cout<<"x+y="<<x<<"\n";
	}
};
oper oper::operator+(oper a)
{
	oper b;
	b.x=x+a.x;
	return b;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int m, n;
	std::cout<<"Input x and y: ";
	std::cin>>m>>n;
	oper x(m), y(n), z;
	z=x+y;
	z.display();
	return 0;
}

