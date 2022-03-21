//복사생성자_묵시적_호출.cpp
#include<iostream>
using namespace std;

class SoSimple
{
private:
	int salary;
public:

	SoSimple(int sal) { salary = sal; cout << "SoSimple() : " << endl;
	}
	SoSimple(const SoSimple& So)// 복사생성자
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
		SoSimple tmp(350000); //생성자가 불려짐
		return tmp; // 복사생성자가 불려짐
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
	
	//1. 객체가 생성과 동시에 객체 초기화 될 때 복사생성자가 불려짐.
	SoSimple obj2(obj);

	obj2.showData();
	cout << "===================================" << endl;

	//2. 객체가 함수의 인자로 전달될 때 복사생성자가 불려짐.
	obj.Simple1(obj2);
	cout << "===================================" << endl;

	SoSimple obj3=obj.Simple2(); 
	obj3.showData();
	cout << "===================================" << endl;

	obj.AddSudang(200000).showData();// 참조자로 반환하면 이렇게 가능
	//obj.showData();

	return 0;
}