//Default_Parameter_VectorClass.cpp
#include<iostream>
#include<vld.h>
using namespace std;
/*
다음과 같이 실행하고 프로그램을 완성하시오

1, 2, 3, 4, 5, 6, 7, 8, 9 10, => 합 : 55
1, ... 20, => 합 : 
*/
class MyVector
{
private:
	int* p;
	int size;
	int sum;
public:
	MyVector(int n = 10):sum(0)// 이렇게 디폴트 인자를 사용하면 빈괄호 생성자가 필요없음
	{
		cout << "MyVector : " << endl;
		p = new int[n];
		size = n;
	}

	~MyVector()
	{
		cout<<"~MyVector"<<endl;
		delete[] p;
	}

	void MyVector_data()
	{
		for (int i = 0; i < size; i++)
			*(p + i) = i + 1;
	}

	void MyVetcor_sum()
	{
		for (int i = 0; i < size; i++)
		{
			cout << *(p + i) << ", ";
			sum += *(p + i);
		}
		cout << "=> 합 : " << sum << endl;
	}

};

int main()
{
	MyVector* v1 = new MyVector(); // 힙 안의 p가 또 힙에 할당된 배열의 주소를 갖고있는 형태
	MyVector* v2;
	v2 = new MyVector(20);

	v1->MyVector_data();
	v1->MyVetcor_sum();

	v2->MyVector_data(); //데이터만 채움
	v2->MyVetcor_sum(); // 데이터 찍으면서 누적

	delete v1; // delete가 v1이 가리키는 동적할당 된 객체를 반환하기 직전,
				// MyVector의 객체 소멸자가 실행된다 -> :  delete[] p 실행 후 -> delete v1 실행!!!!!
	delete v2;

	return 0;
}