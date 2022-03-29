#include "vld.h"" //03/ 29 복습필요!!!
#include <iostream>
using namespace std;

template <class T>  
class MyStack
{
	int top;     // top of stack
	T data[10]; // T 타입의 배열. 스택의 크기는 100
public:
	MyStack();
	void push(T element); //T 타입 원소 element를 data [] 배열에 삽입
	T pop();    //  스택의 탑에 있는 데이터를 data[] 배열에서 리턴

	int Get_topIdx()
	{
		return top;
	}
};

template <class T>
MyStack<T>::MyStack() // 생성자
{
	top = -1; // 스택은 비어 있음
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
		return 0; // 오류 표시
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

	MyStack<int*> ipStack; // int* 만을 저장하는 스택

	int* p = new int[5];
	for (i = 0; i < 3; i++)
		p[i] = i * 10; // 0, 10, 20으로 초기화
	p[i] = -99999;
	ipStack.push(p); // 포인터 푸시

	p = new int[5];
	for (i = 0; i < 4; i++)
		p[i] = (i + 1) * 100; // 100, 200,300,400으로 초기화
	p[i] = -99999;
	ipStack.push(p); // 포인터 푸시

	size = ipStack.Get_topIdx();
	int* q;
	for (i = 0; i <= size; i++)
	{
		q = ipStack.pop(); // 포인터 팝
		for (int j = 0; j < 5; j++)
			if (q[j] != -99999)
				cout << q[j] << ' '; // 화면 출력
			else
				break;
		cout << endl;
		delete[] q;
	}

	cout << "====== MyStack<Point> pointStack ===========" << endl;

	MyStack<Point> pointStack; // Point 객체만 저장하는 스택

	Point a(1, 1), tmp;  //객체생성

	pointStack.push(a); // Point 객체 a 푸시. 복사되어 저장 
	Point b(1, 2);
	pointStack.push(b);// Point 객체 b 푸시. 복사되어 저장 
	Point c(1, 3);
	pointStack.push(c);// Point 객체 c 푸시. 복사되어 저장
	Point d(1, 4);
	pointStack.push(d);// Point 객체 d 푸시. 복사되어 저장

	size = pointStack.Get_topIdx();
	for (int i = 0; i <= size; i++)// Point 객체 출력
	{
		tmp = pointStack.pop(); // Point 객체 팝
		tmp.show();
	}

	cout << "======= MyStack<Point*> pStack =========" << endl;

	MyStack<Point*> pStack; // Point* 만 저장하는 스택
	pStack.push(new Point(10, 10)); // 동적 생성 Point 객체 푸시. 포인터만 저장 
	pStack.push(new Point(10, 20)); // 동적 생성 Point 객체 푸시. 포인터만 저장 
	pStack.push(new Point(10, 30)); // 동적 생성 Point 객체 푸시. 포인터만 저장 

	Point* pPoint;
	size = pStack.Get_topIdx();
	for (int i = 0; i <= size; i++)// Point 객체 출력
	{
		pPoint = pStack.pop(); // Point 객체의 포인터 팝
		pPoint->show(); // Point 객체 출력
		delete pPoint;
	}

	cout << "====== MyStack<string> stringStack =========" << endl;

	MyStack<string> stringStack; //  문자열만 저장하는 스택
	string s = "C++";
	stringStack.push(s);
	stringStack.push("java");
	stringStack.push("C ");
	stringStack.push("python");
	stringStack.push("C# ");

	size = stringStack.Get_topIdx();
	for (int i = 0; i <= size; i++)// Point 객체 출력
		cout << stringStack.pop() << ',';
	cout << endl;

	cout << "====== MyStack<string> stringStack =========" << endl;

}
