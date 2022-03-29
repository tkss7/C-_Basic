//Index_Overloading1.cpp
#include<iostream>
#include<cstdlib> // exit �Լ��� �Լ������� �������
using namespace std;

const int SZ = 3;

class Arr
{
private:
	int idx;
	int nArr[SZ];
public:
	Arr() :idx(0)
	{

	}

	int getIdx()
	{
		return idx;
	}

	int &operator[](int index) // &��ȯ = �޸𸮸� ��ȯ
	{
		cout << "&operator[](int index)" << endl;
		if (index < 0 || index >= SZ)
		{
			cout << "�迭÷�ڿ���!!!" << endl;
			exit(1);
		}
		idx = index;
		return nArr[index];
	}
};

int main()
{
	Arr arr;

	//�迭�� ��ҿ� ����
	//arr.operator[](0)
	arr[0] = 100;
	arr[1] = 200;
	arr[2] = 300;
	

	int idx = arr.getIdx();

	for (int i = 0; i <= idx; i++)
	{
		cout << arr[i] << endl;
	}
	  
	return 0;
}