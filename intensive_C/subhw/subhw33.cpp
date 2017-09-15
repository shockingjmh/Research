#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

int input_find(int);
int count_number(int *, int, int);
void myfflush();

int main()
{
	int ary[] = { 2, 8, 15, 1, 8, 10, 5, 19, 19, 3, 5, 6, 6, 2, 8, 2, 12, 16, 3, 8, 17, 12, 5, 3, 14, 13, 3, 2, 17, 19, 16, 8, 7, 12, 19, 10, 13, 8, 20, 16,
		15, 4, 12, 3, 14, 14, 5, 2, 12, 14, 9, 8, 5, 3, 18, 18, 20, 4 };
	int wantFind;
	int sizeArray = sizeof(ary) / sizeof(ary[0]);
	int count;
	
	wantFind = input_find(sizeArray);
	count = count_number(ary, wantFind, sizeArray);

	printf("���� %d �� �迭�� %d �� �ֽ��ϴ�.\n", wantFind, count);

	return 0;
}

int input_find(int sizeArray)
{
	int result = 0;
	int res;

	while (1)
	{
		printf("ã�⸦ ���ϴ� ���ڸ� �Է��ϼ���(1~20) : ");
		res = scanf("%d", &result);

		if (getchar() != '\n' || res < 1)
		{
			printf("���ڰ� �ԷµǾ����ϴ�. �ٽ� �Է����ּ���!\n\n");
			myfflush();
		}
		else if (result < 1 || result > 20)
		{
			printf("1 ~ 20 ������ ���ڸ� �Է����ּ���!\n\n");
		}
		else
		{
			break;
		}
	}

	return result;
}

int count_number(int *ary, int wantFind, int sizeArray)
{
	int count = 0;
	int i;

	for (i = 0; i < sizeArray; ++i)
	{
		if (ary[i] == wantFind)
		{
			count++;
		}
	}

	return count;
}

void myfflush()
{
	while (getchar() != '\n')
	{
		;
	}

	return;
}