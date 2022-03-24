#include <iostream>
#include <cstring>
using namespace std;

class String    //����� ���� Ŭ����
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
	 //strcmp() ������ 0 �̹Ƿ� 3�� �����ڿ����� �������� �Ǵ�
}

String String::operator+ (const String& s) //��ȯ���� &�� �ƴϹǷ� ���� ��ȯ�Ͽ� ��������ڰ� ��Ÿ����.
{
	cout << "operator+ (const String& s)" << endl;

	char* tempstr=new char[len + s.len-1];
	strcpy(tempstr, str);
	strcat(tempstr, s.str);
	
	String temp(tempstr);
	delete []tempstr;
	return temp;
}
// ������ : ��ü�� �ʱ�ȭ �� �������� ����
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
	s=String(str);  // ������(str), ���Կ�����
	return is;
}

int main()
{
	String str1="I like ";

	String str2="string class";
	String str3=str1+str2; //String str3 �� �߰�,str1+str2�� ������ ���� ��ȯ�ϹǷ� �����������

	cout<<str1<<endl;
	cout<<str2<<endl;
	cout<<str3<<endl;
	cout << "======================" << endl;
/*
	str1+=str2;

	if(str1==str3) 	
		cout<<"���� ���ڿ�!"<<endl;
	else
		cout<<"�������� ���� ���ڿ�!"<<endl;

	cout << "==================" << endl;
	String str4;
	cout<<"���ڿ� �Է�: ";
	cin>>str4;
	cout<<"�Է��� ���ڿ�: "<<str4<<endl;
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
���� ���ڿ�!
==================
String()
���ڿ� �Է�: operator>> (istream& is, String& s)
kingdom  => �Է¹��ڿ�
String(const char* s)
operator= (const String& s)
�Է��� ���ڿ�: operator<< (ostream& os, const String& s)
kingdom
*/