//hello.cpp
/*
*	function == method
	C��� : �������� ���α׷��� ���, �Լ��߽�, .c
	C++ : ��ü���� ���α׷��� ���, ��ü�߽�(C ����� superSet) , .cpp
		: C/C++ �����Ϸ�
	std : iostream�� ����� ��ü���� std��� namespace �� ���ǵǾ� �ִ�.
			std�� �ִ� cout, endl�� ����ϰڴ�
	namespace : �ڵ尡 �������� �������� ���� �̸��� �Լ����� ������ �浹�Ѵ�. �̸� �ذ��ϱ� ���� ������ ����� ���� namespace
	<< : ��½�Ʈ�� ������
	std::endl ==> \n �� ���� �ǹ���
	std::cout ==> ����� ���̺귯���� �ִ� �ܼ־ƿ�
*/
#include<iostream>
// ��, ��µ� �پ��� �޼��带 �����ϴ� ��ü���� ���̺귯���� �����ϴ� �������
int main()
{
	int num = 100;

	std::cout << "hellow world" << std::endl;
	std::cout << "���Ǵ�Ʈ\n";
	std::cout << "�ｺ�ɾ�" << std::endl;
	std::cout << "num : " << num << std::endl;
	std::cout << 'A' << "," << 3.14 << std::endl;

	return 0;
}