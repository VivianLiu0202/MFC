// Sample-0104.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>

class maths
{
	int math;
public:
	void input()
	{
		std::cout<<"Input maths score: ";
		std::cin>>math;
	}
	void display()
	{
		std::cout<<"Maths score: "<<math<<"\n";
	}
};
class computer
{
	int comp;
public:
	void input()
	{
		std::cout<<"Input computer score: ";
		std::cin>>comp;
	}
	void display()
	{
		std::cout<<"Computer score: "<<comp<<"\n";
	}
};
class physics
{
	int phy;
public:
	void input()
	{
		std::cout<<"Input physics score: ";
		std::cin>>phy;
	}
	void display()
	{
		std::cout<<"Physicsr score: "<<phy<<"\n";
	}
};
class maths_computer: public maths, public computer
{
public:
	void input()
	{
		maths::input();
		computer::input();
	}
	void display()
	{
		maths::display();
		computer::display();
	}
};
class computer_physics: public computer, public physics
{
public:
	void input()
	{
		computer::input();
		physics::input();
	}
	void display()
	{
		computer::display();
		physics::display();
	}
};
class student: public maths_computer, public computer_physics
{
	char type[10], name[10];
	int eng;
public:
	void input()
	{
		std::cout<<"Input department type: ";
		std::cin>>type;
		std::cout<<"Input student name: ";
		std::cin>>name;		
		if(strcmp(type, "mc")==0)
			maths_computer::input();
		if(strcmp(type, "cp")==0)
			computer_physics::input();
		std::cout<<"Input english score: ";
		std::cin>>eng;
		std::cout<<"\n";
	}
	void display()
	{
		if(strcmp(type, "mc")==0)
		{
			std::cout<<"Maths and computer department"<<"\n";
			std::cout<<"Student name: "<<name<<"\n";
			maths_computer::display();
		}
		if(strcmp(type, "cp")==0)
		{
			std::cout<<"Computer and physics department"<<"\n";
			std::cout<<"Student name: "<<name<<"\n";
			computer_physics::display();
		}
		std::cout<<"English score: "<<eng<<"\n";
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	student obj;
	obj.input();
	obj.display();
	return 0;
}

