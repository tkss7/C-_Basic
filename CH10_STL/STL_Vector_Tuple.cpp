//STL_Vector_Tuple.cpp 03/30
#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<string>
using namespace std;
// �������� ��� �߰� �����Ѵ� == vector
// �߰��� ���� ��� ���� �߰��Ѵ� == linked list
int main()
{
	vector<tuple<int, string, int>> v;

	v.push_back(make_tuple(1, "kim", 98));
	v.push_back(make_tuple(3, "lee", 67));
	v.push_back(make_tuple(4, "han", 51));
	v.push_back(make_tuple(2, "park", 79));
	v.push_back(make_tuple(5, "uk", 80));

	for (int i = 0; i < v.size(); i++)
		cout << get<0>(v[i]) << ", " << get<1>(v[i]) << ", " << get<2>(v[i]) << endl;
	cout << endl;

	sort(v.begin(), v.end(),greater<tuple<int, string, int>>()); // ù��° �׸� ���������� ����Ʈ ����

	for (int i = 0; i < v.size(); i++)
		cout << get<0>(v[i]) << ", " << get<1>(v[i]) << ", " << get<2>(v[i]) << endl;
	cout << endl;

	string tmp;
	int found;

	while (1)
	{
		found = 1;
		
		cout << "�˻��� ���� ? (�˻�����:end)";
		getline(cin, tmp);

		if (tmp == "end")
			break;

		for (int i = 0; i < v.size(); i++) // �������� �������� ������ ��� ����
		{
			if (get<1>(v[i]) == tmp)
			{
				found = 0;
				cout << get<0>(v[i]) << ", " << get<1>(v[i]) << ", " << get<2>(v[i]) << endl;
			}
		}
		
		if (found)
			cout << tmp << ", Not found !!!" << endl;
	}

	return 0;
}