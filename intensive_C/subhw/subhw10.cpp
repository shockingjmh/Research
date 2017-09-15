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

	inputString("# 성명 입력 : ", inputName, flag);
	flag++;

	height = inputDoubleNum("# 키 입력(cm단위) : ");
	inputString("# 성별입력(M/F) : ", inputGender, flag);

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
			printf("문자를 입력했습니다. 양수만 입력해주세요!\n\n");
			myfflush();
		}
		else if (inputDouble < 0)
		{
			printf("양수만 입력해주세요!\n\n");
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
				printf("남성이면 M, 여성이면 F만 입력해주세요!\n");
			}
		}
	}

	return;
}

void output(char* name, double height, char* gender)
{
	if (*(gender) == 'M')
	{
		printf("%s씨의 키는 %.2lfcm이고 남성입니다\n", name, height);
	}
	else
	{
		printf("%s씨의 키는 %.2lfcm이고 여성입니다\n", name, height);
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