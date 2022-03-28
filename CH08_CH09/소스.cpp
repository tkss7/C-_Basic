//#include<iostream>
//#include<cstring>
//using namespace std;
//int main()
//{
//	char** name;
//	name = new char* [2];
//
//	for (int i = 0; i < 2; i++)
//		name[i] = new char[10];
//
//	const char *n = "string";
//	cin >> name[0];
//	cin >> name[1];
//
//	cout << strlen(name[1]) << endl;
//	printf("%s", *name);
//}
//employess.c
#include<iostream>
#include<cstring>
extern "C"
{
	void emp_input();
	void emp_output();
	int emp_load();
	void emp_find();
	void emp_save();
}
int main()
{
	int choice, stop = 1;

	emp_load();//사원정보 메모리 적재

	while (stop)
	{

		printf("1. 사원정보 입력 \n");
		printf("2. 사원정보 출력 \n");
		printf("3. 사원정보 검색 \n");
		printf("4. 사원정보 저장 \n");
		printf("5. 사원정보 종료 \n");
		printf("Select ? (1~5) ");
		scanf("%d%*c", &choice);

		switch (choice) //해당되는 번호가 없으면 다시 부름
		{
		case 1: emp_input();
			break;
		case 2: emp_output();
			break;
		case 3: emp_find();
			break;
		case 4: emp_save();
			break;
		case 5:stop = 0;
			break;
		}
		//while (getchar() != '\n');
	}//while(1)




	return 0;
}// main() end


