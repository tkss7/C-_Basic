//Default_Parameter_VectorClass.cpp
#include<iostream>
#include<vld.h>
using namespace std;
/*
������ ���� �����ϰ� ���α׷��� �ϼ��Ͻÿ�

1, 2, 3, 4, 5, 6, 7, 8, 9 10, => �� : 55
1, ... 20, => �� : 
*/
class MyVector
{
private:
	int* p;
	int size;
	int sum;
public:
	MyVector(int n = 10):sum(0)// �̷��� ����Ʈ ���ڸ� ����ϸ� ���ȣ �����ڰ� �ʿ����
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
		cout << "=> �� : " << sum << endl;
	}

};

int main()
{
	MyVector* v1 = new MyVector(); // �� ���� p�� �� ���� �Ҵ�� �迭�� �ּҸ� �����ִ� ����
	MyVector* v2;
	v2 = new MyVector(20);

	v1->MyVector_data();
	v1->MyVetcor_sum();

	v2->MyVector_data(); //�����͸� ä��
	v2->MyVetcor_sum(); // ������ �����鼭 ����

	delete v1; // delete�� v1�� ����Ű�� �����Ҵ� �� ��ü�� ��ȯ�ϱ� ����,
				// MyVector�� ��ü �Ҹ��ڰ� ����ȴ� -> :  delete[] p ���� �� -> delete v1 ����!!!!!
	delete v2;

	return 0;
}