//Default_Parameter.cpp
#include<iostream>
using namespace std;

//������ü ���� ���ϱ�
int BoxVolume(int length = 1, int width = 1, int height = 1); // ����ο� ����ΰ� �ٸ��ٸ� ����ο� ����Ʈ���ڸ� �־��Ѵ�.


int main()
{
	cout << "BoxVolume(3, 3, 3) : " << BoxVolume(3, 3, 3) << endl;
	cout << "BoxVolume(5, 5) : " << BoxVolume(5, 5) << endl;
	cout << "BoxVolume(7) : " << BoxVolume(7) << endl;
	cout << "BoxVolume(0) : " << BoxVolume() << endl;

	return 0;
}

//������ü ���� ���ϱ�
int BoxVolume(int length, int width, int height) //����Ʈ ���� : �� ���������� �־���Ѵ�.
//ex) int x, int y=0, int z �̸� ����.
{
	return length * width * height;
}