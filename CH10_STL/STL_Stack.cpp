//STL_Stack.cpp
#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
	stack<int> myStack;

	for (int i = 0; i < 5; i++)
	{
		myStack.push(i + 10);
	}

	cout << "myStack.size(): " << myStack.size() << endl;
	cout<<" myStack.top : " << myStack.top() << endl;
	myStack.pop(); //top에 있는 요소 제거
	cout << "myStack.size(): " << myStack.size() << endl;

	while (myStack.empty() == false)
	{
		cout << myStack.top() << ", ";
		myStack.pop();
	}
	cout << "\nmyStack.size(): " << myStack.size() << endl;

	stack<string> myStrStack;
	string tmp;

	for (int i = 0; i < 5; i++)
	{
		cout << "input string ? ";
		getline(cin, tmp);
		myStrStack.push(tmp);
	}

	while (myStrStack.empty() == false)
	{
		cout << myStrStack.top() << ", ";
		myStrStack.pop();
	}
	cout << "\nmyStack.size(): " << myStrStack.size() << endl;

	return 0;
}