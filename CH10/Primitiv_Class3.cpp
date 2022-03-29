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
	
	operator int() const//형변환 연산자
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
//&& 두개 붙이면 됨 참조자로 바로 초기화 할수 없다. 
// const int &x = 20 은 된다.
// int &&x 20은 된다. 
// & 하나로 하고싶다면 const를 연관되어 있는것에 전부 써야한다.
// 이것의 대안으로 나온게 && 임
// 함수나 객체를 변경못하게 상수화 시켜서 사용하고 싶을때 setRadius와 같은 메소드 때문에 쓰고싶어도 못쓰는 상황이 생긴다
// 이럴 땐 &&를 사용하여 getradius, operator int() 등과 같은것에 하고픈대로 const를 붙이고
// 불러오는 객체에 &&를 붙여 이것이 가능하게 한다.
void TestFunc(CTestData &&param) //2번째 객체 생성 / &쓰면 오류뜸
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
	TestFunc(5); // 묵시적으로 변환생성자가 불려짐
	TestFunc(CTestData(100)); // 명시적 호출 , 객체생성 100전달
	cout << "=========================\n";

	CTestData c1(50);

	cout << (int)c1 << endl; //명시적 호출

	//operator <<(cout, c1)
	cout << c1 << endl; // 만약 << 이 없으면 int형 형변환 연산자를 찾음


	return 0;
}