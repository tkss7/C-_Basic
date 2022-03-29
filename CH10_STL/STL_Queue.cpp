//STL_Queue.cpp
#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main()
{
	queue<char> myQueue;

	myQueue.push('A');
	myQueue.push('B');
	myQueue.push('C');

	cout << "myQueue.size() : " << myQueue.size() << endl;


	while (!myQueue.empty())
	{
		cout << myQueue.front() << " , ";
		myQueue.pop();
	}
	cout << "myQueue.size()" << myQueue.size() << endl;

	myQueue.push('A');
	myQueue.push('B');
	myQueue.push('C');
	myQueue.push('D');

	cout << "myQueue.front() : " << myQueue.front() << endl;
	cout << "myQueue.back() : " << myQueue.back() << endl;
	cout << "myQueue.size() : " << myQueue.size() << endl;

	queue<char> myQueue2;

	myQueue2.push('X');
	myQueue2.push('Y');
	myQueue2.push('Z');

	myQueue.swap(myQueue2); // 크기가 달라도 정확하게 교환함

	while (!myQueue.empty())
	{
		cout << myQueue.front() << " , ";
		myQueue.pop();
	}
	cout << endl;

	while (!myQueue2.empty())
	{
		cout << myQueue2.front() << " , ";
		myQueue2.pop();
	}
	cout << endl;

	return 0;
}
