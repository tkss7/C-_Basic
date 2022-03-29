//Index_Overloading2.cpp
#include<iostream>
#include<cstdlib> // exit 함수의 함수원형이 들어있음
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

	int& operator[](int index) // &반환 = 메모리를 반환
	{
		//cout << "&operator[](int index)" << endl;
		if (index < 0 || index >= 10)
		{
			cout << "배열첨자오류!!!" << endl;
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