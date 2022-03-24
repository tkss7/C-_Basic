#include <iostream>
#include <cstring>
using namespace std;

class String    //사용자 정의 클래스
{
private:
	int len;
	char * str;
public:
	String();
	String(const char * s);
	String(const String& s);
	~String();
	String& operator= (const String& s);
	String& operator+= (const String& s);
	bool operator== (const String& s);
	String operator+ (const String& s);

	friend ostream& operator<< (ostream& os, const String& s);
	friend istream& operator>> (istream& is, String& s);
};

String::String()
{
	cout << "String()" << endl;

	len=0;
	str=NULL;
}

String::String(const char* s)
{
	cout << "String(const char* s)" << endl;
	len=strlen(s)+1;
	str=new char[len];
	strcpy(str, s);
}

String::String(const String& s)
{
	cout << "String(const String& s)" << endl;
	len=s.len;
	str=new char[len];
	strcpy(str, s.str);
}

String::~String() 
{
	if(str!=NULL)
		delete []str; 
}

String& String::operator= (const String& s)
{
	cout << "operator= (const String& s)" << endl;
	if(str!=NULL)
		delete []str;
	len=s.len;
	str=new char[len];
	strcpy(str, s.str);
	return *this;
}

String& String::operator+= (const String& s)
{
	cout << "operator+= (const String& s)" << endl;

	len+=(s.len-1);
	char* tempstr=new char[len];
	strcpy(tempstr, str);
	strcat(tempstr, s.str);

	if(str!=NULL)
		delete []str;
	str=tempstr;
	return *this;
}

bool String::operator== (const String& s)
{
	cout << "operator== (const String& s)" << endl;
	return strcmp(str, s.str) ? false  : true;
	 //strcmp() 같은면 0 이므로 3항 연산자에서는 거짓으로 판단
}

String String::operator+ (const String& s) //반환값이 &가 아니므로 값을 반환하여 복사생성자가 나타난다.
{
	cout << "operator+ (const String& s)" << endl;

	char* tempstr=new char[len + s.len-1];
	strcpy(tempstr, str);
	strcat(tempstr, s.str);
	
	String temp(tempstr);
	delete []tempstr;
	return temp;
}
// 생성자 : 객체를 초기화 할 목적으로 사용됨
ostream& operator<< (ostream& os, const String& s)
{
	cout << "operator<< (ostream& os, const String& s)" << endl;

	os<<s.str;
	return os;
}

istream& operator>> (istream& is, String& s)
{
	cout << "operator>> (istream& is, String& s)" << endl;

	char str[100];
	is>>str;
	s=String(str);  // 생성자(str), 대입연산자
	return is;
}

int main()
{
	String str1="I like ";

	String str2="string class";
	String str3=str1+str2; //String str3 로 했고,str1+str2의 연산을 값을 반환하므로 복사생성자임

	cout<<str1<<endl;
	cout<<str2<<endl;
	cout<<str3<<endl;
	cout << "======================" << endl;
/*
	str1+=str2;

	if(str1==str3) 	
		cout<<"동일 문자열!"<<endl;
	else
		cout<<"동일하지 않은 문자열!"<<endl;

	cout << "==================" << endl;
	String str4;
	cout<<"문자열 입력: ";
	cin>>str4;
	cout<<"입력한 문자열: "<<str4<<endl;
*/
	return 0;
}
/*
String(const char* s)
String(const char* s)
operator+ (const String& s)
String(const char* s)
String(const String& s)
operator<< (ostream& os, const String& s)
I like
operator<< (ostream& os, const String& s)
string class
operator<< (ostream& os, const String& s)
I like string class
======================
operator+= (const String& s)
operator== (const String& s)
동일 문자열!
==================
String()
문자열 입력: operator>> (istream& is, String& s)
kingdom  => 입력문자열
String(const char* s)
operator= (const String& s)
입력한 문자열: operator<< (ostream& os, const String& s)
kingdom
*/