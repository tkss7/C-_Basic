#include <iostream>
using namespace std;
/*
A Ŭ������ ���۷����� �����ϴ� ����� ��� ��ü�̰�, 
AŬ���� Ÿ�Գ��� ����� ����� ��ӵ� Ŭ�������� ������ �����Ѵ�.
*/

//1.Ŭ���� ����
class Person
{
public:
	void Sleep(){ 
		cout<<"Sleep"<<endl;
	}
};

class Student : public Person
{
public:
	void Study(){
		cout<<"Study"<<endl;
	}
};

class PartTimeStd : public Student
{
public:
	void Work(){
		cout<<"Work"<<endl;
	}
};

int main()
{
//2. 
	//��ü�� �����ϴ� ���۷����� ����
    //Ŭ���� �������� ���Ѱ� ��ġ!
	PartTimeStd pt;
	Student &Sref1=pt;
	Person &Pref2=pt;
	
	pt.Sleep();  //�� �޼��� ��� ȣ�Ⱑ��
	Sref1.Sleep();  //sleep,  study �� ����
	Pref2.Sleep();  //sleep  �� ����
	
	//Pref2.Study(); // Error�� ����, Ŭ���������� ���Ѱ� ��ġ
	//Pref2.Work();  // Error�� 
	//Pref2.PartTimeStd::Work(); // Error

	return 0;
}