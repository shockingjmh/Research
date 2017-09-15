#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

double inputDoubleNum(char*);
void inputString(char*, char*, int);
void output(char*, double, char*);
void myfflush();

int main()
{
	char inputName[100];
	char inputGender[10];
	int flag = 0;
	double height;

	inputString("# ���� �Է� : ", inputName, flag);
	flag++;

	height = inputDoubleNum("# Ű �Է�(cm����) : ");
	inputString("# �����Է�(M/F) : ", inputGender, flag);

	output(inputName, height, inputGender);

	return 0;
}

double inputDoubleNum(char* str)
{
	double inputDouble;
	int res;

	while (1)
	{
		printf(str);

		res = scanf("%lf", &inputDouble);
		if (getchar() != '\n' || res == 0)
		{
			printf("���ڸ� �Է��߽��ϴ�. ����� �Է����ּ���!\n\n");
			myfflush();
		}
		else if (inputDouble < 0)
		{
			printf("����� �Է����ּ���!\n\n");
		}
		else
		{			
				break;
		}
	}

	return inputDouble;
}

void inputString(char* str, char* inputStr,int flag)
{

	while (1)
	{
		printf(str);
		gets(inputStr);
		if (flag == 0)
		{
			break;
		}
		else
		{
			if (strcmp(inputStr, "M") == 0 || strcmp(inputStr, "F") == 0)
			{
				break;
			}
			else
			{
				printf("�����̸� M, �����̸� F�� �Է����ּ���!\n");
			}
		}
	}

	return;
}

void output(char* name, double height, char* gender)
{
	if (*(gender) == 'M')
	{
		printf("%s���� Ű�� %.2lfcm�̰� �����Դϴ�\n", name, height);
	}
	else
	{
		printf("%s���� Ű�� %.2lfcm�̰� �����Դϴ�\n", name, height);
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