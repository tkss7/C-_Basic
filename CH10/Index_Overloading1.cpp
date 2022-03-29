//Index_Overloading1.cpp
#include<iostream>
#include<cstdlib> // exit 함수의 함수원형이 들어있음
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

	int &operator[](int index) // &반환 = 메모리를 반환
	{
		cout << "&operator[](int index)" << endl;
		if (index < 0 || index >= SZ)
		{
			cout << "배열첨자오류!!!" << endl;
			exit(1);
		}
		idx = index;
		return nArr[index];
	}
};

int main()
{
	Arr arr;

	//배열의 요소에 접근
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