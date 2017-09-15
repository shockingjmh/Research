#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

int inputIntNum(char*);
int menu();
void fanOpen(unsigned char*, int);
void fanOff(unsigned char*, int);
void fanReverse(unsigned char*, int);
void fanDisplay(unsigned char*, int);
void myfflush();

int main()
{
	unsigned char fanState = 0;
	int sizeBit = sizeof(unsigned char) * 8;
	int menuNum;
	int exit = 0;
	
	while (exit == 0)
	{
		menuNum = menu();

		switch (menuNum)
		{
		case 1:
			fanOpen(&fanState, sizeBit);
			break;
		case 2:
			fanOff(&fanState, sizeBit);
			break;
		case 3:
			fanReverse(&fanState, sizeBit);
			break;
		case 4:
			exit = -1;
			break;
		}
	}

	return 0;
}

int inputIntNum(char* str)
{
	int result;
	int res;

	while (1)
	{
		printf(str);
		res = scanf("%d", &result);
		printf("--------------------------------------------------------------------\n\n");

		if (getchar() != '\n' || res < 1)
		{
			printf("���ڰ� �ԷµǾ����ϴ�. �ٽ� �Է����ּ���!\n\n");
			myfflush();
		}
		else if (result <= 0)
		{
			printf("���� ������ �Է����ּ���!\n\n");
		}
		else
		{
			break;
		}
	}

	return result;
}

int menu()
{
	int inputNum;

	while (1)
	{
		inputNum = inputIntNum("1. ȯǳ�� ����/ 2. ȯǳ�� �ݱ� / 3. ȯǳ�� ��ü ��ȯ / 4. ���� : ");

		if (inputNum > 4)
		{
			printf("1 ~ 4 �� �ϳ��� �������ּ���!\n\n");
		}
		else
		{
			break;
		}
	}

	return inputNum;
}
void fanOpen(unsigned char *p, int sizeBit)
{
	unsigned char bitController = 1;
	int inputNum;
	int i;

	while (1)
	{
		printf("--------------------------------------------------------------------\n");
		inputNum = inputIntNum("* OPEN�� FAN ��ȣ�� �Է��Ͻÿ�(1-8) : ");

		if (inputNum > 8)
		{
			printf("1 ~ 8 �� �ϳ��� �������ּ���!\n\n");
		}
		else
		{
			for (i = 1; i < inputNum; i++)
			{
				bitController *= 2;
			}

			*p |= bitController;

			fanDisplay(p, sizeBit);
			break;
		}
	}

}
void fanOff(unsigned char *p, int sizeBit)
{
	unsigned char bitController = 1;
	int inputNum;
	int i;

	while (1)
	{
		printf("--------------------------------------------------------------------\n");
		inputNum = inputIntNum("* CLOSE�� FAN ��ȣ�� �Է��Ͻÿ�(1-8) : ");

		if (inputNum > 8)
		{
			printf("1 ~ 8 �� �ϳ��� �������ּ���!\n\n");
		}
		else
		{
			for (i = 1; i < inputNum; i++)
			{
				bitController *= 2;
			}
			
			bitController = ~ bitController;
			*p &= bitController;

			fanDisplay(p, sizeBit);
			break;
		}
	}
	return;
}

void fanReverse(unsigned char *p, int sizeBit)
{

	(*p)=~(*p);
	printf("--------------------------------------------------------------------\n");
	printf("       ��ü FAN�� ���°� ��ȯ�Ǿ����ϴ�. (ON, OFF ���� �ڹٲ�)\n");
	printf("--------------------------------------------------------------------\n");
	fanDisplay(p, sizeBit);

	return;
}

void fanDisplay(unsigned char *p, int sizeBit)
{
	unsigned char temp = *p;
	unsigned char current = 0;
	char state[4];
	int i;

	printf("8��FAN   7��FAN   6��FAN   5��FAN   4��FAN   3��FAN   2��FAN   1��FAN\n");

	for (i = 0; i < sizeBit; i++)
	{
		current = temp & 0x80;
		if (current == 0)
		{
			strcpy(state, "OFF");
			printf("%5s    ", state);
		}
		else
		{
			strcpy(state, "ON");
			printf("%5s    ", state);
		}
		temp <<= 1;
	}

	printf("\n--------------------------------------------------------------------\n\n");

	return;
}

void myfflush()
{
	while (getchar() != '\n')
	{
		;
	}

	return;
}