#include <iostream>
using namespace std;

class Stack
{
private:
   int topIdx;   // ������ �Էµ� ��ġ�� �ε���.
   char* stackPtr;  // ���� ������.
   int size;
public:
	Stack(int len=10);
	~Stack();
	void Push(const char& pushValue);
	char Pop();
};

Stack::Stack(int len)
{
	topIdx=-1;		// ���� �ε��� �ʱ�ȭ.
	stackPtr=new char[len];	// ������ ���� ���� �迭 ����.
	size=len;
}

Stack::~Stack()
{
	delete[] stackPtr;
} 

void Stack::Push(const char& pushValue)
{ // ���ÿ� ������ �Է�.

	if(topIdx>=(size-1))
	{
		cout<<"stack full !!!"<<endl;
		return;
	}
	stackPtr[++topIdx]=pushValue;
}

char Stack::Pop()
{ // ���ÿ��� ������ ����.
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
