#include<iostream>
#include"154P_10.h"
using namespace std;
int main()
{
	Add a;
	Sub s;
	Mul m;
	Div d;
	int x, y;
	char ch;
	do {
		cout << "�� ������ �����ڸ� �Է��ϼ���>>";
		cin >> x >> y >> ch;

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