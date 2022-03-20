//Person_Construct_Destructor.cpp 03/18 
#include<iostream>
#include<cstring>
#include<vld.h>
using namespace std;
/*
	���� : 1. p2��� PersonŬ������ ��ü�� ���� ������ �ǰ�,
			2. ������	Person(const char* name2, const char* phone2, int age2)�� �����̵ȴ�
			3. �� �����ڴ� �ʱ⿡ ����Ǵ� �Լ��� �����Ƿ� ������ ������ �� �� �Ŀ� ������(�Լ�)�� ���ö� 
			const char* name2, const char* phone2, int age2 �� �޸𸮰� ��ȯ�Ǹ�
			4. showData() ���� ���� �� �Ҹ��ڰ� ����� �� name�� phone�� ����� �����Ҵ��� ���� ���� ��
			5. p2��ü�� ���������� �Ҹ�ȴ�.
*/
class Person
{
private:
	char* name; // �̷��� �ϸ� �����Ҵ�ްڴٴ� �ǹ�
	char* phone;
	int age;
public:
	Person() :Person("", "", 0) {} // �̷��� �̿������ڸ� ����ϴ°� �ٶ����� ����
	Person(const char* name2, const char* phone2, int age2)
	{
		name = new char[strlen(name2)+1]; //������ �����ϱ⿡ strlen +1 ��ŭ �����Ҵ�޾� name �����Ϳ� �־���, 
											// �̷��� ���ϸ� name�����Ͱ� ������ �ּҰ� �����Ƿ� strcpy�� �ϸ� ������ ���.
		strcpy(name, name2);
		phone = new char[strlen(phone2)+1];
		strcpy(phone, phone2);
		age = age2;
	}

	~Person()
	{
		cout << "~Person() age: " << age << endl;
		delete name;
		delete phone;
	}

	void ShowData();
};

void Person::ShowData()
{
	cout << "name : " << name << ", phone : " << phone << ", age : " << age << endl;
}

int main()
{
	Person  p2("KIM", "010-333-5555", 22); // ���� �� ��ü�� �Ҹ�� �� ������� ���� �����Ҵ��� �� �� �������ְ� �Ҹ�ǰ� ������Ѵ�.
	p2.ShowData();

	return 0;
}