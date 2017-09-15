#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

unsigned int ustrlen(char*);
void ustrcpy(char*, char*);
int ustrcmp(char*, char*);

int main()
{
	char str[10];
	char chr[20] = "Dream";
	unsigned int len;
	int res;

	len = ustrlen(chr);
	printf("%s �� ���� : %u\n\n", chr, len);

	ustrcpy(str, chr);
	printf("str�� ���� : %s\n\n", str);
	
	res = ustrcmp(str, "Drama");
	
	if (res > 0)
	{
		printf("%s�� %s���� ū���� ������.\n\n", str, "Drama");
	}
	else if (res == 0)
	{
		printf("%s�� %s�� ���� ���� ������\n\n", str, "Drama");
	}
	else
	{
		printf("%s�� %s���� �� ���� ���� ������.\n\n", str, "Drama");
	}
	
	return 0;
}

unsigned int ustrlen(char *p)
{
	unsigned int len;
	int i = 0;

	while (1)
	{
		if (p[i] == '\0') //�ι��� ���� ������ ���̸� ���ؾ� �ϹǷ� �ι��ڸ� ������ 0���� ���������Ƿ� �ε����� �������� �� ���̰� ���ڿ��� ����
		{
			len = (unsigned)i;
			break;
		}
		i++;
	}

	return len;
}

void ustrcpy(char *s1, char *s2)
{
	int i = 0;

	while (1)
	{
		if (*(s2+i) == '\0')//s2�� �ι��ڰ� ���� ������ ����
		{
			*(s1 + i) = '\0';//s2���� �ι��ڰ� ���� �ڸ��� �Ȱ��� s1�� �ڸ��� �ι��� �����ϰ� ����
			break;
		}
		*(s1 + i) = *(s2 + i);

		i++;
	}

	return;
}

int ustrcmp(char *s1, char *s2)
{
	int res;
	int i = 0;

	while (1)
	{
		if (*(s1 + i) != *(s2 + i) || (*(s1 + i) == 0  && *(s2 + i) == 0))// s1�� s2�� ���� �ٸ��ų� �ƴϸ� s1�� s2�� ��� �ι��ڸ� ������ ������ ���� ����
		{
			res = *(s1 + i) - *(s2 + i);
			break;
		}
		i++;
	}

	return res;
}