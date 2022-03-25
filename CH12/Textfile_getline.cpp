//Textfile_getline.cpp
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	const char* file = "c:\\windows\\system.ini";
	//const char* file = "student.txt";
	ifstream fin(file, ios::in);

	if (!fin)
	{
		cout << file <<"���Ͽ��� ���� !!!" << endl;
		return -1;
	}

	char buffer[100];

	//getline�� �б⸦ �����ϸ� true�� ��ȯ�Ѵ�.
	while (fin.getline(buffer, 100)) // string�� getline ���� �̰��� ������ => �ӵ��� �� ������ �޸𸮵� �ʿ��� ��ŭ�� ����ϹǷ�,
	{
		cout << buffer << endl;
	}
	fin.close();
	cout << "=====================\n";

	const char* file2 = "student.txt";
	ifstream fin2(file2, ios::in); // C++�� stream�� �����ǰ� �ȵǹǷ� fin.close()�� �ص� �Ȱ��� �������� �� �� �� ����.

	if (!fin2)
	{
		cout << file2 <<"���Ͽ��� ���� !!!" << endl;
		return -1;
	}

	string line;

	while (getline(fin2, line)) // cin�� �ָ� Ű���忡�� �д°�
	{
		cout << line << endl;
	}
	fin2.close();

	return 0;
}