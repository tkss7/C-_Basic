// C++_string.cpp
#include<iostream>
#include<string> //string Ŭ������ ���ڿ� ���
#include<algorithm> //string Ŭ������ ���ڿ� ���
/*
	cin.getline(comAddr, 50) : ���� ���� 50���ڱ��� �޴´�;
	getline(cin,comAddr) : ���κ��� �Է� �޴°� ? : Ű����(cin) , ��� �������ΰ�? : comAddr
*/

using namespace std;
int main()
{
	string name; // ���ڿ� �ϳ� ����, ũ�������� ����
	string name2[20]; // ũ������ ���� ���ڿ��� 20�� �����ϰڴ�.
	string comAddr;

	cout << "���� ? ";
	cin >> name;	//kim
	cin.ignore(100, '\n');

	cout << "ȸ���ּ� ? "; //SEOUL �����
	getline(cin, comAddr); //�����Լ�

	cout << name << "," << comAddr << endl;

	transform(name.begin(), name.end(), name.begin(), ::toupper); // ���ۺ���, �������� ������, ���ۺ���, ���� �빮�ڷ� �ٲ��
	//transform(name.begin(), name.end(), name.begin(), ::tolower); // ���ۺ���, �������� ������, ���ۺ���, ���� �ҹ��ڷ� �ٲ��

	cout << name << "," << comAddr << endl;

	if (name == "KIM")
		cout << "Equal." << endl;
	else
		cout << "Not Equal." << endl;

	return 0;
}