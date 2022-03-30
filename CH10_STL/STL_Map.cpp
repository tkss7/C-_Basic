//STL_Map.cpp 03/30
#include<iostream>
#include<map>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
	map<string, string> dic; //(Key , Value) // 내부적으로 오름차순으로 정렬함
	// 벡터 페어데이터면 변환이 가능할 수도있지만 중복데이터가 있을 수 있으므로 애매하다.
	dic.insert(make_pair("love", "사랑")); //(Key , Value)
	dic.insert(make_pair("apple", "사과")); //이방식을 주로씀
	dic["cherry"] = "체리";
	dic.insert({ "cloud", "구름" });

	map<string, string>::iterator it;
	
	for (it = dic.begin(); it != dic.end(); it++)
		//cout << it->first << ", " << it->second << endl; // 둘 다 가능
		cout << get<0>(*it) << ", " << it->second << endl; // 둘 다 가능

	cout << "dic.size() : " << dic.size() << endl;

	string str;
	while (1)
	{
		cout << "검색 할 key ? (종료:end)";
		getline(cin, str);
		
		if (str == "end")
			break;

		if (dic.find(str) == dic.end()) // 찾으면 찾은 위치에 있음 // 특성상 중복된 key 값이 없으므로 바로찾는다.
			cout << str << ", not found !!!" << endl;
		else
			cout << dic[str] << endl;

	}

	return 0;
}