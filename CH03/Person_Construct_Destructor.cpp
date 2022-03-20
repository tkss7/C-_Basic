//Person_Construct_Destructor.cpp 03/18 
#include<iostream>
#include<cstring>
#include<vld.h>
using namespace std;
/*
	로직 : 1. p2라는 Person클래스의 객체가 먼저 생성이 되고,
			2. 생성자	Person(const char* name2, const char* phone2, int age2)이 실행이된다
			3. 즉 생성자는 초기에 실행되는 함수와 같으므로 생성자 로직이 다 돈 후엔 생성자(함수)가 나올때 
			const char* name2, const char* phone2, int age2 의 메모리가 반환되며
			4. showData() 까지 실행 후 소멸자가 실행될 때 name과 phone에 저장된 동적할당을 먼저 삭제 후
			5. p2객체가 최종적으로 소멸된다.
*/
class Person
{
private:
	char* name; // 이렇게 하면 동적할당받겠다는 의미
	char* phone;
	int age;
public:
	Person() :Person("", "", 0) {} // 이렇게 이웃생성자를 사용하는게 바람직한 것임
	Person(const char* name2, const char* phone2, int age2)
	{
		name = new char[strlen(name2)+1]; //공백을 포함하기에 strlen +1 만큼 동적할당받아 name 포인터에 넣어줌, 
											// 이렇게 안하면 name포인터가 참조할 주소가 없으므로 strcpy를 하면 오류가 뜬다.
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
	Person  p2("KIM", "010-333-5555", 22); // 생성 후 객체가 소멸될 때 멤버들이 받은 동적할당은 그 때 해제해주고 소멸되게 해줘야한다.
	p2.ShowData();

	return 0;
}