#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

void inputStr(char (*)[20]);
void stringSort(char (*)[20], int *);
void output(char (*)[20], int *);
void myfflush();

int main()
{
	char inputString[5][20] = { '\0', };
	int stringLen[5] = { 0, };
	int i;

	inputStr(inputString);
	for (i = 0; i < 5; i++)
	{
		stringLen[i] = strlen(inputString[i]);
	}
	stringSort(inputString, stringLen);
	output(inputString, stringLen);

	return 0;
}

void inputStr(char (*p)[20])
{
	int checkLen = 0;
	int i,j, k;

	for (i = 0; i < 5; i++)
	{
		j = 0;
		printf("# %d번 문자열을 입력하시오 : ", i+1);

		while (1)
		{
			if (j == 19)
			{
				printf("* 입력 불가능한 문자열 길이 입니다. 19자 이내로 입력해주세요!\n\n");
				for (k = 0; k < 20; k++)
				{
					p[i][k] = '\0';
				}
				i -= 1;
				myfflush();
				break;
			}
			else
			{
				p[i][j] = getchar();
				if (p[i][j] == '\n')
				{
					break;
					myfflush();
				}
				j++;
			}
		}
		p[i][j] = NULL;
	}

	return;
}

void stringSort(char (*p)[20], int *q)
{
	char temp[20] = {'\0', };
	int tempInt = 0;
	int i, j;
	int sequenceStr;

	for (i = 0; i < 3; i++)
	{
		for (j = i + 1; j < 4; j++)
		{
			sequenceStr = strcmp(p[i], p[j]);
			if (sequenceStr > 0)
			{
				strcpy(temp, p[i]);
				strcpy(p[i], p[j]);
				strcpy(p[j], temp);

				tempInt = q[i];
				q[i] = q[j];
				q[j] = tempInt;
			}
		}
	}

	return;
}void output(char (*p)[20], int *q)
{
	int i, j;

	printf("\n\n");

	for (i = 0; i < 5; i++)
	{
		printf("str[%d] = %s", i, p[i]);
		for (j = 0; j < q[i]; j++)
		{
			if (j == 0 || j == q[i] -1)
			{
				printf("%3c", p[i][j]);
			}
		}
		printf("\n");
	}

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