#include <iostream> //03/24
using namespace std;
/*
	정수 2 개를 입력하세요>> 100 30
	계산된 값은 130
*/
class Calculator
{
private:
	void input()
	{
		cout << "정수 2 개를 입력하세요>> ";
		cin >> a >> b;
	}
protected:
	int a, b;


public:
	Calculator(int a = 1, int b = 1) {}

	virtual int calc(int _a, int _b) = 0; //순수 가상함수

	void run()
	{
		input();
		cout << "계산된 값은 " << calc(a, b) << endl;
	}
};

class Adder : public Calculator
{
public:
	int calc(int _a, int _b) // 메서드 오버라이딩
	{

		return _a + _b;
	}
};

class Subtractor : public Calculator
{
public:
	int calc(int _a, int _b) // 메서드 오버라이딩
	{

		return _a - _b;
	}
};

class Multiply : public Calculator
{
public:
	int calc(int _a, int _b) // 메서드 오버라이딩
	{

		return _a * _b;
	}
};

class Divide : public Calculator
{
public:
	int calc(int _a, int _b) // 메서드 오버라이딩
	{

		return _a / _b;
	}
};

int main()
{
	Adder adder;
	Subtractor subtractor;
	Multiply multiply;
	Divide divide;

	adder.run();
	subtractor.run();
	multiply.run();
	divide.run();

	return 0;
}