//namespace_test.cpp

#include<iostream>
using namespace std;
namespace BestCom
{
	void showMsg(); //�Լ� ����
	//C++������ �׻� �޼ҵ带 ȣ���ϱ����� �����ؾ��Ѵ�.
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
/*
	:: �� �������� ������
	C++ : ���� ������� , �����ڵ� , ���θ޼ҵ� �� 3���� �и��Ѵ�.
*/
using namespace BestCom;
using namespace ProgCom;
int main()
{
	//simpleFunc();//���ӽ����̽� �ΰ��� �߱⿡ �浹�� ����. �̷��� �տ� ���ӽ����̽����� �ٿ��� �Ѵ�.
	BestCom::simpleFunc();// <== �̷���
	//BestCom::showMsg();
	showMsg();
	return 0;
}