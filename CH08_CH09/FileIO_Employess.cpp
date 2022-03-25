//employess.c
#include <stdio.h>
#include <string.h>
#define EMP_SZ 30

/*
키보드로 부터 성명(names,20), 월급(salary), 회사주소(comAddr,50)을 입력받고 출력하시오.
이때 입력되는 건수는 알지 못하며, 성명이 "end" 이면 입력을 종료하고,
입력된 데이터 출력과, 월급 평균을 구하여 출력하시오.

라이브러리함수의 성공,실패여부를 알려주는 perror()함수가 있다. 
*/
char names[EMP_SZ][20], comAddr[EMP_SZ][50];
int salary[EMP_SZ], Cn=0 ;//공통으로 쓰는건 전역변수 처리

emp_save();
emp_input();
emp_output();
emp_find();
emp_load();

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

emp_input()//데이터 입력
{
	int i;
	int choice, stop = 1;
	

	
	for (i = Cn; i < EMP_SZ; i++)
	{
		printf("성명 ? (입력죵료:end) ");
		gets(names[i]); //kim['\0], lee, han

		if (strcmp(names[i], "end") == 0)
			break;
		printf("월급 ? ");
		scanf("%d%*c", &salary[i]); //1000[enter], 2000, 3000
		printf("회사주소 ? ");
		gets(comAddr[i]);  //seoul, busan, incheon
	}

	Cn = i;
}//emp_input() end

emp_output()//데이터 출력
{
	int i, salTot = 0;
	
	for (i = 0; i < Cn; i++)
	{
		printf("%s, %d, %s \n", names[i], salary[i], comAddr[i]);
		salTot += salary[i];
	}
	
	printf("%d %d", sizeof(names), sizeof(names[0]));
	if (Cn)
	{
		printf("====================\n");
		printf("월급평균: %d \n", salTot / Cn);
		printf("====================\n");
		printf("%s", names);
	}


}//emp_output() end

emp_find()//검색 알고리즘
{
	int i,found;
	char s_name[20];

	while (1)
	{
		printf("\n검색할 성명 ? (검색종료:end) ");
		gets(s_name);   //lee,kim, sun ... end
		if (strcmp(s_name, "end") == 0)
			break;

		found = 1;
		for (i = 0; i < Cn; i++)
		{
			if (strcmp(names[i], s_name) == 0)
			{
				found = 0;
				printf("%s, %d, %s \n", names[i], salary[i], comAddr[i]);
				//break; 
			}
		}

		if (found)
			printf("%s, Not found!!! \n", s_name);

	} //while (1) end
}//emp_find() end

emp_save()
{
	FILE* fp;

	fp = fopen("emps.dat", "wb");
	if (fp == NULL)
	{
		//perror(""); =>""다음에 에러넘버에 해당하는 메시지 내용을 알아서 붙여준다.( 유저가 조치할 수 있도록)
		perror("Error : ");
		exit(1);
	}
	fwrite(&Cn, sizeof(Cn), 1, fp);
	fwrite(names, sizeof(names[1]), Cn, fp);
	fwrite(salary, sizeof(salary[1]), Cn, fp);
	fwrite(comAddr, sizeof(comAddr[1]), Cn, fp);
	fclose(fp);


}//emp_save() end

emp_load()
{
	FILE* fp;
	fp = fopen("emps.dat", "rb");
	if (fp == NULL)
	{
		printf("file load error. \n");
		return;
	}
	fread(&Cn, sizeof(Cn), 1, fp);
	for (int i = 0; i < Cn; i++)
	{
		fread(names[i], sizeof(names[1]), 1, fp); // nams[i]의 주소 입력하면 값으로 넣을수 있는 바이트가 20byte가 최대라서
													// 만약 1 대신 Cn으로 넣으면 20의 공간에 600이 들어오므로 터진다.
	}
	fread(salary, sizeof(salary[1]), Cn, fp); //따라서 Cn개를 한번에 넣으려면 시작주소를 names로 하여 600byte의 공간에 적재해야한다.
	fread(comAddr, sizeof(comAddr[1]), Cn, fp);


	fclose(fp);
	printf("emps.dat load.\n");
}//emp_load() end