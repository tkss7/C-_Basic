#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define random_MAX 10
//rand(): 0~32767 사이 난수 발생

int main()
{
	srand((unsigned int)time(NULL));  //난수처기화

	for (int i = 1; i <= 10; i++)  // //0부터 9 이므로 1 더함
		printf("%d, ", rand() % random_MAX + 1);

	printf("\n");
}

/*
for (int i = 1; i <= 10; i++)
{
		data[i]= rand() % random_MAX + 1);
		for(j=0;j<i ;j++)
		{
		    if(data[i] == data[j])   //다른 난수 만 저장
			{
			    i--;
				break;
		    }
		}
}
*/