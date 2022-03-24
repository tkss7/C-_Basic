#include<iostream>
#include<string>
using namespace std;

class LoopAdder
{
	string name;
	int x, y, sum;
	void read();
	void write();
protected:
	LoopAdder(string name = "")
	{
		this->name = name;
	}
	int getX() { return x; }
	int getY() { return y; }
	virtual int calculate() = 0;
public:
	void run();
};

void LoopAdder::read()
{
	cout << name << ":" << endl;
	cout << "처음 수에서 두번쨰 수까지 더합니다. 두 수를 입력하세요 >> ";
	cin >> x >> y;
}
void LoopAdder::write()
{
	cout << x << "에서 " << y << "까지의 합 = " << sum << " 입니다" << endl;
}
void LoopAdder::run()
{
	read();
	sum = calculate();
	write();
}
class WhileLoopAdder : public LoopAdder
{
public:
	WhileLoopAdder(string _name) :LoopAdder(_name)
	{

	}
	int calculate()
	{
		int i = getX();
		int _sum = 0;
		while (i <= getY())
		{
			_sum += i;
			i++;
		}
		return _sum;
	}
};
class DoWhileLoopAdder : public LoopAdder
{
public:
	DoWhileLoopAdder(string _name) :LoopAdder(_name)
	{

	}
	int calculate()
	{
		int i = getX();
		int _sum = 0;
		do {
			_sum += i;
			i++;
		} while (i <= getY());

		return _sum;
	}
};
int main()
{
	WhileLoopAdder whileLoop("While Loop");
	whileLoop.run();
	DoWhileLoopAdder doWhileLoop("Do While Loop");
	doWhileLoop.run();

	return 0;
}