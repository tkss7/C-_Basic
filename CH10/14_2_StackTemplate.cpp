//14_2_StackTemplate.cpp 03/29
#include <iostream>
#include<string>
#include<vld.h>
using namespace std;

/*
	C, B, A
	50, 40, 30, 20, 10


	A, milti campus, sample
*/

template <typename T>
class Stack
{
private:
	int topIdx;   // ������ �Էµ� ��ġ�� �ε���.
	T* stackPtr;  // ���� ������.
	int size;
public:
	Stack(int len = 10);
	Stack(string s);
	~Stack();
	void Push(const T& pushValue);
	T Pop();
	int Get_topIdx();
};

template <typename T>
Stack<T>::Stack(int len)
{
	topIdx = -1;		// ���� �ε��� �ʱ�ȭ.
	stackPtr = new T[len];	// ������ ���� ���� �迭 ����.
	size = len;
}

//template <typename T>
//Stack<T>::Stack(string s)
//{
//	topIdx = -1;		// ���� �ε��� �ʱ�ȭ.
//	stackPtr = new T[s.length];	// ������ ���� ���� �迭 ����.
//	size = s.length;
//}

//���������� ����?
template <typename T>
Stack<T>::~Stack()
{
	delete[] stackPtr;
}

template <typename T>
void Stack<T>::Push(const T& pushValue)
{ // ���ÿ� ������ �Է�.

	if (topIdx >= (size - 1))
	{
		cout << "stack full !!!" << endl;
		return;
	}
	stackPtr[++topIdx] = pushValue;
}

template <typename T>
T Stack<T>::Pop()
{ // ���ÿ��� ������ ����.
	if (topIdx < 0)
	{
		cout << "stack empty !!!" << endl;
		return (T)0; //(T)32;
	}
	return stackPtr[topIdx--];
}

template <typename T>
int Stack<T>::Get_topIdx()
{
	return topIdx;
}

int main()
{
	Stack<char> stack1(10);
	stack1.Push('A');
	stack1.Push('B');
	stack1.Push('C');

	int size = stack1.Get_topIdx();
	for (int i = 0; i <= size; i++)
		cout << stack1.Pop() << " , ";
	cout << endl;

	Stack<int> stack2(10);
	stack2.Push(10);
	stack2.Push(20);
	stack2.Push(30);
	stack2.Push(40);
	stack2.Push(50);

	size = stack2.Get_topIdx();
	for (int j = 0; j <= size; j++)
		cout << stack2.Pop() << " , ";
	cout << endl;

	Stack<double> stack3(10);
	stack3.Push(10.1);
	stack3.Push(20.2);
	stack3.Push(30.3);
	stack3.Push(40.4);

	size = stack3.Get_topIdx();
	for (int j = 0; j <= size; j++)
		cout << stack3.Pop() << " , ";
	cout << endl;


	Stack<string> stack4(10);
	stack4.Push("multi ");
	stack4.Push("campus");
	stack4.Push("!!!");

	size = stack4.Get_topIdx();
	for (int j = 0; j <= size; j++)
		cout << stack4.Pop() << " , ";
	cout << endl;

	string s[3];

	s[0] = "sample";
	s[1] = ("multi campus");
	s[2] = ("A");
	cout << s[0] << ", " << s[1] << ", " << s[2] << endl;

	return 0;
}