#include<iostream>
using namespace std;

class AbstractGate {
protected:
	bool x, y;
public:
	void set(bool x, bool y) { this->x = x; this->y = y; }
	virtual bool operation() = 0;
};

class ORGate : public AbstractGate
{
public:
	bool operation()
	{
		if (this->x == false && this->y == false)
			return false;
		else
			return true;
	}
};

class ANDGate : public AbstractGate
{
public:
	bool operation()
	{
		if (this->x == true && this->y == true)
			return true;
		else
			return false;
	}
};

class XORGate : public AbstractGate
{
public:
	bool operation()
	{
		if (this->x == this->y )
			return false;
		else
			return true;
	}
};

int main()
{
	ANDGate andGate;
	ORGate orGate;
	XORGate xorGate;

	andGate.set(true, false);
	orGate.set(true, false);
	xorGate.set(true, false);
	cout.setf(ios::boolalpha);
	cout << andGate.operation() << endl;
	cout << orGate.operation() << endl;
	cout << xorGate.operation() << endl;


	return 0;
}
