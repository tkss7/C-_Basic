//OStream_Intro.cpp
#include<cstdio>
//using namespace std;
/*
	��,��� �ý���(IStream, OStream)
	OStream�� �����ϱ� ���� cout ��ü�� ����
	<< : ��½�Ʈ�� ������

*/
namespace myStd
{
	const char* endl = "\n";

	class ostream // Ŭ���� ostream ����
	{
	public:
		ostream& operator<<(const char* str)
		{
			printf("%s", str);
			return *this;
		}
		ostream& operator<<(int n)
		{
			printf("%d", n);
			return *this;
		}
		ostream& operator<<(double d)
		{
			printf("%lf", d);
			return *this;
		}
	};

	ostream cout; //ostream ��ü cout ����
}
using namespace myStd;
int main()
{
	cout << "Hello world." << endl; // cout<< "Hello word." �� �����Ͽ� ��ȯ�ϰ� �װͿ� <<endl�� �� ������

	cout << 3.14159 << " , " << 500 << endl;
	cout << endl;
	cout << 100;
	cout << endl;

	return 0;
}