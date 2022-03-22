#include <iostream>
using namespace std;

/*
������ ���� �����ϱ� ���� �ڵ带 �ϼ��Ͻÿ�.

������
���� ������ :  0
1��° Kim �α���
2��° Lee �α���
3��° Han �α���
�̸�: Han, ����: 19, count: 3
4��° Park �α���
�̸�: Park, ����: 40, count: 4
===================
4��° Park �α׾ƿ�
���� ������ :  3

4��° Uk �α���
�̸�: Uk, ����: 30, count: 4
4��° Uk �α׾ƿ�
3��° Han �α׾ƿ�
2��° Lee �α׾ƿ�
1��° Kim �α׾ƿ�
*/
class Person
{
	char name[20];
	int age;
	static int count; //���� ���
	 
public:
	Person(const char *_name, int _age)
	{
		strcpy(name, _name);
		age = _age;
		count++;
		cout << count << "��° " << name << " �α���" << endl;
	}
	~Person()
	{
		cout << count << "��° " << name << " �α׾ƿ�" << endl;
		count--;

	}

	void ShowData()
	{
		cout << "�̸�: " << name << ", ����: " << age;
		cout << ", count: " << count << endl;
	}

	//�����Լ� ����
	static void Countte()  //�����Լ�
	{
		cout << "���� ������ :  " << count << endl;
	}
};

// main() �Լ���ȣ��Ǳ�������������Ҵ�ȴ�.  
int Person::count = 0; // static ����ʱ�ȭ, �޸��Ҵ�(Data Segment)

// �����Լ� ����
void FuncA()
{
	Person tmp("Park", 40);
	tmp.ShowData();   
	cout << "===================" << endl;
}

int main()
{
	Person::Countte();   
 
	Person p1("Kim", 13);
	Person p2("Lee", 22);
	Person p3("Han", 19);

	p3.ShowData();    
 
	FuncA(); 

	p3.Countte(); //���� ������ : 3

	Person p4("Uk", 30);   
	p4.ShowData();

	return 0;
}
