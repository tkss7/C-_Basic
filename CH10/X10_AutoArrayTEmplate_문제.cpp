#include <iostream>
#include <string>
using namespace std;

//1. ���ø� Ŭ���� ����,��ü�� �迭ó�� �����Ѵ�
//   ���� �ڷ������� �迭�� ����� Ŭ���� ���ø�, 

/*
10, 20, 30, 40,
5.1, 2.1,
multi, campus, ��Ƽķ�۽�,
*/

#define A_SIZE 10

template <typename T>
class AutoArray
{
private:
	int index;
	T* ptr;
public:
	AutoArray(T* t_ptr)
	{
		ptr = t_ptr;
		index = 0;
	}
	~AutoArray() { delete[] ptr; }

	int GetIdx()
	{
		return index;
	}
	T& operator[](int idx)
	{
		index = idx;
		return ptr[idx];
	}


};

int main()
{
	
	AutoArray<int> arrInt(new int[A_SIZE]);
	AutoArray<double> arrDouble(new double[A_SIZE]);
	AutoArray<string> arrStr(new string[A_SIZE]);


	arrInt[0] = 10;
	arrInt[1] = 20;
	arrInt[2] = 30;
	arrInt[3] = 40;

	arrDouble[0] = 5.1;
	arrDouble[1] = 2.1;

	arrStr[0] = "multi ";
	arrStr[1] = "campus";
	arrStr[2] = "��Ƽķ�۽�";


	int idx1, idx2, idx3;

	idx1 = arrInt.GetIdx();
	idx2 = arrDouble.GetIdx();
	idx3 = arrStr.GetIdx();

	for (int i = 0; i <= idx1; i++)
		cout << arrInt[i] << ", ";
	cout << endl;

	for (int i = 0; i <= idx2; i++)
		cout << arrDouble[i] << ", ";
	cout << endl;

	for (int i = 0; i <= idx3; i++)
		cout << arrStr[i] <<  endl;
	cout << endl;

	return 0;
}
