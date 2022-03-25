//Array_ReadWrite.cpp
#include<iostream>
#include<fstream>
using namespace std;
//ostream& write (const char* s, streamsize n); //ostream write() �Լ�����
int main()
{
	int num[10] = { 10,20,30,40,50,60,70,80,90,100 },tnum[10];
	double dnum[5] = { 1.1,2.1,3.1,4.1,5.1 },tdnum[5];
	char msg[30] = "multi campus.", tmsg[30];
	//array.dat, �������Ϸ� ����
	//������ ���� tnum, tdnum, tmsg�� load
	//load�� �迭 ���
	const char* file = "array.dat";
	//1. stream�� ����
	//2. 2������ ����
	//3. �������� load
	//4. �迭 ���
	
	ofstream fout(file,ios::out|ios::binary);

	if (!fout)
	{
		cout << file << "���Ͽ��� ���� !!!" << endl;
		return -1;
	}

	fout.write((char*)num, sizeof(num));
	fout.write((char*)dnum, sizeof(dnum));
	fout.write(msg, sizeof(msg));


	fout.close();
	cout << "�����Ϸ�\n";

	ifstream fin(file, ios::binary);

	fin.read((char*)tnum, sizeof(tnum));
	fin.read((char*)tdnum, sizeof(tdnum));
	fin.read(tmsg, sizeof(tmsg));

	int tnum_c = sizeof(tnum) / sizeof(tnum[0]);
	int tdnum_c = sizeof(tdnum) / sizeof(tdnum[0]);
	

	for (int i = 0; i < tnum_c; i++)
		cout << tnum[i] << ", ";
	cout << endl;
	for (int i = 0; i < tdnum_c; i++)
		cout << tdnum[i] << ", ";
	cout << endl;
	cout << "tsmg : " << tmsg << endl;


	return 0;
}