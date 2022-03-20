//154P_10.cpp
#include<iostream>
using namespace std;

class Add {
private:
	int a, b;
public:
	void setValue(int x, int y);
	int calculate();
};
void Add::setValue(int x, int y)
{
	a = x;
	b = y;
}
int Add:: calculate()
{
	return a + b;
} //Add end.

class Sub {
private:
	int a, b;
public:
	void setValue(int x, int y);
	int calculate();
};
void Sub:: setValue(int x, int y)
{
	a = x;
	b = y;
}
int Sub:: calculate()
{
	return a - b;
}// Sub end.

class Mul {
private:
	int a, b;
public:
	void setValue(int x, int y);
	int calculate();
};
void Mul:: setValue(int x, int y)
{
	a = x;
	b = y;
}
int Mul:: calculate()
{
	return a * b;
} // Mul end.

class Div {
private:
	int a, b;
public:
	void setValue(int x, int y);
	int calculate();
};
void Div:: setValue(int x, int y)
{
	a = x;
	b = y;
}
int Div:: calculate()
{
	return a / b;
} //Div end.

int main()
{
	Add a;
	Sub s;
	Mul m;
	Div d;
	int x, y;
	char ch;
	do {
		cout << "두 정수와 연산자를 입력하세요>>";
		cin >> x >> y >> ch;
		//if (typeid(x).name() || typeid(y).name() != "int")
		//{
		//	cout << "정수가 아닙니다." << endl;
		//	cin.clear();
		//	cin.ignore(x, '\n');
		//	cin.ignore(y, '\n');
		//	cin.ignore(ch, '\n');
		//}


		switch (ch)
		{
		case '+': a.setValue(x, y);
			cout << a.calculate();
			break;
		case '-': s.setValue(x, y);
			cout << s.calculate();
			break;
		case '*': m.setValue(x, y);
			cout << m.calculate();
			break;
		case '/': d.setValue(x, y);
			cout << d.calculate();
			break;
		}
		cout << endl;

	} while (ch == '+' || ch == '-' || ch == '*' || ch == '/');
	
	

	return 0;
}