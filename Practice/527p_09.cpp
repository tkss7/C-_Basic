//527p_09.cpp
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> v;

	//int tmp=1;
	//int idx = -1;
	//while (tmp)
	//{
	//	cout << "������ �Է��ϼ���(0�� �Է��ϸ� ����)>>";
	//	cin >> tmp;

	//	v.push_back(tmp);
	//	cin.clear();
	//	cin.ignore(100, '\n');
	//	for (int i = 0; i <= idx; i++)
	//		cout << v[++idx]<<' ';
	//	cout << endl;
	//}
	int tmp = 1;
	while (tmp)
	{
		cout << "������ �Է��ϼ���(0�� �Է��ϸ� ����)>>";
		cin >> tmp;
		cin.ignore(1,'\n');

		v.push_back(tmp);
;
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << ' ';

		}
			
		cout << endl;
	}
	return 0;
}