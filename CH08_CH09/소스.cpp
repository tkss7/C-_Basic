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

	emp_load();//������� �޸� ����

	while (stop)
	{

		printf("1. ������� �Է� \n");
		printf("2. ������� ��� \n");
		printf("3. ������� �˻� \n");
		printf("4. ������� ���� \n");
		printf("5. ������� ���� \n");
		printf("Select ? (1~5) ");
		scanf("%d%*c", &choice);

		switch (choice) //�ش�Ǵ� ��ȣ�� ������ �ٽ� �θ�
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


