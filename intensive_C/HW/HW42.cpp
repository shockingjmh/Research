#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <malloc.h>

void inputString(char *[5], int);
void mySort(char *[5], int);
void output(char *[5], int);
void myFree(char *[5], int);

int main()
{
	char *p[5];
	int cnt = sizeof(p) / sizeof(p[0]);
	
	void (*fptr[4])(char *[5], int) = {inputString, mySort, output, myFree};

	fptr[0](p, cnt);
	printf("\n# Sort 전\n");
	fptr[2](p, cnt);
	fptr[1](p, cnt);
	printf("\n# Sort 후\n");
	fptr[2](p, cnt);
	fptr[3](p, cnt);

	return 0;
}

void inputString(char *p[5], int cnt)
{
	char temp[500];
	int len;
	int i;

	for (i = 0; i < cnt; i++)
	{
		printf("# 문자열 %d : ", i+1);
		gets(temp);
		len = strlen(temp) + 1;
		*(p + i) = (char*)malloc(sizeof(char)*len);
		strcpy(*(p + i), temp);
		assert(*(p+i) != NULL);
	}

	return;
}

void mySort(char *p[5], int cnt)
{
	char *temp;
	int i, j;

	for (i = 0; i < cnt - 1; i++)
	{
		for (j = i + 1; j < cnt; j++)
		{
			if (strcmp(*(p + i), *(p + j)) > 0)
			{
				temp = *(p + i);
				*(p + i) = *(p + j);
				*(p + j) = temp;
			}
		}
	}

	return;
}

void output(char *p[5], int cnt)
{
	int i;

	printf("\n");
	for (i = 0; i < cnt; i++)
	{
		printf("%d. %s\n", i + 1, *(p + i));
	}
	printf("\n");

	return;
}

void myFree(char *p[5], int cnt)
{
	int i;

	for (i = 0; i < cnt; i++)
	{
		free(*(p + i));
	}

	return;
}