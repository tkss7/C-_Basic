//key_in.cpp
#include<iostream>

/*
	using namespace std : std�� ���� �� ��� �̸��� std(�̸�����)�� �����ϰڴ�.
	>> : �Է� ��Ʈ�� ������
		if (cin.fail()) // �Է¹޴°��� �����ߴٸ�
	{
		cin.clear();
		cin.ignore(100, '\n'); // �Էµ� 100����Ʈ �ȿ� \n���� ����(�����).
	}

*/
//using std::cout;
using namespace std; 
int main()
{
	cout << "Ű����� ������ �Է�" << endl;

	int wid, hei;

	cout << "�ʺ� : ";
	cin >> wid;	// >> : �Է� ��Ʈ�� ������

	cout << "���� :";
	cin >> hei;

	if (cin.fail()) // �Է¹޴°��� �����ߴٸ�
	{
		cin.clear();
		cin.ignore(100, '\n'); // �Էµ� 100����Ʈ �ȿ� \n���� ����(�����).
	}

	int area = wid * hei;
	cout << "������ : " << area << endl;

	char ch;
	cout << "�ѹ��� : ? ";
	cin >> ch;
	cout << "ch : " << ch << endl;

	return 0;
}