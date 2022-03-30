//STL_Vector_Tuple.cpp 03/30
#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<string>
using namespace std;
// 마지막에 계속 추가 삭제한다 == vector
// 중간에 값을 계속 삭제 추가한다 == linked list
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

	sort(v.begin(), v.end(),greater<tuple<int, string, int>>()); // 첫번째 항목 오름차순이 디폴트 값임

	for (int i = 0; i < v.size(); i++)
		cout << get<0>(v[i]) << ", " << get<1>(v[i]) << ", " << get<2>(v[i]) << endl;
	cout << endl;

	string tmp;
	int found;

	while (1)
	{
		found = 1;
		
		cout << "검색할 성명 ? (검색종료:end)";
		getline(cin, tmp);

		if (tmp == "end")
			break;

		for (int i = 0; i < v.size(); i++) // 동명이인 있을수도 있으니 계속 돈다
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