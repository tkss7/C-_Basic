//positive_negative.cpp
#include<iostream>
using namespace std;
/*
���� : ������ �Է¹޾� �������, �������� ����Ѵ�.
		�Ǵ��� IsPositive() ���� Ȯ���Ͽ� ����� main() ���� ����Ѵ�.

�����Է� ? 10
Positive number
�����Է� -> -10
Negative number
*/

bool IsPositive(int n)
{
	if (n >= 0)
		return true;
	else
		return false;
}

int main()
{
	int N;

	cout << "���� : ? ";
	cin >> N;

	cout << (IsPositive(N) == true ? "Positive" : "Negative") << endl;

	return 0;
}