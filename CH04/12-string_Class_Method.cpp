#include <iostream>
#include <string>
using namespace std;

int main()
{
	char name[20]; // C style 문자열, cin.getline(name, 20);
	//문자열추가, 복사, 비교,

	string str1 = "I like "; //getline(cin, name);
	string str2 = "C++ J++ C#";

	int len = str1.length();
	cout << "str1 len : " << len << endl;

	//str1.assign("C++");  //기존내용지우고들어간다
	str1 = "C++";
	cout << "str1.assign(test) : " << str1 << endl;

	//str1.append(" Programming");
	str1 += " Programming";
	cout << "str1.append( 'Programming') : " << str1 << endl;

	//str1.clear();  //문자열지움
	//cout<<"str1.clear() : "<<str1<<endl;

	int n1 = str1.find("Prog");  //대소문자구분
	cout << "str1.find(Prog) : " << n1 << endl;

//str2
	cout << "str2:" << str2 << endl;
	str2.replace(4, 3, "java");  //J#변경 4번쨰부터 3칸을 바꿔라, java로
	cout << "str2.replace(4,3,'java') : " << str2 << endl;

	string str3 = str2.substr(0, 3);  //C++
	cout << "str2.substr(0,3) : " << str3 << endl;

	str3 = str2.substr(4, 4);  //java
	cout << "str2.substr(4,4) : " << str3 << endl;

	string s_num = "123";
	string s_fnum = "123.45";
	int num = stoi(s_num); //문자열을 정수로
	double dnum = stof(s_fnum); //문자열을 더블로
	cout << typeid(num).name() << ", " << num << endl;
	cout << typeid(dnum).name() << ", " << dnum << endl;

	return 0;
}
