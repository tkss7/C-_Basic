//STL_Map.cpp 03/30
#include<iostream>
#include<map>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
	map<string, string> dic; //(Key , Value) // ���������� ������������ ������
	// ���� �����͸� ��ȯ�� ������ ���������� �ߺ������Ͱ� ���� �� �����Ƿ� �ָ��ϴ�.
	dic.insert(make_pair("love", "���")); //(Key , Value)
	dic.insert(make_pair("apple", "���")); //�̹���� �ַξ�
	dic["cherry"] = "ü��";
	dic.insert({ "cloud", "����" });

	map<string, string>::iterator it;
	
	for (it = dic.begin(); it != dic.end(); it++)
		//cout << it->first << ", " << it->second << endl; // �� �� ����
		cout << get<0>(*it) << ", " << it->second << endl; // �� �� ����

	cout << "dic.size() : " << dic.size() << endl;

	string str;
	while (1)
	{
		cout << "�˻� �� key ? (����:end)";
		getline(cin, str);
		
		if (str == "end")
			break;

		if (dic.find(str) == dic.end()) // ã���� ã�� ��ġ�� ���� // Ư���� �ߺ��� key ���� �����Ƿ� �ٷ�ã�´�.
			cout << str << ", not found !!!" << endl;
		else
			cout << dic[str] << endl;

	}

	return 0;
}