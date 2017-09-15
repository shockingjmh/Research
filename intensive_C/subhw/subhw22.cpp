#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int inputIntNum(char* str);
int output(int, char*, char*);
void myfflush();

int main()
{
	srand((unsigned)time(NULL));

	int player = 0;
	int computer = 0;
	int checkResult = 0;
	int win = 0;
	int draw = 0;
	int exit = 0;
	char playerState[20];
	char computerState[20];

	while (1)
	{	
		computer = rand() % 3 + 1;

		checkResult = 0;

		player = inputIntNum("# ������ 1, ������ 2, ���� 3 �߿��� �����ϼ��� : ");//������ 1, ������ 2, ���� 3 �Է��Լ�
		switch (player)
		{
		case 1:
			strcpy(playerState, "����");
			switch (computer)
			{
			case 1:
				draw += 1;
				strcpy(computerState, "����");
				break;
			case 2:
				win += 1;
				strcpy(computerState, "����");
				checkResult = 1;
				break;
			case 3:
				checkResult = -1;
				strcpy(computerState, "��");
				break;
			}
			break;
		case 2:
			strcpy(playerState, "����");
			switch (computer)
			{
			case 1:
				checkResult = -1;
				strcpy(computerState, "����");
				break;
			case 2:
				draw += 1;
				strcpy(computerState, "����");
				break;
			case 3:
				win += 1;
				checkResult = 1;
				strcpy(computerState, "��");
				break;
			}
			break;
		case 3:
			strcpy(playerState, "��");
			switch (computer)
			{
			case 1:
				win += 1;
				checkResult = 1;
				strcpy(computerState, "����");
				break;
			case 2:
				checkResult = -1;
				strcpy(computerState, "����");
				break;
			case 3:
				draw += 1;
				strcpy(computerState, "��");
				break;
			}
			break;
		}

		exit = output(checkResult, playerState, computerState);//����Լ�
		if (exit == -1)
		{
			printf("%d �� %d ��\n\n", win, draw);
			break;
		}
	}
	return 0;
}

int inputIntNum(char* str)//������ 1, ������ 2, ���� 3 �Է��Լ�
{
	int inputInt;
	int res;

	while (1)
	{
		printf(str);

		res = scanf("%d", &inputInt);
		if (getchar() != '\n' || res == 0)
		{
			printf("������ 1, ������ 2, ���� 3 �� �Է����ּ���!\n\n");
			myfflush();
		}
		else if (inputInt < 1 || inputInt > 3)
		{
			printf("������ 1, ������ 2, ���� 3 �� �Է����ּ���!\n\n");
		}
		else
		{
			break;
		}
	}

	return inputInt;
}

int output(int checkResult, char* playerState, char* computerState)
{
	int exit = 0;
	
	switch (checkResult)
	{
	case -1:
		printf("����� %s ����, ��ǻ�ʹ� %s ���� : ����� �����ϴ�.\n\n", playerState, computerState);
		exit = -1;
		break;
	case 0:
		printf("����� %s ����, ��ǻ�ʹ� %s ���� : �����ϴ�.\n\n",playerState, computerState);
		break;
	case 1:
		printf("����� %s ����, ��ǻ�ʹ� %s ���� : �̰���ϴ�.\n\n", playerState, computerState);
		break;
	}
	return exit;
}

void myfflush()//��������� fflush�Լ� 
{
	while (getchar() != '\n')
	{
		;
	}

	return;
}