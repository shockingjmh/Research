#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int inputIntNum(char* str, int, int);
int output(int, int, int);
void myfflush();

int main()
{
	srand((unsigned)time(NULL));

	int randNum = 0;
	int intNum = 0;
	int checkResult = 0;
	int count = 0;
	int max = 101;
	int min = 0;
	int flag;
	int exit = 0;

	
	randNum = rand() % 100 + 1;

	while (1)
	{
		intNum = inputIntNum("# ���ڸ� �Է��Ͻÿ� : ",min, max);//1 ~ 100 ���� �Է�
		count += 1;

		if (count == 10)//10���� ������ ���� ��
		{
			checkResult = 4;
			flag = count;
		}
		else if (min < randNum && randNum < intNum )//�������� �Է°����� �۰� �ּҰ����� ū ���
		{
			max = intNum;
			checkResult = 1;
			flag = min;
		}
		else if (intNum < randNum && randNum < max)//�������� �Է°����� ũ�� �ִ밪���� ���� ���
		{
			min = intNum;
			checkResult = 2;
			flag = max;
		}
		else//������ ���� ���
		{
			checkResult = 0;
			flag = count;
		}

		exit = output(checkResult, flag, intNum);//����Լ�
		if (exit == -1)
		{
			break;
		}
	}
	return 0;
}

int inputIntNum(char* str, int min, int max)//1~100 ���� �Է� �Լ�
{
	int inputInt;
	int res;

	while (1)
	{
		printf(str);

		res = scanf("%d", &inputInt);
		if (getchar() != '\n' || res == 0)
		{
			printf("1 ~ 100 ����� �Է����ּ���!\n\n");
			myfflush();
		}
		else if (inputInt <= 0)
		{
			printf("1 ~ 100 ����� �Է����ּ���!\n\n");
		}
		else
		{
			if (inputInt<min || inputInt > max)
			{
				printf("�߸� �Է��ϼ̽��ϴ�. %d�� %d������ ���ڸ� �Է����ּ���!\n\n", min, max);//�ִ밪�� �ּҰ� ������ ���ڸ� �Է����� ���� ���
			}
			else
			{
				break;
			}
		}
	}

	return inputInt;
}

int output(int checkResult, int flag, int intNum)
{
	int exit = 0;

	switch (checkResult)
	{
	case 0:
		printf("���~ �¾Ҵ�~~~ ��ī��ī~~ %d��° ���� ���߼̽��ϴ�.\n������ �����մϴ�!\n\n", flag);
		exit = -1;
		break;
	case 1:
		printf("%d���ٴ� ũ�� %d���ٴ� �۽��ϴ�.\n\n", flag, intNum);
		break;
	case 2:
		printf("%d���ٴ� ũ�� %d���ٴ� �۽��ϴ�.\n\n", intNum, flag);
		break;
	default:
		printf("%d���̳� �ߴ�. ������\n\n", flag);
		exit = -1;
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