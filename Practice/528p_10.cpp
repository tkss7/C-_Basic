#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
// 귀찮아서 퀴즈부분 랜덤함수 구현 안함 
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
		cout << "현재 " << vec.size() << "개의 나라가 입력되어 있습니다." << endl;
		cout << "나라와 수도를 입력하세요(no no 이면 입력끝)" << endl;
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
				/*auto it = find(vec.begin(), vec.end(), na);// 이런식도 가능한거 같은데 일단 불가능함
				if (it == vec.end())
					cout << "찾았숴요" << endl;
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
			cout << "독일의 수도는?";
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
	Nation na1("대한민국", "서울");
	Nation na2("북한", "평양");
	Nation na3("중국", "베이징");
	Nation na4("일본", "도쿄");
	Nation na5("독일", "베를린");
	Nation na6("러시아", "모스크바");
	Nation na7("멕시코", "멕시코시티");
	Nation na8("베트남", "하노이");
	Nation na9("태국", "방콕");

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
	cout << "***** 나라의 수도 맞추기 게임을 시작합니다. *****" << endl;

	while (stop)
	{
		
		cout << "정보 입력: 1, 퀴즈: 2, 종료: 3 >>";
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