#include <iostream>
using namespace std;

/*
배열을 동적으로 할당받아, 같은 구조의 배열에 복사하려고 한다.
다음과 같이 실행되는 코드를 완성한다.

실행결과
배열크기 입력 ? 5
1 번째 input ? 10
2 번째 input ? 20
3 번째 input ? 30
4 번째 input ? 40
5 번째 input ? 50

dArray 배열 데이터
10, 20, 30, 40, 50,
======================
DynamicArray(const DynamicArray &ref)

dArray 배열 데이터
10, 20, 30, 40, 50,
~DynamicArray()
~DynamicArray()

*/

class DynamicArray
{
private:
	int* arr;
	int len;
public:
	DynamicArray(int _len) : len(_len)
	{
		arr = new int[_len];
	}
	~DynamicArray()
	{
		delete[] arr;
	}
	DynamicArray(DynamicArray &ref)
	{
		arr = new int[ref.len];
		len = ref.len;
		cout << "DynamicArray(const DynamicArray &ref)\n\n";

		for (int i = 0; i < len; i++)
			*(arr + i) = *(ref.arr + i);
	}
	void ArrayInput()
	{
		for (int i = 0; i < len; i++)
		{
			cout << i+1 << " 번째 input ? ";
			cin >> *(arr + i);
		}
	}

	void ArrayOutput()
	{
		cout << "dArray 배열 데이터" << endl;
		for (int i = 0; i < len; i++)
			cout << *(arr + i) << ", ";
		cout << endl;
	}

	
};

int main()
{
	int size;

	cout << "배열크기 입력 ? ";
	cin >> size;

	DynamicArray dArray1(size);
	dArray1.ArrayInput();
	dArray1.ArrayOutput();
	cout << "======================" << endl;

	DynamicArray dArray2(dArray1);
	dArray2.ArrayOutput();

	return 0;
}