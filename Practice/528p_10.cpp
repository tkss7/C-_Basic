#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
// �����Ƽ� ����κ� �����Լ� ���� ���� 
class Nation
{
private:
	string nation;
	string capital;
public:
	Nation(string nation="", string capital="")
	{
		this->nation = nation;
		this->capital = capital;
	}
	void SetData(string tmp1, string tmp2)
	{
		nation = tmp1;
		capital = tmp2;
	}
	string Getnation()
	{
		return nation;
	}
	string Getcapital()
	{
		return capital;
	}
};

class NationHandler
{
private:
	vector<Nation> vec;
	vector<Nation>::iterator it;
public:
	void VectorInput(vector<Nation> tmp)
	{
		vec = tmp;
	}

	void Input()
	{
		
		int stop = 1;
		int found=1;
		cout << "���� " << vec.size() << "���� ���� �ԷµǾ� �ֽ��ϴ�." << endl;
		cout << "����� ������ �Է��ϼ���(no no �̸� �Է³�)" << endl;
		while (stop)
		{
			Nation na;
			string tmp1, tmp2;
			found = 1;
			do
			{
				cout << vec.size() + 1 << ">>";
				cin >> tmp1 >> tmp2;
				if (tmp1 == "no" && tmp2== "no")
				{
					stop = 0;
					break;
				}
				for (int i = 0; i < vec.size(); i++)
				{

					if (tmp1 == vec[i].Getnation())
					{
						cout << "already exists !!" << endl;
						found = 0;
						break;
					}
				}
				/*auto it = find(vec.begin(), vec.end(), na);// �̷��ĵ� �����Ѱ� ������ �ϴ� �Ұ�����
				if (it == vec.end())
					cout << "ã�ҽ���" << endl;
				else
				{
					cout << "already exists !!" << endl;
					found = 0;
				}*/
				
				
			} while (!found);
			na.SetData(tmp1, tmp2);
			vec.push_back(na);
		}
	}

	void Quize()
	{
		int found = 1;
		while (1)
		{
			found = 1;
			string tmp1;
			cout << "������ ������?";
			cin >> tmp1;
			if (tmp1 == "exit")
				break;
			for (int i = 0; i < vec.size(); i++)
			{
				if (tmp1 == vec[i].Getcapital())
				{
					cout << "Correct !!" << endl;
					found = 0;
					break;
				}
			}
			if (found)
				cout << "NO !!" << endl;
		}
	}

};

int main()
{
	NationHandler handler;
	vector<Nation> v;
	Nation na1("���ѹα�", "����");
	Nation na2("����", "���");
	Nation na3("�߱�", "����¡");
	Nation na4("�Ϻ�", "����");
	Nation na5("����", "������");
	Nation na6("���þ�", "��ũ��");
	Nation na7("�߽���", "�߽��ڽ�Ƽ");
	Nation na8("��Ʈ��", "�ϳ���");
	Nation na9("�±�", "����");

	v.push_back(na1);
	v.push_back(na2);
	v.push_back(na3);
	v.push_back(na4);
	v.push_back(na5);
	v.push_back(na6);
	v.push_back(na7);
	v.push_back(na8);
	v.push_back(na9);
	handler.VectorInput(v);
	int stop = 1;
	int choice;
	cout << "***** ������ ���� ���߱� ������ �����մϴ�. *****" << endl;

	while (stop)
	{
		
		cout << "���� �Է�: 1, ����: 2, ����: 3 >>";
		cin >> choice;
		cin.ignore(2, '\n');

		switch (choice)
		{
		case 1:handler.Input();
			break;
		case 2: handler.Quize();
			break;
		case 3: stop = 0;
			break;
		}
	

	}



	return 0;
}