#include <iostream>
using namespace std;

int main()
{
	// �پ��� Ÿ���� ������ �����Ѵ�.
	long int i = 65;
	float f = 1.123;  //���̻� ��������
	double d = 5.12345;
	char c = 'C';

	cout << sizeof(i) << ", " << sizeof(f) << ", " << sizeof(d) << ", " << sizeof(c) << endl;
	cout << i << ", " << f << ", " << d << ", " << c << endl << endl;
	cout << fixed; //�Ҽ������� 6�ڸ�
	cout << i << ", " << f << ", " << d << ", " << c << endl << endl;

	float i2f;
	char i2c;
	double i2d;

// ������ ����ȯ(������)
	i2f = i;	// int -> float
	i2c = i;	// int -> char
	i2d = i;	// int -> double

	cout << "int : " << i << "\n\tto float : "
		<< i2f << "\n\tto char : "
		<< i2c << "\n\tto double : " << i2d << "\n\n";

// ��������� ����ȯ
	cout << "int i = " << i << "\n";
	cout << "(char)i= " << (char)i << "\n";
	cout << "(float)i= " << (float)i << "\n";
	cout << "(double)i= " << (double)i << "\n\n";

//8����Ʈ ������
	_int64 n1 = 2800000000;
	long long int n2= 3100000000;
	 
	cout << "_int64 n1 sizeof :" << sizeof(n1) << "  , " << sizeof(n1) << endl;
	cout << n1 << " , " << n2 << endl;

	auto t1 = 3.5; //����Ű����� ����� ���ÿ� �ʱ�ȭ �Ǿ�� �Ѵ�.
	cout << "t1 : " << t1 << ",  typeid(t1).name() : " << typeid(t1).name() << endl;
	cout << "tyeid(i).name() : " << typeid(i).name() << endl; //auto�� ������ ������ type������ �˷��� // ���ϱ� ������ �ӵ��� ����

	return 0;
}
