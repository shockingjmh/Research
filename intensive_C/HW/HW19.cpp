#pragma warning(disable:4996)
#include <stdio.h>

signed short inputIntNum(char*);
void output(signed short);
void myfflush();

int main()
{
	signed short intNum = 0;

	intNum = inputIntNum("* 10���� ������ �Է��Ͻÿ� : ");
	output(intNum);

	return 0;
}

signed short inputIntNum(char* str)
{
	signed short inputInt;
	int res;

	while (1)
	{
		printf(str);

		res = scanf("%hd", &inputInt);
		if (getchar() != '\n' || res == 0)
		{
			printf("���ڸ� �Է��߽��ϴ�. ������ �Է����ּ���!\n\n");
			myfflush();
		}
		else
		{
			break;
		}
	}

	return inputInt;
}

void output(signed short intNum)
{
	signed short num = 0;
	int i = 1;

	printf("\n%hd(10) = ", intNum);
	while (1)
	{
		if (i > 16)
		{
			printf("(2)\n");
			break;
		}

		num = intNum & 0x8000;
		if (num == 0)
		{
			printf("0");
		}
		else
		{
			printf("1");
		}

		intNum <<= 1;
		i++;
	}

	return;
}

void myfflush()
{
	while (getchar() != '\n')
	{
		;
	}
}