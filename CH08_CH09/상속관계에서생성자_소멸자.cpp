//��Ӱ��迡��������_�Ҹ���.cpp
#include<iostream>
using namespace std;

class SoBase
{
private:
	int baseNum;
public:
	//SoBase() 
	//{
	//	cout << "SoBase() " << endl;
	//}

	SoBase(int n) : baseNum(n)
	{
		cout << "SoBase(int n) : "<< baseNum << endl;
	}
	~SoBase()
	{
		cout << "~SoBase() : " << baseNum << endl;
	}

};

class SoDerived : public SoBase 
{
private:
	int devNum;
public:
	SoDerived(int n) : SoBase(n) //�⺻Ŭ������ ����� ȣ��
	{
		devNum = n;
		cout << "SoDerived(int n) : " << devNum << endl;
	}

	~SoDerived()
	{
		cout << "~SoDerived() : " << devNum << endl;
	}
};

int main()
{
	SoDerived dr1(100); //�ڽİ�ü�� �����ϸ� �θ�Ŭ������ ���ȣ ������ -> �ڽ�Ŭ������ �����ڸ� �θ���.
	//�Ļ�Ŭ������ ��ü�� ȣ���ϸ� �ݵ�� �⺻Ŭ������ ���ȣ �����ڰ� �ʿ��ϴ�.

	return 0;
}