//���������_������_ȣ��.cpp
#include<iostream>
using namespace std;

class SoSimple
{
private:
	int salary;
public:

	SoSimple(int sal) { salary = sal; cout << "SoSimple() : " << endl;
	}
	SoSimple(const SoSimple& So)// ���������
	{
		this->salary = So.salary;
		cout << "SoSimple(cnost SoSimple &so) : " << salary << endl;
	}
	~SoSimple() {}
	
	void Simple1(SoSimple tmp)
	{
		cout << "Simple1(SoSimple tmp)" << endl;
		tmp.showData();
	}

	SoSimple Simple2()
	{
		SoSimple tmp(350000); //�����ڰ� �ҷ���
		return tmp; // ��������ڰ� �ҷ���
	}

	//void AddSudang(int sudang)
	//{
	//	salary += sudang;

	//}

	SoSimple& AddSudang(int sudang)
	{
		salary += sudang;
		return *this;
	}

	void showData()
	{
		cout << "salary : " << salary << endl;
	}
};

int main()
{
	SoSimple obj(2700000);
	
	//1. ��ü�� ������ ���ÿ� ��ü �ʱ�ȭ �� �� ��������ڰ� �ҷ���.
	SoSimple obj2(obj);

	obj2.showData();
	cout << "===================================" << endl;

	//2. ��ü�� �Լ��� ���ڷ� ���޵� �� ��������ڰ� �ҷ���.
	obj.Simple1(obj2);
	cout << "===================================" << endl;

	SoSimple obj3=obj.Simple2(); 
	obj3.showData();
	cout << "===================================" << endl;

	obj.AddSudang(200000).showData();// �����ڷ� ��ȯ�ϸ� �̷��� ����
	//obj.showData();

	return 0;
}