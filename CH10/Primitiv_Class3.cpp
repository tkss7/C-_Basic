//Primitiv_Class3.cpp 03/29
#include<iostream>
using namespace std;

class CTestData
{
private:
	int mData;
public:
	CTestData()
	{
		cout << "CTestData()" << endl;
	}
	CTestData(int _data)
	{
		cout << "CTestData(int _data)" << endl;
		mData = _data;
	}
	~CTestData()
	{
		//cout << "~CTestData()" << endl;
	}

	int getData() const
	{
		return mData;
	}
	void setData(int _param)
	{
		mData = _param;
	}
	
	operator int() const//����ȯ ������
	{
		cout << "operator int() \n";
		return mData;
	}

	friend ostream& operator <<(ostream& os, CTestData& ref);
};

//void TestFunc(int num)
//{
//	cout << "TestFunc(int num)" << endl;
//}
//&& �ΰ� ���̸� �� �����ڷ� �ٷ� �ʱ�ȭ �Ҽ� ����. 
// const int &x = 20 �� �ȴ�.
// int &&x 20�� �ȴ�. 
// & �ϳ��� �ϰ�ʹٸ� const�� �����Ǿ� �ִ°Ϳ� ���� ����Ѵ�.
// �̰��� ������� ���°� && ��
// �Լ��� ��ü�� ������ϰ� ���ȭ ���Ѽ� ����ϰ� ������ setRadius�� ���� �޼ҵ� ������ ����; ������ ��Ȳ�� �����
// �̷� �� &&�� ����Ͽ� getradius, operator int() ��� �����Ϳ� �ϰ��´�� const�� ���̰�
// �ҷ����� ��ü�� &&�� �ٿ� �̰��� �����ϰ� �Ѵ�.
void TestFunc(CTestData &&param) //2��° ��ü ���� / &���� ������
{//CTestData param = 
	cout << "TestFunc(CTestData param)" << endl;
	cout << param.getData() << endl;
	param.setData(200);
	cout << param.getData() << endl;
}

ostream& operator <<(ostream& os, CTestData& ref)
{
	cout << "operator <<(ostream& os, CTestData& ref) " << endl;
	os << ref.mData << endl;

	return os;
}

int main()
{
	TestFunc(5); // ���������� ��ȯ�����ڰ� �ҷ���
	TestFunc(CTestData(100)); // ����� ȣ�� , ��ü���� 100����
	cout << "=========================\n";

	CTestData c1(50);

	cout << (int)c1 << endl; //����� ȣ��

	//operator <<(cout, c1)
	cout << c1 << endl; // ���� << �� ������ int�� ����ȯ �����ڸ� ã��


	return 0;
}