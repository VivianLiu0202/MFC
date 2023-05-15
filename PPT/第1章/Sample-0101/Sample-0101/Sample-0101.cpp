// Sample-0101.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

class example
{
	int i;
public:
	int j;
	void input();
	void display();
};
void example::input()
{
	i=10;
}
void example::display()
{
	std::cout<<"i="<<i<<"\n";
}

int _tmain(int argc, _TCHAR* argv[])
{
	example obj;
	obj.input();
	obj.j=12;
	obj.display();
	std::cout<<"j="<<obj.j<<"\n";
	/*example *pp=new example;	
	pp->input();
	pp->j=12;
	pp->display();*/
	return 0;
}

