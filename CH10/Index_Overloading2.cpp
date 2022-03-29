//Index_Overloading2.cpp
#include<iostream>
#include<cstdlib> // exit �Լ��� �Լ������� �������
using namespace std;



class AutoArray
{
private:
	int idx;
	int *arrPtr;
public:
	AutoArray(int *ptr) 
	{
		idx = 0;
		arrPtr = ptr;
	}
	~AutoArray()
	{
		delete[] arrPtr;
	}
	int getIdx()
	{
		return idx;
	}

	int& operator[](int index) // &��ȯ = �޸𸮸� ��ȯ
	{
		//cout << "&operator[](int index)" << endl;
		if (index < 0 || index >= 10)
		{
			cout << "�迭÷�ڿ���!!!" << endl;
			exit(1);
		}
		idx = index;
		return arrPtr[index];
	}
};

int main()
{
	AutoArray arr(new int[10]);

	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	arr[3] = 40;

	int idx = arr.getIdx();

	for (int i = 0; i <= idx; i++)
	{
		cout << arr[i] << endl;
	}
}