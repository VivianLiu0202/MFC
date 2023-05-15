// Sample-0103.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>

class station
{
	char from[20], to[20];
public:
	station(char f[], char t[])
	{
		strcpy_s(from, f);
		strcpy_s(to, t);
	}
	void input()
	{
		std::cout<<"Input from station: ";
		std::cin>>from;
		std::cout<<"Input to station: ";
		std::cin>>to;
	}
	void display()
	{
		std::cout<<"Going from station "<<from<<" to "<<to<<"\n";
	}
};
class mile
{
	int miles;
public:
	mile(int m)
	{
		miles=m;
	}
	void input()
	{
		std::cout<<"Input miles: ";
		std::cin>>miles;
	}
	void display()
	{
		std::cout<<"Miles between two station is "<<miles<<"\n";
	}
};
class price: public station, public mile
{
	int prices;
public:
	price(char ff[], char tt[], int mm, int p): station(ff,tt), mile(mm)
	{
		prices=p;
	}
	void input()
	{
		station::input();
		mile::input();
		std::cout<<"Input price: ";
		std::cin>>prices;
	}
	void display()
	{
		station::display();
		mile::display();
		std::cout<<"Prices is "<<prices<<"\n";
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	price obj("Tianjin", "Shanghai", 1000, 200);
	obj.display();
	return 0;
}

