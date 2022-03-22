#include <iostream>
using namespace std;

/*
다음과 같이 실행하기 위한 코드를 완성하시오.

실행결과
현재 접속자 :  0
1번째 Kim 로그인
2번째 Lee 로그인
3번째 Han 로그인
이름: Han, 나이: 19, count: 3
4번째 Park 로그인
이름: Park, 나이: 40, count: 4
===================
4번째 Park 로그아웃
현재 접속자 :  3

4번째 Uk 로그인
이름: Uk, 나이: 30, count: 4
4번째 Uk 로그아웃
3번째 Han 로그아웃
2번째 Lee 로그아웃
1번째 Kim 로그아웃
*/
class Person
{
	char name[20];
	int age;
	static int count; //정적 멤버
	 
public:
	Person(const char *_name, int _age)
	{
		strcpy(name, _name);
		age = _age;
		count++;
		cout << count << "번째 " << name << " 로그인" << endl;
	}
	~Person()
	{
		cout << count << "번째 " << name << " 로그아웃" << endl;
		count--;

	}

	void ShowData()
	{
		cout << "이름: " << name << ", 나이: " << age;
		cout << ", count: " << count << endl;
	}

	//정적함수 생성
	static void Countte()  //정적함수
	{
		cout << "현재 접속자 :  " << count << endl;
	}
};

// main() 함수가호출되기전에가장먼저할당된다.  
int Person::count = 0; // static 멤버초기화, 메모리할당(Data Segment)

// 전역함수 생성
void FuncA()
{
	Person tmp("Park", 40);
	tmp.ShowData();   
	cout << "===================" << endl;
}

int main()
{
	Person::Countte();   
 
	Person p1("Kim", 13);
	Person p2("Lee", 22);
	Person p3("Han", 19);

	p3.ShowData();    
 
	FuncA(); 

	p3.Countte(); //현재 접속자 : 3

	Person p4("Uk", 30);   
	p4.ShowData();

	return 0;
}
