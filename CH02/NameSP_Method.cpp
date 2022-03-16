//NameSP_Method.cpp
#include<iostream>
#include"NameSP.h"
using namespace std;
namespace BestCom
{
	void simpleFunc()
	{
		cout << "BestCom simpleFunc() \n";
		showMsg();
	}
	void showMsg()
	{
		cout << "BestCom Msg()() \n";
	}
}
namespace ProgCom
{
	void simpleFunc()
	{
		cout << "ProgCom simpleFunc() \n";
	}
}