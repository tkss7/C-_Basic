#include <iostream>
using namespace std;

/*
�迭�� �������� �Ҵ�޾�, ���� ������ �迭�� �����Ϸ��� �Ѵ�.
������ ���� ����Ǵ� �ڵ带 �ϼ��Ѵ�.

������
�迭ũ�� �Է� ? 5
1 ��° input ? 10
2 ��° input ? 20
3 ��° input ? 30
4 ��° input ? 40
5 ��° input ? 50

dArray �迭 ������
10, 20, 30, 40, 50,
======================
DynamicArray(const DynamicArray &ref)

dArray �迭 ������
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
			cout << i+1 << " ��° input ? ";
			cin >> *(arr + i);
		}
	}

	void ArrayOutput()
	{
		cout << "dArray �迭 ������" << endl;
		for (int i = 0; i < len; i++)
			cout << *(arr + i) << ", ";
		cout << endl;
	}

	
};

int main()
{
	int size;

	cout << "�迭ũ�� �Է� ? ";
	cin >> size;

	DynamicArray dArray1(size);
	dArray1.ArrayInput();
	dArray1.ArrayOutput();
	cout << "======================" << endl;

	DynamicArray dArray2(dArray1);
	dArray2.ArrayOutput();

	return 0;
}