//Default_Parameter.cpp
#include<iostream>
using namespace std;

//직육면체 부피 구하기
int BoxVolume(int length = 1, int width = 1, int height = 1); // 선언부와 실행부가 다르다면 선언부에 디폴트인자를 둬야한다.


int main()
{
	cout << "BoxVolume(3, 3, 3) : " << BoxVolume(3, 3, 3) << endl;
	cout << "BoxVolume(5, 5) : " << BoxVolume(5, 5) << endl;
	cout << "BoxVolume(7) : " << BoxVolume(7) << endl;
	cout << "BoxVolume(0) : " << BoxVolume() << endl;

	return 0;
}

//직육면체 부피 구하기
int BoxVolume(int length, int width, int height) //디폴트 인자 : 맨 마지막부터 있어야한다.
//ex) int x, int y=0, int z 이면 오류.
{
	return length * width * height;
}