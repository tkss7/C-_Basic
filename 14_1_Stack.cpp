#include <iostream>
using namespace std;

class Stack
{
private:
   int topIdx;   // 마지막 입력된 위치의 인덱스.
   char* stackPtr;  // 스택 포인터.
   int size;
public:
	Stack(int len=10);
	~Stack();
	void Push(const char& pushValue);
	char Pop();
};

Stack::Stack(int len)
{
	topIdx=-1;		// 스택 인덱스 초기화.
	stackPtr=new char[len];	// 데이터 저장 위한 배열 선언.
	size=len;
}

Stack::~Stack()
{
	delete[] stackPtr;
} 

void Stack::Push(const char& pushValue)
{ // 스택에 데이터 입력.

	if(topIdx>=(size-1))
	{
		cout<<"stack full !!!"<<endl;
		return;
	}
	stackPtr[++topIdx]=pushValue;
}

char Stack::Pop()
{ // 스택에서 데이터 꺼냄.
	if(topIdx<0)
	{
		cout<<"stack empty !!!"<<endl;
		return 32;
	}
	return stackPtr[topIdx--];
}

int main()
{
	Stack stack(10);

	for(int i=0; i<10; i++)
	   stack.Push('A'+i);
    //stack.Push('X');  //full


	for(int i=0; i<10; i++)
		cout<<stack.Pop()<<", ";
	cout << endl;
	//cout<<stack.Pop()<<endl;  //empty

	return 0;
}
