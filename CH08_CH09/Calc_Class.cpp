#include <iostream> //03/24
using namespace std;
/*
	���� 2 ���� �Է��ϼ���>> 100 30
	���� ���� 130
*/
class Calculator
{
private:
	void input()
	{
		cout << "���� 2 ���� �Է��ϼ���>> ";
		cin >> a >> b;
	}
protected:
	int a, b;


public:
	Calculator(int a = 1, int b = 1) {}

	virtual int calc(int _a, int _b) = 0; //���� �����Լ�

	void run()
	{
		input();
		cout << "���� ���� " << calc(a, b) << endl;
	}
};

class Adder : public Calculator
{
public:
	int calc(int _a, int _b) // �޼��� �������̵�
	{

		return _a + _b;
	}
};

class Subtractor : public Calculator
{
public:
	int calc(int _a, int _b) // �޼��� �������̵�
	{

		return _a - _b;
	}
};

class Multiply : public Calculator
{
public:
	int calc(int _a, int _b) // �޼��� �������̵�
	{

		return _a * _b;
	}
};

class Divide : public Calculator
{
public:
	int calc(int _a, int _b) // �޼��� �������̵�
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