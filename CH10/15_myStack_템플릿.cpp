#include "vld.h"" //03/ 29 �����ʿ�!!!
#include <iostream>
using namespace std;

template <class T>  
class MyStack
{
	int top;     // top of stack
	T data[10]; // T Ÿ���� �迭. ������ ũ��� 100
public:
	MyStack();
	void push(T element); //T Ÿ�� ���� element�� data [] �迭�� ����
	T pop();    //  ������ ž�� �ִ� �����͸� data[] �迭���� ����

	int Get_topIdx()
	{
		return top;
	}
};

template <class T>
MyStack<T>::MyStack() // ������
{
	top = -1; // ������ ��� ����
}

template <class T>
void MyStack<T>::push(T element)
{
	if (top == 99) {
		cout << "stack full";
		return;
	}
	top++;
	data[top] = element;
}

template <class T>
T MyStack<T>::pop()
{
	T retData;
	if (top == -1)
	{
		cout << "stack empty";
		return 0; // ���� ǥ��
	}
	retData = data[top--];
	return retData;
}

class Point
{
	int x, y;
public:
	Point(int x = 0, int y = 0) { this->x = x; this->y = y; }
	void show() { cout << '(' << x << ',' << y << ')' << endl; }

};

int main()
{
	int size, i;

	cout << "====== MyStack<int *> ipStack =========" << endl;

	MyStack<int*> ipStack; // int* ���� �����ϴ� ����

	int* p = new int[5];
	for (i = 0; i < 3; i++)
		p[i] = i * 10; // 0, 10, 20���� �ʱ�ȭ
	p[i] = -99999;
	ipStack.push(p); // ������ Ǫ��

	p = new int[5];
	for (i = 0; i < 4; i++)
		p[i] = (i + 1) * 100; // 100, 200,300,400���� �ʱ�ȭ
	p[i] = -99999;
	ipStack.push(p); // ������ Ǫ��

	size = ipStack.Get_topIdx();
	int* q;
	for (i = 0; i <= size; i++)
	{
		q = ipStack.pop(); // ������ ��
		for (int j = 0; j < 5; j++)
			if (q[j] != -99999)
				cout << q[j] << ' '; // ȭ�� ���
			else
				break;
		cout << endl;
		delete[] q;
	}

	cout << "====== MyStack<Point> pointStack ===========" << endl;

	MyStack<Point> pointStack; // Point ��ü�� �����ϴ� ����

	Point a(1, 1), tmp;  //��ü����

	pointStack.push(a); // Point ��ü a Ǫ��. ����Ǿ� ���� 
	Point b(1, 2);
	pointStack.push(b);// Point ��ü b Ǫ��. ����Ǿ� ���� 
	Point c(1, 3);
	pointStack.push(c);// Point ��ü c Ǫ��. ����Ǿ� ����
	Point d(1, 4);
	pointStack.push(d);// Point ��ü d Ǫ��. ����Ǿ� ����

	size = pointStack.Get_topIdx();
	for (int i = 0; i <= size; i++)// Point ��ü ���
	{
		tmp = pointStack.pop(); // Point ��ü ��
		tmp.show();
	}

	cout << "======= MyStack<Point*> pStack =========" << endl;

	MyStack<Point*> pStack; // Point* �� �����ϴ� ����
	pStack.push(new Point(10, 10)); // ���� ���� Point ��ü Ǫ��. �����͸� ���� 
	pStack.push(new Point(10, 20)); // ���� ���� Point ��ü Ǫ��. �����͸� ���� 
	pStack.push(new Point(10, 30)); // ���� ���� Point ��ü Ǫ��. �����͸� ���� 

	Point* pPoint;
	size = pStack.Get_topIdx();
	for (int i = 0; i <= size; i++)// Point ��ü ���
	{
		pPoint = pStack.pop(); // Point ��ü�� ������ ��
		pPoint->show(); // Point ��ü ���
		delete pPoint;
	}

	cout << "====== MyStack<string> stringStack =========" << endl;

	MyStack<string> stringStack; //  ���ڿ��� �����ϴ� ����
	string s = "C++";
	stringStack.push(s);
	stringStack.push("java");
	stringStack.push("C ");
	stringStack.push("python");
	stringStack.push("C# ");

	size = stringStack.Get_topIdx();
	for (int i = 0; i <= size; i++)// Point ��ü ���
		cout << stringStack.pop() << ',';
	cout << endl;

	cout << "====== MyStack<string> stringStack =========" << endl;

}
