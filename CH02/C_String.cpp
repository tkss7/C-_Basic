//C_String.cpp
#include<iostream>
#include<cstring> // C++ ��Ģ : c ������� ���� Ȯ���� h�� ������ ������ϸ� �տ� c�� �߰��Ѵ�.
/*
	A��ü (.) ->   
	cin.getline �� ����Լ� :�� ��ü������ �� �� �ִ� �Լ�
*/

using namespace std;
int main()
{
	char name[20];
	char comAddr[50];

	cout << "���� ? ";
	cin >> name;	//kim
	cin.ignore(100, '\n');

	cout << "ȸ���ּ� ? "; //SEOUL �����

	//cin >> comAddr; //cin�� ������������ ����
	//cin.getline(comAddr, 50); // ���� ���� 50���ڱ��� �޴´�.
	//cin.getline(comAddr, 50, '\n'); // ���� ���� 50���ڱ��� �޴µ� ���߿� \n�� ������ �׸� �޴´�.
	cin.getline(comAddr, 50, '.'); // ���� ���� 50���ڱ��� �޴µ� ���߿� .�� ������ �׸� �޴´�.
	 // cin.getline �� ����Լ� :�� ��ü������ �� �� �ִ� �Լ�
	cout << name << "," << comAddr << endl;

	cout << "strupr(name) : " << strupr(name) << endl; //�빮�ڷ� �ٲ�
	cout << "strlwr(comAddr) : " << strlwr(comAddr) << endl; //�ҹ��ڷ� �ٲ�

	if (strcmp(name, "KIM") == 0)
		cout << "Equal." << endl;
	else
		cout << "Not Equal." << endl;

	return 0;
}