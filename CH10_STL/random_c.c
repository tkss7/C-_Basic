#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define random_MAX 10
//rand(): 0~32767 ���� ���� �߻�

int main()
{
	srand((unsigned int)time(NULL));  //����ó��ȭ

	for (int i = 1; i <= 10; i++)  // //0���� 9 �̹Ƿ� 1 ����
		printf("%d, ", rand() % random_MAX + 1);

	printf("\n");
}

/*
for (int i = 1; i <= 10; i++)
{
		data[i]= rand() % random_MAX + 1);
		for(j=0;j<i ;j++)
		{
		    if(data[i] == data[j])   //�ٸ� ���� �� ����
			{
			    i--;
				break;
		    }
		}
}
*/