// Sample-0102.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

class student
{
	char name[10];
	int eng, math;
public:
	void input()
	{
		std::cout<<"Input student name: ";
		std::cin>>name;
		std::cout<<"Input english score: ";
		std::cin>>eng;
		std::cout<<"Input math score: ";
		std::cin>>math;
	}
	void display()
	{
		std::cout<<"Student name: "<<name<<"\n";
		std::cout<<"English score: "<<eng<<"\n";
		std::cout<<"Math score: "<<math<<"\n";
	}
};
class computer: public student
{
	int comp;
public:
	void input()
	{
		std::cout<<"Computer department\n";
		student::input();
		std::cout<<"Input computer score: ";
		std::cin>>comp;
		std::cout<<"\n";
	}
	void display()
	{
		std::cout<<"Computer department\n";
		student::display();
		std::cout<<"Computer score: "<<comp<<"\n\n";
	}
};
class physics: public student
{
	int phy;
public:
	void input()
	{
		std::cout<<"Physics department\n";
		student::input();
		std::cout<<"Input physics score: ";
		std::cin>>phy;
		std::cout<<"\n";
	}
	void display()
	{
		std::cout<<"Physics department\n";
		student::display();
		std::cout<<"Physics score: "<<phy<<"\n\n";
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	computer obj1;
	obj1.input();
	obj1.display();
	physics obj2;
	obj2.input();
	obj2.display();
	return 0;
}

