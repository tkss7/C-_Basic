//Template_�Լ�_Intro.cpp
#include<iostream>
using namespace std;

//template Ű���� : ���ø��� ���ǵ��� �˸���.
//	T : �ڷ����� �������� �ʰڴ�.
// 

template <typename T> // �������� ��Ÿ���� �ش�. //���⼭�� int�� double�� �ΰ��� ��ǻ�Ͱ� ����� �ִ°�
//template <class T>  // typename �� class Ű���尡 �Ȱ��� ������ �Ϲ����� class�� ȥ���ɼ� �����Ƿ� typename ���°��� ������
T Add(T x, T y)
{
	return x + y;
}

//double Add(double x, double y)
//{
//	return x + y;
//}

int main()
{
	cout << Add(10, 20) << endl; // Add�Լ��� �ҷ����� int�� TŸ������ ������
	cout << Add<double>(1.1, 2.1) << endl; //type�� ���������ϴ�


	return 0;
}