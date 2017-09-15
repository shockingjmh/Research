#pragma warning(disable:4996)
#include <stdio.h>

void charPrint(char, int, int);
char inputChar(char* str);
int inputIntNum(char* str);
void myfflush();


int main()
{
	char inputCh = '\n';
	int iterativeNum = 0;
	int iterativeLine = 0;

	while (1)
	{
		inputCh = inputChar("* ����� ���ڸ� �Է��Ͻÿ� : ");//���� �Է� �Լ�

		if (inputCh == '#')//# �Է½� ����
		{
			printf("�����մϴ�!\n");
			break;
		}

		iterativeNum = inputIntNum("* ���ٿ� �ݺ��� ȸ���� �Է��Ͻÿ� : ");//���� �Է��Լ� �� ���ٿ� �ݺ��� Ƚ�� ����
		iterativeLine = inputIntNum("* �ݺ������ ���μ��� �Է��Ͻÿ� : ");//���� �Է��Լ� �� �ݺ� ����� ���μ� ����

		charPrint(inputCh, iterativeNum, iterativeLine); //���� ��� �Լ�

	}

	return 0;
}

void charPrint(char inputCh, int iterativeNum, int iterativeLine)//���� ��� �Լ�
{
	int i, j;

	for (i = 0; i < iterativeLine; ++i)//���� ��� ���μ�
	{
		printf("\n");
		for (j = 0; j < iterativeNum; ++j)//���� ��� Ƚ��
		{
			printf("%c", inputCh);
			
		}
	}

	printf("\n\n");

	return;
}

char inputChar(char* str)//���� �Է� �Լ�
{
	char inputOneChar;
	int res;

	while (1)
	{
		printf(str);

		res = scanf("%c", &inputOneChar);
		if (getchar() != '\n' || res == 0)
		{
			printf("���� �ϳ��� �Է����ּ���!\n\n");//���� �Է½� ��Ȯ�� char���� ��µ��� �����Ƿ� ����ó��
			myfflush();
		}
		else
		{
			break;
		}
	}


	return inputOneChar;
}

int inputIntNum(char* str)//���� �Է� �Լ�
{
	int inputInt;
	int res;

	while (1)
	{
		printf(str);

		res = scanf("%d", &inputInt);
		if (getchar() != '\n' || res == 0)//���� ����ó��
		{
			printf("���� ������ �Է����ּ���!\n\n");
			myfflush();
		}
		else if (inputInt <= 0)//0 �� ���� ����ó��
		{
			printf("���� ������ �Է����ּ���!\n\n");
		}
		else
		{
			break;
		}
	}

	return inputInt;
}

void myfflush() // ����� fflush �Լ� 
{

	while (getchar() != '\n')
	{
		;
	}

	return;
}