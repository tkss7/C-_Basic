//Array_ReadWrite.cpp
#include<iostream>
#include<fstream>
using namespace std;
//ostream& write (const char* s, streamsize n); //ostream write() 함수원형
int main()
{
	int num[10] = { 10,20,30,40,50,60,70,80,90,100 },tnum[10];
	double dnum[5] = { 1.1,2.1,3.1,4.1,5.1 },tdnum[5];
	char msg[30] = "multi campus.", tmsg[30];
	//array.dat, 이진파일로 저장
	//파일을 열어 tnum, tdnum, tmsg에 load
	//load된 배열 출력
	const char* file = "array.dat";
	//1. stream을 연결
	//2. 2진파일 저장
	//3. 이진파일 load
	//4. 배열 출력
	
	ofstream fout(file,ios::out|ios::binary);

	if (!fout)
	{
		cout << file << "파일열기 실패 !!!" << endl;
		return -1;
	}

	fout.write((char*)num, sizeof(num));
	fout.write((char*)dnum, sizeof(dnum));
	fout.write(msg, sizeof(msg));


	fout.close();
	cout << "생성완료\n";

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